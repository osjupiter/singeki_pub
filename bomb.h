#include "DxLib.h"
#include "effect.h"
class bomb : public effect{
	int power;

public:
	bomb(int, int,int);
	void main();
	void draw(int);
};