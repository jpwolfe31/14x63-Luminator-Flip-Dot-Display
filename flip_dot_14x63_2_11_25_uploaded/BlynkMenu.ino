// For Blynk terminal commands
BLYNK_WRITE(V3) // for reading terminal commands written from Blynk
{
strcpy(cmd_str, param.asStr());  // copy Blynk app terminal input to cmd_str  
// terminal.println(cmd_str); // for testing
// terminal.flush();
// Blynk.run();
}

void menu() // main waterfall command menu
{ 
  // return if command already executed
  if (strcmp(cmd_str, "cleared") == 0) return;
  // get command length used for decoding below
  cmd_length_int = strlen(cmd_str);  // note - does not include '\0'.
  // if not graphic command, clear blankFlag - note holdover from split flaps that take a long time to blank
  // if (cmd_str[0] != '@' && strlen(cmd_str) < 3){blankFlag == 0;}
  // delay if delay set - useful to record display on video
  if (cmdDelay != 0){
    for (int k = 0; k < cmdDelay; k++){delay1s();} 
    }
  // page two commands start first
  // for second line date and time
  // delete change time code??***** esp32 does not like this as it 
  // auto syncs ntp with rtc? from time to time
    if ((terminal_second_line_flag_int == 1) 
     && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
     int c_day_int; 
     int c_month_int; 
     int c_year_int; 
     int c_hour_int; 
     int c_minute_int; 
     int c_second_int;
     char c_day_str[4]; 
     char c_month_str[4]; 
     char c_year_str[4]; 
     char c_hour_str[4]; 
     char c_minute_str[4]; 
     char c_second_str[4];
     if (strlen(cmd_str) != 17) { // note- null character ‘\0’ not counted
       terminal.println();  // add line feed
       terminal.println ("Invalid entry");
       terminal.println();  // add line feed
       terminal_second_line_flag_int = 0; // reset file read flag 
       terminal.flush();
       return;
       }
     sscanf(cmd_str, "%d%*c%d%*c%d%*c%d%*c%d%*c%d", &c_year_int, 
       &c_month_int, &c_day_int, &c_hour_int, &c_minute_int, &c_second_int);
     sscanf(cmd_str, "%2s%*c%2s%*c%2s%*c%2s%*c%2s%*c%2s", c_year_str, 
       c_month_str, c_day_str, c_hour_str, c_minute_str, c_second_str);
     terminal.println();  // add line feed
     terminal.print("Date and time changed to: ");
     terminal.print(c_year_str);
     terminal.print("/");
     terminal.print(c_month_str);
     terminal.print("/");
     terminal.print(c_day_str);
     terminal.print(" ");
     terminal.print(c_hour_str);
     terminal.print(":");
     terminal.print(c_minute_str);
     terminal.print(":");
     terminal.println(c_second_str);
     terminal_second_line_flag_int = 0; // reset file read flag 
     //format for rtc.setTime(30, 24, 15, 17, 1, 2021);  // 17th Jan 2021 15:24:30
     rtc.setTime(c_second_int, c_minute_int, c_hour_int, c_day_int, c_month_int, (c_year_int+2000)); // rtc uses 4 digit year
     terminal.println();  // add line feed
     // Ensure everything is sent
     terminal.flush();
     Blynk.run();
     return;
  }
  // for second line Wifi ssid
    if ((serial_second_line_flag_int == 2) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
     if (strlen(cmd_str) > 15) { // note- null character ‘\0’ not counted
       terminal.println ("Invalid entry");
       terminal.println();  // add line feed
       terminal.flush();
       Blynk.run();
       serial_second_line_flag_int = 0; // reset file read flag 
       return;
       }
     strcpy(ssid, cmd_str);
     terminal.print("Wifi SSID changed to: ");
     terminal.println(ssid); 
     terminal.println();  // add line feed
     terminal.flush();
     Blynk.run();
     EEPROMWrite(); 
     serial_second_line_flag_int = 0; // reset file read flag 
     return;
     }
  // for second line Wifi password
    if ((serial_second_line_flag_int == 3) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
     if (strlen(cmd_str) > 15) { // note- null character ‘\0’ not counted
       terminal.println ("Invalid entry");
       terminal.println();  // add line feed
       terminal.flush();
       Blynk.run();
       serial_second_line_flag_int = 0; // reset file read flag 
       return;
       }
     strcpy(pass, cmd_str);
     terminal.print("Wifi password changed to: ");
     terminal.println(pass); 
     terminal.println();  // add line feed
     terminal.flush();
     Blynk.run();
     EEPROMWrite();
     serial_second_line_flag_int = 0; // reset file read flag 
     return;
     }
  // for second line GMT offset
    if ((serial_second_line_flag_int == 4) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l > 12) || (l < -12)) {
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        terminal.flush();
        Blynk.run();
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(k_GMT_str, cmd_str);
      k_GMT_int = atoi(k_GMT_str);
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      updateRTC();
      // read new time
      updateTime();
      terminal.print("GMT offset changed to: ");
      terminal.println(k_GMT_str); 
      terminal.println("Clock updated"); 
      terminal.println(); // add line feed
      terminal.flush();
      Blynk.run();
      return;
      }
  // for second line enable start hours
    if ((serial_second_line_flag_int == 5) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l < 0) || (l > 24)) {
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        terminal.flush();
        Blynk.run();
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(enableStartHours_str, cmd_str);
      terminal.print("Enable start hour changed to: ");
      terminal.println(enableStartHours_str); 
      enableStartHours_int = atoi(enableStartHours_str);
      terminal.print("Integer is: ");
      terminal.println(enableStartHours_int);  
      terminal.println();  // add line feed
      terminal.flush();
      Blynk.run();
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      return;
      }
  // for second line enable end hours
    if ((serial_second_line_flag_int == 6) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l < 0) || (l > 24)) {
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(enableEndHours_str, cmd_str);
      terminal.print("Enable end hour changed to: ");
      terminal.println(enableEndHours_str); 
      enableEndHours_int = atoi(enableEndHours_str);
      terminal.print("Integer is: ");
      terminal.println(enableEndHours_int);  
      terminal.println();  // add line feed
      terminal.flush();
      Blynk.run();
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      return;
      }  
  // for second line active time
    if ((serial_second_line_flag_int == 7) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l < 1) || (l > 1440)) {  // time is in minutes
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(activeTime_str, cmd_str);
      terminal.print("Active time (minutes) changed to: ");
      terminal.println(activeTime_str); 
      activeTime_int = atoi(activeTime_str); // convert string to integer 
      activeTime_ul = (long)activeTime_int; // and then to unsigned long
      terminal.print("Integer is: ");
      terminal.println(activeTime_int);  
      terminal.println();  // add line feed
      terminal.flush();
      Blynk.run();
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      return;
      }
  // for second line random graphic display
    if ((serial_second_line_flag_int == 8) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l != 0) && (l != 1)) {  // flag is 0 off or 1 on
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(randomGraphicDisplayFlag_str, cmd_str);
      terminal.println();  // randomGraphicDisplayFlag_int = atoi(randomGraphicDisplayFlag_str);
      terminal.print("Random graphic display flag set to: ");
      terminal.print(randomGraphicDisplayFlag_str); 
      if (randomGraphicDisplayFlag_int == 1) {terminal.println (" on");}
      else {terminal.println(" off");}  
      terminal.print("Integer is: ");
      terminal.println(randomGraphicDisplayFlag_int); 
      terminal.println(); // add line feed
      terminal.flush();
      Blynk.run();
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      return;
      }  
