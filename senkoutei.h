#pragma once
#include "enemy.h"

class senkoutei : public enemy{

public:
	senkoutei(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};