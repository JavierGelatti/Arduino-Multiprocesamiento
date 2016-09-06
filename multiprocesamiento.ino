#include "Multiprocesamiento.h"

char registro[10];
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  esperar(20);
  ejecutar(registro[i++] = 'a');
  esperar(15);
  ejecutar(registro[i++] = 'b');
  
  nuevoHilo();
  ejecutar(
    registro[i++] = 'c';
    ejecutar(registro[i++] = '1');
    esperar(2);
    ejecutar(registro[i++] = '2');
  );
  esperar(10);
  ejecutar(registro[i++] = 'd');
  
  nuevoHilo();
  esperar(5);
  ejecutar(registro[i++] = 'e');
  esperar(5);
  ejecutar(registro[i++] = 'f');
  ejecutar(registro[i++] = 'g');

  // Ejecutar
  while(millis() < 45)
    ejecutarHilos();

  // Verificar
  Serial.println("RESULTADOS:");
  Serial.println(registro[0] == 'c');
  Serial.println(registro[1] == '1');
  Serial.println(registro[2] == '2');
  Serial.println(registro[3] == 'e');
  Serial.println(registro[4] == 'f');
  Serial.println(registro[5] == 'g');
  Serial.println(registro[6] == 'd');
  Serial.println(registro[7] == 'a');
  Serial.println(registro[8] == 'b');
}

void loop() {
  // put your main code here, to run repeatedly:

}
