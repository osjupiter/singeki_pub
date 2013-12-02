#include  "DxLib.h"
#include "object.h"

class background : public object{
	int dx;
	int stage;
	int layer;
	int pic_wid; //‰æ‘œ‰¡ƒTƒCƒY
public:
	background(int x_st,int st,int ly,int w_st){
		x = x_st;
		y = 0;
		stage = st;
		layer = ly;
		width = w_st;
		pic_wid = FIELD_W;
	}
	void main();
	void draw(int);
	void calc(int);
};
