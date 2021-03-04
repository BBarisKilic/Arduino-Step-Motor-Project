#include <Arduino.h>
#include <SoftwareSerial.h>

//Defines variables to set speed by delay time.
String speed = "5";
String updatedSpeed = "";
//Defines variables to set the direction of rotation.
int rotation = int('r');
//RX, TX
SoftwareSerial BTserial(2, 3);

//A method for setting the direction of rotation to right.
void turnRight()
{
  digitalWrite(8, HIGH);
  delay(speed.toInt());
  digitalWrite(8, LOW);

  digitalWrite(9, HIGH);
  delay(speed.toInt());
  digitalWrite(9, LOW);

  digitalWrite(10, HIGH);
  delay(speed.toInt());
  digitalWrite(10, LOW);

  digitalWrite(11, HIGH);
  delay(speed.toInt());
  digitalWrite(11, LOW);
}

//A method for setting the direction of rotation to left.
void turnLeft()
{
  digitalWrite(11, HIGH);
  delay(speed.toInt());
  digitalWrite(11, LOW);

  digitalWrite(10, HIGH);
  delay(speed.toInt());
  digitalWrite(10, LOW);

  digitalWrite(9, HIGH);
  delay(speed.toInt());
  digitalWrite(9, LOW);

  digitalWrite(8, HIGH);
  delay(speed.toInt());
  digitalWrite(8, LOW);
}

void setup()
{
  //Starts software serial at 9600 Baudrate.
  BTserial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void loop()
{
  while (BTserial.available() > 0)
  {
    int inChar = BTserial.read();
    //Changes speed if incoming data is an integer.
    if (isDigit(inChar))
    {
      //Converts the incoming byte to a char and adds it to the string.
      updatedSpeed += (char)inChar;
      
    }
    //Changes direction of rotation if incoming data is a char.
    else
    {
      rotation = int(inChar);
    }
    delay(20);
  }

  //Changes speed.
  if (updatedSpeed != "")
  {
    speed = updatedSpeed;
    updatedSpeed = "";
  }

  //Changes direction of rotation.
  if (rotation == int('r'))
  {
    turnRight();
  }
  else if (rotation == int('l'))
  {
    turnLeft();
  }
}