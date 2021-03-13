#include <stdio.h>
#include <stdlib.h>
#include <EFM8LB1.h>
#include <lab.h>

#define True 1
#define False 1
#define High 1
#define Low  0

#define voltage_compensate 0.045
#define sqrt2 1.41421356237
void main ()
{
	float CH1RMS,CH1Zero,CH2RMS,CH2Zero,frequency_1,frequency_2,phase;
	char buffer_1[16],buffer_2[16],buffer[16];
	int state=0;
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

		do
		{	state=0;
			frequency_1 = Ch1_Frequency();
			sprintf (buffer_1,"f1:%.1f HZ,L",frequency_1 );		
			frequency_2=Ch2_Frequency();
			sprintf (buffer_2,"f2:%.1f HZ,L",frequency_2 );
		}
		while( (frequency_1>500 ||frequency_1/frequency_2>1.2 || frequency_1/frequency_2<0.8 )&& P3_0==1);
		
		

		if( P3_0==0)
		{	do
			{
				frequency_1 = Ch1_Frequency();	
				frequency_2 = Ch2_Frequency();
			}
			while( frequency_1/frequency_2>1.2|| frequency_1/frequency_2<0.8 );
			
		}	
		
		sprintf (buffer_2,"f:%.1f HZ,H",frequency_2 );
		
		phase=phase_Det(frequency_1);
		sprintf(buffer,"Phase: %.1f\xdf", phase);
		LCDprint(buffer,1,1);
		LCDprint(buffer_2,2,1);	
		waitms(1500);
	}
	

}	