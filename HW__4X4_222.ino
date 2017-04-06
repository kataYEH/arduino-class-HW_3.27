#include <SevSeg.h>
#include <Keypad.h>

SevSeg sevseg; 

void setup() {
   Serial.begin(9600); 
   byte numDigits =1;
   
   byte digitPins[] = {A0};
     byte segmentPins[] = {13,11,A4,A2,A1,12,A5,A3};
   sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
}

const byte ROWS = 4;
const byte COLS = 4;
char key;
int k;
char keys[ROWS][COLS]={
   {'7', '4', '1', '0'},
  {'8','5' , '2', 'A'},
  {'9', '6', '3', 'B'},
  {'C', 'D', 'E', 'F'}
};

byte rowPins[ROWS]={2,3,4,5};
byte colPins[COLS]={6,7,8,9};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void loop() {
  key = keypad.getKey();
  
  if (key != NO_KEY)
  {
    if(key>='A' && key<='F')
       k=key-'A';
    else
       k=key-'0';
       
    Serial.println(key);
     sevseg.setNumber(k,1);
     sevseg.refreshDisplay(); 
  }
  else
   sevseg.refreshDisplay(); 
  


  
 
}
