
void updata_temp() {

  while (Serial.available()) {
    char inChar = (char)Serial.read();
    Serial.print(inChar);
    if (inChar == ',' && count == 0) {
      temp_1 = buff.toInt();
      //Serial.println(temp_1);
      count++;
      buff = "";
    }
    else if (inChar == ',' && count == 1) {
      temp_2 = buff.toInt();
      //Serial.println(temp_2);
      count++;
      buff = "";
    }
    else if (inChar == ',' && count == 2) {
      temp_3 = buff.toInt();
      //Serial.println(temp_3);
      count++;
      buff = "";
    }
    else if (inChar == ',' && count == 3) {
      temp_4 = buff.toInt();
      //Serial.println(temp_4);
      count = 0;
      buff = "";
    }
    else if (inChar == '@') {
      count = 0;
    }
    else if (inChar == '?') {
      Serial.print ("SSID : ");
      Serial.println ( buff_ssid.c_str() );
      Serial.print ("PASSWROD : ");
      Serial.println (buff_password.c_str()  );
    }
    else if (inChar == '*') {
      scan();
    }
    else if (inChar == '$') {
      buff_ssid = buff;
      buff = "";
    }
    else if (inChar == '%') {
      buff_password = buff;
      buff = "";
    }
    else if (inChar == '&') {
        Serial.println ( WiFi.localIP() );
    }
    else if (inChar == '^') {
      if (buff_ssid != "" && buff_password != "") {
        WiFi.begin ( buff_ssid.c_str(), buff_password.c_str() );
        // Wait for connection
        while ( WiFi.status() != WL_CONNECTED ) {
          digitalWrite ( led, !digitalRead(led) );
          delay ( 100 );
          Serial.print ( "." );
        }
        Serial.println ( "" );
        Serial.print ( "Connected to " );
        Serial.println ( buff_ssid.c_str() );
        Serial.print ( "IP address:" );
        Serial.println ( WiFi.localIP() );
      } else {
        Serial.println ( "pls input ssid password" );
      }
    }
    else {
      buff = buff + inChar;
    }
  }

}

