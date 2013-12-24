#pragma once
#include<memory>
#include"DxLib.h"
#include"Layer.h"
#include <map>
#include <iostream>
#include<list>
using namespace std;

class LayerPushPop{
public:
	boolean isPop;
	LAY_Ptr pointer;
	int key;
	LayerPushPop(boolean i,int k,LAY_Ptr m){
		isPop=i;
		pointer=m;
		key=k;
	}
};
class SceneNode
{
	list<shared_ptr<LayerPushPop>> pushPop;
	multimap<int, LAY_Ptr> layers;

public:
	SceneNode(void){}
	
	
	virtual void afterdraw(){}
	virtual void beforedraw(){}
	virtual void draw(){}
	virtual void enterScene(){}
	virtual void leaveScene(){}
	virtual void aftermain(){}
	virtual void beforemain(){}
	virtual void main(){
		beforemain();
		/*for(auto part:layers){
			part.second->main();
		}*/
		auto rit = layers.rbegin();   // 逆イテレータ
		while( rit != layers.rend() )  // 先頭まで
		{
			rit->second->main();
			++rit;  // １つ前方に進む
		}
		aftermain();
	
	}
	virtual void back_main(){}
	virtual void called(){}

	void render(){
		beforedraw();
		draw();
		for(auto part:layers){
			part.second->draw();

		}
		afterdraw();
		listpushpop();
		
	}
	void rmLayer(int i){
		std::shared_ptr<LayerPushPop> p(new LayerPushPop(true,i,nullptr));
		pushPop.push_back(p);
	}
	void addLayer(int i,LAY_Ptr m){
		std::shared_ptr<LayerPushPop> p(new LayerPushPop(false,i,m));
		pushPop.push_back(p);
	}
	void listpushpop(){
		for(auto p:pushPop){
			if(p->isPop){
				layers.erase(p->key);
				//p->pointer->setParent(nullptr);
			}else{
				layers.insert(make_pair(p->key,p->pointer));
				p->pointer->setParent(this,p->key);
			}
			
			
		}
		pushPop.clear();
	}
	virtual void buttonPushed(string){}
};


typedef std::shared_ptr<SceneNode> SN_Ptr;
