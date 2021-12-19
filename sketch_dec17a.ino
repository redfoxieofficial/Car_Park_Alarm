#define trig 9
#define echo 10
#define beyaz 2
#define yesil 3
#define sari 4
#define kirmizi 5
#define buzzer 11

int mesafe;
int sure;




void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(beyaz,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(sari,OUTPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
}
int mesafebul(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  sure = pulseIn(echo,HIGH); //echo pini ne zaman high olmuş
  mesafe = (sure/2)/29.1;            // yol = hız.zaman
  return mesafe;
  
}

void loop() {

   Serial.println(mesafebul());
   delay(50);

   if (mesafe > 60){
    digitalWrite(kirmizi,LOW);
    digitalWrite(yesil,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(beyaz,HIGH);

    
        
   }
   else if (mesafe < 60 and mesafe > 40){
    digitalWrite(beyaz,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(kirmizi,LOW);
    digitalWrite(yesil,HIGH);
    tone(buzzer,300);
    delay(700);
    noTone(buzzer);
   }
   else if (mesafe < 40 and mesafe > 20){
    digitalWrite(beyaz,LOW);
    digitalWrite(yesil,LOW);
    digitalWrite(kirmizi,LOW);
    digitalWrite(sari,HIGH);
    
    tone(buzzer,300);
    delay(300);
    noTone(buzzer);
   }
   else if (mesafe < 20 and mesafe > 0){
    digitalWrite(beyaz,LOW);
    digitalWrite(yesil,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(kirmizi,HIGH);
    tone(buzzer,300);
    delay(200);
    noTone(buzzer);

   }
   else if (mesafe < 10 and mesafe > 0){
    digitalWrite(kirmizi,HIGH);
    
    tone(buzzer,100);
    delay(50);
    noTone(buzzer);

   }
   
   
}
