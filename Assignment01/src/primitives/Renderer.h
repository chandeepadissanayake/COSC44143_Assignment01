/*
 * Definitions for a Renderer and its functionality.
 * Adopted, with appropriate changes, from Yan Chernikov's tutorials.
 * Tutorial URL: https://www.youtube.com/watch?v=W3gAzLwfIP0&list=PLlrATfBNZ98foTJPJ_Ev03o2oq3-GGOS2
 */
#pragma once

#include "../drawables/Drawable.h"

class Renderer
{
public:
	void Draw(Drawable& drawable) const;
};

