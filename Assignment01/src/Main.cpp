/*
 * Entry point for the set of programs
 */
#include <iostream>

#include "LineRenderer.h"
#include "ModelRenderer.h"

int main(int argc, char** argv)
{
	switch (argv[1][0])
	{
		case '1':
		{
			LineRenderer lineRenderer(640, 480);
			return lineRenderer.DrawLine(LineRenderer::LineDrawingAlgorithm::LINE_ALGO_DEFAULT);
			break;
		}
		case '2':
		{
			LineRenderer lineRenderer(640, 480);
			return lineRenderer.DrawLine(LineRenderer::LineDrawingAlgorithm::LINE_ALGO_BRESENHAM);
			break;
		}
		case '3':
		{
			ModelRenderer modelRenderer("Backpack Model", 800, 600);
			return modelRenderer.DrawModel();
			break;
		}
		default:
		{
			std::cout << "No task was provided to execute." << std::endl;
			return -1;
		}
	}
}
