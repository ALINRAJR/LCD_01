/*
===============================================================================
 Name        : 12_Day29_24092021_LCD001.c

 Description : LCD 8 bit mode



 Layered Architecture used for this project
 ************************************
 Application layer-12_Day29_24092021_LCD001.c
 ************************************
 Board layer - lcd.c/.h, configboard.h
 ************************************
 Low level drivers or chip level - gpio.c/.h
 ************************************
 Hardware
 ************************************

===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "lcd.h"

/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{

	vLCDInitialize();
	vLCDInitialCommands();

}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();
   vLCDWriteData('A');
   vLCDWriteData('B');
   vLCDGotoxy(LINE0,COL5);
   vLCDWriteString("TRANSIOT");
   vLCDGotoxy(LINE1,COL0);
   vLCDWriteNum(1234,HEXADECIMAL);
   vLCDGotoxy(LINE1,COL6);
   vLCDWriteNum(1234,OCTAL);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {


  }
  /* End of Application entry point */
}




