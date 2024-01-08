#ifndef _TIMING_HPP_
#define _TIMING_HPP_

void startTimer(int slot);
int getTime(int slot);
void drive(double distance, double kp, double tkp, double max, int direction, double time);
void ImuTurnright(double degree, double kp, double max, double time);
void ImuTurnleft(double degree, double kp, double max, double time);
#endif
