#define PIR_Sensor_Mov 2 //Usando o pin2 para receber o sinal de movimento
int tempo_Sensor_Mov=10000; 

//Leitura de distância com o sensor HC-SR04
#include <Ultrasonic.h>
Ultrasonic ultrassom(8,7); // define o nome do sensor(ultrassom)
//e onde esta ligado o trig(8) e o echo(7) respectivamente
int distancia;
//#define motor 2
//int tempo=650;
void setup()
{
  pinMode(PIR_Sensor_Mov,INPUT);
  Serial.begin(9600);
  //pinMode(motor,OUTPUT);
 
}

void loop()
{
  if(digitalRead(PIR_Sensor_Mov))//Se detecta algum movimento...
    {
      //Serial.println("Tem alguém perto");
      
      distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
                                     // centímetros(CM) ou polegadas(INC)
       Serial.print(distancia); //imprime o valor da variável distancia
       Serial.println("cm");
       if(distancia < 15)
          Serial.print("Perto!");
        else
          Serial.print("OK!");
          delay(tempo_Sensor_Mov);
    }
  else
  {
    Serial.println("Esperando");
    delay(200);
  }  
 
 //delay(2000);
  //delay(tempo_Sensor_Mov);


  
 //digitalWrite(motor,HIGH);
 //delay(tempo);
 //digitalWrite(motor,LOW);
 //delay(tempo);
  
}
