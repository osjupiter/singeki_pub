#include "DxLib.h"
#include "effect.h"
#define ANIM_SPEED_BIGEXP 2
class nomalExp : public effect{
	bool ExFlag;
public:
	nomalExp(int, int,bool Ex=false);
	void main();
	void draw(int);
};