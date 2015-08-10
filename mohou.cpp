#include "mahou.h"
#include "Images.h"
#include "Game.h"
#include "math.h"

#define ANIM_SPEED 1
#define SPEED 10
#define SPEED_G 25 //水平移動速度

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
	arrive = false; //目的の高さに到着
	end = false; // 消える
}
void mahou::main(){
	effect::main();
	if (!arrive){
		x += SPEED*dir;
		y += (desty - fiy) / ((destx - fix)*2/3.0 / (SPEED*1.0));
	}
	else{
		x += SPEED_G*dir;
	}
	if (y > desty){	
		arrive = true;
	}
	if (arrive) {
		if ((x-destx)%((width-20)/5)==0){
			shared_ptr<AttackRange> p(new AttackRange(x, x + width - 20, power/5, RAND));
			Game::getIns()->push_attack_list(p, MUSUME);
			stopper = true;
			
			ani_count = 0;
		}
		if (x > destx + SPEED_G * 5){ end = true; }
		if (end){
			if (ani_count / 3 >3)
				del();
		}

	}
}

void mahou::draw(int cx){
	switch (dir){
	case Direction::RIGHT:
		
		if (ani_count / ANIM_SPEED < 5){
	//		DrawRotaGraph2(x - cx, y, 0, 0, 1.0, atan2(desty - fiy, destx - fix), Images::getIns()->g_mahou[ani_count / ANIM_SPEED], true);
			DrawGraph(x - cx, y,  Images::getIns()->g_mahou[ani_count / ANIM_SPEED], true);

		}
		else if (!arrive){
			DrawGraph(x - cx, y, Images::getIns()->g_mahou[ani_count / ANIM_SPEED % 2+3], true);

		}else if (end){
			DrawGraph(x - cx, y, Images::getIns()->g_mahou[6 - (ani_count /3 )%4], true);
		}
		else{
			DrawGraph(x - cx, y,  Images::getIns()->g_mahou[ani_count / ANIM_SPEED % 3 + 7], true);
	//		DrawRotaGraph2(x - cx, y, 0, 0, 1.0, atan2(desty - fiy, destx - fix), Images::getIns()->g_mahou[ani_count / ANIM_SPEED % 3 + 7], true);

			//DrawGraph(x - cx, y, Images::getIns()->g_mahou[ani_count / ANIM_SPEED % (ANI_MAHOU-7)+7], true);
		}
	//	DrawLine(destx-cx, 0, destx - cx, 450, GetColor(0, 0, 255), 2);
	//	DrawLine(0, desty, 800, desty, GetColor(0, 0, 255), 2);

		break;
	case Direction::LEFT:
		DrawTurnGraph(x - cx, y, Images::getIns()->g_mahou[ani_count / ANIM_SPEED % ANI_MAHOU], true);
		break;

	default:
		break;
	}
		effect::draw(cx);
}