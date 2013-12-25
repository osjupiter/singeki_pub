#include "enemy.h"

class tank : public enemy{
	


	static int num;
public:
	tank(int, int, int,int);
	void main(int);
	void draw(int);
	static void init();
	
	static void setNum(int);
	static int getNum();
	
};