#include "DxLib.h"
#include "effect.h"
class negimissile : public effect{
	Direction dir;
	int power;
	int destx;
	int desty;
	int g_type;
	Position tarpos;
public:
	negimissile(int, int, Direction, int, int, int, int);

	void main();
	void draw(int);
};