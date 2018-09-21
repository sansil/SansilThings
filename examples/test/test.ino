#include "Puerto.h"
#include "SansilThings.h"
sansilThing st;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  (*st["test1"]) << [](int b=A0){
    char buff[10];
    int a = analogRead(A0);
    Serial.print(a);
    sprintf(buff, "jajaj %d",b);
    return buff;
  };

  (*st["test2"]) << [](int b=A0){
    char buff[10];
    int a = analogRead(A2);
    // Serial.println(a);
    sprintf(buff, "%d",b);
    return buff;
  };

  (*st["test3"]) << [](int b=1){
    char buff[10];
    int a = analogRead(A0);
    // Serial.println(a);
    sprintf(buff, "%d",a);
    return buff;
  };

  (*st["test1"]) << medirNuevo;
}

void loop() {
  // put your main code here, to run repeatedly:
  // test.medir();
  // Serial.println(test.getMedida());
  delay(1000);
  // test.p_getMedida = medirNuevo;
  // test.p_getMedida(test.getPuerto());
  st["test1"]->execute(A0);
  st["test2"]->execute(A1);
  Serial.println(st["test1"]->r_valor);
  Serial.println(st["test2"]->r_valor);
  Serial.println(millis());
}

char* medirNuevo (int b){
  char buff[10];
  int a = analogRead(A0);
  // Serial.println(a);
  sprintf(buff, "sansil%d",a);
  return buff;
}
