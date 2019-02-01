int cont = 1;

void setup() {
  Serial.begin(115200);
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(100);                       
  digitalWrite(LED_BUILTIN, LOW); 
  delay(100);     
  
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(100);                      
  digitalWrite(LED_BUILTIN, LOW);   
  delay(50);   // wait for a second

  digitalWrite(LED_BUILTIN, HIGH);  
  delay(50);                      
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500); 

  Serial.print("I'm alive hahahaha");
  Serial.print("  cont: ");
  Serial.println(cont);
  cont++;
}
