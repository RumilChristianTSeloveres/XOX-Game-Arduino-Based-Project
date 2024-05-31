int o1 = 2;
int x1 = 3;
int countero;
int counterx;

void setup() {
  // put your setup code here, to run once:
  pinMode(o1, INPUT);
  pinMode(x1, INPUT);
  countero = 0;
  counterx = 0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int o1state = digitalRead(o1);
  int x1state = digitalRead(x1);
  if(o1state == 1){
    countero++;
    Serial.print("Counter O: ");
    Serial.println(countero);
    delay(5000);
  }
  if(x1state == 1){
    counterx++;
    Serial.print("Counter X: ");
    Serial.println(counterx);
    delay(5000);
  }
}
