#pragma config(Motor, port6,        left,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor, port7,        right,     tmotorVex393_HBridge, openLoop)

#include "Goal_Interface.c"

task main()
{
	slaveMotor(right, left);
	initializeGoalManipMotors(left);

	startTask(gManipControlTask, main+1);

	for(;;)
	{
		wait1Msec(1000);
	}


}
