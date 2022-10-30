#include dht.h
#include LiquidCrystal.h
#define SoilSensor A0
#define dht11 A1
int pompa = 13;
LiquidCrystal lcd(12,11,5,4,3,2);
dht DHT;
void sensorTanah(){
sensorSuhu();
int kelembabanTanah = analogRead(SoilSensor);
kelembabanTanah = map(kelembabanTanah, 1023,0,0,100);
lcd.setCursor(0,1);
lcd.print(Soil Hum = );
lcd.print(kelembabanTanah);
lcd.print( % );
delay(3000);
if(kelembabanTanah=20){
siram();
}
}
void sensorSuhu(){
DHT.read11(dht11);
lcd.setCursor(0,0);
lcd.print(Temp = );
lcd.print(DHT.temperature);
lcd.print( C);
}
void siram(){
digitalWrite(pompa, LOW);
lcd.setCursor(0,0);
lcd.print(Sedang Menyiram);
lcd.setCursor(0,1);
lcd.print( );
delay(5000);
digitalWrite(pompa, HIGH);
lcd.setCursor(0,0);
lcd.print(Tunggu hingga );
lcd.setCursor(0,1);
lcd.print(air meresap);
17
delay(5000);
}
void setup() {
Serial.begin(9600);
lcd.begin(16,2);
pinMode(SoilSensor,INPUT);
pinMode(dht11, INPUT);
pinMode(pompa,OUTPUT);
digitalWrite(pompa,HIGH);
}
void loop() {
sensorTanah();
}