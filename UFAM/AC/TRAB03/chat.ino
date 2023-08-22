// Pinos dos botões e LEDs
const int botaoBrancasPin = 2;
const int botaoPretasPin = 3;
const int ledBrancasPin = 4;
const int ledPretasPin = 5;

// Variáveis para controle de tempo
unsigned long tempoBrancas = 180000; // 3 minutos em milissegundos
unsigned long tempoPretas = 180000; // 3 minutos em milissegundos
unsigned long ultimoLance = 0;
boolean turnoBrancas = false;
boolean turnoPretas = false;

void setup() {
  // Configuração dos pinos dos botões e LEDs
  pinMode(botaoBrancasPin, INPUT_PULLUP);
  pinMode(botaoPretasPin, INPUT_PULLUP);
  pinMode(ledBrancasPin, OUTPUT);
  pinMode(ledPretasPin, OUTPUT);

  // Inicia com os LEDs desligados
  digitalWrite(ledBrancasPin, LOW);
  digitalWrite(ledPretasPin, LOW);

  // Ativa as interrupções externas
  attachInterrupt(digitalPinToInterrupt(botaoBrancasPin), botaoBrancasPressionado, FALLING);
  attachInterrupt(digitalPinToInterrupt(botaoPretasPin), botaoPretasPressionado, FALLING);

  // Imprime o estado inicial dos jogadores
  imprimirEstadoJogadores();
}

void loop() {
  // Verifica se algum jogador excedeu o tempo
  if (tempoBrancas <= 0) {
    imprimirResultadoJogo("Brancas", "Pretas");
    while (true) {} // Fica em loop infinito para interromper o jogo
  }
  if (tempoPretas <= 0) {
    imprimirResultadoJogo("Pretas", "Brancas");
    while (true) {} // Fica em loop infinito para interromper o jogo
  }

  // Verifica se é necessário atualizar o tempo
  unsigned long agora = millis();
  if ((agora - ultimoLance) >= 3000) { // Acréscimo de 3 segundos por lance
    if (turnoBrancas) {
      tempoBrancas -= (agora - ultimoLance);
      turnoBrancas = false;
      turnoPretas = true;
      ultimoLance = agora;
    } else if (turnoPretas) {
      tempoPretas -= (agora - ultimoLance);
      turnoBrancas = true;
      turnoPretas = false;
      ultimoLance = agora;
    }
    imprimirEstadoJogadores();
  }
}

// Função chamada quando o botão das Brancas é pressionado
void botaoBrancasPressionado() {
  if (!turnoBrancas && !turnoPretas) {
    turnoBrancas = true;
    ultimoLance = millis();
    digitalWrite(ledBrancasPin, HIGH);
  }
}

// Função chamada quando o botão das Pretas é pressionado
void botaoPretasPressionado() {
  if (turnoBrancas && !turnoPretas) {
    tempoBrancas += 3000; // Acréscimo
    turnoPretas = true;
    ultimoLance = millis();
    digitalWrite(ledBrancasPin, LOW);
    digitalWrite(ledPretasPin, HIGH);
  }
}

// Função para imprimir o estado dos jogadores
void imprimirEstadoJogadores() {
  int minutosBrancas = tempoBrancas / 60000;
  int segundosBrancas = (tempoBrancas % 60000) / 1000;
  int minutosPretas = tempoPretas / 60000;
  int segundosPretas = (tempoPretas % 60000) / 1000;

  Serial.print("Brancas ");
  if (minutosBrancas < 10) {
    Serial.print("0");
  }
  Serial.print(minutosBrancas);
  Serial.print(":");
  if (segundosBrancas < 10) {
    Serial.print("0");
  }
  Serial.print(segundosBrancas);

  Serial.print(" VS ");

  if (minutosPretas < 10) {
    Serial.print("0");
  }
  Serial.print(minutosPretas);
  Serial.print(":");
  if (segundosPretas < 10) {
    Serial.print("0");
  }
  Serial.print(segundosPretas);

  Serial.println(" Pretas");
}

// Função para imprimir o resultado do jogo
void imprimirResultadoJogo(String jogadorSemTempo, String jogadorVencedor) {
  Serial.print("O tempo das ");
  Serial.print(jogadorSemTempo);
  Serial.print(" acabou. As ");
  Serial.print(jogadorVencedor);
  Serial.println(" ganharam!");
}
