EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Battery BT?
U 1 1 620D9784
P 7850 1550
F 0 "BT?" H 7958 1596 50  0000 L CNN
F 1 "Battery" H 7958 1505 50  0000 L CNN
F 2 "" V 7850 1610 50  0001 C CNN
F 3 "~" V 7850 1610 50  0001 C CNN
	1    7850 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT?
U 1 1 620DA1E1
P 7350 1550
F 0 "BT?" H 7458 1596 50  0000 L CNN
F 1 "Battery" H 7458 1505 50  0000 L CNN
F 2 "" V 7350 1610 50  0001 C CNN
F 3 "~" V 7350 1610 50  0001 C CNN
	1    7350 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 1350 7850 1350
Wire Wire Line
	7350 1750 7850 1750
Wire Wire Line
	7350 1350 7100 1350
Connection ~ 7350 1350
$Comp
L Regulator_Switching:LM2596S-5 U?
U 1 1 620DCD3F
P 7000 2600
F 0 "U?" H 7000 2875 50  0000 C CNN
F 1 "LM2596" H 7000 2966 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-263-5_TabPin3" H 7050 2350 50  0001 L CIN
F 3 "http://www.ti.com/lit/ds/symlink/lm2596.pdf" H 7000 2600 50  0001 C CNN
	1    7000 2600
	-1   0    0    1   
$EndComp
Text Notes 6650 2200 0    50   ~ 0
Note: \nMax output 3A, \nV_out < V_in - 1.5V
NoConn ~ 6500 2700
NoConn ~ 7500 2500
$Comp
L Analog_Switch:DG9422DV SW?
U 1 1 620E24D9
P 6800 1350
F 0 "SW?" H 6800 1617 50  0000 C CNN
F 1 "Flip Switch" H 6800 1526 50  0000 C CNN
F 2 "Package_SO:TSOP-6_1.65x3.05mm_P0.95mm" H 6800 1250 50  0001 C CNN
F 3 "https://www.vishay.com/docs/70679/dg9421.pdf" H 6800 1350 50  0001 C CNN
	1    6800 1350
	1    0    0    -1  
$EndComp
NoConn ~ 6800 1550
Text Notes 6300 1000 0    50   ~ 10
Cuts Power to Full System
Wire Wire Line
	7350 1750 6500 1750
Connection ~ 7350 1750
$Comp
L power:GND #PWR?
U 1 1 620E5338
P 6500 1750
F 0 "#PWR?" H 6500 1500 50  0001 C CNN
F 1 "GND" V 6505 1622 50  0000 R CNN
F 2 "" H 6500 1750 50  0001 C CNN
F 3 "" H 6500 1750 50  0001 C CNN
	1    6500 1750
	0    1    1    0   
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 620E5E3A
P 6500 1350
F 0 "#FLG?" H 6500 1425 50  0001 C CNN
F 1 "PWR_FLAG" H 6500 1523 50  0000 C CNN
F 2 "" H 6500 1350 50  0001 C CNN
F 3 "~" H 6500 1350 50  0001 C CNN
	1    6500 1350
	-1   0    0    1   
$EndComp
Text GLabel 6450 1350 0    50   Output ~ 0
+7.2V
Wire Wire Line
	6500 1350 6450 1350
Connection ~ 6500 1350
Text GLabel 7500 2700 2    50   Input ~ 0
+7.2V
$Comp
L power:GND #PWR?
U 1 1 620E6DFB
P 7000 2300
F 0 "#PWR?" H 7000 2050 50  0001 C CNN
F 1 "GND" V 7005 2172 50  0000 R CNN
F 2 "" H 7000 2300 50  0001 C CNN
F 3 "" H 7000 2300 50  0001 C CNN
	1    7000 2300
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 620E772D
P 6500 2500
F 0 "#PWR?" H 6500 2350 50  0001 C CNN
F 1 "+5V" V 6515 2628 50  0000 L CNN
F 2 "" H 6500 2500 50  0001 C CNN
F 3 "" H 6500 2500 50  0001 C CNN
	1    6500 2500
	0    -1   -1   0   
