int pinRosso = 11;
int pinGiallo = 10;
int pinBianco = 9;
int pinVerde = 8;
int durata = 0;
int cicli = 0;
String byteRicevuto = "";
void setup() {
  pinMode(pinRosso, OUTPUT);
  pinMode(pinGiallo, OUTPUT);
  pinMode(pinBianco, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Serial.println("Seriale accesa");
}
void loop() {
  Serial.println("Inserisci quanti cicli devono fare i led");
  while (Serial.available() == 0);
  byteRicevuto = Serial.readString();
  Serial.print("Cicli ricevuti: ");
  Serial.println(byteRicevuto);
  cicli = byteRicevuto.toInt();
  durata = random(1,10);
  durata = durata*1000;  //Qui moltiplico il numero random per mille in quanto il range del random è 1,10. Lo moltiplico per mille perchè la durata è in millisecondi
  Serial.print("La durata random è: ");
  Serial.print(durata);
  Serial.println(" millisecondi");
  for(int i = 0; i < cicli; i++){
    digitalWrite(pinRosso, HIGH);
    delay(durata);
    digitalWrite(pinRosso,LOW);
    digitalWrite(pinGiallo, HIGH);
    delay(durata*2);
    digitalWrite(pinGiallo,LOW);
    digitalWrite(pinBianco, HIGH);
    delay(durata);
    digitalWrite(pinBianco,LOW);
    digitalWrite(pinVerde, HIGH);
    delay(durata*3);
    digitalWrite(pinVerde,LOW);
    Serial.print("Ciclo ");
    Serial.print(i+1);
    Serial.println(" finito");
  }
}
