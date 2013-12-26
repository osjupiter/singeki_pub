#include "DxLib.h"
#include "effect.h"
class beam : public effect{
	int power;

public:
	beam(int, int, int);
	void main();
	void draw(int);
};