$EndComp
$Comp
L teensy:Teensy-LC U?
U 1 1 620EEB35
P 7200 4900
F 0 "U?" H 7225 6137 60  0000 C CNN
F 1 "Teensy-LC" H 7225 6031 60  0000 C CNN
F 2 "" H 7200 4350 60  0000 C CNN
F 3 "" H 7200 4350 60  0000 C CNN
	1    7200 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 620F675E
P 8400 4750
F 0 "#PWR?" H 8400 4500 50  0001 C CNN
F 1 "GND" V 8405 4622 50  0000 R CNN
F 2 "" H 8400 4750 50  0001 C CNN
F 3 "" H 8400 4750 50  0001 C CNN
	1    8400 4750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 620F6F15
P 6050 3950
F 0 "#PWR?" H 6050 3700 50  0001 C CNN
F 1 "GND" V 6055 3822 50  0000 R CNN
F 2 "" H 6050 3950 50  0001 C CNN
F 3 "" H 6050 3950 50  0001 C CNN
	1    6050 3950
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 620F79FA
P 6050 5550
F 0 "#PWR?" H 6050 5300 50  0001 C CNN
F 1 "GND" V 6055 5422 50  0000 R CNN
F 2 "" H 6050 5550 50  0001 C CNN
F 3 "" H 6050 5550 50  0001 C CNN
	1    6050 5550
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 620F7FD5
P 8400 4650
F 0 "#PWR?" H 8400 4500 50  0001 C CNN
F 1 "+5V" V 8415 4778 50  0000 L CNN
F 2 "" H 8400 4650 50  0001 C CNN
F 3 "" H 8400 4650 50  0001 C CNN
	1    8400 4650
	0    1    1    0   
$EndComp
Text Notes 6050 3600 0    50   ~ 0
Note: \nPower should only be given to the teensy via USB OR the 5V input! \nTo only supply via power the batteries, you should cut the 5V trace\non the back of the teensy!
NoConn ~ 4550 1200
NoConn ~ 4650 1200
$Comp
L power:GND #PWR?
U 1 1 62101601
P 4350 1200
F 0 "#PWR?" H 4350 950 50  0001 C CNN
F 1 "GND" H 4355 1027 50  0000 C CNN
F 2 "" H 4350 1200 50  0001 C CNN
F 3 "" H 4350 1200 50  0001 C CNN
	1    4350 1200
	-1   0    0    1   
$EndComp
$Comp
L Motor:Motor_DC_ALT M?
U 1 1 621031E2
P 3200 2300
F 0 "M?" H 3347 2296 50  0000 L CNN
F 1 "Motor_DC_ALT" H 3347 2205 50  0000 L CNN
F 2 "" H 3200 2210 50  0001 C CNN
F 3 "~" H 3200 2210 50  0001 C CNN
	1    3200 2300
	-1   0    0    1   
$EndComp
$Comp
L Motor:Motor_DC_ALT M?
U 1 1 62104FA7
P 3200 1600
F 0 "M?" H 3347 1596 50  0000 L CNN
F 1 "Motor_DC_ALT" H 3347 1505 50  0000 L CNN
F 2 "" H 3200 1510 50  0001 C CNN
F 3 "~" H 3200 1510 50  0001 C CNN
	1    3200 1600
	-1   0    0    1   
$EndComp
Wire Wire Line
	3750 1800 3200 1800
Wire Wire Line
	3750 1300 3200 1300
Wire Wire Line
	3750 2000 3200 2000
Wire Wire Line
	3750 2100 3750 2500
Wire Wire Line
	3750 2500 3200 2500
