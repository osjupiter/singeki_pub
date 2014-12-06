#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class majo : public musume{
private:

public:
	majo(int fx, int ln);
	void main(int);
	void draw(int);

	void damage(int, int);
};