#include <SPI.h> // Подключаем библиотеку для работы с шиной SPI 
#include "nRF24L01.h" // Подключаем файл настроек из библиотеки RF24 
#include "RF24.h" // Подключаем библиотеку для работы с nRF24L01+ 

RF24 radio(9, 10); // Создаём объект radio для работы с библиотекой RF24, указывая номера выводов nRF24L01+ (CE, CSN) 
byte incomingByte;

void setup() { 
  Serial.begin(9600); 
  printf_begin();
  radio.begin();
  radio.setAutoAck(false);
}
 
void loop() { 
  //print characters from array to serial monitor 
  if (Serial.available()) {
    incomingByte = Serial.read();
  }
  switch (incomingByte) {
    case '1':
      radio.startListening();
      radio.printDetails();  // Вот эта строка напечатает нам что-то, если все правильно соединили.
      delay(100);
      radio.stopListening();
      break;
    case '2':
      Serial.println("dddddd2\ndddddd2dddddd2dddddd2dddddd2\nvdddddd2dddddd2dddddd2dddddd2dddddd2dddddd2\n");
      Serial.println("aqqqqd2\nqqqq2dddddd2qqdddd2ddqdd2\nvddq2dddddd2dddddd2dddddd2ddqqqqqqqqqqqqqqqqqqqqqd2dddddd2\n");
      Serial.println("fffffdd2\ndffffffffffffdddfffffffffffffffffffffffffffffdd2\nvdddddd2dddddd2dddddd2fffffffffdd2dddddd2dddddd2\n");
      break;
  }
  incomingByte = '0';
  delay(10);
}

int serial_putc( char c, FILE * ) {
  Serial.print( c );  
  return c;
}

void printf_begin(void) {
  fdevopen( &serial_putc, 0 );
}
