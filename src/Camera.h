#ifndef __CAMERA_H__
#define __CAMERA_H__

#pragma once

#include "Ray.h"

#define Nx 512
#define Ny 512

// camera's origin is (0, 0, 0)
// ray from light source will hit the surface and then hit the camera, making image on the image plane
// image plane has to have l, r, b, t values
class Camera {
public:
    // camera origin e
    glm::vec3 e = glm::vec3(0, 0, 0);

    // direction vector for each axis u, v, w
    glm::vec3 vecU = glm::vec3(1, 0, 0);
    glm::vec3 vecV = glm::vec3(0, 1, 0);
    glm::vec3 vecW = glm::vec3(0, 0, 1);

    // l and r are each end of ix axis of image plane (which is -0.1 and 0.1 in this project)
    float l = -0.1, r = 0.1;
    // b and t are each end of iy axis of image plane (which is -0.1 and 0.1 in this project)
    float b = -0.1, t = 0.1;
    
    // d is distance from origin to image plane (which is 0.1 in this project)
    float d = 0.1;

    // get ray of pixel (ix, iy)
    Ray getRay(float ix, float iy) {
        // u is pixel position on x axis of image plane
        float u = l + (r - l) * (ix + 0.5) / Nx;

        // v is pixel position on y axis of image plane
        float v = b + (t - b) * (iy + 0.5) / Ny;

        // coordinate s
        glm::vec3 s = e + u * vecU + v * vecV - d * vecW;

        // direction d, which depends on s (not e, since e is fixed at (0, 0, 0))
        glm::vec3 direction = s - e;

        return Ray{e, direction};
    };    
};

#endif // __CAMERA_H__