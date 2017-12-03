#include "RobotMap.h"
#include "Utilities.h"

//opposite directions
tMotor cLifterMotorA;
tMotor cLifterMotorB;
tMotor clIfterMotorID;
float  cLifterEncoderScale_ticksPerDeg = 0.0;

void initializeCLifterMotors(tMotor motor1, tMotor motor2, float encoderScale_ticksPerDeg){
	cLifterMotorA=motor1;
	cLifterMotorB=motor2;
	cLifterEncoderScale_ticksPerDeg = encoderScale_ticksPerDeg;
}

/*task cLifterControlTask0(){
	float cLifterError;
	float cLifterSetPoint;
	float cLifterPosition;
	float dcLifterSetPoint;
	float cRate;
	float k;
	unsigned long lastTime=nPgmTime;
	float dT;
	resetMotorEncoder(cLifterMotorID);
	//resetTimer(T1);

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
}*/

task cLifterControlTask()
{
	resetMotorEncoder(cLifterMotorA);
	resetMotorEncoder(cLifterMotorB);
	float cLifterErrorA;
	float cLifterErrorB;
	float cLifterSetPoint;
//	float cLifterSetPointB;
	float cLifterPositionA;
	float cLifterPositionB;
	float maxVal=500;
	float kA=1;
	float kB=1;
	//float minVal;
	for(;;)
	{
		cLifterSetPoint=getJoystickValue(C_LIFTER_AXIS)/127*maxVal;
		if(getJoystickValue(C_LIFTER_AXIS)<20)
		{
			cLifterSetPoint=getMotorEncoder(cLifterMotorA)/cLifterEncoderScale_ticksPerDeg;
			motor[cLifterMotorA]= kA*getJoystickValue(C_LIFTER_AXIS);
		}
		else
		{
			cLifterPositionA=getMotorEncoder(cLifterMotorA)/cLifterEncoderScale_ticksPerDeg;
			cLifterErrorA=cLifterSetPoint-cLifterPositionA;
			motor[cLifterMotorA]=cLifterErrorA*kA;
		}
		cLifterPositionB=getMotorEncoder(cLifterMotorB)/cLifterEncoderScale_ticksPerDeg;
		cLifterErrorB=-cLifterSetPoint-cLifterPositionB;
		motor[cLifterMotorB]=cLifterErrorB*kB;
	}
}
/*Notes:
1. clifteraxis was made up in the robot map, need to  determine which actual axis is being used.
2. what about min value
3. what about the set point value if no joystick value
4. joystick stuff.
5. neg sign for mtr b
//*/
