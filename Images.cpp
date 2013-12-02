#include"Images.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){

	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/black.jpg");
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/game.png");
	
	
	
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}
	
	blend=LoadBlendGraph("pic/blend.jpg");
	
}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}
	int Images::get(char name[]){return ins.gs[string(name)];}