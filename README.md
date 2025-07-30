# Propeller Performance Analysis

This project compares the aerodynamic performance of a traditional 3-blade propeller and a toroidal propeller.
Data from thrust, noise level, and power consumption using Arduino-compatible sensors and analyzed efficiency using theoretical models.

## 🔬 Overview
- Evaluated performance using real-time sensor data (load cell, INA219, tachometer, dB meter)
- Used MATLAB and Python to model thrust vs. RPM and efficiency curves
- Designed and 3D-printed both propeller types based on NACA 63-412 airfoil
- Analyzed trade-offs between efficiency and noise for drone and UAV applications
3-blade propeller

<img width="716" height="430" alt="Wind Turbine" src="https://github.com/user-attachments/assets/a53e1f3e-d5ae-447d-a5a4-d8e1529a51cb" />

Toroidal Propeller

<img width="697" height="426" alt="Toroidal Wind Turbine" src="https://github.com/user-attachments/assets/87eea7da-5704-498a-8c82-e717370f277e" />

## 📁 Project Structure
- `Arduino_Code/`: Arduino sketch for data collection
- `Data/`: Raw data and processed output files
- `Figures/`: Plots and diagrams from the analysis
- `Models/`: MATLAB and Python scripts for theoretical modeling
- `CAD_Designs/`: STL files for the 3D printed propellers
- `Report/`: Final write-up of the experimental study
<img width="1188" height="843" alt="Wiring Diagram" src="https://github.com/user-attachments/assets/44900875-16f8-4907-a3d7-9d5edb32c029" />

## 📊 Key Findings
- Toroidal propeller showed higher efficiency at lower RPMs with reduced acoustic signature
- Traditional 3-blade propeller outperformed at higher RPMs in both thrust and noise
- Trade-off point identified near 2000 RPM — critical for optimizing drone designs

## 📷 Sample Plot

![Prop Thrustplots](https://github.com/user-attachments/assets/47cda380-2c66-48fb-b220-9f411f2a6c92)

![Noise Eff Plots](https://github.com/user-attachments/assets/fd25ea4e-8f06-42e4-9466-e995b4dc19a4)

## 🛠️ Tools Used
- Arduino Uno, Load Cell + HX711, INA219 Current Sensor
- MATLAB, Python (Jupyter Notebook), Excel
- 3D Printing (Prusa i3 Mk3S), PLA Filament
- Digital Tachometer, iPhone Decibel Meter
