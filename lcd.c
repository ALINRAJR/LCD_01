


/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include "lcd.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define DDRAMADDRESSLINE0 0x80
#define DDRAMADDRESSLINE1 0xC0

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

 /**
  * @brief Setting direction for LCD pins connected on board
  * @return None
  **/
void vLCDInitialize(void)
{
#if LCD8BITMODE
	/* TODO DONE */
	/* Setting directions of the data pins of the LCD */
	vGpioSetDir(LCDDATAPORT, LCDDATAPIN_D0, OUTPUT);
	vGpioSetDir(LCDDATAPORT, LCDDATAPIN_D1, OUTPUT);
	vGpioSetDir(LCDDATAPORT, LCDDATAPIN_D2, OUTPUT);
	vGpioSetDir(LCDDATAPORT, LCDDATAPIN_D3, OUTPUT);
	vGpioSetDir(LCDDATAPORT, LCDDATAPIN_D4, OUTPUT);
	vGpioSetDir(LCDDATAPORT, LCDDATAPIN_D5, OUTPUT);
	vGpioSetDir(LCDDATAPORT, LCDDATAPIN_D6, OUTPUT);
	vGpioSetDir(LCDDATAPORT, LCDDATAPIN_D7, OUTPUT);

	/* Setting directions of the control pins of the LCD */
	vGpioSetDir(LCDCTRLPORT, LCDCTRLPIN_RS, OUTPUT);
	vGpioSetDir(LCDCTRLPORT, LCDCTRLPIN_RW, OUTPUT);
	vGpioSetDir(LCDCTRLPORT, LCDCTRLPIN_EN, OUTPUT);

	/* Clearing the control pin RW as we are going to do only write operation always*/
	vGpioClrPin(LCDCTRLPORT, LCDCTRLPIN_RW);

#elif LCD4BITMODE
#endif
}

/**
 * @brief     Crude delay implementation for generating a delay
 * @param[in] count No of times the loop should run
 * @return    No return value
 **/

/* Crude delay implementation for generating a delay */
void vLCDDelay(uint32_t count)
{
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<0xA00;j++);

}

/**
 * @brief Sending initialization commands to LCD controller
 * @return None
 **/
void vLCDInitialCommands(void)
{
#if LCD8BITMODE
	/* TODO DONE
		 * Hint reuse vLCDWriteCommand  and implement the logic	 *
		 *
		 * */
	vLCDWriteCommand(0x38); // 8-BIT MODE
#elif LCD4BITMODE

#endif
	vLCDWriteCommand(0x0F); // cursor blinking
	vLCDWriteCommand(0x06); // entry mode
	vLCDWriteCommand(0x01); // clear screen
}


/**
 * @brief For writing data into the LCD
 * @param[in] data data for writing into LCD
 * @return None
 **/
void vLCDWriteData(uint8_t data)
{
#if LCD8BITMODE
	/* TODO DONE*/
	/* For Data, RS should be 1 */
	vGpioSetPin(LCDCTRLPORT, LCDCTRLPIN_RS);
	/* Writing the 8 byte data into the data pins D0-D7 */
	vGpioSetByte(LCDDATAPORT,LCDDATAPIN_D0,data);
	/* Making EN pin HIGH and LOW to act as an interrupt for the LCD Controller
	 * For notifying the change in values in D0-D7*/
	vGpioSetPin(LCDCTRLPORT, LCDCTRLPIN_EN);
	vLCDDelay(0x50);
	vGpioClrPin(LCDCTRLPORT, LCDCTRLPIN_EN);
	vLCDDelay(0x50);
#elif LCD4BITMODE
#endif
}


/**
 * @brief For writing command into the LCD
 * @param[in] command command for writing into LCD
 * @return None
 **/
void vLCDWriteCommand(uint8_t command)
{
#if LCD8BITMODE
	/* TODO DONE */
	/* For Command, RS should be 0 */
	vGpioClrPin(LCDCTRLPORT, LCDCTRLPIN_RS);
	/* Writing the 8 byte command into the data pins D0-D7 */
	vGpioSetByte(LCDDATAPORT,LCDDATAPIN_D0,command);
	/* Making EN pin HIGH and LOW to act as an interrupt for the LCD Controller
	 * For notifying the change in values in D0-D7*/
	vGpioSetPin(LCDCTRLPORT, LCDCTRLPIN_EN);
	vLCDDelay(0x50);
	vGpioClrPin(LCDCTRLPORT, LCDCTRLPIN_EN);
	vLCDDelay(0x50);

#elif LCD4BITMODE
#endif
}


/**
 * @brief For writing command into the LCD
 * @param[in] string string for writing into LCD
 * @return None
 **/
void vLCDWriteString(uint8_t* string)
{

	/* TODO DONE
	 * Hint reuse vLCDWriteData and implement the logic
	 * */
	while(*string !='\0')
	{
		vLCDWriteData(*string);
		string++;
	}
}


/**
 * @brief For writing command into the LCD
 * @param[in] num num for writing into LCD
 * @param[in] base base of the num for writing into LCD, it can be BINARY,OCTAL,DECIMAL,HEXADECIMAL
 * @return None
 **/
void vLCDWriteNum(uint32_t num, uint8_t base)
{

	/* TODO
	 * Hint reuse vLCDWriteData or vLCDWriteString  and implement the logic the atoi
	 * */


}


/**
 * @brief For writing command into the LCD
 * @param[in] lineno selecting the lineno as either LINE0, LINE1
 * @param[in] columnno column position in the selected line COL0=0,COL1,COL2,COL3,COL4,COL5,
 * 			  COL6,COL7,COL8,COL9,COL10,COL11,COL12,COL13,COL14,COL15
 * @return None
 **/
void vLCDGotoxy(uint8_t lineno, uint8_t columnno)
{
	/* TODO
	 * Hint reuse vLCDWriteCommand  and implement the logic *
	 *
	 * */
	if(lineno==LINE0)
		vLCDWriteCommand(DDRAMADDRESSLINE0+columnno);
	else if(lineno==LINE1)
		vLCDWriteCommand(DDRAMADDRESSLINE1+columnno);

}





