#include"Images.h"
Images Images::ins;

void Images::load(){
	gs[0]=LoadGraph("pic/test.jpg");
}