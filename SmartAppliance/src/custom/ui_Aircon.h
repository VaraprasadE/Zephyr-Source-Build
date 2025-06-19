/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef UI_AIRCON_H_
#define UI_AIRCON_H_

#include "gui_guider.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define AIRCON_TEMP_MIN         16
#define AIRCON_TEMP_MAX         32
#define AIRCON_TIMERHOUR_MAX    24

typedef enum
{
       kAIRCON_TempDown,
       kAIRCON_TempUp,
} AIRCON_Temp_T;

typedef enum
{
       kAIRCON_TimerDown,
       kAIRCON_TimerUp,
} AIRCON_Timer_T;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void ui_aircon_update_temp (uint32_t temp, AIRCON_Temp_T state);

void ui_aircon_update_timer (uint32_t hour, AIRCON_Timer_T state);

#endif /* UI_AIRCON_H_ */
