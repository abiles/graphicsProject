#include "stdafx.h"
#include "HomeWork1.h"
#include "Rect.h"

HomeWork1 GHomeWork1;

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
	int size = 100;

	for (int i = 0; i < rectNum; ++i)
	{

		GLfloat posX = -GWindowWidth + i * 150;
		GLfloat posY = -GWindowHeight + i * 150;
		Rect::RectColor rectColor = {0.0f, 0.0f, 0.0f};

		switch (i)
		{
		case 0 :
			rectColor[0] = 0.5f;
			rectColor[1] = 0.5f;
			rectColor[2] = 0.5f;
			break;

		case 1 :
			rectColor[0] = 1.0f;
			break;

		case 2:
			rectColor[1] = 1.0f;
			break;
		case 3:
			rectColor[2] = 1.0f;
			break;
		case 4:
			rectColor[0] = 1.0f;
			rectColor[1] = 1.0f;
			break;
		case 5:
			rectColor[1] = 1.0f;
			rectColor[2] = 1.0f;
			break;
		default:
			break;
		}
		
		int speedX = rand() % 20 + 1;
		int speedY = rand() % 20 + 1;


		Rect* rect = new Rect(size, rectColor, speedX, speedY, posX, posY, i);
		m_pRects.push_back(rect);
	}
}

void HomeWork1::Run()
{
	for (auto pRect : m_pRects)
	{
		// 윈도우 전체에서 밖으로 나가는지 확인
		if (pRect->m_PosX < -GWindowWidth || pRect->m_PosX + pRect->m_Size > GWindowWidth)
		{
			pRect->m_SpeedX = -pRect->m_SpeedX;
		}

		if (pRect->m_PosY < -GWindowHeight || pRect->m_PosY + pRect->m_Size > GWindowHeight)
		{
			pRect->m_SpeedY = -pRect->m_SpeedY;
		}

		if (pRect->m_PosX + pRect->m_Size > GWindowWidth)
		{
			pRect->m_PosX = GWindowWidth - pRect->m_Size;
		}

		if (pRect->m_PosY + pRect->m_Size > GWindowHeight)
		{
			pRect->m_PosY = GWindowHeight - pRect->m_Size;
		}

		// Rect 끼리 충돌하는지 확인
		for (auto compareRect : m_pRects)
		{
			if (pRect->m_RectTag != compareRect->m_RectTag)
			{
				if (pRect->IsRectCollision(compareRect->m_PosX, compareRect->m_PosY, compareRect->m_Size))
				{
					pRect->m_SpeedX = -pRect->m_SpeedX;
					pRect->m_SpeedY = -pRect->m_SpeedY;
				}
			}
		}

		pRect->m_PosX += pRect->m_SpeedX;
		pRect->m_PosY += pRect->m_SpeedY;
	}

	

}

void HomeWork1::RenderRects()
{
	for (auto pRect : m_pRects)
	{
		pRect->Render();
	}
}

std::vector<Rect*>& HomeWork1::GetRects()
{
	return m_pRects;
}
