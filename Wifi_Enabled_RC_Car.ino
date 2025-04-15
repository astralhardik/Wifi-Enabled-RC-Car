/*
 * ----------------------------------------------------------------------------
 * Project Title   : Wi-Fi Controlled RC Car
 * Description     : A mobile-controlled, Wi-Fi-enabled 4WD robotic car developed
 *                   using ESP8266 (NodeMCU) and motor drivers. Commands are sent
 *                   from a mobile app through HTTP requests.
 *
 * Event           : Torque 2023 – Organized by Phoenix Club, LNMIIT
 * Author          : Hardik Agrawal
 * Date            : April 22, 2023
 *
 * Notes:
 * - Controlled via mobile device over a Wi-Fi hotspot created by the ESP8266
 * - Includes directional movement and speed control
 * - Visual feedback via LEDs
 * ----------------------------------------------------------------------------
 */

#include <ESP8266WiFi.h>

WiFiClient client;     // Any Device connected to the NodeMCU
WiFiServer server(80); // NodeMCU's Server
#define l1 D1
#define l2 D2
#define r1 D3
#define r2 D4
#define green D5
#define red D6
#define yl D7 // left ka yellow
#define yr D8 // right ka yellow
 
int speed = 0;
bool b = 0;

void setup()
{
    Serial.begin(115200); // Want to print data on serial moniter
    WiFi.softAP("Mars Rover", "Spacex23");
    Serial.println();
    Serial.println("NodeMCU is started");
    Serial.println(WiFi.softAPIP());
    server.begin();

    pinMode(l1, OUTPUT);
    pinMode(l2, OUTPUT);
    pinMode(r1, OUTPUT);
    pinMode(r2, OUTPUT);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(yl, OUTPUT);
    pinMode(yr, OUTPUT);
}

// void blinkleft(){
//   digitalWrite(yl,HIGH);
//   delay(1000);
//   digitalWrite(yl,LOW);
//   delay(1000);
//   digitalWrite(yl,HIGH);
//   delay(1000);
// }

// void blinkRight(){
//   digitalWrite(yr,HIGH);
//       delay(1000);
//       digitalWrite(yr,LOW);
//       delay(1000);
//       digitalWrite(yr,HIGH);
//       delay(1000);
// }