// for second line t1 high score
    if ((serial_second_line_flag_int == 9) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
      int l = atoi(cmd_str);
      if ((l < 1) || (l > 999)) {
        terminal.println ("Invalid entry");
        terminal.println();  // add line feed
        serial_second_line_flag_int = 0; // reset file read flag 
        return;
        }
      strcpy(t1_highScore_str, cmd_str);
      terminal.print("Tetris 1 high score changed to: ");
      terminal.println(t1_highScore_str); 
      t1_highScore_int = atoi(t1_highScore_str); // convert string to integer 
      terminal.print("Integer is: ");
      terminal.println(t1_highScore_int);  
      terminal.println();  // add line feed
      terminal.flush();
      Blynk.run();
      EEPROMWrite();
      serial_second_line_flag_int = 0; // reset file read flag
      return;
      }  
  // for second line t2 high score
  if ((serial_second_line_flag_int == 10) && (strcmp(cmd_str, "") != 0)) { // returns 0 if equal
    int l = atoi(cmd_str);
    if ((l < 1) || (l > 999)) {
      terminal.println ("Invalid entry");
      terminal.println();  // add line feed
      serial_second_line_flag_int = 0; // reset file read flag 
      return;
      }
    strcpy(t2_highScore_str, cmd_str);
    terminal.print("Tetris 2 high score changed to: ");
    terminal.println(t2_highScore_str); 
    t2_highScore_int = atoi(t2_highScore_str); // convert string to integer 
    terminal.print("Integer is: ");
    terminal.println(t2_highScore_int);  
    terminal.println();  // add line feed
    terminal.flush();
    Blynk.run();
    EEPROMWrite();
    serial_second_line_flag_int = 0; // reset file read flag
    return;
    }  
  esp_task_wdt_reset();  // refresh watch dog timer
  // end page two commands 
  if (strcmp(cmd_str, "cmd") == 0) { // list commands
    terminal.println("@      - list graphics"); 
    terminal.println("@nn    - display graphic nn"); 
    terminal.println("@ra    - display random graphic"); 
    terminal.println(",__    - display 7x5 10 char string"); 
    terminal.println(",,__   - display 11x6 9 char string"); 
    terminal.println(",,,__  - display 11x8 6 char string"); 
    terminal.println(",,,,__ - display 5x5 10 char string"); 
    terminal.println(",,,,,__- display 5x4 12 num string"); 
    terminal.println(",,,,,,_- display 5x4 3 num sideays");
    terminal.println(";__    - display 7x5 letter string split"); 
    terminal.println(";;_    - display 7x5 scrolling w/setCol"); 
    terminal.println(";;;_   - display 7x5 scrolling w/setCell"); 
    terminal.println("((f    - fast fill display");
    terminal.println("))f    - fast blank display");
    terminal.println("((     - set all cells yellow - std");
    terminal.println("))     - set all cells black - std");
    terminal.println("(ccrr  - set cell yellow"); 
    terminal.println(")ccrr  - set cell black"); 
    terminal.println("(/cc   - set column yellow"); 
    terminal.println(")/cc   - set column black"); 
    terminal.println("(-rr   - set row yellow 0-9"); 
    terminal.println(")-rr   - set row black 0-9");
    terminal.println("dxc    - display 7x5 c on x (0-9)"); 
    terminal.println("exc    - display 11x6 c on x (0-8)");
    terminal.println("fxc    - display 11x8 c on x (0-5)"); 
    terminal.println("((x    - set 7x5 character x yellow (0-9)"); 
    terminal.println("))x    - set 7x5 character x black (0-9)");
    //terminal.println("yxxa     - test alpha display");
    //terminal.println("yxxb     - test alpha display again");
    //terminal.println("yxxc     - test scrolling alpha display (char 0)");
    //terminal.println("yxxg     - test characters by displaying 0-9");
    //terminal.println("yxxhx    - set all characters to x");
    //terminal.println("yxxd     - test scrolling alpha display (char 0-9)");
    terminal.println("rst    - reset controller");
    terminal.println("sig    - report WiFi signal strength"); 
    terminal.println("v      - report version of code");
    terminal.println("c      - Blynk terminal clear");
    terminal.println("clr    - local terminal clear");
    terminal.println("cmd    - list available commands");
    terminal.println("cmdm   - list more commands");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    } // note 50 max terminal width
 if (strcmp(cmd_str, "cmdm") == 0) { // list more commands
    terminal.println("tdr    - report time once");
    terminal.println("tdrc   - report time each minute (toggle)");
    terminal.println("trs    - report/syncs rtc/WiFi times");
    terminal.println("tdon   - time display on");
    terminal.println("tdoff  - time display off");
    terminal.println("tdclr  - clear time display");
    terminal.println("tdset  - set time display");
    terminal.println("tdsec  - time display toggle seconds on/off");
    terminal.println("cdt    - change date and time");  // second page flag 1
    terminal.println("rms    - report motion states (15s)");
    terminal.println("rmot   - report motion detection (toggle)");
    terminal.println("rrel   - report relay on/off (toggle)");
    terminal.println("cat    - cancel active time");
    terminal.println("st     - report op status");
    terminal.println("teep   - test eeprom");
    terminal.println("tled   - test nano leds");
    terminal.println("wdt    - test watchdog timer");
    terminal.println("mcpr0  - mcp reset on (active low)");
    terminal.println("mcpr1  - mcp reset off");
    terminal.println("mcpr2  - mcp reset pulse");
    terminal.println("seta0  - mcp 011 portA set to 0x00");
    terminal.println("seta1  - mcp 011 portA set to 0xFF");
    terminal.println("setb0  - mcp 011 portB set to 0x00");
    terminal.println("setb1  - mcp 011 portB set to 0xFF");
    terminal.println("setc0  - mcp 100 portA set to 0x00");
    terminal.println("setc1  - mcp 100 portA set to 0xFF");
    terminal.println("setd0  - mcp 100 portB set to 0x00");
    terminal.println("setd1  - mcp 100 portB set to 0xFF");
    terminal.println("delxx  - set command delay 0-15 seconds");
    terminal.println("ptxx   - set pulse time (1-50 100us steps)");
    terminal.println("ssxxx  - set column scroll speed (1-999 ms)");
    terminal.println("pnx    - set pulse number (0, 1 or 2)");
    terminal.println("cssid  - change Wifi SSID (eeprom)");  // second page flag 2
    terminal.println("cpass  - change Wifi password (eeprom)");   // second page flag 3
    terminal.println("cgmto  - change GMT offset (eeprom)");  // second page flag 4
    terminal.println("csthr  - change enable start hour (eeprom)");  // second page flag 5
    terminal.println("cenhr  - change enable end hour (eeprom)");  // second page flag 6
    terminal.println("cactm  - change active time minutes (eeprom)");  // second page flag 7
    terminal.println("crgf   - change random graphic flag (eeprom)");  // second page flag 8
    terminal.println("ct1hs  - change t1 high score (eeprom)");  // second page flag 9
    terminal.println("ct2hs  - change t2 high score (eeprom)");  // second page flag 10
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  
  if (cmd_str[0] == '@'){  // if @ "at sign," graphics display command
    char sp[4];
    relayOn(); // turn on relay
    // turn time display off
    timeDisplayFlag_int = 0;
    strcpy(timeDisplayFlag_str, "0");
    clearTimeDisplay();
    lastCommandMillis = currentMillis; // update time out
    if (strcmp(cmd_str, "@ra") == 0){ // returns 0 if equal
      randomGraphicDisplay();
      return;
      }    
    if(strlen(cmd_str) >= 3){ //test to make sure number sent as well
      // note strlen does not count '\0'
      sp[0] = cmd_str[1];
      sp[1] = cmd_str[2];
      sp[2] = '\0';
      graphic_num = atoi(sp); // convert string to integer
      graphicDisplay();
      return;
      }
    else {
      graphicsMenu(); // list avail graphics
      return;
      }
    }
    
  if (strcmp(cmd_str, "tled") == 0){
    // tled - test leds
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    terminal.println();
    terminal.println("Testing Nano ESP32 leds for 12 seconds");
    terminal.println();
    terminal.flush();
    Blynk.run();
    for (int iled = 0; iled <4; iled++){
      //digitalWrite(LED_BUILTIN, HIGH);  // Note also used by Blynk to show link status active high
      digitalWrite(LEDR, LOW);  // active low red 
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDB, HIGH);
      delay1s();
      //digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, LOW); // active low green
      digitalWrite(LEDB, HIGH);
      delay1s();
      //digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDB, LOW); // active low blue
      delay1s();
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, HIGH);
      digitalWrite(LEDB, HIGH); // off
      //digitalWrite(LED_BUILTIN, LOW);
      delay1s();
      }
    delay(50);
    return;
    }
  if (strcmp(cmd_str, "teep") == 0){
    // teep - test eeprom
    terminal.println();
    EEPROMRead();
    //change variables
    terminal.println();
    activeTime_int++;
    sprintf(activeTime_str, "%d", activeTime_int); // convert to string
    terminal.print("activeTime incremented to:  ");
    terminal.print("  ");
    terminal.println(activeTime_str);
    terminal.println();
    EEPROMWrite();  // writes and reads eeprom back
    delay(100);
    terminal.flush();
    Blynk.run();
    delay(50);
    return;
    }
  if (cmd_str[0] == 'p' && cmd_str[1] == 't'){
    // pulseTime - set solenoid pulsetime 0us to 5ms ptxx
    // does not include mcp tranmission times
    char sd[4];
    sd[0] = cmd_str[2];
    sd[1] = cmd_str[3];  // one x causes this to be '/0'
    sd[2] = '\0';
    pulseTime = atoi(sd) * 100; // set pulseTime to xx sent * 100
    if ((cmd_length_int < 3 || cmd_length_int > 4) // check for invald entry
      || (atoi(sd) < 0 || atoi(sd) > 50)) { // limit delay to 5ms
      pulseTime = 1000; // default to 1ms 10 times 100us
      }
    terminal.println(); // add line feed
    terminal.print("pulseTime set to: ");
    terminal.print(pulseTime);
    terminal.print(" us");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (cmd_str[0] == 'p' && cmd_str[1] == 'n'){
    // pulseNumber - set number of pulses to 0, 1 or 2
    char sd[4];
    sd[0] = cmd_str[2];
    sd[1] = '\0';
    pulseNumber = atoi(sd); // set pulseNumber to x sent
    if ((cmd_length_int != 3) // check for invald entry
      || (atoi(sd) < 0 || atoi(sd) > 2)) { // check range 0-2
      pulseNumber = 1; // default to 1 pulse
      }
    terminal.println(); // add line feed
    terminal.print("pulseNumber set to: ");
    terminal.print(pulseNumber);
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "seta0") == 0){
    // set0   - mcp 011 portA  set to 0 i2c1
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    i2c1.beginTransmission(0x23); //starts talking to slave device i2c1 0b000
    i2c1.write(0x00); // IODIRA is 0x00 in Bank0
    i2c1.write(0x00); //  open collector
    i2c1.endTransmission(); //ends communication with slave device
    delay(50);
    return;
    }
  if (strcmp(cmd_str, "seta1") == 0){ // after reset, nano sets each port to 10101010
    // set1   - mcp 011 portA set to 1 i2c1
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    i2c1.beginTransmission(0x23); //starts talking to slave device i2c1 0b000
    i2c1.write(0x00); // IODIRA is 0x00 in Bank0
    i2c1.write(0xFF); // open collector
    i2c1.endTransmission(); //ends communication with slave device
    delay(50);
    return;
    }
  if (strcmp(cmd_str, "setb0") == 0){
    // set0   - mcp 011 portA  set to 0 i2c1
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    i2c1.beginTransmission(0x23); //starts talking to slave device i2c1 0b000
    i2c1.write(0x01); // IODIRA is 0x01 in Bank1
    i2c1.write(0x00); //  open collector
    i2c1.endTransmission(); //ends communication with slave device
    delay(50);
    return;
    }
  if (strcmp(cmd_str, "setb1") == 0){
    // set1   - mcp 011 portA set to 1 i2c1
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    i2c1.beginTransmission(0x23); //starts talking to slave device i2c1 0b000
    i2c1.write(0x01); // IODIRA is 0x01 in Bank1
    i2c1.write(0xFF); //  open collector
    i2c1.endTransmission(); //ends communication with slave device
    delay(50);
    return;
    }
  if (strcmp(cmd_str, "setc0") == 0){
    // set0   - mcp 100 portA  set to 0 i2c1
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    i2c1.beginTransmission(0x24); //starts talking to slave device i2c1 0b000
    i2c1.write(0x00); // IODIRA is 0x00 in Bank0
    i2c1.write(0x00); //  open collector
    i2c1.endTransmission(); //ends communication with slave device
    delay(50);
    return;
    }
  if (strcmp(cmd_str, "setc1") == 0){
    // set1   - mcp 100 portA set to 1 i2c1
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    i2c1.beginTransmission(0x24); //starts talking to slave device i2c1 0b000
    i2c1.write(0x00); // IODIRA is 0x00 in Bank0
    i2c1.write(0xFF); // open collector
    i2c1.endTransmission(); //ends communication with slave device
    delay(50);
    return;
    }
  if (strcmp(cmd_str, "setd0") == 0){
    // set0   - mcp 100 portA  set to 0 i2c1
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    i2c1.beginTransmission(0x24); //starts talking to slave device i2c1 0b000
    i2c1.write(0x01); // IODIRA is 0x01 in Bank1
    i2c1.write(0x00); //  open collector
    i2c1.endTransmission(); //ends communication with slave device
    delay(50);
    return;
    }
  if (strcmp(cmd_str, "setd1") == 0){
    // set1   - mcp 100 portA set to 1 i2c1
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    i2c1.beginTransmission(0x24); //starts talking to slave device i2c1 0b000
    i2c1.write(0x01); // IODIRA is 0x01 in Bank1
    i2c1.write(0xFF); //  open collector
    i2c1.endTransmission(); //ends communication with slave device
    delay(50);
    return;
    }
  if (strcmp(cmd_str, "mcpr0") == 0){
    // mcpr0 - mcp reset on (active low)");
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    digitalWrite(MCPRpin, LOW); // set reset  (active low)
    delay(10);
    return;
    }
  if (strcmp(cmd_str, "mcpr1") == 0){
    // mcpr1 - mcp reset off
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    digitalWrite(MCPRpin, HIGH); // clear reset  (active low)
    delay(10);
    return;
    }
  if (strcmp(cmd_str, "mcpr2") == 0){
    // mcpr2  - mcp reset pulse
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    digitalWrite(MCPRpin, LOW); // set reset  (active low)
    delay(10);
    digitalWrite(MCPRpin, HIGH); // clear reset  (active low)
    delay(10);
    return;
    }
  if (strcmp(cmd_str, "rst") == 0) {  // reset nano
    terminal.println(); // add line feed
    terminal.println("device reset through Blynk terminal");
    // report type of error
    strcpy(error_type_str, "BT");
    nanoError();
    return;
    }
  if ((cmd_str[0] == '(') && (cmd_str[1] == '(') && (cmd_length_int == 2)){ 
    // (( - set all dots yellow
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    fillDisplay();
    return;
    }
  if ((cmd_str[0] == ')') && (cmd_str[1] == ')') && (cmd_length_int == 2)){ 
    // )) - set all dots black
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    blankDisplay();
    return;
    }
  if ((cmd_str[0] == '(') && (cmd_str[1] != '(') && (cmd_length_int == 5)){ 
    // (ccrr - set cell yellow
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    char sc[3];
    sc[0] = cmd_str[1];
    sc[1] = cmd_str[2];
    sc[2] = '\0';
    int columnInput = atoi(sc);
    sc[0] = cmd_str[3];
    sc[1] = cmd_str[4];
    sc[2] = '\0';
    int rowInput = atoi(sc);
    int dotInput = 1; // 1 - yellow, 0 - black
    setCell(columnInput, rowInput, dotInput);
    return;
    }
  if ((cmd_str[0] == ')') && (cmd_str[1] != ')') && (cmd_length_int == 5)){ 
    // )ccrr - set cell black
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    char sc[3];
    sc[0] = cmd_str[1];
    sc[1] = cmd_str[2];
    sc[2] = '\0';
    int columnInput = atoi(sc);
    sc[0] = cmd_str[3];
    sc[1] = cmd_str[4];
    sc[2] = '\0';
    int rowInput = atoi(sc);
    int dotInput = 0; // 1 - yellow, 0 - black
    setCell(columnInput, rowInput, dotInput);
    return;
    }
  if ((cmd_str[0] == '(') && (cmd_str[1] == '/')){ 
    // (/cc - set column yellow
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    char sc[3]; 
    sc[0] = cmd_str[2];
    sc[1] = cmd_str[3];
    sc[2] = '\0';
    int columnInput = atoi(sc);
    int dotInput = 1; // 1 - yellow, 0 - black
    for (int rowInput = 0; rowInput <=13; rowInput++){
      setCell(columnInput, rowInput, dotInput);
      }
    return;
    }
  if ((cmd_str[0] == ')') && (cmd_str[1] == '/')){ 
    // )/cc - set column black
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    char sc[3]; 
    sc[0] = cmd_str[2];
    sc[1] = cmd_str[3];
    sc[2] = '\0';
    int columnInput = atoi(sc);
    int dotInput = 0; // 1 - yellow, 0 - black
    for (int rowInput = 0; rowInput <=13; rowInput++){
      setCell(columnInput, rowInput, dotInput);
      }
    return;
    }
  if ((cmd_str[0] == '(') && (cmd_str[1] == '-')){ 
    // (-rr - set row yellow
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    char sc[3];
    sc[0] = cmd_str[2];
    sc[1] = cmd_str[3];
    sc[2] = '\0';
    int rowInput = atoi(sc);
    int dotInput = 1; // 1 - yellow, 0 - black
    for (int columnInput = 0; columnInput <=62; columnInput++){ 
      setCell(columnInput, rowInput, dotInput);
      }
    return;
    }
  if ((cmd_str[0] == ')') && (cmd_str[1] == '-')){ 
    // )-rr - set row black
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    char sc[3];
    sc[0] = cmd_str[2];
    sc[1] = cmd_str[3];
    sc[2] = '\0';
    int rowInput = atoi(sc);
    int dotInput = 0; // 1 - yellow, 0 - black
    for (int columnInput = 0; columnInput <=62; columnInput++){ 
      setCell(columnInput, rowInput, dotInput);
      }
    return;
    }
  
  
  if (strcmp(cmd_str, "((f") == 0){
    // ((f - fast fill display
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    fastFillDisplay();
    return;
    }
  
  if (strcmp(cmd_str, "))f") == 0){
    // ))f - fast blank display
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    fastBlankDisplay();
    return;
    }
    
  if ((cmd_str[0] == '(') && (cmd_str[1] == '(') && (cmd_length_int == 3)){ 
    // ))x - set 7x5 character x yellow
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    int dot = 1;
    int columnStart;
    char sc[3];
    sc[0] = cmd_str[2];
    sc[1] = cmd_str[3];
    sc[2] = '\0';
    int charInput = atoi(sc);
    switch(charInput){
      case 0: columnStart = 2; break;
      case 1: columnStart = 8; break;
      case 2: columnStart = 14; break;
      case 3: columnStart = 20; break;
      case 4: columnStart = 26; break;
      case 5: columnStart = 32; break;
      case 6: columnStart = 38; break;
      case 7: columnStart = 44; break;
      case 8: columnStart = 50; break;
      case 9: columnStart = 56; break;
      default: columnStart = 0; break;
      }
    for (int columnInput = columnStart; columnInput <= columnStart + 4; columnInput++){
      for (int rowInput = 3; rowInput <=9; rowInput++){
        setCell(columnInput, rowInput, dot);
        }
      }
    return;
    }
   if ((cmd_str[0] == ')') && (cmd_str[1] == ')') && (cmd_length_int == 3)){ 
    // ))x - set 7x5 character x black
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    int dot = 0;
    int columnStart = 0;
    char sc[3];
    sc[0] = cmd_str[2];
    sc[1] = cmd_str[3];
    sc[2] = '\0';
    int charInput = atoi(sc);
    switch(charInput){
      case 0: columnStart = 2; break;
      case 1: columnStart = 8; break;
      case 2: columnStart = 14; break;
      case 3: columnStart = 20; break;
      case 4: columnStart = 26; break;
      case 5: columnStart = 32; break;
      case 6: columnStart = 38; break;
      case 7: columnStart = 44; break;
      case 8: columnStart = 50; break;
      case 9: columnStart = 56; break;
      default: columnStart = 0; break;
      }
    for (int columnInput = columnStart; columnInput <= columnStart + 4; columnInput++){
      for (int rowInput = 3; rowInput <=9; rowInput++){
        setCell(columnInput, rowInput, dot);
        }
      }
    return;
    }
  if ((cmd_str[0] == 'd') && (cmd_length_int == 3)){ 
    // dxc - display 7x5 ascii c on x (0-9)
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    char sch[2];
    sch[0] = cmd_str[1];
    sch[1] = '\0';
    int charNum = atoi(sch);
    char charOut = toupper(cmd_str[2]);
    // toupper - if a lowercase character is processed, the function returns its corresponding uppercase character.  
    // If a non-alphabetic character is processed (e.g. 0-9), the function returns the character sent (0-9).
    // see also tolower()
    int dotInput;
    get_char_fd_array_7x5(charOut); // populates fd_array 7x5 with charOut
    // display font
    for (int columnInput = 0; columnInput <= 4; columnInput++){ // font is 5 by 7
      for (int rowInput = 0; rowInput <= 6; rowInput++){
        dotInput = fd_array_7x5[columnInput][rowInput]; // get dot value
        // 1 space between chars.  Also start at column 2 and row 3
        setCell(columnInput + 2 + (charNum * (5+1)), (rowInput + 3), dotInput); // adjust columns by charNum
        }  
      }
      return;
    }
  if ((cmd_str[0] == 'e') && (cmd_length_int == 3)){
    // exc - display 11x6 ascii c on x (0-8)
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    char sch[2];
    sch[0] = cmd_str[1];
    sch[1] = '\0';
    int charNum = atoi(sch);
    char charOut = toupper(cmd_str[2]);
    int dotInput;
    get_char_fd_array_11x6(charOut); // populates fd_array 11x8 with charOut
    // display font
    for (int columnInput = 0; columnInput <= 5; columnInput++){ // font is 11 by 6
      for (int rowInput = 0; rowInput <= 10; rowInput++){
        dotInput = fd_array_11x6[columnInput][rowInput]; // get dot value
        // 1 spaces between chars.  Also start at column 1 and row 2
        setCell(columnInput + 1 + (charNum * (6+1)), (rowInput + 2 ), dotInput); // adjust columns by charNum
        }  
      }
      return;
    }
  if ((cmd_str[0] == 'f') && (cmd_length_int == 3)){ 
    // exc - display 11x8 ascii c on x (0-5)
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    char sch[2];
    sch[0] = cmd_str[1];
    sch[1] = '\0';
    int charNum = atoi(sch);
    char charOut = toupper(cmd_str[2]);
    int dotInput;
    get_char_fd_array_11x8(charOut); // populates fd_array 11x8 with charOut
    // display font
    for (int columnInput = 0; columnInput <= 7; columnInput++){ // font is 11 by 8
      for (int rowInput = 0; rowInput <= 10; rowInput++){
        dotInput = fd_array_11x8[columnInput][rowInput]; // get dot value
        // 2 spaces between chars.  Also start at column 3 and row 2
        setCell(columnInput + 3 + (charNum * (8+2)), (rowInput + 2 ), dotInput); // adjust columns by charNum
        }  
      }
      return;
    }
  if (cmd_str[0] == ',' && cmd_str[1] != ','){  // if one comma, 7x5 letter string command - up to 10 letters
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    int strLength = strlen(cmd_str);  // includes '\0'
    blankDisplay();
    //clearTimeDisplay();  // turn time display off
    for (int charNum = 0; charNum <= 9; charNum ++){
      if (charNum <= (strLength - 2)){  // [0] is ',' and subtract out '\0' too
        displayCharacter_7x5(charNum, toupper(cmd_str[charNum + 1])); // 0 is ','
        }
      else{
        displayCharacter_7x5(charNum, ' '); // fill blanks
        }
      delay25ms();
      }
    return;
    }  
  if (cmd_str[0] == ',' && cmd_str[1] == ',' && cmd_str[2] != ',') {  // if two commas, 11x6 letter string command - up to 9 letters
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    int strLength = strlen(cmd_str);  // includes '\0'
    blankDisplay();
    //clearTimeDisplay();  // turn time display off
    for (int charNum = 0; charNum <= 8; charNum ++){
      if (charNum <= (strLength - 3)){  // [0] and [1] are ',' and subtract out '\0' too
        displayCharacter_11x6(charNum, toupper(cmd_str[charNum + 2])); // 0 and 1 are ','
        }
      else{
        displayCharacter_11x6(charNum, ' '); // fill blanks
        }
      delay25ms();
      }
    return;
    }  
  if (cmd_str[0] == ',' && cmd_str[1] == ',' && cmd_str[2] == ',' && cmd_str[3] != ',') {  // if three commas, 11x8 letter string command - up to 6 letters
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    int strLength = strlen(cmd_str);  // includes '\0'
    blankDisplay();
    //clearTimeDisplay();  // turn time display off
    for (int charNum = 0; charNum <= 5; charNum ++){
      if (charNum <= (strLength - 4)){  // 0 and 1 and 2 are ',' and subtract out '\0' too
        displayCharacter_11x8(charNum, toupper(cmd_str[charNum + 3])); // 0, 1 and 2 are ','
        }
      else{
        displayCharacter_11x8(charNum, ' '); // fill blanks
        }
      delay25ms();
      }
    return;
    }  
