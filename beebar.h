#pragma once
#include "enemy.h"

class beebar : public enemy{

public:
	beebar(int, int, int);
	void main(int);
	void draw(int);
	static void init();

};