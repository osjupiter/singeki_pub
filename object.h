#pragma once
#include "DxLib.h"
#include "GV.h"
class object{
protected:
	int x;
	int y;
	int width;
	int height;
	const int* image;
public:
	object(int fx,int fy){
		x = fx;
		y = fy;
		
	}
	int getX();
	int getY();
	int getW();
	~object();
	
	virtual bool inCamera(int);
	/*virtual void main();
	virtual void draw(int);*/
};