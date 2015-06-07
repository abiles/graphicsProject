#include "stdafx.h"
#include "HomeWork4.h"
#include "lodepng.h"

HomeWork4 GHomeWork4;

HomeWork4::HomeWork4()
{
}


HomeWork4::~HomeWork4()
{
}

void HomeWork4::Init()
{
	m_Amb[0] = 0.3f;
	m_Amb[1] = 0.3f;
	m_Amb[2] = 0.3f;
	m_Amb[3] = 1.0f;

	m_Dif[0] = 0.8f;
	m_Dif[1] = 0.8f;
	m_Dif[2] = 0.8f;
	m_Dif[3] = 1.0f;

	m_LightPos[0] = -50.0f;
	m_LightPos[1] = 50.0f;
	m_LightPos[2] = 100.0f;
	m_LightPos[3] = 1.0f;




	//gluSphere()
	std::vector<unsigned char> image[3];
	unsigned width[3], height[3], error;

	/// sun
	error = lodepng::decode(image[0], width[0], height[0], "sun.png");

	if (error)
	{
		printf_s("error %u : %s\n", error, lodepng_error_text(error));
	}

	printf_s("\nimage size is %i ", image[0].size());


	/// earth
	error = lodepng::decode(image[1], width[1], height[1], "earth.png");

	if (error)
	{
		printf_s("error %u : %s\n", error, lodepng_error_text(error));
	}

	printf_s("\nimage size is %i ", image[1].size());


	/// moon
	error = lodepng::decode(image[2], width[2], height[2], "moon.png");

	if (error)
	{
		printf_s("error %u : %s\n", error, lodepng_error_text(error));
	}

	printf_s("\nimage size is %i ", image[2].size());

	glGenTextures(3, m_TexId);

	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, m_TexId[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width[0], height[0], 0, GL_RGBA, GL_UNSIGNED_BYTE, image[0].data());

	glBindTexture(GL_TEXTURE_2D, m_TexId[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width[1], height[1], 0, GL_RGBA, GL_UNSIGNED_BYTE, image[1].data());

	glBindTexture(GL_TEXTURE_2D, m_TexId[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width[2], height[2], 0, GL_RGBA, GL_UNSIGNED_BYTE, image[2].data());


}

void HomeWork4::RenderSphere()
{
	glPushMatrix();

	glLightfv(GL_LIGHT0, GL_AMBIENT, m_Amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, m_Dif);
	glLightfv(GL_LIGHT0, GL_POSITION, m_LightPos);
	glEnable(GL_LIGHT0);

//	glEnable(GL_TEXTURE_2D);
	glRotatef(m_RotateX, 1.0f, 0.0f, 0.0f);
	glRotatef(m_RotateY, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, m_ZDistance);

	glBindTexture(GL_TEXTURE_2D, m_TexId[0]);
	glColor3f(1.0f, 1.0f, 1.0f);
	//gluSphere()
	//glutSolidTeapot(100.0f);
	
	glPopMatrix();


}
