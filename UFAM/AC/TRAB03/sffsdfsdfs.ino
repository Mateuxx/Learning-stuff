unsigned long ultimoLance = 0;

volatile boolean ledOn1 = false;
volatile boolean ledOn2 = true;

const int pinoBotao1 = 2;
const int pinoLed1 = 13;

const int pinoBotao2 = 3;
const int pinoLed2 = 12;

unsigned long tempoBrancas = 5000; // 3 minutos em milissegundos
unsigned long tempoPretas = 5000; // 3 minutos em milissegundos

void setup() {
  Serial.begin(9600);

  pinMode(pinoBotao1, INPUT_PULLUP);
  pinMode(pinoLed1, OUTPUT);
  
  pinMode(pinoBotao2, INPUT_PULLUP);
  pinMode(pinoLed2, OUTPUT);
  
  digitalWrite(pinoLed1, LOW);
  digitalWrite(pinoLed2, LOW);

  attachInterrupt(digitalPinToInterrupt(pinoBotao1), buttonPressed1, RISING);
  attachInterrupt(digitalPinToInterrupt(pinoBotao2), buttonPressed2, RISING);
}

void loop() {
  if (ledOn1) {
    digitalWrite(pinoLed1, LOW);
    digitalWrite(pinoLed2, HIGH);
    unsigned long agora = millis();
    if ((agora - ultimoLance) >= 1000) { // Acréscimo de 1 segundo
      tempoBrancas -= (agora - ultimoLance);
      ultimoLance = agora;
      if(tempoBrancas <= 0){
        Serial.println("O tempo das Brancas acabou. As Pretas ganharam!");
        while(true){}
      }
      else
        imprimirEstadoJogadores();
    }
  }
  if (ledOn2) {
    digitalWrite(pinoLed1, HIGH);
    digitalWrite(pinoLed2, LOW);
    unsigned long agora = millis();
    if ((agora - ultimoLance) >= 1000) { // Acréscimo de 1 segundo
      tempoPretas -= (agora - ultimoLance);
      ultimoLance = agora;
      if(tempoPretas <= 0){
        Serial.println("O tempo das Pretas acabou. As Brancas ganharam!");
        while(true){}
      }
      else
        imprimirEstadoJogadores();
    }
  }
}

void buttonPressed1() {
  ledOn1 = !ledOn1;
  ledOn2 = false;
  tempoPretas += 3000; //3 segundos adicioanis
}

void buttonPressed2() {
  ledOn1 = false;
  ledOn2 = !ledOn2;
  tempoBrancas += 3000;//3 segundos adicionais
}

void imprimirEstadoJogadores() { //função para imprimir o contador
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
