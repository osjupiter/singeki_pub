#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class balloon : public musume{
private:
	bool test;
	static int num;
public:
	balloon(int fx, int fy, int ln);
	void main(int);
	void draw(int);
	static int getNum();
	static void setNum(int);
};