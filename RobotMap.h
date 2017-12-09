#if !defined(ROBOTMAP_H)
#define ROBOTMAP_H

#include "JoyStickMap.h"
#include "MotorConstants.h"

const int DRIVE_AXIS = DRIVER_LEFT_Y; //these axis match with the FRC configuration
const int TURN_AXIS = DRIVER_RIGHT_X;

const int GOAL_LIFTER_UP = OPERATOR_RIGHT_BUTTONS_U;
const int GOAL_LIFTER_DOWN = OPERATOR_RIGHT_BUTTONS_D;

const float GOAL_ENCODER_SCALE_TICKS_PER_DEG = IME_TICKS_PER_DEG;

// Create functions to make fetching the drive and turn commands
// easier to understand when used. In this case we will change them
// to simply return a floating point scale from -1.0 to +1.0 to
// allow for simpler control scaling
float getDriveCommand()
{
	return (float)(vexRT[DRIVE_AXIS]) / JOYSTICK_MAX_FLOAT;
}

float getTurnCommand()
{
	return (float)(-vexRT[TURN_AXIS]) / JOYSTICK_MAX_FLOAT; //z axis pointing toward ground
}

enum GoalCommand
{
	GOAL_UP,
	GOAL_CENTER,
	GOAL_DOWN
};
GoalCommand getGoalLifterCommand()
{
	GoalCommand result = GOAL_CENTER;	// Default to neither up or down

	// Up and down are mutually exclusive
	// and at least one must be pressed
	if(vexRT[GOAL_LIFTER_UP]^vexRT[GOAL_LIFTER_DOWN])
	{
		// If not up it must be down
		if(vexRT[GOAL_LIFTER_UP])
	  {
	  	result = GOAL_UP;
	  }
		else
		{
			result = GOAL_DOWN;
		}
	}

	return result;
}

const int C_LIFTER_AXIS = OPERATOR_LEFT_Y;
const int CONE_LIFTER_UP = OPERATOR_LEFT_BUTTONS_U;
const int CONE_LIFTER_DOWN = OPERATOR_LEFT_BUTTONS_D;

float getLiftCommand(){
	return vexRT[C_LIFTER_AXIS] / JOYSTICK_MAX_FLOAT;

/*	if(vexRT[CONE_LIFTER_UP]^vexRT[CONE_LIFTER_DOWN]){

		if(vexRT[CONE_LIFTER_UP]){
			result = C_LIFTER_UP;
		}
		else{
			result = C_LIFTER_DOWN;
		}
	}*/
}

#endif // ROBOTMAP_H
