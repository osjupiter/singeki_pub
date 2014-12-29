#pragma once
#include "enemy.h"

class tamanegi : public enemy{
	int dx;
public:
	tamanegi(int fx, int fy, int st);
	void main(int front);
	void draw(int cx);
};