#ifndef __RAY_H__
#define __RAY_H__

#pragma once

#include <glm/glm.hpp>

using namespace glm;

struct Ray {
public:
    vec3 origin = glm::vec3(0, 0, 0);
    vec3 direction;
};

#endif // __RAY_H__