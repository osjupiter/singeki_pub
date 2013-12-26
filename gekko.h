#include "enemy.h"

class gekko : public enemy{

	static int num;
public:
	gekko(int, int, int, int);
	
	void main(int);
	void draw(int);
	static void init();

	static void setNum(int);
	static int getNum();

};
