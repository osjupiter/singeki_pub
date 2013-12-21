#pragma once
#include  "DxLib.h"
#include "object.h"

class effect:public object{
protected:
	int type;
	int ani_count;
public:
	effect(int,int);
	virtual void main();
	virtual void draw(int);
	void del();
};