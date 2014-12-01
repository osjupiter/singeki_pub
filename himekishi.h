#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class himekishi : public musume{
private:

	bool stopper;

public:
	himekishi(int fx, int ln);
	void main(int);
	void draw(int);
	static void init();

	void damage(int, int);
};