//DEFINIÇÃO DE CONSTANTES
const int red = 11;
const int green = 10;
const int blue= 9;
const int buzzer = 12;
const int flamepin = A1;
const int thereshold = 30;

//DEFINIÇÕES DE PINOS
void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(flamepin, INPUT);
}

//DEFINE A COR QUE O RGB EXIBIRÁ
void setColor(int redValue, int greenValue, int blueValue){
  analogWrite(red, redValue);
  analogWrite(blue, blueValue);
  analogWrite(green, greenValue);
  }

//LOOP PRINCIPAL
void loop(){
  int flamesenseval = analogRead(flamepin);
  Serial.println(flamesenseval);
  if(flamesenseval >= thereshold){
    setColor(255, 0, 0); //red
    tone(buzzer, 1000);
    delay(10);
  }else{
    setColor(0, 255, 0); // green
    noTone(buzzer);
  }
}