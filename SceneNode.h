#pragma once
#include<memory>
#include"DxLib.h"
#include"Layer.h"
#include <map>

class LayerPushPop{
public:
	boolean isPop;
	LAY_Ptr pointer;
	int key;
	LayerPushPop(boolean i,int key,LAY_Ptr m){
		isPop=i;
		pointer=m;
	}
};
class SceneNode
{
	std::list<std::shared_ptr<LayerPushPop>> pushPop;
	std::multimap<int, std::shared_ptr<LAY_Ptr>> layers;

public:
	SceneNode(void){}
	
	
	virtual void afterdraw(){}
	virtual void beforedraw(){}
	virtual void draw(){
		beforedraw();
		for(auto part:layers){
			part.second->get()->draw();
		}
		afterdraw();
	}
	virtual void aftermain(){}
	virtual void beforemain(){}
	virtual void main(){
		beforemain();
		for(auto part:layers){
			part.second->get()->main();
		}
		aftermain();
	
	}
	virtual void back_main(){}
	virtual void called(){}

	void rmLayer(int i){
		std::shared_ptr<LayerPushPop> p(new LayerPushPop(true,i,nullptr));
		pushPop.push_back(p);
	}
	void addLayer(int i,LAY_Ptr m){
		std::shared_ptr<LayerPushPop> p(new LayerPushPop(false,i,m));
		pushPop.push_back(p);
	}
};


typedef std::shared_ptr<SceneNode> SN_Ptr;
