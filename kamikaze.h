#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class kamikaze : public musume{
private:
	bool atk;
	int gap_y;
	int gap_vy;//縦揺れアニメーション用
	static int num;
public:
	kamikaze(int fx, int fy, int ln);
	void main(int);
	void draw(int);
	static int getNum();
	static void setNum(int);
};