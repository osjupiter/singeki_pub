#pragma once
#include "enemy.h"

class kuroshimi : public enemy{

public:
	kuroshimi(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};