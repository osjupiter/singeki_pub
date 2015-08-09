#pragma once
#include "enemy.h"

class ikai : public enemy{

public:
	ikai(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};