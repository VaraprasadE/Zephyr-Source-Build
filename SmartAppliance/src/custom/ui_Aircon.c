/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "ui_Aircon.h"
#include "gui_guider.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint32_t AirconTemp = 25;
uint32_t TimerHour = 1;
int32_t TimerMin = 15;

uint8_t tempSpeed;

/*******************************************************************************
 * Function
 ******************************************************************************/

void ui_aircon_update_temp(uint32_t temp, AIRCON_Temp_T state)
{
	if (temp)
	{
		AirconTemp = temp;
	}
	else
	{
		switch (state)
		{
		case kAIRCON_TempDown:
		{
			AirconTemp--;
			if (AirconTemp < AIRCON_TEMP_MIN)
			{
				AirconTemp = AIRCON_TEMP_MIN;
			}
		}
		break;

		case kAIRCON_TempUp:
		{
			AirconTemp++;
			if (AirconTemp > AIRCON_TEMP_MAX)
			{
				AirconTemp = AIRCON_TEMP_MAX;
			}
		}
		break;
		}
	}
	lv_label_set_text_fmt(guider_ui.scrAircon_labelAirconTemp, "%02" LV_PRIu32, AirconTemp);
}

void ui_aircon_update_timer(uint32_t hour, AIRCON_Timer_T state)
{
	if (hour)
	{
		TimerHour = hour;
	}
	else
	{
		switch (state)
		{
		case kAIRCON_TimerDown:
			TimerMin -= 15;
			break;
		case kAIRCON_TimerUp:
			if(TimerHour >= AIRCON_TIMERHOUR_MAX)
			{
				TimerMin = 0;
			}
			else
			{
				TimerMin += 15;
			}
			break;
		}
	}

	if (TimerMin < 0)
	{
		if (TimerHour > 0)
		{
			TimerMin = 45;
			TimerHour--;
		}
		else
		{
			TimerMin = 0;
		}
	}
	else if (TimerMin == 60)
	{
		TimerMin = 0;
		TimerHour++;
		if(TimerHour > AIRCON_TIMERHOUR_MAX)
		{
			TimerHour = AIRCON_TIMERHOUR_MAX;
		}
	}

	lv_label_set_text_fmt(guider_ui.scrAircon_labelTimerHour, "%02" LV_PRIu32, TimerHour);
	lv_label_set_text_fmt(guider_ui.scrAircon_labelTimerMin, "%02" LV_PRId32, TimerMin);
}
