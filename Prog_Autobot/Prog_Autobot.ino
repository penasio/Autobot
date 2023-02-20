#define PIR_Sensor_Mov 2 //Usando o pin2 para receber o sinal de movimento
int tempo_Sensor_Mov=20000; 
int qt_mov;
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
  qt_mov=0;
  //pinMode(motor,OUTPUT);
 
}

void loop()
{
  if(digitalRead(PIR_Sensor_Mov))//Se detecta algum movimento...
    {
      //Serial.println("Tem alguém perto");
       qt_mov=0;
      do{
      distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em
                                     // centímetros(CM) ou polegadas(INC)
                                     
       
       if(distancia > 15)         
        {
          //Serial.print(distancia);
          Serial.print("Movimento para frente\n");
          Serial.print(qt_mov);
        } 
        else
        {
          //Serial.print(distancia);
          //Serial.print("Perto!\n");
          Serial.print("Muda direção\n");
          Serial.print(qt_mov);
          qt_mov++;
        }
      } while (qt_mov<=10); 
     
         // delay(tempo_Sensor_Mov);
    }
  else
  {
    Serial.println("Esperando");
   
  }  
 delay(200);
 


  
 //digitalWrite(motor,HIGH);
 //delay(tempo);
 //digitalWrite(motor,LOW);
 //delay(tempo);
  
}
