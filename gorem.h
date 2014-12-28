#include "enemy.h"

class goremu : public enemy{
	UnitState pre_state;

public:
	goremu(int, int, int);

	void main(int);
	void draw(int);
	static void init();

	

};
