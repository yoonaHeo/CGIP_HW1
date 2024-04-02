#ifndef __LIGHT_H__
#define __LIGHT_H__

#pragma once

#include <glm/glm.hpp>

using namespace glm;

class Light {
public:
    vec3 position;
    struct Color {
        float r, g, b;
    } color;
    float intensity;
};

#endif // __LIGHT_H__