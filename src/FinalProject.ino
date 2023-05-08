#include <Adafruit_Arcada.h>
#include <Adafruit_SPIFlash.h> // For increasing flash space of board?
#include <Adafruit_Sensor.h> // For basic sensors
#include <PDM.h>
#include <Adafruit_TinyUSB.h>
#include <SoftwareSerial.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define WHITE_LED 43

Adafruit_Arcada arcada;
extern PDMClass PDM;
extern Adafruit_FlashTransport_QSPI flashTransport;
extern Adafruit_SPIFlash Arcada_QSPI_Flash;


uint32_t buttons, last_buttons;
//uint8_t j = 0;  // neopixel counter for rainbow

// Added global variables:
const int latinTextlength = 280;
char latinText[latinTextlength];   // an array to store the english text
char morse[1500]; // an array to store the morse text

boolean newinput = false; // Used to determine whether a newinput should be printed
int runTranslators= 0; // Used to determine whether the user menu should print or a translator should run
//uint8_t inputs = 0;
uint8_t takeinputs = 0; // Used to
uint8_t x = 1; // Character counter for typing on the screen
uint8_t i = 0; // Counter variable
uint8_t k = 0; // Counter variable for printing to the screen
//int right;
//int left;
int clearscreen = 1; // Determines whether or not to clear the screen
int erase = 0; // Determines whether or not to erase screen 
int counterdeclared; // If the counter has started
uint32_t pressStartTime = 0; // Start time for timer for how long the button is held
uint32_t pressStopTime = 0; // Stop time for timer for how long the button is held
uint32_t holdTime = 0; // Timer variable (difference of start and stop times)
uint32_t counter = 0; // Part of timer variable that tracks time since last button input
uint32_t currenttime =0; // Other part of timer variable that tracks time since last button input
// Initializing English to Morse and Morse to English functions
char* EtoM(char c,char* morse);
char* MtoE(char* segment,char* output);


// Check the timer callback, this function is called every millisecond!
volatile uint16_t milliseconds = 0;
void timercallback() {
  analogWrite(LED_BUILTIN, milliseconds);  // pulse the LED
  if (milliseconds == 0) {
    milliseconds = 255;
  } else {
    milliseconds--;
  }
}

// Left setup mostly alone from Clue board test program used as template
void setup() {
  Serial.begin(115200);
  pinMode(WHITE_LED, OUTPUT);
  digitalWrite(WHITE_LED, LOW);
  arcada.displayBegin();
  Serial.println("Arcada display begin");
  for (int i=0; i<250; i+=10) {
    arcada.setBacklight(i);
    delay(1);
  }
  arcada.display->setCursor(0, 0);
  arcada.display->setTextWrap(true);
  arcada.display->setTextSize(2);
  //buttons = last_buttons = 0;
  arcada.timerCallback(1000, timercallback);
  arcada.display->setTextWrap(false);

  Serial.println("Enter in your phrase one character at a time.");
  Serial.println("Enter '$' to finish entering characters.");
}

// Main Loop
void loop() {
// Print the UI if the program is just starting
if (runTranslators == 0) {
 menu();
}
uint8_t pressed_buttons = arcada.readButtons(); // Reading button inputs
    // If the left button is pressed
    if (pressed_buttons & ARCADA_BUTTONMASK_A){ 
      runTranslators = 1;
      // Clears screen initially
      arcada.display->setCursor(0, 20);
      for (int i = 0; i < 15; i++){
        arcada.display->println("                    ");
      }
      // Infinite while loop to continue running this loop until the board is reset
      while (runTranslators == 1){
      // Printing title of function at the top of the screen
      arcada.display->setCursor(0, 0);
      arcada.display->println("  Morse to English  ");
      takeinputs = 1;
      // Takes morse inputs from the buttons until no inputs have been entered for 5 seconds
      while (takeinputs ==1){
        morseinputs();
      }
      translateMtoE(); // Translates Morse to English
      showNewinput(); // Prints English translation to board screen, and english and morse to serial monitor
      memset(latinText, 0, sizeof(latinText)); // Resets morse to all 0s for next translation
      memset(morse, 0, sizeof(morse)); // Resets latinText to all 0s for next translation
      }
    }

    if (pressed_buttons & ARCADA_BUTTONMASK_B){ 
      runTranslators = 1;
      // Clears the screen initially
      arcada.display->setCursor(0, 20);
      for (int i = 0; i < 15; i++){
        arcada.display->println("                    ");
      }
      // Infinite while loop to continue running this loop until the board is reset
      while (runTranslators == 1){
      for (int i = 0; i < 15; i++){
        arcada.display->println("                    ");
      }
      // Printing title of function at the top of the screen
      arcada.display->setCursor(0, 0);
      arcada.display->println("  English to Morse  ");
      
      readinput(); // Read the english text input from the Serial monitor
      showNewinput(); // Prints English to board screen, and english and morse to serial monitor
      buzzer(); // Outputs Morse by flashing with the LEDs and buzzing with the speaker
      memset(morse, 0, sizeof(morse)); // Resets morse to all 0s for next translation
      memset(latinText, 0, sizeof(latinText)); // Resets latinText to all 0s for next translation
      }
    }
}

