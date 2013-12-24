#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class hohei : public musume{
private:
	static int maxhp;
	static int power;
	static int speed;
	static int atk_freq;
	static int defense;
	static int atk_type;
	static int clk;
	static int cost;

	static int num;
public:
	hohei(int fx,int fy,int ln);
	static void init();
	void main(int);
	void draw(int);
	static int getNum();
	static void setNum(int);
	int getPower();
	int getAtkType();
	void damage(int,int);
};