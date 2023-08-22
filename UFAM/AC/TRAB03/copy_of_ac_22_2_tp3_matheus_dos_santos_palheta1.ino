// C++ code
//config brancas
volatile boolean estadoBrancas = false;
const int pinoBotaoBrancas = 3;
const int pinoLedBrancas = 13;
int minutos_brancas = 10;
int segundos_brancas = 0;
volatile boolean brancas = false; //imprime cada tempo so uma vez

//config pretas
volatile boolean estadoPretas = false;
const int pinoBotaoPretas = 2;
const int pinoLedPretas = 12;
int minutos_pretas = 10;
int segundos_pretas = 0;
volatile boolean pretas = false;


int turno = 0; // brancas: 1 e pretas: 2
int timer = 0; // cont do timer 2




volatile boolean fimDeJogo = false;

void setup () {
  //Config leds e botoes
	pinMode(pinoLedBrancas, OUTPUT);
	pinMode(pinoBotaoBrancas, INPUT_PULLUP);
  
  	pinMode(pinoLedPretas, OUTPUT);
	pinMode(pinoBotaoPretas, INPUT_PULLUP);
	
  
  	Serial.begin(9600);
  	Serial.println("CHESS.COM");

  	//Config temporizador  
    cli();
    TCCR2A = 0; // impede interrupcao por comparacao 
    TCNT2 = 0x06; // Inicia o Timer2 em 6
    TCCR2B = ((TCCR2B & B11111000) | B00000110); //prescaler de 256
    TIMSK2 |= 0x01; //Ativa interrupcao por overflow
    sei();
  	
  	//Config Interrupcao externa
  	attachInterrupt(digitalPinToInterrupt(pinoBotaoBrancas), buttonPressedPretas, RISING);
  	attachInterrupt(digitalPinToInterrupt(pinoBotaoPretas), buttonPressedBrancas, RISING);
}

void loop() {
  	if(estadoBrancas) {digitalWrite(pinoLedBrancas, HIGH); digitalWrite(pinoLedPretas, LOW);}
  if(estadoPretas) {digitalWrite(pinoLedPretas, HIGH); digitalWrite(pinoLedBrancas, LOW);}
  
  // VEZ DAS BRANCAS
  	if(digitalRead(pinoLedBrancas) == HIGH && turno == 1 && brancas == true) {
      	//ve se o tempo das brancas acabou
        if(minutos_brancas ==0 && segundos_brancas == 0 && !fimDeJogo) {
       		Serial.println("O tempo das brancas acabou!");
          	Serial.println("Brancas: 00:00"); //o tempo delas acabou         
          	Serial.print("Pretas: ");
          	
          	//printa tempo pretas
          	if(minutos_pretas == 10){  //minutos pretas
              Serial.print(minutos_pretas);
            }else{
              Serial.print("0");
              Serial.print(minutos_pretas);
            }
            Serial.print(":");
          	if(segundos_pretas >= 10){ //segundos pretas
              Serial.println(segundos_pretas);
            }else{
              Serial.print("0");
              Serial.println(segundos_pretas);
            }
          	fimDeJogo = true;
        }
        else {
          	//printar tempo das brancas
          	if(fimDeJogo == false) {
			  if(minutos_brancas == 10){  //minutos brancas
              Serial.print(minutos_brancas);
              }else{
                Serial.print("0");
                Serial.print(minutos_brancas);
              }
              Serial.print(":");
              if(segundos_brancas >= 10){ //segundos brancas
                Serial.println(segundos_brancas);
              }else{
                Serial.print("0");
                Serial.println(segundos_brancas);
              }
            }
          	brancas = !brancas;
        }
    }
  
  
  	// vez das pretas
 	if(digitalRead(pinoLedPretas) == HIGH && turno == 2 && pretas == true) { 
      	// verifica tempo pretas
      	if(minutos_pretas ==0 && segundos_pretas == 0 && !fimDeJogo) {
          	Serial.println("O tempo das pretas acabou!");
          	Serial.print("Brancas: ");
           
          	//printa tempo brancas
          	if(minutos_brancas == 10){  //minutos brancas
              Serial.print(minutos_brancas);
            }else{
              Serial.print("0");
              Serial.print(minutos_brancas);
            }
            Serial.print(":");
          	if(segundos_brancas >= 10){ //segundos brancas
              Serial.println(segundos_brancas);
            }else{
              Serial.print("0");
              Serial.println(segundos_brancas);
            }
          	Serial.print("Pretas: 00:00"); //o tempo delas acabou
          	fimDeJogo = true;
        }
      	else {
          	//Printar tempo das pretas
          	if(fimDeJogo == false) {
              if(minutos_pretas == 10){  //minutos pretas
                Serial.print(minutos_pretas);
              }else{
                Serial.print("0");
                Serial.print(minutos_pretas);
              }
              Serial.print(":");
              if(segundos_pretas >= 10){ //segundos pretas
                Serial.println(segundos_pretas);
              }else{
                Serial.print("0");
                Serial.println(segundos_pretas);
              }
         
              }
          	pretas = !pretas;
        }
  	}
}

// OVERFLOW
ISR(TIMER2_OVF_vect) {
  	timer++;
  	TCNT2 = 0x06; // Para dar 0.004 segundo
    if (timer == 250) { //estouro calculado 
    	timer = 0;
      	brancas = true;
      	pretas = true;
      
      	// TEMPORIZADOR BRANCAS
      	if(digitalRead(pinoLedBrancas) == HIGH && turno == 1 && brancas == true) {
                if(segundos_brancas <= 0) { //passou um minuto
                    minutos_brancas--;
                    segundos_brancas = 59; // n deve ser 60 pq passa de 00 p 59 dnv
                }
                else { //diminui os segundos das brancas
                    segundos_brancas--;
                }
        }   	
      	// TEMPORIZADOR PRETAS
        if(digitalRead(pinoLedPretas) == HIGH && turno == 2 && pretas == true) {  
                if(segundos_pretas <= 0) {//passou um minuto
                    minutos_pretas--;
                    segundos_pretas = 59;
                }
                else {//diminui os segundos das brancas
                    segundos_pretas--;
                }
            }
        }
}
// cliquei no botao das brancas, logo vez das pretas
void buttonPressedBrancas() {
  Serial.println("Vez do Jogador de PRETAS");
  turno = 2;
  estadoPretas = true;
  estadoBrancas = false;
}

// cliquei no botao das pretas, logo vez das brancas
void buttonPressedPretas() {
  Serial.println("Vez do Jogador de BRANCAS");
  turno = 1;
  estadoBrancas = true;
  estadoPretas = false;
}


