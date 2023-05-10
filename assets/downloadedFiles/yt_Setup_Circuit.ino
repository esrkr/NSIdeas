#define led1Pin A0
#define led2Pin A1
#define led3Pin A2
#define led4Pin A3
#define led5Pin 5
#define led6Pin 6
int switch1 = 2, switch2 = 4, switch3 = 7;
int solderingPin = 8, SolderingSwitch = 12;
int fanPin = 9, fanSwitch = 10;
int neoLed = 11, neoSwitch = 3;
int switchMode = 0;
int led1Bness = 0, led2Bness = 0, , led3Bness = 0, led4Bness = 0, led5Bness = 0, led6Bness = 0;
void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(led6Pin, OUTPUT);
  pinMode(solderingPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(neoLed, OUTPUT);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(SolderingSwitch, INPUT);
  pinMode(fanSwitch, INPUT);
  pinMode(neoSwitch, INPUT);
}

void loop() {
  currentMillis = millis() / 1000;
  if (digitalRead(switch1) == 1) {
    switchMode++;
  }
  switch (switchMode) {
    case 1: if (switch2 == 1) {led1Bness++;}
            else if (switch3 == 1) {led1Bness--;}
            analogWrite(led1Pin,led1Bness);
            break;
    case 2: if (switch2 == 1) {led2Bness++;}
            else if (switch3 == 1) {led2Bness--;}
            analogWrite(led2Pin,led2Bness);
            break;
    case 3: if (switch2 == 1) {led3Bness++;}
            else if (switch3 == 1) {led3Bness--;}
            analogWrite(led3Pin,led3Bness);
            break;
    case 4: if (switch2 == 1) {led4Bness++;}
            else if (switch3 == 1) {led4Bness--;}
            analogWrite(led4Pin,led4Bness);
            break;
    case 5: if (switch2 == 1) {led5Bness++;}
            else if (switch3 == 1) {led5Bness--;}
            analogWrite(led5Pin,led5Bness);
            break;
    case 6: if (switch2 == 1) {led6Bness++;}
            else if (switch3 == 1) {led6Bness--;}
            analogWrite(led6Pin,led6Bness);
            break;
  }

  if (digitalRead(SolderingSwitch) == 1) {
    analogWrite(buzzer, 255);
    delay(200);
    analogWrite(buzzer, 0);
    if (c == 0 || (currentMillis - startMillis >= 180)) {
      time_interval = relay_time_in = 180;   c = 1;  delay(1000);
    }
    else if (currentMillis - startMillis >= 120) {
      time_interval = relay_time_in = 120;         delay(1000);
    }
    else if (currentMillis - startMillis >= 60) {
      time_interval = relay_time_in =  60;         delay(1000);
    }
    else if (currentMillis - startMillis < 60) {
      time_interval = relay_time_in = 30;
      delay(1000);
    }
    relay_1_in = 1;   soldering = i = 0;   digitalWrite(relay, 0);
    startMillis = startMillis1 = startMillis2 = currentMillis;
  }
  if (soldering == 0) {
    if (currentMillis - startMillis1 >= 1) {
      leds[0] = CRGB::Red; FastLED.show();   i++;   startMillis1 = currentMillis;
      analogWrite(buzzer, 10);
    }
    if (currentMillis - startMillis2 >= 2) {
      leds[0] = CRGB::Black; FastLED.show();   startMillis2 = currentMillis;
      analogWrite(buzzer, 0);
    }
    if (currentMillis - startMillis >= time_interval) {
      digitalWrite(relay, 1);
      soldering = 1; relay_1_in = 0;   startMillis = currentMillis;
      leds[0] = CRGB::White; FastLED.show();
      analogWrite(buzzer, 255);   delay(200);   analogWrite(buzzer, 0);
    }
  }


}
