#pragma once
#include  "DxLib.h"
#include "unit.h"
#include <vector>
#include "SoundController.h"

typedef pair<int, int> ii;
class castle : public unit{
protected:
	int world;
	int stage;
	int tm;
	int loop_count;
	int hp;
	int defense;
	int cost;
	static const int castle_hp[9];
	//static const int draw_gap[9][3];
	CastleState state;


	//static int nowstage;
	int product_type;


	int exist_clk;
	int exist_ID;

	vector<int> musume_table;
	vector<int> enemy_table;
public:
	castle(int,int,int,int);
	virtual void main(int);
	virtual void draw(int);
	virtual void damage(int,UnitType op_unit_type);
	bool getClock(unsigned int);
	bool isProductTime();
	virtual void setState(CastleState);
	void setProduct(int);
	int getProduct();
	CastleState getState();
	virtual double getProductCLKPAR();
//	static int getNowstage();
//	static void setNowstage(int st);
};



class castle_musume : public castle{
private:

	int now_clk;
public:
	castle_musume(int, int, int,int);
	virtual void main(int);
	virtual void draw(int);
	virtual double getProductCLKPAR() override;
	bool isProductTime();
};
class castle_enemy : public castle{
protected:
	vector<ii> spownlist[5];
	vector<ii> eventlist;
	int spownIndex[5];
	int spown_clk[5];

public:
	castle_enemy(int, int, int, int,vector<vector<string>>);
	
	virtual void main(int);
	void draw(int);
	
//	virtual void damage(int, UnitType op_unit_type);
};
class castle_enemy_indepth : public castle_enemy{
protected:

	
public:
	castle_enemy_indepth(int, int, int, int, vector<vector<string>>);
	void main(int);

};




class shiro_yama :public castle_enemy{
	int wait_time;
	bool break_flag;
public:
	shiro_yama(int, int, int, int,vector<vector<string>>);
	void main(int);
	void draw(int);
};