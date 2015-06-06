#include "stdafx.h"
#include "Rect.h"




Rect::Rect(RectSize rectSize, RectColor rectColor, GLfloat speed, GLfloat posX, GLfloat posY)
{
	for (int i = 0; i < 4; ++i)
	{
		m_RectSize[i] = rectSize[i];
	}

	for (int i = 0; i < 3; ++i)
	{
		m_RectColor[i] = rectColor[i];
	}

	m_Speed = speed;
	m_PosX = posX;
	m_PosY = posY;

	glRectf(m_RectSize[0], m_RectSize[1], m_RectSize[2], m_RectSize[3]);
	glColor3f(m_RectColor[0], m_RectColor[1], m_RectColor[2]);
}


Rect::~Rect()
{
}
