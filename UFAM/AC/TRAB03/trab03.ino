// Configurações das peças Brancas
const int pinoBotaoLigaBrancas = 2;
const int pinoLedBrancas = 12;
unsigned long minutosBrancas = 180000;
volatile boolean brancasMode = false;
unsigned long tempoRestanteAcrescimoBrancas = 0; // Variável para controlar o acréscimo de tempo das Brancas

// Configurações das peças Pretas
const int pinoBotaoDesliga = 3;
const int pinoLedPretas = 13;
unsigned long minutosPretas = 180000;
volatile boolean pretasMode = false;
unsigned long tempoRestanteAcrescimoPretas = 0; // Variável para controlar o acréscimo de tempo das Pretas

// apenas declarações de variáveis
unsigned long tempoInicio = 0;
unsigned long tempoRestanteBrancas = 0;
unsigned long tempoRestantePretas = 0;
unsigned long tempoAnteriorBrancas = 0;
unsigned long tempoAnteriorPretas = 0;

bool primeiraVez = true;

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
  tempoInicio = millis(); // Inicia o tempo no momento atual
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

      // Verifica se o tempo das peças Brancas acabou
      if (tempoRestanteBrancas <= 0) {
        Serial.println("O tempo das Brancas acabou. As Pretas ganharam!");
        brancasMode = false;
        pretasMode = false;
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

      // Verifica se o tempo das peças Pretas acabou
      if (tempoRestantePretas <= 0) {
        Serial.println("O tempo das Pretas acabou. As Brancas ganharam!");
        brancasMode = false;
        pretasMode = false;
      }
    }
  }
}

void turnLEDOn() { // Pretas
  if (!pretasMode) {

    pretasMode = true;
    brancasMode = false;

    unsigned long tempoAtual = millis();
    unsigned long tempoPassado = tempoAtual - tempoInicio;

    tempoInicio = tempoAtual; // Atualiza o tempo inicial com o tempo atual
    tempoRestantePretas -= tempoPassado; // Subtrai o tempo passado do tempo restante das Pretas

    // Acrescenta 3 segundos ao tempo restante das Pretas
    tempoRestantePretas += 3000;

    primeiraVez = false;
  }
}

void turnLEDOff() { // Brancas
  if (!brancasMode) {
   

    brancasMode = true;
    pretasMode = false;

    unsigned long tempoAtual = millis();
    unsigned long tempoPassado = tempoAtual - tempoInicio;

    tempoInicio = tempoAtual; // Atualiza o tempo inicial com o tempo atual
    tempoRestanteBrancas -= tempoPassado; // Subtrai o tempo passado do tempo restante das Brancas

    // Acrescenta 3 segundos ao tempo restante das Brancas
    tempoRestanteBrancas += 3000;

    primeiraVez = false;
  }
}
