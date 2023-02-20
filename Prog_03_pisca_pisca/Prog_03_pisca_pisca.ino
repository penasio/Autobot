#define motor 2
int tempo=650;
void setup()
{
  pinMode(motor,OUTPUT);
 
}

void loop()
{
   digitalWrite(motor,HIGH);
   delay(tempo);
  digitalWrite(motor,LOW);
   delay(tempo);
  
}
