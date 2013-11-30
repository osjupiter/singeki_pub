#pragma once
#include"Layer.h"
#include"Images.h"

class GraphicLayer:public Layer{
	int x,y;
	int hundle;
public:
	GraphicLayer(int tx,int ty,int th){
		x=tx;y=ty;
		hundle=th;
	}
	void draw(){
		DrawGraph(x,y,hundle,TRUE);
		
		DrawGraph(x,y,Images::get("pic/test.jpg"),TRUE);

	}

};