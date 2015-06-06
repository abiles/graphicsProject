// Homework1 : Rect 충돌 관련 숙제

#pragma once

class Rect;

class HomeWork1
{
public:
	HomeWork1();
	~HomeWork1();

	void Init();
	void Run();

private:
	bool			   m_IsFirstCall = false;
	
	std::vector<Rect*> m_pRects;
};

