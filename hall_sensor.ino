// set nomor pin 
const int ledPin1 = 16;
const int ledPin2 = 17;

const int threshold = 50;

// variabel untuk menyimpan nilai touch pin
int touchValue;

void setup(){
  Serial.begin(115200);
  delay(1000);
  // menginisiasi ledpin1 dan ledpin2 sebagai output
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
}

void loop(){
  // membaca state yang dihasilkan dari nilai hallRead
  int measurement = 0;
  measurement = hallRead();
  Serial.print(measurement); 
  // melakukan pengecekan apakah nilai treshold lebih kecil dari nilai touchValue
  // jika iya maka menyalakan LED
  if(measurement > threshold){
    // menyalakan LED
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    Serial.println(" - LED on");
  }
  else{
    // mematikan LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    Serial.println(" - LED off");
  }
  delay(500);
}
