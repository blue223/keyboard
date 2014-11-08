#include "reg52.h"
#define IO P1
#define time 500
unsigned char key_number = 0;
void key_board();
void main()
{
	while(1){
	key_board();

	}
}
void delay(unsigned int t)
{
	while(t--);
}
void key_board()
{
	unsigned char list,row,number;
	IO = 0xf0;	
	if(IO != 0xf0)
	{
		delay(time);
		if(IO != 0xf0)
		{
			row = IO;
			row = row >> 4;
			IO = 0X0F;
			list = IO;
			for(number = 0;(list&0x01) == 1;number ++)
				list = list >> 1;
			key_number = number;
			for(number = 0;(row&0x01) == 1;number ++)
				row = row >> 1;
			key_number = key_number + (number*4);
		}
	}
}