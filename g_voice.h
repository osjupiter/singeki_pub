#include "DxLib.h"
#include "effect.h"
class gvoice : public effect{
	Direction dir;
	int power;
	int pre_atk_x;
public:
    gvoice(int, int, Direction, int);

	void main();
	void draw(int);
};