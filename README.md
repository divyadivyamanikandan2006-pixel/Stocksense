# 📦 **StockSense**

### **Smart Inventory Monitoring & Stock-Level Alert System**

> **Measure • Monitor • Detect • Alert**

**StockSense** is an **ESP32-based smart inventory monitoring system** that measures stock weight, monitors inventory level, displays real-time status, and provides automatic alerts for low-stock conditions.

> 🧪 **Prototype:** Designed, implemented and tested using **Wokwi Simulation**

---

## 🚀 **PROJECT OVERVIEW**

StockSense is designed to reduce manual inventory checking by using **sensor-based real-time monitoring**.

The system combines a **50 kg Load Cell, HX711, HC-SR04, ESP32 and 16×2 I2C LCD** to monitor inventory conditions.

The **ESP32** processes the sensor data and classifies the stock as:

🔴 **LOW STOCK**  
🟢 **NORMAL STOCK**  
🔵 **HIGH STOCK**

When the stock level becomes low, the system activates an **LED and Buzzer alert**.

---

## 🎯 **OBJECTIVE**

- ⚖️ Measure inventory weight in real time
- 📦 Monitor stock level automatically
- 📊 Classify inventory into Low, Normal and High
- 🖥️ Display real-time stock information
- 🔔 Provide automatic low-stock alerts
- 📏 Monitor inventory distance using an ultrasonic sensor
- 🧪 Validate the system using Wokwi simulation
- 🚀 Provide a base for future IoT implementation

---

## ❗ **PROBLEM STATEMENT**

Traditional inventory monitoring mainly depends on **manual stock checking**.

This may cause:

- Manual monitoring effort
- Delayed low-stock identification
- Human errors
- Difficulty in continuous monitoring
- Lack of immediate alerts

### 💡 **Solution**

StockSense provides an **automated sensor-based monitoring system** that continuously measures inventory and indicates the current stock condition.

---

## ✨ **KEY FEATURES**

| Feature | Description |
|---|---|
| ⚖️ **Weight Monitoring** | Measures inventory weight using a Load Cell |
| 📊 **Stock Classification** | Detects Low, Normal and High stock |
| 🖥️ **LCD Display** | Displays weight and stock status |
| 📏 **Distance Monitoring** | Uses HC-SR04 for inventory-level monitoring |
| 🔴 **LED Alert** | Indicates low-stock condition |
| 🔊 **Buzzer Alert** | Provides audible low-stock warning |
| 🧠 **ESP32 Control** | Processes sensor data and controls the system |
| 🧪 **Wokwi Simulation** | Enables complete virtual testing |

---

## 🧩 **COMPONENTS**

### 🔧 **HARDWARE**

**ESP32 DevKit**  
**50 kg Load Cell**  
**HX711 Module**  
**16×2 I2C LCD**  
**HC-SR04 Ultrasonic Sensor**  
**LED**  
**Buzzer**  
**220Ω Resistor**  
**Jumper Wires**

### 💻 **SOFTWARE**

**Arduino C/C++**  
**Wokwi Simulator**  
**HX711 Library**  
**LiquidCrystal_I2C Library**  
**Wire Library**

---

## 🔲 **SYSTEM BLOCK DIAGRAM**

![StockSense Block Diagram](diagrams/block-diagram.png)

### **SYSTEM FLOW**

**Load Cell → HX711 → ESP32 → LCD**

**HC-SR04 → ESP32**

**ESP32 → LED + Buzzer**

The **ESP32 acts as the central controller**, processing sensor information and controlling the display and alert system.

---

## 🔌 **CIRCUIT DIAGRAM**

![StockSense Circuit Diagram](diagrams/circuit-diagram.png)

### **PIN CONFIGURATION**

| Component | Connection |
|---|---|
| **LCD SDA** | GPIO 21 |
| **LCD SCL** | GPIO 22 |
| **HX711 DT** | GPIO 18 |
| **HX711 SCK** | GPIO 19 |
| **HC-SR04 TRIG** | GPIO 5 |
| **HC-SR04 ECHO** | GPIO 17 |
| **LED** | GPIO 2 |
| **Buzzer** | GPIO 4 |

### **POWER**

| Component | Power |
|---|---|
| **LCD** | 5V + GND |
| **HX711** | 5V + GND |
| **HC-SR04** | 5V + GND |
| **LED** | GPIO 2 + GND |
| **Buzzer** | GPIO 4 + GND |

### **LOAD CELL → HX711**

