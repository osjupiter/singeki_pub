#include "castle.h"
#include "Images.h"
castle::castle(int fx,int fy,int st):object(fx,fy){
	
	width = 273;
	x = fx-width/2;
	height = 450;
	stage = st;
}

void castle::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->castle[0], true);
}