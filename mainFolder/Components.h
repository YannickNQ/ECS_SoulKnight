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