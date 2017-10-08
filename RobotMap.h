#if !defined(ROBOTMAP_H)
#define ROBOTMAP_H

#include "JoyStickMap.h"

const int MOTOR_MAX = 127;	// These consts should probably be somewhere else (like a motor utility or map)
const float MOTOR_MAX_FLOAT = (float)MOTOR_MAX;

const int DRIVE_AXIS = DRIVER_LEFT_Y; //these axis match with the FRC configuration
const int TURN_AXIS = DRIVER_RIGHT_X;

const int GOAL_LIFTER_UP = OPERATOR_RIGHT_BUTTONS_U;
const int GOAL_LIFTER_DOWN = OPERATOR_RIGHT_BUTTONS_D;

// Create functions to make fetching the drive and turn commands
// easier to understand when used.
int getDriveCommand()
{
	return vexRT[DRIVE_AXIS];
}

int getTurnCommand()
{
	return vexRT[TURN_AXIS];
}

int getGoalLifterCommand(){
	int result = 0;

	if(vexRT[GOAL_LIFTER_UP]^vexRT[GOAL_LIFTER_DOWN]){
		if(vexRT[GOAL_LIFTER_UP]) result = 1;
		else result = -1;
	}

	return result;

}

#endif // ROBOTMAP_H
