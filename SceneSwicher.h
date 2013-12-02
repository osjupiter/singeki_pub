#pragma once
#include"DxLib.h"
#include"SceneNode.h"
#include"Images.h"

#include"difine.h"
class SceneSwitcher:public SceneNode
{
	int dgree;
	int phase;

	SN_Ptr afterScene;
	SN_Ptr beforeScene;
	SN_Ptr nowScene;
	
public:
	~SceneSwitcher();
	SceneSwitcher(SN_Ptr b,SN_Ptr a);
	void main();
	void draw();



};

