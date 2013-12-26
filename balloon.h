#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class balloon : public musume{
private:

	bool stopper;
	bool atk;
	static int num;
public:
	balloon(int fx, int fy, int ln, shared_ptr<Parameter>);
	void main(int);
	void draw(int);
	static void init();
	static int getNum();
	static void setNum(int);

	void damage(int, int);
};