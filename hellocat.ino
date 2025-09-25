#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(10, 11);

Servo myServo;
int servoval = 12;
int cutout = 2;
String mode = "cat";
long seconds = 0;
String secondsstr = "";
String state;
long days;
String daysstr="";
int yes = 1;
long sum = 0; //sum in seconds

void setup() {
  bluetooth.begin(9600);
  myServo.attach(8);
  myServo.write(12);
  pinMode(cutout, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  while (bluetooth.available()) {  
    delay(10);                         
    char c = bluetooth.read();
    state += c;
  }
  if (state.length() > 0) {
    if (state == "CAT") {
      mode = "cat";
      state="";
    }
    if (state == "NOCAT") {
      mode = "no cat";
      state="";
    }
    if (state == "OK"){
        if (servoval!=120) {
        servoval = 120;
        myServo.write(servoval);
        delay(1000);
       if(servoval!=20) {
        servoval = 20;
        myServo.write(servoval);
      }
        }
        state="";
    }
    if (state[0] >= '0' && state[0] <= '9')
    {
      for(int i = 0; i<state.length(); i++)
      {
        if(yes!=0){
          if(state[i]!=';'){
            secondsstr+=state[i];
          }
          else {
            yes = 0;
          }
        }else {
           daysstr+=state[i];
        }
      }
      yes = 1;
      seconds=secondsstr.toInt();
      days=daysstr.toInt();
      secondsstr="";
      daysstr="";
    }
    state="";
  }
  if (mode=="cat") {
    if (digitalRead(cutout)==LOW) {
      if (servoval!=120) {
        servoval = 120;
        myServo.write(servoval);
      }
    }
    if (digitalRead(cutout)==HIGH) {
      if(servoval!=20) {
        servoval = 20;
        myServo.write(servoval);
      }
    }
  }
  if (seconds > 0){
    sum += 1;
    if (seconds==sum) {
      if (servoval!=120) {
        servoval = 120;
        myServo.write(servoval);
        delay(1000);
         if(servoval!=20) {
          servoval = 20;
          myServo.write(servoval);
         }
        if (days>0){
          sum=0;
          seconds=days;
        }
        else
        {
          sum=0;
          seconds=0;
        }
      }
    }
    delay(1000);
  }
}
