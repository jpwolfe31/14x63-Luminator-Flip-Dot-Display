// Arduino Nano-ESP32 Program for controller that operates 
//   3 Luminator 14 by 21 flip-dot displays 

// for 3 boards, the power supply should be 15 volts at 3 amps

// for tetris
// ***** due to an apparent bug in the Arduino IDE, all tetris struct globals must 
//   appear at the start of the code before any includes  
const unsigned t1_nRows = 30; // changed from 16 to 30 number of rows - need 6 for preview
const unsigned t1_nColumns = 16; // only 14 used
const byte t1_width = 10;  // width of tetris board - number of columns
const unsigned t2_nRows = 29; // t2 has larger bricks- each row is 2x - need 6 for preview 
// 4 spaces left plus 12 space for preview plus 44 spaces for board plus 3 spaces bottom 
//    equals 63 (3 times 21)
const unsigned t2_nColumns = 15; // only 7 of these actually used
const byte t2_width = 7;  // width of tetris board - number of columns - 1/2 actual width due to 2x larger bricks

// for Blynk push buttons V4-V8  
int sw4Value = 0;  // left
int sw5Value = 0;  // right
int sw6Value = 0;  // rotate CCW
int sw7Value = 0;  // rotate CW
int sw8Value = 0;  // drop
int sw9Value = 0;  // pause 

unsigned int t1_screen[t1_nRows];  // number of rows
unsigned int t2_screen[t2_nRows];  // number of rows

byte row = 0;

int t1_grid0[t1_nRows][t1_nColumns]; // rows and columns reversed since flip dot display is being used sideways
int t1_grid1[t1_nRows][t1_nColumns];
int t2_grid0[t2_nRows][t2_nColumns]; 
int t2_grid1[t2_nRows][t2_nColumns];

typedef struct {
  int valueRead;  // value sent by Blynk
  int currState;  // the current reading from the input pin
  int lastState;  // the previous reading from the input pin
  unsigned long lastChanged; // not used, as Blynk debounces inputs
  unsigned long lastDebounce; // not used
} Button;

Button LEFT   = {sw4Value, LOW, LOW, 0, 0}; // revised to delete pin number 
Button RIGHT  = {sw5Value, LOW, LOW, 0, 0}; // and add swxvalue passed by Blynk.run()
Button ROTATE_CCW = {sw6Value, LOW, LOW, 0, 0};
Button ROTATE_CW = {sw7Value, LOW, LOW, 0, 0};
Button DROP   = {sw8Value, LOW, LOW, 0, 0};
Button PAUSE  = {sw9Value, LOW, LOW, 0, 0};
const unsigned long debounceDelay = 50;  // not used, as Blynk debounces inputs
int pauseFlag = 0;
int dropFlag = 0;

byte lastBricks[4];
byte randomBrick;
int missedBrickCnt[7];
unsigned int score;
unsigned int lines;
unsigned int removed;

typedef struct {
  int x, y;
} Vertex;

typedef struct {
  Vertex vertex[4];
} Shape;

typedef struct {
  Shape shape[4];
} BrickDef;

// these brick definitions rotate cw on the flip dot display
// -1 on the y axis extends a brick one space off the board to the left at the start
// -2 is not used as it interferes with the preview brick draw
BrickDef brickdefs[7] = {  
  { // I
    .shape = {
      { .vertex = {{-1, 0}, {0, 0}, {1, 0}, {2, 0}} }, // same
      { .vertex = {{0, 2}, {0, 1}, {0, 0}, {0, -1}} }, // like current tetris 
      { .vertex = {{-1, 0}, {0, 0}, {1, 0}, {2, 0}} }, // same
      { .vertex = {{1, 2}, {1, 1}, {1, 0}, {1, -1}} }  // like current tetris
    }
  },
  { // O
    .shape = {
      { .vertex = {{0, 0}, {0, 1}, {1, 0}, {1, 1}} },  
      { .vertex = {{0, 0}, {0, 1}, {1, 0}, {1, 1}} },
      { .vertex = {{0, 0}, {0, 1}, {1, 0}, {1, 1}} },
      { .vertex = {{0, 0}, {0, 1}, {1, 0}, {1, 1}} }
    }
  },
  { // J
    .shape = {
      { .vertex = {{0, 0}, {1, 0}, {2, 0}, {2, 1}} },
      { .vertex = {{1, 1}, {1, 0}, {1, -1}, {0, 1}} },
      { .vertex = {{0, -1}, {0, 0}, {1, 0}, {2, 0}} },
      { .vertex = {{1, -1}, {1, 0}, {1, 1}, {2, -1}} }
    }
  },
  { // L
    .shape = {
      { .vertex = {{0, 1}, {0, 0}, {1, 0}, {2, 0}} },
      { .vertex = {{0, -1}, {1, -1}, {1, 0}, {1, 1}} },
      { .vertex = {{0, 0}, {1, 0}, {2, 0}, {2, -1}} },
      { .vertex = {{1, -1}, {1, 0}, {1, 1}, {2, 1}} }
    }
  },
  { // S
    .shape = {
      { .vertex = {{2, 0}, {1, 0}, {1, 1}, {0, 1}} },
      { .vertex = {{1, 1}, {1, 0}, {0, 0}, {0, -1}} },
      { .vertex = {{0, 0}, {1, 0}, {1, -1}, {2, -1}} },
      { .vertex = {{2, 1}, {2, 0}, {1, 0}, {1, -1}} }
    }
  },
  { // Z
    .shape = {
      { .vertex = {{0, 0}, {1, 0}, {1, 1}, {2, 1}} },
      { .vertex = {{1, -1}, {1, 0}, {0, 0}, {0, 1}} },
      { .vertex = {{2, 0}, {1, 0}, {1, -1}, {0, -1}} },
      { .vertex = {{1, 1}, {1, 0}, {2, 0}, {2, -1}} }
    }
  },
  { // T
    .shape = {
      { .vertex = {{0, 0}, {1, 0}, {2, 0}, {1, 1}} },
      { .vertex = {{1, -1}, {1, 0}, {1, 1}, {0, 0}} },
      { .vertex = {{0, 0}, {1, 0}, {2, 0}, {1, -1}} },
      { .vertex = {{1, -1}, {1, 0}, {1, 1}, {2, 0}} }
    }
  }
};

