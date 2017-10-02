#include "RobotMap.h"

int getDriveCommand(){
	return vexRT[DRIVE_AXIS];
}

int getTurnCommand(){
	return vexRT[TURN_AXIS];
}
