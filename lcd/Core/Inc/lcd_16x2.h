/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                 *
 *                                  lcd_bvh.h                                      *
 *                                                                                 *
 *                        writed by BUI VAN HUY 16/10/2019                         *
 *                                 16ETE - DUT                                     *
 *                                                                                 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __LCD_16X2_H__
#define __LCD_16X2_H__

#include "stm32f1xx_hal.h"
#include "string.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

//#define PIN
#define RS_Pin           GPIO_PIN_14
#define RS_GPIO_Port     GPIOC

#define EN_Pin           GPIO_PIN_15
#define EN_GPIO_Port     GPIOC

#define RW_Pin           GPIO_PIN_13
#define RW_GPIO_Port     GPIOC

#define D4_Pin           GPIO_PIN_12
#define D4_GPIO_Port     GPIOB

#define D5_Pin           GPIO_PIN_13
#define D5_GPIO_Port     GPIOB

#define D6_Pin           GPIO_PIN_14
#define D6_GPIO_Port     GPIOB

#define D7_Pin           GPIO_PIN_15
#define D7_GPIO_Port     GPIOB

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define LCD_MODE LCD_4_BIT_MODE

//#define address 
#define SET_CGRAM_ADDRESS	 	    	0x40
// Number of visible lines of the display (1 or 2)
#define LINES									   	2
// DDRAM address of first char of line 1
#define START_LINE_1					   	0x00
// DDRAM address of first char of line 2
#define START_LINE_2				  		0x40
#define SET_DDRAM_ADDRESS	 	     	0x80


#define LCD16xN			// For 16xN LCDs

/************************************** Command register **************************************/
#define CLEAR_DISPLAY 					  0x01

#define RETURN_HOME 		    			0x02

#define ENTRY_MODE_SET            0x04
#define OPT_S                   	0x01					// Shift entire display to right
#define OPT_INC 					        0x02					// Cursor increment

#define DISPLAY_ON_OFF_CONTROL    0x08
#define OPT_D	                    0x04					// Turn on display
#define OPT_C											0x02					// Turn on cursor
#define OPT_B 									  0x01					// Turn on cursor blink

#define CURSOR_DISPLAY_SHIFT      0x10		// Move and shift cursor
#define OPT_SC 										0x08
#define OPT_RL 										0x04

#define FUNCTION_SET					    0x20
#define OPT_DL 										0x10						// Set interface data length
#define OPT_N 										0x08						// Set number of display lines
#define OPT_F 										0x04						// Set alternate font

#define SET_DDRAM_ADDR 					  0x80				// Set DDRAM address

/************************************** LCD defines **************************************/
#define LCD_NIB				  	 4
#define LCD_BYTE					 8
#define LCD_DATA_REG         GPIO_PIN_SET
#define LCD_COMMAND_REG      GPIO_PIN_RESET


/************************************** LCD typedefs **************************************/
#define Lcd_PortType  GPIO_TypeDef*
#define Lcd_PinType   uint16_t



/************************************** Public functions **************************************/
void    Lcd_Init(void);
void    Lcd_clear_xy(uint8_t x,uint8_t y);
void    Lcd_write_custom_char( uint8_t x, uint8_t y, uint8_t location);
void    Lcd_gotoxy( uint8_t x, uint8_t y);
void    Lcd_create_custom_char(uint8_t location, uint8_t* data_bytes);
void    Lcd_clear_display(void); 
void    Lcd_write_string(char * string);
void    Lcd_write_int(int number);
	


#endif /* __LCD_16X2_H__ */
