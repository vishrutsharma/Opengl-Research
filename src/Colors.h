#pragma once
#include <glm.hpp>
#include "Utils.h"

enum class Color {
    Red,
    Green,
    Blue,
    Yellow,
    Cyan,
    Magenta,
    White,
    Black,
    Gray,
    Orange,
    Purple,
    Pink
};


inline glm::vec3 GetVec3Color(Color color) {
    switch (color) {
    case Color::Red:     return { 1.0f, 0.0f, 0.0f };
    case Color::Green:   return { 0.0f, 1.0f, 0.0f };
    case Color::Blue:    return { 0.0f, 0.0f, 1.0f };
    case Color::Yellow:  return { 1.0f, 1.0f, 0.0f };
    case Color::Cyan:    return { 0.0f, 1.0f, 1.0f };
    case Color::Magenta: return { 1.0f, 0.0f, 1.0f };
    case Color::White:   return { 1.0f, 1.0f, 1.0f };
    case Color::Black:   return { 0.0f, 0.0f, 0.0f };
    case Color::Gray:    return { 0.5f, 0.5f, 0.5f };
    case Color::Orange:  return { 1.0f, 0.5f, 0.0f };
    case Color::Purple:  return { 0.5f, 0.0f, 0.5f };
    case Color::Pink:    return { 1.0f, 0.4f, 0.7f };
    default:             return { 1.0f, 1.0f, 1.0f }; // Default White
    }
}


inline glm::vec3 GetRandomColor()
{
    int index = Utils::GET_RANDOM_NUMBER(0, 12);
    return GetVec3Color(static_cast<Color>(index));
}
