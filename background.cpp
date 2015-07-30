#include "DxLib.h"
#include "Images.h"
#include "background.h"
#include "GV.h"

const int scroll_type[8][5] = {
/*	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,2,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}*/
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 }
};
double remain(double a,int b){
	int c=a/b;
	return a - c*b;
}

background::background(int x_st, int st, int ly, int w_st,bool mv):object(x_st,0){

		stage = st;
		layer = ly;
		width = w_st;
		height = WINDOW_Y;
		pic_wid = 650;
		move = Images::getIns()->back_ismove[stage][layer];//(scroll_type[stage][layer] == 1);
		dx=0;
		if (move){
			gap = 0;
			dx = x;
		}
		else
			gap = ((layer + 1) / 5.0 / (5 - layer) / (5 - layer));
}

void background::main(int cx){
	if (move){
//		gap = gap + 1;
		
//		dx =  - remain((int)gap,pic_wid) ;
	
	}
	else{

	}
	

}

void background::scroll(int cx){
	if (move) return;
	if (cx < x){
		dx = (x - cx);
		//	dx = remain(x - cx*(layer + 1) / 3, pic_wid);
		/*else if (x + width < cx + FIELD_W){
		dx=x + width - (cx + FIELD_W);
		}*/
	}
	else{
		//îwåiÇÃÇ∏ÇÁÇµï˚óvåüì¢
		dx = ((int)(remain((x - cx)*gap, pic_wid)));
	}
}

void background::draw(int cx){
	
	if (move){
		gap = gap + layer+1;
		dx =  - remain((int)gap,pic_wid) ;
		if (cx < x){
			DrawRectGraph(x - cx, y, x - cx - (dx), y, pic_wid - (x - cx - (dx)), height, Images::getIns()->back[stage][layer], true, false);
		}
		else{
			DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);
		}
	/*	clsDx();
		if (stage == 1 && layer == 2){
			printfDx("gap%lf x%d dx%d dx+pic%d", gap, x, dx, dx+pic_wid);
			DrawLine(x - cx, 0, x - cx, WINDOW_Y, GetColor(255, 255, 0), 4);
			DrawLine(dx, 0, dx, WINDOW_Y, GetColor(0, 255, 0), 4);
			DrawLine(dx + pic_wid, 0, dx + pic_wid, WINDOW_Y, GetColor(0, 0, 255), 4);
			DrawLine(dx + pic_wid + pic_wid+1, 0, dx + pic_wid + pic_wid+1, WINDOW_Y, GetColor(255, 0, 0), 4);

		}*/
		//äGÉãÅ[Év
		if (scroll_type[stage][layer] != 2){
			int tmpdx=dx;
			while (tmpdx <= FIELD_W){
				
				if ((tmpdx = tmpdx + pic_wid) <= FIELD_W){
					if (tmpdx < x - cx)
						DrawRectGraph(x - cx, y, x - cx - (tmpdx), y, pic_wid - (x - cx - (tmpdx)), height, Images::getIns()->back[stage][layer], true, false);
					else DrawGraph(tmpdx, y, Images::getIns()->back[stage][layer], true);
				}
			}
		}
	}else{
		DrawGraph(dx, y, Images::getIns()->back[stage][layer], true);
		int tmpdx=dx;
		if (scroll_type[stage][layer] != 2){
			while (tmpdx <= cx + FIELD_W){
				if ((tmpdx = tmpdx + pic_wid) <= cx + FIELD_W)
					DrawGraph(tmpdx, y, Images::getIns()->back[stage][layer], true);
			}
		}
	}
	
	

}

