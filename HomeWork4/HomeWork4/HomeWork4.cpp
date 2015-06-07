// HomeWork4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "lodepng.h"

static float GWindowWidth = 800.0f;
static float GWindowHeigth = 800.0f;
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat zDistance = -200.0f;

static GLfloat sphereRotate = 0.0f;

GLfloat amb[] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat dif[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat lightPos[] = { -50.0f, 50.0f, 100.0f, 1.0f };

GLuint texId[3];

void LoadTexture()
{
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

	glGenTextures(3, texId);
	glBindTexture(GL_TEXTURE_2D, texId[0]);

	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, 4, width[0], height[0], 0, GL_RGBA, GL_UNSIGNED_BYTE, image[0].data());

	glBindTexture(GL_TEXTURE_2D, texId[1]);
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, 4, width[1], height[1], 0, GL_RGBA, GL_UNSIGNED_BYTE, image[1].data());

	glBindTexture(GL_TEXTURE_2D, texId[2]);
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, 4, width[2], height[2], 0, GL_RGBA, GL_UNSIGNED_BYTE, image[2].data());
}

void makeSun()
{
	glBindTexture(GL_TEXTURE_2D, texId[0]);
	glColor3f(1.0f, 1.0f, 1.0f);
	auto sun = gluNewQuadric();
	gluQuadricDrawStyle(sun, GLU_FILL);
	gluQuadricNormals(sun, GLU_SMOOTH);
	gluQuadricTexture(sun, GL_TRUE);
	int radius = 5;
	gluSphere(sun, radius, radius * 10, radius * 10);
}

void makeEarth()
{
	glBindTexture(GL_TEXTURE_2D, texId[1]);
	glColor3f(1.0f, 1.0f, 1.0f);
	auto earth = gluNewQuadric();
	gluQuadricDrawStyle(earth, GLU_FILL);
	gluQuadricNormals(earth, GLU_SMOOTH);
	gluQuadricTexture(earth, GL_TRUE);
	int radius = 4;
	gluSphere(earth, radius, radius * 10, radius * 10);
}

void makeMoon()
{
	glBindTexture(GL_TEXTURE_2D, texId[2]);
	glColor3f(1.0f, 1.0f, 1.0f);
	auto moon = gluNewQuadric();
	gluQuadricDrawStyle(moon, GLU_FILL);
	gluQuadricNormals(moon, GLU_SMOOTH);
	gluQuadricTexture(moon, GL_TRUE);
	int radius = 3;
	gluSphere(moon, radius, radius * 10, radius * 10);
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	glPushMatrix();

	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, zDistance);

	// 기본 중심 위치에 태양그리기
	glRotatef(sphereRotate, 0.0f, 1.0f, 0.0f);
	makeSun();

	// 태양을 중심으로 위치를 계산하기 위해 pushmatrix를 함
	glPushMatrix();

	// 지구는 몇도를 돌릴까
	glRotatef(sphereRotate, 0.0f, 1.0f, 0.0f);
	// 태양을 중심으로 x축으로 떨어진 정도
	glTranslatef(30.0f, 0.0f, 0.0f);

	makeEarth();

	glPushMatrix();
	glRotatef(sphereRotate, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 20.0f);

	makeMoon();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	sphereRotate += 10.0f;
	if (sphereRotate > 360.0f)
	{
		sphereRotate = 0.0f;
	}

	glutSwapBuffers();
}

void SetupRC()
{
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	LoadTexture();
}

void ChangeSize(int w, int h)
{
	GLfloat fAspect = 0.0f;
	glViewport(0, 0, w, h);
	fAspect = (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, fAspect, 1.0f, 500.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -50.0f);

}

void TimerFunc(int value)
{
	glutPostRedisplay();

	glutTimerFunc(33, TimerFunc, 1);
}

void KeyControl(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		xRot -= 5.0f;
	}

	if (key == GLUT_KEY_DOWN)
	{
		xRot += 5.0f;
	}

	if (key == GLUT_KEY_LEFT)
	{
		yRot -= 5.0f;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		yRot += 5.0f;
	}

	if (key == GLUT_KEY_F1)
	{
		zDistance += 5.0f;
	}

	if (key == GLUT_KEY_F2)
	{
		zDistance -= 5.0f;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(GWindowWidth, GWindowHeigth);

	glutCreateWindow("Homework4");

	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(KeyControl);
	glutTimerFunc(2000, TimerFunc, 1);

	SetupRC();
	glutMainLoop();

	return 0;
}

