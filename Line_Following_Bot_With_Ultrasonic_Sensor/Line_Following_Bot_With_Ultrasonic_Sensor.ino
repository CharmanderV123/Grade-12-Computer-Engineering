
#define echoPin 10 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 11 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

//  int rmotorback = 3;
//  int rmotorfor = 5;
//  int lmotorback = 6;
//  int lmotorfor = 9;

  int rmotorback = 3;
  int rmotorfor = 5;
  int lmotorback = 6;
  int lmotorfor = 9;


  int turnspeed = 200;
  int linespeed = 100;
  int delaytime = 220;
  int ultrasonicturn = 250;
  int ultrasonicdelaytime = 435;
  
  void setup()
  {
    pinMode(rmotorfor, OUTPUT);
    pinMode(rmotorback, OUTPUT);
    pinMode(lmotorfor, OUTPUT);
    pinMode(lmotorback, OUTPUT);
    pinMode(12, INPUT);
    pinMode(13, INPUT);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
    Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
    Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
    Serial.println("with Arduino UNO R3");
  }
  
  
  void loop()
  {
    int LTracker = digitalRead(12);    
    int RTracker = digitalRead(13);  

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (To account for time travelled to and back)

if (distance < 10)
{
  analogWrite(rmotorback, 255);
  analogWrite(rmotorfor, 0);
  analogWrite(lmotorback, 255);
  analogWrite(lmotorfor, 0);
  delay(100);                       // go backwards
  analogWrite(rmotorback, ultrasonicturn);
  analogWrite(rmotorfor, 0);
  analogWrite(lmotorback, 0);
  analogWrite(lmotorfor, ultrasonicturn);
  delay(ultrasonicdelaytime);                       // turns left
}

else{

if (RTracker == LOW and LTracker == LOW)
  {
  analogWrite(rmotorback, 0);
  analogWrite(rmotorfor, 0);
  analogWrite(lmotorback, 0);
  analogWrite(lmotorfor, 0);
  }

  
if (RTracker == HIGH and LTracker == LOW)
    {
    analogWrite(lmotorfor, turnspeed);
    analogWrite(rmotorback, turnspeed);
    analogWrite(rmotorfor, 0);
    analogWrite(lmotorback, 0);
    delay(delaytime);
    }


if (RTracker == LOW and LTracker == HIGH)
  {
  analogWrite(rmotorback, 0);
  analogWrite(rmotorfor, turnspeed);
  analogWrite(lmotorback, turnspeed);
  analogWrite(lmotorfor, 0);
  delay(delaytime);
  }




else
  {
  analogWrite(rmotorback, 0);
  analogWrite(rmotorfor, linespeed);
  analogWrite(lmotorback, 0);
  analogWrite(lmotorfor, linespeed);
  }
}
  }


//  analogWrite (motorB1,100); // rightbackward
//  analogWrite(motorB2,0);   // rightforward
//  analogWrite(motorA2,0);   // leftbackward 
//  analogWrite (motorA1,100); // leftforward

       
