#if !defined(ROBOTMAP_H)
#define ROBOTMAP_H

#include "JoyStickMap.h"

const int MOTOR_MAX = 127;	// These consts should probably be somewhere else (like a motor utility or map)
const float MOTOR_MAX_FLOAT = (float)MOTOR_MAX;

const int DRIVE_AXIS = DRIVER_LEFT_Y; //these axis match with the FRC configuration
const int TURN_AXIS = DRIVER_RIGHT_X;

#endif // ROBOTMAP_H
