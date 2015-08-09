#pragma once
#include "enemy.h"
#include "effect.h"

class i_kaminari : public effect{

public:
	i_kaminari(int, int, int);
	void main();
	void draw(int);
	static void init();
	int power;

};
class ikai : public enemy{

public:
	ikai(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};