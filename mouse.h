#pragma once
#include "DxLib.h"

class mouse_in{
	static mouse_in ins;
	int x,y;
	int l,r;
public:
	static mouse_in* getIns();
	mouse_in();
	void input();
	void Reset();
	int Left();
	int Right();
	int X();
	int Y();
	
};
