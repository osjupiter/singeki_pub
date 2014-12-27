#pragma once
#include "enemy.h"

class saihate : public enemy{
	bool first_atk;
	int loop_count;

public:
	saihate(int fx,int fy, int st);
	void main(int front);
	void draw(int cx);
};