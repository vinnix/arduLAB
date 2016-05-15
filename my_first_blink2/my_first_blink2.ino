int ledpin = 13;
int anapin = 9;

int limite_estagios = 2;

int tempo_atraso_aceso = 0;
int tempo_atraso_apagado = 0;

int qtde_blinks = 20;


int estagio = 0;

int incomingByte = 0;

String inputString = "";
boolean stringComplete = false;

void setup() {
  pinMode(ledpin, OUTPUT); 
  Serial.begin(9600);
  inputString.reserve(200);
  
}


void loop() {
   //  for (int estagio = 0; estagio <= limite_estagios; estagio++) {

           
      switch (estagio)
      {
         case 0:
              tempo_atraso_aceso = 50;
              tempo_atraso_apagado = 100;
              qtde_blinks = 100;              
            break; 
         case 1:
              tempo_atraso_aceso = 100;
              tempo_atraso_apagado = 2000;   
              qtde_blinks = 50;                            
            break;             
         case 2:
              tempo_atraso_aceso = 60;
              tempo_atraso_apagado = 30; 
              qtde_blinks = 50;    
            break;             

         default:
              tempo_atraso_aceso = 1000;
              tempo_atraso_apagado = 1000;
              qtde_blinks = 10;
            break;
            
      }

      for (int i = 0; i <= qtde_blinks; i++)
      {
          digitalWrite(ledpin, HIGH); 
          delay(tempo_atraso_aceso);  
          digitalWrite(ledpin, LOW);
          delay(tempo_atraso_apagado);  
          // checkUSB();
      }

      for (int i = 0; i <= 255; i = i + 10)
      {
         analogWrite(anapin,i);
         delay(500); 
      }
  
      for (int i = 255; i >= 0; i = i - 10)
      {
         analogWrite(anapin,i);
         delay(500); 
      }
      analogWrite(anapin,0);
  
  
  
    if ( estagio >= limite_estagios)
    {
       estagio = 0; 
    }
    else
    {
       estagio++;
    }

    Serial.println("## ################################");
    Serial.print("## PROXIMO ESTAGIO ["); Serial.print(estagio); Serial.println("]");
    Serial.println("## ################################");
    if (stringComplete)
    {
      Serial.println(inputString);
      inputString = "";
      stringComplete = false;
    }

}

/*

mercadpcb 

*/

void checkUSB(){
  
      if (Serial.available() > 0) {
      incomingByte = Serial.read();
     
      Serial.print(estagio);
      Serial.print("] ");
      Serial.println(incomingByte,DEC);
     }
}



void serialEvent(){
    Serial.println("Event...");
    while(Serial.available()){
      char inChar = (char)Serial.read();
      inputString += inChar; 
      if (inChar == '\n'){
        stringComplete = true;
      }
    }
    Serial.println(inputString);
}
