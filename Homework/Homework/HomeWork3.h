#pragma once
class HomeWork3
{
public:
	HomeWork3();
	~HomeWork3();

	void Init();
	void Render3DRect();


public:
	GLfloat m_Vertices[8][3];
	GLfloat m_Color[8][3];
	int		m_Size = 100;
	GLfloat m_RotateX = 0.0f;
	GLfloat m_RotateY = 0.0f;

};

extern HomeWork3 GHomeWork3;