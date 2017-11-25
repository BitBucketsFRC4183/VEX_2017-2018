#include "RobotMap.h"
#include "Utilities.h"

tMotor goalLifterMotorId;
float  goalLifterEncoderScale_ticksPerDeg = 0.0;

void initializeGoalLifterMotors(tMotor masterID, float encoderScale_ticksPerDeg)
{
	goalLifterMotorId = masterID;
	goalLifterEncoderScale_ticksPerDeg = encoderScale_ticksPerDeg;
}

task goalLifterControlTask()
{
	// Variable names for clarity
	float goalError;
	float goalSetPoint;
	float goalPosition;
	resetMotorEncoder(goalLifterMotorId);
	for(;;)
	{
		  switch (getGoalLifterCommand())
		  {
		  	case GOAL_UP:
		  		goalSetPoint = 90.0;	// Should be in "real" units like degrees, inches, etc.
		  		break;
		  	case GOAL_DOWN:
		  		goalSetPoint = -110.0;	// Should be in "real" units
		  		break;
		  	case GOAL_CENTER:
		  	default:
		  		goalSetPoint = 0.0;
		  		break;
		  }

		  // The motor encoder return value depends on the type of encoder
		  // and the motor gear ratios. In this case we "know" that the
		  // integrated encoder has specific scaling (see MotorConstants.h)
			goalPosition = (float)getMotorEncoder(goalLifterMotorId) / goalLifterEncoderScale_ticksPerDeg;
			goalError = goalSetPoint - goalPosition;

			// Motor speed is proportional to the difference of the desired position and the actual position
			// The scale is chosen to
			float Kp = 1.0;
			float commandValue = (float)goalError * Kp;
			if (commandValue > MOTOR_MAX_FLOAT)
			{
				commandValue = MOTOR_MAX_FLOAT;
			}
			else if (commandValue < -MOTOR_MAX_FLOAT)
			{
				commandValue = -MOTOR_MAX_FLOAT;
			}

			motor[goalLifterMotorId] = (int)-commandValue;

			// Delay before running again
			wait1Msec(20);	// 50 Hz should be enough 1/50 = 20 msec
	}
}
