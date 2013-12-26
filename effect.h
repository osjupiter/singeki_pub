#pragma once
#include  "DxLib.h"
#include "object.h"
#include <memory>
class effect:public object, std::enable_shared_from_this<effect>{
protected:
	int type;
	
	int ani_count;
public:
	effect(int,int);
	virtual void main();
	virtual void draw(int);
	void del();
	~effect();
};