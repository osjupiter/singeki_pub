#include "enemy.h"

class goremu : public enemy{
	bool visible;
public:
	goremu(int, int, int);

	void main(int);
	void draw(int);
	static void init();

	

};
