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
