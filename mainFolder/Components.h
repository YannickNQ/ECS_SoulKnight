#pragma once
#include "Vec2.h"
#include "../winbgim.h"
#include "palette.h"

#define M_PI 3.14159265358979323846

class CTransform
{
public:
	Vec2 pos = { 0.0, 0.0 };
	Vec2 velocity = { 0.0,0.0 };
	float angle = 0;

	CTransform(const Vec2 & p, const Vec2 & v, float a)
		: pos(p), velocity(v), angle(a) {}
};

class CShape
{
	float m_scale;
public:
	CShape(float scale): m_scale(scale)
	{
		
	}

	void getxy(int x, int y, int L, int alfa, int& _x, int& _y) {
		_x = L * cos(M_PI * alfa / 180) + x;
		_y = L * sin(M_PI * alfa / 180) + y;
	}

	void Player(const Vec2& position, float angle, const std::string& heroType)
	{
		/*int x = static_cast<int>(position.x * m_scale);
		int y = static_cast<int>(position.y * m_scale);*/

		if (heroType == "Hero1")
		{
			//knightLeft(position, m_scale);
		} 
		else if (heroType == "Hero2")
		{
			//TODO
		}
		else if (heroType == "Hero3")
		{
			//TODO
		}
	}

	void knightLeft(const float x, const float y)
	{
		float scale = 1.2 * m_scale;
		setfillstyle(SOLID_FILL, BLACK);
		// Heroe border
		// casco
		bar(x + 2.4 * scale, y, x + 5.2 * scale, y + .4 * scale);
		bar(x + 1.6 * scale, y + .4 * scale, x + 2.4 * scale, y + .8 * scale);
		bar(x + 1.2 * scale, y + .8 * scale, x + 1.6 * scale, y + 1.2 * scale);
		bar(x + .8 * scale, y + 1.2 * scale, x + 1.2 * scale, y + 2.0 * scale);
		bar(x + .4 * scale, y + 2.0 * scale, x + .8 * scale, y + 3.2 * scale);
		// Eyes
		bar(x, y + 3.2 * scale, x + .4 * scale, y + 4.8 * scale);
		// Chin
		bar(x + .4 * scale, y + 4.8 * scale, x + .8 * scale, y + 6.4 * scale);
		// Body
		bar(x + .8 * scale, y + 6.4 * scale, x + 1.2 * scale, y + 7.6 * scale);
		bar(x + 1.2 * scale, y + 7.6 * scale, x + 1.6 * scale, y + 8.8 * scale);
		// Line before Foot
		bar(x + 1.6 * scale, y + 8.8 * scale, x + 6.4 * scale, y + 9.2 * scale);
		// Foot
		bar(x + 1.6 * scale, y + 9.2 * scale, x + 2.8 * scale, y + 9.6 * scale);
		bar(x + 4.8 * scale, y + 9.2 * scale, x + 6.0 * scale, y + 9.6 * scale);
		bar(x + 2.0 * scale, y + 9.6 * scale, x + 2.8 * scale, y + 10. * scale);
		bar(x + 5.2 * scale, y + 9.6 * scale, x + 6.0 * scale, y + 10. * scale);
		// Second Part
		// Body
		bar(x + 6.4 * scale, y + 7.6 * scale, x + 7.2 * scale, y + 8.8 * scale);
		// Chalina
		bar(x + 6.8 * scale, y + 8.8 * scale, x + 7.2 * scale, y + 9.2 * scale);
		bar(x + 7.2 * scale, y + 9.2 * scale, x + 7.6 * scale, y + 9.6 * scale);
		bar(x + 7.6 * scale, y + 9.6 * scale, x + 10. * scale, y + 10. * scale);
		bar(x + 9.6 * scale, y + 9.2 * scale, x + 10. * scale, y + 9.6 * scale);
		bar(x + 8.8 * scale, y + 8.8 * scale, x + 9.6 * scale, y + 9.2 * scale);
		bar(x + 8.4 * scale, y + 8.0 * scale, x + 8.8 * scale, y + 8.8 * scale);
		bar(x + 8.0 * scale, y + 6.8 * scale, x + 8.4 * scale, y + 8.0 * scale);
		bar(x + 7.6 * scale, y + 6.4 * scale, x + 8.0 * scale, y + 6.8 * scale);
		bar(x + 6.8 * scale, y + 6.0 * scale, x + 7.6 * scale, y + 6.4 * scale);
		// Head
		bar(x + 6.8 * scale, y + 2.0 * scale, x + 7.2 * scale, y + 6.0 * scale);
		bar(x + 6.4 * scale, y + 1.2 * scale, x + 6.8 * scale, y + 2.0 * scale);
		bar(x + 6.0 * scale, y + .8 * scale, x + 6.4 * scale, y + 1.2 * scale);
		bar(x + 5.2 * scale, y + .4 * scale, x + 6.0 * scale, y + .8 * scale);

		// Filling
		setfillstyle(SOLID_FILL, knightPalette().grayBlue);
		bar(x + 2.4 * scale, y + .4 * scale, x + 5.2 * scale, y + 0.8 * scale);
		bar(x + 1.6 * scale, y + .8 * scale, x + 6.0 * scale, y + 1.2 * scale);
		bar(x + 1.2 * scale, y + 1.2 * scale, x + 6.4 * scale, y + 2.0 * scale);
		bar(x + .8 * scale, y + 5.2 * scale, x + 1.2 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightBlue);
		bar(x + 2.8 * scale, y + .8 * scale, x + 4.0 * scale, y + 1.2 * scale);
		bar(x + 2.8 * scale, y + 1.2 * scale, x + 3.2 * scale, y + 1.6 * scale);

		setfillstyle(SOLID_FILL, knightPalette().blue);
		bar(x + 6.0 * scale, y + 1.6 * scale, x + 6.4 * scale, y + 2.0 * scale);
		bar(x + 6.4 * scale, y + 2.0 * scale, x + 6.8 * scale, y + 6.4 * scale);
		bar(x + 6.0 * scale, y + 5.6 * scale, x + 6.4 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().darkBlue);
		bar(x + 4.8 * scale, y + 1.6 * scale, x + 6.0 * scale, y + 2.0 * scale);
		bar(x + .8 * scale, y + 2.0 * scale, x + 6.4 * scale, y + 2.8 * scale);
		bar(x + 4.8 * scale, y + 2.8 * scale, x + 6.4 * scale, y + 3.2 * scale);
		bar(x + 5.2 * scale, y + 3.2 * scale, x + 6.4 * scale, y + 5.6 * scale);
		bar(x + 4.0 * scale, y + 4.8 * scale, x + 6.0 * scale, y + 6.4 * scale);
		bar(x + .8 * scale, y + 4.8 * scale, x + 1.2 * scale, y + 5.2 * scale);
		bar(x + 1.6 * scale, y + 7.6 * scale, x + 6.4 * scale, y + 8.8 * scale);

		setfillstyle(SOLID_FILL, knightPalette().grayBlue);
		bar(x + 4.4 * scale, y + 5.6 * scale, x + 5.4 * scale, y + 6.0 * scale);
		bar(x + 4.4 * scale, y + 6.0 * scale, x + 5.0 * scale, y + 6.4 * scale);
		bar(x + 3.2 * scale, y + 8.0 * scale, x + 5.2 * scale, y + 8.6 * scale);
		bar(x + 1.6 * scale, y + 8.0 * scale, x + 2.8 * scale, y + 8.6 * scale);
		bar(x + 1.6 * scale, y + 7.6 * scale, x + 2.0 * scale, y + 8.0 * scale);

		setfillstyle(SOLID_FILL, knightPalette().blue);
		bar(x + 6.0 * scale, y + 7.6 * scale, x + 6.4 * scale, y + 8.4 * scale);
		bar(x + 1.6 * scale, y + 8.4 * scale, x + 2.0 * scale, y + 8.8 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightBlue);
		bar(x + 2.0 * scale, y + 7.6 * scale, x + 2.4 * scale, y + 8.0 * scale);
		bar(x + 2.4 * scale, y + 8.0 * scale, x + 3.2 * scale, y + 8.4 * scale);
		bar(x + 3.2 * scale, y + 7.6 * scale, x + 3.6 * scale, y + 8.0 * scale);

		setfillstyle(SOLID_FILL, knightPalette().pink);
		bar(x + .8 * scale, y + 3.6 * scale, x + 4.6 * scale, y + 4.8 * scale);

		setfillstyle(SOLID_FILL, knightPalette().orange);
		bar(x + 5.0 * scale, y + 3.2 * scale, x + 5.4 * scale, y + 4.8 * scale);
		bar(x + 4.6 * scale, y + 2.8 * scale, x + 5.0 * scale, y + 3.2 * scale);
		bar(x + .8 * scale, y + 2.8 * scale, x + 1.6 * scale, y + 3.2 * scale);
		bar(x + .4 * scale, y + 3.2 * scale, x + .8 * scale, y + 4.4 * scale);
		bar(x + 1.6 * scale, y + 4.4 * scale, x + 2.0 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightOrange);
		bar(x + 1.6 * scale, y + 2.8 * scale, x + 4.6 * scale, y + 3.2 * scale);
		bar(x + 4.6 * scale, y + 3.2 * scale, x + 5.0 * scale, y + 4.8 * scale);
		bar(x + 3.6 * scale, y + 4.4 * scale, x + 4.6 * scale, y + 4.8 * scale);
		bar(x + 3.6 * scale, y + 4.8 * scale, x + 4.0 * scale, y + 6.4 * scale);
		bar(x + .4 * scale, y + 4.4 * scale, x + 1.6 * scale, y + 4.8 * scale);
		bar(x + 1.2 * scale, y + 4.8 * scale, x + 1.6 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightYellow);
		bar(x + 2.0 * scale, y + 2.8 * scale, x + 2.4 * scale, y + 3.2 * scale);
		bar(x + 2.8 * scale, y + 2.8 * scale, x + 4.0 * scale, y + 3.2 * scale);

		setfillstyle(SOLID_FILL, knightPalette().brown);
		bar(x + .8 * scale, y + 3.2 * scale, x + 4.6 * scale, y + 3.6 * scale);
		bar(x + .8 * scale, y + 3.6 * scale, x + 1.2 * scale, y + 4.4 * scale);

		setfillstyle(SOLID_FILL, BLACK);
		bar(x + 1.6 * scale, y + 3.6 * scale, x + 2.0 * scale, y + 4.4 * scale);
		bar(x + 3.6 * scale, y + 3.6 * scale, x + 4.0 * scale, y + 4.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().skin);
		bar(x + 2.0 * scale, y + 4.8 * scale, x + 3.6 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().red);
		// mouth
		bar(x + 2.4 * scale, y + 5.2 * scale, x + 3.2 * scale, y + 5.6 * scale);
		// Chalina
		bar(x + 1.2 * scale, y + 6.4 * scale, x + 7.6 * scale, y + 7.6 * scale);
		bar(x + 7.2 * scale, y + 6.8 * scale, x + 8.0 * scale, y + 8.8 * scale);
		bar(x + 7.8 * scale, y + 8.8 * scale, x + 8.4 * scale, y + 9.2 * scale);
		bar(x + 8.4 * scale, y + 9.2 * scale, x + 9.6 * scale, y + 9.6 * scale);

		setfillstyle(SOLID_FILL, knightPalette().darkRed);
		bar(x + 1.2 * scale, y + 7.2 * scale, x + 1.6 * scale, y + 7.6 * scale);
		bar(x + 6.4 * scale, y + 6.8 * scale, x + 7.2 * scale, y + 7.2 * scale);
		bar(x + 6.8 * scale, y + 7.2 * scale, x + 7.4 * scale, y + 7.6 * scale);
		bar(x + 7.2 * scale, y + 7.6 * scale, x + 7.4 * scale, y + 9.2 * scale);
		bar(x + 7.2 * scale, y + 8.8 * scale, x + 7.8 * scale, y + 9.2 * scale);
		bar(x + 7.6 * scale, y + 9.2 * scale, x + 8.4 * scale, y + 9.6 * scale);
		bar(x + 8.0 * scale, y + 8.0 * scale, x + 8.4 * scale, y + 8.8 * scale);
		bar(x + 8.4 * scale, y + 8.8 * scale, x + 8.8 * scale, y + 9.2 * scale);

		setfillstyle(SOLID_FILL, knightPalette().hardOrange);
		bar(x + 1.6 * scale, y + 6.4 * scale, x + 4.4 * scale, y + 6.8 * scale);
		bar(x + 2.0 * scale, y + 6.8 * scale, x + 5.2 * scale, y + 7.2 * scale);
	}

