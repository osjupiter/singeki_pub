#include  "DxLib.h"
#include "object.h"

class castle : public object{
	int stage;
	
public:
	castle(int,int,int);
	void draw(int);
};