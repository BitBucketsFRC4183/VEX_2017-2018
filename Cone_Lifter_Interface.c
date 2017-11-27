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
	float dcLifterSetPoint;
	float cRate;
	float k;
	unsigned long lastTime=nPgmTime;
	float dT;
	resetMotorEncoder(cLifterMotorID);

	for(;;){
		switch(getLiftCommand()){
			case C_LIFTER_UP:
				cRate=10.0;
				break;
			case C_LIFTER_DOWN:
				cRate=-10.0;
				break;
			default:
				cRate+=0.0;
				break;
		}
		dT=(float)nPgmTime-lastTime;
		lastTime=nPgmTime;
		dcLifterSetPoint=cRate*dT;
		cLifterSetPoint+=dcLifterSetPoint;

		if(cLifterSetPoint>1890) cLifterSetPoint=1890;
		if(cLifterSetPoint<0) cLifterSetPoint=0;

		cLifterPosition = (float)getMotorEncoder(cLifterMotorID)/cLifterEncoderScale_ticksPerDeg;
		cLifterError = cLifterSetPoint - cLifterPosition;

		k=1.0;

		float commandValue = (float)cLifterError* k;
			if (commandValue > MOTOR_MAX_FLOAT)
			{
				commandValue = MOTOR_MAX_FLOAT;
			}
			else if (commandValue < -MOTOR_MAX_FLOAT)
			{
				commandValue = -MOTOR_MAX_FLOAT;
			}

			motor[cLifterMotorID] = (int)commandValue;

			wait1Msec(20);
	}

}
