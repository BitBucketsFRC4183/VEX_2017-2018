// DriverInterface contains the functions and tasks for controlling the drive base
//
// Since RobotC likes to define the motor assignments as part of the configuration
// pragmas in the competition template, we need to find a way of passing that information
// to this interface. This includes some form of list/array of motor identifiers to
// include how many and which are left and right side.
//
// The next important thing is to provide a task for basic driver control.
// This task is simple and should initially just read the drive/turn commands,
// scale the commands, pass the commands into an arcade drive function to split
// the left/right value, and then pass control to the motors.
//
// In this early stage we don't need to worry about any special behaviors, like
// interactions with autonomous, speed control, or even special driver modes (like
// an automatic 180)... just wrap all of the basic driver controls into one place.

#include "RobotMap.h"

int getDriveCommand(){
	return vexRT[DRIVE_AXIS];
}

int getTurnCommand(){
	return vexRT[TURN_AXIS];
}
