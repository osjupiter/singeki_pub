#pragma once
#include "enemy.h"

class monoris : public enemy{
	int beam_count;
public:
	monoris(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};