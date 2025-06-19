/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


#ifndef UI_OVEN_H_
#define UI_OVEN_H_

#include "gui_guider.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define FADE_ANIM_TIME			300

typedef enum
{
	kOVEN_ModeFFRE,
	kOVEN_ModeULEC,
	kOVEN_ModeFFULC,
	kOVEN_ModeFFLEC,
	kOVEN_ModeGrill,
	kOVEN_ModeFFG,
	kOVEN_ModeUOE,
	kOVEN_ModeLOE,
	kOVEN_ModeDeFrost,
	kOVEN_ModeNull
} OVEN_MODE_T;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void ui_oven_init (void);

void ui_oven_set_Temperature(uint32_t temp);

void ui_oven_set_Timer(uint32_t time);

#endif /* UI_OVEN_H_ */
