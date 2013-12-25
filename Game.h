#pragma once
#include "Dxlib.h"
#include "GV.h"

#include "enemy.h"
#include "effect.h"
#include "castle.h"
#include "background.h"
#include "AttackRange.h"
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
	int resource;
	static Game* ins;
	

	list<shared_ptr<effect>>  delete_effectlist;
	list<shared_ptr<effect>>  effect_list;
	list<shared_ptr<enemy>>  enemy_list[3];
	list<shared_ptr<enemy>>  delete_enemylist;
	list<shared_ptr<musume>> musume_list[3];
	list<shared_ptr<musume>> delete_musumelist;
	vector<shared_ptr<castle>> castle_list;
	list<shared_ptr<background>> back_list;

	list<shared_ptr<AttackRange>> atkrange_musume_list;
	list<shared_ptr<AttackRange>> atkrange_enemy_list;

	shared_ptr<Parameter> param_list[UNIT_M_NUM + 1];

	void Test();
public:
	static const int stage_W[9];
	Game();
	void background_init();
	void param_init();

	int getX();

	void scrollLeft(int);
	void scrollRight(int);
	void birth(int,int); //兵士生成
	void enemy_birth();
	void effect_create(int,int,int,Direction dr=NODIR);
	void main();
	void draw();
	bool getClock(unsigned int);
	void delete_object();
	void stageInc(int);
	void setProduct(int,int); //自動生成セット
	int getProduct(int);
	int getResource();
	int getNowStage();
	void useResource(int);
	void gainResource(int);
	/**/
	static Game* getIns();
	void push_attack_list(shared_ptr<AttackRange>,int unittype);

	void push_del_musume(shared_ptr<musume>);
	void push_del_enemy(shared_ptr<enemy>);
	void push_del_effect(shared_ptr<effect>);

	int getParam(int u_type, ParamType p_type);
	int getParamLevel(int u_type, ParamType p_type);
	int getParamCost(int u_type, ParamType p_type);
	bool incParamLevel(int u_type, ParamType p_type,int lvcost);


};