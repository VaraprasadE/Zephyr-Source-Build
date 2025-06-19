/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "ui_Aircon.h"
static bool ui_aircon_swing_state = false;
extern const lv_img_dsc_t * scrAircon_aimgAirconCool_imgs[6];
uint8_t smog_status = 1;
uint8_t light_status = 0;
extern const lv_img_dsc_t * scrOven_animimg_Door_imgs[8];
static bool ui_oven_light_state = false;
static bool ui_oven_door_state = false;

static void scrHome_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_image_set_pivot(guider_ui.scrHome_imgFan, 10, 10);
        ui_animation(guider_ui.scrHome_imgFan, 1500, 0, lv_image_get_rotation(guider_ui.scrHome_imgFan), 360*10, &lv_anim_path_linear, LV_ANIM_REPEAT_INFINITE, 0, 0, 0, (lv_anim_exec_xcb_t)lv_image_set_rotation, NULL, NULL, NULL);
        lv_img_set_pivot(guider_ui.scrHome_imgFan, lv_obj_get_width(guider_ui.scrHome_imgFan)/2,  lv_obj_get_height(guider_ui.scrHome_imgFan)/2);
        break;
    }
    default:
        break;
    }
}

static void scrHome_btnOven_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrOven, guider_ui.scrOven_del, &guider_ui.scrHome_del, setup_scr_scrOven, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void scrHome_btnHood_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHood, guider_ui.scrHood_del, &guider_ui.scrHome_del, setup_scr_scrHood, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void scrHome_btnAircon_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrAircon, guider_ui.scrAircon_del, &guider_ui.scrHome_del, setup_scr_scrAircon, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_scrHome (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrHome, scrHome_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHome_btnOven, scrHome_btnOven_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHome_btnHood, scrHome_btnHood_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHome_btnAircon, scrHome_btnAircon_event_handler, LV_EVENT_ALL, ui);
}

static void scrAircon_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_image_set_pivot(guider_ui.scrAircon_imgFan, 15, 15);
        ui_animation(guider_ui.scrAircon_imgFan, 2000, 0, lv_image_get_rotation(guider_ui.scrAircon_imgFan), 360*10, &lv_anim_path_linear, LV_ANIM_REPEAT_INFINITE, 0, 0, 0, (lv_anim_exec_xcb_t)lv_image_set_rotation, NULL, NULL, NULL);
        lv_img_set_pivot(guider_ui.scrAircon_imgFan, lv_obj_get_width(guider_ui.scrAircon_imgFan)/2,  lv_obj_get_height(guider_ui.scrAircon_imgFan)/2);
        break;
    }
    default:
        break;
    }
}

static void scrAircon_btnAirconBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrAircon_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void scrAircon_btnTempDown_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_aircon_update_temp (0, kAIRCON_TempDown);
        break;
    }
    default:
        break;
    }
}

static void scrAircon_btnTempUp_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_aircon_update_temp (0, kAIRCON_TempUp);
        break;
    }
    default:
        break;
    }
}

static void scrAircon_btnTimerDown_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_aircon_update_timer(0,kAIRCON_TimerDown);
        break;
    }
    default:
        break;
    }
}

static void scrAircon_btnTimerUp_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_aircon_update_timer(0,kAIRCON_TimerUp);
        break;
    }
    default:
        break;
    }
}

