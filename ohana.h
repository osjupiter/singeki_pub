#pragma once
#include "enemy.h"

class ohana : public enemy{
	UnitState pre_state;
public:
	ohana(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};