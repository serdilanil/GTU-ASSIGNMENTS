int input;
int output;
int x=-1;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0)
  {
    input=Serial.read();

    
    if(input=='a')
    {
    digitalWrite(LED_BUILTIN, HIGH);
    }
    
      
    if(input=='b')
    {
    digitalWrite(LED_BUILTIN, LOW);
    }
    

    if(input=='c')
    {
      digitalWrite(LED_BUILTIN, LOW);
      
      delay(500);
      
      for(int i=0; i<7; i++)
        {
          
        if(i==0 || i==2 || i==4)
          {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          }
          
        if(i==1 || i==3 || i==5)
          {
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
          }
        
        }
    }


    if(input=='d')
      {
      
      while(x==-1){
        x=Serial.read();
      }
      output=x*x;
      Serial.println(output);
      x=-1;
      
      }       
  }
}    
