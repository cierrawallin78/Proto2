
#define ENA_m1 10        // Enable/speed motor Front Right Left
#define ENB_m1 3        // Enable/speed motor Back Right

#define IN_11  9     // L298N #1 in 1 motor Front Left
#define IN_12  8     // L298N #1 in 2 motor Front left I think one of these must be left
#define IN_13  5     // L298N #1 in 3 motor Back Right
#define IN_14  4     // L298N #1 in 4 motor Back Right left?

int speedy = 50; // 50 - 255.
//int speed_Coeff = 4;
char t;


void setup() {
  // put your setup code here, to run once:
  //pinMode(13,OUTPUT);   //left 
  //pinMode(12,OUTPUT);   //right
  //pinMode(-9,OUTPUT);   //left
  //pinMode(8,OUTPUT);   //right 

  pinMode(ENA_m1, OUTPUT);//speed front right
  pinMode(ENB_m1, OUTPUT);//speed back right
 
    pinMode(IN_11, OUTPUT);
    pinMode(IN_12, OUTPUT);
    pinMode(IN_13, OUTPUT);
    pinMode(IN_14, OUTPUT);

 
  
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
  t = Serial.read();
  //Serial.println(t);
}
if(digitalRead(BTState)==LOW) { state='S'; }

else if (t == '1'){
      speedy=50;}
    else if (t == '2'){
      speedy=75;}
    else if (t == '3'){
      speedy=100;}

else if(t == 'l' || t == 'L'){
  digitalWrite(IN_11,HIGH);//front left
  digitalWrite(IN_12, LOW);//back left
  analogWrite(ENA_m1, speedy);

  digitalWrite(IN_13, LOW);//back right
  digitalWrite(IN_14,HIGH);//front right
  analogWrite(ENB_m1, speedy);
  //Serial.println("moving forward");
}

else if(t == 'r' || t == 'R'){
  
  digitalWrite(IN_11,LOW);
  digitalWrite(IN_12, HIGH);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_13, HIGH);
  digitalWrite(IN_14,LOW);
  analogWrite(ENB_m1, speedy);
  //Serial.println("moving backward");
}

else if (t == 'f' || t == 'F'){
  digitalWrite(IN_11,LOW);
  digitalWrite(IN_12,HIGH);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_13,LOW);
  digitalWrite(IN_14,HIGH);
 // Serial.println("moving left");
}

else if (t == 's' || t == 'S'){
  digitalWrite(IN_11,LOW);
  digitalWrite(IN_12,LOW);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_13,LOW);
  digitalWrite(IN_14,LOW);
  analogWrite(ENB_m1, speedy);
  //Serial.println("stop");
  
  
}
else if (t == 'b' || t == 'B'){
  digitalWrite(IN_11,HIGH);
  digitalWrite(IN_12,LOW);
  digitalWrite(IN_13,HIGH);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_14,LOW);
  
  //Serial.println("moving right");


  
}
else{
  digitalWrite(IN_11,LOW);
  digitalWrite(IN_12,LOW);
  analogWrite(ENA_m1, speedy);
  digitalWrite(IN_13,LOW);
  digitalWrite(IN_14,LOW);
  analogWrite(ENB_m1, speedy);
}


}
