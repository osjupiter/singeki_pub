#include "DxLib.h"
#include "Images.h"
#include "background.h"
#include "GV.h"

double remain(double a,int b){
	int c=a/b;
	return a - c*b;
}

void background::main(){

}

void background::calc(int cx){
	if (cx < x)
		dx = x - cx;
	//	dx = remain(x - cx*(layer + 1) / 3, pic_wid);
	/*else if (x + width < cx + FIELD_W){
		dx=x + width - (cx + FIELD_W);
	}*/
	else{
		//”wŒi‚Ì‚¸‚ç‚µ•û—vŒŸ“¢
	dx = remain(x/3 - cx*(layer+1)/3, pic_wid);
	}
}

void background::draw(int cx){
	calc(cx);

	DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);
	if ((dx = dx + pic_wid) <= cx + FIELD_W)
	DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);
	
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

