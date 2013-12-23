#include "DxLib.h"
#include "Images.h"
#include "background.h"
#include "GV.h"

double remain(double a,int b){
	int c=a/b;
	return a - c*b;
}

background::background(int x_st, int st, int ly, int w_st):object(x_st,0){

		stage = st;
		layer = ly;
		width = w_st;
		pic_wid = 650;
		gap = ((layer + 1) / 3.0 / (3 - layer) / (3 - layer));
	
}

void background::main(){}

void background::calc(int cx){
	if (cx < x)
		dx = x - cx;
	//	dx = remain(x - cx*(layer + 1) / 3, pic_wid);
	/*else if (x + width < cx + FIELD_W){
		dx=x + width - (cx + FIELD_W);
	}*/
	else{
		//”wŒi‚Ì‚¸‚ç‚µ•û—vŒŸ“¢
		dx = ((int)(remain(x*gap  - cx*gap, pic_wid)));
	}
}

void background::draw(int cx){
	calc(cx);

	DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);
	while (dx <= cx + FIELD_W){
		if ((dx = dx + pic_wid) <= cx + FIELD_W)
			DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);
	}
/*	if (cx < x){
		remain(x - cx*(layer+1)/3, pic_wid);
		DrawRectGraph(x - cx, y, x - cx- dx, 0, pic_wid - (x - cx - dx), FIELD_H, Images::getIns()->back[stage][layer], true, false);
		if ((dx = dx + pic_wid) <= cx + FIELD_W)
			DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);

	}
	else if (x + width < cx + FIELD_W){
		remain(x - cx*(layer+1)/3, pic_wid);
		DrawRectGraph(x - cx, y, x - cx - dx, 0, pic_wid - (x - cx - dx), FIELD_H, Images::getIns()->back[stage][layer], true, false);

	}
	else{
		//”wŒi‚Ì‚¸‚ç‚µ•û—vŒŸ“¢
		remain(x - cx*(layer+1)/3, pic_wid);
		DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);
		if ((dx = dx + pic_wid) <= cx + FIELD_W)
			DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);

	}*/
}

