//Definição dos pinos para os botões e leds
#define pinoBotaoBranco 3
#define pinoLedBranco 13
#define pinoBotaoPreto 2
#define pinoLedPreto 12

//Variáveis para guardar o tempo
unsigned long tempoPretas = 0;
unsigned long tempoBrancas = 0;

//Variáveis para definir a vez
bool vezPretas = false;
bool vezBrancas = false;

void setup() {
  //Setup - brancas
  pinMode(pinoLedBranco, OUTPUT);
  pinMode(pinoBotaoBranco, INPUT_PULLUP);
  digitalWrite(pinoLedBranco, LOW);

  //Setup - pretas
  pinMode(pinoLedPreto, OUTPUT);
  pinMode(pinoBotaoPreto, INPUT_PULLUP);
  digitalWrite(pinoLedPreto, LOW);

  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(pinoBotaoBranco), turnLEDOn, RISING);
  attachInterrupt(digitalPinToInterrupt(pinoBotaoPreto), turnLEDOff, RISING);
}

void loop() {
  if (vezPretas) {
    // Lógica para a vez das peças pretas
    digitalWrite(pinoLedBranco, LOW);
    digitalWrite(pinoLedPreto, HIGH);

    // Lógica de contagem de tempo das peças pretas
    unsigned long tempoAtual = millis() - tempoPretas;
    unsigned long segundosDecorridos = tempoAtual / 1000;
    unsigned long minutos = 2 - segundosDecorridos / 60;
    unsigned long segundosRestantes = 59 - (segundosDecorridos % 60);

    // Verifica se passou 1 segundo desde a última atualização do timer
    static unsigned long tempoAnteriorPretas = 0;
    if (segundosRestantes != tempoAnteriorPretas) {
      tempoAnteriorPretas = segundosRestantes;

      // Imprime o tempo das peças pretas no monitor serial
      Serial.print("Brancas ");
      if (minutos < 10) {
        Serial.print("0");
      }
      Serial.print(minutos);
      Serial.print(":");
      if (segundosRestantes < 10) {
        Serial.print("0");
      }
      Serial.print(segundosRestantes);
      Serial.print(" VS ");

      // Imprime o tempo das peças brancas no monitor serial
      Serial.print("Pretas ");
      if (minutos < 10) {
        Serial.print("0");
      }
      Serial.print(minutos);
      Serial.print(":");
      if (segundosRestantes < 10) {
        Serial.print("0");
      }
      Serial.println(segundosRestantes);
    }
  }

  if (vezBrancas) {
    // Lógica para a vez das peças brancas
    digitalWrite(pinoLedBranco, HIGH);
    digitalWrite(pinoLedPreto, LOW);

    // Lógica de contagem de tempo das peças brancas
    unsigned long tempoAtual = millis() - tempoBrancas;
    unsigned long segundosDecorridos = tempoAtual / 1000;
    unsigned long minutos = 2 - segundosDecorridos / 60;
    unsigned long segundosRestantes = 59 - (segundosDecorridos % 60);

    // Verifica se passou 1 segundo desde a última atualização do timer
    static unsigned long tempoAnteriorBrancas = 0;
    if (segundosRestantes != tempoAnteriorBrancas) {
      tempoAnteriorBrancas = segundosRestantes;

      // Imprime o tempo das peças brancas no monitor serial
      Serial.print("Brancas ");
      if (minutos < 10) {
        Serial.print("0");
      }
      Serial.print(minutos);
      Serial.print(":");
      if (segundosRestantes < 10) {
        Serial.print("0");
      }
      Serial.print(segundosRestantes);
      Serial.print(" VS ");

      // Imprime o tempo das peças pretas no monitor serial
      Serial.print("Pretas ");
      if (minutos < 10) {
        Serial.print("0");
      }
      Serial.print(minutos);
      Serial.print(":");
      if (segundosRestantes < 10) {
        Serial.print("0");
      }
      Serial.println(segundosRestantes);
    }
  }
}

void turnLEDOn() { //Pretas
  Serial.println("Vez do Jogador de Pretas"); // Mensagem de aviso
  vezPretas = true;
  vezBrancas = false;
  tempoPretas = millis(); // Inicia a contagem de tempo
}

void turnLEDOff() { //Brancas
  Serial.println("Vez do Jogador de Brancas"); // Mensagem de aviso
  vezPretas = false;
  vezBrancas = true;
  tempoBrancas = millis(); // Inicia a contagem de tempo
}