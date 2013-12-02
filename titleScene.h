#pragma once
#include<memory>
#include"DxLib.h"
#include"SceneNode.h"
#include"Images.h"
#include"GraphicLayer.h"
class TitleScene : public SceneNode{

public:
	TitleScene(){
		shared_ptr<GraphicLayer> p(new GraphicLayer(0,0,Images::get("pic/test.jpg")));
		addLayer(0,p);
	}
	void main(){

	}

};