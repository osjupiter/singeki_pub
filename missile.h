#include "DxLib.h"
#include "effect.h"
class missile : public effect{
	Direction dir;
	int power;
public:
	missile(int, int, Direction,int);
	
	void main();
	void draw(int);
};