# 🧭 Real-Time Ultrasonic Distance Monitor

This project measures and displays the real-time distance of an object using the **HC-SR04 Ultrasonic Distance Sensor** and an **LCD 16x2 display**. It calculates the distance based on the time taken by an ultrasonic pulse to travel to an obstacle and back, then shows the result on both the **Serial Monitor** and the **LCD screen**.

---

## 📷 Overview

The **HC-SR04 sensor** emits ultrasonic waves and measures the time it takes for them to bounce back from an object.  
The **Arduino** processes this duration to calculate the distance and displays it in centimeters.

The LCD displays:
- The project title (`Optic Wizards`) on startup.
- The current distance reading in real time.

---

## ⚙️ Hardware Requirements

- Arduino Uno (or compatible board)
- HC-SR04 Ultrasonic Sensor
- LCD 16x2 Display
- Jumper wires
- Breadboard (optional)

---

## 🔌 Circuit Connections

| Component | Arduino Pin | Description |
|------------|--------------|-------------|
| LCD RS     | 8            | Register Select |
| LCD EN     | 9            | Enable |
| LCD D4     | 4            | Data pin 4 |
| LCD D5     | 5            | Data pin 5 |
| LCD D6     | 6            | Data pin 6 |
| LCD D7     | 7            | Data pin 7 |
| HC-SR04 Trig | 17 (A3)   | Trigger pin |
| HC-SR04 Echo | 16 (A2)   | Echo pin |
| VCC (Sensor) | 13 (or 5V) | Power supply for sensor |
| GND (Sensor + LCD) | GND | Common ground |

> 💡 *Note:* Pin 13 is used as a power source for the sensor in this setup. You can alternatively connect VCC to the Arduino’s 5V pin.

---

## 🧩 Code Explanation

1. **Initialization**
   - The LCD and serial monitor are initialized.
   - A welcome message `"Optic Wizards"` is displayed for 5 seconds.

2. **Distance Measurement**
   - The `trigPin` sends a 10 µs HIGH pulse to trigger the ultrasonic burst.
   - The `echoPin` measures the time it takes for the echo to return.

3. **Distance Calculation**
   ```cpp
   distance = duration * 0.034 / 2;

**HC-SR04 Ultrasonic Sensor**
- More information on:
  https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1

- Amazon:
  https://www.amazon.co.uk/DollaTek-Ultrasonic-Distance-Measuring-Transducer/dp/B07DK55VN7/ref=sr_1_2?dib=eyJ2IjoiMSJ9.Y_6ycxGW9TUCKpc01N8YBBtGU_kVUQ-qQs8GNC6aSmbpHW4IsFvQdoL7rgluhYpk64fgp_T72QLgR3KKNCbEKSx6t4LFIwxbTmOOz0u2ehUOg84v6hAn6Oc7Xij5eMrSdUoXj4Nz8NuLrsT1YGRrdLEy59L_YrgY4rzXC7SmD2ijdKmDHF4nWbkrNqOUi0i8C7aNQlYfv-7fG-ZNNXafLZYHR2-E5Mv9CvY8JuHyVV63kekwViYwIIhLpA-NYHefmahfnRBVatj8m4w5F1Ni-94zAZHYB9KUYrTQ_aty68Q.q9EDfIJRs51n-G5P73trdIdJTM9RaGezcaDWYaz1mFA&dib_tag=se&keywords=HC-SR04&qid=1759775887&sr=8-2

- Ebay:
  https://www.ebay.co.uk/itm/155434881025?_skw=hc+sr04&itmmeta=01K6XD3SAWHQTJT6219H3AF1NV&hash=item2430a41001:g:tfoAAOSwRLBkAMj6&itmprp=enc%3AAQAKAAAA4MHg7L1Zz0LA5DYYmRTS30lvhmEo98G%2BufutT6nuj9%2BpzNbPiaZ8xfaW2FyMjB%2BuwDyEWHIB4OXUbYHhp7dUPcYo3TOwMmy%2BeighhKFPNBVaWqW24c2ji1Rp9tWgNVoQs4wSTBLq8W25qGh8S6Zy8ZHZeeBuN1eSr2LUiqJDLibAkDInh%2B2iAjktg6XxDcAGYiZkhZCDh%2FpFt2bpxkHCexPi1GlGSR%2BxyeS6cgE27aiEeYbRkPQIXgFMlzrFSBYOicnzDI8Bam9hNyAcTVq0OGR%2FblFcwtdeiG1EinUY%2BMfu%7Ctkp%3ABk9SR8iVj623Zg

