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



void setup_scr_scrHood(lv_ui *ui)
{
    //Write codes scrHood
    ui->scrHood = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrHood, 1280, 800);
    lv_obj_set_scrollbar_mode(ui->scrHood, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrHood, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHood, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_imgHoodBg
    ui->scrHood_imgHoodBg = lv_image_create(ui->scrHood);
    lv_obj_set_pos(ui->scrHood_imgHoodBg, 0, 0);
    lv_obj_set_size(ui->scrHood_imgHoodBg, 1280, 800);
    lv_obj_add_flag(ui->scrHood_imgHoodBg, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrHood_imgHoodBg, &_hood_bg_RGB565A8_1280x800);
    lv_image_set_pivot(ui->scrHood_imgHoodBg, 50,50);
    lv_image_set_rotation(ui->scrHood_imgHoodBg, 0);

    //Write style for scrHood_imgHoodBg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrHood_imgHoodBg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrHood_imgHoodBg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_btnHoodBack
    ui->scrHood_btnHoodBack = lv_button_create(ui->scrHood);
    lv_obj_set_pos(ui->scrHood_btnHoodBack, 0, 0);
    lv_obj_set_size(ui->scrHood_btnHoodBack, 205, 150);
    ui->scrHood_btnHoodBack_label = lv_label_create(ui->scrHood_btnHoodBack);
    lv_label_set_text(ui->scrHood_btnHoodBack_label, "");
    lv_label_set_long_mode(ui->scrHood_btnHoodBack_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrHood_btnHoodBack_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrHood_btnHoodBack, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrHood_btnHoodBack_label, LV_PCT(100));

    //Write style for scrHood_btnHoodBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHood_btnHoodBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrHood_btnHoodBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHood_btnHoodBack, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHood_btnHoodBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->scrHood_btnHoodBack, &_back_button_RGB565A8_205x150, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->scrHood_btnHoodBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->scrHood_btnHoodBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHood_btnHoodBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHood_btnHoodBack, &lv_font_montserratMedium_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHood_btnHoodBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHood_btnHoodBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_imgHoodLight
    ui->scrHood_imgHoodLight = lv_image_create(ui->scrHood);
    lv_obj_set_pos(ui->scrHood_imgHoodLight, 0, 197);
    lv_obj_set_size(ui->scrHood_imgHoodLight, 901, 511);
    lv_obj_add_flag(ui->scrHood_imgHoodLight, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scrHood_imgHoodLight, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrHood_imgHoodLight, &_hood_light_RGB565A8_901x511);
    lv_image_set_pivot(ui->scrHood_imgHoodLight, 50,50);
    lv_image_set_rotation(ui->scrHood_imgHoodLight, 0);

    //Write style for scrHood_imgHoodLight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrHood_imgHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrHood_imgHoodLight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_contHoodConsole
    ui->scrHood_contHoodConsole = lv_obj_create(ui->scrHood);
    lv_obj_set_pos(ui->scrHood_contHoodConsole, 709, 114);
    lv_obj_set_size(ui->scrHood_contHoodConsole, 482, 126);
    lv_obj_set_scrollbar_mode(ui->scrHood_contHoodConsole, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrHood_contHoodConsole, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHood_contHoodConsole, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrHood_contHoodConsole, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrHood_contHoodConsole, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrHood_contHoodConsole, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHood_contHoodConsole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHood_contHoodConsole, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrHood_contHoodConsole, lv_color_hex(0x272a2e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrHood_contHoodConsole, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHood_contHoodConsole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHood_contHoodConsole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHood_contHoodConsole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHood_contHoodConsole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHood_contHoodConsole, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_barHoodEdge
    ui->scrHood_barHoodEdge = lv_bar_create(ui->scrHood_contHoodConsole);
    lv_obj_set_pos(ui->scrHood_barHoodEdge, 0, 0);
    lv_obj_set_size(ui->scrHood_barHoodEdge, 458, 41);
    lv_obj_set_style_anim_duration(ui->scrHood_barHoodEdge, 1000, 0);
    lv_bar_set_mode(ui->scrHood_barHoodEdge, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->scrHood_barHoodEdge, 0, 100);
    lv_bar_set_value(ui->scrHood_barHoodEdge, 50, LV_ANIM_OFF);

    //Write style for scrHood_barHoodEdge, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHood_barHoodEdge, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrHood_barHoodEdge, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrHood_barHoodEdge, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHood_barHoodEdge, 29, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHood_barHoodEdge, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scrHood_barHoodEdge, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHood_barHoodEdge, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHood_barHoodEdge, 29, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes scrHood_labelHoodLight
    ui->scrHood_labelHoodLight = lv_label_create(ui->scrHood_contHoodConsole);
    lv_obj_set_pos(ui->scrHood_labelHoodLight, 45, 44);
    lv_obj_set_size(ui->scrHood_labelHoodLight, 88, 58);
    lv_label_set_text(ui->scrHood_labelHoodLight, "LIGHT");
    lv_label_set_long_mode(ui->scrHood_labelHoodLight, LV_LABEL_LONG_WRAP);

    //Write style for scrHood_labelHoodLight, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHood_labelHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHood_labelHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHood_labelHoodLight, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHood_labelHoodLight, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHood_labelHoodLight, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHood_labelHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHood_labelHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHood_labelHoodLight, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHood_labelHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHood_labelHoodLight, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHood_labelHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHood_labelHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHood_labelHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHood_labelHoodLight, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_labelHoodFan
    ui->scrHood_labelHoodFan = lv_label_create(ui->scrHood_contHoodConsole);
    lv_obj_set_pos(ui->scrHood_labelHoodFan, 237, 44);
    lv_obj_set_size(ui->scrHood_labelHoodFan, 88, 55);
    lv_label_set_text(ui->scrHood_labelHoodFan, "FAN");
    lv_label_set_long_mode(ui->scrHood_labelHoodFan, LV_LABEL_LONG_WRAP);

    //Write style for scrHood_labelHoodFan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHood_labelHoodFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHood_labelHoodFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHood_labelHoodFan, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHood_labelHoodFan, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHood_labelHoodFan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHood_labelHoodFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHood_labelHoodFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHood_labelHoodFan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHood_labelHoodFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHood_labelHoodFan, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHood_labelHoodFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHood_labelHoodFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHood_labelHoodFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHood_labelHoodFan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_labelHoodCtrl
    ui->scrHood_labelHoodCtrl = lv_label_create(ui->scrHood_contHoodConsole);
    lv_obj_set_pos(ui->scrHood_labelHoodCtrl, 312, 44);
    lv_obj_set_size(ui->scrHood_labelHoodCtrl, 88, 61);
    lv_obj_add_flag(ui->scrHood_labelHoodCtrl, LV_OBJ_FLAG_CLICKABLE);
    lv_label_set_text(ui->scrHood_labelHoodCtrl, "OFF");
    lv_label_set_long_mode(ui->scrHood_labelHoodCtrl, LV_LABEL_LONG_WRAP);

    //Write style for scrHood_labelHoodCtrl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHood_labelHoodCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHood_labelHoodCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHood_labelHoodCtrl, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHood_labelHoodCtrl, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHood_labelHoodCtrl, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHood_labelHoodCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHood_labelHoodCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHood_labelHoodCtrl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHood_labelHoodCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHood_labelHoodCtrl, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHood_labelHoodCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHood_labelHoodCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHood_labelHoodCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHood_labelHoodCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_labelLightCtrl
    ui->scrHood_labelLightCtrl = lv_label_create(ui->scrHood_contHoodConsole);
    lv_obj_set_pos(ui->scrHood_labelLightCtrl, 130, 44);
    lv_obj_set_size(ui->scrHood_labelLightCtrl, 88, 61);
    lv_obj_add_flag(ui->scrHood_labelLightCtrl, LV_OBJ_FLAG_CLICKABLE);
    lv_label_set_text(ui->scrHood_labelLightCtrl, "OFF");
    lv_label_set_long_mode(ui->scrHood_labelLightCtrl, LV_LABEL_LONG_WRAP);

    //Write style for scrHood_labelLightCtrl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHood_labelLightCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHood_labelLightCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHood_labelLightCtrl, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHood_labelLightCtrl, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHood_labelLightCtrl, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrHood_labelLightCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrHood_labelLightCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHood_labelLightCtrl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHood_labelLightCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHood_labelLightCtrl, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHood_labelLightCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHood_labelLightCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHood_labelLightCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHood_labelLightCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_rollerFanCtrl
    ui->scrHood_rollerFanCtrl = lv_roller_create(ui->scrHood);
    lv_obj_set_pos(ui->scrHood_rollerFanCtrl, 808, 532);
    lv_obj_set_width(ui->scrHood_rollerFanCtrl, 304);
    lv_roller_set_options(ui->scrHood_rollerFanCtrl, "SET FAN TO LOW\nSET FAN TO MEDIUM\nSET FAN TO HIGH", LV_ROLLER_MODE_INFINITE);

    //Write style for scrHood_rollerFanCtrl, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->scrHood_rollerFanCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHood_rollerFanCtrl, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrHood_rollerFanCtrl, lv_color_hex(0x2b3038), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrHood_rollerFanCtrl, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHood_rollerFanCtrl, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHood_rollerFanCtrl, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHood_rollerFanCtrl, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrHood_rollerFanCtrl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrHood_rollerFanCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHood_rollerFanCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHood_rollerFanCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHood_rollerFanCtrl, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scrHood_rollerFanCtrl, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrHood_rollerFanCtrl, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrHood_rollerFanCtrl, lv_color_hex(0x36373d), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrHood_rollerFanCtrl, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrHood_rollerFanCtrl, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrHood_rollerFanCtrl, &lv_font_montserratMedium_32, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrHood_rollerFanCtrl, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->scrHood_rollerFanCtrl, 3);
    //Write codes scrHood_cont_imgSmog
    ui->scrHood_cont_imgSmog = lv_obj_create(ui->scrHood);
    lv_obj_set_pos(ui->scrHood_cont_imgSmog, 0, 241);
    lv_obj_set_size(ui->scrHood_cont_imgSmog, 786, 335);
    lv_obj_set_scrollbar_mode(ui->scrHood_cont_imgSmog, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrHood_cont_imgSmog, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrHood_cont_imgSmog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrHood_cont_imgSmog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrHood_cont_imgSmog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrHood_cont_imgSmog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrHood_cont_imgSmog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrHood_cont_imgSmog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrHood_cont_imgSmog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrHood_cont_imgSmog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_imgSmog1
    ui->scrHood_imgSmog1 = lv_image_create(ui->scrHood_cont_imgSmog);
    lv_obj_set_pos(ui->scrHood_imgSmog1, 248, 32);
    lv_obj_set_size(ui->scrHood_imgSmog1, 82, 450);
    lv_obj_add_flag(ui->scrHood_imgSmog1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scrHood_imgSmog1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrHood_imgSmog1, &_smog_1_RGB565A8_82x450);
    lv_image_set_pivot(ui->scrHood_imgSmog1, 50,50);
    lv_image_set_rotation(ui->scrHood_imgSmog1, 0);

    //Write style for scrHood_imgSmog1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrHood_imgSmog1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrHood_imgSmog1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrHood_imgSmog2
    ui->scrHood_imgSmog2 = lv_image_create(ui->scrHood_cont_imgSmog);
    lv_obj_set_pos(ui->scrHood_imgSmog2, 464, 2);
    lv_obj_set_size(ui->scrHood_imgSmog2, 101, 491);
    lv_obj_add_flag(ui->scrHood_imgSmog2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->scrHood_imgSmog2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrHood_imgSmog2, &_smog_2_RGB565A8_101x491);
    lv_image_set_pivot(ui->scrHood_imgSmog2, 50,50);
    lv_image_set_rotation(ui->scrHood_imgSmog2, 0);

    //Write style for scrHood_imgSmog2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrHood_imgSmog2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrHood_imgSmog2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrHood.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrHood);

    //Init events for screen.
    events_init_scrHood(ui);
}
