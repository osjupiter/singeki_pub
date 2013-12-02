#pragma warning(disable:4244)
#include "GV.h"
#include"fps.h"
#include"mouse.h"

#include "anime.h"

#include"SceneManager.h"
#include"Images.h"

//関数の持込-----------------------------------------------------




int lcheck(){
	ScreenFlip();
	if( ProcessMessage() < 0 ) return 1 ;
	//if( CheckHitKey( KEY_INPUT_ESCAPE ) ) return 1 ;
	return 0;
}
fps_c fps_c::ins;

// WinMain関数
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
			 LPSTR lpCmdLine, int nCmdShow )
{
//SetWindowIconID( IDI_ICON2 ) ;	
	// 画面モードの設定

	SetGraphMode( WINDOW_X, WINDOW_Y , 16 ) ;
	ChangeWindowMode( FALSE ) ;
	SetMouseDispFlag( FALSE );
	SetOutApplicationLogValidFlag( false ) ; 
	SetMainWindowText("くっきー") ;
	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1;
	// グラフィックの描画先を裏画面にセット
	SetDrawScreen( DX_SCREEN_BACK ) ;
	SetAlwaysRunFlag(TRUE) ;
	//SetDXArchiveExtension( "abb") ;
	fps_c::getIns()->init();
	fps_c::getIns()->fps_change(60);

	anime* ani = new anime();
	ani->birth(0, 0, HOHEI);

	SceneManager::getIns()->title();
	Images::init();

	while(1){
		DrawBox(0,0,WINDOW_X,WINDOW_Y,GetColor(0,0,0),TRUE);
		mouse_in* mouse=mouse_in::getIns();
		mouse->input();
		SceneManager::getIns()->loop();
		ani->main();
		ani->draw();

		fps_c::getIns()->fps_wait();
		fps_c::getIns()->draw_fps(0,16);
		if(lcheck()==1)break;
	}
	DxLib_End() ;				// ＤＸライブラリ使用の終了処理
	return 0 ;					// ソフトの終了
}