void loop()
{
    client = server.available();
    if (client)
    {
        Serial.println("Started");
        String request = client.readStringUntil('\n');
        Serial.println(request);
        request.trim();

        // controls for the car
        if (!b)
        {
            if (request == "GET /move?dir=forward HTTP/1.1")
            {

                Serial.println("Working");
                //    digitalWrite(l1 , HIGH);
                analogWrite(l1, speed);
                //    digitalWrite(r1, HIGH);/
                analogWrite(r1, speed);
                digitalWrite(r2, LOW);
                digitalWrite(l2, LOW);
                digitalWrite(red, LOW);
                digitalWrite(green, HIGH);

                //  if(green == HIGH){
                //    Serial.println("Forward");
                //  }
                //  delay(1000);
                //  digitalWrite(l1 , LOW);
            }
            else if (request == "GET /move?dir=backward HTTP/1.1")
            {
                Serial.println("OFF");
                //   digitalWrite(r2 , HIGH);
                analogWrite(r2, speed);
                // digitalWrite(l1, LOW);
                digitalWrite(r1, LOW);
                analogWrite(l2, speed);
                digitalWrite(l1, LOW);
                digitalWrite(r1, LOW);
                digitalWrite(red, LOW);
                digitalWrite(green, HIGH);
                //  delay(1000);
                //  digitalWrite(l1 , HIGH);
            }
            else if (request == "GET /move?dir=left HTTP/1.1")
            {
                //   digitalWrite(l1,HIGH);
                analogWrite(l1, speed);
                digitalWrite(l2, LOW);
                // analogWrite(l2,speed/2);
                digitalWrite(r1, LOW);
                // analogWrite(r1,speed/2);
                //   digitalWrite(r2,HIGH);
                analogWrite(r2, speed);
                digitalWrite(red, LOW);
                digitalWrite(green, HIGH);
                // blinkleft();
                digitalWrite(yl, HIGH);
            }
            else if (request == "GET /move?dir=right HTTP/1.1")
            {
                digitalWrite(r2, LOW);
                // analogWrite(r2,speed/2);
                //   digitalWrite(r1,HIGH);
                analogWrite(r1, speed);
                digitalWrite(l1, LOW);
                // analogWrite(l1,speed/2);
                //   digitalWrite(l2,HIGH);
                analogWrite(l2, speed);
                digitalWrite(green, HIGH);
                digitalWrite(red, LOW);
                // blinkRight();
                digitalWrite(yr, HIGH);
            }
            else
            {
                digitalWrite(r2, LOW);
                digitalWrite(l2, LOW);
                digitalWrite(l1, LOW);
                digitalWrite(r1, LOW);
                digitalWrite(red, HIGH);
                digitalWrite(green, LOW);
                digitalWrite(yl, LOW);
                digitalWrite(yr, LOW);
            }
        }
        else
        {
            if (request == "GET /move?dir=forward HTTP/1.1")
            {

                Serial.println("Working");
                //    digitalWrite(l1 , HIGH);
                analogWrite(l1, speed);
                //    digitalWrite(r1, HIGH);/
                analogWrite(r1, speed);
                digitalWrite(r2, LOW);
                digitalWrite(l2, LOW);
                digitalWrite(red, LOW);
                digitalWrite(green, HIGH);

                //  if(green == HIGH){
                //    Serial.println("Forward");
                //  }
                //  delay(1000);
                //  digitalWrite(l1 , LOW);
            }
            else if (request == "GET /move?dir=backward HTTP/1.1")
            {
                Serial.println("OFF");
                //   digitalWrite(r2 , HIGH);
                analogWrite(r2, speed);
                //    digitalWrite(l2 , HIGH);
                analogWrite(l2, speed);
                digitalWrite(l1, LOW);
                digitalWrite(r1, LOW);
                digitalWrite(red, LOW);
                digitalWrite(green, HIGH);
                //  delay(1000);
                //  digitalWrite(l1 , HIGH);
            }
            else if (request == "GET /move?dir=left HTTP/1.1")
            {
                //   digitalWrite(l1,HIGH);
                analogWrite(l1, speed);
                digitalWrite(l2, LOW);
                // analogWrite(l2,speed/2);
                // digitalWrite(r1, LOW);
                analogWrite(r1,speed/2);
                digitalWrite(r2,LOW);
                // analogWrite(r2, speed);
                digitalWrite(red, LOW);
                digitalWrite(green, HIGH);
                // blinkleft();
                digitalWrite(yl, HIGH);
            }
            else if (request == "GET /move?dir=right HTTP/1.1")
            {
                digitalWrite(r2, LOW);
                // analogWrite(r2,speed/2);
                //   digitalWrite(r1,HIGH);
                analogWrite(r1, speed);
                // digitalWrite(l1, );
                analogWrite(l1,speed/2);
                  digitalWrite(l2,LOW);
                // analogWrite(l2, speed);
                digitalWrite(green, HIGH);
                digitalWrite(red, LOW);
                // blinkRight();
                digitalWrite(yr, HIGH);
            }
            else
            {
                digitalWrite(r2, LOW);
                digitalWrite(l2, LOW);
                digitalWrite(l1, LOW);
                digitalWrite(r1, LOW);
                digitalWrite(red, HIGH);
                digitalWrite(green, LOW);
                digitalWrite(yl, LOW);
                digitalWrite(yr, LOW);
            }
        }

        // speed controls
        if (request == "GET /action?type=1 HTTP/1.1")
        {
            speed = 255;
        }
        else if (request == "GET /action?type=2 HTTP/1.1")
        {
            speed = 200;
        }
        else if (request == "GET /action?type=3 HTTP/1.1")
        {
            speed = 150;
        }
        else if(request == "GET /action?type=4 HTTP/1.1")
        {
          b = 1;
        }
        else if(request == "GET /action?type=5 HTTP/1.1")
        {
          b = 0;
        }
    }
}
