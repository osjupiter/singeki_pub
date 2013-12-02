#include"Images.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){

	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/blend.jpg");
	filelist.push_back("pic/black.jpg");

	
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}
	

}