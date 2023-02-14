/*
 * Definitions for the Line Drawers w.r.t. the Tasks 1 and 2
 */
#pragma once

class LineRenderer
{
private:
	unsigned int m_WindowWidth;
	unsigned int m_WindowHeight;
public:
	enum LineDrawingAlgorithm {
		LINE_ALGO_DEFAULT = 0,
		LINE_ALGO_BRESENHAM = 1
	};

	LineRenderer(unsigned int windowWidth, unsigned int windowHeight);

	int DrawLine(LineDrawingAlgorithm alg);
};