Text GLabel 6050 4350 0    50   Output ~ 0
PWM_IN1_MAIN
Text GLabel 6050 4450 0    50   Output ~ 0
PWM_IN2_MAIN
Text GLabel 6050 4950 0    50   Output ~ 0
PWM_IN3_MAIN
Text GLabel 6050 5050 0    50   Output ~ 0
PWM_IN4_MAIN
Text GLabel 4950 2400 2    50   Output ~ 0
PWM_IN1_MAIN
Text GLabel 4950 2300 2    50   Output ~ 0
PWM_IN2_MAIN
Text GLabel 4950 2000 2    50   Output ~ 0
PWM_IN3_MAIN
Text GLabel 4950 1900 2    50   Output ~ 0
PWM_IN4_MAIN
$Comp
L power:+3.3V #PWR?
U 1 1 6210C60C
P 4950 1800
F 0 "#PWR?" H 4950 1650 50  0001 C CNN
F 1 "+3.3V" V 4965 1928 50  0000 L CNN
F 2 "" H 4950 1800 50  0001 C CNN
F 3 "" H 4950 1800 50  0001 C CNN
	1    4950 1800
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 6210C876
P 4950 2200
F 0 "#PWR?" H 4950 2050 50  0001 C CNN
F 1 "+3.3V" V 4965 2328 50  0000 L CNN
F 2 "" H 4950 2200 50  0001 C CNN
F 3 "" H 4950 2200 50  0001 C CNN
	1    4950 2200
	0    1    1    0   
$EndComp
Text GLabel 6050 4650 0    50   Output ~ 0
PWM_Servo
$Comp
L Sensor_Proximity:QRE1113 U?
U 1 1 621167FF
P 4100 4250
F 0 "U?" H 4100 4567 50  0000 C CNN
F 1 "QRB1134" H 4100 4476 50  0000 C CNN
F 2 "OptoDevice:OnSemi_CASE100AQ" H 4100 4050 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/QRE1113-D.PDF" H 4100 4350 50  0001 C CNN
	1    4100 4250
	1    0    0    -1  
$EndComp
Text Notes 2950 3500 0    50   ~ 0
800mA max pull
Text GLabel 3400 3300 2    50   Output ~ 0
PWM_Servo
$Comp
L power:+5V #PWR?
U 1 1 6211025C
P 3400 3200
F 0 "#PWR?" H 3400 3050 50  0001 C CNN
F 1 "+5V" V 3415 3328 50  0000 L CNN
F 2 "" H 3400 3200 50  0001 C CNN
F 3 "" H 3400 3200 50  0001 C CNN
	1    3400 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 1700 3750 1300
$Comp
L Motor:Motor_Servo M?
U 1 1 6210D322
P 3100 3200
F 0 "M?" H 3094 2893 50  0000 C CNN
F 1 "HS-322HD Servo" H 3094 2984 50  0000 C CNN
F 2 "" H 3100 3010 50  0001 C CNN
F 3 "http://forums.parallax.com/uploads/attachments/46831/74481.png" H 3100 3010 50  0001 C CNN
	1    3100 3200
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62110B3E
P 3400 3100
F 0 "#PWR?" H 3400 2850 50  0001 C CNN
F 1 "GND" V 3405 2972 50  0000 R CNN
F 2 "" H 3400 3100 50  0001 C CNN
F 3 "" H 3400 3100 50  0001 C CNN
	1    3400 3100
	0    -1   -1   0   
$EndComp
Text GLabel 4250 2600 3    50   Input ~ 0
+7.2V
$Comp
L power:+5V #PWR?
U 1 1 62102190
P 4350 2600
F 0 "#PWR?" H 4350 2450 50  0001 C CNN
F 1 "+5V" H 4300 2750 50  0000 C CNN
F 2 "" H 4350 2600 50  0001 C CNN
F 3 "" H 4350 2600 50  0001 C CNN
	1    4350 2600
	-1   0    0    1   
$EndComp
$Comp
L Driver_Motor:L298HN U?
U 1 1 620FFDDA
P 4350 1900
F 0 "U?" H 4700 1100 50  0000 C CNN
F 1 "L298N" H 4700 1200 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-15_P2.54x2.54mm_StaggerOdd_Lead4.58mm_Vertical" H 4400 1250 50  0001 L CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000240.pdf" H 4500 2150 50  0001 C CNN
	1    4350 1900
	-1   0    0    1   
$EndComp
$Comp
L teensy:HC-SR04 U?
U 1 1 6213504C
P 1850 2500
F 0 "U?" H 1850 2575 50  0000 C CNN
F 1 "HC-SR04" H 1850 2484 50  0000 C CNN
F 2 "" H 1850 2500 50  0001 C CNN
F 3 "" H 1850 2500 50  0001 C CNN
	1    1850 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 621367E4
