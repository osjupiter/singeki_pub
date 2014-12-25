#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class nouka : public musume{
private:


public:
	nouka(int fx, int ln);
	static void init();
	void main(int);
	void draw(int);
	static int getNum();
	static void setNum(int);

	void damage(int, int);
};