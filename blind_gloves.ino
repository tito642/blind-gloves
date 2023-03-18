// by t2 elattar
#define pinopresenca 7
#define buzzer  8

const int trigPin = 7;
const int echoPin = 5;

float distanciamedida=0;
byte presenca=0;
void setup() {
  Serial.begin(9600);
  pinMode(pinopresenca, INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop()
{

  distanciamedida=ultrasonic.Ranging(CM);
  Serial.println(distanciamedida);
  Serial.println("cm");
  presenca=digitalRead(pinopresenca);
  if(distanciamedida<=150&&presenca==HIGH)
  {
    tone(buzzer, 800,500);
    Serial.println("distancia menor que 1.5 metros");
  } 
  else {
    digitalWrite(buzzer, LOW);
    Serial.println("distancia segura");
    }
  delay(500);
}
