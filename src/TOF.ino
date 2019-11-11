

void TOF() {
  VL53L0X_RangingMeasurementData_t measure;
lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
   // Serial.println(" out of range ");
  }

  delay(100);
}
