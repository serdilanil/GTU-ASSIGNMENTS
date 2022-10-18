


 void setup()
 {
  Serial.begin(9600);
  while(!Serial){
    ;
  }

  

 }
  int thisByte = 33;
 void loop(){
  
  Serial.write(72);
  Serial.write(101);
  Serial.write(108);
  Serial.write(108);
  Serial.write(111);
  Serial.write(32);
  Serial.write(109);
  Serial.write(121);
  Serial.write(32);
  Serial.write(110);
  Serial.write(97);
  Serial.write(109);
  Serial.write(101);
  Serial.write(32);
  Serial.write(105);
  Serial.write(115);
  Serial.write(32);
  Serial.write(83);
  Serial.write(101);
  Serial.write(114);
  Serial.write(100);
  Serial.write(105);
  Serial.write(108);
  Serial.write(32);
  Serial.write(65);
  Serial.write(110);
  Serial.write(196);
  Serial.write(177);
  Serial.write(108);
  Serial.write(32);
  Serial.write(195);
  Serial.write(156);
  Serial.write(110);
  Serial.write(108);
  Serial.write(195);
  Serial.write(188);
  
  if(thisByte == 33) {
   while(true){
    continue;
   }
  }
  
 }
