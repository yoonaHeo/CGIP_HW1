#ifndef __PLANE_H__
#define __PLANE_H__

#pragma once

#include <glm/glm.hpp>

// plane needs normal vector and point on plane
// normal vector has to be a vector which is perpendicular to the plane
// point has to be a vector which represents position in 3D space
class Plane {
public:
    glm::vec3 normal;
    glm::vec3 point;
    struct Color {
        float r, g, b;
    } color;
    glm::vec3 ka, kd, ks;
};

#endif // __PLANE_H__