#pragma once
#include"DxLib.h"
#include<vector>
#include<list>
#include"SceneNode.h"
#include <memory>
#include<algorithm>
#include"Scene.h"
#include "SceneSwicher.h"



class SceneManager
{
	static SceneManager ins;
	SN_Ptr nowScene;


public:
	SceneManager(void){}

	static SceneManager* getIns(){return &ins;}

	void loop(){
		//clsDx();
		//printfDx(typeid(*nowScene.get()).name ());
		nowScene->main();
		nowScene->render();
	}

	void title(){

	}

	void switchScene(SN_Ptr p){
		SN_Ptr s(new SceneSwitcher(nowScene,p));
		changeScene(s,false);
	}
	void changeScene(SN_Ptr s,boolean doLeave=true){
		if(nowScene!=nullptr&&doLeave)nowScene->leaveScene();
		nowScene=s;
		s->enterScene();
	}




};

