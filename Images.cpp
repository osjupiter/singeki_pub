#include"Images.h"
Images Images::ins;

void Images::load(){
	gs[0]=LoadGraph("pic/test.jpg");
	LoadDivGraph("dat/img/•à•ºw.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	back[0][0] = LoadGraph("dat/img/”wŒi‚P|‚P.png");
	back[0][1] = LoadGraph("dat/img/”wŒi‚P|‚Q.png");
	back[0][2] = LoadGraph("dat/img/”wŒi‚P|‚R.png");
	back[1][0] = LoadGraph("dat/img/X/”wŒi‚Q|‚P.png");
	back[1][1] = LoadGraph("dat/img/X/”wŒi‚Q|‚Q.png");
	back[1][2] = LoadGraph("dat/img/X/”wŒi‚Q|‚R.png");
	back[2][0] = LoadGraph("dat/img/–éí/”wŒi‚R|‚P.png");
	back[2][1] = LoadGraph("dat/img/–éí/”wŒi‚R|‚Q.png");
	back[2][2] = LoadGraph("dat/img/–éí/”wŒi‚R|‚R.png");
	back[3][0] = LoadGraph("dat/img/ŠC/”wŒi‚S|‚P.png");
	back[3][2] = LoadGraph("dat/img/ŠC/”wŒi‚S|‚Q.png");

}