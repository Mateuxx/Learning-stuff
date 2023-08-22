// Configurações das peças Brancas
const int pinoBotaoLigaBrancas = 2;
const int pinoLedBrancas = 12;
unsigned long minutosBrancas = 32400;
volatile boolean brancasMode = false;

// Configurações das peças Pretas
const int pinoBotaoDesliga = 3;
const int pinoLedPretas = 13;
unsigned long minutosPretas = 32400;
volatile boolean pretasMode = false;

// apenas declarações de variaveis
unsigned long tempoInicio = 0; 
unsigned long tempoRestanteBrancas =0 ;
unsigned long tempoRestantePretas = 0; 
unsigned long tempoAnteriorBrancas = 0;
unsigned long tempoAnteriorPretas = 0;

void setup() {
  // Configuração dos LEDs
  pinMode(pinoLedBrancas, OUTPUT);
  pinMode(pinoLedPretas, OUTPUT);

  // Configuração dos botões como INPUT_PULLUP
  pinMode(pinoBotaoLigaBrancas, INPUT_PULLUP);
  pinMode(pinoBotaoDesliga, INPUT_PULLUP);

  // Definição inicial dos LEDs (desligados)
  digitalWrite(pinoLedBrancas, LOW);
  digitalWrite(pinoLedPretas, LOW);

  // Inicializa o monitor serial
  Serial.begin(9600);

  // Configura as interrupções para os botões
  attachInterrupt(digitalPinToInterrupt(pinoBotaoLigaBrancas), turnLEDOn, RISING);
  attachInterrupt(digitalPinToInterrupt(pinoBotaoDesliga), turnLEDOff, RISING);

  // Aguarda a conexão com o monitor serial
  while (!Serial) {
    ;
  }
  
  // Inicia os temporizadores com 3 minutos
  tempoRestanteBrancas = minutosBrancas;
  tempoRestantePretas = minutosPretas;
}

void loop() {
  if (pretasMode || brancasMode) {
    // Ligar ou desligar os LEDs
    digitalWrite(pinoLedBrancas, brancasMode);
    digitalWrite(pinoLedPretas, pretasMode);

    unsigned long tempoAtual = millis();
    unsigned long tempoPassado = tempoAtual - tempoInicio;

    if (brancasMode) {
      tempoRestanteBrancas -= tempoPassado;
      tempoInicio = tempoAtual;

      unsigned long minutosBrancasRestantes = tempoRestanteBrancas / 60000;
      unsigned long segundosBrancasRestantes = (tempoRestanteBrancas / 1000) % 60;
      unsigned long minutosPretasRestantes = tempoRestantePretas / 60000;
      unsigned long segundosPretasRestantes = (tempoRestantePretas / 1000) % 60;

      if (segundosBrancasRestantes != tempoAnteriorBrancas) {
        tempoAnteriorBrancas = segundosBrancasRestantes;

        Serial.print("Brancas ");
        if (minutosBrancasRestantes < 10) {
          Serial.print("0");
        }
        Serial.print(minutosBrancasRestantes);
        Serial.print(":");
        if (segundosBrancasRestantes < 10) {
          Serial.print("0");
        }
        Serial.print(segundosBrancasRestantes);
        Serial.print(" VS ");
        if (minutosPretasRestantes < 10) {
          Serial.print("0");
        }
        Serial.print(minutosPretasRestantes);
        Serial.print(":");
        if (segundosPretasRestantes < 10) {
          Serial.print("0");
        }
        Serial.print(segundosPretasRestantes);
        Serial.println(" Pretas");
      }
    }
    else if (pretasMode) {
      tempoRestantePretas -= tempoPassado;
      tempoInicio = tempoAtual;

      unsigned long minutosBrancasRestantes = tempoRestanteBrancas / 60000;
      unsigned long segundosBrancasRestantes = (tempoRestanteBrancas / 1000) % 60;
      unsigned long minutosPretasRestantes = tempoRestantePretas / 60000;
      unsigned long segundosPretasRestantes = (tempoRestantePretas / 1000) % 60;

      if (segundosPretasRestantes != tempoAnteriorPretas) {
        tempoAnteriorPretas = segundosPretasRestantes;

        Serial.print("Brancas ");
        if (minutosBrancasRestantes < 10) {
          Serial.print("0");
        }
        Serial.print(minutosBrancasRestantes);
        Serial.print(":");
        if (segundosBrancasRestantes < 10) {
          Serial.print("0");
        }
        Serial.print(segundosBrancasRestantes);
        Serial.print(" VS ");
        if (minutosPretasRestantes < 10) {
          Serial.print("0");
        }
        Serial.print(minutosPretasRestantes);
        Serial.print(":");
        if (segundosPretasRestantes < 10) {
          Serial.print("0");
        }
        Serial.print(segundosPretasRestantes);
        Serial.println(" Pretas");
      }
    }
  }
}

void turnLEDOn() { // Pretas
  if (!pretasMode) {
    Serial.println("Vez do Jogador de PRETAS"); // Mensagem de aviso
    
    pretasMode = true;
    brancasMode = false;

    unsigned long tempoAtual = millis();
    unsigned long tempoPassado = tempoAtual - tempoInicio;

    tempoInicio = tempoAtual; // Atualiza o tempo inicial com o tempo atual
    tempoRestantePretas -= tempoPassado; // Subtrai o tempo passado do tempo restante para as peças Pretas
    if (tempoRestantePretas <= 0) {
      tempoRestantePretas = minutosPretas * 60000; // Reinicia o tempo restante para as peças Pretas
    }
  }
}

void turnLEDOff() { // Brancas
  if (!brancasMode) {
    Serial.println("Vez do Jogador Brancas"); // Mensagem de aviso
    
    brancasMode = true; // Mudança de estado do LED das peças Brancas
    pretasMode = false; // Mudança de estado do LED das peças Pretas
    
    unsigned long tempoAtual = millis();
    unsigned long tempoPassado = tempoAtual - tempoInicio;

    tempoInicio = tempoAtual; // Atualiza o tempo inicial com o tempo atual
    tempoRestanteBrancas -= tempoPassado; // Subtrai o tempo passado do tempo restante para as peças Brancas
    if (tempoRestanteBrancas <= 0) {
      tempoRestanteBrancas = minutosBrancas * 60000; // Reinicia o tempo restante para as peças Brancas
    }
  }
}
