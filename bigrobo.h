#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class bigrobo : public musume{
private:


	bool atk;
	static int num;
public:
	bigrobo(int fx, int fy, int ln, shared_ptr<Parameter>);
	void main(int);
	void draw(int);
	static void init();
	static int getNum();
	static void setNum(int);
	int getPower();
	int getAtkType();
	void damage(int, int);
};