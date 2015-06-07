#pragma once
class HomeWork4
{
public:
	HomeWork4();
	~HomeWork4();

	void Init();
	void RenderSphere();

public:
	GLuint m_TexId[3];

	float m_RotateX = 0.0f;
	float m_RotateY = 0.0f;
	float m_ZDistance = 0.0f;

	GLfloat m_Amb[4];
	GLfloat m_Dif[4];
	GLfloat m_LightPos[4];
};

extern HomeWork4 GHomeWork4;

