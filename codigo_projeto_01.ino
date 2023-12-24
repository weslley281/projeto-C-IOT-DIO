  
int PINO_SENSOR = A0;
int PINO_LED_VERDE = 2;
int PINO_LED_VERMELHO = 3;
int PINO_MOTOR = 4;

void setup() {
  Serial.begin(9600);
  pinMode(PINO_SENSOR, INPUT);
  pinMode(PINO_LED_VERDE, OUTPUT);
  pinMode(PINO_LED_VERMELHO, OUTPUT);
  pinMode(PINO_MOTOR, OUTPUT);
}

void loop() {
  int valorSensor = analogRead(PINO_SENSOR);
  float tensao = valorSensor * (5.0 / 1023.0);
  float temperatura = (tensao - 0.5) * 100;

  if (temperatura < 28) {
    digitalWrite(PINO_LED_VERDE, HIGH);
    digitalWrite(PINO_LED_VERMELHO, LOW);
    digitalWrite(PINO_MOTOR, LOW);
  } else {
    digitalWrite(PINO_LED_VERDE, LOW);
    digitalWrite(PINO_LED_VERMELHO, HIGH);
    digitalWrite(PINO_MOTOR, HIGH);
  }
}
