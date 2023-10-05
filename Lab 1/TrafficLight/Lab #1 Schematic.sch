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
L Lab-#1-Schematic-rescue:LED-2560 D2
U 1 1 60430FFC
P 7800 1900
F 0 "D2" H 7800 2115 50  0000 C CNN
F 1 "Yellow_LED" H 7800 2024 50  0000 C CNN
F 2 "" H 7800 1900 60  0000 C CNN
F 3 "" H 7800 1900 60  0000 C CNN
	1    7800 1900
	-1   0    0    -1  
$EndComp
$Comp
L Lab-#1-Schematic-rescue:LED-2560 D3
U 1 1 604317EE
P 7050 1800
F 0 "D3" H 7050 2015 50  0000 C CNN
F 1 "Red_LED" H 7050 1924 50  0000 C CNN
F 2 "" H 7050 1800 60  0000 C CNN
F 3 "" H 7050 1800 60  0000 C CNN
	1    7050 1800
	-1   0    0    -1  
$EndComp
$Comp
L Lab-#1-Schematic-rescue:R-2560 R1
U 1 1 604327FE
P 8600 2000
F 0 "R1" V 8393 2000 50  0000 C CNN
F 1 "220" V 8484 2000 50  0000 C CNN
F 2 "" V 8530 2000 30  0000 C CNN
F 3 "" H 8600 2000 30  0000 C CNN
	1    8600 2000
	0    1    1    0   
$EndComp
$Comp
L Lab-#1-Schematic-rescue:R-2560 R3
U 1 1 604331C5
P 8100 1800
F 0 "R3" V 7893 1800 50  0000 C CNN
F 1 "220" V 7984 1800 50  0000 C CNN
F 2 "" V 8030 1800 30  0000 C CNN
F 3 "" H 8100 1800 30  0000 C CNN
	1    8100 1800
	0    1    1    0   
$EndComp
$Comp
L Lab-#1-Schematic-rescue:R-2560 R2
U 1 1 604340B9
P 8400 1900
F 0 "R2" V 8193 1900 50  0000 C CNN
F 1 "220" V 8284 1900 50  0000 C CNN
F 2 "" V 8330 1900 30  0000 C CNN
F 3 "" H 8400 1900 30  0000 C CNN
	1    8400 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 1800 6850 1800
Wire Wire Line
	7250 1800 7950 1800
Wire Wire Line
	7800 1900 8000 1900
$Comp
L Lab-#1-Schematic-rescue:LED-2560 D1
U 1 1 6043070D
P 7400 2000
F 0 "D1" H 7400 2215 50  0000 C CNN
F 1 "Green_LED" H 7400 2124 50  0000 C CNN
F 2 "" H 7400 2000 60  0000 C CNN
F 3 "" H 7400 2000 60  0000 C CNN
	1    7400 2000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7600 2000 8450 2000
Wire Wire Line
	8250 1900 8000 1900
Connection ~ 8000 1900
$Comp
L Lab-#1-Schematic-rescue:Arduino_Mega2560_Shield-arduino XA1
U 1 1 6042C674
P 5250 3850
F 0 "XA1" H 5250 1500 60  0000 C CNN
F 1 "Arduino_Mega2560_Shield" H 5250 1400 60  0000 C CNN
F 2 "" H 5950 6600 60  0001 C CNN
F 3 "https://store.arduino.cc/arduino-mega-2560-rev3" H 5950 6600 60  0001 C CNN
	1    5250 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2000 7200 2000
Wire Wire Line
	6550 1900 7600 1900
$Comp
L Lab-#1-Schematic-rescue:R-2560 R4
U 1 1 6150327D
P 3550 5100
F 0 "R4" V 3343 5100 50  0000 C CNN
F 1 "10k " V 3434 5100 50  0000 C CNN
F 2 "" V 3480 5100 30  0000 C CNN
F 3 "" H 3550 5100 30  0000 C CNN
	1    3550 5100
	0    1    1    0   
$EndComp
$Comp
L Lab-#1-Schematic-rescue:SW_PUSH-2560 SW1
U 1 1 61503D93
P 3150 5400
F 0 "SW1" H 3150 5655 50  0000 C CNN
F 1 "SW_PUSH-2560" H 3150 5564 50  0000 C CNN
F 2 "" H 3150 5400 60  0000 C CNN
F 3 "" H 3150 5400 60  0000 C CNN
	1    3150 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3700 5100 3800 5100
Wire Wire Line
	3400 5100 3300 5100
Wire Wire Line
	3150 5700 3700 5700
$Comp
L Device:Buzzer BZ1
U 1 1 6150D1BF
P 6900 2900
F 0 "BZ1" H 7052 2929 50  0000 L CNN
F 1 "Buzzer" H 7052 2838 50  0000 L CNN
F 2 "" V 6875 3000 50  0001 C CNN
F 3 "~" V 6875 3000 50  0001 C CNN
	1    6900 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2800 6800 2800
Wire Wire Line
	8250 1800 9050 1800
Wire Wire Line
	9050 1800 9050 1900
Wire Wire Line
	9050 1900 8550 1900
Wire Wire Line
	9050 1900 9050 2000
Wire Wire Line
	9050 2000 8750 2000
Connection ~ 9050 1900
Wire Wire Line
	6800 3000 6800 3100
Wire Wire Line
	3800 6350 3800 5100
Connection ~ 3800 5100
Wire Wire Line
	3800 5100 3950 5100
Wire Wire Line
	9050 2000 9050 3100
Wire Wire Line
	9050 3100 6800 3100
Connection ~ 9050 2000
Wire Wire Line
	6650 3100 6650 4050
Wire Wire Line
	7750 3450 7750 2100
Wire Wire Line
	7750 2100 6550 2100
