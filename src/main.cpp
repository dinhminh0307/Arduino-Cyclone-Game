#include <Arduino.h>

int greenPin = 2;
int redPin1 = 3;
int redPin2 = 4;
int redPin3 = 5;
int redPin4 = 6;
int redPin5 = 7;
int delayTime = 100;
int breakTime = 5000;
int readPin = A0;
double readVal = 0.0;
double realVal = 0.0;
void setup() {
pinMode(greenPin, OUTPUT);
pinMode(redPin1, OUTPUT);
pinMode(redPin2, OUTPUT);
pinMode(redPin3, OUTPUT);
pinMode(redPin4, OUTPUT);
pinMode(redPin5, OUTPUT);

pinMode(readPin, INPUT);
Serial.begin(9600);
}

bool onButtonPressed() {
    readVal = analogRead(readPin);
    realVal = (5./1023.) * readVal;
    Serial.println(realVal);
    if(realVal > 0.5) {
        return true;
    }
    else {
        return false;
    }
}

void onUserLoose() {
    digitalWrite(redPin1, HIGH);
    digitalWrite(redPin2, HIGH);
    digitalWrite(redPin3, HIGH);
    delay(breakTime);
}

void onUserWin() {
    digitalWrite(redPin1, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(redPin3, LOW);
    
    delay(breakTime);
}
void loop() {
    digitalWrite(redPin1, HIGH);
    if(onButtonPressed()) {
        onUserLoose();
    }
    else {
        delay(delayTime);
        digitalWrite(redPin1, LOW);
        digitalWrite(redPin2, HIGH);
        if(onButtonPressed()) {
            onUserLoose();
        }
        else {
            delay(delayTime);
            digitalWrite(redPin2, LOW);
            digitalWrite(redPin2, HIGH);
            if(onButtonPressed()) {
                onUserLoose();
            }
            else {
            delay(delayTime);
            digitalWrite(redPin2, LOW);
            digitalWrite(greenPin, HIGH);
            if(onButtonPressed()) {
                onUserWin();
            }
            else {
            delay(delayTime);
            digitalWrite(greenPin, LOW);
            digitalWrite(redPin3, HIGH);
            if(onButtonPressed()) {
                onUserLoose();
            }
            else {
                delay(delayTime);
                digitalWrite(redPin3, LOW);
            }
            }
            } 
        } 
    }   
}