static void scrAircon_rollerMode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * obj = lv_event_get_target(e);
        uint16_t value = lv_roller_get_selected(obj);

        switch (value) {
        case (0):
        {
            lv_obj_set_style_opa(guider_ui.scrAircon_aimgAirconCool, 0, 0);
            lv_label_set_text(guider_ui.scrAircon_labelCompStat, "ON");
            lv_img_set_src(guider_ui.scrAircon_imgComp, &_icn_cool_RGB565A8_26x26);
            break;
        }
        case (1):
        {
            lv_obj_set_style_opa(guider_ui.scrAircon_aimgAirconCool, 255, 0);
            lv_label_set_text(guider_ui.scrAircon_labelCompStat, "ON");
            lv_img_set_src(guider_ui.scrAircon_imgComp, &_icn_dry_RGB565A8_26x26);
            break;
        }
        case (2):
        {
            lv_obj_set_style_opa(guider_ui.scrAircon_aimgAirconCool, 0, 0);
            lv_label_set_text(guider_ui.scrAircon_labelCompStat, "OFF");
            lv_img_set_src(guider_ui.scrAircon_imgComp, &_icn_fan_low_RGB565A8_26x26);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void scrAircon_btnSwing_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (!ui_aircon_swing_state) {
            lv_obj_set_style_opa(guider_ui.scrAircon_aimgAirconSwing, 255, 0);
            lv_animimg_start(guider_ui.scrAircon_aimgAirconSwing);
            ui_aircon_swing_state = true;
            lv_label_set_text(guider_ui.scrAircon_btnSwing_label, "OFF");
        } else {
            lv_obj_set_style_opa(guider_ui.scrAircon_aimgAirconSwing, 0, 0);
            ui_aircon_swing_state = false;
            lv_label_set_text(guider_ui.scrAircon_btnSwing_label, "ON");
        }
        break;
    }
    default:
        break;
    }
}

static void scrAircon_sliderFan_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * obj = lv_event_get_target(e);
        uint16_t value = lv_slider_get_value(obj);

        switch (value) {
        case (0):
        {
            lv_label_set_text(guider_ui.scrAircon_labelFanStat, "LOW");
            lv_img_set_src(guider_ui.scrAircon_imgFanSt, &_icn_fan_low_RGB565A8_26x26);
            break;
        }
        case (1):
        {
            lv_label_set_text(guider_ui.scrAircon_labelFanStat, "MEDIUM");
            lv_img_set_src(guider_ui.scrAircon_imgFanSt, &_aircon_menu_fan_1_RGB565A8_26x26);
            break;
        }
        case (2):
        {
            lv_label_set_text(guider_ui.scrAircon_labelFanStat, "HIGH");
            lv_img_set_src(guider_ui.scrAircon_imgFanSt, &_icn_fan_high_RGB565A8_26x26);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_scrAircon (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrAircon, scrAircon_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrAircon_btnAirconBack, scrAircon_btnAirconBack_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrAircon_btnTempDown, scrAircon_btnTempDown_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrAircon_btnTempUp, scrAircon_btnTempUp_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrAircon_btnTimerDown, scrAircon_btnTimerDown_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrAircon_btnTimerUp, scrAircon_btnTimerUp_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrAircon_rollerMode, scrAircon_rollerMode_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrAircon_btnSwing, scrAircon_btnSwing_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrAircon_sliderFan, scrAircon_sliderFan_event_handler, LV_EVENT_ALL, ui);
}

static void scrHood_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.scrHood_imgSmog2, 1600, 5000, lv_obj_get_y(guider_ui.scrHood_imgSmog2), -50, &lv_anim_path_linear, -1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.scrHood_imgSmog1, 1500, 5000, lv_obj_get_y(guider_ui.scrHood_imgSmog1), -40, &lv_anim_path_linear, -1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrHood_btnHoodBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrHood_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void scrHood_labelHoodCtrl_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (smog_status) {
            smog_status = 0;
            lv_label_set_text(guider_ui.scrHood_labelHoodCtrl, "ON");
            lv_obj_remove_flag(guider_ui.scrHood_imgSmog1, LV_OBJ_FLAG_HIDDEN);
        } else {
            smog_status = 1;
            lv_label_set_text(guider_ui.scrHood_labelHoodCtrl, "OFF");
            lv_obj_add_flag(guider_ui.scrHood_imgSmog1, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.scrHood_imgSmog2, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    }
    default:
        break;
    }
}

static void scrHood_labelLightCtrl_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (light_status) {
            light_status = 0;
            lv_label_set_text(guider_ui.scrHood_labelLightCtrl, "OFF");
            lv_obj_add_flag(guider_ui.scrHood_imgHoodLight, LV_OBJ_FLAG_HIDDEN);
        } else {
            light_status = 1;
            lv_label_set_text(guider_ui.scrHood_labelLightCtrl, "ON");
            lv_obj_remove_flag(guider_ui.scrHood_imgHoodLight, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    }
    default:
        break;
    }
}

