/****************************************************************************************
 Irms

  Se obtiene la corriente IRMS, el cálculo variará de la etapa de acondicionamiento que usen. 
  
  Este ejemplo obtiene el Valor Cuadrático Medio de la señal tal cual ingresa pero duplicando el valor de los cuadrados de la señal
  debido a que la etapa de acondicionamiento solo nos entrega el semiciclo positivo.
 
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
  
  Serial.begin(9600);
  analogReference(INTERNAL);
  //analogReference(INTERNAL1V1); //solo Arduino Mega
}

void loop() {
  
  float Irms=get_corriente(); //Corriente eficaz (A)
  float P=Irms*220.0; // P=IV (Watts)

  Serial.print("Irms: ");
  Serial.print(Irms,3);
  Serial.print("A, Potencia: ");
  Serial.print(P,3);  
  Serial.println("W");
  //delay(100);     
}

float get_corriente()
{
  float voltajeSensor;
  float corriente=0;
  float Sumatoria=0;
  long tiempo=millis();
  int N=0;
  while(millis()-tiempo<500)//Duración 0.5 segundos(Aprox. 30 ciclos de 60Hz)
  { 
    voltajeSensor = analogRead(pin_SCT) * (1.1 / 1023.0);////voltaje del sensor
    corriente=voltajeSensor*Sensibilidad; //corriente=VoltajeSensor*(30A/1V)
    Sumatoria=Sumatoria+sq(corriente);//Sumatoria de Cuadrados
    N=N+1;
    delay(1);
  }
  Sumatoria=Sumatoria*2;//Para compensar los cuadrados de los semiciclos negativos.
  corriente=sqrt((Sumatoria)/N); //ecuación del RMS
  return(corriente);
}
