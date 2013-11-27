#pragma once
#include"DxLib.h"
#include"SceneNode.h"
#include"Images.h"
#include"SceneManager.h"
#include"difine.h"
class SceneSwitcher:public SceneNode
{
	int dgree;
	int phase;
	int* blend;
	int trnum;
	SN_Ptr thisScene;
	SN_Ptr afterScene;
	SN_Ptr beforeScene;
	SN_Ptr nowScene;

	void init(){
	
	}
public:
	~SceneSwitcher(){}
	SceneSwitcher(SN_Ptr m,int transnum,int time){
		
		SN_Ptr p(this);
		int* trans=Images::getIns()->trans;
		afterScene=m;
		beforeScene=Scenes::getIns()->get_back();
		blend=&trans[transnum];
		trnum=transnum;
		phase=0;
		dgree=SWAPTIME;
		nowScene=beforeScene;

		thisScene=p;
		Scenes::getIns()->swapScene(beforeScene,thisScene);

	}
	SceneSwitcher(SN_Ptr m,int transnum,int time,SN_Ptr b){
		SN_Ptr p(this);
		int* trans=Images::getIns()->trans;
		afterScene=m;
		beforeScene=b;
		blend=&trans[transnum];
		trnum=transnum;
		
		thisScene=p;
		Scenes::getIns()->swapScene(beforeScene,thisScene);
		phase=0;
		dgree=SWAPTIME;
		nowScene=beforeScene;

	}
	void back_main(){
		dgree--;
		if(dgree<=0){
			if(phase==0){
				phase=1;
				nowScene=afterScene;
				dgree=SWAPTIME;
				beforeScene->recalled();
				afterScene->called();
			}else{
				Scenes::getIns()->swapScene(thisScene,afterScene);
				thisScene.reset();
				afterScene.reset();
				beforeScene.reset();
				nowScene.reset();

			}
		}

	}
	void trans_draw(){
		int* gs=Images::getIns()->gs;
		if(phase==0){
			DrawBlendGraph(0,0,gs[34],FALSE,*blend,dgree*255/KIETIME,64);
		}
		else if(phase==1){
			DrawBlendGraph(0,0,gs[34],FALSE,*blend,(SWAPTIME-dgree)*255/KIETIME,64);
		}	
	}
	void sur_draw(){
		trans_draw();
		nowScene->sur_draw();
	}
	void draw(){nowScene->draw();}
	void top_draw(){nowScene->top_draw();}
	void bot_draw(){nowScene->bot_draw();}

	static void switchScene(SN_Ptr s,int n,int t){
		new SceneSwitcher(s,n,t);
	}
	static void switchScene(SN_Ptr s,int n){SceneSwitcher::switchScene(s,n,0);}
	static void switchScene(SN_Ptr s){SceneSwitcher::switchScene(s,23,0);}

	static void switchScene(SceneNode* s,int n,int t){
		SN_Ptr p(new SceneWapper(s));
		new SceneSwitcher(p,n,t);
	}
	static void switchScene(SceneNode* s,int n){SceneSwitcher::switchScene(s,n,0);}
	static void switchScene(SceneNode* s){SceneSwitcher::switchScene(s,23,0);}
};

