
void LF_sensor() {

  digitalWrite(trig_l_back, 0);
  delayMicroseconds(2);
  digitalWrite(trig_l_back, 1);
  delayMicroseconds(10);
  digitalWrite(trig_l_back, 0);
 
  duration_LB = pulseIn(echo_l_back, 1);
  distance_LB = duration_LB/ 58.2;
 // Serial.print("distance_LB: ");
 // Serial.println(distance_LB);
   delay(10);
}
