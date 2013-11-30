#include "DxLib.h"
#include <memory>
#include <list>
#include "object.h"

using namespace std;
class stage{
	int x;
	list<shared_ptr<object>> back_list;
public:
	void main();
	void draw();
};