Vertex down = {0, 1};
Vertex left = {-1, 0};
Vertex right = {1, 0};
Vertex identity = {0, 0};

typedef struct {
  byte id;
  byte rotation;
  Vertex location;
} FallingBrick;

// end of tetris
 
// Template ID, Device Name and Auth Token are provided by Blynk
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "XXXXXXXX"
#define BLYNK_TEMPLATE_NAME "Flip Dot"
#define BLYNK_AUTH_TOKEN "XXXXXXXX" // not used in agent, just uploaded app
#define BLYNK_FIRMWARE_VERSION "1.0.1"
char auth[] = BLYNK_AUTH_TOKEN;
char version_str[32] = "V.110924";  // month/day/year

// for eeprom emulation in nano ESP32 flash memory
// esp32 EEPROM appears to retain its value between program uploads
// if the EEPROM is written, then there is a written signature at address 0
// update signature when eeprom data structure is changed
#include <EEPROM.h>
#define EEPROM_SIZE 1000  // This is 1k Byte
uint16_t storedAddress = 0;
int signature;
const int WRITTEN_SIGNATURE = 0xabcdabc1;
char ssid[20] = "XXXXXXXX";
char pass[20] = "XXXXXXXX"; // Set password to "" for open networks.
char k_GMT_str[20] = "-7"; //-8 for California ST and -7 for California DST
char activeTime_str[20] = "10";  
char enableStartHours_str[20] = "7";  // start motion function at 7 am
char enableEndHours_str[20] = "20";  // end motion function at 8 pm
char randomGraphicDisplayFlag_str[20] = "0";  // off 
char timeDisplayFlag_str[20] = "0"; // default is time display is off
char t1_highScore_str[20] = "1";  
char t2_highScore_str[20] = "1";  
int activeTime_int;
int randomGraphicDisplayFlag_int;
int timeDisplayFlag_int; 
int k_GMT_int;
unsigned long activeTime_ul;
int enableStartHours_int;
int enableEndHours_int;
int t1_highScore_int;  
int t2_highScore_int;  
struct memory  // create data structure for easier EEPROM reads/writes
{ // note - all strings - max length 19
  int eeprom_signature;
  char eeprom_ssid[20];
  char eeprom_pass[20]; 
  char eeprom_k_GMT[20];
  char eeprom_enableStartHours[20];
  char eeprom_enableEndHours[20];
  char eeprom_activeTime[20];
  char eeprom_randomGraphicDisplayFlag[20];
  char eeprom_timeDisplayFlag[20];
  char eeprom_t1_highScore[20];
  char eeprom_t2_highScore[20];
} flash;

// for wifi and Blynk
#include <SPI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <Wire.h>
TwoWire i2c1 = TwoWire(0);
TwoWire i2c2 = TwoWire(1);

// for time and clock
#include "time.h"
#include <ESP32Time.h>
ESP32Time rtc(0*3600);
const long  gmtOffset_sec = 3600 * -8; // Pacific Standard Time
const int   daylightOffset_sec = 3600;
const char* ntpServer = "pool.ntp.org";
struct tm timeinfo;

long rssi;
char rssi_str[16];

