#pragma once
#include"DxLib.h"
class Images
{


	static Images ins;

public:	
	int gs[100];
	int sound[100];
	int trans[50];
	int yaji[4][4];
	int font,alphfont;
	
	
	Images(void){}
	~Images(void){}
	void load();
	static Images* getIns(){return &ins;}
};