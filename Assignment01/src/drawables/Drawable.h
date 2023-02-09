#pragma once

#include "../primitives/VertexArray.h"
#include "../primitives/IndexBuffer.h"

class Drawable
{
protected:
	float GetNormalizedCoordinate(float coord, int min, int max);
public:
	virtual VertexArray* GetVertexArray() = NULL;
	virtual IndexBuffer* GetIndexBuffer() = NULL;

	virtual void Draw() = NULL;
};
