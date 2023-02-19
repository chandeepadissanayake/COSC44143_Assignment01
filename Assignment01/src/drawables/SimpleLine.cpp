/*
 * Definitions for SimpleLine.h
 */
#include "SimpleLine.h"

#include <iostream>

SimpleLine::SimpleLine(int windowWidth, int windowHeight, Vec2 p1, Vec2 p2)
	: m_Ib(nullptr)
{
	m_Endpoints[0] = GetNormalizedCoordinate(p1.x, 0, windowWidth); m_Endpoints[1] = GetNormalizedCoordinate(p1.y, 0, windowHeight);
	m_Endpoints[2] = GetNormalizedCoordinate(p2.x, 0, windowWidth); m_Endpoints[3] = GetNormalizedCoordinate(p2.y, 0, windowHeight);

	m_Va = new VertexArray();
	m_Va->Bind();

	m_Vb = new VertexBuffer(m_Endpoints, 2 * 2 * sizeof(float));
	m_Vbl = new VertexBufferLayout();
	m_Vbl->Push<float>(2, true);
	m_Va->AddBuffer(*m_Vb, *m_Vbl);
}

SimpleLine::~SimpleLine()
{
	delete m_Va;
	delete m_Vb;
	delete m_Vbl;
	delete m_Ib;
}

VertexArray* SimpleLine::GetVertexArray()
{
	return m_Va;
}

IndexBuffer* SimpleLine::GetIndexBuffer()
{
	return nullptr;
}

Shader* SimpleLine::GetShader()
{
	return nullptr;
}

void SimpleLine::Draw()
{
	glDrawArrays(GL_LINES, 0, 2);
}
