#include "character.h"
#include "musume.h"
#include "enemy.h"
#include "effect.h"
using namespace std;

class Factory{
private:


public:
	Factory(){};
	static shared_ptr<character> create_chara(int, int, int, UnitType);
	static shared_ptr<effect> create_effect(int fx, int fy, int type, Direction dr, int atk_power, int destx, int desty, int lv);
	static shared_ptr<effect> create_damage_effect(int fx, int fy, int e_type, bool TurnFlag);

	static shared_ptr<musume> create_musume(int, int, int, UnitType);
	static shared_ptr<enemy> create_enemy(int, int, int, UnitType);
};

