//Program to 
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


//int Buzzer = 10;

int led = 12;

int Gassensor = A0;

int motor11 = 10;

int motor12 = 11;




void setup() 

{

   //pinMode(Buzzer,OUTPUT);

   pinMode(motor11,OUTPUT);

   pinMode(motor12,OUTPUT);

   pinMode(led,OUTPUT);

   Serial.begin(9600);

   

   lcd.begin(16, 2);

  lcd.print("ENGINEERS GARAGE");

  lcd.setCursor(0, 1);

}



void loop() {


  int sensorValue = analogRead(Gassensor);

  Serial.println(sensorValue);

  delay(1);      

  

  if(sensorValue < 200)

  {

   // digitalWrite(Buzzer,HIGH);

    

    digitalWrite(led,HIGH);

    delay(1000);

    digitalWrite(motor11,HIGH);

    digitalWrite(motor12,LOW);

    delay(500);

    digitalWrite(motor11,LOW);

    digitalWrite(motor12,LOW);

    delay(1000);

    

    lcd.setCursor(0, 2);

  lcd.print("Smoke Not Detected");

  

  }

  else if (sensorValue > 400)

  {

   // digitalWrite(Buzzer,LOW);

    

    digitalWrite(led,LOW);

    delay(1000);

  

    digitalWrite(motor11,LOW);

    digitalWrite(motor12,LOW);

    delay(1000);

    

    lcd.setCursor(0, 2);

  lcd.print("Smoke Detected");

  

  }

}