// for date and time functions
char second_str[20];
int second_int;
char minute_str[20];
int minute_int;
char hour_str[20];
int hour_int;
char days_str[20];
int days_int;
char months_str[20];
int months_int;
char years_str[20];
int years_int;
char date_str[20]; // date string
char time_str[20]; // time string
int seconds_tick = 0;
int prior_days_int = 0;
int secondsDisplayOn = 1; // blinking : - 0 is off, 1 is on
int printLocalTimeFlag = 0; // for printing ntp and local time for divergence ***** still needs work - likely not needed
// note - to date have not seen a divergence between local time and ntp time

// for error logging and resets
char error_type_str[32];
char error_type_display_str[32];
// set the reset flag on error and clear the reset flag when restarting
int nano_reset_flag_int = 0;

// for watch dog timer
#include <esp_task_wdt.h>
#define WDT_TIMEOUT 8 // 3, 8 and 16  seconds tested

// for Blynk
// led V1 is the LED on the phone attached to Virtual Pin 1
WidgetLED led1(V1);
// Attach virtual serial terminal to Virtual Pin V3
WidgetTerminal terminal(V3);
// for reading a second input line in the Blynk terminal
int terminal_second_line_flag_int = 0;

// for USB Serial and Blynk commands
char cmd_str[640];
int cmd_length_int = 0;
int cmd_flag_int = 0;
int serial_second_line_flag_int = 0;

// for manual timers
unsigned long currentMillis;
unsigned long previousMillis_Blynk = 0;
unsigned long previousMillis_blinkLedWidget = 0; 
unsigned long previousMillis_nanoReset = 0; 
unsigned long previousMillis_updateTimeDisplay = 0;
unsigned long previousMillis_swWidget = 0; 
unsigned long previousMillis_updateLeds = 0;
unsigned long previousMillis_displayActive = 0;
unsigned long previousMillis_updateMotion = 0;
unsigned long lastCommandMillis = 0;
unsigned long lastMotionMillis = 0;
unsigned long previousMillis_LocalTimeReport = 0;

int cmdDelay = 0; // set delay before command runs (for video recording)

// for notifications
char notification_str[256]; 

// for display commands 
int currentDisplayHours_int = 999; // will cause time to be set
int currentDisplayMinutes_int = 999;
int displayActiveFlag_int = 1; 
// int blankFlag = 0; // to avoid repeat blanking - hold over form split flaps
// for display dimensions
char input_str[640];
char input_str2[640];
char row_display_array[32][20];
char word_str[128][21];  // up to 128 words of 19 characters with '\0'
int word_str_length[128];
int word_cnt = 0;
int row_number = 0;
char display_str[640];
int graphic_num;
int graphic_num_old = 0; // to avoid random repeating of graphic

// for game of life (GOL)
int grid0[63][14]; 
int grid1[63][14]; 
int grid2[63][14]; 

// for motion configure motion controls
int motionPin = D12; // D12 active high
int motionState; // state 0-off, 1-on
int prior_motionState;
int motionReportFlag = 1; // default is on
int motionWindowFlag;

// for displaying character array
byte fd_array_5x4[4][5];  
byte fd_array_5x5[5][5];
byte fd_array_7x5[5][7]; 
byte fd_array_11x8[8][11]; 
byte fd_array_11x6[6][11]; 
// up to 50 characters scrolling with blank column separating and run in and out blanks
byte scrolling_fd_array_7x5[1000][7]; 
int colArray[1000];

int pulseTime = 400; // 400 us (4 100us steps) for flip dot solenoid pulses
// range is 0 to 5000 us - usually around 400us not including
// MCP associated delays of around 350us.  Therefore 750us total pulse time
int pulseNumber = 1; // 0 no pulse, 1 normal pulse, 2 double pulse - maybe for future // _needed? *****
int scrollDelay = 0; // scroll delay in ms  // not used? ****

/*
If using Nano ESP32 - in the IDE Tools menu, enter Pin Numbering and choose By GPIO number (legacy).
Then sketch should always use labels to refer to Arduino pins (e.g if you used the 
number 2, replace this with the symbol D2).
This is a more library-compatible scheme and avoids confusion.  
Also see pin table at end of this sketch.
*/

// for leds
// configure leds
// Nano ESP32 onboard RGB led
#define LEDR 46  // Note - Boot0  active low
#define LEDB 45  // Note - not an on-board pinout  active low
#define LEDG 0   // Note - B00t1 active low
// green power led always on with power
// yellow on board led controlled by Blynk - also called LED builtin
//   and is on D13 or GPIO48 - SPI Serial Clock

// led state 0-off, 1-on, 2-blinking(1s)
int redLedPin = D9; // active low - used for indicating power relay on
int blueLedPin = D10;  // active low - used for sw0, sw1 testing
int redLedState = 0; // redLed off
int blueLedState = 0; // blueLed off

// for input pushbutton switches
int SW0Pin = A0; 
int SW1Pin = A1;
int valueSW0 = 0;  
int valueSW1 = 0;
#include <Bounce2.h>
Bounce debouncerSW0 = Bounce();  // active low 
Bounce debouncerSW1 = Bounce();  // active low 

