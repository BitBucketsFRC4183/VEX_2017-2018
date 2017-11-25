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
	long goalError;
	int goalSetPoint;
	int goalPosition;
	for(;;)
	{
		  switch (getGoalLifterCommand())
		  {
		  	case GOAL_UP:
		  		goalSetPoint = 30;	// Should be in "real" units like degrees, inches, etc.
		  		break;
		  	case GOAL_DOWN:
		  		goalSetPoint = -110;	// Should be in "real" units
		  		break;
		  	case GOAL_CENTER:
		  	default:
		  		goalSetPoint = 0;
		  		break;
		  }

		  // The motor encoder return value depends on the type of encoder
		  // and the motor gear ratios. In this case we "know" that the
		  // integrated encoder has specific scaling (see MotorConstants.h)
			goalPosition = getMotorEncoder(goalLifterMotorId);
			goalError = goalSetPoint - goalPosition;

			// Motor speed is proportional to the difference of the desired position and the actual position
			// The scale is chosen to
			motor[goalLifterMotorId] = goalError * 127/360;

			// Delay before running again
			wait1Msec(50);	// 20 Hz should be enough 1/20 = 50 msec
	}
}
