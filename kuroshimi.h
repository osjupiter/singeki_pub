#pragma once
#include "enemy.h"

class kuroshimi : public enemy{
	int back;
	int p_back;
public:
	kuroshimi(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};