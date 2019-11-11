void pid_start() {
  //+ ((left_reading - right_reading) * 0.5);
  float errorP = distance_LF - distance_LB ;
  float errorD = errorP - oldErrorP;
  float errorI = (2.0 / 3.0) * errorI + errorP ;
  totalError = P * errorP + D * errorD + I * errorI ;

  oldErrorP = errorP ;
  RMS = baseSpeed + totalError ;// more to left
  LMS = baseSpeed - totalError ;// more to right
  if ( distance_LF < 15)
  {
    LMS = LMS + 20;
    RMS = RMS - 10;
  }
  if ( distance_LF > 21)
  {
    RMS = RMS+ 20;
  }

  if ( distance_LF > wall_threshold && distance_LB > wall_threshold)
  {
    RMS = 0;
    LMS = 0;
  }


  /*Serial.print("RMS: ");
    Serial.print (RMS);
    Serial.print("     LMS: ");
    Serial.println( LMS);*/

  //  if(RMS < -255) RMS = -255; if(RMS > 255)RMS = 255 ;
  //  if(LMS < -255) LMS = -255;  if(LMS > 255)LMS = 255 ;


  /* if (RMS < 0) {

     RMS = map(RMS , 0 , -255, 0, 255);

     analogWrite(RIGHTMotorEN , RMS);
     analogWrite(LEFTMotorEN , LMS);

     setDirection(RIGHT);

    }
    else if (LMS < 0) {
     LMS = map(LMS , 0 , -255, 0, 255);


     analogWrite(RIGHTMotorEN , RMS);
     analogWrite(LEFTMotorEN , LMS);

     setDirection(LEFT);
    }
    else {

     analogWrite(RIGHTMotorEN , RMS);
     analogWrite(LEFTMotorEN , LMS);

     setDirection(FORWARD);
    }
  */
}
