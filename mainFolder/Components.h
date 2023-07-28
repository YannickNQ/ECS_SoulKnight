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
	Vec2 prevPos = { 0.0, 0.0 };
	Vec2 target = { 0.0, 0.0 };
	float angle = 0;

	CTransform(const Vec2& p, const Vec2& v, float a)
		: pos(p), prevPos(p), velocity(v), angle(a) {}
	CTransform(const Vec2& p, const Vec2& v, const Vec2& t)
		: pos(p), prevPos(p), velocity(v), target(t) {}
};

class CShape
{
	float m_scale;
public:
	int height, width;
	CShape(int x, int y, float scale,std::string tag): m_scale(scale)
	{
		if(tag == "wall")
		{
			StoneWall(x,y);
		}
		else if(tag == "base")
		{
            V(x,y);
        }
		else if(tag == "player")
		{
			knightLeft(x, y);
        }

		else if(tag == "enemy")
		{
            grandSlimeRight(x,y);
        }
		
		else if (tag == "bullet")
		{
			bulletTest(x, y);
		}
	}
	const float getScale() const 
	{
		return  m_scale;
	}
		
	void getxy(int x, int y, int L, int alfa, int& _x, int& _y) {
		_x = L * cos(M_PI * alfa / 180) + x;
		_y = L * sin(M_PI * alfa / 180) + y;
	}

