#include "pch.h"
#include "ParticleFragShader.h"


ParticleFragShader::ParticleFragShader()
{
}


ParticleFragShader::~ParticleFragShader()
{
}

std::string ParticleFragShader::Source()
{//***** TODO *****//
	return
		"#version 330 core\n"
		"in vec4 col;\n"
		"in float age;\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
        "vec4 tmpCol = col;\n"
        "if(age <= 1) {"
        "    tmpCol.r = 1.0f * age;\n"
        "    tmpCol.g = 1.0f * age;\n"
        "    tmpCol.b = 1.0f * age;\n"
        "}\n"
        "if(age > 1 && age <= 2) {"
        "    tmpCol.r = 1.0f * age;\n"
        "    tmpCol.g = 0.5f * age;\n"
        "    tmpCol.b = 0.5f * age;\n"
        "}\n"
        "if(age > 2) {"
        "    tmpCol.r = 1.0f * age;\n"
        "    tmpCol.g = 0.0f;\n"
        "    tmpCol.b = 0.0f;\n"
        "}\n"
		"		FragColor = tmpCol;\n"
		"}\0";
}

int ParticleFragShader::Type()
{
	return GL_FRAGMENT_SHADER;
}
