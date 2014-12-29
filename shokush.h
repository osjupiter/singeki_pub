#pragma once
#include "enemy.h"

class shokush : public enemy{

public:
	shokush(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};
