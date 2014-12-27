#pragma once
#include "musume.h"

class segway : public musume {
private:
	bool atk_done;
	static int num;
public:
	segway(int fx, int ln);
	void main(int);
	void draw(int);
	static void init();
	static int getNum();
	static void setNum(int);
	void decideDirection(int front);
	void damage(int, int);
};