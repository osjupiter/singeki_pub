#include "Parameter.h"
#include "DxLib.h"
#define MAXLEVEL 8

Parameter::Parameter(int pw, int mh, int sp, int def, Position a_type, int clock, int cos, int a_freq,ParamType p1,ParamType p2,ParamType p3){
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

	canRainForce[0]=p1;
	canRainForce[1]=p2;
	canRainForce[2]=p3;



};

void Parameter::draw(int x, int y){
	DrawFormatString(x,y,GetColor(255,255,255)," pw%d mh%d sp%d def%d a_type%d clk%d cost%d freq%d"
		, getParam(POWER), getParam(MAXHP),getParam(SPEED) ,getParam(DEFENSE) ,getParam(A_TYPE),getParam(CLK),getParam(COST),getParam(A_FREQ));

}

int Parameter::getParamLevel(ParamType p_type){
	return level[p_type];
}

int Parameter::getParam(ParamType p_type){
	int ret=0,_base=base[p_type],_level=level[p_type];
	switch(p_type){
		case ParamType::POWER:
			ret=_base*(1+0.5*_level);
			break;
		case ParamType::MAXHP:
			ret=_base*(1+0.5*_level);
			break;
		case ParamType::SPEED:
			ret=_base*(1+0.5*_level);
			break;
		case ParamType::DEFENSE:
			ret=_base*(1+0.5*_level);
			break;
		case ParamType::A_TYPE:
			ret=_base;
			break;
		case ParamType::CLK:
			ret=_base*(1-0.1*_level);
			break;
		case ParamType::COST:
			ret=_base*(1-0.1*_level);
			break;
		case ParamType::A_FREQ:
			ret=_base*(1-0.1*_level);
			break;
	}
	return ret;
}
/*
int Parameter::getCost(ParamType p_type){
	return cost[p_type];
}*/

/*レベル上限値の場合FALSEを返す*/
bool Parameter::LevelUp(ParamType p_type){
	if (level[p_type] >= MAXLEVEL)
		return false;
	level[p_type] +=1;
	return true;
}

int Parameter::getLevel(ParamType p){
	return level[p];
}


int Parameter::getCostForLevelUp(ParamType p){
	int tmp[][9]={
		{50,100,150,200,250,300,350,400,450},
		{50,100,150,200,250,300,350,400,450},
		{50,100,150,200,250,300,350,400,450},
		{50,100,150,200,250,300,350,400,450},
		{50,100,150,200,250,300,350,400,450},
		{50,100,150,200,250,300,350,400,450},
		{50,100,150,200,250,300,350,400,450},
		{50,100,150,200,250,300,350,400,450}
	};
	return tmp[p][level[p]];
}
