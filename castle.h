#pragma once
#include  "DxLib.h"
#include "unit.h"
#include <vector>


typedef pair<int, int> ii;
class castle : public unit{
	int stage;
	int tm;

	int hp;
	int defense;
	int cost;

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
	void main();
	void draw(int);
	void damage(int);
	bool getClock(unsigned int);
	bool isProductTime();
	void setState(int);
	void setProduct(int);
	int getProduct();
	double getProductCLKPAR();
//	static int getNowstage();
//	static void setNowstage(int st);
};