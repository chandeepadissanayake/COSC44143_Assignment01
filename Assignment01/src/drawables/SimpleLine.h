/*
 * Class for drawing a simple straight line with OpenGL.
 */
#pragma once

#include "Drawable.h"
#include "../primitives/Vectors.h"

class SimpleLine : public Drawable
{
private:
	float m_Endpoints[4];

	VertexArray* m_Va;
	VertexBuffer* m_Vb;
	VertexBufferLayout* m_Vbl;
	IndexBuffer* m_Ib;
public:
	SimpleLine(int windowWidth, int windowHeight, Vec2 p1, Vec2 p2);
	~SimpleLine();

	// Inherited via Drawable
	virtual VertexArray* GetVertexArray() override;
	virtual IndexBuffer* GetIndexBuffer() override;
	virtual Shader* GetShader() override;
	virtual void Draw() override;
};

