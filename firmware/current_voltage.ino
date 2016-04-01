#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

// number of analog samples to take per reading
#define NUM_SAMPLES 10

int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;            // calculated voltage


void setup(void) {

  uint32_t currentFrequency;
  Serial.begin(9600);  //May need to lower baud rate if serial output scrambled

  ina219.begin();

  Serial.println("Measuring voltage and current with INA219 ...");
}

void loop(void) {

  float current_mA = 0;

  // take a number of analog samples of voltage and add them up
    while (sample_count < NUM_SAMPLES) {
        sum += analogRead(A2);
        sample_count++;
        delay(10);
    }
    
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.015V is the calibrated reference voltage
    voltage = ((float)sum / (float)NUM_SAMPLES * 5.015) / 1024.0;
    // send voltage for display on Serial Monitor
    // voltage multiplied by 11 when using voltage divider that
    // divides by 11. 11.132 is the calibrated voltage divide
    // value
    Serial.print("Voltage:       ");
    Serial.print(voltage * 11.132);
    Serial.println (" V");
    sample_count = 0;
    sum = 0;

  current_mA = ina219.getCurrent_mA();

  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.println(" mA");

  delay(2000);
}
