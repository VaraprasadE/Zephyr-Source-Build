/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *scrHome;
	bool scrHome_del;
	lv_obj_t *scrHome_labelAirTemp;
	lv_obj_t *scrHome_labelOvenTemp;
	lv_obj_t *scrHome_imgLight;
	lv_obj_t *scrHome_imgFan;
	lv_obj_t *scrHome_labelFanSt;
	lv_obj_t *scrHome_labelLightSt;
	lv_obj_t *scrHome_labelFanMode;
	lv_obj_t *scrHome_btnOven;
	lv_obj_t *scrHome_btnOven_label;
	lv_obj_t *scrHome_btnHood;
	lv_obj_t *scrHome_btnHood_label;
	lv_obj_t *scrHome_btnAircon;
	lv_obj_t *scrHome_btnAircon_label;
	lv_obj_t *scrHome_label_name;
	lv_obj_t *scrHome_digital_clockTime;
	lv_obj_t *scrHome_img_logo;
	lv_obj_t *scrAircon;
	bool scrAircon_del;
	lv_obj_t *scrAircon_imgicnMedium;
	lv_obj_t *scrAircon_imgFanHigh;
	lv_obj_t *scrAircon_btnAirconBack;
	lv_obj_t *scrAircon_btnAirconBack_label;
	lv_obj_t *scrAircon_contAirconCtrl;
	lv_obj_t *scrAircon_labelSetTemp;
	lv_obj_t *scrAircon_labelAirconTemp;
	lv_obj_t *scrAircon_labelCen;
	lv_obj_t *scrAircon_btnTempDown;
	lv_obj_t *scrAircon_btnTempDown_label;
	lv_obj_t *scrAircon_btnTempUp;
	lv_obj_t *scrAircon_btnTempUp_label;
	lv_obj_t *scrAircon_labelTimer;
	lv_obj_t *scrAircon_labelTimerHour;
	lv_obj_t *scrAircon_labelTimerPoints;
	lv_obj_t *scrAircon_labelTimerMin;
	lv_obj_t *scrAircon_btnTimerDown;
	lv_obj_t *scrAircon_btnTimerDown_label;
	lv_obj_t *scrAircon_btnTimerUp;
	lv_obj_t *scrAircon_btnTimerUp_label;
	lv_obj_t *scrAircon_rollerMode;
	lv_obj_t *scrAircon_labelMode;
	lv_obj_t *scrAircon_lineSepTempTimer;
	lv_obj_t *scrAircon_lineSepTimerMode;
	lv_obj_t *scrAircon_lineSepModeSwingFan;
	lv_obj_t *scrAircon_labelComp;
	lv_obj_t *scrAircon_labelCompStat;
	lv_obj_t *scrAircon_labelFan;
	lv_obj_t *scrAircon_labelFanStat;
	lv_obj_t *scrAircon_btnSwing;
	lv_obj_t *scrAircon_btnSwing_label;
	lv_obj_t *scrAircon_labelSwing;
	lv_obj_t *scrAircon_labelFanSpeed;
	lv_obj_t *scrAircon_imgCompFan;
	lv_obj_t *scrAircon_imgCompDry;
	lv_obj_t *scrAircon_LabelLow;
	lv_obj_t *scrAircon_LabelMedium;
	lv_obj_t *scrAircon_LabelHigh;
	lv_obj_t *scrAircon_lineTitle;
	lv_obj_t *scrAircon_imgComp;
	lv_obj_t *scrAircon_lineSepRollerCompFan;
	lv_obj_t *scrAircon_labelAirconTitle;
	lv_obj_t *scrAircon_imgFanSt;
	lv_obj_t *scrAircon_sliderFan;
	lv_obj_t *scrAircon_lineSwingFan;
	lv_obj_t *scrAircon_aimgAirconSwing;
	lv_obj_t *scrAircon_aimgAirconCool;
	lv_obj_t *scrAircon_imgFan;
	lv_obj_t *scrHood;
	bool scrHood_del;
	lv_obj_t *scrHood_imgHoodBg;
	lv_obj_t *scrHood_btnHoodBack;
	lv_obj_t *scrHood_btnHoodBack_label;
	lv_obj_t *scrHood_imgHoodLight;
	lv_obj_t *scrHood_contHoodConsole;
	lv_obj_t *scrHood_barHoodEdge;
	lv_obj_t *scrHood_labelHoodLight;
	lv_obj_t *scrHood_labelHoodFan;
	lv_obj_t *scrHood_labelHoodCtrl;
	lv_obj_t *scrHood_labelLightCtrl;
	lv_obj_t *scrHood_rollerFanCtrl;
	lv_obj_t *scrHood_cont_imgSmog;
	lv_obj_t *scrHood_imgSmog1;
	lv_obj_t *scrHood_imgSmog2;
	lv_obj_t *scrOven;
	bool scrOven_del;
	lv_obj_t *scrOven_animimg_Door;
	lv_obj_t *scrOven_animimg_Fan;
	lv_obj_t *scrOven_Group_Oven;
	lv_obj_t *scrOven_line;
	lv_obj_t *scrOven_Label_CurrTemp;
	lv_obj_t *scrOven_line_5;
	lv_obj_t *scrOven_line_4;
	lv_obj_t *scrOven_line_3;
	lv_obj_t *scrOven_line_2;
	lv_obj_t *scrOven_line_1;
	lv_obj_t *scrOven_Label_Temp;
	lv_obj_t *scrOven_Label_Cen;
	lv_obj_t *scrOven_Label_Status;
	lv_obj_t *scrOven_Label_CurrStat;
	lv_obj_t *scrOven_Label_Time;
	lv_obj_t *scrOven_Bar_Time;
	lv_obj_t *scrOven_Label_Mode;
	lv_obj_t *scrOven_Btn_State;
	lv_obj_t *scrOven_Btn_State_label;
	lv_obj_t *scrOven_Label_Settings;
	lv_obj_t *scrOven_Label_TimeLeft;
	lv_obj_t *scrOven_Label_Min;
	lv_obj_t *scrOven_Group_TarTemp;
	lv_obj_t *scrOven_Img_TempWheel;
	lv_obj_t *scrOven_Label_SelTemp;
	lv_obj_t *scrOven_Label_TarCen;
	lv_obj_t *scrOven_Group_Timer;
	lv_obj_t *scrOven_Img_TimerWheel;
	lv_obj_t *scrOven_Label_SelTimer;
	lv_obj_t *scrOven_Label_TimerSel;
	lv_obj_t *scrOven_Tile_Mode;
	lv_obj_t *scrOven_Tile_Mode_Mode_1;
	lv_obj_t *scrOven_Tile_Mode_Mode_2;
	lv_obj_t *scrOven_Tile_Mode_Mode_3;
	lv_obj_t *scrOven_Tile_Mode_Mode_4;
	lv_obj_t *scrOven_Tile_Mode_Mode_5;
	lv_obj_t *scrOven_Tile_Mode_Mode_6;
	lv_obj_t *scrOven_Tile_Mode_Mode_7;
	lv_obj_t *scrOven_Tile_Mode_Mode_8;
	lv_obj_t *scrOven_Tile_Mode_Mode_9;
	lv_obj_t *scrOven_Img_Mode1;
	lv_obj_t *scrOven_Label_Mode1;
	lv_obj_t *scrOven_Img_Mode2;
	lv_obj_t *scrOven_Label_Mode2;
	lv_obj_t *scrOven_Label_Mode3;
	lv_obj_t *scrOven_Img_Mode3;
	lv_obj_t *scrOven_Img_Mode4;
	lv_obj_t *scrOven_Label_Mode4;
	lv_obj_t *scrOven_Img_Mode5;
	lv_obj_t *scrOven_Label_Mode5;
	lv_obj_t *scrOven_Img_Mode6;
	lv_obj_t *scrOven_Label_Mode6;
	lv_obj_t *scrOven_Img_Mode7;
	lv_obj_t *scrOven_Label_Mode7;
	lv_obj_t *scrOven_Img_Mode8;
	lv_obj_t *scrOven_Label_Mode8;
	lv_obj_t *scrOven_Img_Mode9;
	lv_obj_t *scrOven_Label_Mode9;
	lv_obj_t *scrOven_btnBack;
	lv_obj_t *scrOven_btnBack_label;
	lv_obj_t *scrOven_labelOven;
	lv_obj_t *scrOven_btnOpen;
	lv_obj_t *scrOven_btnOpen_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_scrHome(lv_ui *ui);
