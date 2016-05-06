#include "Ultrasonic.h"

#define echoPinF 13 //Pino 13 recebe o pulso do echo
#define trigPinF 12 //Pino 12 envia o pulso para gerar o echo
#define echoPinD 11 
#define trigPinD 10 
#define echoPinE 9 
#define trigPinE 8 

#define engine1 2
#define engine2 3


//iniciando a função e passando os pinos
Ultrasonic ultrasonicF (12,13);
Ultrasonic ultrasonicD (10,11);
Ultrasonic ultrasonicE (8,9);

unsigned int dF, dE, dD, sensor;

void setup()
{
   Serial.begin(9600); //inicia a porta serial
   pinMode(echoPinF INPUT);   // (recebe)
   pinMode(trigPinF, OUTPUT); // (envia)
   pinMode(echoPinE, INPUT);  // (recebe)
   pinMode(trigPinE, OUTPUT); // (envia)
   pinMode(echoPinD, INPUT);  // (recebe)
   pinMode(trigPinD, OUTPUT); // (envia)
   // define os pinos de saida que vão para o motor
   pinMode(engine1, OUTPUT);
   pinMode(engine2, OUTPUT);
   dF = dE = dD = 0;

}

void loop() {
  leituraSensorF();
  leituraSensorD();
  leituraSensorE();
  if(dE == 0 || dF == 0 || dD == 0)
    digitalWrite(engine2, LOW);
    
  if(distancia >= 150 && distancia < 200){
      while(distancia >= 150 && distancia < 200){
        Serial.print("PERTO 200");
        digitalWrite(engine2, HIGH);
        delay(MAX/2);
        digitalWrite(engine2, LOW);
        delay(MAX/2);
        leituraSensor();
      }
  }
  else if(distancia >= 100 && distancia < 150){
      while(distancia > 100 && distancia < 150){
        Serial.print("PERTO 200");
        digitalWrite(engine2, HIGH);
        delay(MAX/3);
        digitalWrite(engine2, LOW);
        delay(MAX/3);
        leituraSensor();
      }
  }
  else if(distancia >= 50 && distancia < 100){
      while(distancia > 100 && distancia < 150){
        Serial.print("PERTO 200");
        digitalWrite(engine2, HIGH);
        delay(MAX/4);
        digitalWrite(engine2, LOW);
        delay(MAX/4);
        leituraSensor();
      }
  }
  else if(distancia > 0 && distancia < 50){
      while(distancia > 100 && distancia < 150){
        Serial.print("PERTO 200");
        digitalWrite(engine2, HIGH);
        delay(MAX/6);
        //digitalWrite(engine2, LOW);
        //delay(MAX/6);
        leituraSensor();
      }
  }
  delay(100); // delay de 0,1 segundos
}

// ---------------------------------- LEITURA DO SENSOR FRONTAL ---------------------------------- //

void leituraSensorF(){

    //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    digitalWrite(trigPinF, LOW);
  // delay de 2 microssegundos
    delayMicroseconds(2);
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    digitalWrite(trigPinF, HIGH);
  //delay de 10 microssegundos
    delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
    digitalWrite(trigPinF, LOW);
  // função Ranging, faz a conversão do tempo de
  //resposta do echo em centimetros, e armazena
  //na variavel distancia
    dF = (ultrasonicF.Ranging(CM));
    Serial.println(dF);

}

// ---------------------------------- LEITURA DO SENSOR DA ESQUERDA ---------------------------------- //

void leituraSensorE(){

    //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    digitalWrite(trigPinE, LOW);
  // delay de 2 microssegundos
    delayMicroseconds(2);
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    digitalWrite(trigPinE, HIGH);
  //delay de 10 microssegundos
    delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
    digitalWrite(trigPinE, LOW);
  // função Ranging, faz a conversão do tempo de
  //resposta do echo em centimetros, e armazena
  //na variavel distancia
    dE = (ultrasonicE.Ranging(CM));
    Serial.println(dE);

}

// ---------------------------------- LEITURA DO SENSOR DA DIRETA ---------------------------------- //

void leituraSensorD(){

    //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    digitalWrite(trigPinD, LOW);
  // delay de 2 microssegundos
    delayMicroseconds(2);
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    digitalWrite(trigPinD, HIGH);
  //delay de 10 microssegundos
    delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
    digitalWrite(trigPinD, LOW);
  // função Ranging, faz a conversão do tempo de
  //resposta do echo em centimetros, e armazena
  //na variavel distancia
    dD = (ultrasonicD.Ranging(CM));
    Serial.println(dD);

}
 

