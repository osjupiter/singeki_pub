#pragma warning(disable:4244)


#include "GV.h"
#include"fps.h"
#include"mouse.h"

#include "Game.h"
#include"SceneManager.h"
#include"Images.h"
#include"Scene.h"
#include"Data.h"
//�֐��̎���-----------------------------------------------------

#define MAINICON 101


int lcheck(){
	ScreenFlip();
	if( ProcessMessage() < 0 ) return 1 ;
	//if( CheckHitKey( KEY_INPUT_ESCAPE ) ) return 1 ;
	return 0;
}
fps_c fps_c::ins;

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
	//SetMainWindowText("�������[") ;
	SetMainWindowText("�N���ǂ��ł���2���R���L�X�^") ;
	SetWindowIconID(MAINICON);
	// �c�w���C�u��������������
	if( DxLib_Init() == -1 ) return -1;
	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen( DX_SCREEN_BACK ) ;
	SetAlwaysRunFlag(TRUE) ;
	//SetDXArchiveExtension( "abb") ;
	fps_c::getIns()->init();
	fps_c::getIns()->fps_change(30);
	Images::init();
	SoundController::getIns()->load();

	Data::getIns()->Read();

	SceneManager::getIns()->changeScene(make_shared<LogoScene>());
	

	while(1){
		DrawBox(0,0,WINDOW_X,WINDOW_Y,GetColor(0,0,0),TRUE);
		mouse_in* mouse=mouse_in::getIns();
		mouse->input();

		
		SceneManager::getIns()->loop();
		//game->loop();

		

		fps_c::getIns()->fps_wait();
		//fps_c::getIns()->draw_fps(0,WINDOW_Y-16);

		if(lcheck()==1)break;
	}
	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������
	return 0 ;					// �\�t�g�̏I��
}



