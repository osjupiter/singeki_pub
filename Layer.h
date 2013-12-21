#pragma once
#include<memory>
#include<string>
#include"DxLib.h"
using namespace std;
class SceneNode;
class Game;
class Layer
{
protected:
	SceneNode* parentScene;
public:
	Layer(void){}
	void setParent(SceneNode* s){parentScene=s;}

	virtual void draw(){}
	virtual void main(){}
	virtual void called(){}
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
	string id;
	ClickFlag _clicktype;
public:
	
	ButtonLayer(int tx,int ty,int th,int ttx,int tty,int ttw,int tth);
	ButtonLayer* setId(string s);
	ButtonLayer* setClickType(ClickFlag s);
	void main();
};

class MapLayer:public Layer{
private:
	int xlist[9];
	double ratelist[9];

public:
	MapLayer(std::shared_ptr<Game>);
	void draw();
	void main();

	
};

class SelectLayer:public Layer{
private:
	std::shared_ptr<Game> game;
	int x,y,id;
public:
	SelectLayer(int,int,int);
	void draw();
	void main();
	void setGame(std::shared_ptr<Game>);
	
};