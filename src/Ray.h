#ifndef __RAY_H__
#define __RAY_H__

#pragma once

#include <glm/glm.hpp>

struct Ray {
public:
    glm::vec3 origin = glm::vec3(0, 0, 0);
    glm::vec3 direction;
};

#endif // __RAY_H__