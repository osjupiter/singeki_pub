#include "effect.h"
class zangeki : public effect{

	bool turnflag;
public:
	zangeki(int, int, bool);
	void main();
	void draw(int);
};