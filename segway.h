#pragma once
#include "musume.h"

class segway : public musume {
private:

	static int num;
public:
	segway(int fx, int fy, int ln, shared_ptr<Parameter>);
	void main(int);
	void draw(int);
	static void init();
	static int getNum();
	static void setNum(int);

	void damage(int, int);
};