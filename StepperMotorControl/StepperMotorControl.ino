// The Threashold to stop the motor
int Threashold = 120;
// The destance for emergancy
int min_step = 1000;
// 40000 for one cycle
unsigned int cycle_num = 10600;
// Wating time when if fully open
int Wating_time = 5000;
/*****************************************/

// High Froward "Open"
// Low Reverse  "Close"

// Button for open the door
int Button = 2;
// LED to show that the door is close
int closePin = 8;
// LED to show that the door is open
int openPin = 9;
// Motor control pin
int PUL = 6; //define Pulse pin
int DIR = 5; //define Direction pin
int ENA = 7; //define Enable Pin

/******************************************/

// How many cycle until the door is open
// Add to open
// Sub to close
volatile unsigned int counter = 0;
// Mode of the system
volatile byte mode = LOW;
/***************************************/
void setup() {

  pinMode (PUL, OUTPUT);
  pinMode (DIR, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode(openPin, OUTPUT);
  pinMode(closePin, OUTPUT);
  pinMode(Button,  INPUT);
  attachInterrupt(digitalPinToInterrupt(Button), changeMode, LOW);
  //Serial.begin(9600);
}

void loop() {
  // wait when open and close
  if (counter == cycle_num && mode)
  {
    Serial.println("Wait");
    // Stop motor
    Stop();
    // Wating time for the door
    delay(Wating_time);
    // Close the door
    while (counter && mode)
    {
      // Close direction
      Backword();
      counter -= 1;
    }
    // The door is now close
    mode = LOW;

  }
  // wait when close
  else if (!mode)
  {
    // Stop
    Stop();
    digitalWrite(closePin, HIGH);
    digitalWrite(openPin, LOW);
  }
  // move to open
  else if (mode)
  {
    // open direction
    Forward();
    counter += 1;
    digitalWrite(openPin, HIGH);
    digitalWrite(closePin, LOW);


  }
}

void changeMode()
{
  mode = !mode;
}


void Forward()
{
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(DIR, LOW);
    digitalWrite(ENA, HIGH);
    digitalWrite(PUL, HIGH);
    delayMicroseconds(.00001);
    digitalWrite(PUL, LOW);
    delayMicroseconds(.00001);
  }
}

void Backword()
{
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(DIR, HIGH);
    digitalWrite(ENA, HIGH);
    digitalWrite(PUL, HIGH);
    delayMicroseconds(0.00001);
    digitalWrite(PUL, LOW);
    delayMicroseconds(0.00001);
  }
}

void Stop()
{
  digitalWrite(ENA, HIGH);
  delay(500);
}