	void knightRight(const float x, const float y)
	{
		float scale = 1.2 * m_scale;
		setfillstyle(SOLID_FILL, BLACK);
		//Heroe border
		//casco
		bar(x + 4.8 * scale, y, x + 7.6 * scale, y + .4 * scale);
		bar(x + 7.6 * scale, y + .4 * scale, x + 8.4 * scale, y + .8 * scale);
		bar(x + 8.4 * scale, y + .8 * scale, x + 8.8 * scale, y + 1.2 * scale);
		bar(x + 8.8 * scale, y + 1.2 * scale, x + 9.2 * scale, y + 2.0 * scale);
		bar(x + 9.2 * scale, y + 2.0 * scale, x + 9.6 * scale, y + 3.2 * scale);
		//Eyes
		bar(x + 9.6 * scale, y + 3.2 * scale, x + 10. * scale, y + 4.8 * scale);
		//Chin
		bar(x + 9.2 * scale, y + 4.8 * scale, x + 9.6 * scale, y + 6.4 * scale);
		//Body
		bar(x + 8.8 * scale, y + 6.4 * scale, x + 9.2 * scale, y + 7.6 * scale);
		bar(x + 8.4 * scale, y + 7.6 * scale, x + 8.8 * scale, y + 8.8 * scale);
		//Line before Foot
		bar(x + 3.6 * scale, y + 8.8 * scale, x + 8.4 * scale, y + 9.2 * scale);
		//Foot
		bar(x + 7.2 * scale, y + 9.2 * scale, x + 8.4 * scale, y + 9.6 * scale);
		bar(x + 4.0 * scale, y + 9.2 * scale, x + 5.2 * scale, y + 9.6 * scale);
		bar(x + 7.2 * scale, y + 9.6 * scale, x + 8.0 * scale, y + 10. * scale);
		bar(x + 4.0 * scale, y + 9.6 * scale, x + 4.8 * scale, y + 10. * scale);
		//Second Part
		//Body
		bar(x + 2.8 * scale, y + 7.6 * scale, x + 3.6 * scale, y + 8.8 * scale);
		//Chalina
		bar(x + 2.8 * scale, y + 8.8 * scale, x + 3.2 * scale, y + 9.2 * scale);
		bar(x + 2.4 * scale, y + 9.2 * scale, x + 2.8 * scale, y + 9.6 * scale);
		bar(x, y + 9.6 * scale, x + 2.4 * scale, y + 10. * scale);
		bar(x, y + 9.2 * scale, x + .4 * scale, y + 9.6 * scale);
		bar(x + .4 * scale, y + 8.8 * scale, x + 1.2 * scale, y + 9.2 * scale);
		bar(x + 1.2 * scale, y + 8.0 * scale, x + 1.6 * scale, y + 8.8 * scale);
		bar(x + 1.6 * scale, y + 6.8 * scale, x + 2.0 * scale, y + 8.0 * scale);
		bar(x + 2.0 * scale, y + 6.4 * scale, x + 2.4 * scale, y + 6.8 * scale);
		bar(x + 2.4 * scale, y + 6.0 * scale, x + 3.2 * scale, y + 6.4 * scale);
		//Head
		bar(x + 2.8 * scale, y + 2.0 * scale, x + 3.2 * scale, y + 6.0 * scale);
		bar(x + 3.2 * scale, y + 1.2 * scale, x + 3.6 * scale, y + 2.0 * scale);
		bar(x + 3.6 * scale, y + .8 * scale, x + 4.0 * scale, y + 1.2 * scale);
		bar(x + 4.0 * scale, y + .4 * scale, x + 4.8 * scale, y + .8 * scale);

		//Filling
		setfillstyle(SOLID_FILL, knightPalette().grayBlue);
		bar(x + 4.8 * scale, y + .4 * scale, x + 7.6 * scale, y + .8 * scale);
		bar(x + 4.0 * scale, y + .8 * scale, x + 8.4 * scale, y + 1.2 * scale);
		bar(x + 3.6 * scale, y + 1.2 * scale, x + 8.8 * scale, y + 2.0 * scale);
		bar(x + 8.8 * scale, y + 5.2 * scale, x + 9.2 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightBlue);
		bar(x + 6.0 * scale, y + .8 * scale, x + 7.2 * scale, y + 1.2 * scale);
		bar(x + 6.8 * scale, y + 1.2 * scale, x + 7.2 * scale, y + 1.6 * scale);

		setfillstyle(SOLID_FILL, knightPalette().blue);
		bar(x + 3.6 * scale, y + 1.6 * scale, x + 4.0 * scale, y + 2.0 * scale);
		bar(x + 3.2 * scale, y + 2.0 * scale, x + 3.6 * scale, y + 6.4 * scale);
		bar(x + 3.6 * scale, y + 5.6 * scale, x + 4.0 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().darkBlue);
		bar(x + 4.0 * scale, y + 1.6 * scale, x + 5.2 * scale, y + 2.0 * scale);
		bar(x + 3.6 * scale, y + 2.0 * scale, x + 9.2 * scale, y + 2.8 * scale);
		bar(x + 3.6 * scale, y + 2.8 * scale, x + 5.2 * scale, y + 3.2 * scale);
		bar(x + 3.6 * scale, y + 3.2 * scale, x + 4.8 * scale, y + 5.6 * scale);
		bar(x + 4.0 * scale, y + 4.8 * scale, x + 6.0 * scale, y + 6.4 * scale);
		bar(x + 8.8 * scale, y + 4.8 * scale, x + 9.2 * scale, y + 5.2 * scale);
		bar(x + 3.6 * scale, y + 7.6 * scale, x + 8.4 * scale, y + 8.8 * scale);

		setfillstyle(SOLID_FILL, knightPalette().grayBlue);
		bar(x + 4.6 * scale, y + 5.6 * scale, x + 5.6 * scale, y + 6.0 * scale);
		bar(x + 5.0 * scale, y + 6.0 * scale, x + 5.6 * scale, y + 6.4 * scale);
		bar(x + 5.8 * scale, y + 6.0 * scale, x + 6.8 * scale, y + 8.6 * scale);
		bar(x + 7.2 * scale, y + 8.0 * scale, x + 8.4 * scale, y + 8.6 * scale);
		bar(x + 8.0 * scale, y + 7.6 * scale, x + 8.4 * scale, y + 8.0 * scale);

		setfillstyle(SOLID_FILL, knightPalette().blue);
		bar(x + 3.6 * scale, y + 7.6 * scale, x + 4.0 * scale, y + 8.4 * scale);
		bar(x + 8.0 * scale, y + 8.4 * scale, x + 8.4 * scale, y + 8.8 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightBlue);
		bar(x + 7.6 * scale, y + 7.6 * scale, x + 8.0 * scale, y + 8.0 * scale);
		bar(x + 6.8 * scale, y + 8.0 * scale, x + 7.6 * scale, y + 8.4 * scale);
		bar(x + 6.2 * scale, y + 7.6 * scale, x + 6.8 * scale, y + 8.0 * scale);

		setfillstyle(SOLID_FILL, knightPalette().pink);
		bar(x + 5.4 * scale, y + 3.6 * scale, x + 9.2 * scale, y + 4.8 * scale);

		setfillstyle(SOLID_FILL, knightPalette().orange);
		bar(x + 4.6 * scale, y + 3.2 * scale, x + 5.0 * scale, y + 4.8 * scale);
		bar(x + 5.0 * scale, y + 2.8 * scale, x + 5.4 * scale, y + 3.2 * scale);
		bar(x + 8.4 * scale, y + 2.8 * scale, x + 9.2 * scale, y + 3.2 * scale);
		bar(x + 9.2 * scale, y + 3.2 * scale, x + 9.6 * scale, y + 4.4 * scale);
		bar(x + 8.0 * scale, y + 4.4 * scale, x + 8.4 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightOrange);
		bar(x + 5.4 * scale, y + 2.8 * scale, x + 8.4 * scale, y + 3.2 * scale);
		bar(x + 5.0 * scale, y + 3.2 * scale, x + 5.4 * scale, y + 4.8 * scale);
		bar(x + 5.4 * scale, y + 4.4 * scale, x + 6.4 * scale, y + 4.8 * scale);
		bar(x + 6.0 * scale, y + 4.8 * scale, x + 6.4 * scale, y + 6.4 * scale);
		bar(x + 8.4 * scale, y + 4.4 * scale, x + 9.6 * scale, y + 4.8 * scale);
		bar(x + 8.4 * scale, y + 4.8 * scale, x + 8.8 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightYellow);
		bar(x + 7.6 * scale, y + 2.8 * scale, x + 8.0 * scale, y + 3.2 * scale);
		bar(x + 6.0 * scale, y + 2.8 * scale, x + 7.2 * scale, y + 3.2 * scale);

		setfillstyle(SOLID_FILL, knightPalette().brown);
		bar(x + 5.4 * scale, y + 3.2 * scale, x + 9.2 * scale, y + 3.6 * scale);
		bar(x + 8.8 * scale, y + 3.6 * scale, x + 9.2 * scale, y + 4.4 * scale);

		setfillstyle(SOLID_FILL, BLACK);
		bar(x + 8.0 * scale, y + 3.6 * scale, x + 8.4 * scale, y + 4.4 * scale);
		bar(x + 6.0 * scale, y + 3.6 * scale, x + 6.4 * scale, y + 4.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().skin);
		bar(x + 6.4 * scale, y + 4.8 * scale, x + 8.0 * scale, y + 6.4 * scale);

		setfillstyle(SOLID_FILL, knightPalette().red);
		//mouth
		bar(x + 6.8 * scale, y + 5.2 * scale, x + 7.6 * scale, y + 5.6 * scale);
		//Chalina
		bar(x + 2.4 * scale, y + 6.4 * scale, x + 8.8 * scale, y + 7.6 * scale);
		bar(x + 2.0 * scale, y + 6.8 * scale, x + 2.8 * scale, y + 8.8 * scale);
		bar(x + 1.6 * scale, y + 8.8 * scale, x + 2.4 * scale, y + 9.2 * scale);
		bar(x + .4 * scale, y + 9.2 * scale, x + 1.8 * scale, y + 9.6 * scale);

		setfillstyle(SOLID_FILL, knightPalette().darkRed);
		bar(x + 8.4 * scale, y + 7.2 * scale, x + 8.8 * scale, y + 7.6 * scale);
		bar(x + 2.8 * scale, y + 6.8 * scale, x + 3.6 * scale, y + 7.2 * scale);
		bar(x + 2.6 * scale, y + 7.2 * scale, x + 3.2 * scale, y + 7.6 * scale);
		bar(x + 2.6 * scale, y + 7.6 * scale, x + 2.8 * scale, y + 9.2 * scale);
		bar(x + 2.2 * scale, y + 8.8 * scale, x + 2.8 * scale, y + 9.2 * scale);
		bar(x + 1.8 * scale, y + 9.2 * scale, x + 2.4 * scale, y + 9.6 * scale);
		bar(x + 1.6 * scale, y + 8.0 * scale, x + 2.0 * scale, y + 8.8 * scale);
		bar(x + 1.2 * scale, y + 8.8 * scale, x + 1.6 * scale, y + 9.2 * scale);

		setfillstyle(SOLID_FILL, knightPalette().hardOrange);
		bar(x + 5.6 * scale, y + 6.4 * scale, x + 8.4 * scale, y + 6.8 * scale);
		bar(x + 4.8 * scale, y + 6.8 * scale, x + 8.0 * scale, y + 7.2 * scale);
	}


