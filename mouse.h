#pragma once
#include "DxLib.h"

class mouse_in{
	static mouse_in ins;
	int x,y;
	int l,r;
	boolean over;
	void Reset();
	boolean isUsed();	//使われているかどうか
public:
	static mouse_in* getIns();
	mouse_in();
	void input();

	void recieveOver();
	int Left();
	int Right();
	int X();
	int Y();
	boolean LeftPush();	//押しているかどうか
	boolean LeftClick();	//押した瞬間かどうか
	boolean LeftClick(boolean f);
	boolean LeftLeave();	//離した瞬間かどうか
	boolean RightPush();	//押しているかどうか
	boolean RightClick();	//押した瞬間かどうか
	boolean RightLeave();	//離した瞬間かどうか
	boolean isntOver();
	
	static boolean testBox(int,int,int,int);
};