P 2200 2650
F 0 "#PWR?" H 2200 2400 50  0001 C CNN
F 1 "GND" V 2205 2522 50  0000 R CNN
F 2 "" H 2200 2650 50  0001 C CNN
F 3 "" H 2200 2650 50  0001 C CNN
	1    2200 2650
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 62136C19
P 2200 2800
F 0 "#PWR?" H 2200 2650 50  0001 C CNN
F 1 "+5V" V 2215 2928 50  0000 L CNN
F 2 "" H 2200 2800 50  0001 C CNN
F 3 "" H 2200 2800 50  0001 C CNN
	1    2200 2800
	0    1    1    0   
$EndComp
Text GLabel 6050 4250 0    50   Output ~ 0
UltraSonic_Echo
Text GLabel 6050 4150 0    50   Output ~ 0
UltraSonic_Trig
Text GLabel 1500 2650 0    50   Output ~ 0
UltraSonic_Trig
Text GLabel 1500 2800 0    50   Output ~ 0
UltraSonic_Echo
Text Notes 1400 3050 0    50   ~ 0
Ultrasonic Sonar Sensor\n~15mA
$Comp
L pspice:OPAMP U?
U 1 1 6213B6CD
P 1950 5450
F 0 "U?" H 2000 5300 50  0000 L CNN
F 1 "LM324" H 1950 5200 50  0000 L CNN
F 2 "" H 1950 5450 50  0001 C CNN
F 3 "~" H 1950 5450 50  0001 C CNN
	1    1950 5450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6214E91B
P 1850 5750
F 0 "#PWR?" H 1850 5500 50  0001 C CNN
F 1 "GND" H 1855 5577 50  0000 C CNN
F 2 "" H 1850 5750 50  0001 C CNN
F 3 "" H 1850 5750 50  0001 C CNN
	1    1850 5750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 6214EFD8
P 1850 5150
F 0 "#PWR?" H 1850 5000 50  0001 C CNN
F 1 "+5V" H 1865 5323 50  0000 C CNN
F 2 "" H 1850 5150 50  0001 C CNN
F 3 "" H 1850 5150 50  0001 C CNN
	1    1850 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 6214FCFF
P 2150 5150
F 0 "C?" V 1921 5150 50  0000 C CNN
F 1 "0.1uF" V 2012 5150 50  0000 C CNN
F 2 "" H 2150 5150 50  0001 C CNN
F 3 "~" H 2150 5150 50  0001 C CNN
	1    2150 5150
	0    1    1    0   
$EndComp
Wire Wire Line
	1850 5150 2050 5150
Connection ~ 1850 5150
$Comp
L power:GND #PWR?
U 1 1 621513AD
P 2250 5150
F 0 "#PWR?" H 2250 4900 50  0001 C CNN
F 1 "GND" V 2255 5022 50  0000 R CNN
F 2 "" H 2250 5150 50  0001 C CNN
F 3 "" H 2250 5150 50  0001 C CNN
	1    2250 5150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 4350 4500 4350
Wire Wire Line
	1200 5550 1650 5550
$Comp
L Device:R_Small 33k
U 1 1 6215949B
P 1850 6300
F 0 "33k" V 2046 6300 50  0000 C CNN
F 1 "R_f" V 1955 6300 50  0000 C CNN
F 2 "" H 1850 6300 50  0001 C CNN
F 3 "~" H 1850 6300 50  0001 C CNN
	1    1850 6300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1650 5550 1650 6300
Wire Wire Line
	1650 6300 1750 6300
Connection ~ 1650 5550
Wire Wire Line
	1950 6300 2250 6300
Wire Wire Line
	2250 6300 2250 5450
$Comp
L power:+5V #PWR?
U 1 1 6215A70B
P 4600 3700
F 0 "#PWR?" H 4600 3550 50  0001 C CNN
F 1 "+5V" H 4615 3873 50  0000 C CNN
F 2 "" H 4600 3700 50  0001 C CNN
F 3 "" H 4600 3700 50  0001 C CNN
	1    4600 3700
	1    0    0    -1  
