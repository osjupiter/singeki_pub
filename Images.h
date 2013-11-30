#pragma once
#include"DxLib.h"
#include "GV.h"

class Images
{


	static Images ins;

public:	
	int gs[100];
	int sound[100];
	int trans[50];
	int yaji[4][4];
	int font,alphfont;

	int g_hohei[ANI_HOHEI];//•à•º
	int back[4][3];

	Images(void){}
	~Images(void){}
	void load();
	static Images* getIns(){return &ins;}
};