// for power relay - used to reduce power when display is not active 
// turns off all power except nano-esp32, leds, motion sensor and serial terminal  
//  relay connected to npn 3904 base with 3k resistor with
//    3904 collector connected to relay coil then to 15V with 
//    protection diode IN4148 between collector and 15V
int relayPin = D8; // active high (D8)
int relayState; // state 0-off, 1-on
int prior_relayState;
int relayReportFlag = 1; // default is on

// for MCP23017s
// sets all GPIO to inputs but does not affect configuration
int MCPRpin = D11;  // active low
int mcpOutput[11][2];  // for 2 row MCPs and 9 column MCPs - 11 total with two 8 bit ports each
int cgDel = 200;  // column group delay of 200 us is default - not used now - maybe for future

void setup()
{
// at start turn on relay
// blueLed indicates relay is on
pinMode(relayPin, OUTPUT);  
relayOn();

// start i2c
i2c1.begin(D3,D2,100000); // SDA pin D3, SCL pin D2, 400k baud  ****
delay(50);
i2c2.begin(D5,D4,100000); // SDA pin D5, SCL pin D4, 400k baud  ****
delay(50);

// for MCP23017s
pinMode(MCPRpin, OUTPUT);
digitalWrite(MCPRpin, HIGH); // clear reset  (active low)
delay(10);
mcpConfigure(); // configure mcp23017 output expanders
delay(10);
blankDisplay();
delay(10);
blankDisplay();

Serial.begin(38400); // for serial monitor
//while (!Serial) {}; // wait for serial port to connect.

// for watch dog timer
esp_task_wdt_init(WDT_TIMEOUT, true); // enable wdt
esp_task_wdt_add(NULL); //add current thread to WDT watch
// when time runs out, processor does a hardware reset

// connect to Blynk and WiFi network:
Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);  // this code works well with the nano, not so much with mkr
esp_task_wdt_reset();
// print out the status on the serial port
Serial.print("SSID: ");
Serial.println(WiFi.SSID());
// print out the WiFi IP address:
IPAddress ip = WiFi.localIP();
Serial.print("IP Address: ");
Serial.println(ip);
// print and display the received signal strength
rssi = WiFi.RSSI();
Serial.print("Signal strength (RSSI):");
Serial.print(rssi);
Serial.println(" dBm");

// The 'ESP32Time' library is just a wrapper interface for the functions available 
// in 'esp_sntp.h'.  There is no real need for ESP32Time.h other than convenience.
//  As long as WiFi is connected, the ESP32's internal RTC will be periodically 
//  synched to NTP.  The synch interval can be reported and can be changed.  
configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
//struct tm timeinfo; - defined above 
if(!getLocalTime(&timeinfo)){
  Serial.println("Failed to obtain time");
  }
rtc.setTimeStruct(timeinfo); 
delay(500);

esp_task_wdt_reset();  // refresh watch dog timer
updateDate();
updateTime();
Serial.println();
Serial.print(date_str);
Serial.print("  ");
Serial.println(time_str);
Serial.println("Flip Dot Controller is online.");
Serial.print(ssid);
Serial.print("  ");
rssi = WiFi.RSSI();
Serial.print(rssi);
Serial.println(" dBm");
Serial.println(); // add line feed
Serial.println("Type cmd in Blynk App for list of commands.");
Serial.println(); // add line feed

terminal.clear();
terminal.print(date_str);
terminal.print("  ");
terminal.println(time_str);
terminal.println("Flip Dot controller is online.");
terminal.print(ssid);
terminal.print("  ");
terminal.print(rssi);
terminal.println(" dBm");
terminal.println();  // add line feed
terminal.println("Type cmd for list of commands.");
terminal.println(); // add line feed
terminal.flush();

esp_task_wdt_reset();  // refresh watch dog timer

Blynk.logEvent("FDC_restarted"); // log event to timeline
// create visual indicator for push buttons ****

// for eeprom
// In the ESP32, a typical Flash page is 64-Bytes and you need to read-modify-write
// an entire page at a time.  The library saves the data to a buffer with the write() 
// or put() function and it is not actually written to Flash memory until 
// EEPROM.commit() is called. 
// Write eeprom data or if reset, obtain eeprom data
// Check signature at address 0
// If the eeprom is written, then there is a correct written signature.
// Note - unlike Arduino MKR1010 flash memory, this flash memory persists after  
// reprogramming.
EEPROM.begin(EEPROM_SIZE);
EEPROM.get(storedAddress, signature);
// If the EEPROM is written, then there is a orrect written signature
if (signature == WRITTEN_SIGNATURE){
  terminal.println("Returning EEPROM data previsouly written");
  terminal.flush();
  Blynk.run();
  EEPROMRead();  // print confirmation of data written and update variables
  }
