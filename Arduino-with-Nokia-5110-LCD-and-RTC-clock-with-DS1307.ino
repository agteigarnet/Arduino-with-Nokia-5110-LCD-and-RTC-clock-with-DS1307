/***********************************************************************
            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                    Version 2, December 2004

 Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.

http://www.wtfpl.net/

************************************************************************/
#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>
#include <LCD5110_Graph.h>
#include <stdio.h>

// LCD5110(SCK, MOSI, DC, RST, CS);
LCD5110 lcd(7,6,5,3,4); // Start an instance of the LCD5110 class - change the pins to suite your needs

extern unsigned char BigNumbers[];
extern unsigned char SmallFont[];
extern uint8_t clock[];

int periodState = 0; // see myBlinkinPeriod() funcion below

void setup() {
  // put your setup code here, to run once:

      setSyncProvider(RTC.get);   // the function to get the time from the RTC
      setSyncInterval(60);    // Set the number of seconds between re-sync
      setTime(12,30,0,14,1,1970); //  setTime(hr,min,sec,day,month,yr);
                                     // Another way to set the time, useful to test the script even without DS1307

      while(timeStatus()== timeNotSet); // wait until the time is set by the sync provider
    
      lcd.InitLCD();// Initialize the display
      lcd.clrScr();// Clear the screen buffer
      lcd.drawBitmap(0, 0, clock, 84, 48); // Draw a bitmap -  see clock.c and library doc
      lcd.update();  // Copy the screen buffer to the screen
      delay(1000);
      
} // end setup

void loop() {
  // put your main code here, to run repeatedly:  
  
  digitalClockDisplay(); // see function below
  delay(1000);

} // end loop

void digitalClockDisplay(){ 
  // digital clock display of the time  
    
    String myHour  = String (hour());
    String myMinute = String (minute());
    String myYear = String (year());
      
      lcd.clrScr();
      lcd.setFont(SmallFont);
      lcd.print( myDayOfWeek(), CENTER,0);      
      String fullDate = printDigits(day()) + "/" + printDigits(month()) + "/" + myYear;
      lcd.print(fullDate,CENTER,10);      

        lcd.setFont(BigNumbers);

            String strH;  
            strH = printDigits (hour());
            lcd.print(strH,7,18);
            
                myBlinkinPeriod();
                String strM; 
                strM = printDigits (minute());                
                lcd.print(strM,47,18);
    
   lcd.update();  // Copy the screen buffer to the screen
}


String myDayOfWeek(){ // simple switch to print week day in string format

  String mDoW;
    switch (weekday()){      
      case 1:
      mDoW = "Sunday";
      break;
      case 2:
      mDoW = "Monday";
      break;    
      case 3:
      mDoW = "Tuesday";
      break;    
      case 4:
      mDoW = "Wednesday";
      break;    
      case 5:
      mDoW = "Thursday";
      break;    
      case 6:
      mDoW = "Friday";
      break;    
      case 7:
      mDoW = "Saturday";
      break;  
         return mDoW;    
    }   
}


void myBlinkinPeriod(){ // utility function for digital clock display: make period between digits blinking 
                        // see Blink without Delay example in Arduino IDE
 
  unsigned long previousMillis = 0;
  const long interval = 1000;
  unsigned long currentMillis = millis();

    if(currentMillis - previousMillis >= interval) {    
      previousMillis = currentMillis;      
      
        if (periodState == 0){
          lcd.print(".",35,18);     
          periodState = 1;
        }
        else{
          lcd.print("",35,18);      
          periodState = 0;
        }      
        
    }

}

String printDigits(int digits){   // utility function for digital clock display: prints leading 0 
  
  String myDigits ;
    if(digits < 10){  
    myDigits = String (digits);
    myDigits = "0" + myDigits;         
    }
    else{
      myDigits = String (digits);      
      }
    return myDigits;
}
