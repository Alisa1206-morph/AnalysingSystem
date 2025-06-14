#include <LiquidCrystal.h>

int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_1.begin(16, 2); 
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()
{
  float vout = analogRead(A0) * (5.0/1024);
  float degrees = (vout - 0.5) * 100;
  
  Serial.println(degrees);
  lcd_1.setCursor(0, 0);
  String message = "Temp:" + String(degrees) + "C";
  lcd_1.print(message);
  delay(10000);
}

//

int RED_PIN = 10;
int YELLOW_PIN = 9;
int GREEN_PIN = 8;
int TRIG_PIN = 7;
int ECHO_PIN = 6;

void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  float cm = (duration / 2) / 29.1;
  Serial.println(cm);
  if (cm < 100)
  {
    digitalWrite(RED_PIN, HIGH);
    delay(1000);
    digitalWrite(RED_PIN, LOW);
  }
  else if (cm > 100 && cm < 160)
  {
    digitalWrite(YELLOW_PIN, HIGH);
    delay(1000);
    digitalWrite(YELLOW_PIN, LOW);
  }
  else
  {
    digitalWrite(GREEN_PIN, HIGH);
    delay(1000);
    digitalWrite(GREEN_PIN, LOW);
  }
  
  delay(1000);
}

//

void setup() 
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop() 
{
  int value = analogRead(A0);
  Serial.println(value);
  if(value > 800)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  delay(1000);
}