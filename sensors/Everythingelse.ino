void setup() {
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}


void loop() {
	int sensor=AnalogRead(A0);
	Serial.println(sensor);

}
