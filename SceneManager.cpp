#include"SceneManager.h"
SceneManager SceneManager::ins;


	SceneManager::SceneManager(void){}

	SceneManager* SceneManager::getIns(){return &ins;}

	void SceneManager::loop(){
		//clsDx();
		//printfDx(typeid(*nowScene.get()).name ());
		nowScene->main();
		nowScene->render();
	}


	void SceneManager::switchScene(SN_Ptr p){
		SN_Ptr s(new SceneSwitcher(nowScene,p));
		changeScene(s,false);
	}
	void SceneManager::changeScene(SN_Ptr s,boolean doLeave){
		if(nowScene!=nullptr&&doLeave)nowScene->leaveScene();
		nowScene=s;
		s->enterScene();
	}
	void SceneManager::changeScene(SN_Ptr s){
		changeScene(s,true);
	}

