/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2022, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_


#define PROS_USE_SIMPLE_NAMES


#define PROS_USE_LITERALS

#include "api.h"


#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus


#endif
extern pros::Motor leftfrontmtr;
extern pros::Motor rightfrontmtr;
extern pros::Motor rightbackmtr;
extern pros::Motor leftbackmtr;
extern pros::Motor intakemtr;
extern pros::Motor flywheelmtr;
extern pros::Motor leftArm;
extern pros::Motor rightArm;
extern pros:: ADIDigitalOut armFlapL;
extern pros:: ADIDigitalOut armFlapR;
extern pros:: Controller master;
extern pros:: Imu inertial_sensor;
extern pros:: Imu gps_sensor;
#endif  // _PROS_MAIN_H_  
