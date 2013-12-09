#include "Dxlib.h"
#include "GV.h"
#include "object.h"
#include "hohei.h"
#include "enemy.h"
#include "castle.h"
#include "background.h"
#include "Layer.h"
#include "Images.h"
#include <list>
#include <memory>
using namespace std;
//To Do �����X�g��O���X�g�쐬

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
	void birth(int,int); //���m����
	
	void main();
	void draw();
	void delete_object();

	

};