// User Interface function
void menu() {

  arcada.display->setTextColor(ARCADA_WHITE, ARCADA_BLACK);
  arcada.display->setCursor(0, 20);

  arcada.display->println("Welcome to the Morse");
  arcada.display->println("  Code translator!");
  arcada.display->println("     ");
  arcada.display->println("--choose one below--");
  arcada.display->println("     ");
  arcada.display->println("Left Button:");
  arcada.display->println("Morse to English");
  arcada.display->println("     ");
  arcada.display->println("Right Button:");
  arcada.display->print("English to Morse");
}

// Reads english inputs and translates english to morse
void readinput() {
    int ndx = 0; // Counter variable
    char endMarker = '\n';
    char input;
    // Serial.available() will return 1 normally. Will return 0 if there are no more characters to read
    while (Serial.available()) {
      //Serial.read() reads the serial input one character at a time, starting with the oldest one (first one).
      //Once that character is read, it deletes it from the buffer and will read the next character the next time it is called
      //Loops until all of the characters have been read (When Serial.available() becomes unavailable)
        input = Serial.read();
        // If the input is not the end of the line
        if (input != endMarker) {
          latinText[ndx] = input; // Latin Text character is equal to the input character
          *EtoM(latinText[ndx], morse); // Call English to Morse translation
          if (ndx >= latinTextlength) {
              ndx = latinTextlength - 1;
          }
          ndx = ndx+1;
        }
        else {
          latinText[ndx] = '\0'; // terminate the string
          ndx = 0;
          newinput = true;
        }
    }
}

// Prints English and Morse to the serial, prints english to board
void showNewinput() {
    // if there is a new input
    if (newinput == true) {
       Serial.println(latinText);
       Serial.println(morse);
      // Clear the screen
      arcada.display->setCursor(0, 30); 
      for (int i = 0; i < 15; i++){
        arcada.display->println("                    ");
      }
        arcada.display->setCursor(0, 30);
      int k = 1;
      // Print Latin text character by character to the board
      // Skips to the next line on the board if it reaches the end of line (20 chars/line)
      for (int x=0;x<strlen(latinText);x++){
        arcada.display->print(latinText[x]);

        if (x==(k*20)-1){
        arcada.display->println("     ");
        k++;
        }
      }
      delay(50); // Helps to keep the printed text on the screen
    }
    erase=1; // Used to tell Morse whether or not to clear the screen
}

// Flashes the LED and buzzes the speaker with the Morse output
void buzzer() {
  // initializing chars for dot, dash, between english character spaces, and between word spaces
  char dot = '.';
  char dash = '-';
  char interspace = ' ';
  char interword = '/';
    // if there is a new input
    if (newinput == true) {
      // Loop through each element of morse
      for (int x=0;x<strlen(morse);x++){
        char morsechar = morse[x];
        if(morsechar == dot){
          digitalWrite(WHITE_LED, HIGH); // Turns the LED on high
          tone(ARCADA_AUDIO_OUT, 1000, 60); // Turns the buzzer on for 60 ms
          delay(60); // Waits 60 ms so the light and speaker are on for the same amount of time
          digitalWrite(WHITE_LED,LOW); // Turns LED on low
        }
        else if (morsechar == dash){
          digitalWrite(WHITE_LED, HIGH); // Turns the LED on high
          tone(ARCADA_AUDIO_OUT, 1000, 180); // Turns the buzzer on for 180 ms
          delay(180); // Waits 180 ms so the light and speaker are on for the same amount of time
          digitalWrite(WHITE_LED,LOW); // Turns LED on low

        }
        else if (morsechar == interspace){
          delay(180-60); // Will delay 180 ms between english characters
        }
        else if (morsechar == interword){
          delay(420-60); // Will delay 420 ms between english words
        }
        delay(60); // Will delay 60 ms between normal dot and dash
      }
        newinput = false; // Resets newinput after the input has been outputted
    }
}

