#include <Rtc_Pcf8563.h>

Rtc_Pcf8563 rtc;
int button = 0;

void SoarLongo() {
  digitalWrite(7, LOW);
  delay(8000);
  digitalWrite(7, HIGH);
}

void SoarCurto() {
  digitalWrite(7, LOW);
  delay(1700);
  digitalWrite(7, HIGH);
}

void setup() {
  //clear out the registers
  // rtc.initClock();
  //set a time to start with.
  //day, weekday, month, century(1=1900, 0=2000), year(0-99)
  // rtc.setDate(14, 3, 9, 0, 21);
  //hr, min, sec
  // rtc.setTime(1, 15, 0);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(5, INPUT);
}

void loop() {
  button = digitalRead(5);
  if(button == LOW) {
    digitalWrite(7, HIGH);
    Serial.println(rtc.formatTime());
    delay(1000);
    if(rtc.getHour() == 12 and rtc.getMinute() == 30 and rtc.getSecond() == 0) {
      SoarLongo();
    }
    else if(rtc.getHour() == 13 and rtc.getMinute() == 20 and rtc.getSecond() == 0) {
      SoarCurto();
    }
    else if(rtc.getHour() == 14 and rtc.getMinute() == 10 and rtc.getSecond() == 0) {
      SoarCurto();
    }
    else if(rtc.getHour() == 15 and rtc.getMinute() == 0 and rtc.getSecond() == 0) {
      SoarLongo();
    }
    else if(rtc.getHour() == 15 and rtc.getMinute() == 20 and rtc.getSecond() == 0) {
      SoarLongo();
    }
    else if(rtc.getHour() == 16 and rtc.getMinute() == 10 and rtc.getSecond() == 0) {
      SoarCurto();
    }
    else if(rtc.getHour() == 17 and rtc.getMinute() == 0 and rtc.getSecond() == 0) {
      SoarLongo();
    }
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
}
