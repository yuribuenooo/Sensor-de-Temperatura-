//Sensor de temperatura 

#define TMP A5

#define LR 3
#define LB 4
#define LG 6

#define BUZZER 7

// condições paraa led RGB ser acionada

void escala(float t ){
  if( t > 30) {
    analogWrite(LR,255);
    analogWrite(LG,0);
    analogWrite(LB,0);
  }
  else if ( t > 20 && t <= 30){
    analogWrite(LR,0);
    analogWrite(LG,255);
    analogWrite(LB,0);
  }
  else if ( t >= 10 && t <=20){
    analogWrite(LR,0);
    analogWrite(LG,0);
    analogWrite(LB,255);
  }
 else if ( t >= 0 && t <=10){
    analogWrite(LR,255);
    analogWrite(LG,191);
    analogWrite(LB,0);
  }
  else {
    
    analogWrite(LG,179);
    analogWrite(LB,186);
  }
}
void setup()
{
  pinMode(TMP, INPUT);
  pinMode(LR, OUTPUT);
  pinMode(LG, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  float valor = analogRead(TMP);
  float c = (( valor * 5/1024 ) - 0.5) * 100;
  Serial.print("Temp:");
  Serial.print(c);
  Serial.println(" Graus");
  escala(c);
  
  //Condiçõeas para a buzina acionar
  if( c >=45 || c <= -10)
    digitalWrite(BUZZER,HIGH);
  else digitalWrite(BUZZER,LOW);
  
  delay(1000);
}