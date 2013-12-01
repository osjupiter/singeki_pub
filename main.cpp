#pragma warning(disable:4244)
#include "GV.h"
#include"fps.h"
#include"mouse.h"

#include "Game.h"

#include"SceneManager.h"
#include"Images.h"

//�֐��̎���-----------------------------------------------------




int lcheck(){
	ScreenFlip();
	if( ProcessMessage() < 0 ) return 1 ;
	//if( CheckHitKey( KEY_INPUT_ESCAPE ) ) return 1 ;
	return 0;
}
fps_c fps;

// WinMain�֐�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
			 LPSTR lpCmdLine, int nCmdShow )
{
//SetWindowIconID( IDI_ICON2 ) ;	
	// ��ʃ��[�h�̐ݒ�

	SetGraphMode( WINDOW_X, WINDOW_Y , 16 ) ;
	ChangeWindowMode( FALSE ) ;
	SetMouseDispFlag( FALSE );
	SetOutApplicationLogValidFlag( false ) ; 
	SetMainWindowText("�������[") ;
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1;
	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen( DX_SCREEN_BACK ) ;
	SetAlwaysRunFlag(TRUE) ;
	//SetDXArchiveExtension( "abb") ;

	fps.fps_change(60);

	Game* game = new Game();
	game->birth(0, 360, HOHEI);

	SceneManager::getIns()->title();
	Images::init();

	while(1){
		DrawBox(0,0,WINDOW_X,WINDOW_Y,GetColor(255,255,255),TRUE);
		mouse_in* mouse=mouse_in::getIns();
		mouse->input();

		
		SceneManager::getIns()->loop();
		game->loop();
		


		fps.fps_wait();
		fps.draw_fps(0, 16);
		if(lcheck()==1)break;
	}
	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������
	return 0 ;					// �\�t�g�̏I��
}