static void scrHood_rollerFanCtrl_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        if(smog_status == 0) {
            uint16_t id = lv_roller_get_selected(guider_ui.scrHood_rollerFanCtrl);
            switch (id)
            {
            case 0:
                lv_obj_clear_flag(guider_ui.scrHood_imgSmog1, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.scrHood_imgSmog2, LV_OBJ_FLAG_HIDDEN);
                break;
            case 1:
                lv_obj_add_flag(guider_ui.scrHood_imgSmog1, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.scrHood_imgSmog2, LV_OBJ_FLAG_HIDDEN);
                break;
            case 2:
                lv_obj_clear_flag(guider_ui.scrHood_imgSmog1, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.scrHood_imgSmog2, LV_OBJ_FLAG_HIDDEN);
                break;
            default:
                break;
            }
        }
        break;
    }
    default:
        break;
    }
}

void events_init_scrHood (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrHood, scrHood_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHood_btnHoodBack, scrHood_btnHoodBack_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHood_labelHoodCtrl, scrHood_labelHoodCtrl_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHood_labelLightCtrl, scrHood_labelLightCtrl_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHood_rollerFanCtrl, scrHood_rollerFanCtrl_event_handler, LV_EVENT_ALL, ui);
}

static void scrOven_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_obj_remove_flag(guider_ui.scrOven_Group_Oven, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_opa(guider_ui.scrOven_animimg_Door, 0, 0);
        lv_obj_set_style_opa(guider_ui.scrOven_animimg_Fan, 0, 0);
        lv_obj_set_style_text_color(guider_ui.scrOven_Group_TarTemp, lv_color_hex(0xff9110), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(guider_ui.scrOven_Group_TarTemp, &lv_font_montserratMedium_12, 0);
        lv_obj_set_style_text_color(guider_ui.scrOven_Group_Timer, lv_color_hex(0xff9110), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(guider_ui.scrOven_Group_Timer, &lv_font_montserratMedium_12, 0);
        break;
    }
    default:
        break;
    }
}

static void scrOven_Btn_State_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_RELEASED:
    {
        if (!ui_oven_light_state) {
            lv_obj_set_style_opa(guider_ui.scrOven_animimg_Door, 255, 0);
            ui_oven_light_state = true;
            lv_label_set_text(guider_ui.scrOven_Label_CurrStat, "ON");
            lv_label_set_text(guider_ui.scrOven_Btn_State_label, "STOP");
        } else {
            ui_oven_light_state = false;
            ui_oven_door_state = false;
            lv_img_set_src(guider_ui.scrOven_animimg_Door, scrOven_animimg_Door_imgs[0]);
            lv_label_set_text(guider_ui.scrOven_Label_CurrStat, "OFF");
            lv_label_set_text(guider_ui.scrOven_Btn_State_label, "START");
            lv_obj_set_style_opa(guider_ui.scrOven_animimg_Door, 0, 0);
            lv_obj_set_style_opa(guider_ui.scrOven_animimg_Fan, 0, 0);
        }
        break;
    }
    default:
        break;
    }
}

static void scrOven_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrOven_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void scrOven_btnOpen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (!ui_oven_door_state && ui_oven_light_state) {
            lv_obj_set_style_opa(guider_ui.scrOven_animimg_Fan, 0, 0);
            lv_animimg_set_src(guider_ui.scrOven_animimg_Door, (const void **) scrOven_animimg_Door_imgs, 8);
            lv_animimg_start(guider_ui.scrOven_animimg_Door);
            ui_oven_door_state = true;
        } else if (ui_oven_light_state) {
            lv_obj_set_style_opa(guider_ui.scrOven_animimg_Fan, 255, 0);
            lv_animimg_set_src(guider_ui.scrOven_animimg_Door, (const void **) scrOven_animimg_Door_imgs, 8);
            lv_animimg_start(guider_ui.scrOven_animimg_Door);
            ui_oven_door_state = false;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_scrOven (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrOven, scrOven_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrOven_Btn_State, scrOven_Btn_State_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrOven_btnBack, scrOven_btnBack_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrOven_btnOpen, scrOven_btnOpen_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