// Takes Morse inputs
void morseinputs() {
  // Reads button inputs
  uint8_t pressed_buttons = arcada.readButtons();
    counterdeclared = 1;
    // If the erase variable has been set to 1 by showNewInput
    if (erase == 1){
      // And if the buttons are pressed
      if (pressed_buttons & (ARCADA_BUTTONMASK_A || ARCADA_BUTTONMASK_B)) {
        counter = millis(); // Records time in program at last button press
        counterdeclared = 0; // Sets to 0 so counter won't be declared again
        // Clears screen
        for (int i = 0; i < 15; i++){
          arcada.display->setCursor(0, 30);
          arcada.display->println("                    ");
        }
        erase = 0; // Resets to 0
   }
  }
    // If the left button is pressed (dot or dash)
    if (pressed_buttons & ARCADA_BUTTONMASK_A) {
      if (counterdeclared == 1) 
          counter = millis(); // Records time in program at last button press
      pressStartTime = millis(); // Records time in program when the button is pressed
      // Infinite loop that runs while the button is being pressed
      while ((pressed_buttons & ARCADA_BUTTONMASK_A)){
        pressed_buttons = arcada.readButtons();
      }
      pressStopTime = millis(); // Records time in program when the button is let go of
      holdTime = pressStopTime - pressStartTime; // Calculates how long the button was pressed for
      // If the button was held for more than 150 ms, it will be a dash
      if (holdTime > 150) {
        // Save a - to the string
        strcat (morse,"-");
      }
      // If the button was held for more than 150 ms, it will be a dot
      else {
        // Save a . to the string
        strcat (morse,".");
      }
    }
    // If the right button is pressed (new character or new word)
    if (pressed_buttons & ARCADA_BUTTONMASK_B) {
      if (counterdeclared == 1) 
          counter = millis(); // Records time in program at last button press
      pressStartTime = millis(); // Records time in program when the button is pressed
      // Infinite loop that runs while the button is being pressed
      while ((pressed_buttons & ARCADA_BUTTONMASK_B)) {
        pressed_buttons = arcada.readButtons();
      }
      pressStopTime = millis(); // Records time in program when the button is let go of
      holdTime = pressStopTime - pressStartTime; // Calculates how long the button was pressed for
      // If the button was held for more than 150 ms, it will be a new word
      if (holdTime > 150) {
        // Save a " / " to the string
        strcat (morse," / ");
      }
      // If the button was held for less than 150 ms, it will be a new character
      else {
        // Save a " " to the string
        strcat (morse," ");
      }
    }
      int k = 1;
      // Prints the morse input to the screen as you type it in
      arcada.display->setCursor(0, 30);
      for (int x=0;x<strlen(morse);x++){
        arcada.display->print(morse[x]);

        if (x==(k*20)-1){
        arcada.display->println("     ");
        k++;
        }
      }
    // Only if counter is greater than 0
    if (counter >0){
      currenttime = millis(); // Gets current time in program
    }
    // If there has not been a user input for 5 seconds or more
    if ((currenttime - counter) >= 5000){
      takeinputs = 0; // Will break the infinite loop in the main loop to stop taking morse inputs
      newinput = true; // Will allow the output functions to run
      counter = 0; // Resets Counter
      currenttime = 0; // Resets current time
      return;
    }
}

// Splits morse code into chunks of english characters
// Finds the spaces between characters and splits it based on that
void translateMtoE(){
  char *ptr;
    // first split
    ptr = strtok(morse," ");
    MtoE(ptr,latinText);
    // second and following split
    while(ptr != NULL) {
      ptr = strtok(NULL," ");
      if(ptr != NULL) {
        MtoE(ptr,latinText);
      }    
    }
}

