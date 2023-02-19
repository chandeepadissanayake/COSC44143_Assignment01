/*
 * Definitions for Shader.h
 */

#include "Shader.h"

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Shader::Shader(const std::string& filePathVertex, const std::string& filePathFragment)
    : m_FilePathVertex(filePathVertex), m_FilePathFragment(filePathFragment), m_RendererID(0)
{
    ShaderProgramSource source = ParseShaders();
    m_RendererID = CreateShaderProgram(source.VertexSource, source.FragmentSource);
}

Shader::~Shader()
{
    glDeleteProgram(m_RendererID);
}

Shader::ShaderProgramSource Shader::ParseShaders()
{
    std::ifstream fileStreamVertex, fileStreamFragment;

    try
    {
        fileStreamVertex.open(m_FilePathVertex);
        fileStreamFragment.open(m_FilePathFragment);

        std::stringstream streamVertex, streamFragment;
        streamVertex << fileStreamVertex.rdbuf();
        streamFragment << fileStreamFragment.rdbuf();

        fileStreamVertex.close();
        fileStreamFragment.close();

        return {
            streamVertex.str(),
            streamFragment.str()
        };
    }

    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;

        return {
            nullptr,
            nullptr
        };
    }
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile shader!" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

unsigned int Shader::CreateShaderProgram(const std::string& vertexShader, const std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

void Shader::Bind() const
{
    glUseProgram(m_RendererID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

int Shader::GetUniformLocation(const std::string& name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
    {
        return m_UniformLocationCache[name];
    }

    int location = glGetUniformLocation(m_RendererID, name.c_str());
    if (location == -1)
    {
        std::cout << "Warning: Uniform " << name << " doesn't exist!" << std::endl;
    }
    m_UniformLocationCache[name] = location;

    return location;
}

void Shader::SetUniform1i(const std::string& name, int value)
{
    int location = GetUniformLocation(name);
    glUniform1i(location, value);
}

void Shader::SetUniform1ui(const std::string& name, unsigned int value)
{
    int location = GetUniformLocation(name);
    glUniform1ui(location, value);
}

void Shader::SetUniformMat4(const std::string& name, const glm::mat4& mat)
{
    int location = GetUniformLocation(name);
    glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}
