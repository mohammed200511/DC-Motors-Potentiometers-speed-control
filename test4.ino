const int motor_R = 3;
const int motor_L = 5;
const int r_R = A0;
const int r_L = A5;
const int b_R = 4;
const int b_L = 2;
int motorActiveR = 0;
int motorActiveL = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motor_R, OUTPUT);
  pinMode(motor_L, OUTPUT);
  pinMode(r_R, INPUT);
  pinMode(r_L, INPUT);
  pinMode(b_R, INPUT);
  pinMode(b_L, INPUT);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    if (command == 'r' || motorActiveR==1 || command == 'l' || motorActiveL==1){
    if (command == 'r' || motorActiveR==1) {
      analogWrite(motor_R, map(analogRead(r_R), 0, 1023, 0, 255));
      motorActiveR = 1;
    } if (command == 'l' || motorActiveL==1) {
      analogWrite(motor_L, map(analogRead(r_L), 0, 1023, 0, 255));
      motorActiveL = 1; }
    } else if (command == 's') {
      digitalWrite(motor_R, LOW);
      digitalWrite(motor_L, LOW);
      motorActiveR = 0;
      motorActiveL = 0;
    }}
   else {
    if (digitalRead(b_R) == HIGH) {
      analogWrite(motor_R, map(analogRead(r_R), 0, 1023, 0, 255));
    } else if (digitalRead(b_R) == LOW) {
      digitalWrite(motor_R, LOW);
      motorActiveR = 0;
    }
    if (digitalRead(b_L) == HIGH) {
      analogWrite(motor_L, map(analogRead(r_L), 0, 1023, 0, 255));
    } else if (digitalRead(b_L) == LOW) {
      digitalWrite(motor_L, LOW);
      motorActiveL = 0;
    }
  }
}

//     do not complite 
//    some thihg wrong