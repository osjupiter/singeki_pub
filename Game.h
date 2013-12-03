#include "Dxlib.h"
#include "GV.h"
#include "object.h"
#include "hohei.h"
#include "background.h"
#include "Layer.h"
#include "Images.h"
#include <list>
#include <memory>
using namespace std;
//To Do 奥リスト手前リスト作成

class Game : public Layer{
	int x;
	
	list<shared_ptr<object>> musume_list;
	list<shared_ptr<object>> delete_list;
	
	list<shared_ptr<background>> back_list;
	void Test();
public:

	Game();
	int getX();
	void scrollLeft(int);
	void scrollRight(int);
	void birth(int, int, int); //兵士生成
	
	void main();
	void draw();
	void delete_object();

	

};