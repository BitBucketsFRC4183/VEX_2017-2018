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
