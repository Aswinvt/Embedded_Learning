#include<avr/io.h>
#include<util/delay.h>
char key();
void cmd(int);
void data(char);
void main()
{
	
	char a;
	DDRD=0XF0;
	DDRC=0XFF;
	DDRB=0XFF;
	cmd(0X38);
	cmd(0X80);
	cmd(0X0E);
	cmd(0X06);
	cmd(0X01);
	while(1)
	{
		a=key();
		data(a);
	}
}

char key()
{
	int e;
	while(1)
	{
		PORTD=0X7F;
		e=PIND&0X0F;
		switch(e)
		{
			case 0X07:
			return('1');
			break;

			case 0X0B:
			return('2');
			break;

			case 0X0D:
			return('3');
			break;

			case 0X0E:
			return('4');
			break;
		}

		PORTD=0XBF;
		e=PIND&0X0F;
		switch(e)
		{
			case 0X07:
			return('5');
			break;

			case 0X0B:
			return('6');
			break;

			case 0X0D:
			return('7');
			break;

			case 0X0E:
			return('8');
			break;
		}

		PORTD=0XDF;
		e=PIND&0X0F;
		switch(e)
		{
			case 0X07:
			return('9');
			break;

			case 0X0B:
			return('*');
			break;

			case 0X0D:
			return('#');
			break;

			case 0X0E:
			return('0');
			break;
		}

		PORTD=0XEF;
		e=PIND&0X0F;
		switch(e)
		{
			case 0X07:
			return('H');
			break;

			case 0X0B:
			return('A');
			break;

			case 0X0D:
			return('R');
			break;

			case 0X0E:
			return('O');
			break;
		}
	}
}
void cmd(int a)
{
	PORTB=a;
	PORTC=0X02;
	_delay_ms(2000);
	PORTC=0X00;
}

void data(char b)
{
	PORTB=b;
	PORTC=0X03;
	_delay_ms(2000);
	PORTC=0X01;
}
