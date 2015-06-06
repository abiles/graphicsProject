#include "stdafx.h"
#include "HomeWork1.h"
#include "Rect.h"


HomeWork1::HomeWork1()
{
}


HomeWork1::~HomeWork1()
{
	for (auto pRect : m_pRects)
	{
		if (pRect)
		{
			delete pRect;
		}
		pRect = nullptr;
	}
}

void HomeWork1::Init()
{
	int rectNum = 5;
	int size = 30;

	for (int i = 0; i < rectNum; ++i)
	{
		Rect::RectSize rectSize = { i * 50, i * 50, i * 50 + size, i * 50 + size };

		Rect::RectColor rectColor = { i * 0.2f, i * 0.1f, i * 0.05f };
		
		GLfloat speed = i * 10 + 10;

		GLfloat posX = i * 50;
		GLfloat posY = i * 50;

		Rect* rect = new Rect(rectSize, rectColor, speed, posX, posY);
	}
}

void HomeWork1::Run()
{

}
