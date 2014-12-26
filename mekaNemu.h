#pragma	once
#include "castle.h"

class mekaNemu :public castle_enemy{
	int wait_time;
	bool atk_flag;
public:
	mekaNemu(int, int, int, vector<vector<string>>);
	void main(int);
	void draw(int);
};