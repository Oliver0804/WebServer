void scan() {
  WiFi.mode(WIFI_STA);
  //WiFi.disconnect();
  int n = WiFi.scanNetworks();
  Serial.println("scan done"); delay(100);
  if (n == 0) {
    Serial.println("no networks found"); delay(100);
  }
  else
  {
    Serial.print(n); delay(10);
    Serial.println(" networks found"); delay(100);
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1); delay(100);
      Serial.print(":"); delay(100);
      Serial.print(WiFi.SSID(i)); delay(100);
      Serial.print("("); delay(100);
      Serial.print(WiFi.RSSI(i)); delay(100);
      Serial.print(")"); delay(100);
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "~"); delay(10);
      delay(100);
    }
  }
}