	void grandSlimeRight(int x, int y)
	{
		int a = 0, x1, y1, x2, y2, x3, y3, x4, y4;
		int scale = m_scale;

		setcolor(a);
		//Cuerpo
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, RED);
		ellipse(x + 6 * scale, y + 7.8 * scale, 0, 180, 6 * scale, 7.2 * scale);
		ellipse(x + 6 * scale, y + 7.8 * scale, 180, 360, 6 * scale, 4.8 * scale);
		floodfill(x + 6 * scale, y + 8 * scale, a);

		setlinestyle(0, 0, 0);

		//Poder
		scale_morado color_m;

		setfillstyle(SOLID_FILL, scale_azul().RoyalBlue);
		fillellipse(x + 6.6 * scale, y + 3.5 * scale, 3.2 * scale, 2.5 * scale);
		setfillstyle(SOLID_FILL, color_m.BlueViolet);
		fillellipse(x + 7 * scale, y + 3 * scale, 1.5 * scale, 1.5 * scale);
		setfillstyle(SOLID_FILL, color_m.DarkPurple);
		fillellipse(x + 7 * scale, y + 3 * scale, 1.4 * scale, 1.4 * scale);

		//Ojo D

		setcolor(BLACK);
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, YELLOW);
		ellipse(x + 7.9 * scale, y + 6.4 * scale, 180, 360, 0.6 * scale, 0.5 * scale);
		getxy(x + 7.9 * scale, y + 6.4 * scale, 0.6 * scale, 180, x1, y1);
		getxy(x + 7.9 * scale, y + 6.4 * scale, 0.6 * scale, 360, x2, y2);
		sector(x + 7.9 * scale, y + 6.4 * scale, 180, 360, 0.6 * scale, 0.5 * scale);

		int ojo_D[] = {
			static_cast<int>(x1),
			static_cast<int>(y1),
			static_cast<int>(x + 7.3 * scale),
			static_cast<int>(y + 5.4 * scale),
			static_cast<int>(x + 8.8 * scale),
			static_cast<int>(y + 3.9 * scale),
			static_cast<int>(x + 8.8 * scale),
			static_cast<int>(y + 5.5 * scale),
			static_cast<int>(x2),
			static_cast<int>(y2)
		};
		fillpoly(5, ojo_D);

		setcolor(YELLOW);
		line(x + (7.9 - 0.5) * scale, y + 6.4 * scale, x + (7.9 + 0.5) * scale, y + 6.4 * scale);

		//Ojo I
		setcolor(BLACK);
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, YELLOW);
		ellipse(x + 5.6 * scale, y + 6.5 * scale, 180, 360, 0.6 * scale, 0.5 * scale);
		getxy(x + 5.6 * scale, y + 6.5 * scale, 0.6 * scale, 180, x3, y3);
		getxy(x + 5.6 * scale, y + 6.5 * scale, 0.6 * scale, 360, x4, y4);
		sector(x + 5.6 * scale, y + 6.5 * scale, 180, 360, 0.6 * scale, 0.5 * scale);

		int ojo_I[] = {
			static_cast<int>(x3),
			static_cast<int>(y3),
			static_cast<int>(x + 4.5 * scale),
			static_cast<int>(y + 5.4 * scale),
			static_cast<int>(x + 4.8 * scale),
			static_cast<int>(y + 3.7 * scale),
			static_cast<int>(x + 6.1 * scale),
			static_cast<int>(y + 5.3 * scale),
			static_cast<int>(x4),
			static_cast<int>(y4)
		};
		fillpoly(5, ojo_I);

		setcolor(YELLOW);
		line(x + (5.6 - 0.5) * scale, y + 6.5 * scale, x + (5.6 + 0.5) * scale, y + 6.5 * scale);

		//boca
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);

		int boca[] = {
			static_cast<int>(x + 2.5 * scale),static_cast<int>(y + 7.3 * scale),
			static_cast<int>(x + 3 * scale),static_cast<int>(y + 6.5 * scale),
			static_cast<int>(x + 3.2 * scale),static_cast<int>(y + 8 * scale),
			static_cast<int>(x + 4 * scale),static_cast<int>(y + 7 * scale),
			static_cast<int>(x + 4.6 * scale),static_cast<int>(y + 7.4 * scale),
			static_cast<int>(x + 5 * scale),static_cast<int>(y + 9.2 * scale),
			static_cast<int>(x + 5.5 * scale),static_cast<int>(y + 7.7 * scale),
			static_cast<int>(x + 6.2 * scale),static_cast<int>(y + 9.6 * scale),
			static_cast<int>(x + 7 * scale),static_cast<int>(y + 7.5 * scale),
			static_cast<int>(x + 7.5 * scale),static_cast<int>(y + 9.5 * scale),
			static_cast<int>(x + 8.2 * scale),static_cast<int>(y + 7.6 * scale),
			static_cast<int>(x + 8.5 * scale),static_cast<int>(y + 9.2 * scale), //
			static_cast<int>(x + 9.5 * scale),static_cast<int>(y + 7 * scale),
			static_cast<int>(x + 9.7 * scale),static_cast<int>(y + 8.6 * scale), //
			static_cast<int>(x + 10.4 * scale),static_cast<int>(y + 7.5 * scale),
			static_cast<int>(x + 10.6 * scale),static_cast<int>(y + 8 * scale),
			static_cast<int>(x + 9.8 * scale),static_cast<int>(y + 9.6 * scale),
			static_cast<int>(x + 9.7 * scale),static_cast<int>(y + 8.7 * scale),
			static_cast<int>(x + 9 * scale),static_cast<int>(y + 10.5 * scale),
			static_cast<int>(x + 8.5 * scale),static_cast<int>(y + 9.3 * scale),
			static_cast<int>(x + 7.7 * scale),static_cast<int>(y + 10.8 * scale),
			static_cast<int>(x + 7.4 * scale),static_cast<int>(y + 10.4 * scale),
			static_cast<int>(x + 6.7 * scale),static_cast<int>(y + 10.8 * scale),
			static_cast<int>(x + 6.3 * scale),static_cast<int>(y + 10.2 * scale),
			static_cast<int>(x + 5.3 * scale),static_cast<int>(y + 10.9 * scale),
			static_cast<int>(x + 4.8 * scale),static_cast<int>(y + 9.7 * scale),
			static_cast<int>(x + 4 * scale),static_cast<int>(y + 10.6 * scale),
			static_cast<int>(x + 3.4 * scale),static_cast<int>(y + 9 * scale),
			static_cast<int>(x + 3 * scale),static_cast<int>(y + 9.6 * scale),
			static_cast<int>(x + 3 * scale),static_cast<int>(y + 8.2 * scale),
			static_cast<int>(x + 2 * scale),static_cast<int>(y + 8.6 * scale),
			static_cast<int>(x + 1.9 * scale),static_cast<int>(y + 7.6 * scale),
		};
		fillpoly(32, boca);
	}
	void grandSlimeLeft(int x, int y)
	{
		int a = 0, x1, y1, x2, y2, x3, y3, x4, y4;
		int scale = m_scale;

		setcolor(a);
		//Cuerpo
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, RED);
		ellipse(x + 6.1 * scale, y + 7.8 * scale, 0, 180, 6 * scale, 7.2 * scale);
		ellipse(x + 6.1 * scale, y + 7.8 * scale, 180, 360, 6 * scale, 4.8 * scale);
		floodfill(x + 6.1 * scale, y + 8 * scale, a);

		setlinestyle(0, 0, 0);

		//Poder
		scale_morado color_m;

		setfillstyle(SOLID_FILL, scale_azul().RoyalBlue);
		fillellipse(x + 5.5 * scale, y + 3.5 * scale, 3.2 * scale, 2.5 * scale);
		setfillstyle(SOLID_FILL, color_m.BlueViolet);
		fillellipse(x + 5.1 * scale, y + 3 * scale, 1.5 * scale, 1.5 * scale);
		setfillstyle(SOLID_FILL, color_m.DarkPurple);
		fillellipse(x + 5.1 * scale, y + 3 * scale, 1.4 * scale, 1.4 * scale);

		//Ojo D

		setcolor(BLACK);
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, YELLOW);
		ellipse(x + 4.2 * scale, y + 6.4 * scale, 180, 360, 0.6 * scale, 0.5 * scale);
		getxy(x + 4.2 * scale, y + 6.4 * scale, 0.6 * scale, 180, x1, y1);
		getxy(x + 4.2 * scale, y + 6.4 * scale, 0.6 * scale, 360, x2, y2);
		sector(x + 4.2 * scale, y + 6.4 * scale, 180, 360, 0.6 * scale, 0.5 * scale);

		int ojo_D[] = {
			static_cast<int>(x2),
			static_cast<int>(y2),
			static_cast<int>(x + 4.8 * scale),
			static_cast<int>(y + 5.4 * scale),
			static_cast<int>(x + 3.3 * scale),
			static_cast<int>(y + 3.9 * scale),
			static_cast<int>(x + 3.3 * scale),
			static_cast<int>(y + 5.5 * scale),
			static_cast<int>(x1),
			static_cast<int>(y1)
		};
		fillpoly(5, ojo_D);

		setcolor(YELLOW);
		line(x + 4.7 * scale, y + 6.4 * scale, x + 3.7 * scale, y + 6.4 * scale);

		//Ojo I
		setcolor(BLACK);
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, YELLOW);
		ellipse(x + 6.5 * scale, y + 6.5 * scale, 180, 360, 0.6 * scale, 0.5 * scale);
		getxy(x + 6.5 * scale, y + 6.5 * scale, 0.6 * scale, 180, x3, y3);
		getxy(x + 6.5 * scale, y + 6.5 * scale, 0.6 * scale, 360, x4, y4);
		sector(x + 6.5 * scale, y + 6.5 * scale, 180, 360, 0.6 * scale, 0.5 * scale);

		int ojo_I[] = {
			static_cast<int>(x4),
			static_cast<int>(y4),
			static_cast<int>(x + 7.6 * scale),
			static_cast<int>(y + 5.4 * scale),
			static_cast<int>(x + 7.3 * scale),
			static_cast<int>(y + 3.7 * scale),
			static_cast<int>(x + 6 * scale),
			static_cast<int>(y + 5.3 * scale),
			static_cast<int>(x3),
			static_cast<int>(y3)
		};
		fillpoly(5, ojo_I);

		setcolor(YELLOW);
		line(x + 7 * scale, y + 6.5 * scale, x + 6 * scale, y + 6.5 * scale);

		//boca
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);

		int boca[] = {
			static_cast<int>(x + 9.6 * scale),static_cast<int>(y + 7.3 * scale),
			static_cast<int>(x + 9.1 * scale),static_cast<int>(y + 6.5 * scale),
			static_cast<int>(x + 8.9 * scale),static_cast<int>(y + 8 * scale),
			static_cast<int>(x + 8.1 * scale),static_cast<int>(y + 7 * scale),
			static_cast<int>(x + 7.5 * scale),static_cast<int>(y + 7.4 * scale),
			static_cast<int>(x + 7.1 * scale),static_cast<int>(y + 9.2 * scale),
			static_cast<int>(x + 6.6 * scale),static_cast<int>(y + 7.7 * scale),
			static_cast<int>(x + 5.9 * scale),static_cast<int>(y + 9.6 * scale),
			static_cast<int>(x + 5.1 * scale),static_cast<int>(y + 7.5 * scale),
			static_cast<int>(x + 4.6 * scale),static_cast<int>(y + 9.5 * scale),
			static_cast<int>(x + 3.9 * scale),static_cast<int>(y + 7.6 * scale),
			static_cast<int>(x + 3.6 * scale),static_cast<int>(y + 9.2 * scale), //
			static_cast<int>(x + 2.6 * scale),static_cast<int>(y + 7 * scale),
			static_cast<int>(x + 2.4 * scale),static_cast<int>(y + 8.6 * scale), //
			static_cast<int>(x + 1.7 * scale),static_cast<int>(y + 7.5 * scale),
			static_cast<int>(x + 1.5 * scale),static_cast<int>(y + 8 * scale),
			static_cast<int>(x + 2.3 * scale),static_cast<int>(y + 9.6 * scale),
			static_cast<int>(x + 2.4 * scale),static_cast<int>(y + 8.7 * scale),
			static_cast<int>(x + 3.1 * scale),static_cast<int>(y + 10.5 * scale),
			static_cast<int>(x + 3.6 * scale),static_cast<int>(y + 9.3 * scale),
			static_cast<int>(x + 4.4 * scale),static_cast<int>(y + 10.8 * scale),
			static_cast<int>(x + 4.7 * scale),static_cast<int>(y + 10.4 * scale),
			static_cast<int>(x + 5.4 * scale),static_cast<int>(y + 10.8 * scale),
			static_cast<int>(x + 5.8 * scale),static_cast<int>(y + 10.2 * scale),
			static_cast<int>(x + 6.8 * scale),static_cast<int>(y + 10.9 * scale),
			static_cast<int>(x + 7.3 * scale),static_cast<int>(y + 9.7 * scale),
			static_cast<int>(x + 8.1 * scale),static_cast<int>(y + 10.6 * scale),
			static_cast<int>(x + 8.7 * scale),static_cast<int>(y + 9 * scale),
			static_cast<int>(x + 9.1 * scale),static_cast<int>(y + 9.6 * scale),
			static_cast<int>(x + 9.1 * scale),static_cast<int>(y + 8.2 * scale),
			static_cast<int>(x + 10.1 * scale),static_cast<int>(y + 8.6 * scale),
			static_cast<int>(x + 10.2 * scale),static_cast<int>(y + 7.6 * scale),
		};
		fillpoly(32, boca);
	}

	void witchRight(int x,int y)
	{
		int scale = m_scale;
		setcolor(0);
		int x1, y1, x2, y2;
		colorGeneral color;
		scale_marron colorM;

		//Cabello

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		int hair[] = {
			static_cast<int>(x+3.7*scale),
			static_cast<int>(y+8.5*scale),
			static_cast<int>(x+1*scale),
			static_cast<int>(y+8.6*scale),
			static_cast<int>(x+0.4*scale),
			static_cast<int>(y+8*scale),
			static_cast<int>(x+0.4*scale),
			static_cast<int>(y+6.7*scale),
			static_cast<int>(x+1.7*scale),
			static_cast<int>(y+7.5*scale),
			static_cast<int>(x+2*scale),
			static_cast<int>(y+5.3*scale),
			static_cast<int>(x+3.7*scale),
			static_cast<int>(y+5*scale)
			};
		fillpoly(7, hair);

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		int hair_d[] = {
			static_cast<int>(x+9.4*scale),
			static_cast<int>(y+4.4*scale),
			static_cast<int>(x+10.1*scale),
			static_cast<int>(y+5.3*scale),
			static_cast<int>(x+10.1*scale),
			static_cast<int>(y+6.8*scale),
			static_cast<int>(x+9*scale),
			static_cast<int>(y+6.8*scale),
			static_cast<int>(x+8.5*scale),
			static_cast<int>(y+4.5*scale)
			};
		fillpoly(5, hair_d);

		//Cabeza
		setcolor(BLACK);
		setlinestyle(0,0,2);
		setfillstyle(SOLID_FILL, color.Wheat);
		ellipse(x+6.3*scale,y+5.2*scale,360,180,2.7*scale,2.5*scale);
		getxy(x+6.3*scale,y+5.2*scale,2.7*scale, 180,x1,y1);
		getxy(x+6.3*scale,y+5.2*scale,2.7*scale, 360,x2,y2);
		sector(x+6.3*scale,y+5.2*scale,360,180,2.7*scale,2.5*scale);
		
		setcolor(BLACK);
		rectangle(x1,y1,x2,y+6.8*scale);
		bar(x1,y1,x2,y+6.8*scale);

		setcolor(color.Wheat);
		line(x1+0.2,y1,x2-0.2,y2);

		setlinestyle(0,0,0);

		//Ojos
		//Izquierdo
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		rectangle(x+4.5*scale,y+5.2*scale,x+5.4*scale,y+5.6*scale);
		bar(x+4.5*scale,y+5.2*scale,x+5.4*scale,y+5.6*scale);

		setfillstyle(SOLID_FILL, RED);
		fillellipse(x+5.2*scale,y+6.4*scale,0.2*scale,0.6*scale);

		//Derecho
		setfillstyle(SOLID_FILL, color.DeepPink);
		rectangle(x+8.2*scale,y+5.2*scale,x+9*scale,y+5.6*scale);
		bar(x+8.2*scale,y+5.2*scale,x+9*scale,y+5.6*scale);

		setfillstyle(SOLID_FILL, RED);
		fillellipse(x+8.4*scale,y+6.4*scale,0.2*scale,0.6*scale);

		//chalina
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		rectangle(x+2.2*scale,y+6.8*scale,x+10*scale,y+7.6*scale);
		bar(x+2.2*scale,y+6.8*scale,x+10*scale,y+7.6*scale);

		setfillstyle(SOLID_FILL, color.HotPink);
		rectangle(x+2.7*scale,y+7.5*scale,x+9.5*scale,y+8.4*scale);
		bar(x+2.7*scale,y+7.5*scale,x+9.5*scale,y+8.4*scale);

		setfillstyle(SOLID_FILL, color.MediumBlue);
		bar(x+5*scale,y+8.4*scale,x+7.8*scale,y+10.4*scale);

		//Capa

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		int capa_1[] = {
			static_cast<int>(x+2.7*scale),
			static_cast<int>(y+8.4*scale),
			static_cast<int>(x+0.8*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+5.2*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+6.2*scale),
			static_cast<int>(y+9.8*scale),
			static_cast<int>(x+6.2*scale),
			static_cast<int>(y+8.4*scale)
			};
		fillpoly(5, capa_1);

		int capa_2[] = {
			static_cast<int>(x+9.5*scale),
			static_cast<int>(y+8.4*scale),
			static_cast<int>(x+10.3*scale),
			static_cast<int>(y+9.7*scale),
			static_cast<int>(x+9.4*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+7.7*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+7.2*scale),
			static_cast<int>(y+9.8*scale),
			static_cast<int>(x+7.2*scale),
			static_cast<int>(y+8.4*scale)
			};
		fillpoly(6, capa_2);

		//Sombrero
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		int hat[] = {
			static_cast<int>(x+ scale),
			static_cast<int>(y+ 5.5*scale),
			static_cast<int>(x+4*scale),
			static_cast<int>(y+5*scale),
			static_cast<int>(x+10.4*scale),
			static_cast<int>(y+4.4*scale),
			static_cast<int>(x+12*scale),
			static_cast<int>(y+3.8*scale),
			static_cast<int>(x+8.5*scale),
			static_cast<int>(y+2.8*scale),
			static_cast<int>(x+7.2*scale),
			static_cast<int>(y+1.5*scale),
			static_cast<int>(x+6.7*scale),
			static_cast<int>(y+0.7*scale),
			static_cast<int>(x+5.7*scale),
			static_cast<int>(y+0.2*scale),
			static_cast<int>(x+3.6*scale),
			static_cast<int>(y+0.2*scale),
			static_cast<int>(x+1.7*scale),
			static_cast<int>(y+1.7*scale),
			static_cast<int>(x+3.5*scale),
			static_cast<int>(y+1.7*scale),
			static_cast<int>(x+3.5*scale),
			static_cast<int>(y+2.7*scale),
			static_cast<int>(x+2.6*scale),
			static_cast<int>(y+3.5*scale),
			static_cast<int>(x+2.2*scale),
			static_cast<int>(y+4*scale)
			};
		fillpoly(14, hat);

		setcolor(colorM.SaddleBrown);
		setfillstyle(SOLID_FILL, colorM.SaddleBrown);
		int hat_a[] = {
			static_cast<int>(x+3.3*scale),
			static_cast<int>(y+4.4*scale),
			static_cast<int>(x+3.9*scale),
			static_cast<int>(y+3.5*scale),
			static_cast<int>(x+5*scale),
			static_cast<int>(y+2.7*scale),
			static_cast<int>(x+4.5*scale),
			static_cast<int>(y+scale),
			static_cast<int>(x+6.3*scale),
			static_cast<int>(y+1.5*scale),
			static_cast<int>(x+6.7*scale),
			static_cast<int>(y+2.5*scale),
			static_cast<int>(x+7.7*scale),
			static_cast<int>(y+3.2*scale),
			static_cast<int>(x+9.1*scale),
			static_cast<int>(y+3.6*scale),
			static_cast<int>(x+6.3*scale),
			static_cast<int>(y+4*scale)
			};
		fillpoly(9, hat_a);


		// Pie
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		int pie_I[] = {
			static_cast<int>(x+3.1*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+3.1*scale),
			static_cast<int>(y+11.6*scale),
			static_cast<int>(x+4.1*scale),
			static_cast<int>(y+11.6*scale),
			static_cast<int>(x+4.8*scale),
			static_cast<int>(y+10.4*scale)
			};
		fillpoly(4, pie_I);

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		int pie_D[] = {
			static_cast<int>(x+7.2*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+7.2*scale),
			static_cast<int>(y+11.6*scale),
			static_cast<int>(x+8.2*scale),
			static_cast<int>(y+11.6*scale),
			static_cast<int>(x+9*scale),
			static_cast<int>(y+10.4*scale)
			};
		fillpoly(4, pie_D);

	}

	void witchLeft(int x,int y)
	{
		int scale = m_scale;
		setcolor(0);
		int x1, y1, x2, y2;
		colorGeneral color;
		scale_marron colorM;

		//Cabello

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		int hair[] = {
			static_cast<int>(x+8.4*scale),
			static_cast<int>(y+8.5*scale),
			static_cast<int>(x+11.1*scale),
			static_cast<int>(y+8.6*scale),
			static_cast<int>(x+11.7*scale),
			static_cast<int>(y+8*scale),
			static_cast<int>(x+11.7*scale),
			static_cast<int>(y+6.7*scale),
			static_cast<int>(x+10.4*scale),
			static_cast<int>(y+7.5*scale),
			static_cast<int>(x+10.1*scale),
			static_cast<int>(y+5.3*scale),
			static_cast<int>(x+8.4*scale),
			static_cast<int>(y+5*scale)
			};
		fillpoly(7, hair);

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		int hair_d[] = {
			static_cast<int>(x+2.7*scale),
			static_cast<int>(y+4.4*scale),
			static_cast<int>(x+2*scale),
			static_cast<int>(y+5.3*scale),
			static_cast<int>(x+2*scale),
			static_cast<int>(y+6.8*scale),
			static_cast<int>(x+3.1*scale),
			static_cast<int>(y+6.8*scale),
			static_cast<int>(x+3.6*scale),
			static_cast<int>(y+4.5*scale)
			};
		fillpoly(5, hair_d);

		//Cabeza
		setcolor(BLACK);
		setlinestyle(0,0,2);
		setfillstyle(SOLID_FILL, color.Wheat);
		ellipse(x+5.8*scale,y+5.2*scale,360,180,2.7*scale,2.5*scale);
		getxy(x+5.8*scale,y+5.2*scale,2.7*scale, 180,x1,y1);
		getxy(x+5.8*scale,y+5.2*scale,2.7*scale, 360,x2,y2);
		sector(x+5.8*scale,y+5.2*scale,360,180,2.7*scale,2.5*scale);
		
		setcolor(BLACK);
		rectangle(x1,y1,x2,y+6.8*scale);
		bar(x1,y1,x2,y+6.8*scale);

		setcolor(color.Wheat);
		line(x1+0.2,y1,x2-0.2,y2);

		setlinestyle(0,0,0);

		//Ojos
		//Izquierdo
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		rectangle(x+7.6*scale,y+5.2*scale,x+6.7*scale,y+5.6*scale);
		bar(x+7.6*scale,y+5.2*scale,x+6.7*scale,y+5.6*scale);

		setfillstyle(SOLID_FILL, RED);
		fillellipse(x+6.9*scale,y+6.4*scale,0.2*scale,0.6*scale);

		//Derecho
		setfillstyle(SOLID_FILL, color.DeepPink);
		rectangle(x+3.9*scale,y+5.2*scale,x+3.1*scale,y+5.6*scale);
		bar(x+3.9*scale,y+5.2*scale,x+3.1*scale,y+5.6*scale);

		setfillstyle(SOLID_FILL, RED);
		fillellipse(x+3.7*scale,y+6.4*scale,0.2*scale,0.6*scale);

		//chalina
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		rectangle(x+9.9*scale,y+6.8*scale,x+2.1*scale,y+7.6*scale);
		bar(x+9.9*scale,y+6.8*scale,x+2.1*scale,y+7.6*scale);

		setfillstyle(SOLID_FILL, color.HotPink);
		rectangle(x+9.4*scale,y+7.5*scale,x+2.6*scale,y+8.4*scale);
		bar(x+9.4*scale,y+7.5*scale,x+2.6*scale,y+8.4*scale);

		setfillstyle(SOLID_FILL, color.MediumBlue);
		bar(x+7.1*scale,y+8.4*scale,x+4.3*scale,y+10.4*scale);

		//Capa
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		int capa_1[] = {
			static_cast<int>(x+9.4*scale),
			static_cast<int>(y+8.4*scale),
			static_cast<int>(x+11.3*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+6.9*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+5.9*scale),
			static_cast<int>(y+9.8*scale),
			static_cast<int>(x+5.9*scale),
			static_cast<int>(y+8.4*scale)
			};
		fillpoly(5, capa_1);

		int capa_2[] = {
			static_cast<int>(x+2.6*scale),
			static_cast<int>(y+8.4*scale),
			static_cast<int>(x+1.8*scale),
			static_cast<int>(y+9.7*scale),
			static_cast<int>(x+2.7*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+4.4*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+4.9*scale),
			static_cast<int>(y+9.8*scale),
			static_cast<int>(x+4.9*scale),
			static_cast<int>(y+8.4*scale)
			};
		fillpoly(6, capa_2);

		//Sombrero
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		int hat[] = {
			static_cast<int>(x+11.1*scale),
			static_cast<int>(y+5.5*scale),
			static_cast<int>(x+8.1*scale),
			static_cast<int>(y+5*scale),
			static_cast<int>(x+1.7*scale),
			static_cast<int>(y+4.4*scale),
			static_cast<int>(x+0.1*scale),
			static_cast<int>(y+3.8*scale),
			static_cast<int>(x+3.6*scale),
			static_cast<int>(y+2.8*scale),
			static_cast<int>(x+4.9*scale),
			static_cast<int>(y+1.5*scale),
			static_cast<int>(x+5.4*scale),
			static_cast<int>(y+0.7*scale),
			static_cast<int>(x+6.4*scale),
			static_cast<int>(y+0.2*scale),
			static_cast<int>(x+8.5*scale),
			static_cast<int>(y+0.2*scale),
			static_cast<int>(x+10.4*scale),
			static_cast<int>(y+1.7*scale),
			static_cast<int>(x+8.6*scale),
			static_cast<int>(y+1.7*scale),
			static_cast<int>(x+8.6*scale),
			static_cast<int>(y+2.7*scale),
			static_cast<int>(x+9.5*scale),
			static_cast<int>(y+3.5*scale),
			static_cast<int>(x+9.9*scale),
			static_cast<int>(y+4*scale)
			};
		fillpoly(14, hat);

		setcolor(colorM.SaddleBrown);
		setfillstyle(SOLID_FILL, colorM.SaddleBrown);
		int hat_a[] = {
			static_cast<int>(x+8.8*scale),
			static_cast<int>(y+4.4*scale),
			static_cast<int>(x+8.2*scale),
			static_cast<int>(y+3.5*scale),
			static_cast<int>(x+7.1*scale),
			static_cast<int>(y+2.7*scale),
			static_cast<int>(x+7.6*scale),
			static_cast<int>(y+scale),
			static_cast<int>(x+5.8*scale),
			static_cast<int>(y+1.5*scale),
			static_cast<int>(x+5.4*scale),
			static_cast<int>(y+2.5*scale),
			static_cast<int>(x+4.4*scale),
			static_cast<int>(y+3.2*scale),
			static_cast<int>(x+3*scale),
			static_cast<int>(y+3.6*scale),
			static_cast<int>(x+5.8*scale),
			static_cast<int>(y+4*scale)
			};
		fillpoly(9, hat_a);


		// Pie
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		int pie_I[] = {
			static_cast<int>(x+9*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+9*scale),
			static_cast<int>(y+11.6*scale),
			static_cast<int>(x+8*scale),
			static_cast<int>(y+11.6*scale),
			static_cast<int>(x+7.3*scale),
			static_cast<int>(y+10.4*scale)
			};
		fillpoly(4, pie_I);

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		int pie_D[] = {
			static_cast<int>(x+4.9*scale),
			static_cast<int>(y+10.4*scale),
			static_cast<int>(x+4.9*scale),
			static_cast<int>(y+11.6*scale),
			static_cast<int>(x+3.9*scale),
			static_cast<int>(y+11.6*scale),
			static_cast<int>(x+3.1*scale),
			static_cast<int>(y+10.4*scale)
			};
		fillpoly(4, pie_D);

	}

	void SnowWall(const int x, const int y)
	{

	}

	void StoneWall(const int x, const int y)
	{
		int scale = 0.8 * m_scale;
		setfillstyle(SOLID_FILL, StoneWallPalette().BluishGreen);
		bar(x, y, x + 9.2 * scale, y + 9.2 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().BrayishBlue);
		bar(x + 0.8 * scale, y + 0.8 * scale, x + 8.4 * scale, y + 8.4 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().DarkBrayishBlue);
		bar(x + 1.6 * scale, y + 1.6 * scale, x + 7.6 * scale, y + 7.6 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().MediumBrayishBlue);
		bar(x + 2.4 * scale, y + 2.4 * scale, x + 6.8 * scale, y + 6.8 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().mLightGray);
		bar(x + 3.2 * scale, y + 3.2 * scale, x + 6.0 * scale, y + 6.0 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().darkGray);
		bar(x + 9.2 * scale, y, x + 10.0 * scale, y + 10.0 * scale);
		bar(x, y + 9.2 * scale, x + 10.0 * scale, y + 10.0 * scale);
		bar(x + 9.2 * scale, y, x + 10.0 * scale, y + 14.0 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().vinil);
		bar(x, y + 10.0 * scale, x + 9.2 * scale, y + 14.0 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().darkGray);
		bar(x + 0.8 * scale, y + 10.8 * scale, x + 8.4 * scale, y + 13.2 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().vinil);
		bar(x + 1.6 * scale, y + 11.2 * scale, x + 7.6 * scale, y + 12.8 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().lightDarkGray);
		bar(x + 2.4 * scale, y + 11.6 * scale, x + 7.6 * scale, y + 12.8 * scale);
	}
};

class CCollision
{
public:
	float radius = 0;
	CCollision(float r) : radius(r){}
};

class CScore
{
public:
	int score = 0;
	CScore(int s) : score(s) {}
};

class CLifespan
{
public:
	int remaining = 0;
	int total = 0;
	CLifespan(int total) : remaining(total), total(total) {}
};

class CInput
{
public:
	bool up = false;
	bool left = false;
	bool right = false;
	bool down = false;
	bool shoot = false;

	CInput() {}
};