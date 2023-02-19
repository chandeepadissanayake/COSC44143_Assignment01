/*
 * Definitions for Renderer.h
 */
#include "Renderer.h"

#include "VertexArray.h"
#include "IndexBuffer.h"

void Renderer::Draw(Drawable& drawable) const
{
	VertexArray* va = drawable.GetVertexArray();
	IndexBuffer* ib = drawable.GetIndexBuffer();
	Shader* shader = drawable.GetShader();

	if (shader != nullptr)
	{
		shader->Bind();
	}

	if (va != nullptr)
	{
		va->Bind();
	}

	if (ib != nullptr)
	{
		ib->Bind();
	}

	drawable.Draw();
}
