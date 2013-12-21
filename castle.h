#pragma once
#include  "DxLib.h"
#include "unit.h"
#include <vector>
class castle : public unit{
	int stage;
	int tm = 0;
	static int cleared;
	vector<int> musume_table;
	vector<int> enemy_table;
public:
	castle(int,int,int);
	void main();
	void draw(int);
	void damage(int);
	bool getClock(unsigned int);
	void setState(int);
	static int getCleared();
};