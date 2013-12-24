#include "DxLib.h"
#include "effect.h"
class missile : public effect{
	Direction dir;

public:
	missile(int, int, Direction);
	
	void main();
	void draw(int);
};