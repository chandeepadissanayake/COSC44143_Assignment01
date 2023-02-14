/*
 * Class for drawing a straight line with OpenGL using Bresenham's line drawing algorithm.
 */
#pragma once

#include "Drawable.h"
#include "../primitives/Vectors.h"

class BresenhamLine : public Drawable
{
private:
	float* m_Points;
	unsigned int m_CoordsCount;

	VertexArray* m_Va;
	VertexBuffer* m_Vb;
	VertexBufferLayout* m_Vbl;
public:
	BresenhamLine(int windowWidth, int windowHeight, Vec2 p1, Vec2 p2);
	~BresenhamLine();

	// Inherited via Drawable
	virtual VertexArray* GetVertexArray() override;
	virtual IndexBuffer* GetIndexBuffer() override;
	virtual void Draw() override;
};