void setup_scr_scrAircon(lv_ui *ui);
void setup_scr_scrHood(lv_ui *ui);
void setup_scr_scrOven(lv_ui *ui);

LV_IMAGE_DECLARE(_main_Screen_RGB565A8_1280x800);
LV_IMAGE_DECLARE(_hood_menu_light_RGB565A8_440x244);
LV_IMAGE_DECLARE(_aircon_menu_fan_1_RGB565A8_53x53);
LV_IMAGE_DECLARE(_nxp_logo_RGB565A8_261x97);

LV_IMAGE_DECLARE(_aircon_bg_RGB565A8_1280x800);
LV_IMAGE_DECLARE(_aircon_menu_fan_1_RGB565A8_26x26);
LV_IMAGE_DECLARE(_icn_fan_high_RGB565A8_26x26);

LV_IMAGE_DECLARE(_back_button_RGB565A8_205x150);
LV_IMAGE_DECLARE(_icn_fan_low_RGB565A8_26x26);
LV_IMAGE_DECLARE(_icn_dry_RGB565A8_26x26);
LV_IMAGE_DECLARE(_icn_cool_RGB565A8_26x26);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_00);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_01);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_02);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_03);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_04);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_05);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_06);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_07);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_08);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_09);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_10);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_11);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_12);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_13);
LV_IMAGE_DECLARE(scrAircon_aimgAirconSwingaircon_swing_14);
LV_IMAGE_DECLARE(scrAircon_aimgAirconCoolaircon_cool_00);
LV_IMAGE_DECLARE(scrAircon_aimgAirconCoolaircon_cool_01);
LV_IMAGE_DECLARE(scrAircon_aimgAirconCoolaircon_cool_02);
LV_IMAGE_DECLARE(scrAircon_aimgAirconCoolaircon_cool_03);
LV_IMAGE_DECLARE(scrAircon_aimgAirconCoolaircon_cool_04);
LV_IMAGE_DECLARE(scrAircon_aimgAirconCoolaircon_cool_05);
LV_IMAGE_DECLARE(_aircon_menu_fan_1_RGB565A8_80x80);
LV_IMAGE_DECLARE(_hood_bg_RGB565A8_1280x800);
LV_IMAGE_DECLARE(_hood_light_RGB565A8_901x511);
LV_IMAGE_DECLARE(_smog_1_RGB565A8_82x450);
LV_IMAGE_DECLARE(_smog_2_RGB565A8_101x491);

