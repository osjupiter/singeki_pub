#pragma once
#include"Layer.h"
#include"Images.h"

class GraphicLayer:public Layer{
	int x,y;
	int gnum;
public:
	GraphicLayer(){
	
	}
	virtual void draw(){
		DrawGraph(x,y,Images::getIns()->gs[0],TRUE);
	}

};