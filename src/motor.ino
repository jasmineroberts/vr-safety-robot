
void fwd() {
  digitalWrite(RIGHTlogic1, 0);
  digitalWrite(RIGHTlogic2, 1);
  // analogWrite(RIGHTMotorEN, 150);

  digitalWrite(LEFTlogic1, 0);
  digitalWrite(LEFTlogic2, 1);
  //analogWrite(LEFTMotorEN, 150);
  analogWrite(RIGHTMotorEN , RMS);
  analogWrite(LEFTMotorEN , LMS);


}

void stop_() {
  digitalWrite(RIGHTlogic1, 0);
  digitalWrite(RIGHTlogic2, 0);
  digitalWrite(LEFTMotorEN, 0);
  digitalWrite(RIGHTMotorEN, 0);
  digitalWrite(LEFTlogic1, 0);
  digitalWrite(LEFTlogic2, 0);

}
void brake() {
  digitalWrite(RIGHTlogic1, 1);
  digitalWrite(RIGHTlogic2, 0);
  analogWrite(RIGHTMotorEN, 120);

  digitalWrite(LEFTlogic1, 1);
  digitalWrite(LEFTlogic2, 0);
  analogWrite(LEFTMotorEN, 120);

}
void left() {

}
void right() {
  digitalWrite(RIGHTlogic1, 1);
  digitalWrite(RIGHTlogic2, 0);
  analogWrite(RIGHTMotorEN, 90);

  digitalWrite(LEFTlogic1, 0);
  digitalWrite(LEFTlogic2, 1);
  analogWrite(LEFTMotorEN, 90);
 
}

