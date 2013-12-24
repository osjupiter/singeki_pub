#include "AttackRange.h"
#include "difine.h"
bool AttackRange::judge(int x,int w,int u_type){
	if (atk_type == u_type || atk_type==NONE){
		if (x < r_edge && l_edge < x + w)
			return true;		
	}
	return false;
}

int AttackRange::getDamage(){
	return damage;
}

int AttackRange::getAtkType(){
	return atk_type;
}