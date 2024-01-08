#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_
/*
void flyWheelSpin();
void pushWheelSpin();*/
/*
RWEMEBER
nuclear bomb is the right catapult !!!
twentytwomilimeterantiaircraftgun is the left catapult!!!
*/

void moveBack(double distance, double kp, double time);
void moveForward(double distance, double kp, double time);
void forceMove(double power, double time);
void turn(double degrees, double kp, double time);
void turnRight(double degrees, double time);
void turnLeft(double degrees, double time);
void curve(double highSpeed, double lowSpeed, int quandrant, double time);
void spinToWin(double time);
void flywheelControl(double time);
void intakeOn(int power);
void intakeOff();
void revIntake(int power);
void moveArm (int position);
void doFlaps (int position);
#endif
