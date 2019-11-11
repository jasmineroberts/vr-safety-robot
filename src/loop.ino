void loop() {
  //mag_sensor();
  // LB_sensor();
  while (corner_count < 5) {
    basic_run();
  }
  //stop_();

}

bool turn_flag = 0;

void basic_run() {
  F_sensor();
  if (distance_F < front_threshold) {
    brake() ;
    brake() ;
    brake() ;
    stop_();
    left_reading = 0; //encoder
    right_reading = 0;
    while (right_reading < 70 & left_reading < 70) {
      right();
      turn_flag = 1;
      Serial.println(right_reading);
    }

    stop_();
    left_reading = 0; //encoder
    right_reading = 0;
    brake() ;
    brake() ;
    brake() ;
    stop_();
    F_sensor();

  }

  if (distance_F > front_threshold) {
    LF_sensor();
    LB_sensor();
    // TOF();
    pid_start();
    fwd();

    if (turn_flag == 1) {
      corner_count++;
      turn_flag = 0;
    }
  }





}