else { // eeprom is not written and needs to be written
  terminal.println("EEPROM does not contain data.  Writing data to EEPROM.");
  terminal.flush();
  Blynk.run();
  EEPROMWrite();
  delay(100);
  EEPROMRead();  // print confirmation of data written and update variables
  }

// for input pushbutton switches
pinMode(SW0Pin, INPUT_PULLUP);  // declare pushbutton as input (active low - when button pressed, you get 0)
debouncerSW0.attach(SW0Pin); // set up debouncer 0
debouncerSW0.interval(25);  // use a debounce interval of 25 milliseconds
pinMode(SW1Pin, INPUT_PULLUP);  // declare pushbutton as input (active low - when button pressed, you get 0)
debouncerSW1.attach(SW1Pin); // set up debouncer 1
debouncerSW1.interval(25);  // use a debounce interval of 25 milliseconds

//for LEDS
pinMode(LEDR, OUTPUT);
pinMode(LEDG, OUTPUT);
pinMode(LEDB, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
pinMode(redLedPin, OUTPUT);
pinMode(blueLedPin, OUTPUT);

// configure motion controls
pinMode(motionPin, INPUT_PULLDOWN);  // remains low or off when not connected
motionState = digitalRead(motionPin);
prior_motionState = motionState;

// end setup
}

void loop()
{
esp_task_wdt_reset();  // refresh watch dog timer
updateSwitches();
currentMillis = millis();
// Time display and random graphic display updated every second
if (currentMillis - previousMillis_updateTimeDisplay >= 1000) {
  previousMillis_updateTimeDisplay = currentMillis;  // Remember the time
  // update the time display if time is turned on and display active
  if ((timeDisplayFlag_int == 1) && (displayActiveFlag_int == 1)){
    updateTimeDisplay();
    }
  if ((randomGraphicDisplayFlag_int == 1) && (displayActiveFlag_int == 1)){ 
    // check if new day
    days_int = rtc.getDay(); // update day
    if (prior_days_int != days_int){
      esp_task_wdt_reset();  // refresh watch dog timer
      randomGraphicDisplay();
      prior_days_int = days_int; // only one display per day
      }
    }  
  }  
// Check for Blynk command every 0.5 second
if (currentMillis - previousMillis_Blynk >= 500) { 
  previousMillis_Blynk = currentMillis;  // Remember the time
  Blynk.run();
  if (strcmp(cmd_str, "cleared") != 0) {
    menu();
    strcpy(cmd_str, "cleared"); // after menu() runs, clear com_str to avoid repeated commands
    }
  }
// Check for motion every 0.5 second
if (currentMillis - previousMillis_updateMotion >= 500){ 
  previousMillis_updateMotion = currentMillis;  // Remember the time
  // for testing
  motionState = digitalRead(motionPin);  // active high
  if (motionState == HIGH){
    blueLedState = 1; // led on
    lastMotionMillis = currentMillis;  // Remember the time
    }
  else{
    blueLedState = 0; // led off
    }
  if (motionState != prior_motionState){
    prior_motionState = motionState; 
    if (motionReportFlag == 1){
      if (motionState == HIGH){
        terminal.println("motion detected  ");
        }
      else{
        terminal.println("no motion  ");
        }
      //updateTime();  // for testing
      //terminal.println(time_str); 
      terminal.flush();
      Blynk.run();
      }
    }
  }  
// check if display active every 0.5 second
if (currentMillis - previousMillis_displayActive >= 500) { 
  previousMillis_displayActive = currentMillis;  // Remember the time
  // check if motion is in enabled time
  updateTime();
  if (hour_int >= enableStartHours_int && hour_int < enableEndHours_int) motionWindowFlag = 1; 
  else motionWindowFlag = 0;
  }
// check if motion in active time in last 5 minutes or command in last 5 minutes
// activeTime_int is in minutes
if ( ((((currentMillis - lastMotionMillis) <= (activeTime_ul * 60000)) 
    && (motionWindowFlag == 1)) && (lastMotionMillis != 0)) 
    || ((currentMillis - lastCommandMillis) <= (activeTime_ul * 60000)) ){     
    displayActiveFlag_int = 1;
    relayOn();
    }
  else {
    displayActiveFlag_int = 0;
    relayOff();
    } 
// LEDs updated every 0.25 second
if (currentMillis - previousMillis_updateLeds >= 250) { 
  previousMillis_updateLeds = currentMillis;  // Remember the time
  updateLeds();
   }
// led toggle and uptime - also runs during delay25ms
// Uptime and led toggle sent every second  for testing
/*if(currentMillis - previousMillis_blinkLedWidget >= 1000) {
  previousMillis_blinkLedWidget = currentMillis;  // Remember the time
  blinkLedWidget();
  Blynk.virtualWrite(V2, millis() / 60000); // send the uptime
  Blynk.run();
  }
  */
if(((currentMillis - previousMillis_LocalTimeReport) >= 60000) && (printLocalTimeFlag == 1)) { // once per minute ***** Not needed any more
  previousMillis_LocalTimeReport = currentMillis;  // Remember the time
  printLocalTime();
  }
// Error after 5 seconds
// error routine sets previousMillis_nanoReset
if((nano_reset_flag_int == 1) && (currentMillis - previousMillis_nanoReset >= 5000)) {  
  nanoReset();
  }
}  // end of loop

