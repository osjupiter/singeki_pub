#include "difine.h"


class Parameter{
	
	int base[PARAM_NUM];
	int level[PARAM_NUM];
//	int cost[PARAM_NUM];
	ParamType canRainForce[3];

public:
	Parameter(){};
	Parameter(int pw, int mh, int sp, int def, Position a_type, int clock, int cos, int a_freq,ParamType,ParamType,ParamType);
	

	void draw(int x,int y);
	int getParam(ParamType p_type);
	int getParamLevel(ParamType p_type);
//	int getCost(ParamType p_type);
	bool LevelUp(ParamType p_type);
	ParamType* getRainForce(){return canRainForce;}

};


