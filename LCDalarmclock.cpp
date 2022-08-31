/*
 * table2.cpp
 *
 * Created: 12-08-2014 15:43:18
 *  Author: Urvashi
 */ 

# define F_CPU 1000000
#include <avr/io.h>
# include <util/delay.h>
void lcd_init();
void disp_cmd(unsigned int cmd);
void disp_data(int cmd);
void disp_num(unsigned int num);
void disp_string(  char *str);
void special_charringbell1();//2
void special_charringbell2();//3
void special_charringbell3();//4
int main(void)
{
	int h1,h0,s1,s0,m1,m0;
	float k;
	DDRB = 0XFF;

	lcd_init();
	special_charringbell1();//2
	special_charringbell2();//3
	 special_charringbell3();//4
    while(1)
	{
		start:
   for(h1=0;h1<=2;h1++)

   {
	   for(h0=0;h0<=9;h0++)
	   {
		   if(h1==2 && h0==4)
		   {
			   goto start;
		   }
		   for(m1=0;m1<=5;m1++)
		   {
			   for(m0=0;m0<=9;m0++)
			   {
				   
				   
				   
				   for(s1=0;s1<=5;s1++)
				   {
					   for(s0=0;s0<=9;s0++)
					   {
						   
						    
						   for (k=0;k<=9;k++)
						   {
							  
							  disp_cmd(0X80);
							  disp_string ( "ALARM CLOCK");
							  if (  s1==0 && s0==0)
							  {

								  disp_cmd(0X8F);
								  
								 disp_data(2);
								 
								 
								 
								 //disp_cmd(0X01);
								 _delay_ms(2);
								 disp_cmd(0X8F);
								 disp_data(3);
								 _delay_ms(2);
								 //disp_cmd(0X01);
								 _delay_ms(2);
								 disp_cmd(0X8F);
								 disp_data(4);
								 _delay_ms(2);
								 disp_cmd(0X8F);
								 disp_data(' ');
								  
							  }
							   disp_cmd(0XC2);
							   disp_num(h1);
							   _delay_ms(5);
							  disp_cmd(0XC3);
							   disp_num(h0);
							   _delay_ms(5);
							  disp_cmd(0XC5);
							   disp_num(m1);
							   _delay_ms(5);
							 disp_cmd(0XC6);
							   disp_num(m0);
							   _delay_ms(5);
							disp_cmd(0XC8);
							  disp_num(s1);
							   _delay_ms(5);
							   disp_cmd(0XC9);
							   disp_num(s0);
							   
							
							    _delay_ms(2);
							  //  disp_cmd(0X01);
							   // _delay_ms(3);
							   
						   }
					   }
				   }
			   }
		   }
	   }
	     
		}
	}		
				return 0;
	}		
		

void special_charringbell1()//2
{
	
	
	disp_cmd(0X50);
	disp_data(0X04);
	disp_data(0X0E);
	disp_data(0X11);
	
	disp_data(0X11);
	disp_data(0X11);
	disp_data(0X1F);
	disp_data(0X08);
	
	
	
	
}
void special_charringbell2()//3
{
	disp_cmd(0X58);
	disp_data(0X04);
	disp_data(0X0E);
	disp_data(0X11);
	
	disp_data(0X11);
	disp_data(0X11);
	disp_data(0X1F);
	disp_data(0X04);
}
void special_charringbell3()//4
{
	disp_cmd(0X60);
	disp_data(0X04);
	disp_data(0X0E);
	disp_data(0X11);
	
	disp_data(0X11);
	disp_data(0X11);
	disp_data(0X1F);
	disp_data(0X02);
}
void lcd_init()
{
	disp_cmd(0X02);
	disp_cmd(0X28);
	disp_cmd(0X0C);
	disp_cmd(0X06);
}

void disp_cmd(unsigned int cmd)
{
	PORTB=((cmd & 0XF0)+0X04);
	_delay_ms(1);
	PORTB=PORTB - 0X04;
	PORTB=(((cmd<<4)& 0XF0)+0X04);
	_delay_ms(1);
	PORTB=PORTB-0X04;
	
}
void disp_data( int cmd)
{
	PORTB=((cmd  & 0XF0)+0X05);
	_delay_ms(1);
	PORTB=PORTB - 0X04;
	PORTB=(((cmd <<4)& 0XF0)+0X05);
	_delay_ms(1);
	PORTB=PORTB-0X04;
	
}

void disp_string( char *str)
{
	int i=0;
	while (str[i]!='\0')
	{
		disp_data (str[i]);
		i++;
		
	}
}

void disp_num(unsigned int num)
{
	int a=0;
	if (num==0)
	{
		disp_data(48);
	}
	disp_cmd (0X04);
	while (num!=0)
	{
		a=num % 10;
		disp_data(a+48);
		num=num/10;
	}
}

	