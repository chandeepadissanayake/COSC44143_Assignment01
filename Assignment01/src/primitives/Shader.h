/*
 * Definitions for a Shader and its functionality.
 * Adopted, with appropriate changes, from Yan Chernikov's tutorials.
 * Tutorial URL: https://www.youtube.com/watch?v=W3gAzLwfIP0&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2
 */

#pragma once

#include <string>
#include <unordered_map>

#include <glm/glm.hpp>

class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_FilePathVertex;
	std::string m_FilePathFragment;
	std::unordered_map<std::string, int> m_UniformLocationCache;

	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};

	ShaderProgramSource ParseShaders();
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);

	int GetUniformLocation(const std::string& name);
	// Caches for uniforms

public:
	Shader(const std::string& filePathVertex, const std::string& filePathFragment);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform1ui(const std::string& name, unsigned int value);
	void SetUniform1i(const std::string& name, int value);
	void SetUniformMat4(const std::string& name, const glm::mat4& mat);
};

