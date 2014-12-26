#include "DxLib.h"
#include "effect.h"
class hana : public effect{
	UnitType spown;
	bool stopper;
	int dest_y;
	bool fly;
public:
	hana(int, int);
	void main();
	void draw(int);
};