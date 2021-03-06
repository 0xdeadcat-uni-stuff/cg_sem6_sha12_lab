#include "pch.h"
#include "VertexGenerator.h"
#include <iostream>

void VertexGenerator::generateOneVertex(float * vertices, int & index, float x, float y, float z, float r, float g, float b, bool quads)
{
	//***** TODO *****//
	vertices[index] = x;
	vertices[++index] = y;
	vertices[++index] = z;

	vertices[++index] = r;
	vertices[++index] = g;
	vertices[++index] = b;
	vertices[++index] = 1;

	index += 1;
}

float * VertexGenerator::generateVertieces(float* params)
{
	//***** TODO *****//
	float xStart = params[0];
	float xEnd = params[1];
	float xStep = params[2];
	float zStart = params[3];
	float zEnd = params[4];
	float zStep = params[5];

	size = (int)((1 + ((xEnd - xStart) / xStep)) * (1 + ((zEnd - zStart) / zStep)));
	quadSize = size;
	size += (int)((1 + ((xEnd - xStart) / (6 * xStep))) * (1 + ((zEnd - zStart) / (6 * zStep))));
	count = 4;
	dim = 7;
	int i = 0;
	float* vertices = new float[size*count*dim];
	for (float x = xStart; x < xEnd; x += xStep) {
		for (float z = zStart; z < zEnd; z += zStep) {
			generateOneVertex(vertices, i, x, 0, z, 0, 0, 1, true);
			generateOneVertex(vertices, i, x + xStep, 0, z, 0, 0, 1, true);

			generateOneVertex(vertices, i, x + xStep, 0, z + zStep, 0, 0, 1, true);
			generateOneVertex(vertices, i, x, 0, z + zStep, 0, 0, 1, true);
		}
	}

	for (float x = xStart; x < xEnd; x += xStep * 6) {
		for (float z = zStart; z < zEnd; z += zStep * 6) {

			generateOneVertex(vertices, i, x, 0, z, 0, 0, 1, false);
			generateOneVertex(vertices, i, x + 6 * xStep, 0, z, 0, 0, 1, false);

			generateOneVertex(vertices, i, x, 0, z, 0, 0, 1, false);
			generateOneVertex(vertices, i, x, 0, z + 6 * zStep, 0, 0, 1, false);
		}
	}
	return vertices;
}


VertexGenerator::VertexGenerator()
{

}


VertexGenerator::~VertexGenerator()
{
}
