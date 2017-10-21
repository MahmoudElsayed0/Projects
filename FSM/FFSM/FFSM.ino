void(*state)();

void waiting();
void driving();

int distance;
void stop_()
{

}

void forward()
{

}
/* state functions */


void waiting()
{
  stop_();
  distance = 160;
  if (distance > 150)
  {
    state = driving;
    Serial.println("driving");
  }
}

void driving() 
{
  forward();
  distance = 40;
  if (distance < 50)
  {
    state = waiting;
    Serial.println("waiting");
  }
}

void setup() {
  // put your setup code here, to run once:
  state = waiting;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state();
}
