#include "RobotMap.h"
#include "Utilities.h"

//slave motors at some point
tMotor cLifterMotorID;
float  cLifterEncoderScale_ticksPerDeg = 0.0;

void initializeCLifterMotors(tMotor masterID, float encoderScale_ticksPerDeg){
	cLifterMotorID = masterID;
	cLifterEncoderScale_ticksPerDeg = encoderScale_ticksPerDeg;
}

task cLifterControlTask(){
	float cLifterError;
	float cLifterSetPoint;
	float cLifterPosition;

	resetMotorEncoder(cLifterMotorID);

	for(;;){

	}

}
