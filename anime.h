#include "Dxlib.h"
#include "GV.h"
#include "object.h"
#include "hohei.h"
#include <list>
#include <memory>
using namespace std;
class anime{
	int x;
	int y;
	int width;
	int height;
	list<shared_ptr<object>> musume;
	
	
public:
	int getX();
	int getY();
	void birth(int, int, int);
	void main();
	void draw();

};