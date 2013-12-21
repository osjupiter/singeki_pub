#pragma once
#include "Dxlib.h"
#include "GV.h"
#include "unit.h"


class musume :public unit{
protected:

public:
	musume(int,int,int);
	virtual void main(int);
	virtual void draw(int);
	void damage(int,int);
	void del();
};