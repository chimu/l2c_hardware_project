/*----------------------------------------------------------------------------
*         ATMEL Microcontroller Software Support  -  ROUSSET  -
*----------------------------------------------------------------------------
* The software is delivered "AS IS" without warranty or condition of any
* kind, either express, implied or statutory. This includes without
* limitation any warranty or condition with respect to merchantability or
* fitness for any particular purpose, or against the infringements of
* intellectual property rights of others.
*----------------------------------------------------------------------------
* File Name           : Board.h
* Object              : AT91SAM7S Evaluation Board Features Definition File.
*
* Creation            : JPP   16/Jun/2004
* Modifications	      : Steve Weddell  March, 2008
* V 1.0 21/Feb/05 JPP : Define __ramfunc
* V 1.1 21/Feb/05 JPP : add Lib definition
* V 1.2 22/Feb/05 JPP : Add DBGU inline definition
*----------------------------------------------------------------------------
*/
#ifndef Board_h
#define Board_h

#include "AT91SAM7S64.h"
#define __inline static inline
#include "lib_AT91SAM7S64.h"

#define __ramfunc

#define true	-1
#define false	0

/*-------------------------------*/
/* SAM7Board Memories Definition */
/*-------------------------------*/
// The AT91SAM7S256 embeds a 64 Kbyte SRAM bank, and 256 KByte Flash

#define  INT_SARM           0x00200000
#define  INT_SARM_REMAP	    0x00000000

#define  INT_FLASH          0x00000000
#define  INT_FLASH_REMAP    0x01000000

#define  FLASH_PAGE_NB	    512
#define  FLASH_PAGE_LOCK    32
#define  FLASH_PAGE_SIZE    128

/*-----------------*/
/* Leds Definition */
/*-----------------*/
/*                                  */
#define LED1        (1<<12)	// PA12    Define the LED output mask
#define LED2        (1<<11)	// PA11 
#define LED3        (1<<10)	// PA10 
#define LED4        (1<<9)	// PA9 
#define LED5        (1<<8)	// PA8 
#define LED6        (1<<7)	// PA7 
#define LED7        (1<<6)	// PA6 
#define LED8        (1<<5)	// PA5 


#define LED_MASK  (LED1 | LED2 | LED3 | LED4 | LED5 | LED6 | LED7 | LED8)

#define NB_LEB 8  // number of LEDs

#define SW1        (1<<15)	// PA15  Set-up the input (switch) mask
#define SW2        (1<<17)	// PA17 
#define SW3        (1<<19)	// PA19 

#define SW_MASK (SW1 | SW2 | SW3)

/*--------------*/
/* Master Clock */
/*--------------*/

#define EXT_OC          18432000   // Exetrnal ocilator MAINCK
#define MCK             47923200   // MCK (PLLRC div by 2)
#define MCKKHz          (MCK/1000) //

#endif /* Board_h */
