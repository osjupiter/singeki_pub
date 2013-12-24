#include "hohei.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
int hohei::num=0;
int hohei::maxhp;
int hohei::power;
int hohei::speed;
int hohei::defense;
int hohei::atk_freq;
int hohei::atk_type;
int hohei::clk;
int hohei::cost;

hohei::hohei(int fx, int fy, int ln) : musume(fx,fy,ln){
	
	hp = maxhp;
	width = WID_HOHEI;
	height = HEI_HOHEI;
	num++;
	type = RAND;
		
}

void hohei::init(){
	num = 0;
	maxhp=500;
	power=10;
	speed=4;
	defense=1;
	atk_freq=5;
	atk_type=RAND;
	clk=CLK_HOHEI;
	cost=COST_HOHEI;
}

void hohei::main(int front){
	musume::main(front);
	switch (state){
	case MOV:
		x += 4; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case ATK:
		if (ani_count / ANIM_SPEED%ANI_HOHEI_ATK == 0)
			Images::playSE("sound/gun03.mp3",true);
			
		break;
	case DIE:
		y += vy;
		x += vx;
		vy -= 10;
		vx -= 5;
		if (y+height<0)
			del();
		break;
	}
}

void hohei::draw(int cx){
	
	switch (state){
	case MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei[ani_count / ANIM_SPEED%ANI_HOHEI], true);
		break;
	case ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei_atk[ani_count / ANIM_SPEED%ANI_HOHEI_ATK], true);
		break;
	case DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_hohei_atk[0], true);
		break;
	}

	unit::draw(cx);

}

int hohei::getNum(){
	return num;
}

void hohei::setNum(int i){
	num = i;
}

int hohei::getPower(){
	return power;
}
int hohei::getAtkType(){
	return atk_type;
}
void hohei::damage(int d, int op_a_type){
	
	if (op_a_type == NONE || op_a_type == type){
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = DIE;
		}
	}
	
}