#pragma once
#include "DxLib.h"


class fps_c
{
	private : 
		int s_f,b_f;
		int fps_count,count0t;	//fps�̃J�E���^�A60�t���[����1���ƂȂ鎞�����L�^����ϐ�
		int f[150];	//���ς��v�Z���邽��60���1�����Ԃ��L�^
		double ave;	//����fps
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
			{//60�t���[����1��ڂȂ�
				if(t==0)//���S�ɍŏ��Ȃ�܂��Ȃ�
					term=0;
				else//�O��L�^�������Ԃ����Ɍv�Z
					term=count0t+1000-GetNowCount();
			}		
			else    //�҂ׂ�����=���݂���ׂ�����-���݂̎���
				term = (int)(count0t+fps_count*(1000.0/FLAME))-GetNowCount();
			if(term>0)//�҂ׂ����Ԃ����҂�
				Sleep(term);
			gnt=GetNowCount();
			 if(fps_count==0)//60�t���[����1�x������
			     count0t=gnt;
			f[fps_count]=gnt-t;//�P���������Ԃ��L�^
			t=gnt;
			//���όv�Z
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

