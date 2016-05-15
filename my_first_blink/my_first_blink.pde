int ledpin = 13;

int limite_estagios = 2;

int tempo_atraso_aceso = 0;
int tempo_atraso_apagado = 0;

int qtde_blinks = 20;


int estagio = 0;

void setup() {
  pinMode(ledpin, OUTPUT); 
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
              tempo_atraso_aceso = 1000;
              tempo_atraso_apagado = 2000;   
              qtde_blinks = 10;                            
            break;             
         case 2:
              tempo_atraso_aceso = 100;
              tempo_atraso_apagado = 100; 
              qtde_blinks = 20;                                         
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
      }

  
  
    if ( estagio >= limite_estagios)
    {
       estagio = 0; 
    }
    else
    {
       estagio++;
    }
  
  
}
