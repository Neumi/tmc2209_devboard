#include <TMCStepper.h> // TMCstepper - https://github.com/teemuatlut/TMCStepper
#include <SoftwareSerial.h> // Software serial - https://www.arduino.cc/en/Reference/softwareSerial

#define MS1_PIN  4
#define MS2_PIN  5
#define EN_PIN 2
#define SW_TX 10
#define SW_RX 9

#define DRIVER_ADDRESS 0x00 // TMC2209 driver address when MS1 LOW and MS2 LOW
#define R_SENSE 0.1f // TMC2209 Devboard v1.2 by Neumi uses 100mOhm
bool dir = false;

SoftwareSerial SoftSerial(SW_RX, SW_TX);
TMC2209Stepper TMCdriverX(&SoftSerial, R_SENSE, DRIVER_ADDRESS);

void setup() {
  SoftSerial.begin(115200);
  TMCdriverX.beginSerial(115200);

  pinMode(EN_PIN, OUTPUT);
  pinMode(MS2_PIN, OUTPUT);
  pinMode(MS1_PIN, OUTPUT);

  digitalWrite(EN_PIN, LOW);
  digitalWrite(MS1_PIN, LOW);
  digitalWrite(MS2_PIN, LOW);


  TMCdriverX.begin();
  TMCdriverX.toff(5);
  TMCdriverX.rms_current(500); // motor current in mA
  TMCdriverX.microsteps(64); // microsteps in 1/x
  TMCdriverX.en_spreadCycle(false);
  TMCdriverX.pwm_autoscale(true); // needed for stealthChop
  TMCdriverX.VACTUAL(12000); // motor speed
  TMCdriverX.step();
}

void loop() {
  delay(100);
  dir = !dir;
  TMCdriverX.shaft(dir);

  delay(500);
  TMCdriverX.VACTUAL(50000);

  delay(500);
  dir = !dir;
  TMCdriverX.shaft(dir);
  delay(500);

  TMCdriverX.VACTUAL(12000);
  delay(200);
  for (int i = 0; i <= 20; i++) {
    dir = !dir;
    TMCdriverX.shaft(dir);
    delay(50);
  }
}
