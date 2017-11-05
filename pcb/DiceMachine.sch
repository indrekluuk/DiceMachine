EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:DcDcConverter
LIBS:arduino
LIBS:nok5110
LIBS:levelshifter_74hc4050d
LIBS:DiceMachine-cache
EELAYER 25 0
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
L DcDcConverter DCDC1
U 1 1 59ECD6F4
P 3550 1500
F 0 "DCDC1" H 3550 1200 60  0000 C CNN
F 1 "DcDcConverter" H 3550 1800 60  0000 C CNN
F 2 "DcDc5VUp:DcDc5VUp" H 3550 1500 60  0001 C CNN
F 3 "" H 3550 1500 60  0000 C CNN
	1    3550 1500
	1    0    0    -1  
$EndComp
$Comp
L arduino_mini U1
U 1 1 59ECD78B
P 5700 3350
F 0 "U1" H 6200 2400 70  0000 C CNN
F 1 "arduino_mini" H 6450 2300 70  0000 C CNN
F 2 "arduino:arduino_mini" H 5700 3300 60  0000 C CNN
F 3 "" H 5700 3350 60  0000 C CNN
	1    5700 3350
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 59ECD83F
P 2700 1400
F 0 "D1" H 2700 1500 50  0000 C CNN
F 1 "D" H 2700 1300 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_TO-247_Vertical" H 2700 1400 50  0001 C CNN
F 3 "" H 2700 1400 50  0001 C CNN
	1    2700 1400
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x02 J2
U 1 1 59ECD8B8
P 1400 1500
F 0 "J2" H 1400 1600 50  0000 C CNN
F 1 "Conn_01x02" H 1400 1300 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 1400 1500 50  0001 C CNN
F 3 "" H 1400 1500 50  0001 C CNN
	1    1400 1500
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x02 J1
U 1 1 59ECD94F
P 2050 1200
F 0 "J1" H 2050 1300 50  0000 C CNN
F 1 "Conn_01x02" V 2150 1000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 2050 1200 50  0001 C CNN
F 3 "" H 2050 1200 50  0001 C CNN
	1    2050 1200
	0    -1   -1   0   
$EndComp
$Comp
L Conn_01x02 J3
U 1 1 59ECD9CE
P 7900 4800
F 0 "J3" H 7900 4900 50  0000 C CNN
F 1 "Conn_01x02" H 7900 4600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 7900 4800 50  0001 C CNN
F 3 "" H 7900 4800 50  0001 C CNN
	1    7900 4800
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 59ECDCA8
P 7950 1600
F 0 "R1" V 8030 1600 50  0000 C CNN
F 1 "330" V 7950 1600 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 7880 1600 50  0001 C CNN
F 3 "" H 7950 1600 50  0001 C CNN
	1    7950 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	9850 3050 9800 3050
Wire Wire Line
	9800 3050 9800 3500
Wire Wire Line
	9800 3500 10400 3500
$Comp
L GND #PWR7
U 1 1 59ECE495
P 9800 3500
F 0 "#PWR7" H 9800 3250 50  0001 C CNN
F 1 "GND" H 9800 3350 50  0000 C CNN
F 2 "" H 9800 3500 50  0001 C CNN
F 3 "" H 9800 3500 50  0001 C CNN
	1    9800 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 1600 10150 1600
Wire Wire Line
	6400 3200 7000 3200
Wire Wire Line
	7000 3200 7000 1600
Wire Wire Line
	7000 1600 7800 1600
Wire Wire Line
	6400 3300 7100 3300
Wire Wire Line
	7100 3300 7100 2750
Wire Wire Line
	6400 3400 7200 3400
Wire Wire Line
	7200 3400 7200 2900
Wire Wire Line
	6400 3650 7300 3650
Wire Wire Line
	7300 3650 7300 3050
Wire Wire Line
	6400 3750 7400 3750
Wire Wire Line
	7400 3750 7400 3200
Wire Wire Line
	6400 2800 6850 2800
Wire Wire Line
	6850 2800 6850 4800
Wire Wire Line
	6850 4800 7700 4800
Wire Wire Line
	7700 4900 7550 4900
Wire Wire Line
	7550 4900 7550 5150
$Comp
L GND #PWR10
U 1 1 59ECEB05
P 7550 5150
F 0 "#PWR10" H 7550 4900 50  0001 C CNN
F 1 "GND" H 7550 5000 50  0000 C CNN
F 2 "" H 7550 5150 50  0001 C CNN
F 3 "" H 7550 5150 50  0001 C CNN
	1    7550 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 1600 4300 1600
Wire Wire Line
	4300 1600 4300 1750
$Comp
L GND #PWR5
U 1 1 59ECECE3
P 4300 1750
F 0 "#PWR5" H 4300 1500 50  0001 C CNN
F 1 "GND" H 4300 1600 50  0000 C CNN
F 2 "" H 4300 1750 50  0001 C CNN
F 3 "" H 4300 1750 50  0001 C CNN
	1    4300 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 1400 3100 1400
Wire Wire Line
	1600 1400 2050 1400
Wire Wire Line
	2150 1400 2550 1400
Wire Wire Line
	1600 1500 2050 1500
Wire Wire Line
	2050 1500 2050 1600
Wire Wire Line
	2050 1600 3100 1600
$Comp
L GND #PWR9
U 1 1 59ECEF76
P 5700 4900
F 0 "#PWR9" H 5700 4650 50  0001 C CNN
F 1 "GND" H 5700 4750 50  0000 C CNN
F 2 "" H 5700 4900 50  0001 C CNN
F 3 "" H 5700 4900 50  0001 C CNN
	1    5700 4900
	1    0    0    -1  
