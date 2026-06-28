# LDR-Smart-Light-Sensor_ESP32_30-Pin
**Objective**

The objective of this project is to develop an **ESP32-based Smart Light Monitoring System** using an **LDR (Light Dependent Resistor)** sensor to automatically detect ambient light intensity. Based on a predefined threshold, the ESP32 controls an **LED**, **buzzer**, and **16×2 I2C LCD** to indicate bright or dark conditions in real time. This project demonstrates practical skills in **sensor interfacing, analog data acquisition (ADC), I2C communication, GPIO control, and Embedded C firmware development** using the Arduino IDE.

🔰**Working Principle / Operation**
✅🔰⬇️⬆️▫️▪️◾◽◼️◻️🔸🟡🔴♦️

🟡**Project: ESP32 Smart Light Monitoring System using LDR Sensor, I2C LCD, LED & Buzzer**

🔸**Power ON** 

    The ESP32 initializes the LDR sensor, I2C LCD, LED, and buzzer.
  
🔸**Light Detection** 

    The LDR (Light Dependent Resistor) senses the surrounding light intensity. Its resistance changes with light, producing an analog         voltage that is read by the ESP32 through its ADC (GPIO34).
  
🔸**Analog Data Processing** 

    The ESP32 continuously reads the LDR value and compares it with a predefined threshold.
  
🔸**Decision Making**

    If the light intensity is below the threshold (Dark):
                     LED turns ON
                     Buzzer turns ON
  LCD displays 👇
    "ROOM DARK" and "LED ON"    
  If the light intensity is above the threshold (Bright):
                     LED turns OFF
                     Buzzer turns OFF
  LCD displays 👇
    "ROOM BRIGHT" and "LED OFF"
🔸**Continuous Monitoring** 

    The ESP32 repeats this process continuously, providing real-time automatic light monitoring and indication.

 The ESP32 continuously reads the LDR's analog light intensity, compares it with a preset threshold, and automatically controls the LED,   buzzer, and LCD to indicate whether the surrounding environment is bright or dark.

✅ **Live Demo Video** 👇👇

https://youtu.be/Wl8HO9bAUD0?si=2uz2Tcgh7JMX3WZd

**Complete Firmware Working (Step-by-Step)**

Phase-1 : Header Files
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
What happens?

These are preprocessor directives.

Before compilation, the Arduino IDE includes the contents of these library files.

#include <Wire.h>

This loads the I2C communication library.

Purpose:

Initializes ESP32's I2C hardware
Allows communication using only
SDA
SCL

Without Wire.h, the LCD cannot communicate with the ESP32.

#include <LiquidCrystal_I2C.h>

This library provides ready-made functions for controlling a 16×2 I2C LCD.

Instead of manually sending I2C commands, functions like

lcd.print();
lcd.clear();
lcd.setCursor();

become available.

Phase-2 : Pin Definitions
#define LDR_PIN 34
#define LED_PIN 26
#define BUZZER_PIN 27

These are macro definitions.

During compilation,

LDR_PIN

is replaced by

34

This uses no RAM, unlike variables.

Meaning:

Symbol	GPIO
LDR_PIN	GPIO34
LED_PIN	GPIO26
BUZZER_PIN	GPIO27
Phase-3 : LCD Object Creation
LiquidCrystal_I2C lcd(0x27,16,2);

An object named

lcd

is created.

Parameters:

0x27

I2C Address

16

16 columns

2

2 rows

Now every command

lcd.print()

is sent to this LCD.

Phase-4 : Threshold Variable
int threshold = 1800;

A global integer variable.

Purpose:

Stores the boundary between

Bright
Dark

ESP32 ADC range:

0 -------- 4095

Example:

3500 → Bright

900 → Dark

Threshold

1800
Phase-5 : setup()

Arduino calls

setup();

only once after reset.

Step-1
Serial.begin(115200);

Starts UART communication.

Baud Rate

115200 bits/sec

Now ESP32 can send data to

Serial Monitor.

Step-2
pinMode(LED_PIN,OUTPUT);

GPIO26 becomes

OUTPUT

Meaning

ESP32 can supply

HIGH

or

LOW

to LED.

Step-3
pinMode(BUZZER_PIN,OUTPUT);

GPIO27 becomes OUTPUT.

Now ESP32 controls Buzzer.

Step-4
lcd.init();

LCD initialization.

Internally

Library sends

Initialization commands

through I2C.

LCD becomes ready.

Step-5
lcd.backlight();

Turns ON LCD backlight.

Without this,

characters may exist

but screen looks dark.

Step-6
lcd.setCursor(0,0);

Moves cursor.

Column = 0

Row = 0

Upper-left corner.

Step-7
lcd.print("Smart Light");

LCD shows

Smart Light
Step-8
lcd.setCursor(0,1);

Moves cursor

Second row.

Step-9
lcd.print("Monitoring");

LCD becomes

Smart Light
Monitoring
Step-10
delay(2000);

CPU waits

2 seconds.

Step-11
lcd.clear();

Erases LCD.

Ready for live monitoring.

setup() Ends

Now Arduino automatically enters

loop();
loop()

This runs forever.

loop()

↓

loop()

↓

loop()

↓

loop()

until power OFF.

Step-1
int ldrValue = analogRead(LDR_PIN);

This is the most important line.

ESP32 ADC starts conversion.

Hardware flow:

Light

↓

LDR Resistance changes

↓

Voltage Divider

↓

Analog Voltage

↓

GPIO34 ADC

↓

12-bit ADC

↓

Digital Number

↓

ldrValue

Example

Room Bright

↓

ADC = 3500

or

Room Dark

↓

ADC = 850
Step-2
Serial.print("LDR Value : ");

Prints

LDR Value :
Step-3
Serial.println(ldrValue);

Suppose ADC

2150

Serial Monitor

LDR Value : 2150
Step-4
lcd.clear();

Removes previous message.

Otherwise

ROOM BRIGHT

may overlap

ROOM DARK
Step-5

Decision Making

if(ldrValue < threshold)

Suppose

ldrValue = 950

threshold =1800

Condition becomes

950<1800

TRUE

CPU enters

if block.

Inside if()
LED
digitalWrite(LED_PIN,HIGH);

GPIO26 outputs

3.3V

LED ON.

Buzzer
digitalWrite(BUZZER_PIN,HIGH);

GPIO27 outputs

HIGH

Buzzer sounds.

LCD
lcd.setCursor(0,0);

Cursor first row.

lcd.print("ROOM DARK");

LCD

ROOM DARK
lcd.setCursor(0,1);

Second row.

lcd.print("LED ON");

LCD

ROOM DARK
LED ON
Serial
Serial.println("Dark Detected");

Serial Monitor

Dark Detected
else Block

Suppose

ldrValue = 3100

Condition

3100<1800

FALSE

CPU jumps

to

else

LED

digitalWrite(LED_PIN,LOW);

GPIO26 becomes

0V

LED OFF.

Buzzer

digitalWrite(BUZZER_PIN,LOW);

GPIO27 becomes LOW.

Buzzer OFF.

LCD

ROOM BRIGHT
LED OFF

Serial

Bright
Last Line
delay(500);

CPU waits

500 ms

This prevents:

Very fast LCD updates
Excessive Serial output
Continuous rapid buzzer switching

The sensor is checked about twice per second.
