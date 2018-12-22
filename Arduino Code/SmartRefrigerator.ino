#include <SoftwareSerial.h>
SoftwareSerial mySerial(9,10);   // initializing pwm pins for serial communication between Arduino and GSM Module. Put tx of GSM module to pin 9 ,rx of GSM module to pin 10 of arduino    
int trig= 5; 
int echo= 6;    // initializing ultrasonic sensor's trigger and echo pin number, Connect the ultrasonic sensor respectively.  
char s;         // Count Variable
int a= 1;       // Control variable, if a is 1,scanning is resumed. If a=0, scanning is paused. 
long du, di;    // Variables to calculate distance

void setup() {
   mySerial.begin(9600); delay(100);       //Set Baud Rate of GSM Module
   pinMode(trig, OUTPUT);
   pinMode(echo, INPUT);
   pinMode(2, INPUT);   // push button pin
   mySerial.println("AT+CNMI=2,2,0,0,0");  //For GSM Module to Receive Message
   delay(1000);    
}

void loop() {
       
  if (a==1){                                                                    //Scanning Process
  digitalWrite(trig,HIGH);delayMicroseconds(10); digitalWrite(trig,LOW);
  du=pulseIn(echo, HIGH);
  di=(du/2)/29.1; 
  if (di>18&&di<=22)                                                           // Calibrate the distances according to your setup    
  {a=0;SendMessage_eggover(); delay(15000);}
  }
      
       if (mySerial.available()>0){               // Checks for Received Message and takes necessary action  
       char received=mySerial.read();             // Note: Send the message to the GSM module that you define for an particular action, For example, here "?" is sent to find the eggs quantity. 
       if(received=='?')
       { 
        digitalWrite(trig,HIGH); 
        delayMicroseconds(10);digitalWrite(trig,LOW);
        du=pulseIn(echo,HIGH);di=(du/2)/29.1;
        if (di<=7){s='3';}
        else if(di>7&&di<=11){s='2';}                                         // Calibrate the distances as per your setup
        else if(di>11&&di<=16){s='1';}
        SendMessage_enquiry();
        delay(15000);}                             

       else if (received=='y')                  // if user replies 'yes'
       {SendMessage_eggorder_retailer(); delay(15000);a=1;}

                                   
       else if (received=='r')                 // if user wants to find recipe and sends 'recipe'
       {SendMessage_recipe();delay(15000);}
       
       }

int pushbutton=digitalRead(2); // press the push button if you do not want to order and resume scanning. Attach a push button to pin2
    if(pushbutton==HIGH)       // Scaaning could also be resumed  by creating a loop such that sending a 'no' would make a=1      
    {a=1;}

    
delay(10);
} //end of main loop

 void SendMessage_eggover()                                               // Loop for sending Notification of Eggs Finished
{
 
  mySerial.println("AT+CMGF=1");                                          // Set the GSM SIM 900A in Text Mode           
  delay(1000);                                                            // 1 second delay for stability      
  mySerial.println("AT+CMGS=\"+91**********\"\r");                        // put user's mobile number
  delay(1000);
  mySerial.println("Eggs are Finished, Do you want to place an order?");  // put the desired string
  delay(1000);
  mySerial.println((char)26);
  delay(1000);
}

 void SendMessage_enquiry()                                               // Loop for Enquiry of present quantity  
{
  
  mySerial.println("AT+CMGF=1");  
  delay(1000);  
  mySerial.println("AT+CMGS=\"+91**********\"\r");                        //put user's mobile number    
  delay(1000);
  mySerial.println("Quantity of Eggs in Refrigerator = ");
  delay(50);
  mySerial.print(s);
  delay(50);
  mySerial.println((char)26);
  delay(1000);
}

 void SendMessage_eggorder_retailer()                                     // Loop for Order message to Retailer
{
  mySerial.println("AT+CMGF=1");  
  delay(1000);  
  mySerial.println("AT+CMGS=\"+91**********\"\r");                        //put Grocery Store's number 
  delay(1000);
  mySerial.println("Please deliver the order : 1 Dozen eggs  to address:XYZ , time:after 8pm");
  delay(100);
  mySerial.println((char)26);                                             // to indicate end of sending session 
  delay(1000);
}


 void SendMessage_recipe()                                                // Loop of Example Recipe Link           
{
  mySerial.println("AT+CMGF=1");  
  delay(1000);  
  mySerial.println("AT+CMGS=\"+91**********\"\r");                        // put user's mobile number         
  delay(1000);
  mySerial.println("https://www.vegrecipesofindia.com/tomato-recipes-tamatar-recipes/");      //create database of recipe links and Nutritive values of foods 
  delay(100);
   mySerial.println((char)26);
  delay(1000); 
}
