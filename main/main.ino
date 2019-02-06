int cont = 1;
int rele = 4;

void setup() {
  Serial.begin(115200);
  
  pinMode(rele, OUTPUT);
}

void loop() {
  digitalWrite(rele, HIGH);   
  delay(2000);                       
  digitalWrite(rele, LOW); 
  delay(2000);     

  Serial.print("I'm alive hahahaha");
  Serial.print("  cont: ");
  Serial.println(cont);
  cont++;
}
