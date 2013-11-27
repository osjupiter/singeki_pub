#pragma once
#include "DxLib.h"

class object{
protected:
	int x;
	int y;
	int width;
	int height;
public:
	
	int getX();
	int getY();
	virtual void main();
	virtual void draw();
};