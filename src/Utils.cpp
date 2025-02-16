#include "Utils.h"

glm::vec3 Utils::GetDirectionFromAxis(float x, float y)
{
    glm::vec3 direction;
    direction.x = cos(glm::radians(x)) * cos(glm::radians(y));
    direction.y = sin(glm::radians(y));
    direction.z = sin(glm::radians(x)) * cos(glm::radians(y));
    return direction;
}

