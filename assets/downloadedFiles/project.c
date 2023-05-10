#include <Servo.h>

#include <DHT.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define FIREBASE_HOST "https://smarthomeapp-71479-default-rtdb.firebaseio.com/" //Without http:// or https:// schemes
#define FIREBASE_AUTH "ksHjnIGxGw0RJ3ada8667apn5ZB00THNM04ADju5"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


// Replace with your network credentials
const char* ssid = "Balu2G";
const char* password = "123987bk";

FirebaseData firebaseData;
FirebaseJson json;

Servo myservo;  // create servo object to control a servo

#define DHTPIN D4 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

  myservo.attach(D4);  // attaches the servo on GPIO 2 (D4) to the servo object
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(500);
  display.clearDisplay();
   display.setTextColor(WHITE);
}

void getHumiTemp(){
    float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);

  Serial.print("Temperature: ");
  Serial.print(temperature);

}

void setServoAngle(int angle){
  myservo.write(angle);
  }

void setFirebaseValue(int Mode = 0,String tag,String stringData="", int intData=0, float floatData= 0){
  // int 0, string 1, float 2
  if(Mode == 0){
    Firebase.setInt(firebaseData, tag,intData);
    }
  else if(Mode == 1){
    Firebase.setString(firebaseData, tag,stringData);
    }
  else if(Mode == 2){
    Firebase.setFloat(firebaseData, tag,floatData);
    }
  }

  void getFirebaseValue(int Mode = 0,String tag){
  //get int 0, string 1, float 2
  if(Mode == 0){
    return Firebase.getInt(firebaseData, tag);
    }
  else if(Mode == 1){
    return Firebase.getString(firebaseData, tag);
    }
  else if(Mode == 2){
    return Firebase.getFloat(firebaseData, tag);
    }
    else{
        return -1;
    }
  }

void displayOled(String data,int x=15,int y,int textSize = 1){
    display.clearDisplay();
    display.setTextSize(textSize);
    display.setCursor(x, y);
    display.println(data);
    display.display();
} 

void loop() {

}