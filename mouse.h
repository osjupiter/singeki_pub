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
	boolean LeftPush();	//�����Ă��邩�ǂ���
	boolean LeftClick();	//�������u�Ԃ��ǂ���
	boolean LeftLeave();	//�������u�Ԃ��ǂ���
	boolean RightPush();	//�����Ă��邩�ǂ���
	boolean RightClick();	//�������u�Ԃ��ǂ���
	boolean RightLeave();	//�������u�Ԃ��ǂ���
	boolean isUsed();	//�g���Ă��邩�ǂ���
	boolean isntOver();
};
