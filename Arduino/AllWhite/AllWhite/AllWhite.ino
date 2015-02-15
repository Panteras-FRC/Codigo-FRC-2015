#define LEDR 9
#define LEDG 11
#define LEDB 10
#define LEDstatus 13


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDstatus, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LEDR, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LEDG, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LEDB, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LEDstatus, HIGH);   // turn the LED on (HIGH is the voltage level)

}
