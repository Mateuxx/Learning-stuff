#define pinoBotaoLiga 2
#define pinoBotaoDesliga 3
#define pinoLed1 13
#define pinoLed2 12

unsigned long tempoInicio = 0;
unsigned long tempoTotal = 0;
bool ledLigado = false;

void setup() {
  // Configuração dos LEDs
  pinMode(pinoLed1, OUTPUT);
  pinMode(pinoLed2, OUTPUT);

  // Configuração dos botões como INPUT_PULLUP
  pinMode(pinoBotaoLiga, INPUT_PULLUP);
  pinMode(pinoBotaoDesliga, INPUT_PULLUP);

  // Definição inicial dos LEDs (desligados)
  digitalWrite(pinoLed1, LOW);
  digitalWrite(pinoLed2, LOW);

  // Inicializa o monitor serial
  Serial.begin(9600);

  // Configura as interrupções para os botões
  attachInterrupt(digitalPinToInterrupt(pinoBotaoLiga), turnLEDOn, FALLING);
  attachInterrupt(digitalPinToInterrupt(pinoBotaoDesliga), turnLEDOff, FALLING);

  // Aguarda a conexão com o monitor serial
  while (!Serial) {
    ;
  }
}

void loop() {
  
  if (ledLigado) {
    unsigned long tempoAtual = millis() - tempoInicio;
    unsigned long tempoTotal = (millis() - tempoInicio) / 1000;
    unsigned long segundos = tempoAtual / 1000;
    unsigned long minutos = segundos / 60;
    segundos %= 60;

    Serial.print("Tempo: ");
    if (minutos < 10) {
      Serial.print("0");
    }
    Serial.print(minutos);
    Serial.print(":");
    if (segundos < 10) {
      Serial.print("0");
    }
    Serial.println(segundos);
  }
  else {
    Serial.print("Tempo Total: ");
    Serial.println(tempoTotal);
  }

}

void turnLEDOn() {
  // Função chamada quando o botão de ligar é pressionado
  digitalWrite(pinoLed1, HIGH);  // Acende o LED
  ledLigado = true;
  tempoInicio = millis(); // Inicia a contagem de tempo
}

void turnLEDOff() {
  // Função chamada quando o botão de desligar é solto
  ledLigado = false;
  if (ledLigado == false) {
  digitalWrite(pinoLed1, LOW);  // Desliga o LED
  //ledLigado = false;
  
    // Calcula o tempo total em segundos
  //tempoTotal = (millis() - tempoInicio) / 1000;
  //Serial.print("\nSempo total (segundos): ");
  //Serial.print(tempoTotal);
  }


}
