#pragma	once
#include "castle.h"

class mekaNemu :public castle{
	int wait_time;
	bool atk_flag;
public:
	mekaNemu(int, int, int);
	void main(int);
	void draw(int);
};