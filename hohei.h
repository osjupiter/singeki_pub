#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class hohei : public musume{
private:
	
	static int num;
public:
	hohei(int fx,int fy,int ln);
	void main(int);
	void draw(int);
	static int getNum();
	static void setNum(int);
};