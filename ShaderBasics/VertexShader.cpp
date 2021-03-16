#include "pch.h"
#include "VertexShader.h"


std::string VertexShader::Source()
{
	//***** TODO *****//
	return 
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec4 aCol;\n"
		"uniform mat4 proj;\n"
		"uniform mat4 view;\n"
		"out vec4 col;\n"
		"void main()\n"
		"{\n"
		"	float x = cos(aPos.x)*cos(aPos.z);\n"
		"	float y = sin(aPos.z);\n"
		"	float z = sin(aPos.x)*cos(aPos.z);\n"
		"	gl_Position = (proj*view)*vec4(x, y, z, 1.0);\n"
		"	col=aCol;\n"
		"}\0";
}

VertexShader::VertexShader()
{
}


VertexShader::~VertexShader()
{
}
