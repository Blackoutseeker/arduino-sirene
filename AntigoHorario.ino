#include <Rtc_Pcf8563.h>

Rtc_Pcf8563 rtc;
int button = 0;

void SoarLongo() {
  digitalWrite(7, LOW);
  delay(9500);
  digitalWrite(7, HIGH);
}

void SoarCurto() {
  digitalWrite(7, LOW);
  delay(2000);
  digitalWrite(7, HIGH);
}

void setup() {
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
    if(rtc.getHour() == 7 and rtc.getMinute() == 9 and rtc.getSecond() == 10) {
      SoarLongo();
    }
    else if(rtc.getHour() == 7 and rtc.getMinute() == 59 and rtc.getSecond() == 10) {
      SoarCurto();
    }
    else if(rtc.getHour() == 8 and rtc.getMinute() == 49 and rtc.getSecond() == 10) {
      SoarLongo();
    }
    else if(rtc.getHour() == 9 and rtc.getMinute() == 9 and rtc.getSecond() == 10) {
      SoarLongo();
    }
    else if(rtc.getHour() == 9 and rtc.getMinute() == 59 and rtc.getSecond() == 10) {
      SoarCurto();
    }
    else if(rtc.getHour() == 10 and rtc.getMinute() == 49 and rtc.getSecond() == 10) {
      SoarCurto();
    }
    else if(rtc.getHour() == 11 and rtc.getMinute() == 39 and rtc.getSecond() == 10) {
      SoarLongo();
    }
    else if(rtc.getHour() == 12 and rtc.getMinute() == 59 and rtc.getSecond() == 10) {
      SoarLongo();
    }
    else if(rtc.getHour() == 13 and rtc.getMinute() == 49 and rtc.getSecond() == 10) {
      SoarCurto();
    }
    else if(rtc.getHour() == 14 and rtc.getMinute() == 39 and rtc.getSecond() == 10) {
      SoarLongo();
    }
    else if(rtc.getHour() == 14 and rtc.getMinute() == 59 and rtc.getSecond() == 10) {
      SoarLongo();
    }
    else if(rtc.getHour() == 15 and rtc.getMinute() == 49 and rtc.getSecond() == 10) {
      SoarCurto();
    }
    else if(rtc.getHour() == 16 and rtc.getMinute() == 38 and rtc.getSecond() == 50) {
      SoarLongo();
    }
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
}
