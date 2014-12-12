#include "DxLib.h"
#include "effect.h"
class hana : public effect{

	bool stopper;
public:
	hana(int, int);
	void main();
	void draw(int);
};