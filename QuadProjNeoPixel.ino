#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            7

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayVal = 500; // delay for half a second
int randNum;
String randQuad;
String userResponse;
String quads[] = {"trapezium", "square", "rectangle", "parallelogram", "rhombus", "trapezoid", "iso trapezoid", "kite", "not quad"}; //total size = 8( + 1 for not quad)

void setup() {
  
  pixels.begin(); // This initializes the NeoPixel library.
  reset();
  delay(1000);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Here are some instructions: type what shape ");
  Serial.println("Here are the options:");
  for(int i = 0; i < 9; i++){
    Serial.print(i);
    Serial.print(": ");
    Serial.println(quads[i]);
  }
  Serial.println("    ");
  
  //Sets a seed for randomness - gets a value from an empty analogue pin
  randomSeed(analogRead(A0));

}


void loop() {
  randNum = random(0, 9);
  //Serial.println(randNum);  
  randQuad = quads[randNum];
  makeQuad(randQuad);
  //Serial.println(randQuad);
  
  Serial.println("What shape is this? You have 8 seconds.");
  delay(8000);
  
  if (Serial.available() > 0) {
   
    userResponse = "";
    userResponse = Serial.readString();
    userResponse.toLowerCase();
    Serial.println(userResponse);
    if(userResponse == randQuad){
      Serial.println("You're right!\n");
    }else{
      Serial.print("You're wrong! The quad is: ");
      Serial.println(randQuad);
      Serial.println("  ");
    }

  }else{
    Serial.println("You didn't write anything, silly!\n");
  }
  
  delay(delayVal);
  reset();
  delay(delayVal);
  
  
  /*
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).

  }
  */
}
void turnOnFourLEDs(int a,int b,int c,int d){
  //Serial.println("These lights are on" + a + " " + b + " " + c + " " + d);
  int randRed = random(0, 255);
  int randGreen = random(0, 255);
  int randBlue = random(0, 255);
  
  pixels.setPixelColor(a, pixels.Color(randRed,randGreen,randBlue));
  pixels.show();
  pixels.setPixelColor(b, pixels.Color(randRed,randGreen,randBlue));
  pixels.show();
  pixels.setPixelColor(c, pixels.Color(randRed,randGreen,randBlue));
  pixels.show();
  pixels.setPixelColor(d, pixels.Color(randRed,randGreen,randBlue));
  pixels.show();
}

void makeQuad(String typeOfQuad){
  
  if(typeOfQuad == "trapezium"){
    turnOnFourLEDs(13, 24, 29, 50);
  }
  
  else if(typeOfQuad == "square"){
    turnOnFourLEDs(18, 20, 34, 36);

  }
  else if(typeOfQuad == "rectangle"){
    turnOnFourLEDs(18, 22, 34, 38);

  }
  else if(typeOfQuad == "parallelogram"){
    turnOnFourLEDs(19, 23, 34, 38);

  }
  else if(typeOfQuad == "rhombus"){
    turnOnFourLEDs(20, 35, 37, 52);

  } 
  else if(typeOfQuad == "trapezoid"){
    turnOnFourLEDs(17, 19, 43, 49);

  } 
  else if(typeOfQuad == "isosceles trapezoid"){
    turnOnFourLEDs(27, 29, 42, 46);

  } 
  else if(typeOfQuad == "kite"){
    turnOnFourLEDs(12, 26, 30, 52);

  } 
  else{ //not quad
    turnOnFourLEDs(20, 41, 44, 47);

  }
  
}


void testLEDS() {
  
  for(int i = 0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    //delay(delayVal); // Delay for a period of time (in milliseconds).
  }
}


void reset() {
  for(int i = 0; i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
 }
}
