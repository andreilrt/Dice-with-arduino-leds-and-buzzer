int randNumber;
int lastButtonState = 0;
int count = 0;
int buttonState;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT); //LED
  pinMode(3, OUTPUT); //LED
  pinMode(4, OUTPUT); //LED
  pinMode(5, OUTPUT); //LED
  pinMode(6, OUTPUT); //LED
  pinMode(7, OUTPUT); //LED
  pinMode(8, OUTPUT); //LED
  pinMode(9, INPUT); //boton
  pinMode(10, OUTPUT); //buzzer
  randomSeed(analogRead(0));
}

void loop()
{
  buttonState = digitalRead(9);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  if (buttonState != lastButtonState){
    if(buttonState==HIGH){
      count++;
    }
  }
  if (count%2==0){
    randNumber = random(1, 7);
  }
  else{
    randNumber = 0;
    noTone(10);
  }
  lastButtonState = buttonState;
  Serial.println(randNumber);
  if(randNumber == 1){
    digitalWrite(6, HIGH);
    tone(10, 6000, 300);
  }
  if(randNumber == 2){
    digitalWrite(7, HIGH);
    digitalWrite(2, HIGH);
    tone(10, 9000, 300);
  }
  if(randNumber == 3){
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(2, HIGH);
    tone(10, 8000, 300);
  }
  if(randNumber == 4){
    digitalWrite(7, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(3, HIGH);
    tone(10, 10550, 300);
  }
  if(randNumber == 5){
    digitalWrite(7, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);
    tone(10, 5600, 300);
  }
  if(randNumber == 6){
    digitalWrite(7, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    tone(10, 4000, 300);
  }
  delay(600);
}
