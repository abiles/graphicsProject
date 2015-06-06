#include "stdafx.h"
#include "Rect.h"




Rect::Rect(int rectSize, RectColor rectColor, int speedX, int speedY, GLfloat posX, GLfloat posY, int rectTag)
{

	for (int i = 0; i < 3; ++i)
	{
		m_RectColor[i] = rectColor[i];
	}

	m_SpeedX = speedX;
	m_SpeedY = speedY;
	
	m_PosX = posX;
	m_PosY = posY;
	m_Size = rectSize;

	m_RectTag = rectTag;

	//glRectf(m_PosX, m_PosY, m_PosX + m_Size, m_PosY + m_Size);
	//glColor3f(m_RectColor[0], m_RectColor[1], m_RectColor[2]);
}


Rect::~Rect()
{
}

bool Rect::IsRectCollision(GLfloat posX, GLfloat posY, int size)
{
	if (m_PosX > posX + size)
	{
		return false;
	}

	if (m_PosY > posY + size)
	{
		return false;
	}

	if (posX > m_PosX + m_Size)
	{
		return false;
	}

	if (posY > m_PosY + m_Size)
	{
		return false;
	}

	return true;
}

void Rect::Render()
{
	glColor3f(m_RectColor[0], m_RectColor[1], m_RectColor[2]);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(m_PosX, m_PosY, m_PosX + m_Size, m_PosY + m_Size);

}
