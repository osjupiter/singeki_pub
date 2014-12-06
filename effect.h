#pragma once
#include  "DxLib.h"
#include "object.h"
#include <memory>
class effect:public std::enable_shared_from_this<effect>,public object{
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

class wisp : public effect{
	int col;
public:
	wisp(int, int);
	void main();
	void draw(int);

};

class drop : public effect{
	int col;
public:
	drop(int, int);
	void main();
	void draw(int);

};