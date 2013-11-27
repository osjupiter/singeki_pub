#include "hohei.h"

hohei::hohei(int fx,int fy){
	x = fx;
	y = fy;
	width = WID_HOHEI;
	height = HEI_HOHEI;
	LoadDivGraph("dat/img/•à•ºw.png",ANI_HOHEI,ANI_HOHEI,1,width,height,graph);
	ani_count = 0;
}

void hohei::main(){
	//x += 2; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
	ani_count++;
}

void hohei::draw(){
	
	DrawGraph(x, y, graph[ani_count/5%ANI_HOHEI], true);
}