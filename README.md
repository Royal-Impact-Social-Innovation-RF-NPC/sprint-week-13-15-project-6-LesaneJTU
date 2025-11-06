# Automated-Waste-Sorter

## **Table of Contents**
- [Repository Content](#repository-content)  
- [About Automated Waste Sorter Documentation](#about-autonanobot-documentation)  
- [Acknowledgment](#acknowledgment)  
- [Introduction](#introduction)  
- [Objective](#objective)  
- [Functionalities](#functionalities)  
- [Hardware Requirements](#hardware-requirements)  
- [Software Requirements](#software-requirements)  
- [Project Description](#project-description)  
- [Applications](#applications)  
- [Performance Flow](#performance-flow)  
- [How to Use / Setup Instructions](#how-to-use--setup-instructions)
- [Circuit Diagram](#Circuit-Diagram)
- [Video Of Prototype Build](#Image-Of-Prototype-Build)
- [Conclusion](#conclusion)  

---
## **Repository Content**

| File / Folder | Description |
|----------------|-------------|
| **/src/** | Contains all source code files for both ESP32 and ESP32-CAM, including servo control, OLED display, and ESP-NOW communication logic. |
| **/waste sorter/** | Project design files, prototype tests, and supporting scripts related to material detection and sorting logic. |
| **Bill Of Materials.pdf** | Detailed list of all components used in the project, including part numbers, quantities, and specifications. |
| **README.md** | Main project documentation explaining setup, design, and usage. |
| **Schematic View.png** | Visual schematic showing hardware wiring connections between ESP32 boards, servos, LEDs, and OLED display. |
| **circuit.png** | Simplified circuit diagram representation of the full system. |
| **ei-waste-sorter-arduino-1.0.1.zip** | Edge Impulse-trained machine learning model exported for Arduino and deployed on the ESP32-CAM. |
| **performance flow.jpg** | Flowchart illustrating the working process of the automated waste sorting system, from detection to actuation. |

---

## **About Automated Waste Sorter Documentation**

This project is part of a **given IOT project** aimed at exploring smart waste management solutions using embedded systems and machine learning.  

This documentation serves as a comprehensive guide to the project, providing a detailed breakdown of the design, implementation, and functionality of the Automated Waste Sorter. It covers hardware and software setup, circuit diagrams, performance flow, and practical usage instructions, enabling readers to understand, replicate, or extend the system.

---

## **Introduction**

The **Automated Waste Sorter** is a smart embedded system designed to **automatically classify and sort waste materials** such as plastic, metal, and paper.  
Using an **ESP32-CAM** for image capture and a **machine learning model** deployed via **Edge Impulse**, the system detects material types in real-time. Detection results are sent wirelessly to an **ESP32 controller** via **ESP-NOW**, which then activates servos, LEDs, and an OLED display to sort the materials into the appropriate bins.  

This project demonstrates the integration of **AI, IoT, and embedded hardware** to improve recycling efficiency and promote sustainable waste management practices.

---

## **Objective**

The main objective of the **Automated Waste Sorter** is to develop a **low-cost, intelligent waste management system** capable of:  
- **Accurately detecting and classifying waste materials** using an on-device AI model.  
- **Automatically sorting materials** into their respective bins with minimal human intervention.  
- Providing **real-time feedback** through an OLED display and LED indicators.  
- Serving as a **hands-on learning tool** for embedded systems, AI deployment, and IoT communication.  

The system is designed to be **replicable, efficient, and scalable**, laying the foundation for more advanced automated recycling solutions.

---

## **Functionalities**

The **Automated Waste Sorter** performs the following key functions:  
- **Real-time Material Detection:** Uses the ESP32-CAM with an Edge Impulse-trained model to classify waste as plastic, metal, or paper.  
- **Wireless Communication:** Sends detection results from the ESP32-CAM to the main ESP32 controller via **ESP-NOW**.  
- **Automated Sorting:** Activates SG90 servo motors to physically direct waste into the correct bin based on classification.  
- **Visual Feedback:** Displays the detected material on the OLED screen and lights up the corresponding LED indicator.  
- **Portable Power Supply:** Runs autonomously using 18650 Li-ion batteries regulated through a 5V DC-DC converter.  
- **Sustainable Construction:** Uses recycled materials for the sorter’s casing and bins, reducing cost and promoting eco-friendliness.  

---

## **Hardware Requirements**

| Component Name | Purpose in Project |
|----------------|------------------|
| **Arduino R4 Uno** | The main controller that runs the sorting logic and communicates with sensors, LEDs, and servo motors. |
| **ESP32-CAM** | Captures images of waste items and sends them wirelessly to the controller for analysis. |
| **ESP32 Camera Base Board** | Provides stable power and USB connection to the ESP32-CAM for programming and testing. |
| **4 × Li-ion 18650 Battery Cells** | Supplies portable power to the entire system for autonomous operation. |
| **18650 Battery Holder** | Holds and connects the four battery cells safely in series or parallel. |
| **On/Off Rocker Switch** | Controls the main power to the circuit, allowing the system to be safely turned on or off. |
| **Breadboard** | Facilitates connecting components without soldering, useful for prototyping and testing. |
| **LEDs** | Visual indicators to display detected waste material categories (Plastic, Paper, Metal). |
| **SG90 Servo Motor** | Mechanically sorts the waste by moving a flap or gate to guide items into the correct bin. |
| **5V DC-DC Step-Down Regulator (Buck Converter)** | Reduces the battery voltage to 5V to safely power the ESP32, servos, and other electronics. |
| **OLED Display Screen** | Shows real-time system information such as the detected material type. |
| **10µF Electrolytic Capacitor** | Helps stabilize small voltage drops and prevent resets on the ESP32 during operation. |
| **220µF Electrolytic Capacitor** | Maintains steady power supply during high-current activities like servo or camera movement. |
| **Recycled Material** | Used to build the sorter’s casing and bins, promoting sustainability and cost-effectiveness. |
| **Jumper Wires** | Flexible wires for connecting components on the breadboard easily during assembly and testing. |
| **220Ω Resistor** | Limits current to LEDs to prevent damage and control brightness. |

---

## **Software Requirements**

### **Software Tools**
| Software | Purpose in Project |
|----------|------------------|
| **Onshape** | Used for designing the 3D parts and casing of the waste sorter before fabrication. |
| **Edge Impulse** | Platform for training and deploying the machine learning model to classify waste materials using the ESP32-CAM. |
| **CorelDraw** | Used for creating laser cutting files for precise cutting of sorter components. |
| **Ultimaker** | 3D printing software used to prepare and print the custom parts of the waste sorter. |
| **Arduino IDE** | Primary development environment for programming the ESP32 and Arduino boards, uploading firmware, and debugging. |

### **Libraries**
| Library | Purpose in Project |
|---------|------------------|
| **EloquentESP32-CAM** | Simplifies interfacing with the ESP32-CAM, including camera initialization and image capture. |
| **Edge Impulse, AFR Robot** | Provides functions for integrating Edge Impulse ML models and handling inference results on the ESP32. |
| **EdgeImpulse, waste_sorter ×3** | Specific Edge Impulse project libraries for material classification used across different modules of the system. |
| **Lesanejtu-project-1_inferencing** | Custom inference library to process images from the camera and classify materials. |
| **edge-impulse-sdk/dsp/image.hpp** | Edge Impulse SDK header for image processing and feature extraction in ML inference. |
| **ESP32Camera** | Low-level ESP32-CAM camera library for capturing images from the camera module. |
| **ESP32Servo** | Library for controlling SG90 servo motors connected to the ESP32. |
| **Wire** | Standard Arduino I2C communication library used for OLED display and other I2C devices. |
| **Adafruit_GFX** | Graphics library providing basic drawing functions for the OLED display. |
| **Adafruit_SSD1306** | Driver library for controlling SSD1306 OLED displays and rendering information. |

---

## **Project Description**

The **Automated Waste Sorter** integrates **embedded hardware, wireless communication, and AI-based image classification** to simplify waste management.  
The workflow is as follows:  
1. The **ESP32-CAM** captures an image of the incoming waste.  
2. The captured image is processed using a **machine learning model** from **Edge Impulse**, identifying the material type.  
3. The classification result is transmitted wirelessly via **ESP-NOW** to the main **ESP32 controller**.  
4. The controller activates the **servo motors** to open the correct bin flap.  
5. LEDs and the **OLED display** provide visual confirmation of the sorting decision.  
6. The system continues this process in real-time for continuous automated sorting.  

This project demonstrates how low-cost hardware and AI can work together to improve recycling efficiency while providing an educational platform for IoT and embedded systems.

---

## **Applications**

The **Automated Waste Sorter** can be applied in various contexts, including:  
- **Smart public waste bins:** Automatically sort recyclables in schools, offices, or public spaces.  
- **Recycling centers:** Assist in separating materials for more efficient processing.  
- **Educational purposes:** Teach students or hobbyists about AI, embedded systems, and IoT integration.  
- **Prototype for industrial automation:** Foundation for developing more advanced automated recycling systems.  
- **Sustainable practices:** Encourages eco-friendly disposal of waste through automation and real-time sorting feedback.

--- 

## **Performance Flow**

The workflow of the **Automated Waste Sorter** is designed for efficiency and accuracy:  

1. **Waste Detection:** An item is placed in front of the ESP32-CAM.  
2. **Image Capture:** The ESP32-CAM captures a photo of the waste.  
3. **Material Classification:** The captured image is analyzed using the **Edge Impulse ML model**, identifying the type of material (Plastic, Metal, or Paper).  
4. **Data Transmission:** The classification result is sent wirelessly via **ESP-NOW** to the ESP32 controller.  
5. **Sorting Actuation:** The controller activates the corresponding **SG90 servo motors** to direct the waste into the correct bin.  
6. **Visual Feedback:** LEDs and the OLED display show the detected material type for confirmation.  
7. **Continuous Operation:** The system repeats the process for the next item, ensuring automated sorting in real-time.  

---

## **How to Use / Setup Instructions**

### **Hardware Setup**
1. Connect the **ESP32-CAM** and **ESP32 controller** according to the schematic.  
2. Connect **SG90 servo motors** to control the bin flap and gate.  
3. Connect **LEDs** for visual indicators of detected materials.  
4. Connect the **OLED display** via I2C (SDA, SCL) for real-time display.  
5. Connect the **battery pack** to the 5V DC-DC step-down converter to power the system.  
6. Use **jumper wires and breadboard** for easy prototyping and testing.  
7. Secure all components, preferably inside the **recycled material casing**.

### **Software Setup**
1. Install the **Arduino IDE** and necessary libraries:  
   - EloquentESP32-CAM  
   - Edge Impulse SDK & project libraries  
   - ESP32Servo  
   - Wire, Adafruit_GFX, Adafruit_SSD1306  
2. Load the **ESP32-CAM firmware** to the camera module.  
3. Load the **ESP32 controller firmware** for servo and LED control.  
4. Configure the **ESP-NOW MAC addresses** to pair the ESP32-CAM with the ESP32 controller.  
5. Open the **Serial Monitor** for debugging and verification.  

### **Quick Start**
1. Power on the system using the rocker switch.  
2. Place a waste item in front of the ESP32-CAM.  
3. Observe the **OLED display** for the detected material.  
4. Watch the **LED indicator** light up corresponding to the material type.  
5. The **servo motors** move automatically to sort the waste into the correct bin.  
6. Repeat for subsequent items for continuous operation.  

---

## **Circuit Diagram**

The **circuit diagram** provides a clear overview of all connections:  

- **ESP32-CAM:** connected to the camera module, powered via 5V from the DC-DC converter.  
- **ESP32 Controller:** connected to servos, LEDs, and OLED display via I2C and PWM pins.  
- **Power System:** 12V Li-ion battery pack regulated to 5V for ESP32 and servos.  
- **Communication:** ESP32-CAM and ESP32 controller paired wirelessly via **ESP-NOW**.  
- **Capacitors:** 10µF and 220µF capacitors used to stabilize voltage during high-current operations.  

Circuit diagrams are available in the repository as:  
- **Schematic View.png** – detailed wiring layout  
- **circuit.png** – simplified overview for quick reference

---

## **Video Of Prototype Build**

https://www.youtube.com/watch?v=wcsxABCgGAs&t=8s 

---

## **Conclusion**

The Automated Waste Sorter effectively illustrates how wireless communication, artificial intelligence, and embedded systems can be combined to automate waste sorting and classification.

Using an Edge Impulse-trained model on the ESP32-CAM, the system detects materials with accuracy. It uses servo motors to physically sort waste into the appropriate bins and communicates the results via ESP-NOW. LEDs and an OLED display provide visual feedback, which makes the process simple to understand and monitor.

In addition to encouraging sustainable waste management, this project offers a hands-on learning environment for embedded programming, IoT, and AI deployment. Future enhancements might involve adding more material types, increasing the precision of detection, or incorporating data logging for analytics.