void relayOn()
{
relayState = 1; // relay on
redLedState = 1; // led on
digitalWrite(relayPin, HIGH); // turn relay on - active high
delay1s();  // add delay for relay time and remote startup time
if (relayState != prior_relayState){
  prior_relayState = relayState; 
  if (relayReportFlag == 1){
    terminal.print("relay on  ");
    updateTime();
    terminal.println(time_str); 
    terminal.flush();
    Blynk.run();
    }
  }
}
  
void relayOff()
{  
relayState = 0; // relay off
digitalWrite(relayPin, LOW);  // active high
redLedState = 0; // turn off red led
if (relayState != prior_relayState){
  prior_relayState = relayState;
  if (relayReportFlag == 1){
    terminal.print("relay off  ");
    updateTime();
    terminal.println(time_str); 
    terminal.flush();
    Blynk.run();
    }
  }
}

void printLocalTime() // prints local time to Blynk terminal
{
// struct tm timeinfo; - defined globally above  
//getLocalTime(&timeinfo);
//terminal.print("ntp ");
//terminal.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");  // see strftime for formating options
// rtc loaded above in setup ??
terminal.print("nano rtc ");
terminal.println(rtc.getTime("%A, %B %d %Y %H:%M:%S"));   // (String) returns time with specified format 
terminal.flush();
Blynk.run();
return;
}

void updateSwitches()
{
// Update the debouncer instances
debouncerSW0.update();  // each switch cycles led for testing 
debouncerSW1.update();
/*if (debouncerSW0.fell()){ // for testing
  blueLedState ++;
  if (blueLedState >= 3) blueLedState = 0;
  } 
if (debouncerSW1.fell()){
  blueLedState ++;
  if (blueLedState >= 3) blueLedState = 0;
  }
  */ 
return;
}

void updateLeds()
{
// red led control - relay state
switch (redLedState)
  {
    case 0:
      // turn off led
      digitalWrite(redLedPin, HIGH); // active low
      break;
    case 1:
      // turn on led
      digitalWrite(redLedPin, LOW);
      break;
    case 2:
      // blink led
      digitalWrite(redLedPin, !digitalRead(redLedPin));
      break;
    default:
      // default - turn off led
      digitalWrite(redLedPin, HIGH);
      break; 
  } 
  // blue led control - motion state
  switch (blueLedState)
  {
    case 0:
      // turn off led
      digitalWrite(blueLedPin, HIGH); // active low
      break;
    case 1:
      // turn on led
      digitalWrite(blueLedPin, LOW);
      break;
    case 2:
      // blink led
      digitalWrite(blueLedPin, !digitalRead(blueLedPin));
      break;
    default:
      // default - turn off led
      digitalWrite(blueLedPin, HIGH);
      break; 
  } 
return;
}

void nanoError()
{
  // do not log new errors if one has been reported 
  //   and now in prcess of logging and resetting
  if (nano_reset_flag_int == 1) {return;}
  // general case errors
  strcpy(error_type_display_str, error_type_str);
  strcat(error_type_display_str, " Error");
  // special case error
  if (strcmp(error_type_str, "BT") == 0) {
    strcpy(error_type_display_str, "BT restart");
    }  
  if (strcmp(error_type_str, "ST") == 0) {
    strcpy(error_type_display_str, "ST restart");
    }  
  // set flag for error reporting and shutdown
  nano_reset_flag_int = 1;
}

// processor software reset 
void nanoReset()  // runs at end of 5 second nanoReset timer
{
  // send notification
  strcpy(notification_str, error_type_display_str);
  Blynk.logEvent("Nano ESP32 restarted", String(notification_str)); 
  // above log restart in timeline nnnnn
  Serial.println(notification_str);
  ESP.restart ();  //****
}

void updateRTC()  // call this at beginning?? ****
{
configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
//struct tm timeinfo; - defined above 
if(!getLocalTime(&timeinfo)){
  terminal.println("Failed to obtain time");
  }
rtc.setTimeStruct(timeinfo); 
printLocalTime();
return;
}

void updateDate()
{
  // get date data
  years_int = rtc.getYear(); // 4 digits 2021
  sprintf(years_str, "%4d", years_int); 
  
  months_int = rtc.getMonth();  // returns 0-11
  months_int++;
  sprintf(months_str, "%02d", months_int);
  // above converts to 2 character decimal base - pads leading 0s by adding the 0
  days_int = rtc.getDay(); // returns 1-31
  sprintf(days_str, "%02d", days_int);
  strcpy(date_str, years_str);
  strcat(date_str, "-");
  strcat(date_str, months_str);
  strcat(date_str, "-");
  strcat(date_str, days_str);
}  

