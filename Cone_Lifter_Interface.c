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
	float cLifterSetPoint = 0.0;
//	float cLifterSetPointB;
	float cLifterPositionA;
	float cLifterPositionB;
	float maxVal=600;
	float k = 2.0;
	float minVal=-23;
	for(;;)
	{
		int j = getJoystickValue(C_LIFTER_AXIS);
		long enc = getMotorEncoder(cLifterMotorA);
		if(abs(j)>10&&((enc/cLifterEncoderScale_ticksPerDeg<minVal && j>0)
			||(enc/cLifterEncoderScale_ticksPerDeg>maxVal && j<0)
			||(enc/cLifterEncoderScale_ticksPerDeg<maxVal&&
			enc/cLifterEncoderScale_ticksPerDeg>minVal)))
		{
			cLifterSetPoint=(float)getMotorEncoder(cLifterMotorA)/cLifterEncoderScale_ticksPerDeg;
			motor[cLifterMotorA]=j;
		}
		else
		{
			if(cLifterSetPoint>maxVal) cLifterSetPoint=maxVal;
			if(cLifterSetPoint<minVal) cLifterSetPoint=minVal;
			cLifterPositionA=(float)enc/cLifterEncoderScale_ticksPerDeg;
			cLifterErrorA=cLifterSetPoint-cLifterPositionA;
			motor[cLifterMotorA]=cLifterErrorA*k;
		}
		cLifterPositionB=(float)getMotorEncoder(cLifterMotorB)/cLifterEncoderScale_ticksPerDeg;
		cLifterErrorB=-cLifterSetPoint-cLifterPositionB;
		motor[cLifterMotorB]=-cLifterErrorB*k;
	}

	wait1Msec(5); // 200 Hz
}
