const int AirValue = 537;    // Valor no ar (seco)
const int WaterValue = 246;  // Valor no solo molhado
int intervals = (AirValue - WaterValue) / 3;
int soilMoistureValue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  soilMoistureValue = analogRead(A0);

  if (soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals)) {
    Serial.println("Very Wet");
  } 
  else if (soilMoistureValue >= (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals)) {
    Serial.println("Wet");
  } 
  else if (soilMoistureValue >= (AirValue - intervals) && soilMoistureValue < AirValue) {
    Serial.println("Dry");
  }

  delay(100);
}