#include"Images.h"
Images Images::ins;

void Images::load(){
	gs[0]=LoadGraph("pic/test.jpg");
	LoadDivGraph("dat/img/����w.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	back[0][0] = LoadGraph("dat/img/�w�i�P�|�P.png");
	back[0][1] = LoadGraph("dat/img/�w�i�P�|�Q.png");
	back[0][2] = LoadGraph("dat/img/�w�i�P�|�R.png");
	back[1][0] = LoadGraph("dat/img/�X/�w�i�Q�|�P.png");
	back[1][1] = LoadGraph("dat/img/�X/�w�i�Q�|�Q.png");
	back[1][2] = LoadGraph("dat/img/�X/�w�i�Q�|�R.png");
	back[2][0] = LoadGraph("dat/img/���/�w�i�R�|�P.png");
	back[2][1] = LoadGraph("dat/img/���/�w�i�R�|�Q.png");
	back[2][2] = LoadGraph("dat/img/���/�w�i�R�|�R.png");
	back[3][0] = LoadGraph("dat/img/�C/�w�i�S�|�P.png");
	back[3][2] = LoadGraph("dat/img/�C/�w�i�S�|�Q.png");

}