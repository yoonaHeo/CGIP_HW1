#ifndef __CAMERA_H__
#define __CAMERA_H__

#pragma once

#include "Ray.h"
#include <random>
#include <time.h>

using namespace glm;
using namespace std;

#define Nx 512
#define Ny 512

// camera's origin is (0, 0, 0)
// ray from light source will hit the surface and then hit the camera, making image on the image plane
// image plane has to have l, r, b, t values
class Camera {
public:
    // camera origin e
    vec3 e = vec3(0, 0, 0);

    // direction vector for each axis u, v, w
    vec3 vecU = vec3(1, 0, 0);
    vec3 vecV = vec3(0, 1, 0);
    vec3 vecW = vec3(0, 0, 1);

    // l and r are each end of ix axis of image plane (which is -0.1 and 0.1 in this project)
    float l = -0.1, r = 0.1;
    // b and t are each end of iy axis of image plane (which is -0.1 and 0.1 in this project)
    float b = -0.1, t = 0.1;
    
    // d is distance from origin to image plane (which is 0.1 in this project)
    float d = 0.1;

    // get ray of pixel (ix, iy)
    Ray getRay(float ix, float iy) {
        Ray ray;
        glm::vec3 origin = ray.origin;
        // u is pixel position on x axis of image plane
        float u = l + (r - l) * (ix + 0.5) / Nx;

        // v is pixel position on y axis of image plane
        float v = b + (t - b) * (iy + 0.5) / Ny;

        // coordinate s
        vec3 s = origin + u * vecU + v * vecV - d * vecW;

        // direction d, which depends on s (not e, since e is fixed at (0, 0, 0))
        vec3 direction = s - origin;

        return Ray{origin, direction};
    };

    // get random ray of pixel (ix, iy)
    Ray getRandomRay(float ix, float iy) {
        Ray ray;
        vec3 origin = ray.origin;

        // create random float generator
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<float> dis(0, 1);

        // generate a random float between 0 and 1
        float randX = dis(gen);
        float randY = dis(gen);

        // u is pixel position on x axis of image plane
        float u = l + (r - l) * (ix + randX) / Nx;

        // v is pixel position on y axis of image plane
        float v = b + (t - b) * (iy + randY) / Ny;

        // coordinate s
        vec3 s = origin + u * vecU + v * vecV - d * vecW;

        // direction d, which depends on s (not e, since e is fixed at (0, 0, 0))
        vec3 direction = s - origin;

        return Ray{origin, direction};
    };
};

#endif // __CAMERA_H__