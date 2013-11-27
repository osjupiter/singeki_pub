#pragma once
#include<memory>
#include"DxLib.h"
class Layer
{

public:
	Layer(void){}

	virtual void draw(){}
	virtual void main(){}
	virtual void called(){}
};


typedef std::shared_ptr<Layer> LAY_Ptr;
