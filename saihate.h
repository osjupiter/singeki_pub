#pragma once
#include "enemy.h"

class saihate : public enemy{
public:
	saihate(int fx,int fy, int st);
	void main(int front);
	void draw(int cx);
};