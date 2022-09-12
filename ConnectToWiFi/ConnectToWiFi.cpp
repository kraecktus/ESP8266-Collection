// For PlatformIO, in the .ini File it needs these Parameters:
// build_flags = -fexceptions
// build_unflags = -fno - exceptions

#include <Arduino.h>
#include <ESP8266WiFi.h>

#define LED 2

const char *ssid = "SSID";
const char *password = "PASSWORD";

void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);

    try
    {
        digitalWrite(LED, HIGH);
        delay(5000);
        delay(10);
        Serial.println('\n');

        WiFi.begin(ssid, password);
        Serial.print("Connecting to ");
        Serial.print(ssid);
        Serial.print("...");

        Serial.print("\n");
        int i = 0;
        while (WiFi.status() != WL_CONNECTED)
        {
            digitalWrite(LED, LOW);
            delay(1000);
            Serial.print(".");
            digitalWrite(LED, HIGH);
        }
        Serial.println('\n');
        Serial.println("Connection established!");
        Serial.print("IP address:\t");
        Serial.println(WiFi.localIP());
        for (int i = 0; i < 9; i++)
        {
            digitalWrite(LED, HIGH);
            delay(500);
            digitalWrite(LED, LOW);
            delay(1500);
        }
        WiFi.disconnect();
    }
    catch (char e)
    {
        Serial.println(e);
        for (int i = 0; i < 9; i++)
        {
            digitalWrite(LED, HIGH);
            delay(1500);
            digitalWrite(LED, LOW);
            delay(500);
        }
    }
}

void loop()
{
}