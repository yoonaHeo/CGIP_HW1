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
#include "Scene.h"
#include "Light.h"

using namespace glm;
using namespace std;

#define sampleNum 64

// image to be generated has size of Nx * Ny * 3
unsigned char image[Nx * Ny * 3];

struct Color {
    float r, g, b;
} color;

// struct of hitSurface and t
struct HitSurface {
    bool hit;
    float t;    // t value of intersection (point to be hit)
    Color color;
    int firstSurface;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

array<int, 4> hitSurface(Ray ray, Scene scene) {
    array<int, 4> hit = {0, 0, 0, 0};

    for(int i = 0; i < 3; i++) {
        Sphere sphere = scene.sphere[i];
        float a = dot(ray.direction, ray.direction);
        float b = 2 * dot(ray.direction, ray.origin - sphere.center);
        float c = dot(ray.origin - sphere.center, ray.origin - sphere.center) - (sphere.radius * sphere.radius);

        float discriminant1 = b * b - 4 * a * c;

        if(discriminant1 >= 0) {
            hit[i] = 1;
        } else {
            hit[i] = 0;
        }
    }

    Plane plane = scene.plane;

    float discriminant2 = glm::dot(ray.direction, plane.normal);

    if(discriminant2 <= 0) {
        hit[3] = 1;
    } else {
        hit[3] = 0;
    }

    return hit; //this will return true if ray hits each surface
}

array<float, 4> calculateT(Ray ray, Scene scene) {
    array<float, 4> t = {-1.0f, -1.0f, -1.0f, -1.0f};

    for(int i = 0; i < 3; i++) {
        Sphere sphere = scene.sphere[i];
        float a = dot(ray.direction, ray.direction);
        float b = 2 * dot(ray.direction, ray.origin - sphere.center);
        float c = dot(ray.origin - sphere.center, ray.origin - sphere.center) - (sphere.radius * sphere.radius);

        float discriminant = b * b - 4 * a * c;

        t[i] = ((-1) * b - sqrt(discriminant)) / (2 * a);
    }

    Plane plane = scene.plane;
    t[3] = dot(plane.normal, plane.point - ray.origin) / dot(plane.normal, ray.direction);

    return t;   //this will return t values of intersection if ray hits each surface
}

glm::vec3 evaluateRay(Ray ray, float t) {
    return ray.origin + t * ray.direction;
}

HitSurface intersect(Ray ray, Scene scene, float tMin, float tMax) {
    HitSurface hsf = {false, -1.0f};

    float tBest = tMax;

    if (hitSurface(ray, scene)[0] != 0 || hitSurface(ray, scene)[1] != 0 || hitSurface(ray, scene)[2] != 0 || hitSurface(ray, scene)[3] != 0) {
        // this means at least one surface is hit
        // if hitSurface returns true, calculate t values
        array<float, 4> tValues = calculateT(ray, scene);
        for (int i = 0; i < 4; i++) {
            float t = tValues[i];
            if (t > tMin && t < tBest) {
                tBest = t;
                hsf.hit = true;
                hsf.t = tBest;

                hsf.firstSurface = i;
            }
        }
    }
    
    return hsf;
}

// function for calculating shading of the object
vec3 calculateShading(Ray ray, Scene scene, HitSurface hsf, Light light) {
    // Ld = kd * I * max(0, n dot l)
    // Ls = ks * I * max(0, n dot h)^p
    // La = ka * Ia
    // L = La + Ld + Ls = ka * Ia + kd * I * max(0, n dot l) + ks * I * max(0, n dot h)^p

    // kd: coefficient of diffuse reflection
    // ks: coefficient of specular reflection
    // ka: coefficient of ambient reflection
    // I: intensity of light source
    // n: normal vector
    // l: light direction
    // Ia: object color

    vec3 shading = vec3(1, 1, 1);

    array<float, 4> I;
    array<glm::vec3, 4> kd, ks, ka, n, l, h, v, point;
    array<Color, 4> Ia;
    array<int, 4> specular;

    int i = hsf.firstSurface;
    if (i == 3) {
        kd[i] = scene.plane.kd;
        ks[i] = scene.plane.ks;
        ka[i] = scene.plane.ka;
        I[i] = light.intensity;
        point[i] = evaluateRay(ray, hsf.t);
        v[i] = normalize(-ray.direction);
        n[i] = scene.plane.normal;
        l[i] = normalize(light.position - point[i]);
        h[i] = normalize(v[i] + l[i]);
        Ia[i].r = light.color.r;
        Ia[i].g = light.color.g;
        Ia[i].b = light.color.b;
        specular[i] = scene.plane.specular;
    } else {
        kd[i] = scene.sphere[i].kd;
        ks[i] = scene.sphere[i].ks;
        ka[i] = scene.sphere[i].ka;
        I[i] = light.intensity;
        point[i] = evaluateRay(ray, hsf.t);
        v[i] = normalize(-ray.direction);
        n[i] = normalize(point[i] - scene.sphere[i].center);
        l[i] = normalize(light.position - point[i]);
        h[i] = normalize(v[i] + l[i]);
        Ia[i].r = light.color.r;
        Ia[i].g = light.color.g;
        Ia[i].b = light.color.b;
        specular[i] = scene.sphere[i].specular;
    }

    
    Ray shadowRay = {point[i], l[i]};
    HitSurface hsfShadow = intersect(shadowRay, scene, 0.0f, INFINITY);

    // calculate shading
    // L = ka * Ia + kd * I * max(0, n dot l) + ks * I * max(0, n dot h)^p
    if(hsfShadow.hit) {
        shading.r = ka[i].r * Ia[i].r;
        shading.g = ka[i].g * Ia[i].g;
        shading.b = ka[i].b * Ia[i].b;
    } else {
        shading.r = ka[i].r * Ia[i].r + kd[i].r * I[i] * std::max(0.0f, dot(n[i], l[i])) + ks[i].r * I[i] * pow(std::max(0.0f, dot(n[i], h[i])), specular[i]);
        shading.g = ka[i].g * Ia[i].g + kd[i].g * I[i] * std::max(0.0f, dot(n[i], l[i])) + ks[i].g * I[i] * pow(std::max(0.0f, dot(n[i], h[i])), specular[i]);
        shading.b = ka[i].b * Ia[i].b + kd[i].b * I[i] * std::max(0.0f, dot(n[i], l[i])) + ks[i].b * I[i] * pow(std::max(0.0f, dot(n[i], h[i])), specular[i]);
    }
        
    return shading;
}

float gammaCorrect(float value, float gamma) {
    return pow(value, 1.0f / gamma);
}

int main() {
    glfwInit();

    if(!glfwInit()) {
        const char* descrption = nullptr;
        glfwGetError(&descrption);
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }

    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
    if (window == nullptr) {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    if(framebuffer_size_callback == nullptr) {
        cout << "Failed to set framebuffer size callback" << endl;
        return -1;
    }

    Camera camera;

    Sphere S1 = {vec3(-4, 0, -7), 1, {1, 0, 0}, vec3(0.2, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), 0};
    Sphere S2 = {vec3(0, 0, -7), 2, {0, 1, 0}, vec3(0, 0.2, 0), vec3(0, 0.5, 0), vec3(0.5, 0.5, 0.5), 32};
    Sphere S3 = {vec3(4, 0, -7), 1, {0, 0, 1}, vec3(0, 0, 0.2), vec3(0, 0, 1), vec3(0, 0, 0), 0};

    Plane P = {vec3(0, 1, 0), vec3(0, -2, 0), {1, 1, 1}, vec3(0.2, 0.2, 0.2), vec3(1, 1, 1), vec3(0, 0, 0), 0};

    Scene scene = {S1, S2, S3, P};

    Light light = {vec3(-4, 4, -3), {1, 1, 1}, 1.0f};

    float gamma = 2.2f;

    // for each pixel, compute ray and check intersection with sphere
    // set pixel color
    for(int iy = 0; iy < Ny; iy++) {
        for(int ix = 0; ix < Nx; ix++) {
            int idx = (iy * Ny + ix) * 3;
            // compute ray using values above (camera.l, camera.r, camera.b, camera.t, camera.d)
            // computed ray values are ray for each pixel
            Ray ray;
            HitSurface hsf;
            Color finalColor = {0, 0, 0};

            // for each sample, compute ray and check intersection with sphere
            for (int sample = 0; sample < sampleNum; sample++) {
                ray = camera.getRandomRay(ix, iy);

                hsf = intersect(ray, scene, 0.0f, INFINITY);

                if(hsf.hit) {
                    finalColor.r += calculateShading(ray, scene, hsf, light).r;
                    finalColor.g += calculateShading(ray, scene, hsf, light).g;
                    finalColor.b += calculateShading(ray, scene, hsf, light).b;
                    
                }
            }

            if(hsf.hit) {
                finalColor.r /= float(sampleNum);
                finalColor.g /= float(sampleNum);
                finalColor.b /= float(sampleNum);

                // have to be normalized before gamma correction
                finalColor.r = (finalColor.r) > 1 ? 1 : finalColor.r;
                finalColor.g = (finalColor.g) > 1 ? 1 : finalColor.g;
                finalColor.b = (finalColor.b) > 1 ? 1 : finalColor.b;

                finalColor.r = gammaCorrect(finalColor.r, gamma);
                finalColor.g = gammaCorrect(finalColor.g, gamma);
                finalColor.b = gammaCorrect(finalColor.b, gamma);

                image[idx] = 255 * (finalColor.r);
                image[idx + 1] = 255 * (finalColor.g);
                image[idx + 2] = 255 * (finalColor.b);
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