$EndComp
NoConn ~ 6400 2700
NoConn ~ 6400 2900
NoConn ~ 6400 3000
NoConn ~ 6400 3100
NoConn ~ 6400 3850
NoConn ~ 6400 3950
NoConn ~ 6400 4050
NoConn ~ 6400 4150
NoConn ~ 5000 4550
NoConn ~ 5000 4650
NoConn ~ 5000 2950
NoConn ~ 5000 3150
NoConn ~ 5000 3250
NoConn ~ 5000 3350
NoConn ~ 5000 3450
NoConn ~ 5000 3550
NoConn ~ 5000 3650
NoConn ~ 5000 3750
NoConn ~ 5000 3850
NoConn ~ 5550 2200
$Comp
L nok5110 NOK1
U 1 1 59ECF53D
P 10300 2850
F 0 "NOK1" V 10000 3200 60  0000 C CNN
F 1 "nok5110" V 10550 2600 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 10200 3600 60  0001 C CNN
F 3 "" H 10200 3600 60  0001 C CNN
	1    10300 2850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR1
U 1 1 59ECF8EA
P 5700 1400
F 0 "#PWR1" H 5700 1250 50  0001 C CNN
F 1 "+5V" H 5700 1540 50  0000 C CNN
F 2 "" H 5700 1400 50  0001 C CNN
F 3 "" H 5700 1400 50  0001 C CNN
	1    5700 1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 59ECFAC3
P 2050 1600
F 0 "#PWR3" H 2050 1350 50  0001 C CNN
F 1 "GND" H 2050 1450 50  0000 C CNN
F 2 "" H 2050 1600 50  0001 C CNN
F 3 "" H 2050 1600 50  0001 C CNN
	1    2050 1600
	1    0    0    -1  
$EndComp
$Comp
L LevelShifter_74HC4050D LS1
U 1 1 59FB6E3B
P 8350 3050
F 0 "LS1" H 8550 3600 60  0000 C CNN
F 1 "LevelShifter_74HC4050D" H 9200 2250 60  0000 C CNN
F 2 "Housings_SSOP:SOP-16_4.4x10.4mm_Pitch1.27mm" H 8350 3050 60  0001 C CNN
F 3 "" H 8350 3050 60  0000 C CNN
	1    8350 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 2200 5700 1400
Wire Wire Line
	5700 1400 4000 1400
Wire Wire Line
	5850 2200 5850 1400
Wire Wire Line
	5850 1400 10400 1400
Wire Wire Line
	10400 1400 10400 2200
$Comp
L +3.3V #PWR2
U 1 1 59FB7034
P 10400 1400
F 0 "#PWR2" H 10400 1250 50  0001 C CNN
F 1 "+3.3V" H 10400 1540 50  0000 C CNN
F 2 "" H 10400 1400 50  0001 C CNN
F 3 "" H 10400 1400 50  0001 C CNN
	1    10400 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 1600 10150 2200
$Comp
L GND #PWR8
U 1 1 59FB736B
P 8200 3850
F 0 "#PWR8" H 8200 3600 50  0001 C CNN
F 1 "GND" H 8200 3700 50  0000 C CNN
F 2 "" H 8200 3850 50  0001 C CNN
F 3 "" H 8200 3850 50  0001 C CNN
	1    8200 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 2750 9850 2750
Wire Wire Line
	7100 2750 7750 2750
Wire Wire Line
	7200 2900 7750 2900
Wire Wire Line
	8900 2900 9150 2900
Wire Wire Line
	9150 2900 9150 2850
Wire Wire Line
	9150 2850 9850 2850
Wire Wire Line
	7300 3050 7750 3050
Wire Wire Line
	8900 3050 9300 3050
Wire Wire Line
	9300 3050 9300 2950
Wire Wire Line
	9300 2950 9850 2950
Wire Wire Line
	7400 3200 7750 3200
Wire Wire Line
	8900 3200 9450 3200
Wire Wire Line
	9450 3200 9450 3150
Wire Wire Line
	9450 3150 9850 3150
NoConn ~ 8900 3350
NoConn ~ 8900 3500
NoConn ~ 7750 3350
NoConn ~ 7750 3500
Wire Wire Line
	8350 2400 8350 1400
Connection ~ 8350 1400
$Comp
L C C2
U 1 1 59FB7999
P 9000 2000
F 0 "C2" H 9025 2100 50  0000 L CNN
F 1 "C" H 9025 1900 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 9038 1850 50  0001 C CNN
F 3 "" H 9000 2000 50  0001 C CNN
	1    9000 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 59FB7A2C
P 9000 2150
F 0 "#PWR6" H 9000 1900 50  0001 C CNN
F 1 "GND" H 9000 2000 50  0000 C CNN
F 2 "" H 9000 2150 50  0001 C CNN
F 3 "" H 9000 2150 50  0001 C CNN
	1    9000 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 1850 8350 1850
Connection ~ 8350 1850
$Comp
L C C1
U 1 1 59FB7B51
P 5000 1550
F 0 "C1" H 5025 1650 50  0000 L CNN
F 1 "C" H 5025 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 5038 1400 50  0001 C CNN
F 3 "" H 5000 1550 50  0001 C CNN
	1    5000 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 59FB7BA4
P 5000 1700
F 0 "#PWR4" H 5000 1450 50  0001 C CNN
F 1 "GND" H 5000 1550 50  0000 C CNN
F 2 "" H 5000 1700 50  0001 C CNN
F 3 "" H 5000 1700 50  0001 C CNN
	1    5000 1700
	1    0    0    -1  
$EndComp
$EndSCHEMATC
