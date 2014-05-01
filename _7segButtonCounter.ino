/*
2/2/2012
This sketch displays an initialization animation and 
starts a decimal counter that counts down when a button 
is pressed. Hardware is one shift register, a button, 
and a 7-seg. Biggest problem is that the button must
be pressed twice in order to go from 9 to 8. This only 
occurs after the animation though.
*/


int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

const int buttonPin = 2;    
const int ledPin =  13;      
int buttonState = 0;  
int i = 10;
bool anim = true;
  
void setup() 
{
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
  digitalWrite(0, HIGH);

  
  buttonState = digitalRead(buttonPin);
  
  
  if (anim == true)
  {
     animate(); 
     anim = false;
     
     digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, decimal(9));
    digitalWrite(latchPin, HIGH); 
    delay(200);
  }
  
  
  if (buttonState == HIGH) 
  {         
    digitalWrite(ledPin, HIGH); 
    
    
    if (i < 0)
    {
      i = 10;
    }
    else
    {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, decimal(i));
      digitalWrite(latchPin, HIGH); 
      delay(200);
    }
    
    i--;

  } 
  else 
  { 
    digitalWrite(ledPin, LOW); 
    digitalWrite(latchPin, LOW);
  }

  
}

int decimal(int number)
{
 switch (number)
 {
   case 0: return 126;
   break;
   case 1: return 48;
   break;
   case 2: return 109;
   break;
   case 3: return 121;
   break;
   case 4: return 51;
   break;
   case 5: return 91;
   break;
   case 6: return 95;
   break;
   case 7: return 112;
   break;
   case 8: return 127;
   break;
   case 9: return 123;
   break;
   default:
   break;
 }
}

void animate()
{
  
  
    
 
  for (i = 0; i < 3; i++)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 1);
    digitalWrite(latchPin, HIGH); 
    delay(100);
    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0);
    digitalWrite(latchPin, HIGH); 
    delay(150);
  }
  
  digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, 0);
    digitalWrite(latchPin, HIGH); 
    delay(125); 
  
   for (int i = 0; i < 10; i++)
  {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, decimal(i % 9 + 1));
    digitalWrite(latchPin, HIGH); 
    delay(50);
    
  } 
  
  i = -1;
}
