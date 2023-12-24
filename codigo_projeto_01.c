const int pinoLM35 = A0;     // Pino analógico para o LM35
const int pinoMotor = 9;      // Pino digital para o motor do ventilador
const int pinoLEDVerde = 8;   // Pino digital para o LED verde
const int pinoLEDVermelho = 7;// Pino digital para o LED vermelho
const int pinoBuzina = 6;     // Pino digital para a buzina

void setup() {
  Serial.begin(9600);
  pinMode(pinoMotor, OUTPUT);
  pinMode(pinoLEDVerde, OUTPUT);
  pinMode(pinoLEDVermelho, OUTPUT);
  pinMode(pinoBuzina, OUTPUT);
}

void loop() {
  float temperatura = lerTemperatura();

  // Verificar a temperatura
  if (temperatura >= 30) {
    digitalWrite(pinoMotor, HIGH);   // Ligar o motor do ventilador
    digitalWrite(pinoLEDVerde, HIGH); // Ligar o LED verde
  } else {
    digitalWrite(pinoMotor, LOW);    // Desligar o motor do ventilador
    digitalWrite(pinoLEDVerde, LOW);  // Desligar o LED verde
  }

  // Verificar emergência
  if (temperatura >= 50) {
    digitalWrite(pinoLEDVermelho, HIGH); // Ligar o LED vermelho
    acionarBuzina();  // Acionar a buzina
  } else {
    digitalWrite(pinoLEDVermelho, LOW);  // Desligar o LED vermelho
  }

  delay(500); // Aguardar meio segundo antes de fazer a próxima leitura
}

float lerTemperatura() {
  int valorSensor = analogRead(pinoLM35);
  float tensao = (valorSensor / 1024.0) * 5.0; // Converter leitura para tensão
  float temperaturaCelsius = (tensao - 0.5) * 100.0; // Calcular temperatura em graus Celsius
  return temperaturaCelsius;
}

void acionarBuzina() {
  digitalWrite(pinoBuzina, HIGH);  // Ligar a buzina
  delay(1000);  // Manter a buzina ligada por 1 segundo
  digitalWrite(pinoBuzina, LOW);   // Desligar a buzina
}
