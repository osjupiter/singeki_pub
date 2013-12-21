#pragma once
#include<memory>
#include<string>
#include"DxLib.h"
using namespace std;
class SceneNode;
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
public :static enum ClickFlag { CLICK = 3, PUSH = 1,LEAVE=2};
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