// English to Morse library
// Compares English input character to the library, then assigns corresponding Morse characters to the Morse array
char* EtoM(char c,char* morse) {
    if (c == 'A' || c == 'a') {
        strcat(morse,".- ");
    }
    else if (c == 'B' || c == 'b') {
        strcat(morse,"-... ");
    }
    else if (c == 'C' || c == 'c') {
        strcat(morse,"-.-. ");
    }
    else if (c == 'D' || c == 'd') {
        strcat(morse,"-.. ");
    }
    else if (c == 'E' || c == 'e') {
        strcat(morse,". ");
    }
    else if (c == 'F' || c == 'f') {
        strcat(morse,"..-. ");
    }
    else if (c == 'G' || c == 'g') {
        strcat(morse,"--. ");
    }
    else if (c == 'H' || c == 'h') {
        strcat(morse,".... ");
    }
    else if (c == 'I' || c == 'i') {
        strcat(morse,".. ");
    }
    else if (c == 'J' || c == 'j') {
        strcat(morse,".--- ");
    }
    else if (c == 'K' || c == 'k') {
        strcat(morse,"-.- ");
    }
    else if (c == 'L' || c == 'l') {
        strcat(morse,".-.. ");
    }
    else if (c == 'M' || c == 'm') {
        strcat(morse,"-- ");
    }
    else if (c == 'N' || c == 'n') {
        strcat(morse,"-. ");
    }
    else if (c == 'O' || c == 'o') {
        strcat(morse,"--- ");
    }
    else if (c == 'P' || c == 'p') {
        strcat(morse,".--. ");
    }
    else if (c == 'Q' || c == 'q') {
        strcat(morse,"--.- ");
    }
    else if (c == 'R' || c == 'r') {
        strcat(morse,".-. ");
    }
    else if (c == 'S' || c == 's') {
        strcat(morse,"... ");
    }
    else if (c == 'T' || c == 't') {
        strcat(morse,"- ");
    }
    else if (c == 'U' || c == 'u') {
        strcat(morse,"..- ");
    }
    else if (c == 'V' || c == 'v') {
        strcat(morse,"...- ");
    }
    else if (c == 'W' || c == 'w') {
        strcat(morse,".-- ");
    }
    else if (c == 'X' || c == 'x') {
        strcat(morse,"-..- ");
    }
    else if (c == 'Y' || c == 'y') {
        strcat(morse,"-.-- ");
    }
    else if (c == 'Z' || c == 'z') {
        strcat(morse,"--.. ");
    }
    else if (c == '0') {
        strcat(morse,"----- ");
    }
    else if (c == '1') {
        strcat(morse,".---- ");
    }
    else if (c == '2') {
        strcat(morse,"..--- ");
    }
    else if (c == '3') {
        strcat(morse,"...-- ");
    }
    else if (c == '4') {
        strcat(morse,"....- ");
    }
    else if (c == '5') {
        strcat(morse,"..... ");
    }
    else if (c == '6') {
        strcat(morse,"-.... ");
    }
    else if (c == '7') {
        strcat(morse,"--... ");
    }
    else if (c == '8') {
        strcat(morse,"---.. ");
    }
    else if (c == '9') {
        strcat(morse,"----. ");
    }
    else if (c == '.') {
        strcat(morse,".-.-.- ");
    }
    else if (c == ',') {
        strcat(morse,"--..-- ");
    }
    else if (c == ':') {
        strcat(morse,"---... ");
    }
    else if (c == '?') {
        strcat(morse,"..--.. ");
    }
    else if (c == '\'') {
        strcat(morse,".----. ");
    }
    else if (c == '-') {
        strcat(morse,"-....- ");
    }
    else if (c == '/') {
        strcat(morse,"-..-. ");
    }
    else if (c == '(') {
        strcat(morse,"-.--. ");
    }
    else if (c == ')') {
        strcat(morse,"-.--.- ");
    }
    else if (c == '"') {
        strcat(morse,".-..-. ");
    }
    else if (c == '&') {
        strcat(morse,".-... ");
    }
    else if (c= ' ') {
        strcat(morse,"/  ");
    }
    return morse;
}

