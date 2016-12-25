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
//		  ON NEWER AVR (THE ONES THAT SUPPORT WDT
//		  INTERRUPT MODE), IF THE MCU RESETS BECAUSE
//		  OF WDT, THE WDRF BIT DOES NOT GET CLEARED ON
//		  RESTART AND THE WDT REMAINS ACTIVE WITH THE
//		  SMALLEST TIME UNIT. SO THE MCU KEEPS ON
//		  RESETTING IN ENDLESS CYCLE. SO THIS BIT
//		  NEEDS TO BE CHECKED AND CLEARED BY USER
//		  PROGRAM AS EARLY AS POSSIBLE ON RESTART.
//		  THIS BIT CAN SOMETIMES ALSO GET SET ERRANEOUSLY
//		  SO ITS ALWAYS A GOOD PRACTICE TO CHECK FOR IT
//		  WHEN THE PROGRAM STARTS
//	
//
// DECEMBER 22, 2016
//
// ANKIT BHATNAGAR
// ANKIT.BHATNAGARINDIA@GMAIL.COM
//////////////////////////////////////////////

#include "AVR_WDT.h"

void AVR_WDT_Enable(uint8_t wdt_mode, uint8_t wdt_prescale)
{
	//ENABLE WATCH DOG TIMER (WDT) IN
	//THE SPECIFIED MODE AND WITH SPECIFIED
	//TIME PERIOD
	//GLOBAL INTERRUPTS DISABLED FOR THE DURATION OF 
	//EXECUTION OF THIS FUNCTION !
	
	wdt_enable(wdt_prescale);

	//SET THE NEW MODE
	WDTCSR |= wdt_mode;
}

void AVR_WDT_Reset(void)
{
	//RESET THE WATCH DOG TIMER (WDT)
	//TO PREVENT WDT TIMEOUT
	
	wdt_reset();
}

void AVR_WDT_Disable(void)
{
	//DISABLE THE WATCH DOG TIMER (WDT)
	//CLEARS THE WDT TIMER COUNT ALSO
	//EXTERNAL GLOBAL INTERRUPTS DISABLED FOR THE
	//DURATION OF EXECUTION OF THIS FUNCTION !

	//ENABLE WATCHDOG CHANGE ENABLE
	WDTCSR |= ((1 << WDCE) | (1 << WDE));
	
	//DISABLE WATCHDOG
	wdt_disable();
}

uint8_t AVR_WDT_Check_Reset_Flag(void)
{
	//CHECK THE WDRF FLAG IN MCUSR TO
	//SEE IF THE MCU GOT RESET BECAUSE OF
	//WATCHDOG TIMEOUT
	
	return ((MCUSR & (1 << WDRF)) ? 1 : 0);
}

void AVR_WDT_Clear_Reset_Flag(void)
{
	//CLEAR THE WDT RESET FLAG IF PRESENT
	//AS THIS IS NOT DONE AUTOMATICALLY BY THE
	//SYSTEM UPON WDT SYSTEM RESET AND DISABLE WATCHDOG
	//NOTE: ONLY REQUIRED FOR NEVER AVR SUPPORTING
	//WDT INTERRUPT MODE !
	//
	//THIS DISABLES THE WDT ALSO
	
	//CLEAR FLAG
	MCUSR = 0x00;
	//DISABLE WATCHDOG TIMER
	wdt_disable();
}

void AVR_WDT_Reenable_Interrupt(void)
{
	//RE-ENABLE THE WATCHDOG TIMER INTERRUPT
	//THIS SHOULD BE USED INSIDE THE WDT
	//ISR WHEN USING WDT IN INTERRUPT MODE,
	//WHEN WDT ISR EXECUTES, THE WDT INTERRUPT
	//IS DISABLED, AND IF NOT RE-ENABLED IT
	//SET THE RESET MODE AND THE SYSTEM
	//WILL RESTART ON NEXT WDT TIMEOUT

	WDTCSR |= (1 << WDIE);
}

