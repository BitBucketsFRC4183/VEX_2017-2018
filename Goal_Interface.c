#include "RobotMap.h"
#include "Utilities.h"

tMotor gManipID;

void initializeGoalManipMotors(tMotor masterID){
	gManipID = masterID;
}

task gManipControlTask(){
	for(;;){

		float leftMotorSpeed = 0.0;

		if(getGoalLifterCommand() == 1) leftMotorSpeed = 0.5;
		if(getGoalLifterCommand() == -1) leftMotorSpeed = -0.7;

		int gManipMotorCommand = (int)(leftMotorSpeed*MOTOR_MAX_FLOAT);

		motor[gManipID] = gManipMotorCommand;

		wait1Msec(50);
	}

}
long e;
int sp;
int sv;
task motorControl()
{
	for(;;)
	{
			if(vexRT[GOAL_LIFTER_UP]^vexRT[GOAL_LIFTER_DOWN])
			{
				//sets target position of goal lifter based on whether up or down joystick buttons are pressed
				if(vexRT[GOAL_LIFTER_UP]) sp=30;
				if(vexRT[GOAL_LIFTER_DOWN])sp=-110;
			}

			sv=getMotorEncoder(gManipID);
			e=sp-sv;
			//Motor speed is proportional to the difference of the desired position and the actual position
			Motor[gManipID]=e*127/360;
	}
}
