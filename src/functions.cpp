#include "functions.hpp"
#include "timing.hpp"
#include "main.h"
using namespace pros;


void moveBack(double distance, double kp, double time) {
  double power;
  double error;
  rightbackmtr.tare_position();
  //while the robot's rotation does not meet the target
  error = distance - fabs(rightbackmtr.get_position());
  startTimer(0);
  while (fabs(rightbackmtr.get_position()) <= fabs(distance), fabs(error) >= 5){
    //the rest of the turn
    error = distance - fabs(rightbackmtr.get_position());

    error = distance - fabs(rightbackmtr.get_position());

    power = error * kp;
    leftfrontmtr = power;
    leftbackmtr = power;
    rightfrontmtr = -power;
    rightbackmtr = -power;

    if (getTime(0) >= time) {
      break;
    }
  }
  leftfrontmtr = 0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void moveForward(double distance, double kp, double time) {
  double power;
  double error;
  rightbackmtr.tare_position();
  //while the robot's rotation does not meet the target
  error = distance - fabs(rightbackmtr.get_position());
  startTimer(0);
  while (fabs(rightbackmtr.get_position()) <= fabs(distance), fabs(error) >= 5){
    //the rest of the turn

    error = distance - fabs(rightbackmtr.get_position());

    power = error * kp;
    leftfrontmtr = -power;
    leftbackmtr = -power;
    rightfrontmtr = power;
    rightbackmtr = power;

    if (getTime(0) >= time) {
      break;
    }
  }
  leftfrontmtr = 0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void forceMove(double power, double time) {
  startTimer(0);
  while (getTime(0) < time) {
    leftfrontmtr = -power;
    leftbackmtr = -power;
    rightfrontmtr = power;
    rightbackmtr = power;
  }
  leftfrontmtr = -0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void turn(double degrees, double kp, double time) { // use negative if turn left, positive if turn right
  double power;
  double error;

  inertial_sensor.tare_rotation();

  error = degrees - inertial_sensor.get_rotation();

  startTimer(0);

  while (fabs(error) >= 5 && getTime(0) <= time) {

    if (error >= 5) {
      error = degrees - inertial_sensor.get_rotation();
    }

    power = error * kp;

    leftfrontmtr = -power;
    leftbackmtr = -power;
    rightfrontmtr = -power;
    rightbackmtr = -power;

  }
  leftfrontmtr = 0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void turnRight(double degrees, double time) {
  startTimer(0);
  inertial_sensor.tare_rotation();
  while (fabs(inertial_sensor.get_rotation()) <= degrees * 0.555 && getTime(0) <= time) {
    leftfrontmtr = -90;
    leftbackmtr = -90;
    rightfrontmtr = -90;
    rightbackmtr = -90;
  }
  leftfrontmtr = 0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void turnLeft(double degrees, double time) {
  startTimer(0);
  inertial_sensor.tare_rotation();
  while (fabs(inertial_sensor.get_rotation()) <= degrees * 0.555 && getTime(0) <= time) {
    leftfrontmtr = 90;
    leftbackmtr = 90;
    rightfrontmtr = 90;
    rightbackmtr = 90;
  }
  leftfrontmtr = 0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void curve(double highSpeed, double lowSpeed, int quandrant, double time) {
  startTimer(0);
  while(getTime(0) < time) {
    if (quandrant == 1) {
      leftfrontmtr = -highSpeed;
      leftbackmtr = -highSpeed;
      rightfrontmtr = lowSpeed;
      rightbackmtr = lowSpeed;
    }
    if (quandrant == 2) { //no work
      leftfrontmtr = -highSpeed;
      leftbackmtr = -highSpeed;
      rightfrontmtr = lowSpeed;
      rightbackmtr = lowSpeed;
    }
    if (quandrant == 3) { // no work
      leftfrontmtr = lowSpeed;
      leftbackmtr = lowSpeed;
      rightfrontmtr = -highSpeed;
      rightbackmtr = -highSpeed;
    }
    if (quandrant == 4) {
      leftfrontmtr = highSpeed;
      leftbackmtr = highSpeed;
      rightfrontmtr = -lowSpeed;
      rightbackmtr = -lowSpeed;
    }
  }
  leftfrontmtr = 0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void spinToWin(double time) {
  startTimer(0);
  while (getTime(0) < time) {
    flywheelmtr = 500;
  }
  flywheelmtr = 0;
}

void flywheelControl(double time) {
  double targetVel = 500;
  double error;
  double kP = 0.5;

  error = targetVel - flywheelmtr.get_actual_velocity();

  startTimer(0);

  while (getTime(0) < time) {
    if (fabs(flywheelmtr.get_actual_velocity() < targetVel)) {
      flywheelmtr = error * kP;
    }
    pros::lcd::set_text(2, std::to_string(flywheelmtr.get_actual_velocity()));
  flywheelmtr = 0;
  }
}

void intakeOn(int power) {
  intakemtr = -power;
}

void intakeOff() {
  intakemtr = 0;
}

void revIntake(int power) {
  intakemtr = power;
}

void moveArm(int position) {

  if (position == 1) {
    leftArm.move_absolute(-2200, -127);
    rightArm.move_absolute(2200, -127);
  }
  if (position == 0) {
    leftArm.move_absolute(0, -127);
    rightArm.move_absolute(0, -127);
  }
}

void doFlaps(int position) {
  if (position == 0) {
    armFlapL.set_value(0);
    armFlapR.set_value(0);
  }
  if (position == 1) {
    armFlapL.set_value(1);
    armFlapR.set_value(1);
  }
}












/*
void moveBack(double distance, double kp, double time) {
  double power;
  double error;
  rightbackmtr.tare_position();
  //while the robot's rotation does not meet the target
  error = distance - fabs(rightbackmtr.get_position());
  startTimer(0);
  while (fabs(rightbackmtr.get_position()) <= fabs(distance), fabs(error) >= 5){
    //the rest of the turn
    error = distance - fabs(rightbackmtr.get_position());

    power = error * kp;
    leftfrontmtr = -power;
    leftbackmtr = -power;
    rightfrontmtr = power;
    rightbackmtr = power;
    if (getTime(0) >= time) {
      break;
    }
  }
  leftfrontmtr = 0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void moveForward(double distance, double kp, double time) {
  double power;
  double error;
  rightbackmtr.tare_position();
  //while the robot's rotation does not meet the target
  error = distance - fabs(rightbackmtr.get_position());
  startTimer(0);
  while (fabs(rightbackmtr.get_position()) <= fabs(distance), fabs(error) >= 5){
    //the rest of the turn
    error = distance - fabs(rightbackmtr.get_position());

    power = error * kp;
    leftfrontmtr = power;
    leftbackmtr = power;
    rightfrontmtr = -power;
    rightbackmtr = -power;
    if (getTime(0) >= time) {
      break;
    }
  }
  leftfrontmtr = 0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void turn(double degrees, double kp, double time) { // use negative if turn right, positive if turn left
  double power;
  double error;

  inertial_sensor.tare_rotation();

  error = degrees + inertial_sensor.get_rotation();

  startTimer(0);

  while (fabs(error) >= 5 && getTime(0) <= time) {
    error = degrees + inertial_sensor.get_rotation();
    power = error * kp;

    leftfrontmtr = -power;
    leftbackmtr = -power;
    rightfrontmtr = -power;
    rightbackmtr = -power;

  }
  leftfrontmtr = 0;
  leftbackmtr = 0;
  rightfrontmtr = 0;
  rightbackmtr = 0;
}

void spinToWin(double time) {
  startTimer(0);
  while (getTime(0) < time) {
    flywheelmtr = 600;
  }
  flywheelmtr = 0;
}

void intakeOn(int power) {
  intakemtr = -power;
}

void intakeOff() {
  intakemtr = 0;
}

void revIntake(int power) {
  intakemtr = power;
}

void moveArm(int position) {

  if (position == 1) {
    leftArm.move_absolute(-2200, -127);
    rightArm.move_absolute(2200, -127);
  }
  if (position == 0) {
    leftArm.move_absolute(0, -127);
    rightArm.move_absolute(0, -127);
  }
}
*/
