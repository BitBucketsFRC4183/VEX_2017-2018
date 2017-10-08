#include "RobotMap.h"
#include "Utilities.h"

struct GoalManipMotorType{
	tMotor leftID;
	tMotor rightID;
};

GoalManipMotorType gManipMotors;

void initializeGoalManipMotors(tMotor masterID){
	gManipMotors.leftID = masterID;
	gManipMotors.rightID;

}

task gManipControlTask(){
	for(;;){

		float leftMotorSpeed = 0.0;

		if(getGoalLifterCommand() == 1) leftMotorSpeed = 63;
		if(getGoalLifterCommand() == -1) leftMotorSpeed = -63;

		int leftMotorCommand = (int)(leftMotorSpeed*MOTOR_MAX_FLOAT);


		motor[gManipMotors.leftID] = leftMotorCommand;
		motor[gManipMotors.rightID] = leftMotorCommand;
	}
}
