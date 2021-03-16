#include "pch.h"
#include "Particle.h"


void Particle::operator()(float* vertices, int& index, float dT, bool updateAge)
{
	//***** TODO *****//
	if (updateAge)
		age += dT;
	vertices[index] = age;
	vertices[++index] = sPosX;
	vertices[++index] = sPosY;
	vertices[++index] = sPosZ;
	vertices[++index] = 1.0f;
	vertices[++index] = 1.0f;
	vertices[++index] = 1.0f;
	vertices[++index] = 1.0f;
	vertices[++index] = phaseX;
	vertices[++index] = phaseY;
	index += 1;
}

Particle::~Particle()
{
}
