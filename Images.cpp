#include"Images.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){

	filelist.push_back("pic/test.jpg");


	
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}
	

}