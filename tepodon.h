#include "DxLib.h"
#include "effect.h"
class tepodon : public effect{
	int power;
	int dest;
public:
	tepodon(int, int,int,int);
	void main();
	void draw(int);
};