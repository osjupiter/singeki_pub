#pragma once
#include "enemy.h"

class senkoutei : public enemy{

public:
	senkoutei(int, int, int);
	void main(int);
	void draw(int);
	static void init();
	virtual Position decideTargetPos(int target_x_rand, int target_x_sky);
	virtual void decideDirection(int front);

};