if (cmd_str[0] == ',' && cmd_str[1] == ',' && cmd_str[2] == ',' && cmd_str[3] == ',' && cmd_str[4] != ','){  // if four commas, 5x5 letter string command - up to 10 letters
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    int strLength = strlen(cmd_str);  // includes '\0'
    blankDisplay();
    //clearTimeDisplay();  // turn time display off
    for (int charNum = 0; charNum <= 9; charNum ++){
      if (charNum <= (strLength - 5)){  // [0] to [3] is ',' and subtract out '\0' too
        displayCharacter_5x5(charNum, toupper(cmd_str[charNum + 4])); // [0] to [3] are ','
        }
      else{
        displayCharacter_5x5(charNum, ' '); // fill blanks
        }
      delay25ms();
      }
    return;
    }  
if (cmd_str[0] == ',' && cmd_str[1] == ',' && cmd_str[2] == ',' && cmd_str[3] == ',' && cmd_str[4] == ',' && cmd_str[5] != ',' ){  // if five commas, 5x5 letter string command - up to 10 letters
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    int strLength = strlen(cmd_str);  // includes '\0'
    blankDisplay();
    //clearTimeDisplay();  // turn time display off
    for (int charNum = 0; charNum <= 11; charNum ++){
      if (charNum <= (strLength - 6)){  // [0] to [4] is ',' and subtract out '\0' too
        displayCharacter_5x4(charNum, toupper(cmd_str[charNum + 5])); // [0] to [4] are ','
        }
      else{
        displayCharacter_5x4(charNum, ' '); // fill blanks
        }
      delay25ms();
      }
    return;
    }  
