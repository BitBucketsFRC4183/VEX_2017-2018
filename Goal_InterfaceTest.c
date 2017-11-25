#pragma config(Motor, port6,        left,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor, port7,        right,     tmotorVex393_HBridge, openLoop)

#include "Goal_Interface.c"
#include "MotorConstants.h"
task main()
{
	slaveMotor(right, left);
	initializeGoalLifterMotors(left, IME_TICKS_PER_DEG);

	startTask(goalLifterControlTask, main+1);

	for(;;)
	{
		wait1Msec(1000);
	}


}