Wire Wire Line
	7750 3950 7600 3950
Wire Wire Line
	7600 3950 7600 2200
Wire Wire Line
	7600 2200 6550 2200
Wire Wire Line
	7750 3650 7400 3650
Wire Wire Line
	7400 3650 7400 2300
Wire Wire Line
	7400 2300 6550 2300
$Comp
L Display_Character:CC56-12SRWA U?
U 1 1 6151B4F2
P 8100 5450
F 0 "U?" H 8100 6117 50  0000 C CNN
F 1 "CC56-12SRWA" H 8100 6026 50  0000 C CNN
F 2 "Display_7Segment:CA56-12SRWA" H 8100 4850 50  0001 C CNN
F 3 "http://www.kingbrightusa.com/images/catalog/SPEC/CC56-12SRWA.pdf" H 7670 5480 50  0001 C CNN
	1    8100 5450
	1    0    0    -1  
$EndComp
$Comp
L Lab-#1-Schematic-rescue:R-2560 R5
U 1 1 6151EB39
P 9950 5650
F 0 "R5" V 9743 5650 50  0000 C CNN
F 1 "220" V 9834 5650 50  0000 C CNN
F 2 "" V 9880 5650 30  0000 C CNN
F 3 "" H 9950 5650 30  0000 C CNN
	1    9950 5650
	0    1    1    0   
$EndComp
$Comp
L Lab-#1-Schematic-rescue:R-2560 R6
U 1 1 6151F703
P 9600 5750
F 0 "R6" V 9393 5750 50  0000 C CNN
F 1 "220" V 9484 5750 50  0000 C CNN
F 2 "" V 9530 5750 30  0000 C CNN
F 3 "" H 9600 5750 30  0000 C CNN
	1    9600 5750
	0    1    1    0   
$EndComp
Wire Wire Line
	9200 5750 9450 5750
Wire Wire Line
	9200 5650 9800 5650
Wire Wire Line
	9750 5750 10500 5750
Wire Wire Line
	10500 5750 10500 2400
Wire Wire Line
	10500 2400 6550 2400
Wire Wire Line
	10100 5650 10400 5650
Wire Wire Line
	10400 5650 10400 2500
Wire Wire Line
	10400 2500 6550 2500
Wire Wire Line
	3300 5100 3300 1050
Wire Wire Line
	3300 1050 6550 1050
Wire Wire Line
	6550 1050 6550 1700
Connection ~ 3300 5100
Wire Wire Line
	3300 5100 3150 5100
Wire Wire Line
	8550 3450 9100 3450
Wire Wire Line
	9100 3450 9100 4800
Wire Wire Line
	9100 4800 7000 4800
Wire Wire Line
	7000 4800 7000 5150
Wire Wire Line
	7000 5650 6950 5650
Wire Wire Line
	6950 5650 6950 4750
Wire Wire Line
	6950 4750 9050 4750
Wire Wire Line
	9050 4750 9050 3950
Wire Wire Line
	9050 3950 8550 3950
Wire Wire Line
	6900 4700 9000 4700
Wire Wire Line
	9000 4700 9000 3550
Wire Wire Line
	9000 3550 8550 3550
Wire Wire Line
	7000 5250 6900 5250
Wire Wire Line
	6900 5250 6900 4700
Wire Wire Line
	6650 6350 3800 6350
Wire Wire Line
	6650 3100 6800 3100
Connection ~ 6800 3100
Wire Wire Line
	7000 5750 6850 5750
Wire Wire Line
	6850 5750 6850 4650
Wire Wire Line
	6850 4650 8950 4650
Wire Wire Line
	8950 4650 8950 4050
Wire Wire Line
	8950 4050 8550 4050
Wire Wire Line
	7000 5350 6800 5350
Wire Wire Line
	6800 5350 6800 4600
Wire Wire Line
	6800 4600 8900 4600
Wire Wire Line
	8900 4600 8900 3650
Wire Wire Line
	8900 3650 8550 3650
Wire Wire Line
	8850 4550 8850 4150
Wire Wire Line
	8850 4150 8550 4150
$Comp
L 74xx:74HC595 U?
U 1 1 61513012
P 8150 3850
F 0 "U?" H 8150 4631 50  0000 C CNN
F 1 "74HC595" H 8150 4540 50  0000 C CNN
F 2 "" H 8150 3850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 8150 3850 50  0001 C CNN
	1    8150 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 5850 7000 6000
Wire Wire Line
	7000 6000 9250 6000
Wire Wire Line
	9250 6000 9250 4550
Wire Wire Line
	9250 4550 8850 4550
Wire Wire Line
	7000 5450 6900 5450
Wire Wire Line
	6900 5450 6900 6050
Wire Wire Line
	6900 6050 9300 6050
Wire Wire Line
	9300 6050 9300 3750
Wire Wire Line
	9300 3750 8550 3750
Wire Wire Line
	7000 5550 6800 5550
Wire Wire Line
	6800 5550 6800 6100
Wire Wire Line
	6800 6100 9350 6100
Wire Wire Line
	9350 6100 9350 3850
Wire Wire Line
	9350 3850 8550 3850
Wire Wire Line
	8150 4550 6650 4550
Connection ~ 6650 4550
Wire Wire Line
	6650 4550 6650 6350
Wire Wire Line
	8150 3250 10300 3250
Wire Wire Line
	10300 3250 10300 6400
Wire Wire Line
	10300 6400 3700 6400
Wire Wire Line
	3700 6400 3700 5700
Connection ~ 3700 5700
Wire Wire Line
	3700 5700 3950 5700
Wire Wire Line
	7750 4050 6650 4050
Connection ~ 6650 4050
Wire Wire Line
	6650 4050 6650 4550
$EndSCHEMATC
