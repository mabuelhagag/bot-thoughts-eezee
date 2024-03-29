/*
  SD card basic file example
 
 This example shows how to create and destroy an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10
 
 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 	 
 */
#include <SD.h>

File myFile;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);

  digitalWrite(10, HIGH);
  pinMode(10, OUTPUT);

  delay(5000);

  while(!SD.begin(10)) {
    Serial.println("[FAIL] initialization failed.");
    delay(1000);
  }
  Serial.println("[PASS] initialization done.");

}

void loop()
{
  bool pass = true;
  
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin 
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
  // or the SD library functions will not work. 
  if (SD.exists("example.txt")) {
    Serial.println("[FAIL] example.txt already exists.");
    pass = false;
  }
  else {
    Serial.println("[PASS] no example.txt, good.");
  }

  // open a new file and immediately close it:
  myFile = SD.open("example.txt", FILE_WRITE);
  myFile.close();

  // Check to see if the file exists: 
  if (SD.exists("example.txt")) {
    Serial.println("[PASS] example.txt created.");
  }
  else {
    Serial.println("[FAIL] example.txt not created.");  
    pass = false;
  }

  // delete the file:
  SD.remove("example.txt");

  if (SD.exists("example.txt")){ 
    Serial.println("[FAIL] example.txt not removed.");  
    pass = false;
  }
  else {
    Serial.println("[PASS] example.txt removed.");
  }

  if (pass) {
    Serial.println("----\n[PASS] ALL TESTS PASS\n----\n");
  } else {
    Serial.println("----\n[FAIL] one or more tests failed\n----\n");
  }
  
  delay(5000);
  
}



