#pragma once
#include "iostream"
using namespace std;
class Element
{
private:
	int ElementStartX;
	int ElementStartY;
	int ElementEndX;
	int ElementEndY;
	int ElementStart;
	int ElementEnd;
	int ElementType;
public:
	void SetElementStart(int Start,int width)
	{
		ElementStart = Start-1;
		ElementStartY = (int)(Start-1)/(width);
		if(ElementStartY%2==0)
			ElementStartX = (Start-1)%(width);
		else ElementStartX = width-(Start-1)%width-1;
	}

	void SetElementEnd(int End,int width)
	{
		ElementEnd = End-1;
		ElementEndY = (int)(End-1)/(width);
		if(ElementEndY%2==0)
			ElementEndX = (End-1)%(width);
		else ElementEndX = width-(End-1)%width-1;
	}

	int S()
	{
		return ElementStart;
	}

	int E()
	{
		return ElementEnd;
	}

	int SX()
	{
		return ElementStartX; 
	}

	int SY()
	{
		return ElementStartY;
	}

	int EX()
	{
		return ElementEndX;
	}

	int EY()
	{
		return ElementEndY;
	}

	Element(void)
	{
	}

	virtual ~Element(void)
	{
	}
};

