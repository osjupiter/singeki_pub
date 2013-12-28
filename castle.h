#pragma once
#include  "DxLib.h"
#include "unit.h"
#include <vector>

typedef pair<int, int> ii;
class castle : public unit{
protected:
	int stage;
	int tm;
	int loop_count;
	int hp;
	int defense;
	int cost;
	static const int castle_hp[9];
	static const int draw_gap[9][3];

	vector<ii> spownlist;
	vector<ii> eventlist;
	int spownID;

	//static int nowstage;
	int product_type;

	int now_clk;

	int exist_clk;
	int exist_ID;

	vector<int> musume_table;
	vector<int> enemy_table;
public:
	castle(int,int,int);
	virtual void main(int);
	virtual void draw(int);
	void damage(int,UnitType op_unit_type);
	bool getClock(unsigned int);
	bool isProductTime();
	void setState(int);
	void setProduct(int);
	int getProduct();
	double getProductCLKPAR();
//	static int getNowstage();
//	static void setNowstage(int st);
};

class shiro_yama :public castle{
	int wait_time;
	bool break_flag;
public:
	shiro_yama(int,int,int);
	void main(int);
	void draw(int);
};