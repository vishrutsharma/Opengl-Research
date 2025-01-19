#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad\glad.h>
#include <string>

class Shader
{
public:
    unsigned int ID;
    Shader(const char* vertexShaderPath, const char* fragementShaderPath);
    void Use();
    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    int GetUniformLocation(const std::string& value);

private:
    void CheckForErrors(unsigned int shader,std::string type);
};
