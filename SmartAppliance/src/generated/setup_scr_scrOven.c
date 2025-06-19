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
#include "ui_Oven.h"


void setup_scr_scrOven(lv_ui *ui)
{
    //Write codes scrOven
    ui->scrOven = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrOven, 1280, 800);
    lv_obj_set_scrollbar_mode(ui->scrOven, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrOven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->scrOven, &_oven_bg_RGB565A8_1280x800, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->scrOven, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->scrOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_animimg_Door
    ui->scrOven_animimg_Door = lv_animimg_create(ui->scrOven);
    lv_obj_set_pos(ui->scrOven_animimg_Door, 18, 0);
    lv_obj_set_size(ui->scrOven_animimg_Door, 704, 800);
    lv_animimg_set_src(ui->scrOven_animimg_Door, (const void **) scrOven_animimg_Door_imgs, 8);
    lv_animimg_set_duration(ui->scrOven_animimg_Door, 90*8);
    lv_animimg_set_repeat_count(ui->scrOven_animimg_Door, 1);
    lv_image_set_src(ui->scrOven_animimg_Door, scrOven_animimg_Door_imgs[0]);

    //Write codes scrOven_animimg_Fan
    ui->scrOven_animimg_Fan = lv_animimg_create(ui->scrOven);
    lv_obj_set_pos(ui->scrOven_animimg_Fan, 376, 385);
    lv_obj_set_size(ui->scrOven_animimg_Fan, 120, 120);
    lv_animimg_set_src(ui->scrOven_animimg_Fan, (const void **) scrOven_animimg_Fan_imgs, 4);
    lv_animimg_set_duration(ui->scrOven_animimg_Fan, 80*4);
    lv_animimg_set_repeat_count(ui->scrOven_animimg_Fan, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui->scrOven_animimg_Fan);

    //Write codes scrOven_Group_Oven
    ui->scrOven_Group_Oven = lv_obj_create(ui->scrOven);
    lv_obj_set_pos(ui->scrOven_Group_Oven, 666, 20);
    lv_obj_set_size(ui->scrOven_Group_Oven, 578, 761);
    lv_obj_set_scrollbar_mode(ui->scrOven_Group_Oven, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrOven_Group_Oven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Group_Oven, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrOven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrOven_Group_Oven, lv_color_hex(0x4A484A), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrOven_Group_Oven, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Group_Oven, 58, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Group_Oven, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrOven_Group_Oven, lv_color_hex(0x181818), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrOven_Group_Oven, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Group_Oven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_line
    ui->scrOven_line = lv_line_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_line, 5, 5);
    lv_obj_set_size(ui->scrOven_line, 549, 26);
    static lv_point_precise_t scrOven_line[] = {{0, 0},{1384, 0}};
    lv_line_set_points(ui->scrOven_line, scrOven_line, 2);

    //Write style for scrOven_line, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrOven_line, 17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrOven_line, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrOven_line, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->scrOven_line, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_CurrTemp
    ui->scrOven_Label_CurrTemp = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_CurrTemp, 32, 47);
    lv_obj_set_size(ui->scrOven_Label_CurrTemp, 186, 52);
    lv_label_set_text(ui->scrOven_Label_CurrTemp, "CURRENT TEMP");
    lv_label_set_long_mode(ui->scrOven_Label_CurrTemp, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_CurrTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_CurrTemp, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_CurrTemp, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_CurrTemp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_CurrTemp, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_CurrTemp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_CurrTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_line_5
    ui->scrOven_line_5 = lv_line_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_line_5, 10, 258);
    lv_obj_set_size(ui->scrOven_line_5, 533, 11);
    static lv_point_precise_t scrOven_line_5[] = {{0, 0},{1293, 0}};
    lv_line_set_points(ui->scrOven_line_5, scrOven_line_5, 2);

    //Write style for scrOven_line_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrOven_line_5, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrOven_line_5, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrOven_line_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_line_4
    ui->scrOven_line_4 = lv_line_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_line_4, 10, 423);
    lv_obj_set_size(ui->scrOven_line_4, 533, 11);
    static lv_point_precise_t scrOven_line_4[] = {{0, 0},{1293, 0}};
    lv_line_set_points(ui->scrOven_line_4, scrOven_line_4, 2);

    //Write style for scrOven_line_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrOven_line_4, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrOven_line_4, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrOven_line_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_line_3
    ui->scrOven_line_3 = lv_line_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_line_3, 266, 129);
    lv_obj_set_size(ui->scrOven_line_3, 240, 5);
    static lv_point_precise_t scrOven_line_3[] = {{0, 0},{626, 0}};
    lv_line_set_points(ui->scrOven_line_3, scrOven_line_3, 2);

    //Write style for scrOven_line_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrOven_line_3, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrOven_line_3, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrOven_line_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_line_2
    ui->scrOven_line_2 = lv_line_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_line_2, 258, 55);
    lv_obj_set_size(ui->scrOven_line_2, 26, 185);
    static lv_point_precise_t scrOven_line_2[] = {{0, 0},{0, 470}};
    lv_line_set_points(ui->scrOven_line_2, scrOven_line_2, 2);

    //Write style for scrOven_line_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrOven_line_2, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrOven_line_2, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrOven_line_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_line_1
    ui->scrOven_line_1 = lv_line_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_line_1, 258, 488);
    lv_obj_set_size(ui->scrOven_line_1, 16, 161);
    static lv_point_precise_t scrOven_line_1[] = {{0, 0},{0, 882}};
    lv_line_set_points(ui->scrOven_line_1, scrOven_line_1, 2);

    //Write style for scrOven_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->scrOven_line_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->scrOven_line_1, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->scrOven_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Temp
    ui->scrOven_Label_Temp = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_Temp, 0, 120);
    lv_obj_set_size(ui->scrOven_Label_Temp, 261, 120);
    lv_label_set_text(ui->scrOven_Label_Temp, "250");
    lv_label_set_long_mode(ui->scrOven_Label_Temp, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Temp, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Temp, &lv_font_montserratMedium_120, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Temp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Temp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Cen
    ui->scrOven_Label_Cen = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_Cen, 205, 102);
    lv_obj_set_size(ui->scrOven_Label_Cen, 42, 41);
    lv_label_set_text(ui->scrOven_Label_Cen, "ºC");
    lv_label_set_long_mode(ui->scrOven_Label_Cen, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Cen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Cen, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Cen, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Cen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Cen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Cen, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Status
    ui->scrOven_Label_Status = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_Status, 322, 50);
    lv_obj_set_size(ui->scrOven_Label_Status, 154, 29);
    lv_label_set_text(ui->scrOven_Label_Status, "STATUS");
    lv_label_set_long_mode(ui->scrOven_Label_Status, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Status, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Status, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Status, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Status, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Status, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Status, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Status, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_CurrStat
    ui->scrOven_Label_CurrStat = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_CurrStat, 370, 82);
    lv_obj_set_size(ui->scrOven_Label_CurrStat, 112, 38);
    lv_label_set_text(ui->scrOven_Label_CurrStat, "OFF");
    lv_label_set_long_mode(ui->scrOven_Label_CurrStat, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_CurrStat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_CurrStat, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_CurrStat, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_CurrStat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_CurrStat, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_CurrStat, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_CurrStat, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_CurrStat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Time
    ui->scrOven_Label_Time = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_Time, 274, 152);
    lv_obj_set_size(ui->scrOven_Label_Time, 109, 61);
    lv_label_set_text(ui->scrOven_Label_Time, "TIME\nLEFT");
    lv_label_set_long_mode(ui->scrOven_Label_Time, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Time, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Time, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Bar_Time
    ui->scrOven_Bar_Time = lv_bar_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Bar_Time, 272, 226);
    lv_obj_set_size(ui->scrOven_Bar_Time, 242, 11);
    lv_obj_set_style_anim_duration(ui->scrOven_Bar_Time, 1000, 0);
    lv_bar_set_mode(ui->scrOven_Bar_Time, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->scrOven_Bar_Time, 0, 100);
    lv_bar_set_value(ui->scrOven_Bar_Time, 33, LV_ANIM_OFF);

    //Write style for scrOven_Bar_Time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrOven_Bar_Time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrOven_Bar_Time, lv_color_hex(0x4A4441), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrOven_Bar_Time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Bar_Time, 29, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Bar_Time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scrOven_Bar_Time, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrOven_Bar_Time, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrOven_Bar_Time, lv_color_hex(0xFF9110), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrOven_Bar_Time, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Bar_Time, 29, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Mode
    ui->scrOven_Label_Mode = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_Mode, 202, 273);
    lv_obj_set_size(ui->scrOven_Label_Mode, 117, 32);
    lv_label_set_text(ui->scrOven_Label_Mode, "MODE");
    lv_label_set_long_mode(ui->scrOven_Label_Mode, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Btn_State
    ui->scrOven_Btn_State = lv_imagebutton_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Btn_State, 202, 673);
    lv_obj_set_size(ui->scrOven_Btn_State, 133, 55);
    lv_obj_add_flag(ui->scrOven_Btn_State, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->scrOven_Btn_State, LV_IMAGEBUTTON_STATE_RELEASED, &_BTN_oven_RGB565A8_133x55, NULL, NULL);
    lv_imagebutton_set_src(ui->scrOven_Btn_State, LV_IMAGEBUTTON_STATE_PRESSED, &_BTN_oven_RGB565A8_133x55, NULL, NULL);
    lv_imagebutton_set_src(ui->scrOven_Btn_State, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_BTN_oven_RGB565A8_133x55, NULL, NULL);
    lv_imagebutton_set_src(ui->scrOven_Btn_State, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_BTN_oven_RGB565A8_133x55, NULL, NULL);
    ui->scrOven_Btn_State_label = lv_label_create(ui->scrOven_Btn_State);
    lv_label_set_text(ui->scrOven_Btn_State_label, "START");
    lv_label_set_long_mode(ui->scrOven_Btn_State_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrOven_Btn_State_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrOven_Btn_State, 0, LV_STATE_DEFAULT);

    //Write style for scrOven_Btn_State, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scrOven_Btn_State, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Btn_State, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Btn_State, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Btn_State, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Btn_State, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scrOven_Btn_State, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Btn_State, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_recolor(ui->scrOven_Btn_State, lv_color_hex(0x35C915), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->scrOven_Btn_State, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scrOven_Btn_State, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scrOven_Btn_State, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scrOven_Btn_State, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scrOven_Btn_State, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for scrOven_Btn_State, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Btn_State, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_recolor(ui->scrOven_Btn_State, lv_color_hex(0x35C915), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->scrOven_Btn_State, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->scrOven_Btn_State, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->scrOven_Btn_State, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->scrOven_Btn_State, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->scrOven_Btn_State, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for scrOven_Btn_State, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Btn_State, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->scrOven_Btn_State, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes scrOven_Label_Settings
    ui->scrOven_Label_Settings = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_Settings, 186, 441);
    lv_obj_set_size(ui->scrOven_Label_Settings, 202, 38);
    lv_label_set_text(ui->scrOven_Label_Settings, "SETTINGS");
    lv_label_set_long_mode(ui->scrOven_Label_Settings, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Settings, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Settings, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Settings, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Settings, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_TimeLeft
    ui->scrOven_Label_TimeLeft = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_TimeLeft, 376, 158);
    lv_obj_set_size(ui->scrOven_Label_TimeLeft, 61, 61);
    lv_label_set_text(ui->scrOven_Label_TimeLeft, "30");
    lv_label_set_long_mode(ui->scrOven_Label_TimeLeft, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_TimeLeft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_TimeLeft, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_TimeLeft, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_TimeLeft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_TimeLeft, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_TimeLeft, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_TimeLeft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Min
    ui->scrOven_Label_Min = lv_label_create(ui->scrOven_Group_Oven);
    lv_obj_set_pos(ui->scrOven_Label_Min, 442, 173);
    lv_obj_set_size(ui->scrOven_Label_Min, 90, 32);
    lv_label_set_text(ui->scrOven_Label_Min, "mins");
    lv_label_set_long_mode(ui->scrOven_Label_Min, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Min, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Min, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Min, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Min, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Min, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Min, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Group_TarTemp
    ui->scrOven_Group_TarTemp = lv_obj_create(ui->scrOven);
    lv_obj_set_pos(ui->scrOven_Group_TarTemp, 669, 473);
    lv_obj_set_size(ui->scrOven_Group_TarTemp, 240, 240);
    lv_obj_set_scrollbar_mode(ui->scrOven_Group_TarTemp, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrOven_Group_TarTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Group_TarTemp, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrOven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrOven_Group_TarTemp, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrOven_Group_TarTemp, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Group_TarTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Img_TempWheel
    ui->scrOven_Img_TempWheel = lv_image_create(ui->scrOven_Group_TarTemp);
    lv_obj_set_pos(ui->scrOven_Img_TempWheel, 66, -11);
    lv_obj_set_size(ui->scrOven_Img_TempWheel, 149, 285);
    lv_obj_add_flag(ui->scrOven_Img_TempWheel, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_add_flag(ui->scrOven_Img_TempWheel, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->scrOven_Img_TempWheel, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_TempWheel, &_wheel_bg_RGB565A8_149x285);
    lv_image_set_pivot(ui->scrOven_Img_TempWheel, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_TempWheel, 0);

    //Write style for scrOven_Img_TempWheel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_TempWheel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_TempWheel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_SelTemp
    ui->scrOven_Label_SelTemp = lv_label_create(ui->scrOven_Group_TarTemp);
    lv_obj_set_pos(ui->scrOven_Label_SelTemp, 0, 94);
    lv_obj_set_size(ui->scrOven_Label_SelTemp, 154, 64);
    lv_obj_add_flag(ui->scrOven_Label_SelTemp, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_add_flag(ui->scrOven_Label_SelTemp, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->scrOven_Label_SelTemp, "TARGET\nTEMP");
    lv_label_set_long_mode(ui->scrOven_Label_SelTemp, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_SelTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_SelTemp, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_SelTemp, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_SelTemp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_SelTemp, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_SelTemp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_SelTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_TarCen
    ui->scrOven_Label_TarCen = lv_label_create(ui->scrOven_Group_TarTemp);
    lv_obj_set_pos(ui->scrOven_Label_TarCen, 160, 97);
    lv_obj_set_size(ui->scrOven_Label_TarCen, 42, 29);
    lv_obj_add_flag(ui->scrOven_Label_TarCen, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->scrOven_Label_TarCen, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_label_set_text(ui->scrOven_Label_TarCen, "ºC");
    lv_label_set_long_mode(ui->scrOven_Label_TarCen, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_TarCen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_TarCen, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_TarCen, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_TarCen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_TarCen, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_TarCen, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_TarCen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Group_Timer
    ui->scrOven_Group_Timer = lv_obj_create(ui->scrOven);
    lv_obj_set_pos(ui->scrOven_Group_Timer, 954, 473);
    lv_obj_set_size(ui->scrOven_Group_Timer, 250, 264);
    lv_obj_set_scrollbar_mode(ui->scrOven_Group_Timer, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrOven_Group_Timer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Group_Timer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrOven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrOven_Group_Timer, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrOven_Group_Timer, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Group_Timer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Img_TimerWheel
    ui->scrOven_Img_TimerWheel = lv_image_create(ui->scrOven_Group_Timer);
    lv_obj_set_pos(ui->scrOven_Img_TimerWheel, 18, -11);
    lv_obj_set_size(ui->scrOven_Img_TimerWheel, 149, 285);
    lv_obj_add_flag(ui->scrOven_Img_TimerWheel, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->scrOven_Img_TimerWheel, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_add_flag(ui->scrOven_Img_TimerWheel, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_TimerWheel, &_wheel_bg_2_RGB565A8_149x285);
    lv_image_set_pivot(ui->scrOven_Img_TimerWheel, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_TimerWheel, 0);

    //Write style for scrOven_Img_TimerWheel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_TimerWheel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_TimerWheel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_SelTimer
    ui->scrOven_Label_SelTimer = lv_label_create(ui->scrOven_Group_Timer);
    lv_obj_set_pos(ui->scrOven_Label_SelTimer, 146, 100);
    lv_obj_set_size(ui->scrOven_Label_SelTimer, 133, 61);
    lv_obj_add_flag(ui->scrOven_Label_SelTimer, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_add_flag(ui->scrOven_Label_SelTimer, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->scrOven_Label_SelTimer, "SETUP\nTIMER");
    lv_label_set_long_mode(ui->scrOven_Label_SelTimer, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_SelTimer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_SelTimer, lv_color_hex(0xFF9110), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_SelTimer, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_SelTimer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_SelTimer, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_SelTimer, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_SelTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_TimerSel
    ui->scrOven_Label_TimerSel = lv_label_create(ui->scrOven_Group_Timer);
    lv_obj_set_pos(ui->scrOven_Label_TimerSel, 87, 97);
    lv_obj_set_size(ui->scrOven_Label_TimerSel, 72, 32);
    lv_obj_add_flag(ui->scrOven_Label_TimerSel, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_add_flag(ui->scrOven_Label_TimerSel, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->scrOven_Label_TimerSel, "min\n\n");
    lv_label_set_long_mode(ui->scrOven_Label_TimerSel, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_TimerSel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_TimerSel, lv_color_hex(0xc9c5c5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_TimerSel, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_TimerSel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_TimerSel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_TimerSel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_TimerSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Tile_Mode
    ui->scrOven_Tile_Mode = lv_tileview_create(ui->scrOven);
    lv_obj_set_pos(ui->scrOven_Tile_Mode, 680, 323);
    lv_obj_set_size(ui->scrOven_Tile_Mode, 541, 111);
    lv_obj_set_scrollbar_mode(ui->scrOven_Tile_Mode, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scrOven_Tile_Mode, LV_OBJ_FLAG_SCROLLABLE);
    ui->scrOven_Tile_Mode_Mode_1 = lv_tileview_add_tile(ui->scrOven_Tile_Mode, 0, 0, LV_DIR_RIGHT);
    ui->scrOven_Tile_Mode_Mode_2 = lv_tileview_add_tile(ui->scrOven_Tile_Mode, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
    ui->scrOven_Tile_Mode_Mode_3 = lv_tileview_add_tile(ui->scrOven_Tile_Mode, 2, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
    ui->scrOven_Tile_Mode_Mode_4 = lv_tileview_add_tile(ui->scrOven_Tile_Mode, 3, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
    ui->scrOven_Tile_Mode_Mode_5 = lv_tileview_add_tile(ui->scrOven_Tile_Mode, 4, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
    ui->scrOven_Tile_Mode_Mode_6 = lv_tileview_add_tile(ui->scrOven_Tile_Mode, 5, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
    ui->scrOven_Tile_Mode_Mode_7 = lv_tileview_add_tile(ui->scrOven_Tile_Mode, 6, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
    ui->scrOven_Tile_Mode_Mode_8 = lv_tileview_add_tile(ui->scrOven_Tile_Mode, 7, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
    ui->scrOven_Tile_Mode_Mode_9 = lv_tileview_add_tile(ui->scrOven_Tile_Mode, 8, 0, LV_DIR_LEFT);

    //Write style for scrOven_Tile_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrOven_Tile_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Tile_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Tile_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scrOven_Tile_Mode, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrOven_Tile_Mode, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Tile_Mode, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



    //Write codes scrOven_Img_Mode1
    ui->scrOven_Img_Mode1 = lv_image_create(ui->scrOven_Tile_Mode_Mode_1);
    lv_obj_set_pos(ui->scrOven_Img_Mode1, 61, 23);
    lv_obj_set_size(ui->scrOven_Img_Mode1, 61, 61);
    lv_obj_add_flag(ui->scrOven_Img_Mode1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_Mode1, &_icn_oven_fan_rear_RGB565A8_61x61);
    lv_image_set_pivot(ui->scrOven_Img_Mode1, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_Mode1, 0);

    //Write style for scrOven_Img_Mode1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_Mode1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Mode1
    ui->scrOven_Label_Mode1 = lv_label_create(ui->scrOven_Tile_Mode_Mode_1);
    lv_obj_set_pos(ui->scrOven_Label_Mode1, 157, 29);
    lv_obj_set_size(ui->scrOven_Label_Mode1, 301, 67);
    lv_label_set_text(ui->scrOven_Label_Mode1, "Fan Forced Rear Element");
    lv_label_set_long_mode(ui->scrOven_Label_Mode1, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode1, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes scrOven_Img_Mode2
    ui->scrOven_Img_Mode2 = lv_image_create(ui->scrOven_Tile_Mode_Mode_2);
    lv_obj_set_pos(ui->scrOven_Img_Mode2, 61, 23);
    lv_obj_set_size(ui->scrOven_Img_Mode2, 61, 61);
    lv_obj_add_flag(ui->scrOven_Img_Mode2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_Mode2, &_icn_oven_upper_lower_RGB565A8_61x61);
    lv_image_set_pivot(ui->scrOven_Img_Mode2, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_Mode2, 0);

    //Write style for scrOven_Img_Mode2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_Mode2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Mode2
    ui->scrOven_Label_Mode2 = lv_label_create(ui->scrOven_Tile_Mode_Mode_2);
    lv_obj_set_pos(ui->scrOven_Label_Mode2, 162, 11);
    lv_obj_set_size(ui->scrOven_Label_Mode2, 293, 82);
    lv_label_set_text(ui->scrOven_Label_Mode2, "Upper & Lower\nElements\nConvection");
    lv_label_set_long_mode(ui->scrOven_Label_Mode2, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode2, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes scrOven_Label_Mode3
    ui->scrOven_Label_Mode3 = lv_label_create(ui->scrOven_Tile_Mode_Mode_3);
    lv_obj_set_pos(ui->scrOven_Label_Mode3, 173, 14);
    lv_obj_set_size(ui->scrOven_Label_Mode3, 285, 88);
    lv_label_set_text(ui->scrOven_Label_Mode3, "Fan Forced Upper & Lower Convection");
    lv_label_set_long_mode(ui->scrOven_Label_Mode3, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode3, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode3, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Img_Mode3
    ui->scrOven_Img_Mode3 = lv_image_create(ui->scrOven_Tile_Mode_Mode_3);
    lv_obj_set_pos(ui->scrOven_Img_Mode3, 61, 23);
    lv_obj_set_size(ui->scrOven_Img_Mode3, 61, 61);
    lv_obj_add_flag(ui->scrOven_Img_Mode3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_Mode3, &_icn_oven_fan_upper_lower_RGB565A8_61x61);
    lv_image_set_pivot(ui->scrOven_Img_Mode3, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_Mode3, 0);

    //Write style for scrOven_Img_Mode3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_Mode3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_Mode3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes scrOven_Img_Mode4
    ui->scrOven_Img_Mode4 = lv_image_create(ui->scrOven_Tile_Mode_Mode_4);
    lv_obj_set_pos(ui->scrOven_Img_Mode4, 61, 23);
    lv_obj_set_size(ui->scrOven_Img_Mode4, 61, 61);
    lv_obj_add_flag(ui->scrOven_Img_Mode4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_Mode4, &_icn_oven_fan_lower_RGB565A8_61x61);
    lv_image_set_pivot(ui->scrOven_Img_Mode4, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_Mode4, 0);

    //Write style for scrOven_Img_Mode4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_Mode4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Mode4
    ui->scrOven_Label_Mode4 = lv_label_create(ui->scrOven_Tile_Mode_Mode_4);
    lv_obj_set_pos(ui->scrOven_Label_Mode4, 152, 14);
    lv_obj_set_size(ui->scrOven_Label_Mode4, 317, 85);
    lv_label_set_text(ui->scrOven_Label_Mode4, "Fan Forced\nLower Element\nConvection");
    lv_label_set_long_mode(ui->scrOven_Label_Mode4, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode4, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode4, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes scrOven_Img_Mode5
    ui->scrOven_Img_Mode5 = lv_image_create(ui->scrOven_Tile_Mode_Mode_5);
    lv_obj_set_pos(ui->scrOven_Img_Mode5, 106, 26);
    lv_obj_set_size(ui->scrOven_Img_Mode5, 61, 61);
    lv_obj_add_flag(ui->scrOven_Img_Mode5, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_Mode5, &_icn_oven_gril_RGB565A8_61x61);
    lv_image_set_pivot(ui->scrOven_Img_Mode5, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_Mode5, 0);

    //Write style for scrOven_Img_Mode5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_Mode5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Mode5
    ui->scrOven_Label_Mode5 = lv_label_create(ui->scrOven_Tile_Mode_Mode_5);
    lv_obj_set_pos(ui->scrOven_Label_Mode5, 210, 44);
    lv_obj_set_size(ui->scrOven_Label_Mode5, 152, 44);
    lv_label_set_text(ui->scrOven_Label_Mode5, "Grill");
    lv_label_set_long_mode(ui->scrOven_Label_Mode5, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode5, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode5, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes scrOven_Img_Mode6
    ui->scrOven_Img_Mode6 = lv_image_create(ui->scrOven_Tile_Mode_Mode_6);
    lv_obj_set_pos(ui->scrOven_Img_Mode6, 61, 23);
    lv_obj_set_size(ui->scrOven_Img_Mode6, 61, 61);
    lv_obj_add_flag(ui->scrOven_Img_Mode6, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_Mode6, &_icn_oven_fan_gril_RGB565A8_61x61);
    lv_image_set_pivot(ui->scrOven_Img_Mode6, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_Mode6, 0);

    //Write style for scrOven_Img_Mode6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_Mode6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Mode6
    ui->scrOven_Label_Mode6 = lv_label_create(ui->scrOven_Tile_Mode_Mode_6);
    lv_obj_set_pos(ui->scrOven_Label_Mode6, 160, 44);
    lv_obj_set_size(ui->scrOven_Label_Mode6, 328, 55);
    lv_label_set_text(ui->scrOven_Label_Mode6, "Fan Forced Grill");
    lv_label_set_long_mode(ui->scrOven_Label_Mode6, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode6, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode6, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes scrOven_Img_Mode7
    ui->scrOven_Img_Mode7 = lv_image_create(ui->scrOven_Tile_Mode_Mode_7);
    lv_obj_set_pos(ui->scrOven_Img_Mode7, 56, 17);
    lv_obj_set_size(ui->scrOven_Img_Mode7, 61, 61);
    lv_obj_add_flag(ui->scrOven_Img_Mode7, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_Mode7, &_icn_oven_upper_RGB565A8_61x61);
    lv_image_set_pivot(ui->scrOven_Img_Mode7, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_Mode7, 0);

    //Write style for scrOven_Img_Mode7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_Mode7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Mode7
    ui->scrOven_Label_Mode7 = lv_label_create(ui->scrOven_Tile_Mode_Mode_7);
    lv_obj_set_pos(ui->scrOven_Label_Mode7, 144, 32);
    lv_obj_set_size(ui->scrOven_Label_Mode7, 381, 55);
    lv_label_set_text(ui->scrOven_Label_Mode7, "Upper Outer Element");
    lv_label_set_long_mode(ui->scrOven_Label_Mode7, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode7, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode7, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes scrOven_Img_Mode8
    ui->scrOven_Img_Mode8 = lv_image_create(ui->scrOven_Tile_Mode_Mode_8);
    lv_obj_set_pos(ui->scrOven_Img_Mode8, 61, 23);
    lv_obj_set_size(ui->scrOven_Img_Mode8, 61, 61);
    lv_obj_add_flag(ui->scrOven_Img_Mode8, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_Mode8, &_icn_oven_lower_RGB565A8_61x61);
    lv_image_set_pivot(ui->scrOven_Img_Mode8, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_Mode8, 0);

    //Write style for scrOven_Img_Mode8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_Mode8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Mode8
    ui->scrOven_Label_Mode8 = lv_label_create(ui->scrOven_Tile_Mode_Mode_8);
    lv_obj_set_pos(ui->scrOven_Label_Mode8, 138, 41);
    lv_obj_set_size(ui->scrOven_Label_Mode8, 392, 64);
    lv_label_set_text(ui->scrOven_Label_Mode8, "Lower Outer Element");
    lv_label_set_long_mode(ui->scrOven_Label_Mode8, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode8, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes scrOven_Img_Mode9
    ui->scrOven_Img_Mode9 = lv_image_create(ui->scrOven_Tile_Mode_Mode_9);
    lv_obj_set_pos(ui->scrOven_Img_Mode9, 74, 17);
    lv_obj_set_size(ui->scrOven_Img_Mode9, 61, 61);
    lv_obj_add_flag(ui->scrOven_Img_Mode9, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scrOven_Img_Mode9, &_icn_oven_defrost_RGB565A8_61x61);
    lv_image_set_pivot(ui->scrOven_Img_Mode9, 50,50);
    lv_image_set_rotation(ui->scrOven_Img_Mode9, 0);

    //Write style for scrOven_Img_Mode9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scrOven_Img_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scrOven_Img_Mode9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_Label_Mode9
    ui->scrOven_Label_Mode9 = lv_label_create(ui->scrOven_Tile_Mode_Mode_9);
    lv_obj_set_pos(ui->scrOven_Label_Mode9, 210, 35);
    lv_obj_set_size(ui->scrOven_Label_Mode9, 162, 44);
    lv_label_set_text(ui->scrOven_Label_Mode9, "Defrost");
    lv_label_set_long_mode(ui->scrOven_Label_Mode9, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_Label_Mode9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_Label_Mode9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_Label_Mode9, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_Label_Mode9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_Label_Mode9, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_Label_Mode9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_Label_Mode9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_btnBack
    ui->scrOven_btnBack = lv_button_create(ui->scrOven);
    lv_obj_set_pos(ui->scrOven_btnBack, 0, 0);
    lv_obj_set_size(ui->scrOven_btnBack, 205, 150);
    ui->scrOven_btnBack_label = lv_label_create(ui->scrOven_btnBack);
    lv_label_set_text(ui->scrOven_btnBack_label, "");
    lv_label_set_long_mode(ui->scrOven_btnBack_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrOven_btnBack_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrOven_btnBack, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrOven_btnBack_label, LV_PCT(100));

    //Write style for scrOven_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrOven_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrOven_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_btnBack, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->scrOven_btnBack, &_back_button_RGB565A8_205x150, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->scrOven_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->scrOven_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_btnBack, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_labelOven
    ui->scrOven_labelOven = lv_label_create(ui->scrOven);
    lv_obj_set_pos(ui->scrOven_labelOven, 0, 717);
    lv_obj_set_size(ui->scrOven_labelOven, 640, 64);
    lv_label_set_text(ui->scrOven_labelOven, "Oven");
    lv_label_set_long_mode(ui->scrOven_labelOven, LV_LABEL_LONG_WRAP);

    //Write style for scrOven_labelOven, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrOven_labelOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_labelOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_labelOven, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_labelOven, &lv_font_montserratMedium_37, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_labelOven, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrOven_labelOven, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrOven_labelOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_labelOven, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrOven_labelOven, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrOven_labelOven, lv_color_hex(0x47494b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrOven_labelOven, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->scrOven_labelOven, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->scrOven_labelOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->scrOven_labelOven, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrOven_labelOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrOven_labelOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrOven_labelOven, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrOven_labelOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_labelOven, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrOven_btnOpen
    ui->scrOven_btnOpen = lv_button_create(ui->scrOven);
    lv_obj_set_pos(ui->scrOven_btnOpen, 98, 291);
    lv_obj_set_size(ui->scrOven_btnOpen, 544, 426);
    ui->scrOven_btnOpen_label = lv_label_create(ui->scrOven_btnOpen);
    lv_label_set_text(ui->scrOven_btnOpen_label, "");
    lv_label_set_long_mode(ui->scrOven_btnOpen_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrOven_btnOpen_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrOven_btnOpen, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrOven_btnOpen_label, LV_PCT(100));

    //Write style for scrOven_btnOpen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrOven_btnOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrOven_btnOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrOven_btnOpen, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrOven_btnOpen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrOven_btnOpen, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrOven_btnOpen, &lv_font_montserratMedium_42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrOven_btnOpen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrOven_btnOpen, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrOven.
    ui_oven_init();

    //Update current screen layout.
    lv_obj_update_layout(ui->scrOven);

    //Init events for screen.
    events_init_scrOven(ui);
}
