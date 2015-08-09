#include "DxLib.h"
#include "effect.h"
class mahou : public effect{
	int power;
	int destx;
	int desty;
	Direction dir;
	int fiy;
	int fix;
	bool stopper;
public:
	mahou(int fx, int fy, Direction d, int p, int dstx, int dsty);
	void main();
	void draw(int);
};