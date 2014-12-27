#pragma once
#include "enemy.h"

class steam : public enemy{
public:
	steam(int fx, int fy, int st);
	void main(int front);
	void draw(int cx);
};