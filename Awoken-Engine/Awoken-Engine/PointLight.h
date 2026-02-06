#pragma once
#include "glm.hpp"

using namespace glm;

class PointLight
{
public:
    PointLight();

    PointLight(vec3 position, float constant, float linear, float quadratic, vec3 color = vec3(1.0f, 1.0f, 1.0f));

    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 color;
};

