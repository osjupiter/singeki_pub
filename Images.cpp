#include"Images.h"
#include "DxLib.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

void Images::load(){
	vector<string> filelist;

	SetUseASyncLoadFlag( FALSE ); // �񓯊��ǂݍ��݃t���OOFF
	//�^�C�g���Ɏg�����̂�����
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/�荏�ڂ邯�[��.png");
	filelist.push_back("pic/world.png");
	
		
	filelist.push_back("pic/test.jpg");
	filelist.push_back("pic/black.jpg");
	
	blend=LoadBlendGraph("pic/blend.jpg");
	

		
	for(auto s:filelist){
		gs[s]=LoadGraph(s.c_str());

	}	





	SetUseASyncLoadFlag( TRUE ); // �񓯊��ǂݍ��݃t���OON
	


	LoadDivGraph("dat/img/����w.png", ANI_HOHEI, ANI_HOHEI, 1, WID_HOHEI, HEI_HOHEI, g_hohei);
	LoadDivGraph("dat/img/����a.png", ANI_HOHEI_ATK, ANI_HOHEI_ATK, 1, WID_HOHEI, HEI_HOHEI, g_hohei_atk);

	LoadDivGraph("dat/img/�G���w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank[0]);
	LoadDivGraph("dat/img/�G���a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK ,HEI_TANK, g_tank_atk[0]);
	LoadDivGraph("dat/img/��Ԏ��S.png", ANI_TANK_DEL,1, ANI_TANK_DEL, WID_TANK_DEL, HEI_TANK_DEL, g_tank_dei[0]);
	
	LoadDivGraph("dat/img/�G���2w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank[1]);
	LoadDivGraph("dat/img/�G���2a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK, HEI_TANK, g_tank_atk[1]);
	LoadDivGraph("dat/img/��Ԏ��S2.png", ANI_TANK_DEL, 1, ANI_TANK_DEL, WID_TANK_DEL, HEI_TANK_DEL, g_tank_dei[1]);

	LoadDivGraph("dat/img/�G���3w.png", ANI_TANK, ANI_TANK, 1, WID_TANK, HEI_TANK, g_tank[2]);
	LoadDivGraph("dat/img/�G���3a.png", ANI_TANK_ATK, ANI_TANK_ATK, 1, WID_TANK, HEI_TANK, g_tank_atk[2]);
	LoadDivGraph("dat/img/��Ԏ��S3.png", ANI_TANK_DEL, 1, ANI_TANK_DEL, WID_TANK_DEL, HEI_TANK_DEL, g_tank_dei[2]);

	LoadDivGraph("dat/img/�w��w.png", ANI_COPTER, ANI_COPTER, 1, WID_COPTER, HEI_COPTER, g_copter);
	LoadDivGraph("dat/img/�w�����S.png", ANI_COPTER_DIE, ANI_COPTER_DIE, 1, WID_COPTER_DIE, HEI_COPTER_DIE, g_copter_die);

	LoadDivGraph("dat/img/���D��w.png", ANI_BALLOON, ANI_BALLOON, 1, WID_BALLOON, HEI_BALLOON, g_balloon);
	LoadDivGraph("dat/img/���D��a.png", ANI_BALLOON_ATK, ANI_BALLOON_ATK, 1, WID_BALLOON, HEI_BALLOON, g_balloon_atk);

	LoadDivGraph("dat/img/���{��w.png", ANI_BIG, ANI_BIG, 1, WID_BIG, HEI_BIG, g_robo);
	LoadDivGraph("dat/img/���{��a.png", ANI_BIG_ATK, 6, 3, WID_BIG_ATK, HEI_BIG, g_robo_atk);

	LoadDivGraph("dat/img/���f�qw.png", ANI_KAMIKAZE, ANI_KAMIKAZE, 1, WID_KAMIKAZE, HEI_KAMIKAZE, g_kamikaze);
	LoadDivGraph("dat/img/���f�qa.png", ANI_KAMIKAZE_ATK, 5, 5, WID_KAMIKAZE_ATK, HEI_KAMIKAZE_ATK, g_kamikaze_atk);
	
	LoadDivGraph("dat/img/�o�Y�[�J��w.png", ANI_BAZOOKA, ANI_BAZOOKA, 1, WID_BAZOOKA, HEI_BAZOOKA, g_bazooka);
	LoadDivGraph("dat/img/�o�Y�[�J��a.png", ANI_BAZOOKA_ATK, 6, 2, WID_BAZOOKA_ATK, HEI_BAZOOKA_ATK, g_bazooka_atk);

	LoadDivGraph("dat/img/�Z�O�E�F�C��w.png", ANI_SEGWAY, ANI_SEGWAY, 1, WID_SEGWAY, HEI_SEGWAY, g_segway);
	LoadDivGraph("dat/img/�Z�O�E�F�C���������O.png", ANI_SEGWAY_WAIT, ANI_SEGWAY_WAIT, 1, WID_SEGWAY_WAIT, HEI_SEGWAY, g_segway_wait);
	LoadDivGraph("dat/img/�Z�O�E�F�C��������.png", ANI_SEGWAY, ANI_SEGWAY, 1, WID_SEGWAY_RUN, HEI_SEGWAY, g_segway_run);

	LoadDivGraph("dat/img/�Q�b�R�[w.png", ANI_GEKKO, ANI_GEKKO, 1, WID_GEKKO, HEI_GEKKO, g_gekko);
	LoadDivGraph("dat/img/�Q�b�R�[��a.png", ANI_GEKKO_UP, ANI_GEKKO, 1, WID_GEKKO, HEI_GEKKO, g_gekko_up);
	LoadDivGraph("dat/img/�Q�b�R�[��a.png", ANI_GEKKO_DOWN, ANI_GEKKO_DOWN, 1, WID_GEKKO, HEI_GEKKO, g_gekko_down);

	LoadDivGraph("dat/img/���[���K������w.png", ANI_RAILGUN, 1, ANI_RAILGUN, WID_RAILGUN, HEI_RAILGUN, g_rail);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�c����.png",ANI_YOUJO_W,ANI_YOUJO_W,1,WID_YOUJO,HEI_YOUJO,g_youjo_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�c��d.png", ANI_YOUJO_D, ANI_YOUJO_D, 1, WID_YOUJO, HEI_YOUJO-10, g_youjo_d);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�c��j.png", ANI_YOUJO_A, ANI_YOUJO_A/2, 2, WID_YOUJO, HEI_YOUJO, g_youjo_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/���U��w.png", ANI_TATEKO_W, ANI_TATEKO_W, 1, WID_TATEKO, HEI_TATEKO, g_tateko_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/���U��a.png", ANI_TATEKO_A, ANI_TATEKO_A, 1, WID_TATEKO, HEI_TATEKO, g_tateko_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�P�R�mw.png", ANI_HIME_W, ANI_HIME_W, 1, WID_HIME_W, HEI_HIME, g_hime_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�P�R�ma.png", ANI_HIME_A, ANI_HIME_A, 1, WID_HIME_A, HEI_HIME, g_hime_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�C�J���Xw.png", ANI_IKAROS_W, ANI_IKAROS_W, 1, WID_IKAROS_W, HEI_IKAROS, g_ikaros_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�C�J���Xa.png", ANI_IKAROS_A, ANI_IKAROS_A, 1, WID_IKAROS_A, HEI_IKAROS, g_ikaros_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�}�W��w.png", ANI_MAJO_W, ANI_MAJO_W, 1, WID_MAJO_W, HEI_MAJO, g_majo_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�}�W��a.png", ANI_MAJO_A, ANI_MAJO_A, 1, WID_MAJO_A, HEI_MAJO, g_majo_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�_��w.png", ANI_NOUKA_W, ANI_NOUKA_W, 1, WID_NOUKA_W, HEI_NOUKA, g_nouka_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�_��s.png", ANI_NOUKA_A, 4, 4, WID_NOUKA_A, HEI_NOUKA, g_nouka_a1);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�_��m.png", ANI_NOUKA_A, 4, 4, WID_NOUKA_A, HEI_NOUKA, g_nouka_a2);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�Ԃ�.png", ANI_HANA, 5, 5, WID_HANA, HEI_HANA, g_hana);

	LoadDivGraph("dat/img/���e.png", ANI_BOMB, ANI_BOMB, 1, WID_BOMB, HEI_BOMB, g_bomb);
	LoadDivGraph("dat/img/����E.png", ANI_EXP, 6, 2, WID_EXP, HEI_EXP, g_exp);
	LoadDivGraph("dat/img/���S������.png", ANI_NOMALEXP, ANI_NOMALEXP, 1, WID_NOMALEXP, HEI_NOMALEXP, g_nomalExp);

	LoadDivGraph("dat/img/���唚���G�t�F�N�g.png", ANI_BIGEXP, 5, 3, WID_BIGEXP, HEI_BIGEXP, g_bigexp);

	LoadDivGraph("dat/img/�Ռ��g.png", ANI_SHOCK, ANI_SHOCK, 1, WID_SHOCK, HEI_SHOCK, g_shock);
	LoadDivGraph("dat/img/�~�T�C��.png", ANI_MISSILE, ANI_MISSILE, 1, WID_MISSILE, HEI_MISSILE, g_missile);
	LoadDivGraph("dat/img/�e�|�h��.png", ANI_TEPODON, ANI_TEPODON, 1, WID_TEPODON, HEI_TEPODON, g_tepodon);
	LoadDivGraph("dat/img/�r�[�����˒�.png", ANI_BEAM, 1,ANI_BEAM, WID_BEAM, HEI_BEAM, g_beam);
	LoadDivGraph("dat/img/�r�[���`���[�W��.png", ANI_BEAM_C, ANI_BEAM_C, 1, WID_BEAM_C, HEI_BEAM_C, g_beam_c);

	LoadDivGraph("dat/img/�e��e��e.png", ANI_GUNSHOT, ANI_GUNSHOT, 1, WID_GUNSHOT, HEI_GUNSHOT, g_gunshot);
	LoadDivGraph("dat/img/�C�e��e��e.png", ANI_CANNONSHOT, ANI_CANNONSHOT, 1, WID_CANNONSHOT, HEI_CANNONSHOT, g_cannonshot);

	LoadDivGraph("dat/img/�ł̐��E/e2a1.png", 8, 8, 1, 96, 450, g_e_yamidrop[0]);
	LoadDivGraph("dat/img/�ł̐��E/e2a2.png", 8, 8, 1, 96, 450, g_e_yamidrop[1]);
	LoadDivGraph("dat/img/�ł̐��E/e2a3.png", 8, 8, 1, 96, 450, g_e_yamidrop[2]);

	LoadDivGraph("dat/img/�ł̐��E/ea1.png", 7, 7, 1, 155, 168, g_e_wisp[0]);
	LoadDivGraph("dat/img/�ł̐��E/ea2.png", 7, 7, 1, 155, 168, g_e_wisp[1]);
	LoadDivGraph("dat/img/�ł̐��E/ea3.png", 7, 7, 1, 155, 168, g_e_wisp[2]);


	back[0][0] = 0;
	back[0][1] = LoadGraph("dat/img/�r��/�r��P�|�S.png");
	back[0][2] = LoadGraph("dat/img/�r��/�r��P�|�R.png");
	back[0][3] = LoadGraph("dat/img/�r��/�r��P�|�Q.png");
	back[0][4] = LoadGraph("dat/img/�r��/�r��P�|�P.png");
	houdai_yama = LoadGraph("dat/img/�R/�R��C��.png");

	back[1][0] = 0;
	back[1][1] = LoadGraph("dat/img/�r��/�r��P�D�T�|�S.png");
	back[1][2] = LoadGraph("dat/img/�r��/�r��P�D�T�|�R.png");
	back[1][3] = LoadGraph("dat/img/�r��/�r��P�D�T�|�Q.png");
	back[1][4] = LoadGraph("dat/img/�r��/�r��P�D�T�|�P.png");

	back[2][0] = 0;
	back[2][1] = LoadGraph("dat/img/�r��/�r��Q�|�S.png");
	back[2][2] = LoadGraph("dat/img/�r��/�r��Q�|�R.png");
	back[2][3] = LoadGraph("dat/img/�r��/�r��Q�|�Q.png");
	back[2][4] = LoadGraph("dat/img/�r��/�r��Q�|�P.png");

	back[3][0] = 0;
	back[3][1] = LoadGraph("dat/img/�r��/�r��R�|�S.png");
	back[3][2] = LoadGraph("dat/img/�r��/�r��R�|�R.png");
	back[3][3] = LoadGraph("dat/img/�r��/�r��R�|�Q.png");
	back[3][4] = LoadGraph("dat/img/�r��/�r��R�|�P.png");

	back[4][0] = LoadGraph("dat/img/�r��/�r��T�|�T.png");
	back[4][1] = LoadGraph("dat/img/�r��/�r��T�|�S.png");
	back[4][2] = LoadGraph("dat/img/�r��/�r��T�|�R.png");
	back[4][3] = LoadGraph("dat/img/�r��/�r��T�|�Q.png");
	back[4][4] = LoadGraph("dat/img/�r��/�r��T�|�P.png");

	back[5][0] = 0;
	back[5][1] = LoadGraph("dat/img/�r��/�r��U�|�S.png");
	back[5][2] = LoadGraph("dat/img/�r��/�r��U�|�R.png");
	back[5][3] = LoadGraph("dat/img/�r��/�r��U�|�Q.png");
	back[5][4] = LoadGraph("dat/img/�r��/�r��U�|�P.png");

	back[6][0] = 0;
	back[6][1] = LoadGraph("dat/img/�r��/�r��V�|�S.png");
	back[6][2] = LoadGraph("dat/img/�r��/�r��V�|�R.png");
	back[6][3] = LoadGraph("dat/img/�r��/�r��V�|�Q.png");
	back[6][4] = LoadGraph("dat/img/�r��/�r��V�|�P.png");
	
	back[7][0] = LoadGraph("dat/img/�r��/�r��W�|�T.png");
	back[7][1] = LoadGraph("dat/img/�r��/�r��W�|�S.png");
	back[7][2] = LoadGraph("dat/img/�r��/�r��W�|�R.png");
	back[7][3] = LoadGraph("dat/img/�r��/�r��W�|�Q.png");
	back[7][4] = LoadGraph("dat/img/�r��/�r��W�|�P.png");

	g_mekahaikyo=LoadGraph("dat/img/���J�p��.png");

	g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
	g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
	g_castle[0][2] = LoadGraph("dat/img/�ŏ��̋��_.png");
	
	g_castle[1][0] = LoadGraph("dat/img/�R/�R��.png");
	g_castle[1][1] = LoadGraph("dat/img/�R/�R�锼��.png");
	g_castle[1][2] = LoadGraph("dat/img/�R/���J�R��.png");
	
	g_castle[2][0] = LoadGraph("dat/img/�X/�X��.png");
	g_castle[2][1] = LoadGraph("dat/img/�X/�X�锼��.png");
	g_castle[2][2] = LoadGraph("dat/img/�X/���J�X��.png");
	
	g_castle[3][0] = LoadGraph("dat/img/���/����.png");
	g_castle[3][1] = LoadGraph("dat/img/���/���锼��.png");
	g_castle[3][2] = LoadGraph("dat/img/���/���J����.png");
	
	g_castle[4][0] = LoadGraph("dat/img/�C/�C��.png");
	g_castle[4][1] = LoadGraph("dat/img/�C/�C�锼��.png");
	g_castle[4][2] = LoadGraph("dat/img/�C/���J�C��.png");
	
	g_castle[5][0] = LoadGraph("dat/img/����/������.png");
	g_castle[5][1] = LoadGraph("dat/img/����/�����锼��.png");
	g_castle[5][2] = LoadGraph("dat/img/����/���J������.png");
	
	g_castle[6][0] = LoadGraph("dat/img/���A/���A��.png");
	g_castle[6][1] = LoadGraph("dat/img/���A/���A�锼��.png");
	g_castle[6][2] = LoadGraph("dat/img/���A/���J���A��.png");
	
	g_castle[7][0] = LoadGraph("dat/img/�s�s/�s�s��.png");
	g_castle[7][1] = LoadGraph("dat/img/�s�s/�s�s�锼��.png");
	g_castle[7][2] = LoadGraph("dat/img/�s�s/���J�s�s��.png");
	
	LoadDivGraph("dat/img/���J�˂ޖ�.png", ANI_MEKANEMU, ANI_MEKANEMU, 1, WID_MEKANEMU, HEI_CASTLE, g_castle[8]);
	LoadDivGraph("dat/img/���X�{�X��.png", 3, 3, 1, 324, 364, g_thunder_mekanemu);



	//sound[0]=LoadSoundMem("sound/kuma.mp3");

	

	filelist.push_back("pic/tou.png");

	filelist.push_back("pic/ba.png");
	filelist.push_back("pic/ha.png");
	filelist.push_back("pic/ka.png");
	filelist.push_back("pic/na.png");
	filelist.push_back("pic/ra.png");
	filelist.push_back("pic/sa.png");
	filelist.push_back("pic/ba2.png");
	filelist.push_back("pic/ha2.png");
	filelist.push_back("pic/ka2.png");
	filelist.push_back("pic/na2.png");
	filelist.push_back("pic/ra2.png");
	filelist.push_back("pic/sa2.png");
	filelist.push_back("pic/����.png");

	
	filelist.push_back("pic/HP.png");
	filelist.push_back("pic/�U�����x.png");
	filelist.push_back("pic/�����_�E��.png");
	filelist.push_back("pic/���Y���x.png");
	filelist.push_back("pic/����.png");
	filelist.push_back("pic/�h��.png");
	filelist.push_back("pic/��.png");

	filelist.push_back("pic/HP2.png");
	filelist.push_back("pic/�U�����x2.png");
	filelist.push_back("pic/�����_�E��2.png");
	filelist.push_back("pic/���Y���x2.png");
	filelist.push_back("pic/����2.png");
	filelist.push_back("pic/�h��2.png");
	filelist.push_back("pic/��2.png");



	filelist.push_back("pic/���J�C��a.png");
	filelist.push_back("pic/���J�C��a2.png");
	filelist.push_back("pic/���J�R��a.png");
	filelist.push_back("pic/���J�R��a2.png");
	filelist.push_back("pic/���J�X��a.png");
	filelist.push_back("pic/���J�X��a2.png");
	filelist.push_back("pic/���J�s�s��a.png");
	filelist.push_back("pic/���J�s�s��a2.png");
	filelist.push_back("pic/���J���A��a.png");
	filelist.push_back("pic/���J���A��a2.png");
	filelist.push_back("pic/���J����a.png");
	filelist.push_back("pic/���J����a2.png");
	filelist.push_back("pic/�ŏ��̋��_a.png");
	filelist.push_back("pic/�ŏ��̋��_a2.png");
	filelist.push_back("pic/���J������a.png");
	filelist.push_back("pic/���J������a2.png");
	filelist.push_back("pic/���Y���~a.png");
	filelist.push_back("pic/���Y���~a2.png");
	filelist.push_back("pic/MUI.png");

	filelist.push_back("pic/���j�b�g�I���E�C���h�E.png");
	filelist.push_back("pic/MUI�̃X�e�[�W�̂܂�.png");
	filelist.push_back("pic/���j�b�g�I���E�C���h�E.png");
	filelist.push_back("pic/���j�b�g�I���E�C���h�E�Q.png");
	filelist.push_back("pic/�J�X�^���p��E�C���h�E.png");
	filelist.push_back("pic/�J�X�^���p�����Ȏ���.png");
	filelist.push_back("pic/�J�X�^���p���E�C���h�E.png");
	filelist.push_back("pic/GAMEOVER.png");
	filelist.push_back("pic/�����{�^��1.png");
	filelist.push_back("pic/�����{�^��2.png");
	filelist.push_back("pic/�����{�^��1m.png");
	filelist.push_back("pic/�����{�^��3.png");
	filelist.push_back("pic/�G���f�B���O.png");
	filelist.push_back("pic/Lv.png");
	filelist.push_back("pic/CUSTUM.png");
	filelist.push_back("pic/CUSTUMon.png");
	//�|�b�v�A�b�v�E�C���h�E.png
	filelist.push_back("pic/�|�b�v�A�b�v�E�C���h�E.png");
	filelist.push_back("pic/�|�b�v�A�b�v����.png");


	for(auto s:filelist){
		if (gs.count(s) == 0)
			gs[s]=LoadGraph(s.c_str());

	}	

	SetUseASyncLoadFlag( FALSE ); // �񓯊��ǂݍ��݃t���OOFF
	font=CreateFontToHandle( "���C���I" , 13 , 5 ,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;
}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}

	int Images::get(const char name[]){return ins.gs[string(name)];}


	


	int Images::getMusumeIcon(int id,boolean dfalse){
		string s;
		switch (id){
			case 0:
				s="pic/���Y���~a";
				break;
			case 1:
				s="pic/na";
				break;
			case 2:
				s="pic/ha";
				break;
			case 3:
				s="pic/ra";
				break;
			case 4:
				s="pic/ka";
				break;
			case 5:
				s="pic/ba";
				break;
			case 6:
				s="pic/sa";
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
		}
		if(dfalse)s+="2";
		return ins.get((s+".png").c_str());
	}
	int Images::getSiroIcon(int id,boolean defalt_false){
		string s;
		switch (id){
			case 0:
				s="pic/�ŏ��̋��_a";
				break;
			case 1:
				s="pic/���J�R��a";
				break;
			case 2:
				s="pic/���J�X��a";
				break;
			case 3:
				s="pic/���J����a";
				break;
			case 4:
				s="pic/���J�C��a";
				break;
			case 5:
				s="pic/���J������a";
				break;
			case 6:
				s="pic/���J���A��a";
				break;
			case 7:
				s="pic/���J�s�s��a";
				break;
			case 8:
				break;
			case 9:
				break;
		}
		if(defalt_false)
			s+="2";
		return ins.get((s+".png").c_str());
	}

	int Images::getParamTypeIcon(ParamType i,boolean dfalse){
		string hoge[]={
			"pic/��",
			"pic/HP",
			"pic/����",
			"pic/�h��",
			"",
			"pic/���Y���x",
			"pic/�����_�E��",
			"pic/�U�����x",
		};
		
		return ins.get((hoge[i]+(dfalse?"2":"")+".png").c_str());

	}

