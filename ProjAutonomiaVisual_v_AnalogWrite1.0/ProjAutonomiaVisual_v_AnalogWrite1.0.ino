#include "Ultrasonic.h"

#define echoPin1 46 //Pino 13 recebe o pulso do echo
#define trigPin1 47 //Pino 12 envia o pulso para gerar o echo
#define echoPin2 48 
#define trigPin2 49
#define echoPin3 50
#define trigPin3 51 

#define motorD 10
#define motorE 11
#define motorF 12

#define fator 2
#define direcao 3
#define maximo 150
#define minimo 30
#define medio 80

//iniciando a função e passando os pinos
Ultrasonic ultrasonicF(trigPin1, echoPin1);
Ultrasonic ultrasonicE(trigPin2, echoPin2);
Ultrasonic ultrasonicD(trigPin3, echoPin3);

//void leituraSensor(char pos);
void giraMotor(char motor, int intervalo);
//void giraMotor();
void gerenciaMotor();
void gerenciarMotor();

unsigned int dE, dD, dF;
char giraE[] = {0, 0, 0};
char giraD[] = {0, 0, 0};
char giraF[] = {0, 0, 0};
char parado[] = {0, 0, 0};
char d, e;

unsigned long tempoAnterior[] = {0, 0, 0};
unsigned long tempoAtual[] = {0, 0, 0};
int intervalo[] = {500, 250, 100};
unsigned int estado = LOW;
int i;

void setup() {
   Serial.begin(9600); //inicia a porta serial
  /* pinMode(echoPin1, INPUT);    // define o pino 13 como entrada (recebe)
   pinMode(trigPin1, OUTPUT);   // define o pino 12 como saida (envia)
   pinMode(echoPin2, INPUT);    //  (recebe)
   pinMode(trigPin2, OUTPUT);   //  (envia)
   pinMode(echoPin3, INPUT);    //  (recebe)
   pinMode(trigPin3, OUTPUT);   //  (envia) */
   // define os pinos de saida que vão para o motor 
   pinMode(motorD, OUTPUT);
   pinMode(motorE, OUTPUT);
   
   dE = dF = dD = 0;

}

void loop() {

  Serial.print("Distancia frontal:");
  Serial.println(dF);

  Serial.print("Distancia esquerda:");
  Serial.println(dE);

  Serial.print("Distancia direita:");
  Serial.println(dD);

  
  dF = ultrasonicF.Ranging(CM);
  dE = ultrasonicE.Ranging(CM);
  dD = ultrasonicD.Ranging(CM);
  //gerenciaMotor();
  gerenciarMotor();
  //analogWrite(motorE, 254);
  delay(10);
}

void gerenciarMotor(){

  if(dE >= minimo && dE < maximo){
    if(!giraE[0]){
      analogWrite(motorE, 160);
      giraE[0] = 1;
      giraE[1] = 0;
      giraE[2] = 0;
    }   
  }
  else if(dE > 0 && dE < minimo){
    if(!giraE[1]){
      analogWrite(motorE, 120);
      giraE[1] = 1;
      giraE[2] = 0;
      giraE[0] = 0;
    }
  }
  else{
    if(!giraE[2]){
      digitalWrite(motorE, HIGH);  
      giraE[2] = 1;
      giraE[1] = 0;
      giraE[0] = 0;
    }  
  }
    
if(dD >= minimo && dD < maximo){
    if(!giraD[0]){
      analogWrite(motorD, 160);
      giraD[0] = 1;
      giraD[1] = 0;
      giraD[2] = 0;
    }   
  }
  else if(dD > 0 && dD < minimo){
    if(!giraD[1]){
      analogWrite(motorD, 120);
      giraD[1] = 1;
      giraD[2] = 0;
      giraD[0] = 0;
    }
  }
  else{
    if(!giraD[2]){
      digitalWrite(motorD, HIGH);  
      giraD[2] = 1;
      giraD[1] = 0;
      giraD[0] = 0;
    }  
  }
   
if(dF >= minimo && dF < maximo){
    if(!giraD[0]){
      analogWrite(motorF, 150);
      giraF[0] = 1;
      giraF[1] = 0;
      giraF[2] = 0;
    }   
  }
  else if(dF > 0 && dF < minimo){
    if(!giraF[1]){
      analogWrite(motorF, 110);
      giraF[1] = 1;
      giraF[2] = 0;
      giraF[0] = 0;
    }
  }
  else{
    if(!giraF[2]){
      digitalWrite(motorF, HIGH);  
      giraF[2] = 1;
      giraF[1] = 0;
      giraF[0] = 0;
    }  
  }
  
}


void gerenciaMotor(){
  tempoAtual[0] = millis();
  if(dE >= minimo && dE < maximo){ 
    intervalo[0] = maximo;
    if(tempoAtual[0] - tempoAnterior[0] >= intervalo[0]){
      estado = ~estado;
      digitalWrite(motorE, estado);
      tempoAnterior[0] = millis();
    }
  }/*
  else if (dE >= minimo && dE < medio){
    intervalo[0] = medio;
    if(tempoAtual[0] - tempoAnterior[0] >= intervalo[0]){
      estado = ~estado;
      digitalWrite(motorE, estado);
      tempoAnterior[0] = millis();
    }
  }*/
  else if (dE > 0 && dE < minimo){
      if(tempoAtual[0] - tempoAnterior[0] >= intervalo[0]){
      estado = ~estado;
      digitalWrite(motorE, estado);
      tempoAnterior[0] = millis();
     }
  }
  else{
    digitalWrite(motorE,HIGH);
  }
  
  tempoAtual[1] = millis();
  if(dD >= medio && dD < maximo){ 
    intervalo[1] = maximo;
    if(tempoAtual[1] - tempoAnterior[1] >= intervalo[1]){
      estado = ~estado;
      digitalWrite(motorE, estado);
      tempoAnterior[1] = millis();
    }
  }/*
  else if (dD >= minimo && dD < medio){
    intervalo[1] = medio;
    if(tempoAtual[1] - tempoAnterior[1] >= intervalo[1]){
      estado = ~estado;
      digitalWrite(motorD, estado);
      tempoAnterior[1] = millis();
    }
  }*/
  else if (dD > 0 && dD < minimo){
      if(tempoAtual[1] - tempoAnterior[1] >= intervalo[1]){
      estado = ~estado;
      digitalWrite(motorD, estado);
      tempoAnterior[1] = millis();
     }
  }
  else{
    digitalWrite(motorD, HIGH);
  }
  
  
}


