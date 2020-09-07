# Ejemplos_SCT013
Códigos de ejemplo para sensores de corriente AC no invasivos SCT-013 o transformadores de corriente (CTs) similares

![Sensor de Corriente AC 30A no invasivo - SCT-013-030](https://naylampmechatronics.com/449-large_default/sensor-de-corriente-ac-30a-no-invasivo-sct-013-030.jpg)

Información detallada de los ejemplos en: [Tutorial sensor de corriente AC no invasivo SCT-013](https://naylampmechatronics.com/blog/51_tutorial-sensor-de-corriente-ac-no-invasivo-s.html)

## Contenido
* **SimpleLectura:**  Se obtienen mediciones de intensidad usando un sensor SCT013
* **Irms:** Se obtiene la corriente RMS, el cálculo variará de la etapa de acondicionamiento que usen.

## Requerimientos
 **Software**
  * IDE Arduino
  
 **Hardware**
  * [Arduino Uno](https://naylampmechatronics.com/arduino-tarjetas/8-arduino-uno-r3.html) (o cualquier modelo)
  * Sensor de corriente no invasivo([SCT-013-030](https://naylampmechatronics.com/sensores-corriente-voltaje/154-sensor-de-corriente-ac-30a-no-invasivo-sct-013-030.html), [SCT-013-000](https://naylampmechatronics.com/sensores-corriente-voltaje/227-sensor-de-corriente-ac-100a-no-invasivo-sct-013-000.html) o similar)
  
## Conexiones
  Sensor | Arduino
  ----------------------|-------  
   Señal(Acondicionada) | A0
  
  El sensor no se puede conectar directamente al Arduino, necesita un circuito de acondicionamiento
  
  Puede cambiar la conexión a otro pin analógico del arduino modificando la variable que define el pin

## Licencia
Los ejemplos son Open Source, desarrollados por el equipo de Naylamp Mechatronics bajo [licencia MIT](LICENSE)
 
## Links 
 * [Tutorial sensor de corriente AC no invasivo SCT-013](https://naylampmechatronics.com/blog/51_tutorial-sensor-de-corriente-ac-no-invasivo-s.html)
 * [Sensor de Corriente AC 30A no invasivo - SCT-013-030](https://naylampmechatronics.com/sensores-corriente-voltaje/154-sensor-de-corriente-ac-30a-no-invasivo-sct-013-030.html)
