int pushbutton = 7;
int led = 11;
int state = -1;
int potent = A5;
float bright = 255;
int mark=1;
int ring = 3;
int time = 0;
void setup() {
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushbutton, INPUT);
  pinMode(led,OUTPUT);
  pinMode(potent,INPUT);
  pinMode(ring,OUTPUT);
}

void loop() {
  // read the input pin:
  int potentgio = analogRead(potent);
  float light = (potentgio / 1023.0) * 50;
  if(bright<=0+light || bright>=255-light) mark*=-1;
  bright+=light*mark;
  if(digitalRead(pushbutton))
  {
    time++;
    analogWrite(ring,254);
    state=-state;
  }
  else
    analogWrite(ring,0);
  if(state==1)
  {
    //digitalWrite(led,HIGH);
    analogWrite(led,bright);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  
  Serial.println("\n\n");
  
   Serial.print("LED status: ");
   if(state==1) Serial.println("On");
   else Serial.println("Off");
   
   Serial.print("Potentiometer value: ");
   Serial.println(light);
   
   Serial.print("Fading value: ");
   Serial.println(light*mark);
   
   Serial.print("Time pushed: ");
   Serial.println(time);
  
  
  
  delay(300);        // delay in between reads for stability
}
