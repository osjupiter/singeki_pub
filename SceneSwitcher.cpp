#pragma once
#include"DxLib.h"
#include"SceneSwicher.h"
#include"SceneManager.h"


	SceneSwitcher::~SceneSwitcher(){}
	SceneSwitcher::SceneSwitcher(SN_Ptr b,SN_Ptr a){

		afterScene=a;
		beforeScene=b;
		nowScene=b;

		phase=0;
		dgree=SWAPTIME;


	}
	void SceneSwitcher::main(){
		dgree--;
		if(dgree<=-SWAPWAIT){
			if(phase==0){
				phase=1;
				nowScene=afterScene;
				dgree=SWAPTIME;
			}else{
				SceneManager::getIns()->changeScene(afterScene);
			}
		}

	}
	void SceneSwitcher::draw(){
		int tmp=(phase!=0)?(SWAPTIME-dgree):dgree;
		double p=(tmp/(double)SWAPTIME);
		int tdg=255*p;
		nowScene->render();
		DrawBlendGraph(0,0,Images::get("pic/black.jpg"),FALSE,Images::getIns()->blend,tdg,64);
		
	}