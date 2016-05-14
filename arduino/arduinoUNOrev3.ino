// DH11 tempreture and Humidity sensor
#include <dht.h> // dht.t library

/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
// I2C Display for I2C bus and LCD Display
#include <LiquidCrystal_I2C.h>


#define dht_apin A0 // Analog Pin sensor is connected to


// import for Power Line
char blueToothVal ;           //value sent over via bluetooth
char lastValue = 48;

// Water Level Sensor
const int sensorPin= 1; //sensor pin connected to analog pin A0
int liquid_level;


int sensorLDR = A2; // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor

dht DHT;



LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address



void setup(){

  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(sensorPin, INPUT);//the liquid level sensor will be an input to the arduino
  delay(6000);//Delay to let system boot



  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight

// ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on




}//end "setup()"

void loop(){

//LDR Sensor

sensorValue = analogRead(sensorLDR); // read the value from the sensor

Serial.println(sensorValue); //prints the values coming from the sensor on the screen


// water level sensor
  liquid_level= analogRead(sensorPin); //arduino reads the value from the liquid level sensor

  Serial.println(liquid_level);//prints out liquid level sensor reading

  lcd.setCursor(0,1); //Start at character 4 on line 0
  lcd.print("Water :");
  lcd.print((float)liquid_level, 0);


// Water level sensor end



    //Start of Program

    DHT.read11(dht_apin);


    Serial.println(DHT.humidity);

    Serial.println(DHT.temperature);

    lcd.setCursor(0,0); //Start at character 4 on line 0
    lcd.print("Temperaure :");
    lcd.print((float)DHT.temperature, 0);




  //Fastest should be once every two seconds.



Serial.println (lastValue);
    blueToothVal=Serial.read(); //read it

  if (blueToothVal=='n')
  {//if value from bluetooth serial is n
    digitalWrite(13,HIGH);            //switch on LED
    if (lastValue!='n')
      Serial.println(lastValue); //print LED is on
    lastValue=blueToothVal;
  }
  else if (blueToothVal=='f')
  {//if value from bluetooth serial is n
    digitalWrite(13,LOW);             //turn off LED
    if (lastValue!='f')
      Serial.println(lastValue); //print LED is on
    lastValue=blueToothVal;
  }

delay(3000);//Wait 5 seconds before accessing sensor again.






}// end loop()
