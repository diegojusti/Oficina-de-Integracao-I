#include "Ultrasonic.h"

#define echoPinF 13 //Pino 13 recebe o pulso do echo
#define trigPinF 12 //Pino 12 envia o pulso para gerar o echo
#define echoPinD 11 //Pino 11 recebe o pulso do echo
#define trigPinD 10 //Pino 10 envia o pulso para gerar o echo
#define echoPinE 9 
#define trigPinE 8 


#define engine1 2 //Define o pino do motor da Esquerda
#define engine2 3 //Define o pino do motor da Direita
#define engine3 4 //Define o pino do motor Frontal

#define constante 2

//iniciando a função e passando os pinos
Ultrasonic ultrasonicF (12,13);
Ultrasonic ultrasonicD (10,11);
Ultrasonic ultrasonicE (8,9);
void giraMotor(char motor, int distancia);

unsigned int distanciaFront, distanciaEsq, distanciaDir, sensor;

void setup()
{
   Serial.begin(9600); //inicia a porta serial
   pinMode(echoPinF, INPUT);   // (recebe)
   pinMode(trigPinF, OUTPUT); // (envia)
   pinMode(echoPinE, INPUT);  // (recebe)
   pinMode(trigPinE, OUTPUT); // (envia)
   pinMode(echoPinD, INPUT);  // (recebe)
   pinMode(trigPinD, OUTPUT); // (envia)
   // define os pinos de saida que vão para o motor
   pinMode(engine1, OUTPUT);
   pinMode(engine2, OUTPUT);
   distanciaFront = distanciaEsq = distanciaDir = 0;
}

void loop() {
  distanciaFront = leituraSensor(12, 13);
  distanciaEsq = leituraSensor(8, 9);
  distanciaDir = leituraSensor(10, 11);

  giraMotor('f', distanciaFront);
  giraMotor('d', distanciaDir);
  giraMotor('e', distanciaEsq);   
}

// ---------------------------------- LEITURA DO SENSOR FRONTAL ---------------------------------- //

int leituraSensor(int trigPin, int echoPin){
  float distancia = 0;
  //seta o pino TRIG com um pulso "LOW"
    digitalWrite(trigPinF, LOW);
  // delay de 2 microssegundos
    delayMicroseconds(2);
  //seta o pino TRIG com pulso "HIGH"
    digitalWrite(trigPinF, HIGH);
  //delay de 10 microssegundos
    delayMicroseconds(10);
  //seta o pino TRIG com pulso "LOW" novamente
    digitalWrite(trigPinF, LOW);
  // função Ranging, faz a conversão do tempo de resposta do echo em centimetros, e armazena na variavel distancia
    distancia = (ultrasonicF.Ranging(CM));
    Serial.println(distancia);
    return distancia;
}

void giraMotor(char motor, int distancia)
{
   int qualMotor, tempoDelay = 0;

   //Define qual motor irá girar
   if(motor == 'f')
    qualMotor = engine3;
   else if(motor == 'e')
    qualMotor = engine1;
   else if(motor == 'd')
    qualMotor = engine2;

   //Calcula o tempo do delay de acordo com a distancia calculada
   tempoDelay = distancia;
      
   if(distancia == 0 || distancia > 300)
     digitalWrite(qualMotor, LOW);
    
   digitalWrite(qualMotor, HIGH);
   delay(tempoDelay);

   digitalWrite(qualMotor, LOW);
   delay(tempoDelay);
}

