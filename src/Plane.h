#ifndef __PLANE_H__
#define __PLANE_H__

#pragma once

#include <glm/glm.hpp>

class Plane {
public:
    glm::vec3 normal;
    glm::vec3 point;
};

#endif // __PLANE_H__