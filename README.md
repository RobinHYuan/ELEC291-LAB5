# ELEC291-LAB5


### Introduction:
In this lab, we will be using the EFM8 board to measure the RMS voltages of any two given AC signals and the phase difference between the reference and test signals in degree.


### Team Member:
Jerry Shao, 84982321 \
Robin Yuan, 88011879


------------

#### Video demonstrations:

https://www.youtube.com/watch?v=Olm7Yfmvy40 (for frequency measurement)

https://www.youtube.com/watch?v=PDNpej76NwM (for voltage amplitude measurement)

https://www.youtube.com/watch?v=M9bew8Vv2B0 (for phase shift measurement)


------------

### Extra Features:

1. Portable design; No USB Connection is Needed
2. High Frequency Measurement Range: 15Hz-60,000Hz
3. High Voltage Measurement Range：200mV-3.2V
4. Adjustble Pull-up Resistors Allow Us to Change the Rise Time of the LM393 Output to Get More Stable Readings
5. Auto-backlighting circuit is used so that users can read the measurements with ease in a dark environment
6. High Slew Rate Op-amp Used, TLE2082 gives us fatser and more accurate signal reponse at high frequencies 
7. Input Voltage Buffer Used to Protect the Signal Generator and the Circuit

------------

### PIN Assignment:

#define LCD_RS P3_3\
#define LCD_RW P3_2\
#define LCD_E  P3_1\
#define LCD_D4 P1_4\
#define LCD_D5 P1_5\
#define LCD_D6 P1_6\
#define LCD_D7 P1_7

#define Channel_1Peak P2_5\
#define Channel_1Zero P2_2\
#define Channel_2Peak P2_4\
#define Channel_2Zero P2_3



------------

### BreadBoard Layout:
#### Note:
1. The bottom two slider switches are used for changing pull-up resistance of the output pins of LM393
2. The Slider swithces on the left is used for selecting frequency range and input-protection
<img src="https://user-images.githubusercontent.com/68177491/111015389-63883480-835d-11eb-9c7d-8d34519ef2f0.jpg" width="595" height="794"/>


------------

#### This lab is sponsored by Matou Sakura

<img src="https://user-images.githubusercontent.com/68177491/110687738-b4e5c780-8195-11eb-9695-f509644cab16.jpg" width="623" height="872"/>