void updateTime()
{
  //get time data
  hour_int = rtc.getHour(true); // true is 24 hour time 0-23
  sprintf(hour_str, "%02d", hour_int); 
  // above converts to 2 character decimal base - pads leading 0s by adding the 0
  minute_int = rtc.getMinute(); // 0-59
  sprintf(minute_str, "%02d", minute_int); 
  second_int = rtc.getSecond();
  sprintf(second_str, "%02d", second_int); 
  strcpy(time_str, hour_str);
  strcat(time_str, ":");
  strcat(time_str, minute_str);
  strcat(time_str, ":");
  strcat(time_str, second_str);
}  

void updateTimeDisplay()
{
updateDate();
updateTime();
// check if new hour or mintues and update display if so
if ((currentDisplayHours_int != hour_int) ||
    (currentDisplayMinutes_int != minute_int)){
  strcpy(input_str, months_str);
  strcat(input_str, days_str);
  strcat(input_str, " ");
  strcat(input_str, hour_str);
  strcat(input_str, " "); // seconds tick
  strcat(input_str, minute_str);
  // update current hours and minutes  
  currentDisplayHours_int = hour_int;
  currentDisplayMinutes_int = minute_int;
  displayTimeString_7x5();  // displays input_str with blank display background 
  }
// go back and add seconds tick
if (secondsDisplayOn == 1){ 
  if (seconds_tick == 1) {
    seconds_tick = 0; 
    displayCharacter_7x5(7, 0x02);  // left :
    }
  else{
    seconds_tick = 1; 
    displayCharacter_7x5(7, 0x03);  // right :
    }
  }
else {
  displayCharacter_7x5(7, ':');  // center :
  }
}

void setTimeDisplay()
{
// updates time display to current time and turns time display on
currentDisplayHours_int = 999;  // cause update by using incorrect time 
currentDisplayMinutes_int = 999; 
fastBlankDisplay();
timeDisplayFlag_int = 1; // turn on time display if not already on
updateTimeDisplay();
}

void clearTimeDisplay()
{
// clears time display and turns time display off
fastBlankDisplay();
timeDisplayFlag_int = 0; // turn off time display to keep clear
}

void EEPROMWrite()
{
// note - function changing these variables must also update
//   the working variables - e.g. k_GMT_int and k_GMT_str
// store signature first
flash.eeprom_signature = WRITTEN_SIGNATURE;
strcpy(flash.eeprom_ssid, ssid);
strcpy(flash.eeprom_pass, pass);
strcpy(flash.eeprom_k_GMT, k_GMT_str);
strcpy(flash.eeprom_enableStartHours, enableStartHours_str);
strcpy(flash.eeprom_enableEndHours, enableEndHours_str);
strcpy(flash.eeprom_activeTime, activeTime_str);
strcpy(flash.eeprom_randomGraphicDisplayFlag, randomGraphicDisplayFlag_str);
strcpy(flash.eeprom_timeDisplayFlag, timeDisplayFlag_str);
strcpy(flash.eeprom_t1_highScore, t1_highScore_str);
strcpy(flash.eeprom_t2_highScore, t2_highScore_str);
EEPROM.put(storedAddress, flash);
EEPROM.commit();
EEPROMRead();
}

