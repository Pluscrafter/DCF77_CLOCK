#include <Time.h>
#include <TimeLib.h>

#include <Wire.h>
#include <DCF77.h>
#include <RTClib.h>

#define DCF_PIN 2                
#define DCF_INTERRUPT 0


time_t time;
DCF77 DCF = DCF77(DCF_PIN,DCF_INTERRUPT, true);
RTC_DS1307 rtc;

bool initialTIME = false;

void setup() {
  DCF.Start();
  if (! rtc.begin()) {
    while (1);
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  time_t DCFtime = DCF.getTime();
  if (DCFtime!=0){
    setTime(DCFtime);
    if(initialTIME == false){
      rtc.adjust(DateTime(year(),month(),hour(),minute(),second()));
    }
  }

  if(hour() == 3 && minute()==0 && second()==0){
      rtc.adjust(DateTime(year(),month(),hour(),minute(),second()));
  }
  else if(hour() == 3 && minute()==1 && second()==0){
      rtc.adjust(DateTime(year(),month(),hour(),minute(),second()));
  }
  else if(hour() == 3 && minute()==2 && second()==0){
      rtc.adjust(DateTime(year(),month(),hour(),minute(),second()));
  }
  
}
