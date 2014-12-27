#pragma once
#include "castle.h"
#include "character.h"
#include <memory>

class boss_castle :public castle_enemy{
	shared_ptr<character> boss_unit;
	UnitType u_type;
public:
	boss_castle(int, int, int,int, vector<vector<string>>,UnitType);
	virtual void main(int);
	virtual void draw(int);
	virtual void setState(CastleState);
	virtual void damage(int, UnitType op_unit_type);
};