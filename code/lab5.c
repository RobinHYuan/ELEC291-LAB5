#include <stdio.h>
#include <stdlib.h>
#include <EFM8LB1.h>
#include <lab.h>
#define sqrt2 1.41421356237
#define True 1
#define voltage_compensate 0.033
void main (void)
{
	float CH1RMS,CH1Zero,CH2RMS,CH2Zero;
	char buffer [16];
	 
    	waitms(500); // Give PuTTy a chance to start before sending
	printf("\x1b[2J"); // Clear screen using ANSI escape sequence.
	
	
	InitPinADC(2, 2); // Configure P2.2 as analog input
	InitPinADC(2, 3); // Configure P2.3 as analog input
	InitPinADC(2, 4); // Configure P2.4 as analog input
	InitPinADC(2, 5); // Configure P2.5 as analog input
	
   	InitADC();
	LCD_4BIT();
	
	while(True)
	{	 
	 	CH1RMS = Volts_at_Pin(QFP32_MUX_P2_5)/sqrt2+voltage_compensate;
		CH1Zero = Volts_at_Pin(QFP32_MUX_P2_2);
		CH2RMS = Volts_at_Pin(QFP32_MUX_P2_4)/sqrt2+voltage_compensate;
		CH2Zero = Volts_at_Pin(QFP32_MUX_P2_3);
		
		sprintf (buffer,"CH1 RMS= %.2f V",CH1RMS );
		LCDprint(buffer,1,1);
		sprintf (buffer,"CH2 RMS= %.2f V",CH2RMS );
		LCDprint(buffer,2,1);
		waitms(500);
	}
	

}	

