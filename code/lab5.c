#include <stdio.h>
#include <stdlib.h>
#include <EFM8LB1.h>
#include <lab.h>

#define True 1
#define False 1
#define High 1
#define Low  0

#define voltage_compensate 0.032
#define sqrt2 1.41421356237
void main (void)
{
	float CH1RMS,CH1Zero,CH2RMS,CH2Zero,frequency;
	char buffer[16];
        waitms(500); // Give PuTTy a chance to start before sending
	printf("\x1b[2J"); // Clear screen using ANSI escape sequence.

	InitPinADC(2, 4); // Configure P2.4 as analog input
	InitPinADC(2, 5); // Configure P2.5 as analog input
	
        InitADC();
	LCD_4BIT();
	
	while(True)
	{	 
		CH1RMS = (Volts_at_Pin(QFP32_MUX_P2_5)+voltage_compensate)/sqrt2;
		CH2RMS = (Volts_at_Pin(QFP32_MUX_P2_4)+voltage_compensate)/sqrt2;
		
		CH1Zero = Volts_at_Pin(QFP32_MUX_P2_2);
		CH2Zero = Volts_at_Pin(QFP32_MUX_P2_3);
		
		sprintf (buffer,"CH1 Peak= %.2f V",Volts_at_Pin(QFP32_MUX_P2_5)+voltage_compensate );
		LCDprint(buffer,1,1);
		sprintf (buffer,"CH2 Peak= %.2f V",Volts_at_Pin(QFP32_MUX_P2_4)+voltage_compensate );
		LCDprint(buffer,2,1);
		waitms(1000);
		
		sprintf (buffer,"CH1 RMS= %.2f V",CH1RMS );
		LCDprint(buffer,1,1);
		sprintf (buffer,"CH2 RMS= %.2f V",CH2RMS );
		LCDprint(buffer,2,1);
		
		waitms(500);

		
		frequency = Ch1_Frequency();
		sprintf (buffer,"f1:%.1f HZ",frequency );
		LCDprint(buffer,1,1);
		
		frequency=Ch2_Frequency();
		sprintf (buffer,"f2:%.1f HZ",frequency );
		LCDprint(buffer,2,1);
		
		waitms(1500);
	}
	

}	

