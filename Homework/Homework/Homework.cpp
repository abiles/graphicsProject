// Homework.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Rect.h"
#include "HomeWork1.h"
#include "HomeWork2.h"
#include "HomeWork3.h"


float GWindowWidth = 800.0f;
float GWindowHeight = 600.0f;
float GRotateX = 0.0f;
float GRotateY = 0.0f;

static float m_RotX = 0.0f;
static float m_RotY = 0.0f;

static bool w1 = true;
static bool w2 = false;
static bool w3 = false;



void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (w1)
	{
		GHomeWork1.RenderRects();
	}
	else if (w2)
	{
		GHomeWork2.RenderSpiralPoints();

	}
	else if (w3)
	{
		GHomeWork3.Render3DRect();
	}

	glutSwapBuffers();

}

void ChangeSize(GLsizei w, GLsizei h)
{
	GWindowWidth = w;
	GWindowHeight = h;

	GLfloat nRange = 500.0f;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-w, w, -h, h, -nRange, nRange);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SetupRC()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	GHomeWork1.Init();
	GHomeWork3.Init();
}

void TimerFunc(int value)
{

	if (w1)
	{
		GHomeWork1.Run();
	}

	glutPostRedisplay();

	glutTimerFunc(33, TimerFunc, 1);
}

void KeyControl(int key, int x, int y)
{

	

	switch (key)
	{
	case GLUT_KEY_UP:
		if (w2)
		{
			GHomeWork2.m_RotateX -= 5.0f;
		}
		else if (w3)
		{
			GHomeWork3.m_RotateX -= 5.0f;
		}
		break;

	case GLUT_KEY_DOWN:
		if (w2)
		{
			GHomeWork2.m_RotateX += 5.0f;
		}
		else if (w3)
		{
			GHomeWork3.m_RotateX += 5.0f;
		}
		break;

	case GLUT_KEY_LEFT:
		if (w2)
		{
			GHomeWork2.m_RotateY -= 5.0f;
		}
		else if (w3)
		{
			GHomeWork3.m_RotateY -= 5.0f;
		}
		break;

	case GLUT_KEY_RIGHT:
		if (w2)
		{
			GHomeWork2.m_RotateY += 5.0f;
		}
		else if (w3)
		{
			GHomeWork3.m_RotateY += 5.0f;
		}
		break;
		
	case GLUT_KEY_F1:
		w1 = true;
		w2 = false;
		w3 = false;
		break;

	case GLUT_KEY_F2:
		w1 = false;
		w2 = true;
		w3 = false;

		break;

	case GLUT_KEY_F3:
		w1 = false;
		w2 = false;
		w3 = true;
		break;

	case GLUT_KEY_F5:
		glEnable(GL_LIGHTING);
		break;
	case GLUT_KEY_F6:
		glDisable(GL_LIGHTING);
		break;
	case GLUT_KEY_F12:
		if (w2)
		{
			GHomeWork2.m_RotateX = 0.0f;
			GHomeWork2.m_RotateY = 0.0f;
		}
		else if (w3)
		{
			GHomeWork3.m_RotateX = 0.0f;
			GHomeWork3.m_RotateY = 0.0f;
		}
	default:
		break;
	}
	
	glutPostRedisplay();
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));


	// 모든 드로잉 명령들을 화면에 나타난 윈도우 상에서 수행
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(GWindowWidth, GWindowHeight);
	
	glutCreateWindow("Homework");

	// 윈도우 그릴 때 마다 불리는 함수 
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(KeyControl);
	glutTimerFunc(2000, TimerFunc, 1);

	SetupRC();
	glutMainLoop();

	return 0;
}

