#pragma once
#include "difine.h"


class Parameter{
	
	int base[PARAM_NUM];
	int level[PARAM_NUM];
//	int cost[PARAM_NUM];
	ParamType canRainForce[3];
	double mag[PARAM_NUM];

public:
	Parameter(){};
	Parameter(int pw, int mh, int sp, int def, Position a_type, int clock, int cos, int a_freq,ParamType,ParamType,ParamType);
	Parameter(int pw, int mh, int sp, int def, Position a_type, int clock, int cos, int a_freq,double mag[6]);

	void draw(int x,int y);
	int getParam(ParamType p_type);
	int getParamMag(ParamType p_type,int lv);
	int getParamLevel(ParamType p_type);
//	int getCost(ParamType p_type);
	bool LevelUp(ParamType p_type);
	ParamType* getRainForce(){return canRainForce;}
	int getLevel(ParamType p);
	int getCostForLevelUp(ParamType p);
};


