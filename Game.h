#pragma once
#include "Dxlib.h"
#include "GV.h"
#include "character.h"
#include "enemy.h"
#include "effect.h"
#include "castle.h"
#include "background.h"
#include "AttackRange.h"
#include "Layer.h"
#include "Images.h"
#include "musume.h"
#include "SoundController.h"

#include <list>
#include <vector>
#include <memory>
using namespace std;

class Game : public Layer{
	int x; 
	int world;
	int front_line;
	int resource;
	static Game* ins;
	int nowstage;

	int birth_limit;

	list<shared_ptr<effect>>  delete_effectlist;
	list<shared_ptr<effect>>  effect_list;
	list<shared_ptr<character>>  enemy_list[3];
	list<shared_ptr<character>>  delete_enemylist;
	list<shared_ptr<character>> musume_list[3];
	list<shared_ptr<character>> delete_musumelist;
	
	vector<shared_ptr<object>> memfree_list;

	vector<int> musume_nuber_list;
	
	

	vector<shared_ptr<castle>> castle_list;
	bool stage_clear;
	list<shared_ptr<background>> back_list;

	list<shared_ptr<AttackRange>> atkrange_musume_list;
	list<shared_ptr<AttackRange>> atkrange_enemy_list;

	shared_ptr<Parameter> param_list[UNIT_M_NUM + 1];

	void Test();
	int cameraTargetSpeed;
	int cameraMoveCount;

	bool pauseFlag;
public:
	static const int stage_W[9];
	Game(int _world=0);
	void background_init();
	void param_init();
	void castle_init();
	int getX();

	void scrollLeft(int);
	void scrollRight(int);
	void setCamera(int);

	void birth(int,int); //兵士生成
	void enemy_birth();
	void effect_create(int,int,int,Direction dr=NODIR,int atk_power=0,int dest=0);
	void damage_effect_create(int, int, int, bool TurnFlag=false);
	void main();
	void draw();
	bool getClock(unsigned int);
	void delete_object();
	void stageInc(); 
	void stageClear();//ステージクリア
	void setProduct(int,int); //自動生成セット
	int getProduct(int);
	double getProductCLKPAR(int);
	int getNowStage();
	/*ポーズ*/
	void turnPauseFlag();
	bool getPauseFlag();
	/*資源*/
	void useResource(int);
	void gainResource(int);
	int getResource();

	bool isClear();
	bool isGameover();

	/**/
	static Game* getIns();
	void push_castle_list(int stage);
	void push_attack_list(shared_ptr<AttackRange>,int unittype);

	
	void push_del_musume(shared_ptr<musume>);
	void push_del_enemy(shared_ptr<enemy>);
	void push_del_effect(shared_ptr<effect>);

	int getParam(int u_type, ParamType p_type);
	int getParamLevel(int u_type, ParamType p_type);
	int getParamCost(int u_type, ParamType p_type);
	bool incParamLevel(int u_type, ParamType p_type,int lvcost);

	pair<list<shared_ptr<character>>*,list<shared_ptr<character>>*> getDarkness();

	vector<int> getMusumeNumber();

	
	void setBirthLimit(int i);
	int getBirthLimit();
	int getMusumeSum();
	
	ParamType* Game::getRainForce(int);
	shared_ptr<Parameter> getParam(int id);
	string getParamSummary(ParamType);
	string getParamName(ParamType p);
	string getUnitName(UnitType p);
	string getUnitSummary(UnitType p);
};