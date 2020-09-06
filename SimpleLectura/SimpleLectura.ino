/****************************************************************************************
 Simple Lectura

  Se obtienen mediciones de intensidad usando un sensor SCT013 (requiere circuito de acondicionamiento para el sensor)
 
 Conexiones:
  -----------------------------
  Señal(Acondicionada) -> A0 (Arduino)
  -----------------------------    
  *El sensor no se puede conectar directamente al Arduino, necesita un circuito de acondicionamiento
  *Puede cambiar la conexión a otro pin analógico del arduino modificando la variable que define el pin

 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir)
 
 Última modificación el 06/09/2020
 
 Más información en:
   -https://naylampmechatronics.com/blog/51_tutorial-sensor-de-corriente-ac-no-invasivo-s.html
   -https://github.com/naylampmechatronics/Ejemplos_SCT013
   
**************************************************************************************************/
int pin_SCT = A0; //definición del pin del sensor
float Sensibilidad=30.0; //sensibilidad en V/A (para nuestro sensor:30A/1V)

void setup() {
  Serial.begin(115200);
  analogReference(INTERNAL);
}

void loop() {  
  int sensorValue = analogRead(pin_SCT); //Lectura analógica
  float voltajeSensor = analogRead(A0) * (1.1 / 1023.0); //voltaje del sensor
  float corriente=voltajeSensor*Sensibilidad; //corriente=VoltajeSensor*(30A/1V)
  Serial.println(corriente,3);//enviamos por el puerto serie
}
