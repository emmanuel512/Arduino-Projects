#include <AFMotor.h>

// DC motor on M3
AF_DCMotor motor3(3,MOTOR12_8KHZ);

// DC motor on M4
AF_DCMotor motor4(4, MOTOR12_8KHZ);

enum M_Direction
{
  GO_FORWARD,
  GO_BACKWARD,
  GO_RIGHT,
  GO_LEFT,
  STOP  
};

//variables and function protypes
void move_forward(void);
void move_reverse(void);
void move_stop(void);
void move_left(void);
void move_right(void);
int getDirection(int xPosition, int yPosition);

int xPin = A0;
int yPin = A1;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

enum M_Direction direct = STOP;

void setup() {
  
  Serial.begin(9600);     // set up Serial library at 9600 bps
  // initialize motor object on motor 3
  motor3.run(RELEASE);
  // intialize motor object on motor 2
  motor4.run(RELEASE);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

// Move motor in forward 
void move_forward()
{
    motor3.run(BACKWARD);
    motor3.setSpeed(255);  
  
    motor4.run(BACKWARD);
    motor4.setSpeed(255);  
}

// Stop motor
void move_stop()
{
    motor3.run(RELEASE);
    motor3.setSpeed(0);  
  
    motor4.run(RELEASE);
    motor4.setSpeed(0);  
}

// Move motor in reverse
void move_reverse()
{
    motor3.run(FORWARD);
    motor3.setSpeed(255);  
  
    motor4.run(FORWARD);
    motor4.setSpeed(255);  
}

// Move motor in right
void move_right()
{
    motor3.run(BACKWARD);
    motor3.setSpeed(255);  
  
    motor4.run(RELEASE);
    motor4.setSpeed(255);  
}

// Move motor in left
void move_left()
{
    motor3.run(RELEASE);
    motor3.setSpeed(255);  
  
    motor4.run(BACKWARD);
    motor4.setSpeed(255);   
}

// Get direction based on readings from thumbstick 
int getDirection(int xPos, int yPos)
{
  int move_direction;

  if(xPos == 521 && yPos == 1023)
  {
    Serial.println("Move Forward");
    return move_direction = GO_FORWARD;
  }

  else if(xPos == 521 && yPos == 0)
  {
    Serial.println("Move Backward");
    return move_direction = GO_BACKWARD;
  }

  else if(xPos == 1023 && yPos == 520)
  {
    Serial.println("Move Right");
    return move_direction = GO_RIGHT;
  }

  else if(xPos == 0 && yPos == 520)
  {
    Serial.print("Move Left");
    return move_direction = GO_LEFT;
  }
  
  else
  {
    return move_direction = STOP;
    Serial.println("Non valid input from thumbstick so no movement");
  }  
}


void loop() 
{
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  direct = getDirection(xPosition, yPosition);
  switch(direct)
  {
    case GO_FORWARD:
      move_forward();
      break;
    case GO_BACKWARD:
      move_reverse();
      break;
    case GO_RIGHT:
      move_right();
      break;
    case GO_LEFT:
      move_left();
      break;
    case STOP:
      move_stop();
      break;
    default:
      move_stop();
  }
}
