#include "AttackRange.h"
#include "difine.h"
#include "DxLib.h"
bool AttackRange::judge(int x, int w, Position u_type){
	if (u_type==ALL || atk_type == u_type || atk_type==Position::ALL){
		if (x < r_edge && l_edge < x + w)
			return true;		
	}
	return false;
}

void AttackRange::draw(int cx){
	if(atk_type==ALL)
		DrawBox(l_edge-cx, 0, r_edge-cx, WINDOW_Y, GetColor(0,255,0),true);
	else if (atk_type == RAND)
		DrawBox(l_edge - cx, WINDOW_Y/2, r_edge - cx, WINDOW_Y, GetColor(0, 255, 0), true); 
	else if (atk_type == SKY)
		DrawBox(l_edge - cx, 0, r_edge - cx, WINDOW_Y/2, GetColor(0, 255, 0), true);

}

int AttackRange::getDamage(){
	return damage;
}

Position AttackRange::getAtkType(){
	return atk_type;
}
