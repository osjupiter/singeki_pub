#include "AttackRange.h"
#include "difine.h"
#include "DxLib.h"
bool AttackRange::judge(int x,int w,int u_type){
	if (atk_type == u_type || atk_type==NONE){
		if (x < r_edge && l_edge < x + w)
			return true;		
	}
	return false;
}

void AttackRange::draw(int cx){
	DrawBox(l_edge-cx, 0, r_edge-cx, WINDOW_Y, GetColor(0,255,0),true);
}

int AttackRange::getDamage(){
	return damage;
}

int AttackRange::getAtkType(){
	return atk_type;
}
