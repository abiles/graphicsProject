#include "stdafx.h"
#include "HomeWork2.h"

HomeWork2 GHomeWork2;

HomeWork2::HomeWork2()
{
}


HomeWork2::~HomeWork2()
{
}

void HomeWork2::RenderSpiralPoints()
{
	GLfloat x, y, z, angle;
	glColor3f(0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glRotatef(m_RotateX, 1.0f, 0.0f, 0.0f);
	glRotatef(m_RotateY, 0.0f, 1.0f, 0.0f);
	
	glBegin(GL_POINTS);
	z = -50.0f;

	float range = 10.0f;

	for (angle = 0.0f; angle <= 2.0f*GL_PI* 50.0f;  angle += 0.1f)
	{
		x = range * cos(angle);
		y = range * sin(angle);
		glVertex3f(x, y, z);
		z += 0.5f;
		range += 0.5f;
	}
	glEnd();
	glPopMatrix();

}
