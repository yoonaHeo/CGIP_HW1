#ifndef __SCENE_H__
#define __SCENE_H__

#pragma once

#include "Sphere.h"
#include "Plane.h"

class Scene {
public:
    Sphere sphere[3];
    Plane plane;
};

#endif // __SCENE_H__