$EndComp
Text GLabel 8400 5750 2    50   Output ~ 0
LineSensor_1
Text GLabel 4650 4150 2    50   Output ~ 0
LineSensor_1
$Comp
L power:+5V #PWR?
U 1 1 6215F953
P 3600 4150
F 0 "#PWR?" H 3600 4000 50  0001 C CNN
F 1 "+5V" H 3615 4323 50  0000 C CNN
F 2 "" H 3600 4150 50  0001 C CNN
F 3 "" H 3600 4150 50  0001 C CNN
	1    3600 4150
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 621601A5
P 3700 4150
F 0 "R?" H 3500 4200 50  0000 L CNN
F 1 "100" H 3500 4100 50  0000 L CNN
F 2 "" H 3700 4150 50  0001 C CNN
F 3 "~" H 3700 4150 50  0001 C CNN
	1    3700 4150
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 62160D09
P 3800 4350
F 0 "#PWR?" H 3800 4100 50  0001 C CNN
F 1 "GND" H 3805 4177 50  0000 C CNN
F 2 "" H 3800 4350 50  0001 C CNN
F 3 "" H 3800 4350 50  0001 C CNN
	1    3800 4350
	0    1    1    0   
$EndComp
Text Notes 3850 3800 0    50   ~ 0
Line Sensor 1
Text Notes 650  850  0    118  ~ 24
MINIMUM VIABLE PRODUCT SCHEMATIC
Text Notes 1800 4500 0    50   ~ 0
Beacon
$Comp
L power:GND #PWR?
U 1 1 62163155
P 4500 4350
F 0 "#PWR?" H 4500 4100 50  0001 C CNN
F 1 "GND" H 4505 4177 50  0000 C CNN
F 2 "" H 4500 4350 50  0001 C CNN
F 3 "" H 4500 4350 50  0001 C CNN
	1    4500 4350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 62165126
P 4600 3800
F 0 "R?" H 4400 3850 50  0000 L CNN
F 1 "50k" H 4400 3750 50  0000 L CNN
F 2 "" H 4600 3800 50  0001 C CNN
F 3 "~" H 4600 3800 50  0001 C CNN
	1    4600 3800
	-1   0    0    1   
$EndComp
Wire Wire Line
	4650 4150 4600 4150
Wire Wire Line
	4600 3900 4600 4150
Connection ~ 4600 4150
Wire Wire Line
	4600 4150 4400 4150
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 6217583A
P 3900 7150
F 0 "Q?" V 3585 7150 50  0000 C CNN
F 1 "LTR-3208E" V 3676 7150 50  0000 C CNN
F 2 "" H 4100 7250 50  0001 C CNN
F 3 "~" H 3900 7150 50  0001 C CNN
	1    3900 7150
	1    0    0    -1  
$EndComp
Text Notes 6900 7650 2    50   ~ 0
Red Becon Sensing\n(3333 Hz)
Text Notes 4350 7800 0    50   ~ 0
Red Becon Sensing\n(909 Hz)
$Comp
L power:+5V #PWR?
U 1 1 6217C329
P 4000 6600
F 0 "#PWR?" H 4000 6450 50  0001 C CNN
F 1 "+5V" H 4015 6773 50  0000 C CNN
F 2 "" H 4000 6600 50  0001 C CNN
F 3 "" H 4000 6600 50  0001 C CNN
	1    4000 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6217C32F
P 4000 6700
F 0 "R?" H 3800 6750 50  0000 L CNN
F 1 "50k" H 3800 6650 50  0000 L CNN
F 2 "" H 4000 6700 50  0001 C CNN
F 3 "~" H 4000 6700 50  0001 C CNN
	1    4000 6700
	-1   0    0    1   
$EndComp
Wire Wire Line
	4000 6800 4000 6900
Wire Wire Line
	4000 6900 4300 6900
Connection ~ 4000 6900
Wire Wire Line
	4000 6900 4000 6950
