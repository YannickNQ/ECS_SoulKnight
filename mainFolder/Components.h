#pragma once
#include "Vec2.h"
#include "../winbgim.h"

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
public:
	//TODO
	//This function draw the shape of the entities
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