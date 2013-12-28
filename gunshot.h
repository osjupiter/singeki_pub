#include "effect.h"
class gunshot : public effect{

	bool turnflag;
public:
	gunshot(int, int, bool);
	void main();
	void draw(int);
};