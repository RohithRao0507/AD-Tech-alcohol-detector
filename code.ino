#include <LiquidCrystal.h>
 LiquidCrystal lcd(8, 9, 10, 11, 12, 13);//RS,EN,D4,D5,D6,D7
#define gas 5
#define engine 6
#define gnd 3
#define relay 7
int alc=0,button=0;
void setup() 
{
  Serial.begin(9600);       // initialize serial communications at 9600 bps:
  pinMode(gas,INPUT);
  pinMode(engine,INPUT_PULLUP);
  pinMode(relay,OUTPUT);
  pinMode(gnd,OUTPUT);
  digitalWrite(relay,HIGH);
  digitalWrite(gnd,LOW);
  lcd.begin(16, 2);//initializing LCD
  lcd.setCursor(0,0);
  lcd.print("Smart Vehicle");
  lcd.setCursor(0,1);
  lcd.print("Protection");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("press key....");
  delay(1000);  
}

void loop() 
{
 if(alc==HIGH)
 { 
  if(button==LOW)
  { 
    lcd.clear(); 
    digitalWrite(relay,LOW);
    lcd.setCursor(0,1);
    lcd.print("safe drive...");
    delay(2000);   
                             
   }
 }
 else
 {
  digitalWrite(relay,HIGH);
  lcd.setCursor(0,0);
  lcd.print("ALCOHOL DETECTED");
  delay(1000);
  lcd.clear(); 
 }
}
