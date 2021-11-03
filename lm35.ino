/*
 * 
 * Programa para o LM35. 
 * Foi adcionado um resistor de 1kohms entre o ground e o 
 * output para aumentrar a passagem de corrente e estabilizar o sensor.
 * 
 * Programa criado por:
 *                         João Carlos
 *                         03/11/2021 15:27
 * 
*/
#define lm35 A0 //Pino o qual o sensor está conectado
float temp = 0, media = 0;
byte i = 0;
void setup()
{
  Serial.begin(9600);
  analogReference(INTERNAL); // Ativa a referência interna do Arduino ( 1.1V )
  pinMode(lm35, INPUT);
}

void loop()
{
  for ( i = 0; i < 20; i++) {
    temp = analogRead(lm35);
    temp = temp * 1.1 / (1023 * 0.01);
    /*
      Temperatura =  temperatura * 1.1 ( referência analôgica interna) / (10bits * mv por grau)
    */
    media  = media + temp;
    delay(10); // Delay para descarga dos capacitores da entrada analôgica
  }
  Serial.println(media / 20);
  media = 0;
  delay(5 * 60000); // Leitura a cada 5min ( A temperatura ambiente não muda tão rápido)
}
