#include "Parameter.h"
#include "DxLib.h"
#define MAXLEVEL 5

Parameter::Parameter(int pw, int mh, int sp, int def, Position a_type, int clock, int cos, int a_freq){
	base[POWER] = pw;
	base[MAXHP] = mh;
	base[SPEED] = sp;
	base[DEFENSE] = def;
	base[A_TYPE] = a_type;
	base[CLK] = clock;
	base[COST] = cos;
	base[A_FREQ] = a_freq;

	level[POWER] = 0;
	level[MAXHP] = 0;
	level[SPEED] = 0;
	level[DEFENSE] = 0;
	level[A_TYPE] = 0;
	level[CLK] = 0;
	level[COST] = 0;
	level[A_FREQ] = 0;

};

void Parameter::draw(int x, int y){
	DrawFormatString(x,y,GetColor(255,255,255)," pw%d mh%d sp%d def%d a_type%d clk%d cost%d freq%d"
		, base[POWER], base[MAXHP],base[SPEED] ,base[DEFENSE] ,base[A_TYPE],base[CLK],base[COST],base[A_FREQ]);

}

int Parameter::getParamLevel(ParamType p_type){
	return level[p_type];
}

int Parameter::getParam(ParamType p_type){
	return base[p_type]*(1+0.5*level[p_type]);
}
/*
int Parameter::getCost(ParamType p_type){
	return cost[p_type];
}*/

/*ƒŒƒxƒ‹ãŒÀ’l‚Ìê‡FALSE‚ð•Ô‚·*/
bool Parameter::LevelUp(ParamType p_type){
	if (level[p_type] >= MAXLEVEL)
		return false;
	level[p_type] +=1;
	return true;
}

