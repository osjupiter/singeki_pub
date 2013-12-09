#include  "DxLib.h"
#include "object.h"

class background : public object{
	int dx;
	int stage;
	int layer;
	int pic_wid; //‰æ‘œ‰¡ƒTƒCƒY
	double gap;
public:
	background(int x_st, int st, int ly, int w_st);
	void main();
	void draw(int);
	void calc(int);
};