$Comp
L power:GND #PWR?
U 1 1 6217ECD1
P 4000 7350
F 0 "#PWR?" H 4000 7100 50  0001 C CNN
F 1 "GND" H 4005 7177 50  0000 C CNN
F 2 "" H 4000 7350 50  0001 C CNN
F 3 "" H 4000 7350 50  0001 C CNN
	1    4000 7350
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 62180F55
P 6300 7000
F 0 "Q?" V 5985 7000 50  0000 C CNN
F 1 "LTR-3208E" V 6076 7000 50  0000 C CNN
F 2 "" H 6500 7100 50  0001 C CNN
F 3 "~" H 6300 7000 50  0001 C CNN
	1    6300 7000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 62180F5B
P 6400 6450
F 0 "#PWR?" H 6400 6300 50  0001 C CNN
F 1 "+5V" H 6415 6623 50  0000 C CNN
F 2 "" H 6400 6450 50  0001 C CNN
F 3 "" H 6400 6450 50  0001 C CNN
	1    6400 6450
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 62180F61
P 6400 6550
F 0 "R?" H 6200 6600 50  0000 L CNN
F 1 "50k" H 6200 6500 50  0000 L CNN
F 2 "" H 6400 6550 50  0001 C CNN
F 3 "~" H 6400 6550 50  0001 C CNN
	1    6400 6550
	-1   0    0    1   
$EndComp
Wire Wire Line
	6400 6650 6400 6750
Wire Wire Line
	6400 6750 6700 6750
Connection ~ 6400 6750
Wire Wire Line
	6400 6750 6400 6800
$Comp
L power:GND #PWR?
U 1 1 62180F6B
P 6400 7200
F 0 "#PWR?" H 6400 6950 50  0001 C CNN
F 1 "GND" H 6405 7027 50  0000 C CNN
F 2 "" H 6400 7200 50  0001 C CNN
F 3 "" H 6400 7200 50  0001 C CNN
	1    6400 7200
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 62187F90
P 4400 6900
F 0 "C?" V 4171 6900 50  0000 C CNN
F 1 "200pF" V 4262 6900 50  0000 C CNN
F 2 "" H 4400 6900 50  0001 C CNN
F 3 "~" H 4400 6900 50  0001 C CNN
	1    4400 6900
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 62188658
P 4500 7150
F 0 "R?" H 4300 7200 50  0000 L CNN
F 1 "1k" H 4300 7100 50  0000 L CNN
F 2 "" H 4500 7150 50  0001 C CNN
F 3 "~" H 4500 7150 50  0001 C CNN
	1    4500 7150
	-1   0    0    1   
$EndComp
Wire Wire Line
	4500 7050 4500 6900
$Comp
L power:GND #PWR?
U 1 1 621895CE
P 4500 7350
F 0 "#PWR?" H 4500 7100 50  0001 C CNN
F 1 "GND" H 4505 7177 50  0000 C CNN
F 2 "" H 4500 7350 50  0001 C CNN
F 3 "" H 4500 7350 50  0001 C CNN
	1    4500 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 7350 4500 7250
Wire Wire Line
	4500 6900 4800 6900
Connection ~ 4500 6900
$Comp
L Device:R_Small R?
U 1 1 6218E23B
P 2450 5450
F 0 "R?" V 2650 5400 50  0000 L CNN
F 1 "1k" V 2550 5400 50  0000 L CNN
F 2 "" H 2450 5450 50  0001 C CNN
F 3 "~" H 2450 5450 50  0001 C CNN
	1    2450 5450
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 6218E736
P 2550 5700
F 0 "C?" V 2321 5700 50  0000 C CNN
F 1 "147pF" V 2412 5700 50  0000 C CNN
F 2 "" H 2550 5700 50  0001 C CNN
F 3 "~" H 2550 5700 50  0001 C CNN
	1    2550 5700
	-1   0    0    1   
$EndComp
Wire Wire Line
	2550 5450 2550 5600
$Comp
L power:GND #PWR?
U 1 1 62190DE6
P 2550 5900
F 0 "#PWR?" H 2550 5650 50  0001 C CNN
F 1 "GND" H 2555 5727 50  0000 C CNN
F 2 "" H 2550 5900 50  0001 C CNN
F 3 "" H 2550 5900 50  0001 C CNN
	1    2550 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 5800 2550 5900
Wire Wire Line
	5000 6900 5300 6900
