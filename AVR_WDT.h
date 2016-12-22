//////////////////////////////////////////////
// AVR WATCH DOG TIMER LIBRARY
//
// IF WATCHDOG TIMER ON (WTDON) FUSE IS
// PROGRAMMED / ENABLED THE ONLY MODE WDT 
// CAN WORK IS IN SYSTEM RESET MODE
//
// DECEMBER 22, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////


#ifndef _AVR_WDT_H_
#define _AVR_WDT_H_

#include <stdio.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>

#define AVR_WDT_MODE_INTERRUPT				(1 << WDIE)
#define AVR_WDT_MODE_SYSTEM_RESET			(1 << WDE)
#define AVR_WDT_MODE_INTERRUPT_SYSTEM_RESET (AVR_WDT_MODE_INTERRUPT | AVR_WDT_MODE_SYSTEM_RESET)

#define AVR_WDT_PRESCALE_16MS	((0 << WDP3) | (0 << WDP2) | (0 << WDP1) | (0 << WDP0))
#define AVR_WDT_PRESCALE_32MS	((0 << WDP3) | (0 << WDP2) | (0 << WDP1) | (1 << WDP0))
#define AVR_WDT_PRESCALE_64MS	((0 << WDP3) | (0 << WDP2) | (1 << WDP1) | (0 << WDP0))
#define AVR_WDT_PRESCALE_125MS	((0 << WDP3) | (0 << WDP2) | (1 << WDP1) | (1 << WDP0))
#define AVR_WDT_PRESCALE_250MS	((0 << WDP3) | (1 << WDP2) | (0 << WDP1) | (0 << WDP0))
#define AVR_WDT_PRESCALE_500MS	((0 << WDP3) | (1 << WDP2) | (0 << WDP1) | (1 << WDP0))
#define AVR_WDT_PRESCALE_1000MS	((0 << WDP3) | (1 << WDP2) | (1 << WDP1) | (0 << WDP0))
#define AVR_WDT_PRESCALE_2000MS	((0 << WDP3) | (1 << WDP2) | (1 << WDP1) | (1 << WDP0))
#define AVR_WDT_PRESCALE_4000MS	((1 << WDP3) | (0 << WDP2) | (0 << WDP1) | (0 << WDP0))
#define AVR_WDT_PRESCALE_8000MS	((1 << WDP3) | (0 << WDP2) | (0 << WDP1) | (1 << WDP0))

void AVR_WDT_Enable(uint8_t wdt_mode, uint8_t wdt_prescale);
void AVR_WDT_Check_Reset_Flag(void);
void AVR_WDT_Reset(void);
void AVR_WDT_Disable(void);

#endif
