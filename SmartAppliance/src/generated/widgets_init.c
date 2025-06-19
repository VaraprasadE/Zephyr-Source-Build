/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include "gui_guider.h"
#include "widgets_init.h"
#include <stdlib.h>
#include <string.h>


__attribute__((unused)) void kb_event_cb (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
    if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

__attribute__((unused)) void ta_event_cb (lv_event_t *e) {
#if LV_USE_KEYBOARD
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);

    if(code == LV_EVENT_FOCUSED) {
        if(lv_indev_get_type(lv_indev_active()) != LV_INDEV_TYPE_KEYPAD) {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
        }
    }
    else if(code == LV_EVENT_READY) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_state(ta, LV_STATE_FOCUSED);
        lv_indev_reset(NULL, ta);
    }
#endif
}

void clock_count(int *hour, int *min, int *sec)
{
    (*sec)++;
    if(*sec == 60)
    {
        *sec = 0;
        (*min)++;
    }
    if(*min == 60)
    {
        *min = 0;
        if(*hour < 12)
        {
            (*hour)++;
        } else {
            (*hour)++;
            *hour = *hour %12;
        }
    }
}

void digital_clock_count(int * hour, int * minute, int * seconds, char * meridiem)
{

    (*seconds)++;
    if(*seconds == 60) {
        *seconds = 0;
        (*minute)++;
    }
    if(*minute == 60) {
        *minute = 0;
        if(*hour < 12) {
            (*hour)++;
        }
        else {
            (*hour)++;
            (*hour) = (*hour) % 12;
        }
    }
    if(*hour == 12 && *seconds == 0 && *minute == 0) {
        if((lv_strcmp(meridiem, "PM") == 0)) {
            lv_strcpy(meridiem, "AM");
        }
        else {
            lv_strcpy(meridiem, "PM");
        }
    }
}


extern int scrHome_digital_clockTime_hour_value;
extern int scrHome_digital_clockTime_min_value;
extern int scrHome_digital_clockTime_sec_value;

void scrHome_digital_clockTime_timer(lv_timer_t *timer)
{
    clock_count(&scrHome_digital_clockTime_hour_value, &scrHome_digital_clockTime_min_value, &scrHome_digital_clockTime_sec_value);
    if (lv_obj_is_valid(guider_ui.scrHome_digital_clockTime))
    {
        lv_label_set_text_fmt(guider_ui.scrHome_digital_clockTime, "%d:%02d", scrHome_digital_clockTime_hour_value, scrHome_digital_clockTime_min_value);
    }
}

const lv_image_dsc_t * scrAircon_aimgAirconSwing_imgs[15] = {
    &scrAircon_aimgAirconSwingaircon_swing_00,
    &scrAircon_aimgAirconSwingaircon_swing_01,
    &scrAircon_aimgAirconSwingaircon_swing_02,
    &scrAircon_aimgAirconSwingaircon_swing_03,
    &scrAircon_aimgAirconSwingaircon_swing_04,
    &scrAircon_aimgAirconSwingaircon_swing_05,
    &scrAircon_aimgAirconSwingaircon_swing_06,
    &scrAircon_aimgAirconSwingaircon_swing_07,
    &scrAircon_aimgAirconSwingaircon_swing_08,
    &scrAircon_aimgAirconSwingaircon_swing_09,
    &scrAircon_aimgAirconSwingaircon_swing_10,
    &scrAircon_aimgAirconSwingaircon_swing_11,
    &scrAircon_aimgAirconSwingaircon_swing_12,
    &scrAircon_aimgAirconSwingaircon_swing_13,
    &scrAircon_aimgAirconSwingaircon_swing_14,
};
const lv_image_dsc_t * scrAircon_aimgAirconCool_imgs[6] = {
    &scrAircon_aimgAirconCoolaircon_cool_00,
    &scrAircon_aimgAirconCoolaircon_cool_01,
    &scrAircon_aimgAirconCoolaircon_cool_02,
    &scrAircon_aimgAirconCoolaircon_cool_03,
    &scrAircon_aimgAirconCoolaircon_cool_04,
    &scrAircon_aimgAirconCoolaircon_cool_05,
};
const lv_image_dsc_t * scrOven_animimg_Door_imgs[8] = {
    &scrOven_animimg_Dooroven_door_00,
    &scrOven_animimg_Dooroven_door_01,
    &scrOven_animimg_Dooroven_door_02,
    &scrOven_animimg_Dooroven_door_03,
    &scrOven_animimg_Dooroven_door_04,
    &scrOven_animimg_Dooroven_door_05,
    &scrOven_animimg_Dooroven_door_06,
    &scrOven_animimg_Dooroven_door_07,
};
const lv_image_dsc_t * scrOven_animimg_Fan_imgs[4] = {
    &scrOven_animimg_Fanoven_fan_light_0,
    &scrOven_animimg_Fanoven_fan_light_1,
    &scrOven_animimg_Fanoven_fan_light_2,
    &scrOven_animimg_Fanoven_fan_light_3,
};
