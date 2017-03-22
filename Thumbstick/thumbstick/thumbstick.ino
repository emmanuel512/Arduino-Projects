int xPin = A0;
int yPin = A1;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  // initialize serial communications at 9600 bps
  Serial.begin(9600);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  // activiate pull-up resistor on the push-button pin
  pinMode(buttonPin, INPUT_PULLUP);
  // pinMode(buttonPin, INPUT);
  // digitalWrite(buttonPin, HIGH);
  Serial.println("Getting Reads from ThumbStick");
}


void loop() {
  // put your main code here, to run repeatedly:
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
  
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);

  delay(100); //add some delay between reads
}
