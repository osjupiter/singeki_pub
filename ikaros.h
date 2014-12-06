#pragma once
#include "DxLib.h"
#include "musume.h"
#include "GV.h"

class ikaros : public musume{
private:

public:
	ikaros(int fx, int ln);
	void main(int);
	void draw(int);

	void damage(int, int);
};