#include "DxLib.h"
#include "effect.h"
#define ANIM_SPEED_BIGEXP 2
class bigExp : public effect{


public:
	bigExp(int, int);
	void main();
	void draw(int);
};