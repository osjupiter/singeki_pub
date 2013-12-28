#pragma once
#include "DxLib.h"

class mouse_in{
	static mouse_in ins;
	int x,y;
	int l,r;
	boolean over;
public:
	static mouse_in* getIns();
	mouse_in();
	void input();
	void Reset();
	void recieveOver();
	int Left();
	int Right();
	int X();
	int Y();
	boolean LeftPush();	//‰Ÿ‚µ‚Ä‚¢‚é‚©‚Ç‚¤‚©
	boolean LeftClick();	//‰Ÿ‚µ‚½uŠÔ‚©‚Ç‚¤‚©
	boolean LeftLeave();	//—£‚µ‚½uŠÔ‚©‚Ç‚¤‚©
	boolean RightPush();	//‰Ÿ‚µ‚Ä‚¢‚é‚©‚Ç‚¤‚©
	boolean RightClick();	//‰Ÿ‚µ‚½uŠÔ‚©‚Ç‚¤‚©
	boolean RightLeave();	//—£‚µ‚½uŠÔ‚©‚Ç‚¤‚©
	boolean isUsed();	//g‚í‚ê‚Ä‚¢‚é‚©‚Ç‚¤‚©
	boolean isntOver();
};
