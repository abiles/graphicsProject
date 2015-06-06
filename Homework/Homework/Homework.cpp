// Homework.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Rect.h"
#include "HomeWork1.h"



float GWindowWidth = 800.0f;
float GWindowHeight = 600.0f;


void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	GHomeWork1.RenderRect();

	glutSwapBuffers();

}

void ChangeSize(GLsizei w, GLsizei h)
{
	GWindowWidth = w;
	GWindowHeight = h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glOrtho(-w, w, -h, h, 1.0f, -1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SetupRC()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	GHomeWork1.Init();
}

void TimerFunc(int value)
{
	GHomeWork1.Run();
	glutPostRedisplay();

	glutTimerFunc(33, TimerFunc, 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(NULL));


	// 모든 드로잉 명령들을 화면에 나타난 윈도우 상에서 수행
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(GWindowWidth, GWindowHeight);

	glutCreateWindow("Homework");

	// 윈도우 그릴 때 마다 불리는 함수 
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(2000, TimerFunc, 1);

	SetupRC();
	glutMainLoop();

	return 0;
}

