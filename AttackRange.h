#pragma once
#include "difine.h"

class AttackRange{
	int l_edge;
	int r_edge;
	int damage;
	Position atk_type;

public:
	AttackRange(int l_e, int r_e, int d, Position a_t){
		l_edge = l_e;
		r_edge = r_e;
		damage = d;
		atk_type = a_t;
	}

	bool judge(int x, int w, Position u_type);
	int getDamage();
	Position getAtkType();
	void draw(int);
};