/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
 
#include <Keypad.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (   0 x 27  ,  16 , 2  )  ;
#define Password_Length  4 
char A [ Password_Length ] ; 
char B [ Password_Length ] = "123"; 
byte data_count = 0 , master_count = 0 ;
bool Pass_is_good ;
const byte numRows = 4 ;
const byte numCols   = 4 ;
char val [ numRows ] [ numCols ] = {
{ '1' , '2' , '3' , 'A'} ,
{ '4' , '5' , '6' , 'B'} ,
{ '7' , '8' , '9' , 'C'} ,
{ '*' , '0' , '#' , 'D'}  } ;
byte rowPins [ numRows ] = { 9 , 8 , 7 , 6 };
byte colPins  [ numCols   ] = { 5 , 4 , 3 , 2 };
Keypad myKeypad =Keypad(makeKeymap (val) ,rowPins ,colPins ,numRows ,numCols) ;
void setup( )  {
lcd  . begin ( ) ;
lcd  . backlight ( ) ;
Serial.begin ( 9600 ) ;
pinMode ( 12 , OUTPUT ) ;
pinMode ( 11 , OUTPUT ) ;
}
void loop( )   {
lcd . setCursor ( 0 , 0 ) ;
lcd . print ("Enter Password:") ;
char keypressed = myKeypad.getKey( ) ;
if ( customKey ) {
A [ data_count ] = customKey ;
lcd . setCursor data_count , 1) ;
lcd . print (A[data_count] ) ;
data_count ++ ;
}
if ( data_count == Password_Length-1 ) {
lcd . clear ( ) ;
    if (!strcmp ( A , B )) {
lcd . print ("The Door is Open") ;
    digitalWrite ( 12   ,  HIGH ) ;
    digitalWrite ( 11   ,  HIGH ) ;
      delay(10000) ;
    digitalWrite ( 12   ,  LOW ) ;
    digitalWrite ( 11   ,  LOW ) ;
      }
    else {
lcd . print ("The Door is Locked  ") ;
      delay(1000) ;
      }
lcd . clear ( ) ;
    clearData ( ) ;  
  }
}
void clearData(){
  while ( data_count != 0 ) {
    A [ data_count -- ] = 0 ; 
  }
  return ;
}
