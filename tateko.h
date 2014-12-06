#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class tateko : public musume{
private:

	bool stopper;

public:
	tateko(int fx, int ln);
	void main(int);
	void draw(int);
	static void init();

	void damage(int, int);
};