**E+ → E+**  
**E- → E-**  
**A+ → A+**  
**A- → A-**

---

## ⚙️ **WORKING PRINCIPLE**

### **01 — SENSE**

The **Load Cell** detects the weight of the inventory.

### **02 — AMPLIFY**

The **HX711** amplifies and converts the load-cell signal.

### **03 — PROCESS**

The **ESP32** reads and processes the sensor value.

### **04 — MONITOR**

The **HC-SR04** measures the distance to the inventory.

### **05 — CLASSIFY**

The ESP32 compares the measured weight with predefined thresholds.

### **06 — DISPLAY**

The **16×2 I2C LCD** displays the weight and stock condition.

### **07 — ALERT**

For low stock, the **LED and Buzzer** are activated automatically.

---

## 📊 **STOCK CLASSIFICATION**

| Weight | Status | LED | Buzzer |
|---:|---|:---:|:---:|
| **< 5 kg** | 🔴 **LOW STOCK** | 🟢 ON | 🔊 ON |
| **5.0 – 5.1 kg** | 🟢 **NORMAL STOCK** | ⚪ OFF | ⚪ OFF |
| **> 5.1 kg** | 🔵 **HIGH STOCK** | ⚪ OFF | ⚪ OFF |

---

## 🔴 **LOW STOCK**

**Condition:** Weight < 5 kg

**System Response:**

`LOW STOCK → LED ON → BUZZER ON`

**LCD Example:**

```text
Weight: 3.2 kg
LOW STOCK!
🟢 NORMAL STOCK OUTPUT
Weight: 5.0 kg
Status: NORMAL STOCK
LED: OFF
Buzzer: OFF
🔵 HIGH STOCK OUTPUT
Weight: 23.8 kg
Status: HIGH STOCK
LED: OFF
Buzzer: OFF
📁 PROJECT STRUCTURE
StockSense/
│
├── README.md
├── sketch.ino
├── diagram.json
├── libraries.txt
│
├── diagrams/
│   ├── block-diagram.png
│   └── circuit-diagram.png
│
└── Demo/
    ├── low-stock.png
    ├── normal-stock.png
    └── high-stock.png
🚀 FUTURE ENHANCEMENTS
The current StockSense prototype can be further developed into a complete IoT-based Inventory Management System.
☁️ Cloud-Based Inventory Monitoring
📱 Mobile Application
🌐 Web Dashboard
🔔 Real-Time Notifications
📦 Multiple Product Monitoring
📊 Inventory History & Analytics
🗄️ Database Integration
🤖 Automated Reordering
📡 Wi-Fi Remote Monitoring
🏭 Industrial Inventory Management
📈 PROJECT STATUS
Module
Status
ESP32 Integration
✅ Completed
Load Cell Integration
✅ Completed
HX711 Integration
✅ Completed
LCD Display
✅ Completed
Ultrasonic Sensor
✅ Completed
LED Alert
✅ Completed
Buzzer Alert
✅ Completed
Stock Classification
✅ Completed
Wokwi Simulation
✅ Completed
Physical Hardware Prototype
🔄 Future Work
IoT Dashboard
🔄 Future Enhancement
🛠️ TECHNOLOGIES USED
ESP32 • Arduino C/C++ • Wokwi • HX711 • Load Cell • HC-SR04 • I2C • Embedded Systems
🌟 PROJECT HIGHLIGHTS
Measure → Monitor → Detect → Alert
StockSense combines:
ESP32 + Load Cell + HX711 + HC-SR04 + LCD + LED + Buzzer
to create a Smart Inventory Monitoring Prototype.
📌 PROJECT INFORMATION
Category
Details
Project Name
StockSense
Project Type
**Embedded Systems Project Application
  Smart Inventory Monitoring
  Controller
  ESP32Platform
  Wokwi
Language
  Arduino C/C++
 Prototype
Simulation-BasedStatus**
✅ Simulation Completed
👩‍💻 DEVELOPER
Divya M
Electronics & Communication Engineering Student
Technical Interests
Embedded Systems • IoT • Sensor Interfacing • Image Processing • MATLAB • PCB Design
Career Focus
Core Electronics • Embedded Systems • IoT • Engineering Projects
“Turning ideas into practical engineering solutions.”
⭐ SUPPORT THE PROJECT
If you find StockSense interesting, consider giving this repository a ⭐ Star.
📦 StockSense
Smart Inventory Monitoring for a Smarter Tomorrow
