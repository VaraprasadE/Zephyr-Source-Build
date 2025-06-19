/*
 * Copyright 2024 NXP
 * NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
 * activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
 * terms, then you may not retain, install, activate or otherwise use the software.
 */

#include "ui_Oven.h"
#include "lvgl.h"
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static uint16_t lv_obj_get_tile_id(lv_obj_t *obj);
static void oven_wheel_scroll_event_cb(lv_event_t *e);

/*******************************************************************************
 * Variables
 ******************************************************************************/
lv_obj_t *ui_Label_Target_Temp_Numer;
uint16_t Oven_Mode = kOVEN_ModeFFRE;

/*******************************************************************************
 * Function
 ******************************************************************************/

/*Complete Oven setting*/
void ui_oven_init(void)
{
	/*Set first Tile*/
	lv_obj_set_tile_id(guider_ui.scrOven_Tile_Mode, Oven_Mode, 0, LV_ANIM_OFF);
	/*Oven target temperature*/
	ui_Label_Target_Temp_Numer = lv_label_create(guider_ui.scrOven_Img_TempWheel);

	lv_obj_set_width(ui_Label_Target_Temp_Numer, 80);
	lv_obj_set_height(ui_Label_Target_Temp_Numer, LV_SIZE_CONTENT);
	lv_obj_set_pos(ui_Label_Target_Temp_Numer, -40, 0);
	lv_obj_set_align(ui_Label_Target_Temp_Numer, LV_ALIGN_RIGHT_MID);
	lv_label_set_text(ui_Label_Target_Temp_Numer, "150");
	lv_obj_set_style_text_color(ui_Label_Target_Temp_Numer, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_Label_Target_Temp_Numer, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui_Label_Target_Temp_Numer, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui_Label_Target_Temp_Numer, &lv_font_montserratMedium_26, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_set_flex_flow(guider_ui.scrOven_Group_TarTemp, LV_FLEX_FLOW_COLUMN);
	lv_obj_set_flex_align(guider_ui.scrOven_Group_TarTemp, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
	lv_obj_set_style_pad_row(guider_ui.scrOven_Group_TarTemp, 20, 0);

	lv_obj_add_event_cb(guider_ui.scrOven_Group_TarTemp, oven_wheel_scroll_event_cb, LV_EVENT_SCROLL, ui_Label_Target_Temp_Numer);
	lv_obj_set_scroll_snap_y(guider_ui.scrOven_Group_TarTemp, LV_SCROLL_SNAP_CENTER);

	uint32_t i;
	for (i = 0; i < 20; i++)
	{
		lv_obj_t *label = lv_label_create(guider_ui.scrOven_Group_TarTemp);
		lv_label_set_text_fmt(label, "%d", 150 + i * 5);
		lv_obj_set_width(label, 60);
	}

	lv_obj_move_foreground(guider_ui.scrOven_Img_TempWheel);
	lv_obj_move_foreground(guider_ui.scrOven_Label_SelTemp);
	lv_obj_move_foreground(guider_ui.scrOven_Label_TarCen);

	lv_obj_update_layout(guider_ui.scrOven_Group_TarTemp);
	lv_obj_update_snap(guider_ui.scrOven_Group_TarTemp, LV_ANIM_OFF);
	lv_obj_send_event(guider_ui.scrOven_Group_TarTemp, LV_EVENT_SCROLL, NULL);

	/*Oven Timer*/
	lv_obj_t *ui_Label_Timer_Number;
	ui_Label_Timer_Number = lv_label_create(guider_ui.scrOven_Img_TimerWheel);

	lv_obj_set_width(ui_Label_Timer_Number, 80);
	lv_obj_set_height(ui_Label_Timer_Number, LV_SIZE_CONTENT);
	lv_obj_set_pos(ui_Label_Timer_Number, -40, 0);
	lv_obj_set_align(ui_Label_Timer_Number, LV_ALIGN_RIGHT_MID);
	lv_label_set_text(ui_Label_Timer_Number, "15");
	lv_obj_set_style_text_color(ui_Label_Timer_Number, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui_Label_Timer_Number, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui_Label_Timer_Number, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui_Label_Timer_Number, &lv_font_montserratMedium_26, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_set_flex_flow(guider_ui.scrOven_Group_Timer, LV_FLEX_FLOW_COLUMN);
	lv_obj_set_flex_align(guider_ui.scrOven_Group_Timer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
	lv_obj_set_style_pad_row(guider_ui.scrOven_Group_Timer, 20, 0);
	lv_obj_add_event_cb(guider_ui.scrOven_Group_Timer, oven_wheel_scroll_event_cb, LV_EVENT_SCROLL, ui_Label_Timer_Number);
	lv_obj_set_scroll_snap_y(guider_ui.scrOven_Group_Timer, LV_SCROLL_SNAP_CENTER);
	for (i = 0; i < 17; i++)
	{
		lv_obj_t *label = lv_label_create(guider_ui.scrOven_Group_Timer);
		lv_label_set_text_fmt(label, "%d", i * 5 + 10);
		lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_RIGHT, 0);
		lv_obj_set_width(label, 60);
	}

	lv_obj_move_foreground(guider_ui.scrOven_Img_TimerWheel);
	lv_obj_move_foreground(guider_ui.scrOven_Label_SelTimer);
	lv_obj_move_foreground(guider_ui.scrOven_Label_TimerSel);

	lv_obj_update_layout(guider_ui.scrOven_Group_Timer);
	lv_obj_update_snap(guider_ui.scrOven_Group_Timer, LV_ANIM_OFF);
	lv_obj_send_event(guider_ui.scrOven_Group_Timer, LV_EVENT_SCROLL, NULL);
}

void ui_oven_set_Temperature(uint32_t temp)
{
	uint32_t i;

	for (i = 0; i < 20; i++)
	{
		if (temp == (150 + i * 5))
		{
			break;
		}
	}

	lv_obj_scroll_to_y(guider_ui.scrOven_Group_TarTemp, (-108 + 40 * i), LV_ANIM_ON);
}

void ui_oven_set_Timer(uint32_t time)
{
	uint32_t i;

	for (i = 0; i < 20; i++)
	{
		if (time == (10 + i * 5))
		{
			break;
		}
	}
	lv_obj_scroll_to_y(guider_ui.scrOven_Group_Timer, (-108 + 40 * i), LV_ANIM_ON);
}

/*******************************************************************************
 * Static function
 ******************************************************************************/

static uint16_t lv_obj_get_tile_id(lv_obj_t *obj)
{
	lv_obj_t *tile_obj = lv_tileview_get_tile_act(obj);

	lv_coord_t tx = lv_obj_get_x(tile_obj);
	lv_coord_t ty = lv_obj_get_y(tile_obj);

	uint32_t i;
	for (i = 0; i < lv_obj_get_child_cnt(obj); i++)
	{
		tile_obj = lv_obj_get_child(obj, i);
		lv_coord_t x = lv_obj_get_x(tile_obj);
		lv_coord_t y = lv_obj_get_y(tile_obj);
		if (x == tx && y == ty)
		{
			return 8 - i;
		}
	}

	return 0;
}

static void oven_wheel_scroll_event_cb(lv_event_t *e)
{
	lv_obj_t *cont = lv_event_get_target(e);

	lv_area_t cont_a;
	lv_obj_get_coords(cont, &cont_a);
	lv_coord_t cont_y_center = cont_a.y1 + lv_area_get_height(&cont_a) / 2;

	int32_t inv = lv_obj_get_style_flex_track_place(cont, 0) == LV_FLEX_ALIGN_START ? 1 : -1;
	lv_coord_t y_min = LV_COORD_MAX;
	lv_obj_t *y_min_obj = NULL;
	lv_coord_t r = lv_obj_get_height(cont) * 55 / 100;
	uint32_t i;
	uint32_t child_cnt = lv_obj_get_child_cnt(cont);
	for (i = 0; i < child_cnt; i++)
	{
		lv_obj_t *child = lv_obj_get_child(cont, i);
		if (lv_obj_has_flag(child, LV_OBJ_FLAG_FLOATING))
			continue;
		lv_area_t child_a;
		lv_obj_get_coords(child, &child_a);

		lv_coord_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;
		lv_coord_t diff_y = child_y_center - cont_y_center;
		diff_y = LV_ABS(diff_y);
		if (diff_y < y_min)
		{
			y_min = diff_y;
			y_min_obj = child;
		}

		/*Get the x of diff_y on a circle.*/
		lv_coord_t x;
		/*If diff_y is out of the circle use the last point of the circle (the radius)*/
		if (diff_y >= r)
		{
			x = r;
		}
		else
		{
			/*Use Pythagoras theorem to get x from radius and y*/
			uint32_t x_sqr = r * r - diff_y * diff_y;
			lv_sqrt_res_t res;
			lv_sqrt(x_sqr, &res, 0x8000); /*Use lvgl's built in sqrt root function*/
			x = r - res.i;
		}

		/*Translate the item by the calculated X coordinate*/
		lv_obj_set_style_translate_x(child, inv * x, 0);
	}

	lv_obj_t *large_label = lv_event_get_user_data(e);
	int timer = atoi(lv_label_get_text(y_min_obj));
	lv_label_set_text(large_label, lv_label_get_text(y_min_obj));
	if (cont == guider_ui.scrOven_Group_TarTemp)
	{
		lv_label_set_text(guider_ui.scrOven_Label_Temp, lv_label_get_text(y_min_obj));
	}
	else if (cont == guider_ui.scrOven_Group_Timer)
	{
		lv_label_set_text(guider_ui.scrOven_Label_TimeLeft, lv_label_get_text(y_min_obj));
		/*set the timer bar*/
		lv_bar_set_value(guider_ui.scrOven_Bar_Time, timer / 0.9, LV_ANIM_OFF);
	}
}
