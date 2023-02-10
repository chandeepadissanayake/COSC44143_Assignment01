/*
 * Definitions for a Vertex Array and its functionality.
 * Adopted, with appropriate changes, from Yan Chernikov's tutorials.
 * Tutorial URL: https://www.youtube.com/watch?v=W3gAzLwfIP0&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2
 */
#pragma once

#include "VertexBuffer.h"

#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int m_RendererID;
public:
	VertexArray();
	~VertexArray();

	void Bind() const;
	void Unbind() const;

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
};