	void draw(float x, float y, float a, std::string tag)
	{
		if (tag == "wall") {
			StoneWall(x, y);
		}
		else if (tag == "base") {
			V(x, y);
		}
		else if (tag == "player") {
			knightLeft(x, y);
		}

		else if (tag == "enemy") {
			grandSlimeRight(x, y);
		}
		
		else if (tag == "bullet") {
			bulletTest(x, y);
		}
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
	void bulletTest(int x, int y)
	{
		setfillstyle(SOLID_FILL, RED);
		fillellipse(x, y,8, 8);
	}

	void armaOneRight(int x,int y,int scale)
	{
		setfillstyle(SOLID_FILL,0);
		bar(x+scale,y+2*scale,x+4*scale,y+3.5*scale);
		setfillstyle(SOLID_FILL,0);
		bar(x+4*scale,y+scale,x+5*scale,y+4.5*scale);
		setfillstyle(SOLID_FILL,14);
		bar(x+5*scale,y+scale,x+6*scale,y+4.5*scale);
		setfillstyle(SOLID_FILL,15);
		bar(x+6*scale,y+2*scale,x+15*scale,y+2.75*scale);
		setfillstyle(SOLID_FILL,15);
		bar(x+6*scale,y+2.75*scale,x+14*scale,y+3.5*scale);
	}

	void armaOneLeft(int x,int y,int scale)
	{
		setfillstyle(SOLID_FILL,0);
		bar(x+scale,y+2*scale,x+4*scale,y+3.5*scale);
		setfillstyle(SOLID_FILL,0);
		bar(x+4*scale,y+scale,x+5*scale,y+4.5*scale);
		setfillstyle(SOLID_FILL,14);
		bar(x+5*scale,y+scale,x+6*scale,y+4.5*scale);
		setfillstyle(SOLID_FILL,15);
		bar(x+6*scale,y+2*scale,x+15*scale,y+2.75*scale);
		setfillstyle(SOLID_FILL,15);
		bar(x+6*scale,y+2.75*scale,x+14*scale,y+3.5*scale);
	}

	void armaTwoRight(int x,int y,int scale)
	{
		setfillstyle(SOLID_FILL,7);
		bar(x+scale,y+3*scale,x+2*scale,y+5*scale);
		setfillstyle(SOLID_FILL,7);
		bar(x+2*scale,y+2*scale,x+3*scale,y+4*scale);
		setfillstyle(SOLID_FILL,BLACK);
		bar(x+3*scale,y+scale,x+9*scale,y+4*scale);
		setfillstyle(SOLID_FILL,7);
		bar(x+4*scale,y+2*scale,x+8*scale,y+3*scale);
	}

	void armaTwoLeft(int x,int y,int scale)
	{
		setfillstyle(SOLID_FILL,7);
		bar(x+scale,y+3*scale,x+2*scale,y+5*scale);
		setfillstyle(SOLID_FILL,7);
		bar(x+2*scale,y+2*scale,x+3*scale,y+4*scale);
		setfillstyle(SOLID_FILL,BLACK);
		bar(x+3*scale,y+scale,x+9*scale,y+4*scale);
		setfillstyle(SOLID_FILL,7);
		bar(x+4*scale,y+2*scale,x+8*scale,y+3*scale);
	}

	void bulletOne(int x,int y,int scale){

		setlinestyle(SOLID_LINE, 0, 3);
		setcolor(3);
		fillellipse(x+scale,y+scale,2.5*scale,2.5*scale);
		setlinestyle(SOLID_LINE, 0, 3);
		setcolor(6);
		fillellipse(x+scale,y+scale,2*scale,2*scale);
		setlinestyle(SOLID_LINE, 0, 3);
		setcolor(8);
		fillellipse(x+scale,y+scale,1.5*scale,1.5*scale);

	}
	
	void armaRight(int x, int y) 
	{
		float scale = 0.8 * m_scale;
        int arma_2[] = {
            static_cast<int>(x+scale),
            static_cast<int>(y+1.5*scale),
            static_cast<int>(x+3.5*scale),
            static_cast<int>(y+1.5*scale),
            static_cast<int>(x+scale),
            static_cast<int>(y+4*scale)
            };
        fillpoly(3, arma_2);
        setfillstyle(SOLID_FILL,14);
        bar(x+2.8*scale,y+scale,x+12*scale,y+3*scale);
        setfillstyle(SOLID_FILL,14);
        bar(x+2.8*scale,y+3*scale,x+7*scale,y+5.8*scale);
        setfillstyle(SOLID_FILL,0);
        bar(x+4*scale,y+3.2*scale,x+6.8*scale,y+5.2*scale);
        setfillstyle(SOLID_FILL,0);
        bar(x+9*scale,y+3*scale,x+10*scale,y+5.2*scale);
        setfillstyle(SOLID_FILL,0);
        bar(x+12*scale,y+1.3*scale,x+14*scale,y+1.8*scale);
    }

    void armaLeft(int x, int y) 
	{
		float scale = 0.5 * m_scale;
		float width = 0;
        int arma_2[] = {
            static_cast<int>(x-scale+width),
            static_cast<int>(y+1.5*scale),
            static_cast<int>(x-3.5*scale+width),
            static_cast<int>(y+1.5*scale),
            static_cast<int>(x-scale+width),
            static_cast<int>(y+4*scale)
            };
        fillpoly(3, arma_2);
        setfillstyle(SOLID_FILL,14);
        bar(x-2.8*scale+width,y+scale,x-12*scale+width,y+3*scale);
        setfillstyle(SOLID_FILL,14);
        bar(x-2.8*scale+width,y+3*scale,x-7*scale+width,y+5.8*scale);
        setfillstyle(SOLID_FILL,0);
        bar(x-4*scale+width,y+3.2*scale,x-6.8*scale+width,y+5.2*scale);
        setfillstyle(SOLID_FILL,0);
        bar(x-9*scale+width,y+3*scale,x-10*scale+width,y+5.2*scale);
        setfillstyle(SOLID_FILL,0);
        bar(x-12*scale+width,y+1.3*scale,x-14*scale+width,y+1.8*scale);
    }

	void knightLeft(const float x, const float y) //96x96
	{
		float scale = 0.8 * m_scale;
		width = height = 0.96*scale;

		// rectangle(x, y, x + m_scale, y + m_scale);
		setfillstyle(SOLID_FILL, BLACK);
		// Heroe border
		// casco
		bar(x + .24 * scale, y, x + .52 * scale, y + .04 * scale);
		bar(x + .16 * scale, y + .04 * scale, x + .24 * scale, y + .08 * scale);
		bar(x + .12 * scale, y + .08 * scale, x + .16 * scale, y + .12 * scale);
		bar(x + .08 * scale, y + .12 * scale, x + .12 * scale, y + .20 * scale);
		bar(x + .04 * scale, y + .20 * scale, x + .08 * scale, y + .32 * scale);
		// Eyes
		bar(x, y + .32 * scale, x + .04 * scale, y + .48 * scale);
		// Chin
		bar(x + .04 * scale, y + .48 * scale, x + .08 * scale, y + .64 * scale);
		// Body
		bar(x + .08 * scale, y + .64 * scale, x + .12 * scale, y + .76 * scale);
		bar(x + .12 * scale, y + .76 * scale, x + .16 * scale, y + .88 * scale);
		// Line before Foot
		bar(x + .16 * scale, y + .88 * scale, x + .64 * scale, y + .92 * scale);
		// Foot
		bar(x + .16 * scale, y + .92 * scale, x + .28 * scale, y + .96 * scale);
		bar(x + .48 * scale, y + .92 * scale, x + .60 * scale, y + .96 * scale);
		bar(x + .20 * scale, y + .96 * scale, x + .28 * scale, y + 1. * scale);
		bar(x + .52 * scale, y + .96 * scale, x + .60 * scale, y + 1. * scale);
		// Second Part
		// Body
		bar(x + .64 * scale, y + .76 * scale, x + .72 * scale, y + .88 * scale);
		// Chalina
		bar(x + .68 * scale, y + .88 * scale, x + .72 * scale, y + .92 * scale);
		bar(x + .72 * scale, y + .92 * scale, x + .76 * scale, y + .96 * scale);
		bar(x + .76 * scale, y + .96 * scale, x + 1. * scale, y + 1. * scale);
		bar(x + .96 * scale, y + .92 * scale, x + 1. * scale, y + .96 * scale);
		bar(x + .88 * scale, y + .88 * scale, x + .96 * scale, y + .92 * scale);
		bar(x + .84 * scale, y + .80 * scale, x + .88 * scale, y + .88 * scale);
		bar(x + .80 * scale, y + .68 * scale, x + .84 * scale, y + .80 * scale);
		bar(x + .76 * scale, y + .64 * scale, x + .80 * scale, y + .68 * scale);
		bar(x + .68 * scale, y + .60 * scale, x + .76 * scale, y + .64 * scale);
		// Head
		bar(x + .68 * scale, y + .20 * scale, x + .72 * scale, y + .60 * scale);
		bar(x + .64 * scale, y + .12 * scale, x + .68 * scale, y + .20 * scale);
		bar(x + .60 * scale, y + .08 * scale, x + .64 * scale, y + .12 * scale);
		bar(x + .52 * scale, y + .04 * scale, x + .60 * scale, y + .08 * scale);

		// Filling
		setfillstyle(SOLID_FILL, knightPalette().grayBlue);
		bar(x + .24 * scale, y + .04 * scale, x + .52 * scale, y + .08 * scale);
		bar(x + .16 * scale, y + .08 * scale, x + .60 * scale, y + .12 * scale);
		bar(x + .12 * scale, y + .12 * scale, x + .64 * scale, y + .20 * scale);
		bar(x + .08 * scale, y + .52 * scale, x + .12 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightBlue);
		bar(x + .28 * scale, y + .08 * scale, x + .40 * scale, y + .12 * scale);
		bar(x + .28 * scale, y + .12 * scale, x + .32 * scale, y + .16 * scale);

		setfillstyle(SOLID_FILL, knightPalette().blue);
		bar(x + .60 * scale, y + .16 * scale, x + .64 * scale, y + .20 * scale);
		bar(x + .64 * scale, y + .20 * scale, x + .68 * scale, y + .64 * scale);
		bar(x + .60 * scale, y + .56 * scale, x + .64 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().darkBlue);
		bar(x + .48 * scale, y + .16 * scale, x + .60 * scale, y + .20 * scale);
		bar(x + .08 * scale, y + .20 * scale, x + .64 * scale, y + .28 * scale);
		bar(x + .48 * scale, y + .28 * scale, x + .64 * scale, y + .32 * scale);
		bar(x + .52 * scale, y + .32 * scale, x + .64 * scale, y + .56 * scale);
		bar(x + .40 * scale, y + .48 * scale, x + .60 * scale, y + .64 * scale);
		bar(x + .08 * scale, y + .48 * scale, x + .12 * scale, y + .52 * scale);
		bar(x + .16 * scale, y + .76 * scale, x + .64 * scale, y + .88 * scale);

		setfillstyle(SOLID_FILL, knightPalette().grayBlue);
		bar(x + .44 * scale, y + .56 * scale, x + .54 * scale, y + .60 * scale);
		bar(x + .44 * scale, y + .60 * scale, x + .50 * scale, y + .64 * scale);
		bar(x + .32 * scale, y + .80 * scale, x + .52 * scale, y + .86 * scale);
		bar(x + .16 * scale, y + .80 * scale, x + .28 * scale, y + .86 * scale);
		bar(x + .16 * scale, y + .76 * scale, x + .20 * scale, y + .80 * scale);

		setfillstyle(SOLID_FILL, knightPalette().blue);
		bar(x + .60 * scale, y + .76 * scale, x + .64 * scale, y + .84 * scale);
		bar(x + .16 * scale, y + .84 * scale, x + .20 * scale, y + .88 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightBlue);
		bar(x + .20 * scale, y + .76 * scale, x + .24 * scale, y + .80 * scale);
		bar(x + .24 * scale, y + .80 * scale, x + .32 * scale, y + .84 * scale);
		bar(x + .32 * scale, y + .76 * scale, x + .36 * scale, y + .80 * scale);

		setfillstyle(SOLID_FILL, knightPalette().pink);
		bar(x + .08 * scale, y + .36 * scale, x + .46 * scale, y + .48 * scale);

		setfillstyle(SOLID_FILL, knightPalette().orange);
		bar(x + .50 * scale, y + .32 * scale, x + .54 * scale, y + .48 * scale);
		bar(x + .46 * scale, y + .28 * scale, x + .50 * scale, y + .32 * scale);
		bar(x + .08 * scale, y + .28 * scale, x + .16 * scale, y + .32 * scale);
		bar(x + .04 * scale, y + .32 * scale, x + .08 * scale, y + .44 * scale);
		bar(x + .16 * scale, y + .44 * scale, x + .20 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightOrange);
		bar(x + .16 * scale, y + .28 * scale, x + .46 * scale, y + .32 * scale);
		bar(x + .46 * scale, y + .32 * scale, x + .50 * scale, y + .48 * scale);
		bar(x + .36 * scale, y + .44 * scale, x + .46 * scale, y + .48 * scale);
		bar(x + .36 * scale, y + .48 * scale, x + .40 * scale, y + .64 * scale);
		bar(x + .04 * scale, y + .44 * scale, x + .16 * scale, y + .48 * scale);
		bar(x + .12 * scale, y + .48 * scale, x + .16 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightYellow);
		bar(x + .20 * scale, y + .28 * scale, x + .24 * scale, y + .32 * scale);
		bar(x + .28 * scale, y + .28 * scale, x + .40 * scale, y + .32 * scale);

		setfillstyle(SOLID_FILL, knightPalette().brown);
		bar(x + .08 * scale, y + .32 * scale, x + .46 * scale, y + .36 * scale);
		bar(x + .08 * scale, y + .36 * scale, x + .12 * scale, y + .44 * scale);

		setfillstyle(SOLID_FILL, BLACK);
		bar(x + .16 * scale, y + .36 * scale, x + .20 * scale, y + .44 * scale);
		bar(x + .36 * scale, y + .36 * scale, x + .40 * scale, y + .44 * scale);

		setfillstyle(SOLID_FILL, knightPalette().skin);
		bar(x + .20 * scale, y + .48 * scale, x + .36 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().red);
		// mouth
		bar(x + .24 * scale, y + .52 * scale, x + .32 * scale, y + .56 * scale);
		// Chalina
		bar(x + .12 * scale, y + .64 * scale, x + .76 * scale, y + .76 * scale);
		bar(x + .72 * scale, y + .68 * scale, x + .80 * scale, y + .88 * scale);
		bar(x + .78 * scale, y + .88 * scale, x + .84 * scale, y + .92 * scale);
		bar(x + .84 * scale, y + .92 * scale, x + .96 * scale, y + .96 * scale);

		setfillstyle(SOLID_FILL, knightPalette().darkRed);
		bar(x + .12 * scale, y + .72 * scale, x + .16 * scale, y + .76 * scale);
		bar(x + .64 * scale, y + .68 * scale, x + .72 * scale, y + .72 * scale);
		bar(x + .68 * scale, y + .72 * scale, x + .74 * scale, y + .76 * scale);
		bar(x + .72 * scale, y + .76 * scale, x + .74 * scale, y + .92 * scale);
		bar(x + .72 * scale, y + .88 * scale, x + .78 * scale, y + .92 * scale);
		bar(x + .76 * scale, y + .92 * scale, x + .84 * scale, y + .96 * scale);
		bar(x + .80 * scale, y + .80 * scale, x + .84 * scale, y + .88 * scale);
		bar(x + .84 * scale, y + .88 * scale, x + .88 * scale, y + .92 * scale);

		setfillstyle(SOLID_FILL, knightPalette().hardOrange);
		bar(x + .16 * scale, y + .64 * scale, x + .44 * scale, y + .68 * scale);
		bar(x + .20 * scale, y + .68 * scale, x + .52 * scale, y + .72 * scale);
	}

	void knightRight(const float x, const float y)
	{
		float scale = 0.8 * m_scale;
		setfillstyle(SOLID_FILL, BLACK);
		//Heroe border
		//casco
		bar(x + .48 * scale, y, x + .76 * scale, y + .04 * scale);
		bar(x + .76 * scale, y + .04 * scale, x + .84 * scale, y + .08 * scale);
		bar(x + .84 * scale, y + .08 * scale, x + .88 * scale, y + .12 * scale);
		bar(x + .88 * scale, y + .12 * scale, x + .92 * scale, y + .20 * scale);
		bar(x + .92 * scale, y + .20 * scale, x + .96 * scale, y + .32 * scale);
		//Eyes
		bar(x + .96 * scale, y + .32 * scale, x + 1. * scale, y + .48 * scale);
		//Chin
		bar(x + .92 * scale, y + .48 * scale, x + .96 * scale, y + .64 * scale);
		//Body
		bar(x + .88 * scale, y + .64 * scale, x + .92 * scale, y + .76 * scale);
		bar(x + .84 * scale, y + .76 * scale, x + .88 * scale, y + .88 * scale);
		//Line before Foot
		bar(x + .36 * scale, y + .88 * scale, x + .84 * scale, y + .92 * scale);
		//Foot
		bar(x + .72 * scale, y + .92 * scale, x + .84 * scale, y + .96 * scale);
		bar(x + .40 * scale, y + .92 * scale, x + .52 * scale, y + .96 * scale);
		bar(x + .72 * scale, y + .96 * scale, x + .80 * scale, y + 1. * scale);
		bar(x + .40 * scale, y + .96 * scale, x + .48 * scale, y + 1. * scale);
		//Second Part
		//Body
		bar(x + .28 * scale, y + .76 * scale, x + .36 * scale, y + .88 * scale);
		//Chalina
		bar(x + .28 * scale, y + .88 * scale, x + .32 * scale, y + .92 * scale);
		bar(x + .24 * scale, y + .92 * scale, x + .28 * scale, y + .96 * scale);
		bar(x, y + .96 * scale, x + .24 * scale, y + 1. * scale);
		bar(x, y + .92 * scale, x + .04 * scale, y + .96 * scale);
		bar(x + .04 * scale, y + .88 * scale, x + .12 * scale, y + .92 * scale);
		bar(x + .12 * scale, y + .80 * scale, x + .16 * scale, y + .88 * scale);
		bar(x + .16 * scale, y + .68 * scale, x + .20 * scale, y + .80 * scale);
		bar(x + .20 * scale, y + .64 * scale, x + .24 * scale, y + .68 * scale);
		bar(x + .24 * scale, y + .60 * scale, x + .32 * scale, y + .64 * scale);
		//Head
		bar(x + .28 * scale, y + .20 * scale, x + .32 * scale, y + .60 * scale);
		bar(x + .32 * scale, y + .12 * scale, x + .36 * scale, y + .20 * scale);
		bar(x + .36 * scale, y + .08 * scale, x + .40 * scale, y + .12 * scale);
		bar(x + .40 * scale, y + .04 * scale, x + .48 * scale, y + .08 * scale);

		//Filling
		setfillstyle(SOLID_FILL, knightPalette().grayBlue);
		bar(x + .48 * scale, y + .04 * scale, x + .76 * scale, y + .08 * scale);
		bar(x + .40 * scale, y + .08 * scale, x + .84 * scale, y + .12 * scale);
		bar(x + .36 * scale, y + .12 * scale, x + .88 * scale, y + .20 * scale);
		bar(x + .88 * scale, y + .52 * scale, x + .92 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightBlue);
		bar(x + .60 * scale, y + .08 * scale, x + .72 * scale, y + .12 * scale);
		bar(x + .68 * scale, y + .12 * scale, x + .72 * scale, y + .16 * scale);

		setfillstyle(SOLID_FILL, knightPalette().blue);
		bar(x + .36 * scale, y + .16 * scale, x + .40 * scale, y + .20 * scale);
		bar(x + .32 * scale, y + .20 * scale, x + .36 * scale, y + .64 * scale);
		bar(x + .36 * scale, y + .56 * scale, x + .40 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().darkBlue);
		bar(x + .40 * scale, y + .16 * scale, x + .52 * scale, y + .20 * scale);
		bar(x + .36 * scale, y + .20 * scale, x + .92 * scale, y + .28 * scale);
		bar(x + .36 * scale, y + .28 * scale, x + .52 * scale, y + .32 * scale);
		bar(x + .36 * scale, y + .32 * scale, x + .48 * scale, y + .56 * scale);
		bar(x + .40 * scale, y + .48 * scale, x + .60 * scale, y + .64 * scale);
		bar(x + .88 * scale, y + .48 * scale, x + .92 * scale, y + .52 * scale);
		bar(x + .36 * scale, y + .76 * scale, x + .84 * scale, y + .88 * scale);

		setfillstyle(SOLID_FILL, knightPalette().grayBlue);
		bar(x + .46 * scale, y + .56 * scale, x + .56 * scale, y + .60 * scale);
		bar(x + .50 * scale, y + .60 * scale, x + .56 * scale, y + .64 * scale);
		bar(x + .58 * scale, y + .60 * scale, x + .68 * scale, y + .86 * scale);
		bar(x + .72 * scale, y + .80 * scale, x + .84 * scale, y + .86 * scale);
		bar(x + .80 * scale, y + .76 * scale, x + .84 * scale, y + .80 * scale);

		setfillstyle(SOLID_FILL, knightPalette().blue);
		bar(x + .36 * scale, y + .76 * scale, x + .40 * scale, y + .84 * scale);
		bar(x + .80 * scale, y + .84 * scale, x + .84 * scale, y + .88 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightBlue);
		bar(x + .76 * scale, y + .76 * scale, x + .80 * scale, y + .80 * scale);
		bar(x + .68 * scale, y + .80 * scale, x + .76 * scale, y + .84 * scale);
		bar(x + .62 * scale, y + .76 * scale, x + .68 * scale, y + .80 * scale);

		setfillstyle(SOLID_FILL, knightPalette().pink);
		bar(x + .54 * scale, y + .36 * scale, x + .92 * scale, y + .48 * scale);

		setfillstyle(SOLID_FILL, knightPalette().orange);
		bar(x + .46 * scale, y + .32 * scale, x + .50 * scale, y + .48 * scale);
		bar(x + .50 * scale, y + .28 * scale, x + .54 * scale, y + .32 * scale);
		bar(x + .84 * scale, y + .28 * scale, x + .92 * scale, y + .32 * scale);
		bar(x + .92 * scale, y + .32 * scale, x + .96 * scale, y + .44 * scale);
		bar(x + .80 * scale, y + .44 * scale, x + .84 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightOrange);
		bar(x + .54 * scale, y + .28 * scale, x + .84 * scale, y + .32 * scale);
		bar(x + .50 * scale, y + .32 * scale, x + .54 * scale, y + .48 * scale);
		bar(x + .54 * scale, y + .44 * scale, x + .64 * scale, y + .48 * scale);
		bar(x + .60 * scale, y + .48 * scale, x + .64 * scale, y + .64 * scale);
		bar(x + .84 * scale, y + .44 * scale, x + .96 * scale, y + .48 * scale);
		bar(x + .84 * scale, y + .48 * scale, x + .88 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().lightYellow);
		bar(x + .76 * scale, y + .28 * scale, x + .80 * scale, y + .32 * scale);
		bar(x + .60 * scale, y + .28 * scale, x + .72 * scale, y + .32 * scale);

		setfillstyle(SOLID_FILL, knightPalette().brown);
		bar(x + .54 * scale, y + .32 * scale, x + .92 * scale, y + .36 * scale);
		bar(x + .88 * scale, y + .36 * scale, x + .92 * scale, y + .44 * scale);

		setfillstyle(SOLID_FILL, BLACK);
		bar(x + .80 * scale, y + .36 * scale, x + .84 * scale, y + .44 * scale);
		bar(x + .60 * scale, y + .36 * scale, x + .64 * scale, y + .44 * scale);

		setfillstyle(SOLID_FILL, knightPalette().skin);
		bar(x + .64 * scale, y + .48 * scale, x + .80 * scale, y + .64 * scale);

		setfillstyle(SOLID_FILL, knightPalette().red);
		//mouth
		bar(x + .68 * scale, y + .52 * scale, x + .76 * scale, y + .56 * scale);
		//Chalina
		bar(x + .24 * scale, y + .64 * scale, x + .88 * scale, y + .76 * scale);
		bar(x + .20 * scale, y + .68 * scale, x + .28 * scale, y + .88 * scale);
		bar(x + .16 * scale, y + .88 * scale, x + .24 * scale, y + .92 * scale);
		bar(x + .04 * scale, y + .92 * scale, x + .18 * scale, y + .96 * scale);

		setfillstyle(SOLID_FILL, knightPalette().darkRed);
		bar(x + .84 * scale, y + .72 * scale, x + .88 * scale, y + .76 * scale);
		bar(x + .28 * scale, y + .68 * scale, x + .36 * scale, y + .72 * scale);
		bar(x + .26 * scale, y + .72 * scale, x + .32 * scale, y + .76 * scale);
		bar(x + .26 * scale, y + .76 * scale, x + .28 * scale, y + .92 * scale);
		bar(x + .22 * scale, y + .88 * scale, x + .28 * scale, y + .92 * scale);
		bar(x + .18 * scale, y + .92 * scale, x + .24 * scale, y + .96 * scale);
		bar(x + .16 * scale, y + .80 * scale, x + .20 * scale, y + .88 * scale);
		bar(x + .12 * scale, y + .88 * scale, x + .16 * scale, y + .92 * scale);

		setfillstyle(SOLID_FILL, knightPalette().hardOrange);
		bar(x + .56 * scale, y + .64 * scale, x + .84 * scale, y + .68 * scale);
		bar(x + .48 * scale, y + .68 * scale, x + .80 * scale, y + .72 * scale);
	}


	void grandSlimeRight(int x, int y)
	{
		int a = 2, x1, y1, x2, y2, x3, y3, x4, y4;
		int scale = 0.6 * m_scale;

		setcolor(a);
		//Cuerpo
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, RED);
		ellipse(x + .6 * scale, y + .78 * scale, 0, 180, .6 * scale, .72 * scale);
		ellipse(x + .6 * scale, y + .78 * scale, 180, 360, .6 * scale, .48 * scale);
		floodfill(x + .6 * scale, y + .8 * scale, a);

		setlinestyle(0, 0, 0);

		//Poder
		scale_morado color_m;

		setfillstyle(SOLID_FILL, scale_azul().RoyalBlue);
		fillellipse(x + .66 * scale, y + .35 * scale, .32 * scale, .25 * scale);
		setfillstyle(SOLID_FILL, color_m.BlueViolet);
		fillellipse(x + .7 * scale, y + .3 * scale, .15 * scale, .15 * scale);
		setfillstyle(SOLID_FILL, color_m.DarkPurple);
		fillellipse(x + .7 * scale, y + .3 * scale, .14 * scale, .14 * scale);

		//Ojo D

		setcolor(BLACK);
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, YELLOW);
		ellipse(x + .79 * scale, y + .64 * scale, 180, 360, 0.06 * scale, 0.05 * scale);
		getxy(x + .79 * scale, y + .64 * scale, 0.06 * scale, 180, x1, y1);
		getxy(x + .79 * scale, y + .64 * scale, 0.06 * scale, 360, x2, y2);
		sector(x + .79 * scale, y + .64 * scale, 180, 360, 0.06 * scale, 0.05 * scale);

