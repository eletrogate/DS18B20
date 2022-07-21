#include <OneWire.h>
#include <DallasTemperature.h>

// O fio de dados é conectado no pino digital 2 no Arduino
#define ONE_WIRE_BUS 2

// Prepara uma instância oneWire para comunicar com qualquer outro dispositivo oneWire
OneWire oneWire(ONE_WIRE_BUS);  

// Passa uma referência oneWire para a biblioteca DallasTemperature
DallasTemperature sensors(&oneWire);

void setup(void)
{
  sensors.begin();  // Inicia a biblioteca
  Serial.begin(9600);
}

void loop(void)
{ 
  // Manda comando para ler temperaturas
  sensors.requestTemperatures(); 

  // Escreve a temperatura em Celsius
  Serial.print("Temperatura: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println(" graus");
  
  delay(500);
}