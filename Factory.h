#include "character.h"
#include "musume.h"
#include "enemy.h"
using namespace std;

class Factory{
private:


public:
	Factory(){};
	static shared_ptr<musume> create_musume(int, int, int, UnitType);
	static shared_ptr<enemy> create_enemy(int, int, int, UnitType);
};

