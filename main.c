//*----------------------------------------------------------------------------
//*         ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name: 		main.c
//* Object: 		main application written in C
//* Creation: 		JPP   16/Jun/2004
//* Modifications:	Steve Weddell for ENEL353/COSC361, March, 2008
//* Purpose:		Produces a "Knight-Rider" effect on a bank of 8-LEDs
//*----------------------------------------------------------------------------

// Include Standard files
#include "Board.h"

#include "display.h"

/* Global variables */
#define SPEED 		(MCKKHz/20)
unsigned int LedSpeed = SPEED *50 ;
const int led_mask[8]= {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

//Function Prototypes
static void change_speed ( void );
static void wait ( void );


//*--------------------------------------------------------------------------------------
//* Function Name       : change_speed
//* Object              : Adjust "LedSpeed" value depending on SW1 and SW3 are pressed or not
//* Input Parameters    : none
//* Output Parameters   : Update of LedSpeed value.
//*--------------------------------------------------------------------------------------
static void change_speed ( void )
{//* Begin
    if ( (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & SW1) == 0 )
    {
        if ( LedSpeed > SPEED ) LedSpeed -=SPEED ;
    }
    if ( (AT91F_PIO_GetInput(AT91C_BASE_PIOA) & SW3) == 0 )
    {
        if ( LedSpeed < MCK ) LedSpeed +=SPEED ;
    }
}//* End

//*--------------------------------------------------------------------------------------
//* Function Name       : wait
//* Object              : Software waiting loop
//* Input Parameters    : none. Waiting time is defined by the global variable LedSpeed.
//* Output Parameters   : none
//*--------------------------------------------------------------------------------------
static void wait ( void )
{//* Begin
    volatile unsigned int waiting_time ;
    //change_speed () ;
    for(waiting_time = 0; waiting_time < LedSpeed; waiting_time++) ;
}//* End

//*--------------------------------------------------------------------------------------
//* Function Name       : Main
//* Object              : Software entry point
//* Input Parameters    : none.
//* Output Parameters   : none.
//*--------------------------------------------------------------------------------------
int main(void)
{//* Begin
    int i;
    // First, enable the clock of the PIO
       //AT91F_PMC_EnablePeriphClock ( AT91C_BASE_PMC, 1 << AT91C_ID_PIOA ) ;

    // then, we configure the PIO Lines corresponding to LED1 to LED8
    // to be outputs. No need to set these pins to be driven by the PIO because it is GPIO pins only.
       AT91F_PIO_CfgOutput( AT91C_BASE_PIOA, 65535 ) ;

    // Illuminate all the LED's. On the ECE interface board we apply a Logic-1 (3.3V)
       AT91F_PIO_SetOutput( AT91C_BASE_PIOA, LED_MASK ) ;
    
	// Turn-off all the LEDs, assuming common cathod configuration, apply a Logic-0 (0V) to each LED    
       AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, LED_MASK) ;

	
	//for (i = 0; i < 4; i++) AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, 1<<(i+4)) ;
	//for (i = 4; i < 12; i++) AT91F_PIO_SetOutput( AT91C_BASE_PIOA, 1<<(i+4)) ;
	for (i = 0; i < 8; i++) AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, 1<<(i+8)) ;

	
	setSegment(0,'T');
	setSegment(1,'I');
	setSegment(2,'T');
	setSegment(3,'S');
	
	//display[0]='a';
	//display[1]='b';
	//display[2]='a';
	//display[3]='a';
	
	
	char* test = "1234567890 ABCDEFGHIJKLMNOPQRSTUVWXYZ    ";
	setDisplay(test);

    // Loop forever
	unsigned int derp = 0, offset = 0;
	char danielAnderson = 0;
	unsigned char hamish = 0;
    for (;;)
    {
		
		//for (i =4; i < 12; i++) AT91F_PIO_SetOutput( AT91C_BASE_PIOA, i) ;
		///for (i =4; i < 12; i++) AT91F_PIO_SetOutput( AT91C_BASE_PIOA, i) ;
		
		//Clear all LEDs of selected segment; 

		displayStep();
		if (derp%300 == 0) 
		{	
			offset++;
			if (offset > 36) offset = 0;
			setDisplay(test+offset);
		}

		
		for (i = 0; i < 5000; i++) ;
		//for (i = 0; i < 31; i++) AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, 1<<((derp-1)%4+7)) ;
		//wait();
		//for (i = 0; i < 31; i++) AT91F_PIO_SetOutput( AT91C_BASE_PIOA, 1<<(derp%4+7)) ;
		//wait();
		//wait();
		//wait();
	
		derp++;
	
	
	
	
	
	
	
	/*
        // Once a Shot on each led
	for ( i=0 ; i < NB_LEB ; i++ )
        {
	    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, led_mask[i]) ;
	    wait();
	    AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, led_mask[i] ) ;
	    wait();
        }// End for
        // Once a Shot on each led
        for ( i=(NB_LEB-1) ; i >= 0 ; i-- )
        {
	    AT91F_PIO_SetOutput( AT91C_BASE_PIOA, led_mask[i]) ;
	    wait();
	    AT91F_PIO_ClearOutput( AT91C_BASE_PIOA, led_mask[i] ) ;
	    wait();
        }*/
    }// End for
}//* End
