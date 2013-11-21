#pragma once
#include "DxLib.h"


class fps_c
{
	private : 
		int s_f,b_f;
		int fps_count,count0t;	//fpsのカウンタ、60フレームに1回基準となる時刻を記録する変数
		int f[150];	//平均を計算するため60回の1周時間を記録
		double ave;	//平均fps
		int FLAME;

	public:
		fps_c()
		{
			s_f=CreateFontToHandle(NULL,20,9,DX_FONTTYPE_NORMAL) ;
			b_f=CreateFontToHandle(NULL,64,9,DX_FONTTYPE_NORMAL);
			FLAME=60;

		}
		void fps_wait()
		{
			int term,i,gnt;
			static int t=0;
		    if(fps_count==0)
			{//60フレームの1回目なら
				if(t==0)//完全に最初ならまたない
					term=0;
				else//前回記録した時間を元に計算
					term=count0t+1000-GetNowCount();
			}		
			else    //待つべき時間=現在あるべき時刻-現在の時刻
				term = (int)(count0t+fps_count*(1000.0/FLAME))-GetNowCount();
			if(term>0)//待つべき時間だけ待つ
				Sleep(term);
			gnt=GetNowCount();
			 if(fps_count==0)//60フレームに1度基準を作る
			     count0t=gnt;
			f[fps_count]=gnt-t;//１周した時間を記録
			t=gnt;
			//平均計算
			if(fps_count==FLAME-1)
			{
			     ave=0;
				for(i=0;i<FLAME;i++)
					ave+=f[i];
				ave/=FLAME;
			}
			fps_count = (++fps_count)%FLAME ;
		}
		void draw_fps(int x, int y)
		{
			if(ave!=0)
				DrawFormatStringToHandle(x,y,GetColor(255,255,255),s_f,"[%.1f]",1000/ave) ;
			
			return;
		}
		void fps_root()
		{
			fps_wait();
			draw_fps(0,WINDOW_Y-20);
		}
		void fps_change(int num)
		{
			if((num>0)&(num<150))
				FLAME=num;
		}


};

