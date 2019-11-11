
void F_sensor() {

  digitalWrite(trig_front, 0);
  delayMicroseconds(2);
  digitalWrite(trig_front, 1);
  delayMicroseconds(10);
  digitalWrite(trig_front, 0);
 
  duration_F = pulseIn(echo_front, 1);
  distance_F = duration_F / 58.2;
 // Serial.print("distance_F: ");
 // Serial.println(distance_F);
   delay(10);
}
