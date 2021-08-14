#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>

#define ssid "BEAR FAMILY | 2.4G"
#define password "bearhome"
#define serverName "http://192.168.1.5:9000/location"

<<<<<<< HEAD
//Your Domain name with URL path or IP address with path
const char* serverName = "http://127.0.0.1:9000/location";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
=======
>>>>>>> 426fb622dfc161a2fbd3d700eaebe3cadfefc7b5
unsigned long lastTime = 0;
unsigned long timerDelay = 5000;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  Serial.println("[Connecting to WIFI]");
  while(WiFi.status() != WL_CONNECTED) {
  }
  Serial.println("[Connected to WiFi]");
  Serial.println("Delay 5 seconds before publishing the first reading.");
}

void loop() {
    //Check WiFi connection status
    if(WiFi.status() == WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
    
      http.begin(client, serverName);

<<<<<<< HEAD
      // Specify content-type header
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      // Data to send with HTTP POST
      String httpRequestData = "name=quyen&lat=24.25&long=49.54";           
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
      
      // If you need an HTTP request with a content type: application/json, use the following:
      //http.addHeader("Content-Type", "application/json");
      //int httpResponseCode = http.POST("{\"name\":\"<3\",\"lat\":\"<3\",\"long\":\"<3\"}");
=======
      //Get package from LoRa Receiver and split
        String LoRa_Received_String = "";
        Serial.println("[Receiving data]");
        while (!Serial.available()) {
        }

        delay(100);
     
        int count = 0;
        String splited[3];
        String data_received = "";

        while (Serial.available()) {
          char temp_read = Serial.read();
           if (temp_read != 10)
             data_received += char(temp_read);
        }
      
        for(int i = 0; i < data_received.length(); i++) {
          char temp_read = data_received[i];
          if (temp_read != 10) {
            if (temp_read == 32)
              count++;
            else
              splited[count] += char(temp_read);
          }
        }

      //Send to web server
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST("{\"name\":\"" + splited[0] + "\",\"lat\":\"" + splited[1] + "\", \"long\":\"" + splited[2] + "\"}");
      
>>>>>>> 426fb622dfc161a2fbd3d700eaebe3cadfefc7b5
     
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
        
      // Free resources
      http.end();
    }
}
