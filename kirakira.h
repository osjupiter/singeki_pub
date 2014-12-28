#include "DxLib.h"
#include "effect.h"
class kirakira : public effect{
	Direction dir;
	int power;
	int pre_atk_x;
	int level;
public:
	kirakira(int, int, Direction, int,int,int,int);

	void main();
	void draw(int);
};