#include"Images.h"
#include "DxLib.h"
#include<map>
#include <string>
#include <iostream>
Images Images::ins;

template
<
    typename TYPE,
    std::size_t SIZE
>
std::size_t array_length(const TYPE (&)[SIZE])
{
    return SIZE;
}

void Images::load(){
	vector<string> filelist;

	SetUseASyncLoadFlag( FALSE ); // �񓯊��ǂݍ��݃t���OOFF
	//�^�C�g���Ɏg�����̂�����
	filelist.push_back("pic/title.png");
	filelist.push_back("pic/�荏�ڂ邯�[��.png");
	
	
		
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

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�c��w2.png",ANI_YOUJO_W,ANI_YOUJO_W,1,WID_YOUJO,HEI_YOUJO,g_youjo_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�c��d2.png", ANI_YOUJO_D, ANI_YOUJO_D, 1, WID_YOUJO, HEI_YOUJO, g_youjo_d);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�c��j2.png", ANI_YOUJO_A, ANI_YOUJO_A/2, 2, WID_YOUJO, HEI_YOUJO, g_youjo_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/���U��w.png", ANI_TATEKO_W, ANI_TATEKO_W, 1, WID_TATEKO, HEI_TATEKO, g_tateko_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/���U��a.png", ANI_TATEKO_A, ANI_TATEKO_A, 1, WID_TATEKO, HEI_TATEKO, g_tateko_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�P�R�mw2.png", ANI_HIME_W, ANI_HIME_W, 1, WID_HIME_W, HEI_HIME, g_hime_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�P�R�ma2.png", ANI_HIME_A, ANI_HIME_A, 1, WID_HIME_A, HEI_HIME, g_hime_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�C�J���Xw2.png", ANI_IKAROS_W, ANI_IKAROS_W, 1, WID_IKAROS_W, HEI_IKAROS, g_ikaros_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�C�J���Xa2.png", ANI_IKAROS_A, ANI_IKAROS_A, 1, WID_IKAROS_A, HEI_IKAROS, g_ikaros_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�}�W��w2.png", ANI_MAJO_W, ANI_MAJO_W, 1, WID_MAJO_W, HEI_MAJO, g_majo_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�}�W��a2.png", ANI_MAJO_A, ANI_MAJO_A, 1, WID_MAJO_A, HEI_MAJO, g_majo_a);

	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�_��w.png", ANI_NOUKA_W, ANI_NOUKA_W, 1, WID_NOUKA_W, HEI_NOUKA, g_nouka_w);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�_��s.png", ANI_NOUKA_A, 4, 4, WID_NOUKA_A, HEI_NOUKA, g_nouka_a1);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�_��m.png", ANI_NOUKA_A, 4, 4, WID_NOUKA_A, HEI_NOUKA, g_nouka_a2);

	LoadDivGraph("dat/img/�G���j�b�g/�r��/�K�W�K�W���Jw.png", ANI_GAJIGAJI_W, ANI_GAJIGAJI_W, 1, WID_GAJIGAJI, HEI_GAJIGAJI_W, g_gajigaji_w[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�K�W�K�W���Ja.png", ANI_GAJIGAJI_A, ANI_GAJIGAJI_A, 1, WID_GAJIGAJI, HEI_GAJIGAJI_A, g_gajigaji_a[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�K�W�K�W���J2w.png", ANI_GAJIGAJI_W, ANI_GAJIGAJI_W, 1, WID_GAJIGAJI, HEI_GAJIGAJI_W, g_gajigaji_w[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�K�W�K�W���J2a.png", ANI_GAJIGAJI_A, ANI_GAJIGAJI_A, 1, WID_GAJIGAJI, HEI_GAJIGAJI_A, g_gajigaji_a[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�K�W�K�W���J3w.png", ANI_GAJIGAJI_W, ANI_GAJIGAJI_W, 1, WID_GAJIGAJI, HEI_GAJIGAJI_W, g_gajigaji_w[2]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�K�W�K�W���J3a.png", ANI_GAJIGAJI_A, ANI_GAJIGAJI_A, 1, WID_GAJIGAJI, HEI_GAJIGAJI_A, g_gajigaji_a[2]);

	LoadDivGraph("dat/img/�G���j�b�g/�r��/�ԗ֖C��w.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_w[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�ԗ֖C��a1.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_a[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�ԗ֖C��2w.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_w[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�ԗ֖C��2a.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_a[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�ԗ֖C��3w.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_w[2]);
	LoadDivGraph("dat/img/�G���j�b�g/�r��/�ԗ֖C��3a.png", ANI_SHARIN, ANI_SHARIN, 1, WID_SHARIN, HEI_SHARIN, g_sharin_a[2]);

	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�S���[��1s.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_w[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�S���[��1a.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_a[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�S���[��2s.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_w[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�S���[��2a.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_a[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�S���[��3s.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_w[2]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�S���[��3a.png", ANI_GOREMU, 4, 3, WID_GOREMU, HEI_GOREMU, g_goremu_a[2]);

	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�r�[�o�[w.png", ANI_BEEBAR_W, ANI_BEEBAR_W, 1, WID_BEEBAR_W, HEI_BEEBAR_W, g_beebar_w[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�r�[�o�[a.png", ANI_BEEBAR_A, ANI_BEEBAR_A, 1, WID_BEEBAR_A, HEI_BEEBAR_A, g_beebar_a[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�r�[�o�[2w.png", ANI_BEEBAR_W, ANI_BEEBAR_W, 1, WID_BEEBAR_W, HEI_BEEBAR_W, g_beebar_w[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�r�[�o�[2a.png", ANI_BEEBAR_A, ANI_BEEBAR_A, 1, WID_BEEBAR_A, HEI_BEEBAR_A, g_beebar_a[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�r�[�o�[3w.png", ANI_BEEBAR_W, ANI_BEEBAR_W, 1, WID_BEEBAR_W, HEI_BEEBAR_W, g_beebar_w[2]);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�r�[�o�[3a.png", ANI_BEEBAR_A, ANI_BEEBAR_A, 1, WID_BEEBAR_A, HEI_BEEBAR_A, g_beebar_a[2]);

	
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�����͂�a1.png", ANI_SAIHATE_A, 1, ANI_SAIHATE_A, WID_SAIHATE_A_R, HEI_SAIHATE, g_saihate_a_r);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�����͂�a2.png", ANI_SAIHATE_A, ANI_SAIHATE_A, 1, WID_SAIHATE, HEI_SAIHATE_A_S, g_saihate_a_s);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�����͂�t.png", ANI_SAIHATE_T, ANI_SAIHATE_T, 1, WID_SAIHATE, HEI_SAIHATE, g_saihate_t);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�����͂�h.png", ANI_SAIHATE_H, 3, 3, WID_SAIHATE, HEI_SAIHATE, g_saihate_h);

	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���m���X1w.png", ANI_MONORIS_W, ANI_MONORIS_W, 1, WID_MONORIS, HEI_MONORIS, g_monoris_w[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���m���X1a1.png", ANI_MONORIS_A1, ANI_MONORIS_A1, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a1[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���m���X1a2.png", ANI_MONORIS_A2, ANI_MONORIS_A2, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a2[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���m���X2w.png", ANI_MONORIS_W, ANI_MONORIS_W, 1, WID_MONORIS, HEI_MONORIS, g_monoris_w[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���m���X2a1.png", ANI_MONORIS_A1, ANI_MONORIS_A1, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a1[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���m���X2a2.png", ANI_MONORIS_A2, ANI_MONORIS_A2, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a2[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���m���X3w.png", ANI_MONORIS_W, ANI_MONORIS_W, 1, WID_MONORIS, HEI_MONORIS, g_monoris_w[2]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���m���X3a1.png", ANI_MONORIS_A1, ANI_MONORIS_A1, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a1[2]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���m���X3a2.png", ANI_MONORIS_A2, ANI_MONORIS_A2, 1, WID_MONORIS, HEI_MONORIS, g_monoris_a2[2]);

	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���d�_�P����.png", ANI_DENGUMO_W, ANI_DENGUMO_W, 1, WID_DENGUMO, HEI_DENGUMO, g_dengumo_w[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���d�_�P�U��.png", ANI_DENGUMO_A, 5 , 3, WID_DENGUMO, HEI_DENGUMO, g_dengumo_a[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���d�_�Q����.png", ANI_DENGUMO_W, ANI_DENGUMO_W, 1, WID_DENGUMO, HEI_DENGUMO, g_dengumo_w[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���d�_�Q�U��.png", ANI_DENGUMO_A, 5, 3, WID_DENGUMO, HEI_DENGUMO, g_dengumo_a[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���d�_�R����.png", ANI_DENGUMO_W, ANI_DENGUMO_W, 1, WID_DENGUMO, HEI_DENGUMO, g_dengumo_w[2]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���d�_�R�U��.png", ANI_DENGUMO_A, 5, 3, WID_DENGUMO, HEI_DENGUMO, g_dengumo_a[2]);

	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/�r�[���G�t�F�N�g1.png", ANI_MONOBEAM, ANI_MONOBEAM, 1, WID_MONOBEAM, HEI_MONOBEAM, g_monobeam[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/�r�[���G�t�F�N�g2.png", ANI_MONOBEAM, ANI_MONOBEAM, 1, WID_MONOBEAM, HEI_MONOBEAM, g_monobeam[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/�r�[���G�t�F�N�g3.png", ANI_MONOBEAM, ANI_MONOBEAM, 1, WID_MONOBEAM, HEI_MONOBEAM, g_monobeam[2]);

	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/���P.png", ANI_DENKAMI, 1, ANI_DENKAMI, WID_DENKAMI, HEI_DENKAMI, g_denkami[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/��2.png", ANI_DENKAMI, 1, ANI_DENKAMI, WID_DENKAMI, HEI_DENKAMI, g_denkami[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/��3.png", ANI_DENKAMI, 1, ANI_DENKAMI, WID_DENKAMI, HEI_DENKAMI, g_denkami[2]);

	LoadDivGraph("dat/img/�G���j�b�g/���̒�/���q��1w.png", ANI_SENKOU_W, ANI_SENKOU_W, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_w[0]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/���q��1a.png", ANI_SENKOU_A, ANI_SENKOU_A, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_a[0]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/���q��2w.png", ANI_SENKOU_W, ANI_SENKOU_W, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_w[1]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/���q��2a.png", ANI_SENKOU_A, ANI_SENKOU_A, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_a[1]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/���q��3w.png", ANI_SENKOU_W, ANI_SENKOU_W, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_w[2]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/���q��3a.png", ANI_SENKOU_A, ANI_SENKOU_A, 1, WID_SENKOU, HEI_SENKOU, g_senkoutei_a[2]);

	LoadDivGraph("dat/img/�G���j�b�g/���̒�/����1.png", ANI_GYORAI, ANI_GYORAI, 1, WID_GYORAI, HEI_GYORAI, g_gyorai[0]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/����2.png", ANI_GYORAI, ANI_GYORAI, 1, WID_GYORAI, HEI_GYORAI, g_gyorai[1]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/����3.png", ANI_GYORAI, ANI_GYORAI, 1, WID_GYORAI, HEI_GYORAI, g_gyorai[2]);


	LoadDivGraph("dat/img/�G���j�b�g/���̒�/��̐G��1�o��.png", ANI_SHOKUSH_S, 5, 3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_s[0]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/��̐G��1�U��.png", ANI_SHOKUSH_A, 3,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_a[0]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/��̐G��2�o��.png", ANI_SHOKUSH_S, 5,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_s[1]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/��̐G��2�U��.png", ANI_SHOKUSH_A, 3,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_a[1]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/��̐G��3�o��.png", ANI_SHOKUSH_S, 5,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_s[2]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/��̐G��3�U��.png", ANI_SHOKUSH_A, 3,3, WID_SHOKUSH, HEI_SHOKUSH, g_shokush_a[2]);

	LoadDivGraph("dat/img/�G���j�b�g/���̒�/��̐G��1�L���L��.png", ANI_KIRAKIRA, 6,2, WID_KIRAKIRA, HEI_KIRAKIRA, g_kirakira[0]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/��̐G��2�L���L��.png", ANI_KIRAKIRA, 6,2, WID_KIRAKIRA, HEI_KIRAKIRA, g_kirakira[1]);
	LoadDivGraph("dat/img/�G���j�b�g/���̒�/��̐G��3�L���L��.png", ANI_KIRAKIRA, 6,2, WID_KIRAKIRA, HEI_KIRAKIRA, g_kirakira[2]);

	LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/���ԖC��1�o��.png", ANI_OHANA_S, 4, 4, WID_OHANA, HEI_OHANA, g_ohana_s[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/���ԖC��1�U��.png", ANI_OHANA_A, 3, 3, WID_OHANA, HEI_OHANA, g_ohana_a[0]);
	LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/���ԖC��2�o��.png", ANI_OHANA_S, 4, 4, WID_OHANA, HEI_OHANA, g_ohana_s[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/���ԖC��2�U��.png", ANI_OHANA_A, 3, 3, WID_OHANA, HEI_OHANA, g_ohana_a[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/���ԖC��3�o��.png", ANI_OHANA_S, 4, 4, WID_OHANA, HEI_OHANA, g_ohana_s[2]);
	LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/���ԖC��3�U��.png", ANI_OHANA_A, 3, 3, WID_OHANA, HEI_OHANA, g_ohana_a[2]);

	LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/�ʂ˂��~�T�C��1.png", ANI_NEGIMISSILE, 2, 1, WID_NEGIMISSILE, HEI_NEGIMISSILE, g_negimissile[2]);
	LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/�ʂ˂��~�T�C��2.png", ANI_NEGIMISSILE, 2, 1, WID_NEGIMISSILE, HEI_NEGIMISSILE, g_negimissile[1]);
	LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/�ʂ˂��~�T�C��3.png", ANI_NEGIMISSILE, 2, 1, WID_NEGIMISSILE, HEI_NEGIMISSILE, g_negimissile[0]);


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

	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�䂫����1.png", ANI_YUKIDAMA, 4, 2, WID_YUKIDAMA, HEI_YUKIDAMA, g_yukidama1);
	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�䂫����2.png", ANI_YUKIDAMA, 4, 2, WID_YUKIDAMA, HEI_YUKIDAMA, g_yukidama2);

	LoadDivGraph("dat/img/�G���j�b�g/�ጴ/�S�����̐�.png", ANI_GVOICE, ANI_GVOICE, 1, WID_GVOICE, HEI_GVOICE, g_gvoice);

	LoadDivGraph("dat/img/�e��e��e.png", ANI_GUNSHOT, ANI_GUNSHOT, 1, WID_GUNSHOT, HEI_GUNSHOT, g_gunshot);
	LoadDivGraph("dat/img/�C�e��e��e.png", ANI_CANNONSHOT, ANI_CANNONSHOT, 1, WID_CANNONSHOT, HEI_CANNONSHOT, g_cannonshot);

	LoadDivGraph("dat/img/�G���j�b�g/�r��/���݂��G�t�F�N�g.png", ANI_GAJIKAMI, ANI_GAJIKAMI, 1, WID_GAJIKAMI, HEI_GAJIKAMI, g_gajikami);
	LoadDivGraph("dat/img/�G���j�b�g/�_�̏�/�r�[����e�P.png", ANI_MONOB_H, ANI_MONOB_H, 1, WID_MONOB_H, HEI_MONOB_H, g_monob_h);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�����w.png", ANI_MAHOJIN, 5, 4, WID_MAHOJIN, HEI_MAHOJIN, g_mahojin);
	LoadDivGraph("dat/img/�ނ��߃��j�b�g/�a���G�t�F�N�g1.png", ANI_ZANGEKI, ANI_ZANGEKI, 1, WID_ZANGEKI, HEI_ZANGEKI, g_zangeki);


	LoadDivGraph("dat/img/�ł̐��E/e2a1.png", 8, 8, 1, 96, 450, g_e_yamidrop[0]);
	LoadDivGraph("dat/img/�ł̐��E/e2a2.png", 8, 8, 1, 96, 450, g_e_yamidrop[1]);
	LoadDivGraph("dat/img/�ł̐��E/e2a3.png", 8, 8, 1, 96, 450, g_e_yamidrop[2]);

	LoadDivGraph("dat/img/�ł̐��E/ea1.png", 7, 7, 1, 155, 168, g_e_wisp[0]);
	LoadDivGraph("dat/img/�ł̐��E/ea2.png", 7, 7, 1, 155, 168, g_e_wisp[1]);
	LoadDivGraph("dat/img/�ł̐��E/ea3.png", 7, 7, 1, 155, 168, g_e_wisp[2]);
	houdai_yama = LoadGraph("dat/img/�R/�R��C��.png");
	/*
*/



	g_mekahaikyo=LoadGraph("dat/img/���J�p��.png");

	
	LoadDivGraph("dat/img/���J�˂ޖ�.png", ANI_MEKANEMU, ANI_MEKANEMU, 1, WID_MEKANEMU, HEI_CASTLE, g_castle[8]);
	LoadDivGraph("dat/img/���X�{�X��.png", 3, 3, 1, 324, 364, g_thunder_mekanemu);



	//sound[0]=LoadSoundMem("sound/kuma.mp3");

	
	
	filelist.push_back("pic/tou.png");

	filelist.push_back("pic/Pause.png");

	filelist.push_back("pic/clear.png");
	
	filelist.push_back("pic/ba.png");
	filelist.push_back("pic/ha.png");
	filelist.push_back("pic/ka.png");
	filelist.push_back("pic/na.png");
	filelist.push_back("pic/ra.png");
	filelist.push_back("pic/sa.png");

	filelist.push_back("pic/bu.png");
	filelist.push_back("pic/ja.png");
	filelist.push_back("pic/ma.png");
	filelist.push_back("pic/ta.png");
	filelist.push_back("pic/wa.png");
	filelist.push_back("pic/ya.png");

	filelist.push_back("pic/ba2.png");
	filelist.push_back("pic/ha2.png");
	filelist.push_back("pic/ka2.png");
	filelist.push_back("pic/na2.png");
	filelist.push_back("pic/ra2.png");
	filelist.push_back("pic/sa2.png");

	
	filelist.push_back("pic/bu2.png");
	filelist.push_back("pic/ja2.png");
	filelist.push_back("pic/ma2.png");
	filelist.push_back("pic/ta2.png");
	filelist.push_back("pic/wa2.png");
	filelist.push_back("pic/ya2.png");

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

	
	filelist.push_back("pic/���[���h�}�b�va.png");
	filelist.push_back("pic/���[���h�}�b�vb.png");
	filelist.push_back("pic/���[���h�}�b�vc.png");
	filelist.push_back("pic/���[���h�}�b�vd.png");
	filelist.push_back("pic/���[���h�}�b�ve.png");
	filelist.push_back("pic/���[���h�}�b�vf.png");
	
	filelist.push_back("pic/���[���h�}�b�vg.png");

	
	filelist.push_back("pic/�o���O���j�b�g�I���E�C���h�E.png");
	filelist.push_back("pic/�o���{�^��ON.png");
	filelist.push_back("pic/�o���{�^��OFF.png");
	
	filelist.push_back("pic/�o���{�^��NO.png");
	filelist.push_back("pic/world_stage.png");




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
	
	font2=CreateFontToHandle( "���C���I" , 30 , 5 ,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;
}

	void Images::init(){ins.load();}
	Images* Images::getIns(){return &ins;}

	int Images::get(const char name[]){return ins.gs[string(name)];}


	


	int Images::getMusumeIcon(int id,boolean dfalse){
		string hoge[]={
			"pic/���Y���~a",
			"pic/na",
			"pic/ha",
			"pic/ra",
			"pic/ka",
			"pic/ba",
			"pic/sa",
			"pic/wa",
			"pic/bu",
			"pic/ta",
			"pic/ma",
			"pic/ya",
			"pic/ja",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",

		};
		string s=hoge[id];

		if(dfalse)s+="2";
		return ins.get((s+".png").c_str());
	}
	int Images::getSiroIcon(int id,boolean defalt_false){
		return ins.g_shiro_icon[id][(defalt_false)?1:0];
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


	void Images::loadStage(int sid){
		


		SetUseASyncLoadFlag( TRUE ); // �񓯊��ǂݍ��݃t���OON
		switch (sid)
		{
		case 1:
			
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/�r��/�r��P�|�S.png");
			back[0][2] = LoadGraph("dat/img/�r��/�r��P�|�R.png");
			back[0][3] = LoadGraph("dat/img/�r��/�r��P�|�Q.png");
			back[0][4] = LoadGraph("dat/img/�r��/�r��P�|�P.png");

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


			
			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/�ŏ��̋��_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/�V��/�r��/�r��P�G��P.png");
			g_castle[1][1] = LoadGraph("dat/img/�V��/�r��/�r��P�G��Q.png");
			g_castle[1][2] = LoadGraph("dat/img/�V��/�r��/�r��P������.png");
	
			g_castle[2][0] = LoadGraph("dat/img/�V��/�r��/�r��Q�G��P.png");
			g_castle[2][1] = LoadGraph("dat/img/�V��/�r��/�r��Q�G��Q.png");
			g_castle[2][2] = LoadGraph("dat/img/�V��/�r��/�r��Q������.png");
	
			g_castle[3][0] = LoadGraph("dat/img/�V��/�r��/�r��R�G��P.png");
			g_castle[3][1] = LoadGraph("dat/img/�V��/�r��/�r��R�G��Q.png");
			g_castle[3][2] = LoadGraph("dat/img/�V��/�r��/�r��R������.png");
	
			g_castle[4][0] = LoadGraph("dat/img/�V��/�r��/�r��S�G��P.png");
			g_castle[4][1] = LoadGraph("dat/img/�V��/�r��/�r��S�G��Q.png");
			g_castle[4][2] = LoadGraph("dat/img/�V��/�r��/�r��S������.png");
	
			g_castle[5][0] = LoadGraph("dat/img/�V��/�r��/�r��T�G��P.png");
			g_castle[5][1] = LoadGraph("dat/img/�V��/�r��/�r��T�G��Q.png");
			g_castle[5][2] = LoadGraph("dat/img/�V��/�r��/�r��T������.png");
	
			g_castle[6][0] = LoadGraph("dat/img/�V��/�r��/�r��U�G��P.png");
			g_castle[6][1] = LoadGraph("dat/img/�V��/�r��/�r��U�G��P.png");
			g_castle[6][2] = LoadGraph("dat/img/�V��/�r��/�r��U������.png");
	
			g_castle[7][0] = LoadGraph("dat/img/�V��/�r��/�r��V�G��P.png");
			g_castle[7][1] = LoadGraph("dat/img/�V��/�r��/�r��V�G��Q.png");
			g_castle[7][2] = LoadGraph("dat/img/�V��/�r��/�r��V������.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/wild_s1",
					"pic/wild_s2",
					"pic/wild_s3",
					"pic/wild_s4",
					"pic/wild_s5",
					"pic/wild_s6",
					"pic/wild_s7",
					"pic/wild_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			LoadDivGraph("dat/img/�G���j�b�g/�r��/�X�`�[���p���N���{����.png", ANI_STEAM_W, 3, 3, WID_STEAM, HEI_STEAM, g_steam_w);
			LoadDivGraph("dat/img/�G���j�b�g/�r��/�X�`�[���p���N���{�U��.png", ANI_STEAM_A, 4, 4, WID_STEAM, HEI_STEAM, g_steam_a);
			LoadDivGraph("dat/img/�G���j�b�g/�r��/�X�`�[���p���N���{���A.png", ANI_STEAM_F, ANI_STEAM_F, 1, WID_STEAM, HEI_STEAM, g_steam_f);


			break;
		case 4:
			back[0][0] = LoadGraph("dat/img/�ጴ/�ጴ�P-5.png");
			back[0][1] = LoadGraph("dat/img/�ጴ/�ጴ�P-4.png");
			back[0][2] = LoadGraph("dat/img/�ጴ/�ጴ�P-3.png");
			back[0][3] = LoadGraph("dat/img/�ጴ/�ጴ�P-2.png");
			back[0][4] = LoadGraph("dat/img/�ጴ/�ጴ�P-1.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/�ጴ/�ጴ�Q�|�S.png");
			back[1][2] = LoadGraph("dat/img/�ጴ/�ጴ�Q�|�R.png");
			back[1][3] = LoadGraph("dat/img/�ጴ/�ጴ�Q�|�Q.png");
			back[1][4] = LoadGraph("dat/img/�ጴ/�ጴ�Q�|�P.png");

			back[2][0] = LoadGraph("dat/img/�ጴ/�ጴ�R�|�T.png");
			back[2][1] = LoadGraph("dat/img/�ጴ/�ጴ�R�|�S.png");
			back[2][2] = LoadGraph("dat/img/�ጴ/�ጴ�R�|�R.png");
			back[2][3] = LoadGraph("dat/img/�ጴ/�ጴ�R�|�Q.png");
			back[2][4] = LoadGraph("dat/img/�ጴ/�ጴ�R�|�P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/�ጴ/�ጴ�S�|�S.png");
			back[3][2] = LoadGraph("dat/img/�ጴ/�ጴ�S�|�R.png");
			back[3][3] = LoadGraph("dat/img/�ጴ/�ጴ�S�|�Q.png");
			back[3][4] = LoadGraph("dat/img/�ጴ/�ጴ�S�|�P.png");

			back[4][0] = 0;
			back[4][1] = LoadGraph("dat/img/�ጴ/�ጴ�T�|�S.png");
			back[4][2] = LoadGraph("dat/img/�ጴ/�ጴ�T�|�R.png");
			back[4][3] = LoadGraph("dat/img/�ጴ/�ጴ�T�|�Q.png");
			back[4][4] = LoadGraph("dat/img/�ጴ/�ጴ�T�|�P.png");

			back[5][0] = LoadGraph("dat/img/�ጴ/�ጴ�U�|�T.png");
			back[5][1] = LoadGraph("dat/img/�ጴ/�ጴ�U�|�S.png");
			back[5][2] = LoadGraph("dat/img/�ጴ/�ጴ�U�|�R.png");
			back[5][3] = LoadGraph("dat/img/�ጴ/�ጴ�U�|�Q.png");
			back[5][4] = LoadGraph("dat/img/�ጴ/�ጴ�U�|�P.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/�ጴ/�ጴ�V�|�S.png");
			back[6][2] = LoadGraph("dat/img/�ጴ/�ጴ�V�|�R.png");
			back[6][3] = LoadGraph("dat/img/�ጴ/�ጴ�V�|�Q.png");
			back[6][4] = LoadGraph("dat/img/�ጴ/�ጴ�V�|�P.png");

			back[7][0] = 0;
			back[7][1] = LoadGraph("dat/img/�ጴ/�ጴ�W�|�S.png");
			back[7][2] = LoadGraph("dat/img/�ጴ/�ጴ�W�|�R.png");
			back[7][3] = LoadGraph("dat/img/�ጴ/�ጴ�W�|�Q.png");
			back[7][4] = LoadGraph("dat/img/�ጴ/�ጴ�W�|�P.png");

			
			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/�ŏ��̋��_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�P�G��P.png");
			g_castle[1][1] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�P�G��Q.png");
			g_castle[1][2] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�P������.png");
	
			g_castle[2][0] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�Q�G��P.png");
			g_castle[2][1] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�Q�G��Q.png");
			g_castle[2][2] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�Q������.png");
	
			g_castle[3][0] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�R�G��P.png");
			g_castle[3][1] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�R�G��Q.png");
			g_castle[3][2] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�R������.png");
	
			g_castle[4][0] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�S�G��P.png");
			g_castle[4][1] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�S�G��Q.png");
			g_castle[4][2] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�S������.png");
	
			g_castle[5][0] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�T�G��P.png");
			g_castle[5][1] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�T�G��Q.png");
			g_castle[5][2] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�T������.png");
	
			g_castle[6][0] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�U�G��P.png");
			g_castle[6][1] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�U�G��P.png");
			g_castle[6][2] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�U������.png");
	
			g_castle[7][0] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�V�G��P.png");
			g_castle[7][1] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�V�G��Q.png");
			g_castle[7][2] = LoadGraph("dat/img/�V��/�ጴ/�ጴ�V������.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/snow_s1",
					"pic/snow_s2",
					"pic/snow_s3",
					"pic/snow_s4",
					"pic/snow_s5",
					"pic/snow_s6",
					"pic/snow_s7",
					"pic/snow_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}


			break;
		case 2:
			back[0][0] = LoadGraph("dat/img/�_�̏�/�_�̏�P�|�T.png");
			back[0][1] = LoadGraph("dat/img/�_�̏�/�_�̏�P�|�S.png");
			back[0][2] = LoadGraph("dat/img/�_�̏�/�_�̏�P�|�R.png");
			back[0][3] = LoadGraph("dat/img/�_�̏�/�_�̏�P�|�Q.png");
			back[0][4] = LoadGraph("dat/img/�_�̏�/�_�̏�P�|�P.png");
			

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/�_�̏�/�_�̏�Q�|�S.png");
			back[1][2] = LoadGraph("dat/img/�_�̏�/�_�̏�Q�|�R.png");
			back[1][3] = LoadGraph("dat/img/�_�̏�/�_�̏�Q�|�Q.png");
			back[1][4] = LoadGraph("dat/img/�_�̏�/�_�̏�Q�|�P.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/�_�̏�/�_�̏�R�|�S.png");
			back[2][2] = LoadGraph("dat/img/�_�̏�/�_�̏�R�|�R.png");
			back[2][3] = LoadGraph("dat/img/�_�̏�/�_�̏�R�|�Q.png");
			back[2][4] = LoadGraph("dat/img/�_�̏�/�_�̏�R�|�P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/�_�̏�/�_�̏�S�|�S.png");
			back[3][2] = LoadGraph("dat/img/�_�̏�/�_�̏�S�|�R.png");
			back[3][3] = LoadGraph("dat/img/�_�̏�/�_�̏�S�|�Q.png");
			back[3][4] = LoadGraph("dat/img/�_�̏�/�_�̏�S�|�P.png");

			back[4][0] = 0;
			back[4][1] = LoadGraph("dat/img/�_�̏�/�_�̏�T�|�S.png");
			back[4][2] = LoadGraph("dat/img/�_�̏�/�_�̏�T�|�R.png");
			back[4][3] = LoadGraph("dat/img/�_�̏�/�_�̏�T�|�Q.png");
			back[4][4] = LoadGraph("dat/img/�_�̏�/�_�̏�T�|�P.png");

			back[5][0] = LoadGraph("dat/img/�_�̏�/�_�̏�U�|�T.png");
			back[5][1] = LoadGraph("dat/img/�_�̏�/�_�̏�U�|�S.png");
			back[5][2] = LoadGraph("dat/img/�_�̏�/�_�̏�U�|�R.png");
			back[5][3] = LoadGraph("dat/img/�_�̏�/�_�̏�U�|�Q.png");
			back[5][4] = LoadGraph("dat/img/�_�̏�/�_�̏�U�|�P.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/�_�̏�/�_�̏�V�|�S.png");
			back[6][2] = LoadGraph("dat/img/�_�̏�/�_�̏�V�|�R.png");
			back[6][3] = LoadGraph("dat/img/�_�̏�/�_�̏�V�|�Q.png");
			back[6][4] = LoadGraph("dat/img/�_�̏�/�_�̏�V�|�P.png");

			back[7][0] = LoadGraph("dat/img/�_�̏�/�_�̏�W�|�T.png");
			back[7][1] = LoadGraph("dat/img/�_�̏�/�_�̏�W�|�S.png");
			back[7][2] = LoadGraph("dat/img/�_�̏�/�_�̏�W�|�R.png");
			back[7][3] = LoadGraph("dat/img/�_�̏�/�_�̏�W�|�Q.png");
			back[7][4] = LoadGraph("dat/img/�_�̏�/�_�̏�W�|�P.png");
			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/�ŏ��̋��_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�P�G��P.png");
			g_castle[1][1] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�P�G��Q.png");
			g_castle[1][2] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�P������.png");
	
			g_castle[2][0] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�Q�G��P.png");
			g_castle[2][1] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�Q�G��Q.png");
			g_castle[2][2] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�Q������.png");
	
			g_castle[3][0] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�R�G��P.png");
			g_castle[3][1] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�R�G��Q.png");
			g_castle[3][2] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�R������.png");
	
			g_castle[4][0] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�S�G��P.png");
			g_castle[4][1] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�S�G��Q.png");
			g_castle[4][2] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�S������.png");
	
			g_castle[5][0] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�T�G��P.png");
			g_castle[5][1] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�T�G��Q.png");
			g_castle[5][2] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�T������.png");
	
			g_castle[6][0] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�U�G��P.png");
			g_castle[6][1] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�U�G��P.png");
			g_castle[6][2] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�U������.png");
	
			g_castle[7][0] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�V�G��P.png");
			g_castle[7][1] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�V�G��Q.png");
			g_castle[7][2] = LoadGraph("dat/img/�V��/�_�̏�/�_�̏�V������.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/cloud_s1",
					"pic/cloud_s2",
					"pic/cloud_s3",
					"pic/cloud_s4",
					"pic/cloud_s5",
					"pic/cloud_s6",
					"pic/cloud_s7",
					"pic/cloud_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			break;
		case 5:
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/�X�K�[��/�X�K�[���P�|�S.png");
			back[0][2] = LoadGraph("dat/img/�X�K�[��/�X�K�[���P�|�R.png");
			back[0][3] = LoadGraph("dat/img/�X�K�[��/�X�K�[���P�|�Q.png");
			back[0][4] = LoadGraph("dat/img/�X�K�[��/�X�K�[���P�|�P.png");
			

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/�X�K�[��/�X�K�[���Q�|�S.png");
			back[1][2] = LoadGraph("dat/img/�X�K�[��/�X�K�[���Q�|�R.png");
			back[1][3] = LoadGraph("dat/img/�X�K�[��/�X�K�[���Q�|�Q.png");
			back[1][4] = LoadGraph("dat/img/�X�K�[��/�X�K�[���Q�|�P.png");

			back[2][0] = LoadGraph("dat/img/�X�K�[��/�X�K�[���R�|�T.png");
			back[2][1] = LoadGraph("dat/img/�X�K�[��/�X�K�[���R�|�S.png");
			back[2][2] = LoadGraph("dat/img/�X�K�[��/�X�K�[���R�|�R.png");
			back[2][3] = LoadGraph("dat/img/�X�K�[��/�X�K�[���R�|�Q.png");
			back[2][4] = LoadGraph("dat/img/�X�K�[��/�X�K�[���R�|�P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/�X�K�[��/�X�K�[���S�|�S.png");
			back[3][2] = LoadGraph("dat/img/�X�K�[��/�X�K�[���S�|�R.png");
			back[3][3] = LoadGraph("dat/img/�X�K�[��/�X�K�[���S�|�Q.png");
			back[3][4] = LoadGraph("dat/img/�X�K�[��/�X�K�[���S�|�P.png");

			back[4][0] = 0;
			back[4][1] = LoadGraph("dat/img/�X�K�[��/�X�K�[���T�|�S.png");
			back[4][2] = LoadGraph("dat/img/�X�K�[��/�X�K�[���T�|�R.png");
			back[4][3] = LoadGraph("dat/img/�X�K�[��/�X�K�[���T�|�Q.png");
			back[4][4] = LoadGraph("dat/img/�X�K�[��/�X�K�[���T�|�P.png");

			back[5][0] = 0;
			back[5][1] = LoadGraph("dat/img/�X�K�[��/�X�K�[���U�|�S.png");
			back[5][2] = LoadGraph("dat/img/�X�K�[��/�X�K�[���U�|�R.png");
			back[5][3] = LoadGraph("dat/img/�X�K�[��/�X�K�[���U�|�Q.png");
			back[5][4] = LoadGraph("dat/img/�X�K�[��/�X�K�[���U�|�P.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/�X�K�[��/�X�K�[���V�|�S.png");
			back[6][2] = LoadGraph("dat/img/�X�K�[��/�X�K�[���V�|�R.png");
			back[6][3] = LoadGraph("dat/img/�X�K�[��/�X�K�[���V�|�Q.png");
			back[6][4] = LoadGraph("dat/img/�X�K�[��/�X�K�[���V�|�P.png");

			back[7][0] = LoadGraph("dat/img/�X�K�[��/�X�K�[���W�|�T.png");
			back[7][1] = LoadGraph("dat/img/�X�K�[��/�X�K�[���W�|�S.png");
			back[7][2] = LoadGraph("dat/img/�X�K�[��/�X�K�[���W�|�R.png");
			back[7][3] = LoadGraph("dat/img/�X�K�[��/�X�K�[���W�|�Q.png");
			back[7][4] = LoadGraph("dat/img/�X�K�[��/�X�K�[���W�|�P.png");

			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/�ŏ��̋��_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���P�G��P.png");
			g_castle[1][1] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���P�G��2.png");
			g_castle[1][2] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���P������.png");
	
			g_castle[2][0] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���Q�G��P.png");
			g_castle[2][1] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���Q�G��2.png");
			g_castle[2][2] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���Q������.png");
	
			g_castle[3][0] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���R�G��P.png");
			g_castle[3][1] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���R�G��2.png");
			g_castle[3][2] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���R������.png");
	
			g_castle[4][0] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���S�G��P.png");
			g_castle[4][1] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���S�G��2.png");
			g_castle[4][2] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���S������.png");
	
			g_castle[5][0] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���T�G��P.png");
			g_castle[5][1] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���T�G��2.png");
			g_castle[5][2] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���T������.png");
	
			g_castle[6][0] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���U�G��P.png");
			g_castle[6][1] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���U�G��2.png");
			g_castle[6][2] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���U������.png");
	
			g_castle[7][0] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���V�G��P.png");
			g_castle[7][1] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���V�G��Q.png");
			g_castle[7][2] = LoadGraph("dat/img/�V��/�X�K�[��/�X�K�[���V������.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/forest_s1",
					"pic/forest_s2",
					"pic/forest_s3",
					"pic/forest_s4",
					"pic/forest_s5",
					"pic/forest_s6",
					"pic/forest_s7",
					"pic/forest_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/�ʂ˂��ҋ@.png", ANI_TAMANEGI_WA, 4, 1, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_w);
			LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/�ʂ˂��U��.png", ANI_TAMANEGI_WA, 4, 1, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_a);
			LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/�ʂ˂��g�����X�t�H�[��.png", ANI_TAMANEGI_T, 4, 3, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_t);
			LoadDivGraph("dat/img/�G���j�b�g/�X�K�[��/�ʂ˂�re�g�����X�t�H�[��.png", ANI_TAMANEGI_TR, 6, 1, WID_TAMANEGI, HEI_TAMANEGI, g_tamanegi_tr);


			break;
		case 3:
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/���̒�/���̒��P�|�S.png");
			back[0][2] = LoadGraph("dat/img/���̒�/���̒��P�|�R.png");
			back[0][3] = LoadGraph("dat/img/���̒�/���̒��P�|�Q.png");
			back[0][4] = LoadGraph("dat/img/���̒�/���̒��P�|�P.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/���̒�/���̒��Q�|�S.png");
			back[1][2] = LoadGraph("dat/img/���̒�/���̒��Q�|�R.png");
			back[1][3] = LoadGraph("dat/img/���̒�/���̒��Q�|�Q.png");
			back[1][4] = LoadGraph("dat/img/���̒�/���̒��Q�|�P.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/���̒�/���̒��R�|�S.png");
			back[2][2] = LoadGraph("dat/img/���̒�/���̒��R�|�R.png");
			back[2][3] = LoadGraph("dat/img/���̒�/���̒��R�|�Q.png");
			back[2][4] = LoadGraph("dat/img/���̒�/���̒��R�|�P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/���̒�/���̒��S�|�S.png");
			back[3][2] = LoadGraph("dat/img/���̒�/���̒��S�|�R.png");
			back[3][3] = LoadGraph("dat/img/���̒�/���̒��S�|�Q.png");
			back[3][4] = LoadGraph("dat/img/���̒�/���̒��S�|�P.png");

			back[4][0] = LoadGraph("dat/img/���̒�/���̒��T�|�T.png");
			back[4][1] = LoadGraph("dat/img/���̒�/���̒��T�|�S.png");
			back[4][2] = LoadGraph("dat/img/���̒�/���̒��T�|�R.png");
			back[4][3] = LoadGraph("dat/img/���̒�/���̒��T�|�Q.png");
			back[4][4] = LoadGraph("dat/img/���̒�/���̒��T�|�P.png");

			back[5][0] = 0;
			back[5][1] = LoadGraph("dat/img/���̒�/���̒��U�|�S.png");
			back[5][2] = LoadGraph("dat/img/���̒�/���̒��U�|�R.png");
			back[5][3] = LoadGraph("dat/img/���̒�/���̒��U�|�Q.png");
			back[5][4] = LoadGraph("dat/img/���̒�/���̒��U�|�P.png");
			
			
			back[6][0] = 0;
			back[6][1] = LoadGraph("dat/img/���̒�/���̒��V�|�S.png");
			back[6][2] = LoadGraph("dat/img/���̒�/���̒��V�|�R.png");
			back[6][3] = LoadGraph("dat/img/���̒�/���̒��V�|�Q.png");
			back[6][4] = LoadGraph("dat/img/���̒�/���̒��V�|�P.png");

			back[7][0] = LoadGraph("dat/img/���̒�/���̒��W�|�T.png");
			back[7][1] = LoadGraph("dat/img/���̒�/���̒��W�|�S.png");
			back[7][2] = LoadGraph("dat/img/���̒�/���̒��W�|�R.png");
			back[7][3] = LoadGraph("dat/img/���̒�/���̒��W�|�Q.png");
			back[7][4] = LoadGraph("dat/img/���̒�/���̒��W�|�P.png");

			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/�ŏ��̋��_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/�V��/���̒�/���̒��P�G��P.png");
			g_castle[1][1] = LoadGraph("dat/img/�V��/���̒�/���̒��P�G��Q.png");
			g_castle[1][2] = LoadGraph("dat/img/�V��/���̒�/���̒��P������.png");
	
			g_castle[2][0] = LoadGraph("dat/img/�V��/���̒�/���̒��Q�G��P.png");
			g_castle[2][1] = LoadGraph("dat/img/�V��/���̒�/���̒��Q�G��Q.png");
			g_castle[2][2] = LoadGraph("dat/img/�V��/���̒�/���̒��Q������.png");
	
			g_castle[3][0] = LoadGraph("dat/img/�V��/���̒�/���̒��R�G��P.png");
			g_castle[3][1] = LoadGraph("dat/img/�V��/���̒�/���̒��R�G��Q.png");
			g_castle[3][2] = LoadGraph("dat/img/�V��/���̒�/���̒��R������.png");
	
			g_castle[4][0] = LoadGraph("dat/img/�V��/���̒�/���̒��S�G��P.png");
			g_castle[4][1] = LoadGraph("dat/img/�V��/���̒�/���̒��S�G��Q.png");
			g_castle[4][2] = LoadGraph("dat/img/�V��/���̒�/���̒��S������.png");
	
			g_castle[5][0] = LoadGraph("dat/img/�V��/���̒�/���̒��T�G��P.png");
			g_castle[5][1] = LoadGraph("dat/img/�V��/���̒�/���̒��T�G��Q.png");
			g_castle[5][2] = LoadGraph("dat/img/�V��/���̒�/���̒��T������.png");
	
			g_castle[6][0] = LoadGraph("dat/img/�V��/���̒�/���̒��U�G��P.png");
			g_castle[6][1] = LoadGraph("dat/img/�V��/���̒�/���̒��U�G��P.png");
			g_castle[6][2] = LoadGraph("dat/img/�V��/���̒�/���̒��U������.png");
	
			g_castle[7][0] = LoadGraph("dat/img/�V��/���̒�/���̒��V�G��P.png");
			g_castle[7][1] = LoadGraph("dat/img/�V��/���̒�/���̒��V�G��Q.png");
			g_castle[7][2] = LoadGraph("dat/img/�V��/���̒�/���̒��V������.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/water_s1",
					"pic/water_s2",
					"pic/water_s3",
					"pic/water_s4",
					"pic/water_s5",
					"pic/water_s6",
					"pic/water_s7",
					"pic/water_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			LoadDivGraph("dat/img/�G���j�b�g/���̒�/����̋����ҋ@.png", ANI_GUUZO_W, 4, 1, WID_GUUZO, HEI_GUUZO, g_guuzo_w);
			LoadDivGraph("dat/img/�G���j�b�g/���̒�/����̋����U��1.png", ANI_GUUZO_A, 2, 1, WID_GUUZO, HEI_GUUZO, g_guuzo_a1);
			LoadDivGraph("dat/img/�G���j�b�g/���̒�/����̋����U��2.png", ANI_GUUZO_A, 2, 1, WID_GUUZO, HEI_GUUZO, g_guuzo_a2);


			break;
		case 6:
			back[0][0] = 0;
			back[0][1] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�P�|�S.png");
			back[0][2] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�P�|�R.png");
			back[0][3] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�P�|�Q.png");
			back[0][4] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�P�|�P.png");

			back[1][0] = 0;
			back[1][1] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�Q�|�S.png");
			back[1][2] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�Q�|�R.png");
			back[1][3] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�Q�|�Q.png");
			back[1][4] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�Q�|�P.png");

			back[2][0] = 0;
			back[2][1] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�R�|�S.png");
			back[2][2] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�R�|�R.png");
			back[2][3] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�R�|�Q.png");
			back[2][4] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�R�|�P.png");

			back[3][0] = 0;
			back[3][1] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�S�|�S.png");
			back[3][2] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�S�|�R.png");
			back[3][3] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�S�|�Q.png");
			back[3][4] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�S�|�P.png");

			back[4][0] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�T�|�T.png");
			back[4][1] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�T�|�S.png");
			back[4][2] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�T�|�R.png");
			back[4][3] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�T�|�Q.png");
			back[4][4] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�T�|�P.png");

			back[5][0] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�U�|�T.png");
			back[5][1] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�U�|�S.png");
			back[5][2] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�U�|�R.png");
			back[5][3] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�U�|�Q.png");
			back[5][4] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�U�|�P.png");
			
			
			back[6][0] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�V�|�T.png");
			back[6][1] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�V�|�S.png");
			back[6][2] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�V�|�R.png");
			back[6][3] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�V�|�Q.png");
			back[6][4] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B�V�|�P.png");

			back[7][0] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B8-5.png");
			back[7][1] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B8-4.png");
			back[7][2] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B8-3.png");
			back[7][3] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B8-2.png");
			back[7][4] = LoadGraph("dat/img/���J�V�e�B/���J�V�e�B8-1.png");

			g_castle[0][0] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][1] = LoadGraph("dat/img/sirodummy.png");
			g_castle[0][2] = LoadGraph("dat/img/�ŏ��̋��_.png");
	
			g_castle[1][0] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�P�G��1.png");
			g_castle[1][1] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�P�G��2.png");
			g_castle[1][2] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�P������.png");
	
			g_castle[2][0] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�Q�G��P.png");
			g_castle[2][1] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�Q�G��Q.png");
			g_castle[2][2] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�Q������.png");
	
			g_castle[3][0] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�R�G��1.png");
			g_castle[3][1] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�R�G��2.png");
			g_castle[3][2] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�R������.png");
	
			g_castle[4][0] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�S�G��1.png");
			g_castle[4][1] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�S�G��2.png");
			g_castle[4][2] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�S������.png");
	
			g_castle[5][0] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�T�G��1.png");
			g_castle[5][1] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�T�G��2.png");
			g_castle[5][2] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�T������.png");
	
			g_castle[6][0] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�U�G��1.png");
			g_castle[6][1] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�U�G��2.png");
			g_castle[6][2] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�U������.png");
	
			g_castle[7][0] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�V�G��1.png");
			g_castle[7][1] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�V�G��2.png");
			g_castle[7][2] = LoadGraph("dat/img/�V��/���J�V�e�B/���J�V�e�B�V������.png");
			{
				string shiro_icon_name[]={
					"pic/first_ufo",
					"pic/meka_s1",
					"pic/meka_s2",
					"pic/meka_s3",
					"pic/meka_s4",
					"pic/meka_s5",
					"pic/meka_s6",
					"pic/meka_s7",
					"pic/meka_s8",
				};
				for(int i=0;i<array_length(shiro_icon_name);i++){
					g_shiro_icon[i][0]= LoadGraph((shiro_icon_name[i]+"_1.png").c_str());
					g_shiro_icon[i][1]= LoadGraph((shiro_icon_name[i]+"_2.png").c_str());
				}
			}

			LoadDivGraph("dat/img/�G���j�b�g/���J�V�e�B/���낢����w.png", ANI_KUROSHIMI_W, ANI_KUROSHIMI_W, 1, WID_KUROSHIMI, HEI_KUROSHIMI, g_kuroshimi_w);
			LoadDivGraph("dat/img/�G���j�b�g/���J�V�e�B/���낢����a.png", ANI_KUROSHIMI_A, ANI_KUROSHIMI_A, 1, WID_KUROSHIMI, HEI_KUROSHIMI, g_kuroshimi_a);


			break;

		default:
			printfDx("initStageERROR!!");
			break;
		}
		SetUseASyncLoadFlag( FALSE ); // �񓯊��ǂݍ��݃t���OON
	}

	void Images::releaseStage(){
			
		
		for(int i=0;i<8;i++){
			for(int j=0;j<5;j++){
				DeleteGraph(back[i][j]);
			}
		}

		for(int i=0;i<9;i++){
			for(int j=0;j<3;j++){
				DeleteGraph(g_castle[i][j]);
			}
		}

	
	}

	string Images::getStageSummary(int sid){
	
		string s[]={
		"",
		"���Ă��̒n�Ő푈��������",
		"UFO�͉_�ɂԂ���",
		"�������pUFO",
		"�R�̉��ɂ͎傪����ł���Ƃ���",
		"�����q�͐X�K�[�����M���I",
		"�̋�"	};
	return s[sid];
}

	
	string Images::getStageName(int sid){
	
		string s[]={
		"",
		"�r��",
		"�_�̏�",
		"����",
		"�ጴ",
		"�X��",
		"�@�B�X"	};
	return s[sid];
}
