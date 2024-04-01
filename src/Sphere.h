#ifndef __SPHERE_H__
#define __SPHERE_H__

#pragma once

#include <glm/glm.hpp>

// sphere needs center point and radius
// center point has to be a vector which represents position in 3D space
class Sphere {
public:
    glm::vec3 center;
    int radius;
};

#endif // __SPHERE_H__