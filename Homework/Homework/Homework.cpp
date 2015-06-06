// Homework.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void SetupRC()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 모든 드로잉 명령들을 화면에 나타난 윈도우 상에서 수행
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("Simple");

	// 윈도우 그릴 때 마다 불리는 함수 
	glutDisplayFunc(RenderScene);

	SetupRC();


	glutMainLoop();

	return 0;
}