if (cmd_str[0] == ',' && cmd_str[1] == ',' && cmd_str[2] == ',' && cmd_str[3] == ',' && cmd_str[4] == ',' && cmd_str[5] == ',' ){  // if six commas, 5x4 sideways letter string command - up to 3 letters
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    int strLength = strlen(cmd_str);  // includes '\0'
    blankDisplay();
    //clearTimeDisplay();  // turn time display off
    for (int charNum = 0; charNum <= 2; charNum ++){
      if (charNum <= (strLength - 7)){  // [0] to [5] is ',' and subtract out '\0' too
        // sideways
        displayCharacter_5x4s(charNum, toupper(cmd_str[charNum + 6]), 2); // [0] to [5] are ',' // start on column 2 
        }
      else{
        // sideways
        displayCharacter_5x4s(charNum, ' ', 2); // fill blanks start on column 2
        }
      delay25ms();
      }
    return;
    }  
if (cmd_str[0] == ';' && cmd_str[1] != ';'){  // if semicolon, 7x5 letter string command split words
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    //clearTimeDisplay();  // turn time display off
    char* cmd_chopped = cmd_str + 1; // eliminate leading ';' 
    strcpy(input_str, cmd_chopped); 
    displaySplitWords_7x5(); // split words into lines and display
    return;
    }  

