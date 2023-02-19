/*
 * Interface for all OpenGL shapes and other objects to be drawn.
 */
#pragma once

#include "../primitives/VertexArray.h"
#include "../primitives/IndexBuffer.h"
#include "../primitives/Shader.h"

class Drawable
{
protected:
	float GetNormalizedCoordinate(float coord, int min, int max);
public:
	virtual VertexArray* GetVertexArray() = NULL;
	virtual IndexBuffer* GetIndexBuffer() = NULL;
	virtual Shader* GetShader() = NULL;

	virtual void Draw() = NULL;
};
