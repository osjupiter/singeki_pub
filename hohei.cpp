#include "hohei.h"
#include "Images.h"
#define ANIM_SPEED 2

hohei::hohei(int fx,int fy){
	x = fx;
	y = fy;
	width = WID_HOHEI;
	height = HEI_HOHEI;
	life = true;
	ani_count = 0;
}

void hohei::main(){
	x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
	if (x > FIELD_W*12)life = false;
	ani_count++;
}

void hohei::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_hohei[ani_count / ANIM_SPEED%ANI_HOHEI], true);

}