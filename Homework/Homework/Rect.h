#pragma once
class Rect
{
public:
	using RectSize = GLfloat[4];
	using RectColor = GLfloat[3];


	Rect(RectSize rectSize, RectColor rectColor, GLfloat speed, GLfloat posX, GLfloat posY );
	~Rect();



private:
	RectSize    m_RectSize;
	RectColor   m_RectColor;
	GLfloat	    m_Speed = 0.0f;
	GLfloat     m_PosX = 0.0f;
	GLfloat     m_PosY = 0.0f;


};

