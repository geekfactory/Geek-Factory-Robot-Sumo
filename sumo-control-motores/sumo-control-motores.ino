#include "GBOT.h"

void setup() {
  // iniciar puerto y mostrar mensaje
  Serial.begin(115200);
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("                 ROBOT SUMO - MOTORES               "));
  Serial.println(F("              https://www.geekfactory.mx            "));
  Serial.println(F("----------------------------------------------------"));

  // configurar los pines de control de motores como salidas
  // pines de control del motor dercho
  pinMode(PIN_MOTOR_DER_1, OUTPUT);
  pinMode(PIN_MOTOR_DER_2, OUTPUT);
  pinMode(PIN_MOTOR_DER_PWM, OUTPUT);
  // pines de control del motor izquierdo
  pinMode(PIN_MOTOR_IZQ_1, OUTPUT);
  pinMode(PIN_MOTOR_IZQ_2, OUTPUT);
  pinMode(PIN_MOTOR_IZQ_PWM, OUTPUT);

  // configurar los pines de dirección para avanzar
  // motor derecho
  digitalWrite(PIN_MOTOR_DER_1, HIGH);
  digitalWrite(PIN_MOTOR_DER_2, LOW);
  // motor izquierdo
  digitalWrite(PIN_MOTOR_IZQ_1, HIGH);
  digitalWrite(PIN_MOTOR_IZQ_2, LOW);
}

void loop() {

  for (int i = 0; i <= 255; i++) {
    delay(100);
    analogWrite(PIN_MOTOR_DER_PWM, i);
    analogWrite(PIN_MOTOR_IZQ_PWM, i);
    Serial.println(i);
  }

  delay(5000);

  for (int i = 255; i >= 0; i--) {
    delay(100);
    analogWrite(PIN_MOTOR_DER_PWM, i);
    analogWrite(PIN_MOTOR_IZQ_PWM, i);
    Serial.println(i);
  }

  delay(5000);
}
