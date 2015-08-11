#pragma once
#include "enemy.h"
#include "effect.h"
class glight : public effect{

public:
	glight(int, int,int);
	void main();
	void draw(int);
	static void init();
	int power;

};

class gbeam : public effect{

public:
	gbeam(int, int);
	void main();
	void draw(int);
	static void init();

};

class guuzou : public enemy{

public:
	guuzou(int, int, int);
	void main(int);
	void draw(int);
	static void init();


};