if (cmd_str[0] == ';' && cmd_str[1] == ';' && cmd_str[2] != ';')  { 
  // scrolling with setColumn
  char* cmd_chopped = cmd_str + 2; // eliminate 2 leading ';' 
  strcpy(input_str, cmd_chopped);
  scrolling_7x5_1(); // call function - scrolls global input_str
  return;
  }  

if (cmd_str[0] == ';' && cmd_str[1] == ';' && cmd_str[2] == ';') { 
  // scrolling with setCell
  char* cmd_chopped = cmd_str + 3; // eliminate 3 leading ';' 
  strcpy(input_str, cmd_chopped);
  scrolling_7x5_2(); // call function - scrolls global input_str
  return;
  }  
  
if (cmd_str[0] == 's' && cmd_str[1] == 's'){
    // scrollDelay 0 to 999ms ssxxx
    char ss[6];
    ss[0] = cmd_str[2];
    ss[1] = cmd_str[3]; // one x causes this to be '/0'
    ss[2] = cmd_str[4]; // two x causes this to be '/0'
    ss[3] = '\0';
    scrollDelay = atoi(ss); // set scrollDelay to xxx sent
    if ((cmd_length_int < 3 || cmd_length_int > 5) // check for invald entry
      || (atoi(ss) < 0 || atoi(ss) > 999)) { // limit speed to 0 to 999ms
      scrollDelay = 100; // default to 100ms
      }
    terminal.println(); // add line feed
    terminal.print("scrollDelay set to: ");
    terminal.print(scrollDelay);
    terminal.print(" ms");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (cmd_str[0] == 'd' && cmd_str[1] == 'e' 
    && cmd_str[2] == 'l'){ // delxx - set command delay 0-15 seconds 
    char sd[4];
    sd[0] = cmd_str[3];
    sd[1] = cmd_str[4];  // one x causes this to be '/0'
    sd[2] = '\0';
    cmdDelay = atoi(sd); // set delay to xx sent
    if ((cmd_length_int < 4 || cmd_length_int > 5) // check for invald entry
      || (atoi(sd) < 0 || atoi(sd) > 15)) { // limit delay to 15 seconds
      cmdDelay = 0;
      }
    terminal.println(); // add line feed
    terminal.print("Command delay set to: ");
    terminal.print(cmdDelay);
    terminal.print(" seconds");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "tdon") == 0) { // time display on
    timeDisplayFlag_int = 1;
    strcpy(timeDisplayFlag_str, "1");
    terminal.println("time display on");
    terminal.println();
    EEPROMWrite();
    setTimeDisplay();
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "tdoff") == 0) { // time display off
    timeDisplayFlag_int = 0;
    strcpy(timeDisplayFlag_str, "0");
    terminal.println("time display off");
    terminal.println();
    EEPROMWrite();
    clearTimeDisplay();
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
    } 
  if (strcmp(cmd_str, "tdset") == 0) { // set time display - note - likely not neded by itself
    setTimeDisplay();
    delay500ms();
    return;
    } 
  if (strcmp(cmd_str, "tdsec") == 0) {  // toggle seconds on flag
    if (secondsDisplayOn == 1) {secondsDisplayOn = 0;}
    else {secondsDisplayOn = 1;}
    terminal.print("secondsDisplayOn flag = ");
    terminal.println(secondsDisplayOn);
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
  }
    if (strcmp(cmd_str, "tdclr") == 0) { // clear time display - note - likely not needed by itself
    relayOn(); // turn on relay
    clearTimeDisplay();
    delay500ms();
    return;
    } 
  if (strcmp(cmd_str, "cdt") == 0) { // change date and time
     terminal.println(); // add line feed
     terminal.println("Enter date and time (yy/mm/dd hh:mm:ss)");
     terminal_second_line_flag_int = 1;  // set flag for next line read
     terminal.println(); // add line feed
     terminal.flush();
     Blynk.run();
     return;
    }
  if (strcmp(cmd_str, "tdr") == 0) {  // report time
    // report time data
    terminal.println(); // add line feed
    terminal.print("nano rtc ");
    // (String) returns time with specified format 
    terminal.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));   
    terminal.println();
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "tdrc") == 0) {  // report time
    // report time data
    terminal.println(); // add line feed
    terminal.println("nano rtc reporting each minute");
    terminal.print("nano rtc ");
    // (String) returns time with specified format 
    terminal.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));   
    terminal.println();
    Blynk.run();
    // then report time data every minute
    // toggle time reprot flag
    if (printLocalTimeFlag == 0) {
      printLocalTimeFlag = 1;
      }
    else printLocalTimeFlag = 0;
    return;
    }
  if (strcmp(cmd_str, "trs") == 0) {  // report and sync rtc and current wifi times
    //get time data
    terminal.println(); // add line feed
    updateTime();
    terminal.print("Rtc time is ");
    terminal.println(time_str);
    // update RTC
    updateRTC();
    // read new time
    terminal.println("WiFi and rtc time synced");
    updateTime();
    terminal.print("WiFi and rtc time are ");
    terminal.println(time_str);
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "c") == 0) { // Clear the terminal content    // note - returns 0 if equal
    terminal.clear();  // this is the remote clear.  type clr for a local clear.
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cssid") == 0) { // change Wifi SSID
    terminal.println("Enter new Wifi SSID: ");
    serial_second_line_flag_int = 2;  // set flag for next WifI SSID line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cpass") == 0) { // change Wifi password
    terminal.println("Enter new Wifi password: ");
    serial_second_line_flag_int = 3;  // set flag for next WifI password line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cgmto") == 0) { // change GMT offset
    terminal.println("Enter new GMT offset: ");
    serial_second_line_flag_int = 4;  // set flag for next GMT offset line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "csthr") == 0) { // change enable start hour
    terminal.println("Enter new enable start hour: ");
    serial_second_line_flag_int = 5;  // set flag for next enable start hour line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "cenhr") == 0) { // change enable end hour
    terminal.println("Enter new enable end hour: ");
    serial_second_line_flag_int = 6;  // set flag for next enable end hour line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
 if (strcmp(cmd_str, "cactm") == 0) { // change active time
    terminal.println("Enter new active time (minutes): ");
    serial_second_line_flag_int = 7;  // set flag for next active time line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
 if (strcmp(cmd_str, "crgf") == 0) { // change random graphic display flag
    terminal.println("Set random graphic flag - 0 off 1 on: ");
    serial_second_line_flag_int = 8;  // set flag for next active time line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "ct1hs") == 0) { // change t1 high score
    terminal.println("Enter new tetris 1 high score: ");
    serial_second_line_flag_int = 9;  // set flag for next active time line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "ct2hs") == 0) { // change t2 high score
    terminal.println("Enter new tetris 2 high score: ");
    serial_second_line_flag_int = 10;  // set flag for next active time line read
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "v") == 0) {  // report version
    terminal.println(); // add line feed
    terminal.print("Version of Controller Code is: ");
    terminal.println(version_str);
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "sig") == 0) {  // report wifi signal strength
    rssi = WiFi.RSSI();
    terminal.println(); // add line feed
    terminal.print("Signal strength (RSSI) is ");
    terminal.print(rssi);
    terminal.println(" dBm");
    terminal.println(); // add line feed
    terminal.flush();
    Blynk.run();
    return;
    }
  if (strcmp(cmd_str, "wdt") == 0) {  // check wdt function
    unsigned int t;
    terminal.println("\nWatchdog Test - run 18 seconds with a WDTimer.clear()\n");
    //Serial.println("\nWatchdog Test - run 18 seconds with a WDT.clear()\n");
    for (t = 1; t <= 18; ++t) {
      esp_task_wdt_reset();  // refresh wdt - before it loops
      delay(950);
      terminal.print(t);
      terminal.print(".");
      terminal.flush();
      Blynk.run(); 
      }
    terminal.println("\n\nWatchdog Test - free run wait for reset at 8 seconds\n");
    for (t = 1; t >= 1; ++t) {
      delay(950);
      terminal.print(t);
      terminal.print(".");
      terminal.flush();
      Blynk.run();
      }
    return;
    }   
  if (strcmp(cmd_str, "cat") == 0) {  //  cancel active time in 10 seconds
    lastMotionMillis = currentMillis - (activeTime_ul * 60000) + 10000;
    lastCommandMillis = currentMillis - (activeTime_ul * 60000) + 10000;
    return;
    }
  if (strcmp(cmd_str, "rms") == 0) {  //  report motion state (15s)
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    terminal.println("Motion State for 15 seconds:");
    for (int j = 0; j < 15; j++){
      motionState = digitalRead(motionPin);  // active high
      terminal.print("  ");
      terminal.println(motionState);
      terminal.flush();  // output to terminal immediately
      //Blynk.run();      
      delay1s();
      //esp_task_wdt_reset();  // refresh watch dog timer
      }
    return;
    }
    
  if (strcmp(cmd_str, "rmot") == 0) {  //  report motion status
    relayOn(); // turn on relay
    lastCommandMillis = currentMillis; // update time out
    if (motionReportFlag == 0){motionReportFlag = 1;}
    else motionReportFlag = 0;
    return;
    }
   
  if (strcmp(cmd_str, "rrel") == 0) {  //  report relay status
    if (relayReportFlag == 0){relayReportFlag = 1;}
    else relayReportFlag = 0;
    return;
    }
  if (strcmp(cmd_str, "st") == 0) {
    terminal.print("uptime = ");
    terminal.print(millis() / 60000);
    terminal.println(" minutes");
    terminal.print("motionState = ");
    terminal.println(motionState);
    terminal.print("motionWindowFlag = ");
    terminal.println(motionWindowFlag);
    terminal.print("redLedState = ");
    terminal.println(redLedState);
    terminal.print("blueLedState = ");
    terminal.println(blueLedState);
    terminal.print("relayState = ");
    terminal.println(relayState);
    terminal.print("cmdDelay = ");
    terminal.print(cmdDelay);
    terminal.println(" seconds");
    terminal.flush();  // output to terminal immediately
    terminal.print("hour_int = ");
    terminal.println(hour_int);
    terminal.print("minute_int = ");
    terminal.println(minute_int);
    currentMillis = millis();
    terminal.print("remaining active time motion(sec) = ");
    // activeTime is in minutes
    if (lastMotionMillis != 0){ // note - if no motion, then lastMotionMillis will be 0
      // Note - min used to avoid negative number
      terminal.println(((activeTime_ul * 60000)- min((currentMillis - lastMotionMillis), (activeTime_ul * 60000)))/1000);
      }
    else {terminal.println(0);}
    terminal.print("remaining active time command(sec) = "); // above calcuation returns seconds as /1000 - 10 min is 600 sec
    terminal.println(((activeTime_ul * 60000)- min((currentMillis - lastCommandMillis), (activeTime_ul * 60000)) )/1000);
    terminal.print("ssid = ");
    terminal.println(ssid);
    terminal.print("pass = ");
    terminal.println(pass);
    terminal.print("GMT offset = ");
    terminal.println(k_GMT_int);
    terminal.print("enableStartHours = ");
    terminal.println(enableStartHours_int);
    terminal.print("enableEndHours = ");
    terminal.println(enableEndHours_int);
    terminal.print("activeTime = ");
    terminal.print(activeTime_int);
    terminal.println(" minutes");
    terminal.print("randomGraphicDisplayFlag = ");
    terminal.println(randomGraphicDisplayFlag_int);
    terminal.print("timeDisplayFlag = ");
    terminal.println(timeDisplayFlag_int);
    terminal.print("t1_highScore = ");
    terminal.println(t1_highScore_int);
    terminal.print("t2_highScore = ");
    terminal.println(t2_highScore_int);
    terminal.println(); // add line
    terminal.flush();
    Blynk.run();
    return;
    }
  
