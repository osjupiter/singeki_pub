#pragma once
#include  "DxLib.h"
#include "unit.h"
#include <vector>
#define ACTIVE 4
#define WAIT 5
#define OCCUPY 6
class castle : public unit{
	int stage;
	int tm;
	static int nowstage;
	int product_type;
	int product_clk;

	vector<int> musume_table;
	vector<int> enemy_table;
public:
	castle(int,int,int);
	void main();
	void draw(int);
	void damage(int);
	bool getClock(unsigned int);
	void setState(int);
	void setProduct(int);
	static int getNowstage();
};