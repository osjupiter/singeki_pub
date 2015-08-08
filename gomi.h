#pragma once
#include "effect.h"

class gomi :public effect{
	Direction dir;
	int power;
	int dx[25];
	int count[25];
	int d[25];

public:
	gomi(int fx, int fy, int p);
	void main();
	void draw(int);
};
