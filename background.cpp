#include "DxLib.h"
#include "Images.h"
#include "background.h"
#include "GV.h"

void background::main(){

}

void background::calc(int cx){
	if (cx < x)
		dx = x - cx;
	else if (x + width < cx + FIELD_W){
		dx=x + width - (cx + FIELD_W);
	}
	else{
		//”wŒi‚Ì‚¸‚ç‚µ•û—vŒŸ“¢
		dx = (x - cx*((layer % 2) + 1)) % pic_wid;
	
	}
}

void background::draw(int cx){
	calc(cx);

	DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);
	if ((dx = dx + pic_wid) <= cx + FIELD_W)
		DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);

}

