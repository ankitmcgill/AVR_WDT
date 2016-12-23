//////////////////////////////////////////////
// AVR WATCH DOG TIMER LIBRARY
//
// IF WATCHDOG TIMER ON (WTDON) FUSE IS
// PROGRAMMED / ENABLED THE ONLY MODE WDT 
// CAN WORK IS IN SYSTEM RESET MODE
//
// NOTE : BEFORE DOING ANY KIND OF OPERATION
//		  ON WATCHDOG, MAKE SURE TO DISABLE
//		  GLOBAL INTERRUPTS ! USERS
//		  RESPONSIBILITY. THE LIBRARY WON'T
//		  DO IT AUTOMATICALLY !!
//
// DECEMBER 22, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////


#ifndef _AVR_WDT_H_
#define _AVR_WDT_H_

#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>

#define AVR_WDT_MODE_INTERRUPT				(1 << WDIE)
#define AVR_WDT_MODE_SYSTEM_RESET			(1 << WDE)
#define AVR_WDT_MODE_INTERRUPT_SYSTEM_RESET (AVR_WDT_MODE_INTERRUPT | AVR_WDT_MODE_SYSTEM_RESET)

#define AVR_WDT_PRESCALE_16MS	WDTO_15MS
#define AVR_WDT_PRESCALE_32MS	WDTO_30MS
#define AVR_WDT_PRESCALE_64MS	WDTO_60MS
#define AVR_WDT_PRESCALE_125MS	WDTO_120MS
#define AVR_WDT_PRESCALE_250MS	WDTO_250MS
#define AVR_WDT_PRESCALE_500MS	WDTO_500MS
#define AVR_WDT_PRESCALE_1000MS	WDTO_1S
#define AVR_WDT_PRESCALE_2000MS	WDTO_2S
#define AVR_WDT_PRESCALE_4000MS	WDTO_4S
#define AVR_WDT_PRESCALE_8000MS	WDTO_8S

void AVR_WDT_Enable(uint8_t wdt_mode, uint8_t wdt_prescale);
uint8_t AVR_WDT_Check_Reset_Flag(void);
void AVR_WDT_Clear_Reset_Flag(void);
void AVR_WDT_Reset(void);
void AVR_WDT_Disable(void);

#endif
