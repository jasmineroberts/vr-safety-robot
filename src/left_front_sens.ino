
void LB_sensor() {

  digitalWrite(trig_l_front, 0);
  delayMicroseconds(2);
  digitalWrite(trig_l_front, 1);
  delayMicroseconds(10);
  digitalWrite(trig_l_front, 0);
  
  duration_LF = pulseIn(echo_l_front, 1);
  distance_LF = duration_LF / 58.2;
  //Serial.print("distance_LF: ");
  //  Serial.println(distance_LF);
  delay(10);
}
