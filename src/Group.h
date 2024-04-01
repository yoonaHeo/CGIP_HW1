#ifndef __GROUP_H__
#define __GROUP_H__

#pragma once

#include "Sphere.h"
#include "Plane.h"

class Group {
public:
    Sphere sphere[3];
    Plane plane;
};

#endif // __GROUP_H__