// end of command waterfall
}

// for iphone blinking link green LED on Blynk app - runs every second to indicate link
// also blinks Nano ESP32 built in yellow LED
/*void blinkLedWidget()   // for testing
{
if (led1.getValue()) {
  led1.off();
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //Serial.println("LED on V1: off");  // Note - built in LED controlled by pin 6
  } else {
    led1.on();
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    //Serial.println("LED on V1: on");
  }
}
*/

// for tetris buttons on Blynk app
BLYNK_WRITE(V4)  // left
{
LEFT.valueRead = param.asInt(); // assigning incoming value from pin V4 to a variable
}
BLYNK_WRITE(V5)  // right
{
RIGHT.valueRead = param.asInt(); // assigning incoming value from pin V5 to a variable
}
BLYNK_WRITE(V6)  // rotate CCW{
{
ROTATE_CCW.valueRead = param.asInt(); // assigning incoming value from pin V6 to a variable
}
BLYNK_WRITE(V7)  // rotate CW
{
ROTATE_CW.valueRead = param.asInt(); // assigning incoming value from pin V6 to a variable
}
BLYNK_WRITE(V8)  // drop
{
DROP.valueRead = param.asInt(); // assigning incoming value from pin V7 to a variable
}
BLYNK_WRITE(V9)  // pause
{
PAUSE.valueRead = param.asInt(); // assigning incoming value from pin V8 to a variable
}

