//voice control
const int relay1pin =13 ;
const int relay2pin =2;
const int toggle1 = 8;
const int toggle2 = 9;
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
Serial.println("voice recognition");
lcd.println("voice recognition");
pinMode(relay1pin,OUTPUT);
pinMode(relay2pin,OUTPUT);
pinMode(toggle1,INPUT);
pinMode(toggle2,INPUT);

digitalWrite(relay1pin,LOW);
digitalWrite(relay1pin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
int toggle1state= digitalRead(toggle1);
int toggle2state= digitalRead(toggle2);
if(toggle1state==1){
  digitalWrite(relay1pin,LOW);
   digitalWrite(relay2pin,HIGH);//active low configuration
  lcd.setCursor(0,1);
 
  lcd.println("1st relay is on");
  Serial.println("1st relay is on");
   
}
else if(toggle2state==1){
  digitalWrite(relay2pin,LOW);
   digitalWrite(relay1pin,HIGH);//active low configuration
  lcd.setCursor(0,1);
  lcd.println("2nd relay is on");
  Serial.println("2nd relay is on");
   
}
}
