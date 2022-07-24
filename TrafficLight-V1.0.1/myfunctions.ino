// ****************************Hilfsfunktionen******************************************************
void clearscreen() { 
for(int i=0; i<10; i++) {
Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
}

// *************************************************************************************************

// passiv buzzer melody: (Big Ben)
int melody[] = {
NOTE_E3, NOTE_GS3, NOTE_FS3, NOTE_B2, 0,
NOTE_E3, NOTE_FS3, NOTE_GS3, NOTE_E3, 0,
NOTE_GS3, NOTE_E3, NOTE_FS3, NOTE_B2, 0,
NOTE_B2, NOTE_FS3, NOTE_GS3, NOTE_E3
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
4,4,4,2.5,4,
4,4,4,2.5,4,
4,4,4,2.5,4,
4,4,4,2.5};

// *************************************************************************************************

void MyWaitLoop(int wlt)
{// Pause Loop
waitloop = 0; // Variable zurücksetzen
while (waitloop < wlt) // Pause in Millisekunden
{ 
waitloop += 1; // inc waitloop 1
delay(1);
yield(); // Equivalent zu  Application.ProcessMessages; 
// Serial.println(String(waitloop));
}
}

// *************************************************************************************************

void BlinkLED(int farbe) {
 toggle = !toggle;
 if (BuzzerTrigger == 0){  
 BuzzerTrigger += 1;
 if (buzzerPin != -1) {beep(NOTE_E3, 350);} // BuzzerBeep
 }
 if (toggle) {
 if (farbe == ROT) {
 BlinkTrafficLight(true,false,false); // Rot
 }
 if (farbe == GELB) {
 BlinkTrafficLight(false,true,false); // Gelb
 }
 if (farbe == GRUEN) {
 BlinkTrafficLight(false,false,true); // Grün
 }
  } else 
     {
 digitalWrite(ROT, LOW); 
 digitalWrite(GELB, LOW);
 digitalWrite(GRUEN, LOW); 
      } 
MyWaitLoop(500); // kurze Pause 
}

// *************************************************************************************************

void BlinkLEDWifiConnect() {
toggle = !toggle;
 if (toggle) {
 BlinkTrafficLight(false,true,false); // Gelb
 }
  else 
     {
  BlinkTrafficLight(false,false,true); // Grün
      } 
 delay(1); // kurze Pause
}


// *************************************************************************************************

void SwitchTrafficLight(bool TLRed, bool TLYellow, bool TLGreen, bool Start){
if (!Start && buzzerPin != -1) {beep(NOTE_E3, 350);}  
if (TLRed){digitalWrite(ROT, HIGH);} else {digitalWrite(ROT, LOW);}
if (TLYellow){digitalWrite(GELB, HIGH);} else {digitalWrite(GELB, LOW);}
if (TLGreen){digitalWrite(GRUEN, HIGH);} else {digitalWrite(GRUEN, LOW);}
BuzzerTrigger = 0; // Zurücksetzen
MyWaitLoop(1000);
}

// *************************************************************************************************

void BlinkTrafficLight(bool TLRed, bool TLYellow, bool TLGreen){ 
if (TLRed){digitalWrite(ROT, HIGH);} else {digitalWrite(ROT, LOW);}
if (TLYellow){digitalWrite(GELB, HIGH);} else {digitalWrite(GELB, LOW);}
if (TLGreen){digitalWrite(GRUEN, HIGH);} else {digitalWrite(GRUEN, LOW);}
}

// *************************************************************************************************

void beep(int note, int duration){
tone(buzzerPin, note, duration);
MyWaitLoop(duration);}


// *************************************************************************************************

/*void BuzzerBeep()
{
beep(NOTE_A4, 500);
beep(NOTE_A4, 500);    
beep(NOTE_A4, 500);
beep(NOTE_F4, 350);
beep(NOTE_C5, 150);  
beep(NOTE_A4, 500);
beep(NOTE_F4, 350);
beep(NOTE_C5, 150);
beep(NOTE_A4, 650);
} */

// *************************************************************************************************

void BuzzerBeep()
{   
beep(NOTE_A4, 250);
beep(NOTE_F4, 250);
beep(NOTE_A4, 250);
}

// *************************************************************************************************

void StartBuzzerBeep()
{
// iterate over the notes of the melody:
for (int thisNote = 0; thisNote < 2; thisNote++) {
// to calculate the note duration, take one second divided by the note type.
//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
int noteDuration = 1000 / noteDurations[thisNote];
tone(buzzerPin, melody[thisNote], noteDuration);
// to distinguish the notes, set a minimum time between them.
// the note's duration + 30% seems to work well:
int pauseBetweenNotes = noteDuration * 1.30;
MyWaitLoop(pauseBetweenNotes);
// stop the tone playing:
noTone(buzzerPin);
}  
}

// *************************************************************************************************

void ShortBuzzerBeep()
{
// iterate over the notes of the melody:
for (int thisNote = 0; thisNote < 4; thisNote++) {
// to calculate the note duration, take one second divided by the note type.
//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
int noteDuration = 1000 / noteDurations[thisNote];
tone(buzzerPin, melody[thisNote], noteDuration);
// to distinguish the notes, set a minimum time between them.
// the note's duration + 30% seems to work well:
int pauseBetweenNotes = noteDuration * 1.30;
MyWaitLoop(pauseBetweenNotes);
// stop the tone playing:
noTone(buzzerPin);
}  
}

// *************************************************************************************************

void BigBenBuzzerBeep()
{
// iterate over the notes of the melody:
for (int thisNote = 0; thisNote < 19; thisNote++) {
// to calculate the note duration, take one second divided by the note type.
//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
int noteDuration = 1000 / noteDurations[thisNote];
tone(buzzerPin, melody[thisNote], noteDuration);
// to distinguish the notes, set a minimum time between them.
// the note's duration + 30% seems to work well:
int pauseBetweenNotes = noteDuration * 1.30;
MyWaitLoop(pauseBetweenNotes);
// stop the tone playing:
noTone(buzzerPin);
}  
}

// *************************************************************************************************

void StarWarsBuzzerBeep()
{
beep(NOTE_A4, 500);
 beep(NOTE_A4, 500);    
  beep(NOTE_A4, 500);
   beep(NOTE_F4, 350);
    beep(NOTE_C5, 150);  
     beep(NOTE_A4, 500);
      beep(NOTE_F4, 350);
       beep(NOTE_C5, 150);
        beep(NOTE_A4, 650);
 
MyWaitLoop(500);
 
beep(NOTE_E5, 500);
 beep(NOTE_E5, 500);
  beep(NOTE_E5, 500);  
   beep(NOTE_F5, 350);
    beep(NOTE_C5, 150);
     beep(NOTE_GS4, 500);
      beep(NOTE_F4, 350);
       beep(NOTE_C5, 150);
        beep(NOTE_A4, 650);
        
MyWaitLoop(500);

beep(NOTE_A5, 500);
 beep(NOTE_A4, 300);
  beep(NOTE_A4, 150);
   beep(NOTE_A5, 500);
    beep(NOTE_GS5, 325);
     beep(NOTE_G5, 175);
      beep(NOTE_FS5, 125);
       beep(NOTE_F5, 125);    
        beep(NOTE_FS5, 250);
        
MyWaitLoop(325);

beep(NOTE_AS4, 250);
 beep(NOTE_DS5, 500);
  beep(NOTE_D5, 325);  
   beep(NOTE_CS5, 175);  
    beep(NOTE_C5, 125);  
     beep(NOTE_AS4, 125);  
      beep(NOTE_C5, 250);  
 
MyWaitLoop(350);
}
// *************************************************************************************************
// *************************************************************************************************
