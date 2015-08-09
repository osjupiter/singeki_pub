#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class majo : public musume{
private:
	int maho_count;
public:
	majo(int fx, int ln);
	void main(int);
	void draw(int);
	void decideDirection(int front);
	void damage(int, int);
};