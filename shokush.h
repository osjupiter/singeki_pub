#pragma once
#include "enemy.h"

class shokush : public enemy{
	UnitState pre_state;

public:
	shokush(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};
