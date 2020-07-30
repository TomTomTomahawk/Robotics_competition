//28.26: perimètre roue
//7.065cm: 1 detection
//projection: 47 cm
//153/7.065=21.6


//HALL EFFECT SENSOR
int hallSensorPin = 12;//On connecte le hall sensor sur le pin 13
int state = 0;//variable to store the value read
//int 
 
unsigned int count = 0;

long laststate = 0;  // the last time the output pin was toggled

//  MOTEUR A : MOTEUR CHASSIS ARRIÈRE
int ENA=5; //Connecté à Arduino pin 5(sortie pwm)
int IN1=2; //Connecté à Arduino pin 2
int IN2=3; //Connecté à Arduino pin 3

//  MOTEUR B : MOTEUR ÉCHELLE
int ENB=6; //Connecté à Arduino pin 6(Sortie pwm)
int IN3=4; //Connecté à Arduino pin 4
int IN4=7; //Connecté à Arduino pin 7

void setup() {

  Serial.begin(9600);              //  setup serial

// HALL EFFECT SENSOR

pinMode(hallSensorPin, INPUT);//hall sensor

//  MOTEURS
  
 pinMode(ENA,OUTPUT);//Configurer les broches comme sortie
 pinMode(ENB,OUTPUT);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 digitalWrite(ENA,LOW);// Moteur A - Ne pas tourner (désactivation moteur)
 digitalWrite(ENB,LOW);// Moteur B - Ne pas tourner (désactivation moteur)

 // Direction du Moteur A
 digitalWrite(IN1,LOW); 
 digitalWrite(IN2,HIGH);

 // Direction du Moteur B
 // NB: en sens inverse du moteur A
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
}

void loop() {

analogWrite(ENA,0);
 delay(3000);
 analogWrite(ENA,150);
delay(3000);
 analogWrite(ENA,0);
delay(5000);
 
 digitalWrite(IN1,HIGH); 
 digitalWrite(IN2,LOW);
 
analogWrite(ENA,0);
 delay(3000);
 analogWrite(ENA,150);
delay(3000);
 analogWrite(ENA,0);
delay(3000);
  delay(10000000);
 count = 0;
 
 while(count<20){//On estime qu'on n'a besoin de faire que 15 tours de roue
    
  analogWrite(ENA,150);//Run chassis motor
  
  state = digitalRead(hallSensorPin);//sample the state of the hall effect sensor

  //filter out any noise by setting a time buffer
  if (state != laststate){
  Serial.println("detect");
  count ++;//Count+1 as there has been a legitimate state change
  laststate = state; //set the current time
  Serial.println(count*7);
  }}
  
  analogWrite(ENA,0);

  delay(3000);

  //analogWrite(ENB,250);
  delay(3000);
  //analogWrite(ENB,0);
  
  delay(5000000);
  }
  
//analogWrite(ENA,0);

//delay(3000);

//analogWrite(ENB,250);
//delay(3000);
//analogWrite(ENB,0);
  
//delay(5000000);

 // Basic crap
// Moteurs
//analogWrite(ENA,0);
//delay(3000);
//analogWrite(ENA,175);
//delay(3000);
//analogWrite(ENA,0);
//delay(3000);
//analogWrite(ENB,225);
//delay(1500);
//analogWrite(ENB,0);
//delay(500000);
