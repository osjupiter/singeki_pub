#pragma once
#include "DxLib.h"
#include "GV.h"
class object{
protected:
	int x;
	int y;
	int width;
	int height;
	bool life;
public:
	
	int getX();
	int getY();
	int getW();
	bool getLife();
	virtual bool inCamera(int);
	virtual void main();
	virtual void draw(int);
};