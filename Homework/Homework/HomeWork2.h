#pragma once

#define GL_PI 3.14f

class HomeWork2
{
public:
	HomeWork2();
	~HomeWork2();

	void RenderSpiralPoints();

public:
	GLfloat m_RotateX = 0.0f;
	GLfloat m_RotateY = 0.0f;
};

extern HomeWork2 GHomeWork2;