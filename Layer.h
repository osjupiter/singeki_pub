#pragma once
#include<memory>
#include<string>
#include"DxLib.h"
using namespace std;
class SceneNode;
class Game;

/*
	0 Game
	1 right left
	2 Menu
	5 Clear
	9 MapClose
	10 MapLay
	11 Select
	15 Factory
	20 OptionLayer
*/



class Layer
{
protected:
	SceneNode* parentScene;
	int thisLayerID;
public:
	Layer(void){}
	void setParent(SceneNode* s,int id){parentScene=s;thisLayerID=id;}

	virtual void draw(){}
	virtual void main(){}
	virtual void called(){}
	boolean testBox(int,int,int,int);
};


typedef std::shared_ptr<Layer> LAY_Ptr;

class GraphicLayer:public Layer{
protected:
	int x,y;
	int hundle;
public:
	GraphicLayer(int tx,int ty,int th);
	void draw();

};
class ButtonLayer:public GraphicLayer{
public :static enum ClickFlag { ONMOUSE=0,CLICK = 3, PUSH = 1,LEAVE=2};
private:
	int bx,by,bw,bh;
	boolean _oldMouseisin;
	string id;
	ClickFlag _clicktype;
	string _enterSE,_clickSE;
public:
	
	ButtonLayer(int tx,int ty,int th,int ttx,int tty,int ttw,int tth);
	ButtonLayer* setId(string s);
	ButtonLayer* setClickType(ClickFlag s);
	ButtonLayer* setEnterSE(string);
	ButtonLayer* setClickSE(string);
	void main();
};

class MapLayer:public Layer{
private:
	int xlist[9];
	double ratelist[9];
	int lx,ly,lw,lh;

public:
	MapLayer(std::shared_ptr<Game>);
	void draw();
	void main();

	
};

class SelectLayer:public Layer{
private:
	int x,y,id,w,h;
public:
	SelectLayer(int,int,int);
	void draw();
	void main();
	
};

class StageClearLayer:public Layer{
private:
	int stage_id, data;
	int remain_time;
public:
	StageClearLayer(int,int);
	void draw();
	void main();
	
};



class MenuLayer:public Layer{
private:
	int onMouseTime[3];
	shared_ptr<Game> game;
	int xlist[9];
	double ratelist[9];
	int lx,ly,lw,lh;
public:
	MenuLayer(shared_ptr<Game>);
	void draw();
	void main();
	
};

class MapCloseLayer:public Layer{
private:

public:
	MapCloseLayer();
	void draw();
	void main();
};

class FactoryLayer:public Layer{
private:
	int x,y,w,h,lh,lxmar,lw;
	int select,lmartop;
	shared_ptr<Game> game;
public:
	FactoryLayer(shared_ptr<Game>);
	void draw();
	void main();
};

class OptionLayer:public Layer{
private:
	int x,y,w,h,lh;


public:
	OptionLayer();
	void draw();
	void main();
};



