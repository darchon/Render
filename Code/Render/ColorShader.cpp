/******************************
* ColorShader.cpp
******************************/
#include "ColorShader.h"

ColorShader::ColorShader()
{
	m_vertexShader = 0;
	m_pixelShader = 0;
	m_layout = 0;
	m_matrixBuffer = 0;
}


ColorShader::ColorShader(const ColorShader& other)
{
}


ColorShader::~ColorShader()
{
}

