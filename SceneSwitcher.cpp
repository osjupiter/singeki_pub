#pragma once
#include"DxLib.h"
#include"SceneSwicher.h"
#include"SceneManager.h"


	SceneSwitcher::~SceneSwitcher(){}
	SceneSwitcher::SceneSwitcher(SN_Ptr b,SN_Ptr a){

		afterScene=a;
		beforeScene=b;
		nowScene=b;

		swapwait=30;
		swaptime=15;

		phase=0;
		dgree=swaptime;


	}
	void SceneSwitcher::main(){
		dgree--;
		if(dgree<=0){
			if(phase==0){
				if(dgree<=-swapwait){
					phase=1;
					nowScene=afterScene;
					beforeScene->leaveScene();
					dgree=swaptime;
				}
			}else{
				SceneManager::getIns()->changeScene(afterScene);
			}
		}

	}
	void SceneSwitcher::draw(){
		int tmp=(phase!=0)?(swaptime-dgree):dgree;
		double p=(tmp/(double)swaptime);
		int tdg=255*p;
		nowScene->render();
		DrawBlendGraph(0,0,Images::get("pic/black.jpg"),FALSE,Images::getIns()->blend,tdg,64);
		
	}
	void SceneSwitcher::setSwapTime(int wait,int time){
		swaptime=time;
		swapwait=wait;
	
	}