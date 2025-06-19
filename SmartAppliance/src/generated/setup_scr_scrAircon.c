/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_scrAircon(lv_ui *ui)
{
    //Write codes scrAircon
    ui->scrAircon = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrAircon, 1280, 800);
    lv_obj_set_scrollbar_mode(ui->scrAircon, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrAircon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->scrAircon, &_aircon_bg_RGB565A8_1280x800, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->scrAircon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->scrAircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_imgicnMedium
    ui->scrAircon_imgicnMedium = lv_image_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_imgicnMedium, 1154, 738);
    lv_obj_set_size(ui->scrAircon_imgicnMedium, 26, 26);
    lv_obj_add_flag(ui->scrAircon_imgicnMedium, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scrAircon_imgicnMedium, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrAircon_imgicnMedium, &_aircon_menu_fan_1_RGB565A8_26x26);
    lv_image_set_pivot(ui->scrAircon_imgicnMedium, 50,57);
    lv_image_set_rotation(ui->scrAircon_imgicnMedium, 0);

    //Write style for scrAircon_imgicnMedium, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrAircon_imgicnMedium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrAircon_imgicnMedium, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_imgFanHigh
    ui->scrAircon_imgFanHigh = lv_image_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_imgFanHigh, 1066, 667);
    lv_obj_set_size(ui->scrAircon_imgFanHigh, 26, 26);
    lv_obj_add_flag(ui->scrAircon_imgFanHigh, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scrAircon_imgFanHigh, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrAircon_imgFanHigh, &_icn_fan_high_RGB565A8_26x26);
    lv_image_set_pivot(ui->scrAircon_imgFanHigh, 50,57);
    lv_image_set_rotation(ui->scrAircon_imgFanHigh, 0);

    //Write style for scrAircon_imgFanHigh, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrAircon_imgFanHigh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrAircon_imgFanHigh, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_btnAirconBack
    ui->scrAircon_btnAirconBack = lv_button_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_btnAirconBack, 0, 5);
    lv_obj_set_size(ui->scrAircon_btnAirconBack, 205, 150);
    ui->scrAircon_btnAirconBack_label = lv_label_create(ui->scrAircon_btnAirconBack);
    lv_label_set_text(ui->scrAircon_btnAirconBack_label, "");
    lv_label_set_long_mode(ui->scrAircon_btnAirconBack_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrAircon_btnAirconBack_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrAircon_btnAirconBack, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrAircon_btnAirconBack_label, LV_PCT(100));

    //Write style for scrAircon_btnAirconBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_btnAirconBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrAircon_btnAirconBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_btnAirconBack, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_btnAirconBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->scrAircon_btnAirconBack, &_back_button_RGB565A8_205x150, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->scrAircon_btnAirconBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->scrAircon_btnAirconBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_btnAirconBack, lv_color_hex(0xadff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_btnAirconBack, &lv_font_montserratMedium_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_btnAirconBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_btnAirconBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_contAirconCtrl
    ui->scrAircon_contAirconCtrl = lv_obj_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_contAirconCtrl, 802, 5);
    lv_obj_set_size(ui->scrAircon_contAirconCtrl, 469, 791);
    lv_obj_set_scrollbar_mode(ui->scrAircon_contAirconCtrl, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrAircon_contAirconCtrl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_contAirconCtrl, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrAircon_contAirconCtrl, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrAircon_contAirconCtrl, lv_color_hex(0x4A4C4A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrAircon_contAirconCtrl, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_contAirconCtrl, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_contAirconCtrl, 250, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_contAirconCtrl, lv_color_hex(0x242424), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_contAirconCtrl, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_contAirconCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_contAirconCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_contAirconCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_contAirconCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_contAirconCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelSetTemp
    ui->scrAircon_labelSetTemp = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelSetTemp, 21, 29);
    lv_obj_set_size(ui->scrAircon_labelSetTemp, 426, 41);
    lv_label_set_text(ui->scrAircon_labelSetTemp, "SET  TEMPERATURE");
    lv_label_set_long_mode(ui->scrAircon_labelSetTemp, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelSetTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelSetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelSetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelSetTemp, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelSetTemp, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelSetTemp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelSetTemp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelSetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelSetTemp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelSetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelSetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelSetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelSetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelSetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelSetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelAirconTemp
    ui->scrAircon_labelAirconTemp = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelAirconTemp, 45, 79);
    lv_obj_set_size(ui->scrAircon_labelAirconTemp, 141, 100);
    lv_label_set_text(ui->scrAircon_labelAirconTemp, "25");
    lv_label_set_long_mode(ui->scrAircon_labelAirconTemp, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelAirconTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelAirconTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelAirconTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelAirconTemp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelAirconTemp, &lv_font_montserratMedium_90, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelAirconTemp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelAirconTemp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelAirconTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelAirconTemp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelAirconTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelAirconTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelAirconTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelAirconTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelAirconTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelAirconTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelCen
    ui->scrAircon_labelCen = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelCen, 173, 70);
    lv_obj_set_size(ui->scrAircon_labelCen, 45, 35);
    lv_label_set_text(ui->scrAircon_labelCen, "ºC");
    lv_label_set_long_mode(ui->scrAircon_labelCen, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelCen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelCen, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelCen, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelCen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelCen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelCen, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_btnTempDown
    ui->scrAircon_btnTempDown = lv_button_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_btnTempDown, 338, 100);
    lv_obj_set_size(ui->scrAircon_btnTempDown, 61, 61);
    ui->scrAircon_btnTempDown_label = lv_label_create(ui->scrAircon_btnTempDown);
    lv_label_set_text(ui->scrAircon_btnTempDown_label, "-");
    lv_label_set_long_mode(ui->scrAircon_btnTempDown_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrAircon_btnTempDown_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrAircon_btnTempDown, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrAircon_btnTempDown_label, LV_PCT(100));

    //Write style for scrAircon_btnTempDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_btnTempDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_btnTempDown, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_btnTempDown, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrAircon_btnTempDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_btnTempDown, 29, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_btnTempDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_btnTempDown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_btnTempDown, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_btnTempDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_btnTempDown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_btnTempUp
    ui->scrAircon_btnTempUp = lv_button_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_btnTempUp, 237, 100);
    lv_obj_set_size(ui->scrAircon_btnTempUp, 61, 61);
    ui->scrAircon_btnTempUp_label = lv_label_create(ui->scrAircon_btnTempUp);
    lv_label_set_text(ui->scrAircon_btnTempUp_label, "+");
    lv_label_set_long_mode(ui->scrAircon_btnTempUp_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrAircon_btnTempUp_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrAircon_btnTempUp, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrAircon_btnTempUp_label, LV_PCT(100));

    //Write style for scrAircon_btnTempUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_btnTempUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_btnTempUp, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_btnTempUp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrAircon_btnTempUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_btnTempUp, 29, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_btnTempUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_btnTempUp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_btnTempUp, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_btnTempUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_btnTempUp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelTimer
    ui->scrAircon_labelTimer = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelTimer, 56, 217);
    lv_obj_set_size(ui->scrAircon_labelTimer, 352, 32);
    lv_label_set_text(ui->scrAircon_labelTimer, "SET  TIMER");
    lv_label_set_long_mode(ui->scrAircon_labelTimer, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelTimer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelTimer, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelTimer, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelTimer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelTimer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelTimer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelTimerHour
    ui->scrAircon_labelTimerHour = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelTimerHour, 26, 264);
    lv_obj_set_size(ui->scrAircon_labelTimerHour, 96, 73);
    lv_label_set_text(ui->scrAircon_labelTimerHour, "01");
    lv_label_set_long_mode(ui->scrAircon_labelTimerHour, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelTimerHour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelTimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelTimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelTimerHour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelTimerHour, &lv_font_montserratMedium_58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelTimerHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelTimerHour, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelTimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelTimerHour, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelTimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelTimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelTimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelTimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelTimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelTimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelTimerPoints
    ui->scrAircon_labelTimerPoints = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelTimerPoints, 112, 264);
    lv_obj_set_size(ui->scrAircon_labelTimerPoints, 16, 58);
    lv_label_set_text(ui->scrAircon_labelTimerPoints, ":");
    lv_label_set_long_mode(ui->scrAircon_labelTimerPoints, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelTimerPoints, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelTimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelTimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelTimerPoints, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelTimerPoints, &lv_font_montserratMedium_58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelTimerPoints, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelTimerPoints, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelTimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelTimerPoints, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelTimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelTimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelTimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelTimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelTimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelTimerPoints, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelTimerMin
    ui->scrAircon_labelTimerMin = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelTimerMin, 141, 264);
    lv_obj_set_size(ui->scrAircon_labelTimerMin, 101, 79);
    lv_label_set_text(ui->scrAircon_labelTimerMin, "15");
    lv_label_set_long_mode(ui->scrAircon_labelTimerMin, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelTimerMin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelTimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelTimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelTimerMin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelTimerMin, &lv_font_montserratMedium_58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelTimerMin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelTimerMin, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelTimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelTimerMin, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelTimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelTimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelTimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelTimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelTimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelTimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_btnTimerDown
    ui->scrAircon_btnTimerDown = lv_button_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_btnTimerDown, 338, 264);
    lv_obj_set_size(ui->scrAircon_btnTimerDown, 61, 61);
    ui->scrAircon_btnTimerDown_label = lv_label_create(ui->scrAircon_btnTimerDown);
    lv_label_set_text(ui->scrAircon_btnTimerDown_label, "-");
    lv_label_set_long_mode(ui->scrAircon_btnTimerDown_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrAircon_btnTimerDown_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrAircon_btnTimerDown, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrAircon_btnTimerDown_label, LV_PCT(100));

    //Write style for scrAircon_btnTimerDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_btnTimerDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_btnTimerDown, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_btnTimerDown, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrAircon_btnTimerDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_btnTimerDown, 29, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_btnTimerDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_btnTimerDown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_btnTimerDown, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_btnTimerDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_btnTimerDown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_btnTimerUp
    ui->scrAircon_btnTimerUp = lv_button_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_btnTimerUp, 237, 264);
    lv_obj_set_size(ui->scrAircon_btnTimerUp, 61, 61);
    ui->scrAircon_btnTimerUp_label = lv_label_create(ui->scrAircon_btnTimerUp);
    lv_label_set_text(ui->scrAircon_btnTimerUp_label, "+");
    lv_label_set_long_mode(ui->scrAircon_btnTimerUp_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrAircon_btnTimerUp_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrAircon_btnTimerUp, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrAircon_btnTimerUp_label, LV_PCT(100));

    //Write style for scrAircon_btnTimerUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_btnTimerUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_btnTimerUp, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_btnTimerUp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrAircon_btnTimerUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_btnTimerUp, 29, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_btnTimerUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_btnTimerUp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_btnTimerUp, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_btnTimerUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_btnTimerUp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_rollerMode
    ui->scrAircon_rollerMode = lv_roller_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_rollerMode, 8, 394);
    lv_obj_set_width(ui->scrAircon_rollerMode, 213);
    lv_roller_set_options(ui->scrAircon_rollerMode, "COOL\nDRY\nFAN", LV_ROLLER_MODE_INFINITE);

    //Write style for scrAircon_rollerMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scrAircon_rollerMode, 23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_rollerMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_rollerMode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_rollerMode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_rollerMode, lv_color_hex(0x9D9D9D), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_rollerMode, &lv_font_montserratMedium_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_rollerMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_rollerMode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrAircon_rollerMode, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrAircon_rollerMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrAircon_rollerMode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrAircon_rollerMode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_rollerMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_rollerMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_rollerMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scrAircon_rollerMode, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_rollerMode, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_rollerMode, lv_color_hex(0x20A1C5), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_rollerMode, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_rollerMode, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_rollerMode, &lv_font_montserratMedium_37, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_rollerMode, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->scrAircon_rollerMode, 3);
    //Write codes scrAircon_labelMode
    ui->scrAircon_labelMode = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelMode, 56, 367);
    lv_obj_set_size(ui->scrAircon_labelMode, 352, 35);
    lv_label_set_text(ui->scrAircon_labelMode, "SELECT  MODE");
    lv_label_set_long_mode(ui->scrAircon_labelMode, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelMode, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelMode, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelMode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelMode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_lineSepTempTimer
    ui->scrAircon_lineSepTempTimer = lv_line_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_lineSepTempTimer, 42, 202);
    lv_obj_set_size(ui->scrAircon_lineSepTempTimer, 400, 2);
    static lv_point_precise_t scrAircon_lineSepTempTimer[] = {{0, 0},{960, 0}};
    lv_line_set_points(ui->scrAircon_lineSepTempTimer, scrAircon_lineSepTempTimer, 2);

    //Write style for scrAircon_lineSepTempTimer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrAircon_lineSepTempTimer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrAircon_lineSepTempTimer, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrAircon_lineSepTempTimer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->scrAircon_lineSepTempTimer, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_lineSepTimerMode
    ui->scrAircon_lineSepTimerMode = lv_line_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_lineSepTimerMode, 32, 352);
    lv_obj_set_size(ui->scrAircon_lineSepTimerMode, 400, 2);
    static lv_point_precise_t scrAircon_lineSepTimerMode[] = {{0, 0},{960, 0}};
    lv_line_set_points(ui->scrAircon_lineSepTimerMode, scrAircon_lineSepTimerMode, 2);

    //Write style for scrAircon_lineSepTimerMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrAircon_lineSepTimerMode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrAircon_lineSepTimerMode, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrAircon_lineSepTimerMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->scrAircon_lineSepTimerMode, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_lineSepModeSwingFan
    ui->scrAircon_lineSepModeSwingFan = lv_line_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_lineSepModeSwingFan, 32, 670);
    lv_obj_set_size(ui->scrAircon_lineSepModeSwingFan, 400, 2);
    static lv_point_precise_t scrAircon_lineSepModeSwingFan[] = {{0, 0},{960, 0}};
    lv_line_set_points(ui->scrAircon_lineSepModeSwingFan, scrAircon_lineSepModeSwingFan, 2);

    //Write style for scrAircon_lineSepModeSwingFan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrAircon_lineSepModeSwingFan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrAircon_lineSepModeSwingFan, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrAircon_lineSepModeSwingFan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->scrAircon_lineSepModeSwingFan, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelComp
    ui->scrAircon_labelComp = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelComp, 301, 420);
    lv_obj_set_size(ui->scrAircon_labelComp, 117, 38);
    lv_label_set_text(ui->scrAircon_labelComp, "COMP");
    lv_label_set_long_mode(ui->scrAircon_labelComp, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelComp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelComp, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelComp, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelComp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelComp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelComp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelCompStat
    ui->scrAircon_labelCompStat = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelCompStat, 314, 470);
    lv_obj_set_size(ui->scrAircon_labelCompStat, 88, 50);
    lv_label_set_text(ui->scrAircon_labelCompStat, "ON");
    lv_label_set_long_mode(ui->scrAircon_labelCompStat, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelCompStat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelCompStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelCompStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelCompStat, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelCompStat, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelCompStat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelCompStat, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelCompStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelCompStat, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelCompStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelCompStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelCompStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelCompStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelCompStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelCompStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelFan
    ui->scrAircon_labelFan = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelFan, 312, 544);
    lv_obj_set_size(ui->scrAircon_labelFan, 88, 32);
    lv_label_set_text(ui->scrAircon_labelFan, "FAN");
    lv_label_set_long_mode(ui->scrAircon_labelFan, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelFan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelFan, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelFan, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelFan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelFan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelFan, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelFanStat
    ui->scrAircon_labelFanStat = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelFanStat, 314, 594);
    lv_obj_set_size(ui->scrAircon_labelFanStat, 141, 52);
    lv_label_set_text(ui->scrAircon_labelFanStat, "LOW");
    lv_label_set_long_mode(ui->scrAircon_labelFanStat, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelFanStat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelFanStat, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelFanStat, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelFanStat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelFanStat, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelFanStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_btnSwing
    ui->scrAircon_btnSwing = lv_button_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_btnSwing, 144, 702);
    lv_obj_set_size(ui->scrAircon_btnSwing, 58, 41);
    ui->scrAircon_btnSwing_label = lv_label_create(ui->scrAircon_btnSwing);
    lv_label_set_text(ui->scrAircon_btnSwing_label, "ON");
    lv_label_set_long_mode(ui->scrAircon_btnSwing_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrAircon_btnSwing_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrAircon_btnSwing, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrAircon_btnSwing_label, LV_PCT(100));

    //Write style for scrAircon_btnSwing, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_btnSwing, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_btnSwing, lv_color_hex(0x6A6A6A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_btnSwing, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrAircon_btnSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_btnSwing, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_btnSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_btnSwing, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_btnSwing, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_btnSwing, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_btnSwing, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scrAircon_btnSwing, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scrAircon_btnSwing, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scrAircon_btnSwing, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_btnSwing, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scrAircon_btnSwing, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scrAircon_btnSwing, 14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scrAircon_btnSwing, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scrAircon_btnSwing, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scrAircon_btnSwing, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scrAircon_btnSwing, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scrAircon_btnSwing, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->scrAircon_btnSwing, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->scrAircon_btnSwing, lv_color_hex(0x29BAE6), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_btnSwing, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->scrAircon_btnSwing, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->scrAircon_btnSwing, 14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scrAircon_btnSwing, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scrAircon_btnSwing, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scrAircon_btnSwing, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scrAircon_btnSwing, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes scrAircon_labelSwing
    ui->scrAircon_labelSwing = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelSwing, 8, 708);
    lv_obj_set_size(ui->scrAircon_labelSwing, 136, 35);
    lv_label_set_text(ui->scrAircon_labelSwing, "SWING");
    lv_label_set_long_mode(ui->scrAircon_labelSwing, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelSwing, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelSwing, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelSwing, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelSwing, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelSwing, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelSwing, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelSwing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelFanSpeed
    ui->scrAircon_labelFanSpeed = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_labelFanSpeed, 232, 714);
    lv_obj_set_size(ui->scrAircon_labelFanSpeed, 82, 35);
    lv_label_set_text(ui->scrAircon_labelFanSpeed, "FAN");
    lv_label_set_long_mode(ui->scrAircon_labelFanSpeed, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelFanSpeed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelFanSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelFanSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelFanSpeed, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelFanSpeed, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelFanSpeed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelFanSpeed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelFanSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelFanSpeed, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelFanSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelFanSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelFanSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelFanSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelFanSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelFanSpeed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_imgCompFan
    ui->scrAircon_imgCompFan = lv_image_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_imgCompFan, 1053, 494);
    lv_obj_set_size(ui->scrAircon_imgCompFan, 26, 26);
    lv_obj_add_flag(ui->scrAircon_imgCompFan, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrAircon_imgCompFan, &_icn_fan_low_RGB565A8_26x26);
    lv_image_set_pivot(ui->scrAircon_imgCompFan, 50,50);
    lv_image_set_rotation(ui->scrAircon_imgCompFan, 0);

    //Write style for scrAircon_imgCompFan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrAircon_imgCompFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrAircon_imgCompFan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_imgCompDry
    ui->scrAircon_imgCompDry = lv_image_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_imgCompDry, 1053, 494);
    lv_obj_set_size(ui->scrAircon_imgCompDry, 26, 26);
    lv_obj_add_flag(ui->scrAircon_imgCompDry, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrAircon_imgCompDry, &_icn_dry_RGB565A8_26x26);
    lv_image_set_pivot(ui->scrAircon_imgCompDry, 50,50);
    lv_image_set_rotation(ui->scrAircon_imgCompDry, 0);

    //Write style for scrAircon_imgCompDry, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrAircon_imgCompDry, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrAircon_imgCompDry, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_LabelLow
    ui->scrAircon_LabelLow = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_LabelLow, 293, 694);
    lv_obj_set_size(ui->scrAircon_LabelLow, 42, 61);
    lv_label_set_text(ui->scrAircon_LabelLow, ".\nL");
    lv_label_set_long_mode(ui->scrAircon_LabelLow, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_LabelLow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_LabelLow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_LabelLow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_LabelLow, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_LabelLow, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_LabelLow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_LabelLow, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_LabelLow, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_LabelLow, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_LabelLow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_LabelLow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_LabelLow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_LabelLow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_LabelLow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_LabelLow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_LabelMedium
    ui->scrAircon_LabelMedium = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_LabelMedium, 354, 694);
    lv_obj_set_size(ui->scrAircon_LabelMedium, 42, 61);
    lv_label_set_text(ui->scrAircon_LabelMedium, ".\nM");
    lv_label_set_long_mode(ui->scrAircon_LabelMedium, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_LabelMedium, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_LabelMedium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_LabelMedium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_LabelMedium, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_LabelMedium, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_LabelMedium, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_LabelMedium, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_LabelMedium, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_LabelMedium, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_LabelMedium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_LabelMedium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_LabelMedium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_LabelMedium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_LabelMedium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_LabelMedium, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_LabelHigh
    ui->scrAircon_LabelHigh = lv_label_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_LabelHigh, 416, 691);
    lv_obj_set_size(ui->scrAircon_LabelHigh, 42, 61);
    lv_label_set_text(ui->scrAircon_LabelHigh, ".\nH");
    lv_label_set_long_mode(ui->scrAircon_LabelHigh, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_LabelHigh, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_LabelHigh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_LabelHigh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_LabelHigh, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_LabelHigh, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_LabelHigh, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_LabelHigh, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_LabelHigh, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_LabelHigh, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_LabelHigh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_LabelHigh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_LabelHigh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_LabelHigh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_LabelHigh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_LabelHigh, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_lineTitle
    ui->scrAircon_lineTitle = lv_line_create(ui->scrAircon_contAirconCtrl);
    lv_obj_set_pos(ui->scrAircon_lineTitle, 13, 11);
    lv_obj_set_size(ui->scrAircon_lineTitle, 429, 11);
    static lv_point_precise_t scrAircon_lineTitle[] = {{0, 0},{405, 0}};
    lv_line_set_points(ui->scrAircon_lineTitle, scrAircon_lineTitle, 2);

    //Write style for scrAircon_lineTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrAircon_lineTitle, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrAircon_lineTitle, lv_color_hex(0x52DAFF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrAircon_lineTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->scrAircon_lineTitle, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_imgComp
    ui->scrAircon_imgComp = lv_image_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_imgComp, 1058, 470);
    lv_obj_set_size(ui->scrAircon_imgComp, 26, 26);
    lv_obj_add_flag(ui->scrAircon_imgComp, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrAircon_imgComp, &_icn_cool_RGB565A8_26x26);
    lv_image_set_pivot(ui->scrAircon_imgComp, 50,50);
    lv_image_set_rotation(ui->scrAircon_imgComp, 0);

    //Write style for scrAircon_imgComp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrAircon_imgComp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrAircon_imgComp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_lineSepRollerCompFan
    ui->scrAircon_lineSepRollerCompFan = lv_line_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_lineSepRollerCompFan, 1029, 426);
    lv_obj_set_size(ui->scrAircon_lineSepRollerCompFan, 2, 202);
    static lv_point_precise_t scrAircon_lineSepRollerCompFan[] = {{0, 0},{0, 294}};
    lv_line_set_points(ui->scrAircon_lineSepRollerCompFan, scrAircon_lineSepRollerCompFan, 2);

    //Write style for scrAircon_lineSepRollerCompFan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrAircon_lineSepRollerCompFan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrAircon_lineSepRollerCompFan, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrAircon_lineSepRollerCompFan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->scrAircon_lineSepRollerCompFan, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_labelAirconTitle
    ui->scrAircon_labelAirconTitle = lv_label_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_labelAirconTitle, 29, 700);
    lv_obj_set_size(ui->scrAircon_labelAirconTitle, 744, 79);
    lv_label_set_text(ui->scrAircon_labelAirconTitle, "Air Conditioner");
    lv_label_set_long_mode(ui->scrAircon_labelAirconTitle, LV_LABEL_LONG_WRAP);

    //Write style for scrAircon_labelAirconTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrAircon_labelAirconTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_labelAirconTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrAircon_labelAirconTitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrAircon_labelAirconTitle, &lv_font_montserratMedium_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrAircon_labelAirconTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrAircon_labelAirconTitle, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrAircon_labelAirconTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrAircon_labelAirconTitle, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrAircon_labelAirconTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_labelAirconTitle, lv_color_hex(0x47494b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_labelAirconTitle, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->scrAircon_labelAirconTitle, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->scrAircon_labelAirconTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->scrAircon_labelAirconTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrAircon_labelAirconTitle, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrAircon_labelAirconTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrAircon_labelAirconTitle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrAircon_labelAirconTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_labelAirconTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_imgFanSt
    ui->scrAircon_imgFanSt = lv_image_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_imgFanSt, 1058, 564);
    lv_obj_set_size(ui->scrAircon_imgFanSt, 26, 26);
    lv_obj_add_flag(ui->scrAircon_imgFanSt, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrAircon_imgFanSt, &_icn_fan_low_RGB565A8_26x26);
    lv_image_set_pivot(ui->scrAircon_imgFanSt, 50,57);
    lv_image_set_rotation(ui->scrAircon_imgFanSt, 0);

    //Write style for scrAircon_imgFanSt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrAircon_imgFanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrAircon_imgFanSt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_sliderFan
    ui->scrAircon_sliderFan = lv_slider_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_sliderFan, 1112, 711);
    lv_obj_set_size(ui->scrAircon_sliderFan, 133, 5);
    lv_slider_set_range(ui->scrAircon_sliderFan, 0, 2);
    lv_slider_set_mode(ui->scrAircon_sliderFan, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->scrAircon_sliderFan, 0, LV_ANIM_OFF);

    //Write style for scrAircon_sliderFan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_sliderFan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_sliderFan, lv_color_hex(0x6A6A6A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_sliderFan, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_sliderFan, 147, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->scrAircon_sliderFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrAircon_sliderFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scrAircon_sliderFan, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_sliderFan, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_sliderFan, lv_color_hex(0x29bae6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_sliderFan, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_sliderFan, 147, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for scrAircon_sliderFan, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrAircon_sliderFan, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrAircon_sliderFan, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrAircon_sliderFan, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrAircon_sliderFan, 147, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes scrAircon_lineSwingFan
    ui->scrAircon_lineSwingFan = lv_line_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_lineSwingFan, 1029, 702);
    lv_obj_set_size(ui->scrAircon_lineSwingFan, 2, 58);
    static lv_point_precise_t scrAircon_lineSwingFan[] = {{0, 0},{0, 294}};
    lv_line_set_points(ui->scrAircon_lineSwingFan, scrAircon_lineSwingFan, 2);

    //Write style for scrAircon_lineSwingFan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrAircon_lineSwingFan, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrAircon_lineSwingFan, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrAircon_lineSwingFan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->scrAircon_lineSwingFan, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrAircon_aimgAirconSwing
    ui->scrAircon_aimgAirconSwing = lv_animimg_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_aimgAirconSwing, 106, 423);
    lv_obj_set_size(ui->scrAircon_aimgAirconSwing, 645, 123);
    lv_animimg_set_src(ui->scrAircon_aimgAirconSwing, (const void **) scrAircon_aimgAirconSwing_imgs, 15);
    lv_animimg_set_duration(ui->scrAircon_aimgAirconSwing, 100*15);
    lv_animimg_set_repeat_count(ui->scrAircon_aimgAirconSwing, LV_ANIM_REPEAT_INFINITE);
    // lv_animimg_set_playback_time(ui->scrAircon_aimgAirconSwing, 1500);
    // lv_animimg_set_playback_delay(ui->scrAircon_aimgAirconSwing, 100);
    lv_image_set_src(ui->scrAircon_aimgAirconSwing, scrAircon_aimgAirconSwing_imgs[0]);

    //Write codes scrAircon_aimgAirconCool
    ui->scrAircon_aimgAirconCool = lv_animimg_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_aimgAirconCool, 552, 247);
    lv_obj_set_size(ui->scrAircon_aimgAirconCool, 88, 108);
    lv_animimg_set_src(ui->scrAircon_aimgAirconCool, (const void **) scrAircon_aimgAirconCool_imgs, 6);
    lv_animimg_set_duration(ui->scrAircon_aimgAirconCool, 90*6);
    lv_animimg_set_repeat_count(ui->scrAircon_aimgAirconCool, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui->scrAircon_aimgAirconCool);

    //Write codes scrAircon_imgFan
    ui->scrAircon_imgFan = lv_image_create(ui->scrAircon);
    lv_obj_set_pos(ui->scrAircon_imgFan, 640, 267);
    lv_obj_set_size(ui->scrAircon_imgFan, 80, 80);
    lv_obj_add_flag(ui->scrAircon_imgFan, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrAircon_imgFan, &_aircon_menu_fan_1_RGB565A8_80x80);
    lv_image_set_pivot(ui->scrAircon_imgFan, 15,15);
    lv_image_set_rotation(ui->scrAircon_imgFan, 0);

    //Write style for scrAircon_imgFan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrAircon_imgFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrAircon_imgFan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrAircon.
    lv_obj_clear_flag(guider_ui.scrAircon_contAirconCtrl, LV_OBJ_FLAG_SCROLLABLE);

    //Update current screen layout.
    lv_obj_update_layout(ui->scrAircon);

    //Init events for screen.
    events_init_scrAircon(ui);
}