// read eeprom
void EEPROMRead()
{
EEPROM.get(storedAddress, signature);
// If the EEPROM is written, then there is a written signature
if (signature == WRITTEN_SIGNATURE){
  EEPROM.get(storedAddress, flash);
  // Print a confirmation of the EEPROM data
  terminal.println("Data read from EEPROM:  ");
  terminal.print("ssid ");
  terminal.println(flash.eeprom_ssid); 
  terminal.print("pass: ");  
  terminal.println(flash.eeprom_pass);  
  terminal.print("k_GMT: ");
  terminal.println(flash.eeprom_k_GMT); 
  terminal.print("enableStartHours: ");
  terminal.println(flash.eeprom_enableStartHours);
  terminal.print("enableEndHours: ");
  terminal.println(flash.eeprom_enableEndHours);
  terminal.print("activeTime: ");
  terminal.println(flash.eeprom_activeTime);
  terminal.print("randomGraphicDisplayFlag: ");
  terminal.println(flash.eeprom_randomGraphicDisplayFlag);
  terminal.print("timeDisplayFlag: ");
  terminal.println(flash.eeprom_timeDisplayFlag);
  terminal.print("t1_highScore: ");
  terminal.println(flash.eeprom_t1_highScore);
  terminal.print("t2_highScore: ");
  terminal.println(flash.eeprom_t2_highScore);
  terminal.println();
  // convert eeprom data to strings and numbers used in the program
  strcpy(ssid, flash.eeprom_ssid);
  strcpy(pass, flash.eeprom_pass);
  strcpy(k_GMT_str, flash.eeprom_k_GMT);
  strcpy(enableStartHours_str, flash.eeprom_enableStartHours);
  strcpy(enableEndHours_str, flash.eeprom_enableEndHours);
  strcpy(activeTime_str, flash.eeprom_activeTime); 
  strcpy(randomGraphicDisplayFlag_str, flash.eeprom_randomGraphicDisplayFlag); 
  strcpy(timeDisplayFlag_str, flash.eeprom_timeDisplayFlag); 
  strcpy(t1_highScore_str, flash.eeprom_t1_highScore); 
  strcpy(t2_highScore_str, flash.eeprom_t2_highScore); 
  k_GMT_int = atoi(flash.eeprom_k_GMT);
  enableStartHours_int = atoi(flash.eeprom_enableStartHours);
  enableEndHours_int = atoi(flash.eeprom_enableEndHours);
  activeTime_int = atoi(flash.eeprom_activeTime); 
  activeTime_ul = (long)activeTime_int; // and then to unsigned long
  randomGraphicDisplayFlag_int = atoi(flash.eeprom_randomGraphicDisplayFlag); 
  timeDisplayFlag_int = atoi(flash.eeprom_timeDisplayFlag); 
  t1_highScore_int = atoi(flash.eeprom_t1_highScore); 
  t2_highScore_int = atoi(flash.eeprom_t2_highScore); 
  }
else { // eeprom is not written and needs to be written
  terminal.println("EEPROM does not contain data.");
  }
terminal.flush();
Blynk.run();
return;
}  

// delays that maintain Blynk uptime and led connection 
//   and WDT clearing
void delay25ms(){ 
  currentMillis = millis();
  if(currentMillis - previousMillis_blinkLedWidget >= 1000) {
    previousMillis_blinkLedWidget = currentMillis;  // Remember the time
    //blinkLedWidget();
    //Blynk.virtualWrite(V2, millis() / 60000); // send the uptime
    Blynk.run();
    delay(5); // is a longer delay needed?
    }
  else{
    delay(25);
    } 
  esp_task_wdt_reset();
  }

void delay30ms(){delay(5); delay25ms();}
void delay50ms(){delay(25); delay25ms();}
void delay75ms(){delay(50); delay25ms();}
void delay100ms(){delay(75); delay25ms();}
void delay150ms(){delay(100); delay50ms();}
void delay200ms(){delay(175); delay25ms();}
void delay250ms(){delay(225); delay25ms();}
void delay300ms(){delay(275); delay25ms();}
void delay350ms(){delay(325); delay25ms();}
void delay400ms(){delay(375); delay25ms();}
void delay450ms(){delay(425); delay25ms();}
void delay500ms(){delay250ms(); delay250ms();}
void delay600ms(){delay300ms(); delay300ms();}
void delay700ms(){delay350ms(); delay350ms();}
void delay750ms(){delay500ms(); delay250ms();}
void delay800ms(){delay400ms(); delay400ms();}
void delay900ms(){delay450ms(); delay450ms();}
void delay1s(){delay500ms(); delay500ms();}
void delay2s(){delay1s(); delay1s();}
void delay3s(){delay2s(); delay1s();}
void delay4s(){delay2s(); delay2s();}
void delay5s(){delay3s(); delay2s();}
void delay6s(){delay4s(); delay2s();}
void delay7s(){delay4s(); delay3s();}
void delay8s(){delay4s(); delay4s();}
void delay9s(){delay5s(); delay4s();}
void delay10s(){delay5s(); delay5s();}

/*
In the IDE Tools menu, enter Pin Numbering and choose By GPIO number (legacy);
Make sure the sketch always uses labels to refer to pins. If you used the number 2, 
replace this with the symbol D2 everywhere.  This will switch to a more library-compatible 
scheme and avoid the above confusion.  Do not include GPIO in the number. 
See pin table below.

Nano	ESP32
D0	GPIO44
D1	GPIO43
D2	GPIO5  **** is this esp32 pin 5 ss that conflicts with use of eeprom???  however, this is used with i2c now - probapbly not
D3	GPIO6
D4	GPIO7
D5	GPIO8
D6	GPIO9  *** do not want to use gpi0 6-11 as also used for integrated flash?? eeprom??? **** 
D7	GPIO10
D8	GPIO17
D9	GPIO18
D10	GPIO21
D11	GPIO38
D12	GPIO47
D13	GPIO48  also built in led and SPI clock and used with Blynk for link indication
A0	GPIO1
A1	GPIO2
A2	GPIO3
A3	GPIO4
A4	GPIO11
A5	GPIO12
A6	GPIO13
A7	GPIO14
BOOT0	GPIO46  also Red on rgb led 
BOOT1	GPIO0   also Green on rgb led

GPIO 45 is not on board pinout but is Blue on rgb 
Note - some early boards (not mine) have different rgb colors

*/

