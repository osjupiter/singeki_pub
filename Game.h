#include "Dxlib.h"
#include "GV.h"
#include "object.h"
#include "hohei.h"
#include "tank.h"
#include "enemy.h"
#include "castle.h"
#include "background.h"
#include "Layer.h"
#include "Images.h"
#include <list>
#include <memory>
using namespace std;

class Game : public Layer{
	int x; 
	int front_line;

	list<shared_ptr<enemy>>  enemy_list[3];
	list<shared_ptr<enemy>>  delete_enemylist;
	list<shared_ptr<musume>> musume_list[3];
	list<shared_ptr<musume>> delete_musumelist;
	list<shared_ptr<castle>> castle_list;
	list<shared_ptr<background>> back_list;
	void Test();
public:

	Game();
	int getX();
	void scrollLeft(int);
	void scrollRight(int);
	void birth(int,int); //ï∫émê∂ê¨
	void enemy_birth();
	void main();
	void draw();
	bool getClock(unsigned int);
	void delete_object();
	

};