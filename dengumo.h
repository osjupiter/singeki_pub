#pragma once
#include "enemy.h"

class dengumo : public enemy{
	bool thunder;
	int thunder_count;
public:
	dengumo(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};