#pragma once
class Rect
{
public:
	using RectColor = GLfloat[3];

	Rect(int size, RectColor rectColor, int speedX, int speedY, GLfloat posX, GLfloat posY, int rectTag );
	~Rect();

	bool IsRectCollision(GLfloat posX, GLfloat posY, int size);
	void Render();


public:
	int			m_Size = 0;
	RectColor   m_RectColor;
	int		    m_SpeedX = 0;
	int			m_SpeedY = 0;
	GLfloat     m_PosX = 0.0f;
	GLfloat     m_PosY = 0.0f;
	int			m_RectTag = -1;


};

