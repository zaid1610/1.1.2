const int gasSensorPin = A0; // Analog pin connected to the gas sensor output

float resistance; // Variable to store gas sensor resistance value
float ppm;        // Variable to store gas concentration in parts per million (PPM)
void setup() {
  Serial.begin(9600);
  pinMode(gasSensorPin, INPUT);
}
float readGasSensorData() {
  int sensorValue = analogRead(gasSensorPin); // Read the sensor value

  // Calculate the sensor resistance using the known resistor value (Rs/Ro = 10)
  resistance = ((1023 / (float)sensorValue) - 1) * 10000;

  // Use a formula to calculate the gas concentration in PPM
  ppm = 116.6020682 * pow(resistance / 10000, -2.769034857);

  return ppm;
}
void loop() {
  float gasConcentration = readGasSensorData();

  Serial.print("Gas Concentration (PPM): ");
  Serial.println(gasConcentration);

  delay(2000); // Add a delay to avoid rapid sensor readings
}
