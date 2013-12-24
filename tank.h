#include "enemy.h"

class tank : public enemy{
	
	int power;
	int speed;
	int atk_freq;
	int defense;
	int atk_type;
	int clk;
	int cost;

	static int num;
public:
	tank(int, int, int,int);
	void main(int);
	void draw(int);
	static void init();
	void del();
	static void setNum(int);
	static int getNum();
	int getPower();
	int getAtkType();
	void damage(int, int);
};