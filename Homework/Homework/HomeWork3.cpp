#include "stdafx.h"
#include "HomeWork3.h"

HomeWork3 GHomeWork3;

HomeWork3::HomeWork3()
{
}


HomeWork3::~HomeWork3()
{
}



void HomeWork3::Init()
{

	GLfloat vertices[][3] =
	{
		{ -m_Size, -m_Size, m_Size },
		{ -m_Size, m_Size, m_Size },
		{ m_Size, m_Size, m_Size },
		{ m_Size, -m_Size, m_Size },
		{ -m_Size, -m_Size, -m_Size },
		{ -m_Size, m_Size, -m_Size },
		{ m_Size, m_Size, -m_Size },
		{ m_Size, -m_Size, -m_Size },

	};

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_Vertices[i][j] = vertices[i][j];
		}
	}

	GLfloat color[][3] =
	{
		{ 0, 0, 1 }, 
		{ 0, 1, 1 }, 
		{ 0, 1, 0 }, 
		{ 1, 0, 1 }, 
		{ 0, 0, 0 }, 
		{ 0, 1, 0 }, 
		{ 1, 1, 0 }, 
		{ 1, 0, 0 },
	};

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m_Color[i][j] = color[i][j];
		}
	}
}

void HomeWork3::Render3DRect()
{
	glPushMatrix();
	glRotatef(m_RotateX, 1.0f, 0.0f, 0.0f);
	glRotatef(m_RotateY, 0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);
	glColor3fv(m_Color[0]); glVertex3fv(m_Vertices[0]);
	glColor3fv(m_Color[3]); glVertex3fv(m_Vertices[3]);
	glColor3fv(m_Color[2]); glVertex3fv(m_Vertices[2]);
	glColor3fv(m_Color[1]); glVertex3fv(m_Vertices[1]);
	glColor3fv(m_Color[2]); glVertex3fv(m_Vertices[2]);
	glColor3fv(m_Color[3]); glVertex3fv(m_Vertices[3]);
	glColor3fv(m_Color[7]); glVertex3fv(m_Vertices[7]);
	glColor3fv(m_Color[6]); glVertex3fv(m_Vertices[6]);
	glColor3fv(m_Color[3]); glVertex3fv(m_Vertices[3]);
	glColor3fv(m_Color[0]); glVertex3fv(m_Vertices[0]);
	glColor3fv(m_Color[4]); glVertex3fv(m_Vertices[4]);
	glColor3fv(m_Color[7]); glVertex3fv(m_Vertices[7]);
	glColor3fv(m_Color[1]); glVertex3fv(m_Vertices[1]);
	glColor3fv(m_Color[2]); glVertex3fv(m_Vertices[2]);
	glColor3fv(m_Color[6]); glVertex3fv(m_Vertices[6]);
	glColor3fv(m_Color[5]); glVertex3fv(m_Vertices[5]);
	glColor3fv(m_Color[4]); glVertex3fv(m_Vertices[4]);
	glColor3fv(m_Color[5]); glVertex3fv(m_Vertices[5]);
	glColor3fv(m_Color[6]); glVertex3fv(m_Vertices[6]);
	glColor3fv(m_Color[7]); glVertex3fv(m_Vertices[7]);
	glColor3fv(m_Color[5]); glVertex3fv(m_Vertices[5]);
	glColor3fv(m_Color[4]); glVertex3fv(m_Vertices[4]);
	glColor3fv(m_Color[0]); glVertex3fv(m_Vertices[0]);
	glColor3fv(m_Color[1]); glVertex3fv(m_Vertices[1]);
	glEnd();
	

	glPopMatrix();
}










