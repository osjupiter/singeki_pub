#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class hohei : public musume{
private:
	int state;
	
public:
	hohei(int fx,int fy,int ln);
	void main();
	void draw(int);
	
};