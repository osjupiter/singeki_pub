#pragma once
#include "Dxlib.h"
#include "GV.h"

#include "enemy.h"
#include "effect.h"
#include "castle.h"
#include "background.h"
#include "Layer.h"
#include "Images.h"
#include "musume.h"
#include <list>
#include <vector>
#include <memory>
using namespace std;

class Game : public Layer{
	int x; 
	int front_line;
	static Game* ins;
	static const int stage_W[9];

	list<shared_ptr<effect>>  delete_effectlist;
	list<shared_ptr<effect>>  effect_list;
	list<shared_ptr<enemy>>  enemy_list[3];
	list<shared_ptr<enemy>>  delete_enemylist;
	list<shared_ptr<musume>> musume_list[3];
	list<shared_ptr<musume>> delete_musumelist;
	vector<shared_ptr<castle>> castle_list;
	list<shared_ptr<background>> back_list;

	void Test();
public:

	Game();
	int getX();
	void scrollLeft(int);
	void scrollRight(int);
	void birth(int,int); //ï∫émê∂ê¨
	void enemy_birth();
	void effect_create(int,int,int);
	void main();
	void draw();
	bool getClock(unsigned int);
	void delete_object();
	void stageInc();

	/**/
	static Game* getIns();
	void push_del_musume(shared_ptr<musume>);
	void push_del_enemy(shared_ptr<enemy>);
	void push_del_effect(shared_ptr<effect>);

};