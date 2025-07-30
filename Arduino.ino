#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Servo.h>
#include <HX711_ADC.h>
#include <EEPROM.h>

Adafruit_INA219 ina219;
Servo ESC;  // Create servo object to control the ESC

const int HX711_dout = 2;    // HX711 dout pin
const int HX711_sck = 3;     // HX711 sck pin
int potValue;                // Value from the analog pin
const int calVal_eepromAdress = 0;
unsigned long t = 0;

HX711_ADC LoadCell(HX711_dout, HX711_sck);

void setup() {
    Serial.begin(115200);
    ESC.attach(9, 1000, 2000);   // (Pin 9, Min pulse width, Max pulse width in microseconds)

    uint32_t currentFrequency;

    LoadCell.begin();
    float calibrationValue;
    calibrationValue = 1132.54;  // Calibration value from calibration.ino

    unsigned long stabilizingtime = 2000;
    boolean _tare = true;
    LoadCell.start(stabilizingtime, _tare);
    if (LoadCell.getTareTimeoutFlag()) {
        Serial.println("Timeout, check HX711 wiring and pin designations");
        while (1);
    } else {
        LoadCell.setCalFactor(calibrationValue);
        Serial.println("Startup is complete");
    }

    if (!ina219.begin()) {
        Serial.println("Failed to find INA219 chip");
        while (1) {
            delay(10);
        }
    }

    ESC.write(potValue);
    delay(4000);
    Serial.println("Now Measuring Data");
}

void loop() {
    float shuntvoltage = 0;
    float busvoltage = 0;
    float current_mA = 0;
    float loadvoltage = 0;
    float power_mW = 0;
    static boolean newDataReady = 0;

    ESC.write(potValue);  // Send the signal to the ESC
    if (potValue < 20) {
        potValue++;
    }

    for (int i = 0; i < potValue * 5; i++) {
        while (!newDataReady) {
            if (LoadCell.update()) newDataReady = true;
        }
        float loadcell = LoadCell.getData();
        Serial.print(loadcell); Serial.print("\t");  // Thrust (g)
        newDataReady = 0;

        shuntvoltage = ina219.getShuntVoltage_mV();
        busvoltage = ina219.getBusVoltage_V();
        current_mA = ina219.getCurrent_mA();
        power_mW = ina219.getPower_mW();
        loadvoltage = busvoltage + (shuntvoltage / 1000);

        // Bus Voltage (V), Shunt Voltage (mV), Load Voltage (V), Current (mA), Power (mW)
        Serial.print(busvoltage); Serial.print("\t");
        Serial.print(shuntvoltage); Serial.print("\t");
        Serial.print(loadvoltage); Serial.print("\t");
        Serial.print(current_mA); Serial.print("\t");
        Serial.print(power_mW); Serial.println("\t");
    }
}
