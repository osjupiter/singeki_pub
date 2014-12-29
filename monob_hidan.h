#include "effect.h"
class monob_hidan : public effect{

	bool turnflag;

public:
	monob_hidan(int, int, bool);
	void main();
	void draw(int);
};