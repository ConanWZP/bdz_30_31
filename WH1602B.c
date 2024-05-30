#include "WH1602B.h"
#include "timerForDisplay.h"

void WriteBits8(uint8_t RS,uint8_t RW, uint8_t D7,uint8_t D6,uint8_t D5,uint8_t D4,uint8_t D3,uint8_t D2,uint8_t D1,uint8_t D0)
{
	(RS == 1)?(RS1()):(RS0());
  (RW == 1)?(RW1()):(RW0());
	Delay_us(1);
   	
	E1();
	Delay_us(1); 	
	
	(D7 == 1)?(D7_Set()):(D7_Reset());  
	(D6 == 1)?(D6_Set()):(D6_Reset());
	(D5 == 1)?(D5_Set()):(D5_Reset());
	(D4 == 1)?(D4_Set()):(D4_Reset()); 
	(D3 == 1)?(D3_Set()):(D3_Reset());
	(D2 == 1)?(D2_Set()):(D2_Reset());
	(D1 == 1)?(D1_Set()):(D1_Reset());
	(D0 == 1)?(D0_Set()):(D0_Reset());
	Delay_us(1);                    	
	
	E0();
  Delay_us(1);
}

void LCD_Init8()
{
	HAL_Delay(20);
	WriteBits8(0,0,0,0,1,1,0,0,0,0);
	HAL_Delay(5);	
	WriteBits8(0,0,0,0,1,1,0,0,0,0);
  HAL_Delay(2);	
	WriteBits8(0,0,0,0,1,1,0,0,0,0);
	HAL_Delay(2);	
	WriteBits8(0,0,0,0,1,1,1,0,0,0);  // ????????? ?????????(DL=1 - ????? 8 ???, N=1 - 2 ??????, F=0 - 5x8)
	HAL_Delay(2);		
	WriteBits8(0,0,0,0,0,0,1,0,0,0);  // ????????? ??????? 
	HAL_Delay(2);
	WriteBits8(0,0,0,0,0,0,0,0,0,1);  // ??????? ???????
	HAL_Delay(2);
	WriteBits8(0,0,0,0,0,0,0,1,1,0);  // I/D=1 - ????? DDRAM ?????????????, S=0 - ????? ??????? ??????? ??????? ?? DDRAM ????????
	HAL_Delay(2);	
	
	WriteBits8(0,0,0,0,0,0,1,1,1,1);  // ???????? ??????? ? ???????
  HAL_Delay(2);	
}	

void LCD_CharCmd(char cSym)
{
	uint8_t bit0=cSym & (1<<0);
	uint8_t bit1=cSym & (1<<1);
	bit1 = bit1 >> 1;
	uint8_t bit2=cSym & (1<<2);
	bit2 = bit2 >> 2;
	uint8_t bit3=cSym & (1<<3);
	bit3 = bit3 >> 3;
	uint8_t bit4=cSym & (1<<4);
	bit4 = bit4 >> 4;
	uint8_t bit5=cSym & (1<<5);
	bit5 = bit5 >> 5;
	uint8_t bit6=cSym & (1<<6);
	bit6 = bit6 >> 6;
	uint8_t bit7=cSym & (1<<7);
	bit7 = bit7 >> 7;
	
	WriteBits8(1,0,bit7,bit6,bit5,bit4,bit3,bit2,bit1,bit0);
}

void LCD_String(char* st)
{
	while(*st != 0)
	{
		LCD_CharCmd(*st);
		st++;
	  HAL_Delay(1);
	}
}

void LCD_SelectedString(char* st,uint8_t c)
{
	switch(c)
	{
		case 1:
		WriteBits8(0,0,1,0,0,0,0,0,0,0); 
		LCD_String(st);
		HAL_Delay(1);
		break;
		
		case 2:
		WriteBits8(0,0,1,1,0,0,0,0,0,0); 
		LCD_String(st);
		HAL_Delay(1);
		break;
		
		default:
		WriteBits8(0,0,1,0,0,0,0,0,0,0);
		HAL_Delay(1);
	  LCD_String("ERROR,TRY AGAIN!");
		HAL_Delay(1);
	}
}
