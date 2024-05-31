//Determining arduino pins to be use
int o1 = 2;
int o2 = 3;
int x1 = 7;
int x2 = 8;
int countero;
int counterx;
int xa = 9;
int xb = 10;
int xc = 11;
int xd = 12;
int xe = 13;
int xf = 14;
int xg = 15;

const int data = 4;  // Arduino pin for data pin of the shift register
const int latch = 5;  // Arduino pin for latch pin of the shift register
const int clock = 6;  // Arduino pin for clock pin of the shift register
const char common = 'a'; // 7-segment with common cathode
void setup() {
  // assigning the working modes to the shift register pins and other pins for arduino
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(o1, INPUT);
  pinMode(o2, INPUT);
  pinMode(x1, INPUT);
  pinMode(x2, INPUT);
  Serial.begin(9600);
  countero = 0;
  counterx = 0;
  pinMode(xa, OUTPUT);
  pinMode(xb, OUTPUT);
  pinMode(xc, OUTPUT);
  pinMode(xd, OUTPUT);
  pinMode(xe, OUTPUT);
  pinMode(xf, OUTPUT);
  pinMode(xg, OUTPUT);
}

void loop() {


  //First code for counter x
  int x1state = digitalRead(x1);
  int x2state = digitalRead(x2);

  if(counterx == 0){
    digitalWrite(xa, HIGH);
    digitalWrite(xb, HIGH);
    digitalWrite(xc, HIGH);
    digitalWrite(xd, HIGH);
    digitalWrite(xe, HIGH);
    digitalWrite(xf, HIGH);
    digitalWrite(xg, LOW);
    }

  if(x1state == 1 || x2state == 1){
    counterx++;
    Serial.print("Counter X: ");
    Serial.println(counterx);
    delay(5000);

    if(counterx == 1){
    digitalWrite(xa, LOW);
    digitalWrite(xb, HIGH);
    digitalWrite(xc, HIGH);
    digitalWrite(xd, LOW);
    digitalWrite(xe, LOW);
    digitalWrite(xf, LOW);
    digitalWrite(xg, LOW);
    }

    if(counterx == 2){
    digitalWrite(xa, HIGH);
    digitalWrite(xb, HIGH);
    digitalWrite(xc, LOW);
    digitalWrite(xd, HIGH);
    digitalWrite(xe, HIGH);
    digitalWrite(xf, LOW);
    digitalWrite(xg, HIGH);
    }

    if(counterx == 3){
    digitalWrite(xa, HIGH);
    digitalWrite(xb, HIGH);
    digitalWrite(xc, HIGH);
    digitalWrite(xd, HIGH);
    digitalWrite(xe, HIGH);
    digitalWrite(xf, HIGH);
    digitalWrite(xg, LOW);
    }

    if(counterx == 4){
    digitalWrite(xa, LOW);
    digitalWrite(xb, HIGH);
    digitalWrite(xc, HIGH);
    digitalWrite(xd, LOW);
    digitalWrite(xe, LOW);
    digitalWrite(xf, HIGH);
    digitalWrite(xg, HIGH);
    }

    if(counterx == 5){
    digitalWrite(xa, HIGH);
    digitalWrite(xb, LOW);
    digitalWrite(xc, HIGH);
    digitalWrite(xd, HIGH);
    digitalWrite(xe, LOW);
    digitalWrite(xf, HIGH);
    digitalWrite(xg, HIGH);
    }

    if(counterx == 6){
    digitalWrite(xa, HIGH);
    digitalWrite(xb, LOW);
    digitalWrite(xc, HIGH);
    digitalWrite(xd, HIGH);
    digitalWrite(xe, HIGH);
    digitalWrite(xf, HIGH);
    digitalWrite(xg, HIGH);
    }

    if(counterx == 7){
    digitalWrite(xa, HIGH);
    digitalWrite(xb, HIGH);
    digitalWrite(xc, HIGH);
    digitalWrite(xd, LOW);
    digitalWrite(xe, LOW);
    digitalWrite(xf, LOW);
    digitalWrite(xg, LOW);
    }

    if(counterx == 8){
    digitalWrite(xa, HIGH);
    digitalWrite(xb, HIGH);
    digitalWrite(xc, HIGH);
    digitalWrite(xd, HIGH);
    digitalWrite(xe, HIGH);
    digitalWrite(xf, HIGH);
    digitalWrite(xg, HIGH);
    }

    if(counterx == 9){
    digitalWrite(xa, HIGH);
    digitalWrite(xb, HIGH);
    digitalWrite(xc, HIGH);
    digitalWrite(xd, HIGH);
    digitalWrite(xe, LOW);
    digitalWrite(xf, HIGH);
    digitalWrite(xg, HIGH);
  }
 }
  
  //Second code for counter o with OUTPUT shift registers
  int o1state = digitalRead(o1);
  int o2state = digitalRead(o2);
  if(countero == 0){
    byte bits = binary(0);
    display(bits);
  }
  
  if(o1state == 1 || o2state == 1){
    countero++;
    Serial.print("Counter O: ");
    Serial.println(countero);
    delay(500);
  
  if(int i = countero) {// for loop to generate number from 0 to 9
  byte bits = binary(i) ; /* detect the binary given for respective number from the cases given below */
   
    display(bits);    // displaying the numbers on 7-segment    
  }
 }
}

void display(byte eightBits) {
  if (common == 'a') { // if the configuration is common cathode
    eightBits = eightBits ^ B11111111;  // then change the bits from 0 to 1  
  }
  digitalWrite(latch, LOW);  // preparing shift register for data
  shiftOut(data, clock, LSBFIRST, eightBits); /* sending the data to  7segmnet starting from least significant bit*/
  digitalWrite(latch, HIGH); /* displaying the data on the 7 segment */
}
/*cases for detecting the binary of the numbers generated from 0 to 9 */
byte binary (int Number) {
  switch (Number) {
    case 0:
      return B00000001;// if 0 is generated then binary for zero  
      break;
    case 1:
      return B11001111;// if 1 is generated then giving binary for one
      break;
    case 2:
      return B10010010;// if 2 is generated then giving binary for two
      break;
    case 3:
      return B10000110;// if 3 is generated then giving binary for three  
      break;
    case 4:
      return B11001100;// if 4 is generated then giving binary for four
      break;
    case 5:
      return B10100100;// if 5 is generated then giving binary for five
      break;
    case 6:
      return B10100000;// if 6 is generated then giving binary for six
      break;
    case 7:
      return B10001111;// if 7 is generated then giving binary for seven
      break;
    case 8:
      return B10000000;// if 8 is generated then giving binary for eight
      break;
    case 9:
      return B10000100; // if 9 is generated then giving binary for nine  
  }
}
