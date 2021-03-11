#include <stdio.h>
#include <stdlib.h>
#include <EFM8LB1.h>
#include <lab.h>

#define True  1
#define False 0
#define High  1
#define Low   0

#define voltage_compensate 0.023
#define sqrt2 1.41421356237

void main (void)
{
	float CH1RMS,CH1Zero,CH2RMS,CH2Zero,frequency,phase;
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
		
		sprintf (buffer,"CH1 Peak= %.2f V",Volts_at_Pin(QFP32_MUX_P2_5) );
		LCDprint(buffer,1,1);
		sprintf (buffer,"CH2 Peak= %.2f V",Volts_at_Pin(QFP32_MUX_P2_4) );
		LCDprint(buffer,2,1);
		waitms(1000);
		
		sprintf (buffer,"CH1 RMS= %.2f V",CH1RMS );
		LCDprint(buffer,1,1);
		sprintf (buffer,"CH2 RMS= %.2f V",CH2RMS );
		LCDprint(buffer,2,1);

		
		waitms(500);

	
		frequency = 1.014*Ch1_Frequency();
		sprintf (buffer,"f:%.1f HZ",frequency );
		LCDprint(buffer,2,1);
		waitms(1500);

		phase = phase_Det();
		sprintf(buffer, "Phase:%.1f deg", phase);
		LCDprintf(buffer, 2, 1);
		waitms(1500);
	}
	

}	
