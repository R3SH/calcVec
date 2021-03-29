#include "lVec.h"
#include "memory.h"
#include "math.h"

#define M_PI       3.14159265358979323846   // pi from <corecrt_math_defines.h>

LVec::LVec()
{
	this->vertex = nullptr;
}

LVec::LVec(struct point spnt)
{
	this->vertex = new point[2];
}

LVec::LVec(const LVec& src)
{
	if(this->vertex == nullptr)
		this->vertex = new point[2];
	memcpy(this->vertex, src.vertex, sizeof(point)*2);
}

LVec::~LVec()
{
	delete[] this->vertex;
}

double LVec::getLength()
{
	if (this->vertex != nullptr)
	{
		return sqrt((this->vertex[1].x - this->vertex[0].x)*(this->vertex[1].x - this->vertex[0].x) +
			(this->vertex[1].y - this->vertex[0].y)*(this->vertex[1].y - this->vertex[0].y));
	}
	std::cout << "method getLength: Can't get length of non-existing vector" << std::endl;
	system("PAUSE");
}

double LVec::getAngle(LVec& fVec, LVec& sVec)
{
	if (fVec.vertex != nullptr && sVec.vertex != nullptr)
	{
		return acos(((fVec.vertex[1].x - fVec.vertex[0].x)*(sVec.vertex[1].x - sVec.vertex[0].x) + 
			(fVec.vertex[1].y - fVec.vertex[0].y) * (sVec.vertex[1].y - sVec.vertex[0].y)) /
			((fVec.getLength()) * (sVec.getLength()))) * 180 / M_PI;
	}
	std::cout << "ERROR getAngle method: Can't getAngle of non-exsisting vector/vectors" << std::endl;
	system("PAUSE");
}

point LVec::get_sp()
{
	if(this->vertex)
		return this->vertex[0];
	std::cout << "ERROR get_sp method: Can't get coords of non-existing vector" << std::endl;
	system("PAUSE");
}

point LVec::get_ep()
{
	if(this->vertex)
		return this->vertex[1];
	std::cout << "ERROR get_ep method: Can't get coords of non-existing vector" << std::endl;
	system("PAUSE");
}

void LVec::set_sp()
{
	if (this->vertex == nullptr)
		this->vertex = new point[2];

	std::cout << "Enter coords of starting point " << std::endl << "Enter x: ";
	std::cin >> this->vertex[0].x;
	std::cout << "Enter y: ";
	std::cin >> this->vertex[0].y;
}

void LVec::set_ep()
{
	if (this->vertex == nullptr)
		this->vertex = new point[2];

	std::cout << "Enter coords of ending point " << std::endl << "Enter x: ";
	std::cin >> this->vertex[1].x;
	std::cout << "Enter y: ";
	std::cin >> this->vertex[1].y;
}

void LVec::printVec()
{
	if (this->vertex == nullptr)
	{
		std::cout << "Can't print non-existent vector" << std::endl;
		return;
	}

	std::cout << "Start coords:\nx = " << this->vertex[0].x << "\ty = " << this->vertex[0].y << std::endl;
	std::cout << "End coords:\nx = " << this->vertex[1].x << "\ty = " << this->vertex[1].y << std::endl;
}

void operator-(const LVec& src)
{
	if (src.vertex == nullptr)
	{
		std::cout << "ERROR operator-: Can't invert non-existing vector" << std::endl;
		system("PAUSE");
		return;
	}
	/*struct point tmpoint = src.vertex[0];
	src.vertex[0] = src.vertex[1];
	src.vertex[1] = tmpoint;*/
	src * (-1);
}

void operator*(const LVec& src, double mult)
{
	if (src.vertex == nullptr)
	{
		std::cout << "ERROR: Can't multiply non-existing vector" << std::endl;
		system("PAUSE");
		return;
	}

	src.vertex[0].x *= mult;
	src.vertex[0].y *= mult;
	src.vertex[1].x *= mult;
	src.vertex[1].y *= mult;
}

double operator*(LVec& lSrc, LVec& rSrc)
{
	if (lSrc.vertex != nullptr || rSrc.vertex != nullptr)
		return (lSrc.getLength())*(rSrc.getLength())*(cos(lSrc.getAngle(lSrc, rSrc) * M_PI / 180));
	
	std::cout << "ERROR: Can't multiply non-existing vector/vectors" << std::endl;
	system("PAUSE");
}