// Morse to English library
// Compares Morse input characters to the library, then assigns corresponding English character to the latintext array
char* MtoE(char* segment,char* output) {
    if (strcmp(segment,".-") == 0) {
        strcat(output,"a");
    }
    else if (strcmp(segment,"-...") == 0) {
        strcat(output,"b");
    }
    else if (strcmp(segment,"-.-.") == 0) {
        strcat(output,"c");
    }
    else if (strcmp(segment,"-..") == 0) {
        strcat(output,"d");
    }
    else if (strcmp(segment,".") == 0 && strlen(segment) == 1) {
        strcat(output,"e");
    }
    else if (strcmp(segment,"..-.") == 0) {
        strcat(output,"f");
    }
    else if (strcmp(segment,"--.") == 0) {
        strcat(output,"g");
    }
    else if (strcmp(segment,"....") == 0) {
        strcat(output,"h");
    }
    else if (strcmp(segment,"..") == 0 && strlen(segment) == 2) {
        strcat(output,"i");
    }
    else if (strcmp(segment,".---") == 0) {
        strcat(output,"j");
    }
    else if (strcmp(segment,"-.-") == 0) {
        strcat(output,"k");
    }
    else if (strcmp(segment,".-..") == 0) {
        strcat(output,"l");
    }
    else if (strcmp(segment,"--") == 0) {
        strcat(output,"m");
    }
    else if (strcmp(segment,"-.") == 0) {
        strcat(output,"n");
    }
    else if (strcmp(segment,"---") == 0) {
        strcat(output,"o");
    }
    else if (strcmp(segment,".--.") == 0) {
        strcat(output,"p");
    }
    else if (strcmp(segment,"--.-") == 0) {
        strcat(output,"q");
    }
    else if (strcmp(segment,".-.") == 0) {
        strcat(output,"r");
    }
    else if (strcmp(segment,"...") == 0) {
        strcat(output,"s");
    }
    else if (strcmp(segment,"-") == 0) {
        strcat(output,"t");
    }
    else if (strcmp(segment,"..-") == 0) {
        strcat(output,"u");
    }
    else if (strcmp(segment,"...-") == 0) {
        strcat(output,"v");
    }
    else if (strcmp(segment,".--") == 0) {
        strcat(output,"w");
    }
    else if (strcmp(segment,"-..-") == 0) {
        strcat(output,"x");
    }
    else if (strcmp(segment,"-.--") == 0) {
        strcat(output,"y");
    }
    else if (strcmp(segment,"--..") == 0) {
        strcat(output,"z");
    }
    else if (strcmp(segment,"-----") == 0) {
        strcat(output,"0");
    }
    else if (strcmp(segment,".----") == 0) {
        strcat(output,"1");
    }
    else if (strcmp(segment,"..---") == 0) {
        strcat(output,"2");
    }
    else if (strcmp(segment,"...--") == 0) {
        strcat(output,"3");
    }
    else if (strcmp(segment,"....-") == 0) {
        strcat(output,"4");
    }
    else if (strcmp(segment,".....") == 0) {
        strcat(output,"5");
    }
    else if (strcmp(segment,"-....") == 0) {
        strcat(output,"6");
    }
    else if (strcmp(segment,"--...") == 0) {
        strcat(output,"7");
    }
    else if (strcmp(segment,"---..") == 0) {
        strcat(output,"8");
    }
    else if (strcmp(segment,"----.") == 0) {
        strcat(output,"9");
    }
    else if (strcmp(segment,".-.-.-") == 0) {
        strcat(output,".");
    }
    else if (strcmp(segment,"--..--") == 0) {
        strcat(output,",");
    }
    else if (strcmp(segment,"---...") == 0) {
        strcat(output,":");
    }
    else if (strcmp(segment,"..--..") == 0) {
        strcat(output,"?");
    }
    else if (strcmp(segment,".----.") == 0) {
        strcat(output,"\'");
    }
    else if (strcmp(segment,"-....-") == 0) {
        strcat(output,"-");
    }
    else if (strcmp(segment,"-..-.") == 0) {
        strcat(output,"/");
    }
    else if (strcmp(segment,"-.--.") == 0) {
        strcat(output,"(");
    }
    else if (strcmp(segment,"-.--.-") == 0) {
        strcat(output,")");
    }
    else if (strcmp(segment,".-..-.") == 0) {
        strcat(output,"\"");
    }
    else if (strcmp(segment,".-...") == 0) {
        strcat(output,"&");
    }
    else if (strcmp(segment,"/") == 0) {
        strcat(output," ");
    }
    return output;
}