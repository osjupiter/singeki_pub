#pragma once
#include "DxLib.h"

class mouse_in{
	static mouse_in ins;
	int x,y;
	int l,r;
	boolean over;
	void Reset();
	boolean isUsed();	//�g���Ă��邩�ǂ���
public:
	static mouse_in* getIns();
	mouse_in();
	void input();

	void recieveOver();
	int Left();
	int Right();
	int X();
	int Y();
	boolean LeftPush();	//�����Ă��邩�ǂ���
	boolean LeftClick();	//�������u�Ԃ��ǂ���
	boolean LeftClick(boolean f);
	boolean LeftLeave();	//�������u�Ԃ��ǂ���
	boolean RightPush();	//�����Ă��邩�ǂ���
	boolean RightClick();	//�������u�Ԃ��ǂ���
	boolean RightLeave();	//�������u�Ԃ��ǂ���
	boolean isntOver();
	
	static boolean testBox(int,int,int,int);
};
