//08-09-2017 FINALIZADO COM SUCESSO
//Michael Moraes Sabino
//estuartyy@gmail.com

// Definição dos pinos para a utilização da ponte H ou Driver L298N.
//MOTOR A
const int motorA1  = 9;   // Motor lado esquerdo
const int motorA2  = 3;   // Motor lado esquerdo

//MOTOR B
const int motorB1  = 11;  // Motor lado direito
const int motorB2  = 10;  // Motor lado direito

const int buzzer = 12 ;   // Pino 13 como pino do Buzzer ou (buzina).
const int BTState = 2; // Pino 2 como o pino de comunicação do Bluetooth.

int i = 0; // VariáveL
int j = 0;  // VariáveL
int state_rec; //variavel para armazenamento de dados.
int vSpeed = 200;   // Define velocidade padrão 0 a 255.
char state; //state recebe os caracteres do celular

void setup() 
{
  // Inicializa as portas como entrada e saída.
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(BTState, INPUT);

  Serial.begin(9600); // Inicializa o Monitor Serial 9600.
}

void loop() 
{
  // Para o carrinho quando a conexão com Bluetooth é desconectada.
  if (digitalRead(BTState) == LOW) 
  {
    state_rec = 'S';
  }

  // Salva os valores da variável 'state'
  if (Serial.available() > 0) 
  {
    state_rec = Serial.read();
    state = state_rec;
    //Serial.println(vSpeed); //mostra na serial a velocidade
  }

  // Altera a velocidade de acordo com valores especificados.
  if (state == '0')
  {
    vSpeed = 0;
  }
  else if (state == '4') 
  {
    vSpeed = 100;
  }
  else if (state == '6') {
    vSpeed = 155;
  }
  else if (state == '7') 
  {
    vSpeed = 180;
  }
  else if (state == '8') 
  {
    vSpeed = 200;
  }
  else if (state == '9') 
  {
    vSpeed = 230;
  }
  else if (state == 'q') 
  {
    vSpeed = 255;
  }

  if (state != 'S') 
  {
    Serial.print(state);
  }
  
   if (state == 'F') 
   {   // Se o estado recebido for igual a 'F', o carro se movimenta para frente.
    analogWrite(motorA1, 0);
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, vSpeed);
    analogWrite(motorB2, 0);
  }

    else if (state == 'I')
    {  // Se o estado recebido for igual a 'G', o carro se movimenta para Frente Esquerda.
    analogWrite(motorA1, vSpeed); 
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 100);    
    analogWrite(motorB2, 0);
  }

    else if (state == 'G') 
    {   // Se o estado recebido for igual a 'I', o carro se movimenta para Frente Direita.
    analogWrite(motorA1, 100); 
    analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed);      
    analogWrite(motorB2, 0);
  }

  else if (state == 'R')
  { // Se o estado recebido for igual a 'R', o carro se movimenta para direita.       
    analogWrite(motorA1, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
    analogWrite(motorA2, vSpeed);
  }

   else if (state == 'H') 
   {  // Se o estado recebido for igual a 'H', o carro se movimenta para Trás Esquerda.
    analogWrite(motorA1, 0);   
    analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, 0); 
    analogWrite(motorB2, 100);
  }
  
  else if (state == 'J') 
  {  // Se o estado recebido for igual a 'J', o carro se movimenta para Trás Direita.
    analogWrite(motorA1, 0);   
    analogWrite(motorA2, 100);
    analogWrite(motorB1, 0);   
    analogWrite(motorB2, vSpeed);
  }

  else if (state == 'L')
  {  // Se o estado recebido for igual a 'L', o carro se movimenta para esquerda.
    analogWrite(motorB1, vSpeed);
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB2, 0);
  }

  else if (state == 'B') 
  {    // Se o estado recebido for igual a 'B', o carro se movimenta para trás.
    analogWrite(motorA1, vSpeed);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, vSpeed);
  }
  else if (state == 'S') 
  {   // Se o estado recebido for igual a 'S', o carro permanece parado.
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
  }

  else if (state == 'V')
  { // Se o estado recebido for iguala 'V', aciona a buzina.
    if (j == 0)
    {
      tone(buzzer, 1000);
      j = 1;
    }
    else if (j == 1) 
    {
      noTone(buzzer);
      j = 0;
    }
    state = 'n';
  }
}
