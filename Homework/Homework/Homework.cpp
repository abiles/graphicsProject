// Homework.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	// ��� ����� ��ɵ��� ȭ�鿡 ��Ÿ�� ������ �󿡼� ����
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow("Simple");

	// ������ �׸� �� ���� �Ҹ��� �Լ� 
	glutDisplayFunc(RenderScene);

	SetupRC();


	glutMainLoop();

	return 0;
}

