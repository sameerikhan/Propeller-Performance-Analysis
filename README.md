# Propeller Performance Analysis

This project compares the aerodynamic performance of a traditional 3-blade propeller and a toroidal propeller.
Data from thrust, noise level, and power consumption using Arduino-compatible sensors and analyzed efficiency using theoretical models.

# Overview
- Evaluated performance using real-time sensor data (load cell, INA219, tachometer, dB meter)
- Used MATLAB and Python to model thrust vs. RPM and efficiency curves
- Designed and 3D-printed both propeller types based on NACA 63-412 airfoil
- Analyzed trade-offs between efficiency and noise for drone and UAV applications

## 📊 Key Findings
- Toroidal propeller showed higher efficiency at lower RPMs with reduced acoustic signature
- Traditional 3-blade propeller outperformed at higher RPMs in both thrust and noise
- Trade-off point identified near 2000 RPM — critical for optimizing drone designs

## 📷 Sample Plot

![Prop Thrustplots](https://github.com/user-attachments/assets/47cda380-2c66-48fb-b220-9f411f2a6c92)


## Tools Used
- Arduino Uno, Load Cell + HX711, INA219 Current Sensor
- MATLAB, Python (Jupyter Notebook), Excel
- 3D Printing (Prusa i3 Mk3S), PLA Filament
- Digital Tachometer, iPhone Decibel Meter
