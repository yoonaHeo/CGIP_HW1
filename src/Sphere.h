#ifndef __SPHERE_H__
#define __SPHERE_H__

#pragma once

#include <glm/glm.hpp>

using namespace glm;

// sphere needs center point and radius
// center point has to be a vector which represents position in 3D space
class Sphere {
public:
    vec3 center;
    int radius;
    struct Color {
        float r, g, b;
    } color;
    vec3 ka, kd, ks;
    int specular;
};

#endif // __SPHERE_H__