		int ojo_D[] = {
			static_cast<int>(x1),
			static_cast<int>(y1),
			static_cast<int>(x + .73 * scale),
			static_cast<int>(y + .54 * scale),
			static_cast<int>(x + .88 * scale),
			static_cast<int>(y + .39 * scale),
			static_cast<int>(x + .88 * scale),
			static_cast<int>(y + .55 * scale),
			static_cast<int>(x2),
			static_cast<int>(y2)
		};
		
		fillpoly(5, ojo_D);

		setcolor(YELLOW);
		line(x + .74 * scale, y + .64 * scale, x + .84 * scale, y + .64 * scale);

		//Ojo I
		setcolor(BLACK);
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, YELLOW);
		ellipse(x + .56 * scale, y + .65 * scale, 180, 360, 0.06 * scale, 0.05 * scale);
		getxy(x + .56 * scale, y + .65 * scale, 0.06 * scale, 180, x3, y3);
		getxy(x + .56 * scale, y + .65 * scale, 0.06 * scale, 360, x4, y4);
		sector(x + .56 * scale, y + .65 * scale, 180, 360, 0.06 * scale, 0.05 * scale);

		int ojo_I[] = {
			static_cast<int>(x3),
			static_cast<int>(y3),
			static_cast<int>(x + .45 * scale),
			static_cast<int>(y + .54 * scale),
			static_cast<int>(x + .48 * scale),
			static_cast<int>(y + .37 * scale),
			static_cast<int>(x + .61 * scale),
			static_cast<int>(y + .53 * scale),
			static_cast<int>(x4),
			static_cast<int>(y4)
		};
		fillpoly(5, ojo_I);

		setcolor(YELLOW);
		line(x + .51 * scale, y + .65 * scale, x + .61 * scale, y + .65 * scale);

		//boca
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);

		int boca[] = {
			static_cast<int>(x + .25 * scale),static_cast<int>(y + .73 * scale),
			static_cast<int>(x + .3 * scale),static_cast<int>(y + .65 * scale),
			static_cast<int>(x + .32 * scale),static_cast<int>(y + .8 * scale),
			static_cast<int>(x + .4 * scale),static_cast<int>(y + .7 * scale),
			static_cast<int>(x + .46 * scale),static_cast<int>(y + .74 * scale),
			static_cast<int>(x + .5 * scale),static_cast<int>(y + .92 * scale),
			static_cast<int>(x + .55 * scale),static_cast<int>(y + .77 * scale),
			static_cast<int>(x + .62 * scale),static_cast<int>(y + .96 * scale),
			static_cast<int>(x + .7 * scale),static_cast<int>(y + .75 * scale),
			static_cast<int>(x + .75 * scale),static_cast<int>(y + .95 * scale),
			static_cast<int>(x + .82 * scale),static_cast<int>(y + .76 * scale),
			static_cast<int>(x + .85 * scale),static_cast<int>(y + .92 * scale), //
			static_cast<int>(x + .95 * scale),static_cast<int>(y + .7 * scale),
			static_cast<int>(x + .97 * scale),static_cast<int>(y + .86 * scale), //
			static_cast<int>(x + 1.04 * scale),static_cast<int>(y + .75 * scale),
			static_cast<int>(x + 1.06 * scale),static_cast<int>(y + .8 * scale),
			static_cast<int>(x + .98 * scale),static_cast<int>(y + .96 * scale),
			static_cast<int>(x + .97 * scale),static_cast<int>(y + .87 * scale),
			static_cast<int>(x + .9 * scale),static_cast<int>(y + 1.05 * scale),
			static_cast<int>(x + .85 * scale),static_cast<int>(y + .93 * scale),
			static_cast<int>(x + .77 * scale),static_cast<int>(y + 1.08 * scale),
			static_cast<int>(x + .74 * scale),static_cast<int>(y + 1.04 * scale),
			static_cast<int>(x + .67 * scale),static_cast<int>(y + 1.08 * scale),
			static_cast<int>(x + .63 * scale),static_cast<int>(y + 1.02 * scale),
			static_cast<int>(x + .53 * scale),static_cast<int>(y + 1.09 * scale),
			static_cast<int>(x + .48 * scale),static_cast<int>(y + .97 * scale),
			static_cast<int>(x + .4 * scale),static_cast<int>(y + 1.06 * scale),
			static_cast<int>(x + .34 * scale),static_cast<int>(y + .9 * scale),
			static_cast<int>(x + .3 * scale),static_cast<int>(y + .96 * scale),
			static_cast<int>(x + .3 * scale),static_cast<int>(y + .82 * scale),
			static_cast<int>(x + .2 * scale),static_cast<int>(y + .86 * scale),
			static_cast<int>(x + .19 * scale),static_cast<int>(y + .76 * scale),
		};
		fillpoly(32, boca);
	}
	void grandSlimeLeft(int x, int y)
	{
		int a = 0, x1, y1, x2, y2, x3, y3, x4, y4;
		int scale = 0.6 * m_scale;

		setcolor(a);
		//Cuerpo
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, RED);
		ellipse(x + .61 * scale, y + .78 * scale, 0, 180, .6 * scale, .72 * scale);
		ellipse(x + .61 * scale, y + .78 * scale, 180, 360, .6 * scale, .48 * scale);
		floodfill(x + .61 * scale, y + .8 * scale, a);

		setlinestyle(0, 0, 0);

		//Poder
		scale_morado color_m;

		setfillstyle(SOLID_FILL, scale_azul().RoyalBlue);
		fillellipse(x + .55 * scale, y + .35 * scale, .32 * scale, .25 * scale);
		setfillstyle(SOLID_FILL, color_m.BlueViolet);
		fillellipse(x + .51 * scale, y + .3 * scale, .15 * scale, .15 * scale);
		setfillstyle(SOLID_FILL, color_m.DarkPurple);
		fillellipse(x + .51 * scale, y + .3 * scale, .14 * scale, .14 * scale);

		//Ojo D

		setcolor(BLACK);
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, YELLOW);
		ellipse(x + .42 * scale, y + .64 * scale, 180, 360, 0.06 * scale, 0.05 * scale);
		getxy(x + .42 * scale, y + .64 * scale, 0.06 * scale, 180, x1, y1);
		getxy(x + .42 * scale, y + .64 * scale, 0.06 * scale, 360, x2, y2);
		sector(x + .42 * scale, y + .64 * scale, 180, 360, 0.06 * scale, 0.05 * scale);

		int ojo_D[] = {
			static_cast<int>(x2),
			static_cast<int>(y2),
			static_cast<int>(x + .48 * scale),
			static_cast<int>(y + .54 * scale),
			static_cast<int>(x + .33 * scale),
			static_cast<int>(y + .39 * scale),
			static_cast<int>(x + .33 * scale),
			static_cast<int>(y + .55 * scale),
			static_cast<int>(x1),
			static_cast<int>(y1)
		};
		fillpoly(5, ojo_D);

		setcolor(YELLOW);
		line(x + .47 * scale, y + .64 * scale, x + .37 * scale, y + .64 * scale);

		//Ojo I
		setcolor(BLACK);
		setlinestyle(0, 0, 2);
		setfillstyle(SOLID_FILL, YELLOW);
		ellipse(x + .65 * scale, y + .65 * scale, 180, 360, 0.06 * scale, 0.05 * scale);
		getxy(x + .65 * scale, y + .65 * scale, 0.06 * scale, 180, x3, y3);
		getxy(x + .65 * scale, y + .65 * scale, 0.06 * scale, 360, x4, y4);
		sector(x + .65 * scale, y + .65 * scale, 180, 360, 0.06 * scale, 0.05 * scale);

		int ojo_I[] = {
			static_cast<int>(x4),
			static_cast<int>(y4),
			static_cast<int>(x + .76 * scale),
			static_cast<int>(y + .54 * scale),
			static_cast<int>(x + .73 * scale),
			static_cast<int>(y + .37 * scale),
			static_cast<int>(x + .6 * scale),
			static_cast<int>(y + .53 * scale),
			static_cast<int>(x3),
			static_cast<int>(y3)
		};
		fillpoly(5, ojo_I);

		setcolor(YELLOW);
		line(x + .7 * scale, y + .65 * scale, x + .6 * scale, y + .65 * scale);

		//boca
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);

		int boca[] = {
			static_cast<int>(x + .96 * scale),static_cast<int>(y + .73 * scale),
			static_cast<int>(x + .91 * scale),static_cast<int>(y + .65 * scale),
			static_cast<int>(x + .89 * scale),static_cast<int>(y + .8 * scale),
			static_cast<int>(x + .81 * scale),static_cast<int>(y + .7 * scale),
			static_cast<int>(x + .75 * scale),static_cast<int>(y + .74 * scale),
			static_cast<int>(x + .71 * scale),static_cast<int>(y + .92 * scale),
			static_cast<int>(x + .66 * scale),static_cast<int>(y + .77 * scale),
			static_cast<int>(x + .59 * scale),static_cast<int>(y + .96 * scale),
			static_cast<int>(x + .51 * scale),static_cast<int>(y + .75 * scale),
			static_cast<int>(x + .46 * scale),static_cast<int>(y + .95 * scale),
			static_cast<int>(x + .39 * scale),static_cast<int>(y + .76 * scale),
			static_cast<int>(x + .36 * scale),static_cast<int>(y + .92 * scale), //
			static_cast<int>(x + .26 * scale),static_cast<int>(y + .7 * scale),
			static_cast<int>(x + .24 * scale),static_cast<int>(y + .86 * scale), //
			static_cast<int>(x + .17 * scale),static_cast<int>(y + .75 * scale),
			static_cast<int>(x + .15 * scale),static_cast<int>(y + .8 * scale),
			static_cast<int>(x + .23 * scale),static_cast<int>(y + .96 * scale),
			static_cast<int>(x + .24 * scale),static_cast<int>(y + .87 * scale),
			static_cast<int>(x + .31 * scale),static_cast<int>(y + 1.05 * scale),
			static_cast<int>(x + .36 * scale),static_cast<int>(y + .93 * scale),
			static_cast<int>(x + .44 * scale),static_cast<int>(y + 1.08 * scale),
			static_cast<int>(x + .47 * scale),static_cast<int>(y + 1.04 * scale),
			static_cast<int>(x + .54 * scale),static_cast<int>(y + 1.08 * scale),
			static_cast<int>(x + .58 * scale),static_cast<int>(y + 1.02 * scale),
			static_cast<int>(x + .68 * scale),static_cast<int>(y + 1.09 * scale),
			static_cast<int>(x + .73 * scale),static_cast<int>(y + .97 * scale),
			static_cast<int>(x + .81 * scale),static_cast<int>(y + 1.06 * scale),
			static_cast<int>(x + .87 * scale),static_cast<int>(y + .9 * scale),
			static_cast<int>(x + .91 * scale),static_cast<int>(y + .96 * scale),
			static_cast<int>(x + .91 * scale),static_cast<int>(y + .82 * scale),
			static_cast<int>(x + 1.01 * scale),static_cast<int>(y + .86 * scale),
			static_cast<int>(x + 1.02 * scale),static_cast<int>(y + .76 * scale),
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
			static_cast<int>(x+.37*scale),
			static_cast<int>(y+.85*scale),
			static_cast<int>(x+.1*scale),
			static_cast<int>(y+.86*scale),
			static_cast<int>(x+.04*scale),
			static_cast<int>(y+.8*scale),
			static_cast<int>(x+.04*scale),
			static_cast<int>(y+.67*scale),
			static_cast<int>(x+.17*scale),
			static_cast<int>(y+.75*scale),
			static_cast<int>(x+.2*scale),
			static_cast<int>(y+.53*scale),
			static_cast<int>(x+.37*scale),
			static_cast<int>(y+.5*scale)
			};
		fillpoly(7, hair);

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		int hair_d[] = {
			static_cast<int>(x+.94*scale),
			static_cast<int>(y+.44*scale),
			static_cast<int>(x+1.01*scale),
			static_cast<int>(y+.53*scale),
			static_cast<int>(x+1.01*scale),
			static_cast<int>(y+.68*scale),
			static_cast<int>(x+.9*scale),
			static_cast<int>(y+.68*scale),
			static_cast<int>(x+.85*scale),
			static_cast<int>(y+.45*scale)
			};
		fillpoly(5, hair_d);

		//Cabeza
		setcolor(BLACK);
		setlinestyle(0,0,2);
		setfillstyle(SOLID_FILL, color.Wheat);
		ellipse(x+.63*scale,y+.52*scale,360,180,.27*scale,.25*scale);
		getxy(x+.63*scale,y+.52*scale,.27*scale, 180,x1,y1);
		getxy(x+.63*scale,y+.52*scale,.27*scale, 360,x2,y2);
		sector(x+.63*scale,y+.52*scale,360,180,.27*scale,.25*scale);
    
		setcolor(BLACK);
		rectangle(x1,y1,x2,y+.68*scale);
		bar(x1,y1,x2,y+.68*scale);

		setcolor(color.Wheat);
		line(x1+0.02,y1,x2-0.02,y2);

		setlinestyle(0,0,0);

		 //Ojos
		//Izquierdo
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		rectangle(x+.45*scale,y+.52*scale,x+.54*scale,y+.56*scale);
		bar(x+.45*scale,y+.52*scale,x+.54*scale,y+.56*scale);

		setfillstyle(SOLID_FILL, RED);
		fillellipse(x+.52*scale,y+.64*scale,0.02*scale,0.06*scale);

		//Derecho
		setfillstyle(SOLID_FILL, color.DeepPink);
		rectangle(x+.82*scale,y+.52*scale,x+.9*scale,y+.56*scale);
		bar(x+.82*scale,y+.52*scale,x+.9*scale,y+.56*scale);

		setfillstyle(SOLID_FILL, RED);
		fillellipse(x+.84*scale,y+.64*scale,0.02*scale,0.06*scale);

		//chalina
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		rectangle(x+.22*scale,y+.68*scale,x+.10*scale,y+.76*scale);
		bar(x+.22*scale,y+.68*scale,x+.10*scale,y+.76*scale);

		setfillstyle(SOLID_FILL, color.HotPink);
		rectangle(x+.27*scale,y+.75*scale,x+.95*scale,y+.84*scale);
		bar(x+.27*scale,y+.75*scale,x+.95*scale,y+.84*scale);

		setfillstyle(SOLID_FILL, color.MediumBlue);
		bar(x+.5*scale,y+.84*scale,x+.78*scale,y+1.04*scale);

		//Capa

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		int capa_1[] = {
			static_cast<int>(x+.27*scale),
			static_cast<int>(y+.84*scale),
			static_cast<int>(x+.08*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.52*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.62*scale),
			static_cast<int>(y+.98*scale),
			static_cast<int>(x+.62*scale),
			static_cast<int>(y+.84*scale)
			};
		fillpoly(5, capa_1);

		int capa_2[] = {
			static_cast<int>(x+.95*scale),
			static_cast<int>(y+.84*scale),
			static_cast<int>(x+1.03*scale),
			static_cast<int>(y+.97*scale),
			static_cast<int>(x+.94*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.77*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.72*scale),
			static_cast<int>(y+.98*scale),
			static_cast<int>(x+.72*scale),
			static_cast<int>(y+.84*scale)
			};
		fillpoly(6, capa_2);

		//Sombrero
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		int hat[] = {
			static_cast<int>(x+ scale),
			static_cast<int>(y+ .55*scale),
			static_cast<int>(x+44*scale),
			static_cast<int>(y+55*scale),
			static_cast<int>(x+1.04*scale),
			static_cast<int>(y+.44*scale),
			static_cast<int>(x+1.2*scale),
			static_cast<int>(y+.38*scale),
			static_cast<int>(x+.85*scale),
			static_cast<int>(y+.28*scale),
			static_cast<int>(x+.72*scale),
			static_cast<int>(y+.15*scale),
			static_cast<int>(x+.67*scale),
			static_cast<int>(y+.07*scale),
			static_cast<int>(x+.57*scale),
			static_cast<int>(y+.02*scale),
			static_cast<int>(x+.36*scale),
			static_cast<int>(y+.02*scale),
			static_cast<int>(x+.17*scale),
			static_cast<int>(y+.17*scale),
			static_cast<int>(x+.35*scale),
			static_cast<int>(y+.17*scale),
			static_cast<int>(x+.35*scale),
			static_cast<int>(y+.27*scale),
			static_cast<int>(x+.26*scale),
			static_cast<int>(y+.35*scale),
			static_cast<int>(x+.22*scale),
			static_cast<int>(y+.4*scale)
			};
		fillpoly(14, hat);

		setcolor(colorM.SaddleBrown);
		setfillstyle(SOLID_FILL, colorM.SaddleBrown);
		int hat_a[] = {
			static_cast<int>(x+.33*scale),
			static_cast<int>(y+.44*scale),
			static_cast<int>(x+.39*scale),
			static_cast<int>(y+.35*scale),
			static_cast<int>(x+.5*scale),
			static_cast<int>(y+.27*scale),
			static_cast<int>(x+.45*scale),
			static_cast<int>(y+scale),
			static_cast<int>(x+.63*scale),
			static_cast<int>(y+.15*scale),
			static_cast<int>(x+.67*scale),
			static_cast<int>(y+.25*scale),
			static_cast<int>(x+.77*scale),
			static_cast<int>(y+.32*scale),
			static_cast<int>(x+.91*scale),
			static_cast<int>(y+.36*scale),
			static_cast<int>(x+.63*scale),
			static_cast<int>(y+.4*scale)
			};
		fillpoly(9, hat_a);


		// Pie
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		int pie_I[] = {
			static_cast<int>(x+.31*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.31*scale),
			static_cast<int>(y+1.16*scale),
			static_cast<int>(x+.41*scale),
			static_cast<int>(y+1.16*scale),
			static_cast<int>(x+.48*scale),
			static_cast<int>(y+1.04*scale)
			};
		fillpoly(4, pie_I);

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		int pie_D[] = {
			static_cast<int>(x+.72*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.72*scale),
			static_cast<int>(y+1.16*scale),
			static_cast<int>(x+.82*scale),
			static_cast<int>(y+1.16*scale),
			static_cast<int>(x+.9*scale),
			static_cast<int>(y+1.04*scale)
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
			static_cast<int>(x+.84*scale),
			static_cast<int>(y+.85*scale),
			static_cast<int>(x+1.11*scale),
			static_cast<int>(y+.86*scale),
			static_cast<int>(x+1.17*scale),
			static_cast<int>(y+.8*scale),
			static_cast<int>(x+1.17*scale),
			static_cast<int>(y+.67*scale),
			static_cast<int>(x+1.04*scale),
			static_cast<int>(y+.75*scale),
			static_cast<int>(x+1.01*scale),
			static_cast<int>(y+.53*scale),
			static_cast<int>(x+.84*scale),
			static_cast<int>(y+.5*scale)
			};
		fillpoly(7, hair);

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		int hair_d[] = {
			static_cast<int>(x+.27*scale),
			static_cast<int>(y+.44*scale),
			static_cast<int>(x+.2*scale),
			static_cast<int>(y+.53*scale),
			static_cast<int>(x+.2*scale),
			static_cast<int>(y+.68*scale),
			static_cast<int>(x+.31*scale),
			static_cast<int>(y+.68*scale),
			static_cast<int>(x+.36*scale),
			static_cast<int>(y+.45*scale)
			};
		fillpoly(5, hair_d);

		//Cabeza
		setcolor(BLACK);
		setlinestyle(0,0,2);
		setfillstyle(SOLID_FILL, color.Wheat);
		ellipse(x+.58*scale,y+.52*scale,360,180,.27*scale,.25*scale);
		getxy(x+.58*scale,y+.52*scale,.27*scale, 180,x1,y1);
		getxy(x+.58*scale,y+.52*scale,.27*scale, 360,x2,y2);
		sector(x+.58*scale,y+.52*scale,360,180,.27*scale,.25*scale);
    
		setcolor(BLACK);
		rectangle(x1,y1,x2,y+.68*scale);
		bar(x1,y1,x2,y+.68*scale);

		setcolor(color.Wheat);
		line(x1+0.02,y1,x2-0.02,y2);

		setlinestyle(0,0,0);

		 //Ojos
		//Izquierdo
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, color.DeepPink);
		rectangle(x+.76*scale,y+.52*scale,x+.67*scale,y+.56*scale);
		bar(x+.76*scale,y+.52*scale,x+.67*scale,y+.56*scale);

		setfillstyle(SOLID_FILL, RED);
		fillellipse(x+.69*scale,y+.64*scale,0.02*scale,0.06*scale);

		//Derecho
		setfillstyle(SOLID_FILL, color.DeepPink);
		rectangle(x+.39*scale,y+.52*scale,x+.31*scale,y+.56*scale);
		bar(x+.39*scale,y+.52*scale,x+.31*scale,y+.56*scale);

		setfillstyle(SOLID_FILL, RED);
		fillellipse(x+.37*scale,y+.64*scale,0.02*scale,0.06*scale);

		//chalina
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		rectangle(x+.99*scale,y+.68*scale,x+.21*scale,y+.76*scale);
		bar(x+.99*scale,y+.68*scale,x+.21*scale,y+.76*scale);

		setfillstyle(SOLID_FILL, color.HotPink);
		rectangle(x+.94*scale,y+.75*scale,x+.26*scale,y+.84*scale);
		bar(x+.94*scale,y+.75*scale,x+.26*scale,y+.84*scale);

		setfillstyle(SOLID_FILL, color.MediumBlue);
		bar(x+.71*scale,y+.84*scale,x+.43*scale,y+1.04*scale);

		//Capa
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		int capa_1[] = {
			static_cast<int>(x+.94*scale),
			static_cast<int>(y+.84*scale),
			static_cast<int>(x+1.13*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.69*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.59*scale),
			static_cast<int>(y+.98*scale),
			static_cast<int>(x+.59*scale),
			static_cast<int>(y+.84*scale)
			};
		fillpoly(5, capa_1);

		int capa_2[] = {
			static_cast<int>(x+.26*scale),
			static_cast<int>(y+.84*scale),
			static_cast<int>(x+.18*scale),
			static_cast<int>(y+.97*scale),
			static_cast<int>(x+.27*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.44*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.49*scale),
			static_cast<int>(y+.98*scale),
			static_cast<int>(x+.49*scale),
			static_cast<int>(y+.84*scale)
			};
		fillpoly(6, capa_2);

		//Sombrero
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, colorM.DarkBrown);
		int hat[] = {
			static_cast<int>(x+1.11*scale),
			static_cast<int>(y+.55*scale),
			static_cast<int>(x+.81*scale),
			static_cast<int>(y+.5*scale),
			static_cast<int>(x+.17*scale),
			static_cast<int>(y+.44*scale),
			static_cast<int>(x+0.01*scale),
			static_cast<int>(y+.38*scale),
			static_cast<int>(x+.36*scale),
			static_cast<int>(y+.28*scale),
			static_cast<int>(x+.49*scale),
			static_cast<int>(y+.15*scale),
			static_cast<int>(x+.54*scale),
			static_cast<int>(y+0.07*scale),
			static_cast<int>(x+.64*scale),
			static_cast<int>(y+0.02*scale),
			static_cast<int>(x+.85*scale),
			static_cast<int>(y+0.02*scale),
			static_cast<int>(x+1.04*scale),
			static_cast<int>(y+.17*scale),
			static_cast<int>(x+.86*scale),
			static_cast<int>(y+.17*scale),
			static_cast<int>(x+.86*scale),
			static_cast<int>(y+.27*scale),
			static_cast<int>(x+.95*scale),
			static_cast<int>(y+.35*scale),
			static_cast<int>(x+.99*scale),
			static_cast<int>(y+.4*scale)
			};
		fillpoly(14, hat);

		setcolor(colorM.SaddleBrown);
		setfillstyle(SOLID_FILL, colorM.SaddleBrown);
		int hat_a[] = {
			static_cast<int>(x+.88*scale),
			static_cast<int>(y+.44*scale),
			static_cast<int>(x+.82*scale),
			static_cast<int>(y+.35*scale),
			static_cast<int>(x+.71*scale),
			static_cast<int>(y+.27*scale),
			static_cast<int>(x+.76*scale),
			static_cast<int>(y+scale),
			static_cast<int>(x+.58*scale),
			static_cast<int>(y+.15*scale),
			static_cast<int>(x+.54*scale),
			static_cast<int>(y+.25*scale),
			static_cast<int>(x+.44*scale),
			static_cast<int>(y+.32*scale),
			static_cast<int>(x+.3*scale),
			static_cast<int>(y+.36*scale),
			static_cast<int>(x+.58*scale),
			static_cast<int>(y+.4*scale)
			};
		fillpoly(9, hat_a);


		// Pie
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		int pie_I[] = {
			static_cast<int>(x+.9*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.9*scale),
			static_cast<int>(y+1.16*scale),
			static_cast<int>(x+.8*scale),
			static_cast<int>(y+1.16*scale),
			static_cast<int>(x+.73*scale),
			static_cast<int>(y+1.04*scale)
			};
		fillpoly(4, pie_I);

		setcolor(BLACK);
		setfillstyle(SOLID_FILL, BLACK);
		int pie_D[] = {
			static_cast<int>(x+.49*scale),
			static_cast<int>(y+1.04*scale),
			static_cast<int>(x+.49*scale),
			static_cast<int>(y+1.16*scale),
			static_cast<int>(x+.39*scale),
			static_cast<int>(y+1.16*scale),
			static_cast<int>(x+.31*scale),
			static_cast<int>(y+1.04*scale)
			};
		fillpoly(4, pie_D);

	}

	void V(int x,int y){
		int e = 0.8*m_scale;
		setfillstyle(1,8);
		bar(x,y,x+e,y+e);
	}

	void SnowWall(const int x, const int y)
	{

	}

	void StoneWall(const int x, const int y)
	{
		int scale = 0.8 * m_scale;
		setfillstyle(SOLID_FILL, StoneWallPalette().BluishGreen);
		bar(x, y, x + .92 * scale, y + .92 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().BrayishBlue);
		bar(x + .08 * scale, y + .08 * scale, x + .84 * scale, y + .84 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().DarkBrayishBlue);
		bar(x + .16 * scale, y + .16 * scale, x + .76 * scale, y + .76 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().MediumBrayishBlue);
		bar(x + .24 * scale, y + .24 * scale, x + .68 * scale, y + .68 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().mLightGray);
		bar(x + .32 * scale, y + .32 * scale, x + .60 * scale, y + .60 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().darkGray);
		bar(x + .92 * scale, y, x + 1.0 * scale, y + 1.0 * scale);
		bar(x, y + .92 * scale, x + 1.0 * scale, y + 1.0 * scale);
		bar(x + .92 * scale, y, x + 1.0 * scale, y + 1.4 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().vinil);
		bar(x, y + 1.0 * scale, x + .92 * scale, y + 1.4 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().darkGray);
		bar(x + 0.08 * scale, y + 1.08 * scale, x + .84 * scale, y + 1.32 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().vinil);
		bar(x + .16 * scale, y + 1.12 * scale, x + .76 * scale, y + 1.28 * scale);

		setfillstyle(SOLID_FILL, StoneWallPalette().lightDarkGray);
		bar(x + .24 * scale, y + 1.16 * scale, x + .76 * scale, y + 1.28 * scale);
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