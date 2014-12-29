#include "effect.h"
class gajikami : public effect{

	bool turnflag;
public:
	gajikami(int, int, bool);
	void main();
	void draw(int);
};