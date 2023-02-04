#include <LiquidCrystal.h>

//Program will measure temperature using TEMP36 sensor. Not calibrated, but the value seems to be around 1 degree Celsius less than the real temp.
//Temperature is printed to an 16x2 lcd display

const int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, tem = A0; //Pins rs through d7 are pins used by the lcd display and tem is the temperature sensor value reading pin
float temp, tempc;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  temp = analogRead(tem);
  float volt = (temp / 1024.0)*5.0; //Analog sensor value comes with values between 0 and 1023 (so 1024 total) and is converted to voltage between 0 and 5 volts
  tempc = (volt - .5) * 100; //Here the voltage is converted to Celsius
  

  lcd.setCursor(0, 0);
  lcd.print("Temp in C: ");
  lcd.println(tempc);
  delay(5000); //Temperature is updated in 5 second intervals, change this value to change the update interval (value in milliseconds)
  

}
