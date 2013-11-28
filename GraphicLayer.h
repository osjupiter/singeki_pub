#pragma once
#include"Layer.h"
#include"Images.h"

class GraphicLayer:public Layer{
	int x,y;
public:
	GraphicLayer(int tx,int ty){
		x=tx;y=ty;
		printfDx("new Graphic");
	}
	void draw(){
		DrawGraph(x,y,Images::get("pic/test.jpg"),TRUE);
		printfDx("Graphic");
	}

};