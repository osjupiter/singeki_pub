#include "DxLib.h"
#include "object.h"
#include "GV.h"

class hohei : public object{
private:
	
	int ani_count;
public:
	hohei(int,int);
	void main();
	void draw(int);

};