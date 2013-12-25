#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class hohei : public musume{
private:


	static int num;
public:
	hohei(int fx, int fy, int ln, shared_ptr<Parameter>);
	static void init();
	void main(int);
	void draw(int);
	static int getNum();
	static void setNum(int);
	int getPower();
	int getAtkType();
	void damage(int,int);
};