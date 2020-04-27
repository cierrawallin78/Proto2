
#define ENA_m1 10        // Enable/speed motor Front 
#define ENB_m1 3        // Enable/speed motor Back

#define IN_11  9     // L298N #1 in 1 motor Front Left
#define IN_12  8     // L298N #1 in 2 motor back left 
#define IN_13  5     // L298N #1 in 3 motor Back Right
#define IN_14  4     // L298N #1 in 4 motor front right

int speedy = 50; // 50 - 255 (speed options)

char t; //initializes character for serial reading


void setup() {
  // put your setup code here, to run once:
  //pinMode(13,OUTPUT);   //left 
  //pinMode(12,OUTPUT);   //right
  //pinMode(-9,OUTPUT);   //left
  //pinMode(8,OUTPUT);   //right 

  pinMode(ENA_m1, OUTPUT);
  pinMode(ENB_m1, OUTPUT);
 
    pinMode(IN_11, OUTPUT);
    pinMode(IN_12, OUTPUT);
    pinMode(IN_13, OUTPUT);
    pinMode(IN_14, OUTPUT);

 
  
Serial.begin(9600);
}

void loop() {
 //if serial is available, read
  if(Serial.available()>0){
  t = Serial.read();

}
  //if connection is lost, halt
if(digitalRead(BTState)==LOW) { state='S'; }

//if speed control is 1, car is slow
  //if speed control is 2, car is medium speed
  //if speed control is 3, car is fast
else if (t == '1'){
      speedy=50;}
    else if (t == '2'){
      speedy=75;}
    else if (t == '3'){
      speedy=100;}

 //turns car left
else if(t == 'l' || t == 'L'){
  digitalWrite(IN_11,HIGH);//front left
  digitalWrite(IN_12, LOW);//back left
  analogWrite(ENA_m1, speedy);

  digitalWrite(IN_13, LOW);//back right
  digitalWrite(IN_14,HIGH);//front right
  analogWrite(ENB_m1, speedy);
  
}
//turns car right
else if(t == 'r' || t == 'R'){
  
  digitalWrite(IN_11,LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14,LOW);
  analogWrite(ENB_m1, speedy);
  
}
//car moves forwards
else if (t == 'f' || t == 'F'){
  digitalWrite(IN_11,LOW);
  digitalWrite(IN_12,HIGH);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_13,LOW);
  digitalWrite(IN_14,HIGH);

}
//car stops
else if (t == 's' || t == 'S'){
  digitalWrite(IN_11,LOW);
  digitalWrite(IN_12,LOW);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_13,LOW);
  digitalWrite(IN_14,LOW);
  analogWrite(ENB_m1, speedy);

  
  
}
  //car moves backwards
else if (t == 'b' || t == 'B'){
  digitalWrite(IN_11,HIGH);
  digitalWrite(IN_12,LOW);
  digitalWrite(IN_13,HIGH);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_14,LOW);
  



  
}
  //if no input is received, car halts
else{
  digitalWrite(IN_11,LOW);
  digitalWrite(IN_12,LOW);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_13,LOW);
  digitalWrite(IN_14,LOW);
  analogWrite(ENB_m1, speedy);
}


}
