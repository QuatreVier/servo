#include <Servo.h>// se llama a la libreria de servo 

Servo motoservo; //se define la variable del motor
int pinservo = 4; // variable pin del servo
int pininiciar = 8; // variable del pin para eñ boton para inicar el movimiento del servo
int pinresert = 7; // variable del pin para el boton de regresar al angulo inicial
int angulo = 0; // angulo inicial del motor
int angulomaximo = 180; // angulo maximo del motor
int estado1 = 0; // estado del primer boton 
int estado2 = 0; // estado del segundo boton 
int ledblanco = 39; // los leds que se usan para indicar la posicion del motor
int ledverde = 41;
int ledamarillo = 43;
int ledrojo = 47;

void setup() {
  motoservo.attach(pinservo); // definimos que el motor va a estar en el pin
  pinMode(pininiciar, INPUT); // el pininiciar sera de entrada
  pinMode(pinresert, INPUT); // igual de entrada
  motoservo.write(angulo); // el motor al inicar se pondra a el angulp 
  pinMode(ledblanco, OUTPUT); // se ponen los leds como salida en los pines aclarados
  pinMode(ledverde, OUTPUT);
  pinMode(ledamarillo, OUTPUT);
  pinMode(ledrojo, OUTPUT);
}

void loop() {
  estado1 = digitalRead(pininiciar); // se le el estado de los botones 
  estado2 = digitalRead(pinresert);
  if(estado1 == HIGH){ // esta funcion hace que cuando se apriete el primer boton el motor aumente de angulo
    angulo++;
    if(angulo >= angulomaximo){
      angulo = angulomaximo;
    }
  }
  if(estado2 == HIGH){ // Esta funcion hace que cuando se apriete el segundo boton el motor disminuya de angulo
    angulo--;
    if(angulo <=0){
      angulo = 0;
    }
  }
  motoservo.write(angulo); // Se escribe en el motor el angulo
  if(angulo == 0){ // si el angulo es 0 se prende un led pero se apagan los demas
    digitalWrite(ledblanco, HIGH);
    digitalWrite(ledverde, LOW);
    digitalWrite(ledamarillo, LOW);
    digitalWrite(ledrojo, LOW);
  }
  if (angulo > 0 && angulo < 90) { // si el angulo es mayor a 0 y menor a 90 se prende otro led pero se apagan los demas
    digitalWrite(ledblanco, LOW);
    digitalWrite(ledverde, HIGH);
    digitalWrite(ledamarillo, LOW);
    digitalWrite(ledrojo, LOW);
    
  }
  if (angulo > 90 &&  angulo < 180) { // si el angulo es mayor a 90 pero menor a 180 se otro led pero se apagan los demas
    digitalWrite(ledblanco, LOW);
    digitalWrite(ledverde, LOW);
    digitalWrite(ledamarillo, HIGH);
    digitalWrite(ledrojo, LOW);
    
  }
  if (angulo == 180) { // si el angulo es 180 se prende otro led pero se apagan los demas
    digitalWrite(ledblanco, LOW);
    digitalWrite(ledverde, LOW);
    digitalWrite(ledamarillo, LOW);
    digitalWrite(ledrojo, HIGH);
  }
  delay(10);
}
