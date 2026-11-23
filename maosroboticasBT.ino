
#include <Servo.h>

// Robô PICHULECO

Servo servo1;
Servo servo2;

// Pinos dos servos
int pinoServo1 = 7;
int pinoServo2 = 6;

// Pinos do ultrassônico
int trig = 11;
int echo = 12;

long duracao;
int distancia;

void setup() {

  servo1.attach(pinoServo1);
  servo2.attach(pinoServo2);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);

  servo1.write(0);
  servo2.write(0);
}

void loop() {

  // Medir distância
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duracao = pulseIn(echo, HIGH);

  distancia = duracao * 0.034 / 2;

  Serial.println(distancia);

  // Detectar obstáculo
  if (distancia > 0 && distancia <= 20) {

    servo1.write(90);
    servo2.write(90);

    delay(1000);

    servo1.write(0);
    servo2.write(0);

    delay(500);
  }

  delay(100);
}