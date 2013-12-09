#include "hohei.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3


hohei::hohei(int fx, int fy, int ln) : musume(fx,fy,ln){
	state = MOV;
	width = WID_HOHEI;
	height = HEI_HOHEI;

}

void hohei::main(){
	unit::main();
	if(state == MOV)x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
	if (x > FIELD_W * 15) life = false;
	if (x > FIELD_W-dist) state = ATK;
}

void hohei::draw(int cx){
	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei[ani_count / ANIM_SPEED%ANI_HOHEI], true);
		break;
	case ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei_atk[ani_count / ANIM_SPEED%ANI_HOHEI_ATK], true);
		break;
	}
}