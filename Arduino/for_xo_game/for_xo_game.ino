int switch1 = 2;
int switch2 = 3;
int switch3 = 4;
int count;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  count = 0;
}


void loop() {
  // read the input pin:
  int s1State = digitalRead(switch1);
  int s2State = digitalRead(switch2);
  int s3State = digitalRead(switch3);


  if(s1State == 1 && s2State == 1 && s3State == 1){
    count++;
    Serial.println(count);
    delay(5000);
    }
    
  delay(1);

  
}
