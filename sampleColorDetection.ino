/*     Arduino Color Sensing Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int Rfrequency = 0, Bfrequency = 0, Gfrequency  = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  Rfrequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  //Rfrequency = map(Rfrequency, 18,237,255,0);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(Rfrequency);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  Gfrequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  //Gfrequency = map(Gfrequency, 30,268,255,0);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(Gfrequency);//printing RED color frequency
  Serial.print("  ");
  delay(100);
  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  Bfrequency = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  //Bfrequency = map(Bfrequency, 23,201,255,0);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(Bfrequency);//printing RED color frequency
//  if(Rfrequency < Bfrequency && Rfrequency < Gfrequency)
//  {
//      Serial.print(" --RED DETECTED--");//printing color name
//  }
//  else if(Bfrequency < Rfrequency && Bfrequency < Gfrequency)
//  {
//    Serial.print(" --BLUE DETECTED--");//printing color name
//  }
//  else if(Gfrequency < Rfrequency && Gfrequency < Bfrequency)
//  {
//    Serial.print(" --GREEN DETECTED--");//printing color name
//  }
//   else if(Gfrequency == Rfrequency && Gfrequency == Bfrequency)
//  {
//    Serial.print(" --WHITE DETECTED--");//printing color name
//  }
//  else
//  {
//    Serial.print(" --NO COLOR DETECTED--");
//  }
  Serial.print("The overall colour is= ");
  Serial.print("The overall colour is= ");
  Serial.println((Bfrequency + Gfrequency + Rfrequency) / 3);
  delay(100);
}
