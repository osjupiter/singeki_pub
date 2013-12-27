#include "DxLib.h"
#include "effect.h"
#define ANIM_SPEED_BIGEXP 2
class nomalExp : public effect{

public:
	nomalExp(int, int);
	void main();
	void draw(int);
};