LV_IMAGE_DECLARE(_oven_bg_RGB565A8_1280x800);
LV_IMAGE_DECLARE(scrOven_animimg_Dooroven_door_00);
LV_IMAGE_DECLARE(scrOven_animimg_Dooroven_door_01);
LV_IMAGE_DECLARE(scrOven_animimg_Dooroven_door_02);
LV_IMAGE_DECLARE(scrOven_animimg_Dooroven_door_03);
LV_IMAGE_DECLARE(scrOven_animimg_Dooroven_door_04);
LV_IMAGE_DECLARE(scrOven_animimg_Dooroven_door_05);
LV_IMAGE_DECLARE(scrOven_animimg_Dooroven_door_06);
LV_IMAGE_DECLARE(scrOven_animimg_Dooroven_door_07);
LV_IMAGE_DECLARE(scrOven_animimg_Fanoven_fan_light_0);
LV_IMAGE_DECLARE(scrOven_animimg_Fanoven_fan_light_1);
LV_IMAGE_DECLARE(scrOven_animimg_Fanoven_fan_light_2);
LV_IMAGE_DECLARE(scrOven_animimg_Fanoven_fan_light_3);
LV_IMAGE_DECLARE(_BTN_oven_RGB565A8_133x55);
LV_IMAGE_DECLARE(_wheel_bg_RGB565A8_149x285);
LV_IMAGE_DECLARE(_wheel_bg_2_RGB565A8_149x285);
LV_IMAGE_DECLARE(_icn_oven_fan_rear_RGB565A8_61x61);
LV_IMAGE_DECLARE(_icn_oven_upper_lower_RGB565A8_61x61);
LV_IMAGE_DECLARE(_icn_oven_fan_upper_lower_RGB565A8_61x61);
LV_IMAGE_DECLARE(_icn_oven_fan_lower_RGB565A8_61x61);
LV_IMAGE_DECLARE(_icn_oven_gril_RGB565A8_61x61);
LV_IMAGE_DECLARE(_icn_oven_fan_gril_RGB565A8_61x61);
LV_IMAGE_DECLARE(_icn_oven_upper_RGB565A8_61x61);
LV_IMAGE_DECLARE(_icn_oven_lower_RGB565A8_61x61);
LV_IMAGE_DECLARE(_icn_oven_defrost_RGB565A8_61x61);

LV_FONT_DECLARE(lv_font_montserratMedium_85)
LV_FONT_DECLARE(lv_font_montserratMedium_42)
LV_FONT_DECLARE(lv_font_montserratMedium_120)
LV_FONT_DECLARE(lv_font_montserratMedium_26)
LV_FONT_DECLARE(lv_font_montserratMedium_32)
LV_FONT_DECLARE(lv_font_arial_93)
LV_FONT_DECLARE(lv_font_montserratMedium_37)
LV_FONT_DECLARE(lv_font_montserratMedium_90)
LV_FONT_DECLARE(lv_font_montserratMedium_40)
LV_FONT_DECLARE(lv_font_montserratMedium_58)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_26)


#ifdef __cplusplus
}
#endif
#endif
