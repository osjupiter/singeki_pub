#include "effect.h"
class cannonshot : public effect{

	bool turnflag;

public:
	cannonshot(int, int,bool);
	void main();
	void draw(int);
};