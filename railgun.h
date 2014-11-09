#include "GV.h"
#include "Game.h"

class railgun : public enemy{
private:
	bool stopper;
	static int num;

public:
	railgun(int, int, int);
	void main(int);
	void draw(int);
	static void init();

	static int getNum();
	static void setNum(int);


};