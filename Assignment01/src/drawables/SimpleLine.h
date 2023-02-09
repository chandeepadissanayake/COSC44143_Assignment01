#pragma once

#include "Drawable.h"
#include "../primitives/Vectors.h"

class SimpleLine : public Drawable
{
private:
	int m_WindowWidth; int m_WindowHeight;
	float m_Endpoints[4];

	VertexArray* m_Va;
	VertexBuffer* m_Vb;
	VertexBufferLayout* m_Vbl;
	IndexBuffer* m_Ib;

	// Temporary code to remove when developing for line.
	static float positions[8];
	static unsigned int indices[6];
public:
	SimpleLine(int windowWidth, int windowHeight, Vec2 p1, Vec2 p2);
	~SimpleLine();

	// Inherited via Drawable
	VertexArray* GetVertexArray() override;
	IndexBuffer* GetIndexBuffer() override;
	void Draw() override;
};

