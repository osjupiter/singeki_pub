#include "mahou.h"
#include "Images.h"
#include "Game.h"
#include "math.h"

#define ANIM_SPEED 1
#define SPEED 10
#define SPEED_G 25 //…•½ˆÚ“®‘¬“x

mahou::mahou(int fx, int fy, Direction d,int p,int dstx,int dsty) :effect(fx, fy){
	type = MAHOU;
	width = WID_MAHOU;
	height = HEI_MAHOU;
	dir = d;
	destx = dstx;
	desty = dsty;
	fix = fx;
	fiy = fy;
	power = p;
	stopper = false;
	arrive = false; //–Ú“I‚Ì‚‚³‚É“’…
	end = false; // Á‚¦‚é
}
void mahou::main(){
	effect::main();
	if (!arrive){
		x += SPEED*dir;
		y += (desty - fiy) / ((destx - fix)*2/3.0 / (SPEED*1.0));
	}
	else if (end){
		x += SPEED*dir;

	}
	else{
		x += SPEED_G*dir;
	}
	if (y > desty){	
		if (!arrive){
			SoundController::getSE()->playSE("sound/magic-attack-holy1_–‚—UŒ‚‚r‚d.mp3", false);
		}
		arrive = true;

	}
	if (arrive) {
		if ((x-destx)%((width-20)/5)==0){
			shared_ptr<AttackRange> p(new AttackRange(x, x + width - 20, power/5, RAND));
			Game::getIns()->push_attack_list(p, MUSUME);
			
			
		}
		if (x > destx + SPEED_G * 5 && !end){ end = true; ani_count = 0; }
		if (end){
			if (ani_count / 3 >3)
				del();
		}

	}
}

void mahou::draw(int cx){
	switch (dir){
	case Direction::RIGHT:
		
		if (end){
			DrawGraph(x - cx, y, Images::getIns()->g_mahou[6 - (ani_count / 3) % 4], true);
		}
		else if (!arrive){
			DrawGraph(x - cx, y, Images::getIns()->g_mahou[ani_count / ANIM_SPEED % 2+3], true);

		}else if(ani_count / ANIM_SPEED < 5){
			//		DrawRotaGraph2(x - cx, y, 0, 0, 1.0, atan2(desty - fiy, destx - fix), Images::getIns()->g_mahou[ani_count / ANIM_SPEED], true);
			DrawGraph(x - cx, y, Images::getIns()->g_mahou[ani_count / ANIM_SPEED % 10], true);

		}
		else{
			DrawGraph(x - cx, y,  Images::getIns()->g_mahou[ani_count / ANIM_SPEED % 3 + 7], true);
		}
	
		break;
	case Direction::LEFT:
		DrawTurnGraph(x - cx, y, Images::getIns()->g_mahou[ani_count / ANIM_SPEED % ANI_MAHOU], true);
		break;

	default:
		break;
	}
		effect::draw(cx);
}