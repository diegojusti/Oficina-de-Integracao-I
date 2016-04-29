#include "Ultrasonic.h"

#define echoPin 13 //Pino 13 recebe o pulso do echo
#define trigPin 12 //Pino 12 envia o pulso para gerar o echo

#define engine1 2
#define engine2 3


//iniciando a função e passando os pinos
Ultrasonic ultrasonic(12,13);


void setup()
{
   Serial.begin(9600); //inicia a porta serial
   pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
   pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
   pinMode(engine1, OUTPUT);
   pinMode(engine2, OUTPUT);

}

int distancia = 0;

void leitura(){

    //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    digitalWrite(trigPin, LOW);
  // delay de 2 microssegundos
    delayMicroseconds(1);
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    digitalWrite(trigPin, HIGH);
  //delay de 10 microssegundos
    delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
    digitalWrite(trigPin, LOW);
  // função Ranging, faz a conversão do tempo de
  //resposta do echo em centimetros, e armazena
  //na variavel distancia
    distancia = (ultrasonic.Ranging(CM));
    Serial.println(distancia);

}
 
void loop()
{

  int i = 0;
  leitura();
 
  //Serial.print("Distancia em CM: ");
  //Serial.println(distancia);

 // Distancia minima para apitar ou vibrar


 /*
  if(distancia >= 60 && distancia < 120)
  {
    Serial.print(" PERTO 120\n"); 
    digitalWrite(engine1, HIGH);
  }
  else if(distancia >= 40 && distancia < 60)
  {
    Serial.print(" PERTO 60\n");       
  }
  */
  if(distancia >= 20 &&distancia < 40)
  {
    Serial.print(" PERTO 40\n");
    while(distancia >= 20 &&distancia < 40){
      digitalWrite(engine2, HIGH);
      delay(500);
      digitalWrite(engine2, LOW);
      delay(500);
      leitura();
      if(distancia == 0)
       digitalWrite(engine2, LOW);
    }
   
  } 
  else if(distancia >= 10 && distancia < 20)
  {
    Serial.print(" PERTO 20\n"); 
    while(distancia >= 1 &&distancia < 20){
      digitalWrite(engine2, HIGH);
      delay(200);
      digitalWrite(engine2, LOW);
      delay(200);
      leitura();
    }
  }/*
  else if(distancia < 10)
  {
    Serial.print(" PERTO 10\n"); 
  }*/

  if(distancia > 180){
    digitalWrite(engine1, LOW);
    digitalWrite(engine2, LOW);
  }
   if(distancia == 0)
       digitalWrite(engine2, LOW);
  delay(100); //espera 0,1 segundo para fazer a leitura novamente


}



