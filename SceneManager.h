#pragma once
#include"DxLib.h"
#include<vector>
#include<list>
#include"SceneNode.h"
#include <memory>
#include<algorithm>
#include "SceneSwicher.h"



class SceneManager
{
	static SceneManager ins;
	SN_Ptr nowScene;


public:
	SceneManager(void);

	static SceneManager* getIns();

	void loop();


	void switchScene(SN_Ptr p);
	void changeScene(SN_Ptr s,boolean doLeave);
	void changeScene(SN_Ptr s);



};

