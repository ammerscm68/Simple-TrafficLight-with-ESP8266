/*******************************************************************************************
 ** Autor: Mario Ammerschuber                                                             **
 ** Datum: Juni 2022                                                                      **
 ** Version: 1.01                                                                        ** 
 ** Lizenz:  Creative Commons Zero v1.0 Universal                                         **
 *******************************************************************************************
*/

/************************( Importieren der Bibliotheken )************************/
#include <pitches.h>                        // for passiv Buzzer

/*#define ROT 2     // NodeMCU v3 D4 -> GPIO 2
  #define GELB 0    // NodeMCU v3 D3 -> GPIO 0
  #define GRUEN 4   // NodeMCU v3 D2 -> GPIO 4*/
#define GRUEN 2 // NodeMCU v3 D4 -> GPIO 2
#define GELB 0  // NodeMCU v3 D3 -> GPIO 0
#define ROT 4   // NodeMCU v3 D2 -> GPIO 4

// passiv Buzzer Init
// ****************************************************************************************************
const int buzzerPin = D1; //for ESP8266 Microcontroller (D4 dont work with ESP8266 Microcontroller)
// const int buzzerPin = -1; // no Buzzer
// ****************************************************************************************************

int toggle = 0;
int BuzzerTrigger = 0;
int waitloop = 0;
 
/*****************************************( Setup )****************************************/
void setup() {
 Serial.begin(115200); // Serielle Verbindung mit 115200 Baud
  delay(250); //waits for data
  clearscreen(); // Serial Monitor clear screen

  // Init passiv Buzzer
  if (buzzerPin != -1) {
  pinMode(buzzerPin, OUTPUT);
  noTone(buzzerPin);} // kein Ton
  
// Pins als Output festlegen.
pinMode(ROT, OUTPUT);
pinMode(GELB, OUTPUT);
pinMode(GRUEN, OUTPUT);

Serial.println("*** Alert-Traffic-Light ***");
Serial.println("");

  // Initial LED's
  digitalWrite(ROT, LOW); 
  digitalWrite(GELB, LOW);
  digitalWrite(GRUEN, LOW); 
  SwitchTrafficLight(true,false,false,true); // Rot
  SwitchTrafficLight(false,true,false,true); // gelb
  SwitchTrafficLight(false,false,true,true); // grün
  MyWaitLoop(1000); 
  
  // LED's - Startstatus setzen
  if (buzzerPin != -1) {BuzzerBeep();} // Start Beep

  Serial.println("");
  Serial.println("Alert-Traffic-Light gestartet ...");
}
/*************************************( Setup - Ende )*************************************/
 
/*************************************(Hauptprogramm)**************************************/
void loop() {
  // Ampelsimulation
  SwitchTrafficLight(true,false,false,true); // Red
  MyWaitLoop(30000);
  SwitchTrafficLight(true,true,false,true); // Red/yellow
  MyWaitLoop(2000);
  SwitchTrafficLight(false,false,true,true); // green
  MyWaitLoop(30000);
  SwitchTrafficLight(false,true,false,true); // yellow
  MyWaitLoop(3000);
}
 /*************************************(Hauptprogramm - Ende)**************************************/
