/*
 * how to upload
 * 1.CH_PH=HIGH.
 * 2.GPIO_0=LOW.
 * 3.Reset power.
 * 4.Upload arduino code for esp-01
 * 5.GPIO_0 pull High.
 * 6.System is working.
 * 
 */

/*
 *   *=scan
 *   $=ssid
 *   %=password
 *   ^=connection
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

//const char *ssid = "BRAININTERNET";
//const char *password = "BRAINCOOL";
/*
String ssid = "PandoraBox_4ED15A";
String password = "0982983012";
*/
char *ssid = "";
char *password = "";

ESP8266WebServer server ( 80 );

const int led = LED_BUILTIN;
int temp_1, temp_2, temp_3, temp_4;
int count = 0;
String buff = "";
String buff_ssid = "";
String buff_password = "";
byte uart_buff[10];
int buff_index = 0;
int re_connect = 0;


void setup ( void ) {
  pinMode ( led, OUTPUT );
  digitalWrite ( led, 0 );
  Serial.begin ( 115200 );
  delay(100);
  Serial.println ( "" );
  if ( MDNS.begin ( "esp8266" ) ) {
    Serial.println ( "MDNS responder started" );
  }

  server.on ( "/", handleRoot );
  server.on ( "/test.svg", drawGraph );
  server.on ( "/inline", []() {server.send ( 200, "text/plain", "this works as well" );});
  server.onNotFound ( handleNotFound );
  server.begin();
  Serial.println ( "HTTP server started" );
}

void loop ( void ) {
  updata_temp();
  server.handleClient();
  delay(100);
}

