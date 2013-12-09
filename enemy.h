#pragma once
#include  "DxLib.h"
#include "unit.h"

class enemy : public unit{


public:
	virtual void main();
	virtual void draw(int);
};