#pragma once
#include "Dxlib.h"
#include "GV.h"
#include "unit.h"
#define MOV 0
#define ATK 1
#define DIE 2

class musume :public unit{
protected:

public:
	musume(int,int,int);
	virtual void main();
	
};