#include "DxLib.h"
#include "effect.h"
class gyorai : public effect{
	Direction dir;
	int power;
	int destx;
	int desty;
	int level;
	Position tarpos;
public:
	gyorai(int, int, Direction, int,int,int,int);

	void main();
	void draw(int);
};