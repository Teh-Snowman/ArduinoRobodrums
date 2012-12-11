/* ROBO - DRUMS 
Name: Josh Dusome
Date: Dec 10 2012
This program recieves input from vibration
sensors mounted on the bottom of two drums
, then temporarily powers a corresponding LED
on a breadboard.
*/

//Variable Declaration

//General Variables
unsigned char state1 = 0;
unsigned char state2 = 0;

//Socket Variables
int drumSensor1=2; //attachInterrupt0
int drumSensor2=3; //attachInterrupt1
int light1=4;
int light2=5;

//Time Variables
int flash=2; //wait duration on light flash

void setup()
{
  pinMode(drumSensor1,INPUT); //Vib Sensor
  pinMode(drumSensor2,INPUT); //Vib Sensor
  pinMode(light1,OUTPUT); //LED
  pinMode(light2,OUTPUT); //LED
  attachInterrupt(0, LED1, RISING); //drumSensor1 interrupt
  attachInterrupt(1, LED2, RISING); //drumSensor2 interrupt
}

void loop()
{
  //If both drums are played both lights turn ON
  if(state1 !=0 && state2 !=0)
      {
        //RESET State
        state1 = 0;
        state2 = 0;
        //Power Lights
        digitalWrite(light1,HIGH);
        digitalWrite(light2,HIGH);
        //Wait
        delay(flash);
      }
      //If one drum is played one light turns on
  else if(state1 !=0 && state2 ==0)
      {
        //RESET State
        state1 = 0;
        //Power Light
        digitalWrite(light1,HIGH);
        //Wait
        delay(flash);
      }
      //If one drum is played one light turns on
  else if(state1 ==0 && state2 !=0)
      {
        //RESET State
        state2 = 0;
        //Power Lights
        digitalWrite(light2,HIGH);
        //Wait
        delay(flash);
      } 
   //If no drums are played the lights remain OFF   
  else
       //Turn Off Lights
       digitalWrite(light1,LOW);
       digitalWrite(light2,LOW);
  
}
//LED1 Function - changes state1
void LED1()
{
  state1++; 
}  
//LED2 Function - changes state2
void LED2()
{
  state2++;
}
