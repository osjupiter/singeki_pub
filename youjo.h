#pragma once

#include "musume.h"
#include "GV.h"

class youjo : public musume{
private:
	bool stopper;
public:
	youjo(int fx, int ln);
	static void init();
	void main(int front);
	void draw(int cx);


};