$Comp
L Device:Q_Photo_NPN Q?
U 1 1 62199661
P 1000 5650
F 0 "Q?" V 1328 5650 50  0000 C CNN
F 1 "LTR-3208E" V 1237 5650 50  0000 C CNN
F 2 "" H 1200 5750 50  0001 C CNN
F 3 "~" H 1000 5650 50  0001 C CNN
	1    1000 5650
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 6219AAFD
P 800 5550
F 0 "#PWR?" H 800 5400 50  0001 C CNN
F 1 "+5V" H 815 5723 50  0000 C CNN
F 2 "" H 800 5550 50  0001 C CNN
F 3 "" H 800 5550 50  0001 C CNN
	1    800  5550
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6219C5D3
P 1050 4850
F 0 "R?" H 850 4900 50  0000 L CNN
F 1 "10k" H 850 4800 50  0000 L CNN
F 2 "" H 1050 4850 50  0001 C CNN
F 3 "~" H 1050 4850 50  0001 C CNN
	1    1050 4850
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6219D050
P 1250 4850
F 0 "R?" H 1050 4900 50  0000 L CNN
F 1 "10k" H 1050 4800 50  0000 L CNN
F 2 "" H 1250 4850 50  0001 C CNN
F 3 "~" H 1250 4850 50  0001 C CNN
	1    1250 4850
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6219D3F5
P 1600 4850
F 0 "R?" H 1400 4900 50  0000 L CNN
F 1 "10k" H 1400 4800 50  0000 L CNN
F 2 "" H 1600 4850 50  0001 C CNN
F 3 "~" H 1600 4850 50  0001 C CNN
	1    1600 4850
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 6219D726
P 950 4850
F 0 "#PWR?" H 950 4600 50  0001 C CNN
F 1 "GND" V 955 4722 50  0000 R CNN
F 2 "" H 950 4850 50  0001 C CNN
F 3 "" H 950 4850 50  0001 C CNN
	1    950  4850
	0    1    1    0   
$EndComp
Wire Wire Line
	1350 4850 1450 4850
Wire Wire Line
	1450 4850 1450 5350
Wire Wire Line
	1450 5350 1650 5350
Connection ~ 1450 4850
Wire Wire Line
	1450 4850 1500 4850
$Comp
L power:+5V #PWR?
U 1 1 6219FE89
P 1700 4850
F 0 "#PWR?" H 1700 4700 50  0001 C CNN
F 1 "+5V" V 1600 4900 50  0000 C CNN
F 2 "" H 1700 4850 50  0001 C CNN
F 3 "" H 1700 4850 50  0001 C CNN
	1    1700 4850
	0    1    1    0   
$EndComp
$Comp
L pspice:OPAMP U?
U 1 1 621A054C
P 3850 5550
F 0 "U?" H 3900 5400 50  0000 L CNN
F 1 "LM324" H 3850 5300 50  0000 L CNN
F 2 "" H 3850 5550 50  0001 C CNN
F 3 "~" H 3850 5550 50  0001 C CNN
	1    3850 5550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 621A1592
P 3750 5250
F 0 "#PWR?" H 3750 5100 50  0001 C CNN
F 1 "+5V" H 3765 5423 50  0000 C CNN
F 2 "" H 3750 5250 50  0001 C CNN
F 3 "" H 3750 5250 50  0001 C CNN
	1    3750 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 621A1B5F
P 3750 5850
F 0 "#PWR?" H 3750 5600 50  0001 C CNN
F 1 "GND" H 3755 5677 50  0000 C CNN
F 2 "" H 3750 5850 50  0001 C CNN
F 3 "" H 3750 5850 50  0001 C CNN
	1    3750 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 5650 3350 5650
Wire Wire Line
	3350 5650 3350 6200
Wire Wire Line
	3350 6200 4250 6200
Wire Wire Line
	4250 6200 4250 5550
Wire Wire Line
	4250 5550 4150 5550
Wire Wire Line
	4250 5550 4400 5550
Connection ~ 4250 5550
Connection ~ 2250 5450
Wire Wire Line
	2250 5450 2350 5450
Wire Wire Line
	2550 5450 3550 5450
Connection ~ 2550 5450
$EndSCHEMATC
