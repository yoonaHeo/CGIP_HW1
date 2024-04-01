#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <array>
#include <algorithm>

#include "Ray.h"
#include "Camera.h"
#include "Sphere.h"
#include "Plane.h"
#include "Group.h"

// image to be generated has size of Nx * Ny * 3
unsigned char image[Nx * Ny * 3];

// struct of hitSurface and t
struct HitSurface {
    bool hit;
    float t;    // t value of intersection (point to be hit)
};

// color value of each pixel
struct Color {
    unsigned char r, g, b;
} color;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

std::array<int, 4> hitSurface(Ray ray, Group group) {
    std::array<int, 4> hit = {0, 0, 0, 0};

    for(int i = 0; i < 3; i++) {
        Sphere sphere = group.sphere[i];
        float a = glm::dot(ray.direction, ray.direction);
        float b = 2 * glm::dot(ray.direction, ray.origin - sphere.center);
        float c = glm::dot(ray.origin - sphere.center, ray.origin - sphere.center) - (sphere.radius * sphere.radius);

        float discriminant1 = b * b - 4 * a * c;

        if(discriminant1 >= 0) {
            hit[i] = 1;
        } else {
            hit[i] = 0;
        }
    }

    Plane plane = group.plane;

    float discriminant2 = glm::dot(ray.direction, plane.normal);

    if(discriminant2 <= 0) {
        hit[3] = 1;
    } else {
        hit[3] = 0;
    }

    return hit; //this will return true if ray hits each surface
}

std::array<float, 4> calculateT(Ray ray, Group group) {
    std::array<float, 4> t = {-1.0f, -1.0f, -1.0f, -1.0f};

    for(int i = 0; i < 3; i++) {
        Sphere sphere = group.sphere[i];
        float a = glm::dot(ray.direction, ray.direction);
        float b = 2 * glm::dot(ray.direction, ray.origin - sphere.center);
        float c = glm::dot(ray.origin - sphere.center, ray.origin - sphere.center) - (sphere.radius * sphere.radius);

        float discriminant = b * b - 4 * a * c;

        t[i] = ((-1) * b - sqrt(discriminant)) / (2 * a);
    }

    Plane plane = group.plane;
    t[3] = glm::dot(plane.normal, plane.point - ray.origin) / glm::dot(plane.normal, ray.direction);

    return t;   //this will return t values of intersection if ray hits each surface
}

HitSurface groupIntersect(Ray ray, Group group, float tMin, float tMax) {
    HitSurface hsf = {false, -1.0f};

    float tBest = tMax;

    if (hitSurface(ray, group)[0] != 0 || hitSurface(ray, group)[1] != 0 || hitSurface(ray, group)[2] != 0 || hitSurface(ray, group)[3] != 0) {
        // this means at least one surface is hit
        // if hitSurface returns true, calculate t values
        std::array<float, 4> tValues = calculateT(ray, group);
        for (int i = 0; i < 4; i++) {
            float t = tValues[i];
            if (t > tMin && t < tBest) {
                tBest = t;
                hsf.hit = true;
                hsf.t = tBest;
                
                color = {255, 255, 255};
                std::cout << "tBest: " << tBest << std::endl;
            }
        }
    }

    return hsf;
}

int main() {
    glfwInit();

    if(!glfwInit()) {
        const char* descrption = nullptr;
        glfwGetError(&descrption);
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if(framebuffer_size_callback == nullptr) {
        std::cout << "Failed to set framebuffer size callback" << std::endl;
        return -1;
    }

    Camera camera;

    Sphere S1 = {glm::vec3(-4, 0, -7), 1};
    Sphere S2 = {glm::vec3(0, 0, -7), 2};
    Sphere S3 = {glm::vec3(4, 0, -7), 1};

    Plane P = {glm::vec3(0, 1, 0), glm::vec3(0, -2, 0)};

    Group group = {S1, S2, S3, P};

    // for each pixel, compute ray and check intersection with sphere
    // set pixel color
    for(int iy = 0; iy < Ny; iy++) {
        for(int ix = 0; ix < Nx; ix++) {
            int idx = (iy * Ny + ix) * 3;
            // compute ray using values above (camera.l, camera.r, camera.b, camera.t, camera.d)
            // computed ray values are ray for each pixel
            Ray ray = camera.getRay(ix, iy);

            // check intersection with sphere
            HitSurface hsf = groupIntersect(ray, group, 0.0f, INFINITY);

            if(hsf.hit) {
                image[idx] = color.r;
                image[idx + 1] = color.g;
                image[idx + 2] = color.b;
            } else {
                image[idx] = 0;
                image[idx + 1] = 0;
                image[idx + 2] = 0;
            }
        }
    }

    while(!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw pixels
        glDrawPixels(Nx, Ny, GL_RGB, GL_UNSIGNED_BYTE, image);

        // check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}