void displayCharacter_11x6(int charNum, char charOut)
{
// for 11x6 font
int dotInput;
get_char_fd_array_11x6(charOut); // populates fd_array with charOut
// diplay font
for (int columnInput = 0; columnInput <= 5; columnInput++){ // font is 11 by 6
  for (int rowInput = 0; rowInput <= 10; rowInput++){
    dotInput = fd_array_11x6[columnInput][rowInput]; // get dot value
    // 1 spaces between chars.  Also start at column 1 and row 2
    setCell(columnInput + 1 + (charNum * (6+1)), (rowInput + 2 ), dotInput); // adjust columns by charNum
    }  
  }
return;
}

void blankDisplay()
{
int dotInput = 0;
for (int columnInput = 0; columnInput <= 62; columnInput++){ // 63 columns
  for (int rowInput = 0; rowInput <=13; rowInput++){ // 14 rows
    setCell(columnInput, rowInput, dotInput);
    }
  delay(25);  // wdt reset not required in such a quick execution
  }
}

void fillDisplay()
{
int dotInput = 1;
for (int columnInput = 0; columnInput <= 62; columnInput++){ // 63 columns
  for (int rowInput = 0; rowInput <=13; rowInput++){ // 14 rows
    setCell(columnInput, rowInput, dotInput);
    }
  delay(25);  // wdt reset not required in such a quick execution
  }
}

void fastBlankDisplay()
{
int rowStates = 0b0000000000000;  // sb 14
for (int column = 0;  column <= 62; column++){
  setColumnGroup(column, rowStates);
  }
}

void fastFillDisplay()
{
int rowStates = 0b11111111111111;  // sb 14
for (int column = 0;  column <= 62; column++){
  setColumnGroup(column, rowStates);
  }
}

