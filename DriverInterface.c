// DriverInterface contains the functions and tasks for controlling the drive base
//
// Since RobotC likes to define the motor assignments as part of the configuration
// pragmas in the competition template, we need to find a way of passing that information
// to this interface. This includes some form of list/array of motor identifiers to
// include how many and which are left and right side.
//
// The next important thing is to provide a task for basic driver control.
// This task is simple and should initially just read the drive/turn commands,
// scale the commands, pass the commands into an arcade drive function to split
// the left/right value, and then pass control to the motors.
//
// In this early stage we don't need to worry about any special behaviors, like
// interactions with autonomous, speed control, or even special driver modes (like
// an automatic 180)... just wrap all of the basic driver controls into one place.

#include "RobotMap.h"
#include "Utilities.h"

// Create two "member-like" variables here to represent the
// master motor IDs for the left and right motors.
// Normally we would want a private or protected interface
// but RobotC does not provide such. All we can do here is
// create two globals to be initialized by the main program
// when it starts. To make it look more like a class we will
// just place the items in a struct
struct DriveMotorType
{
	tMotor leftId;
	tMotor rightId;
};

DriveMotorType driveMotors;
void initializeDriveMotors(tMotor leftMasterId, tMotor rightMasterId)
{
	driveMotors.leftId = leftMasterId;
	driveMotors.rightId = rightMasterId;
}

// Create functions to make fetching the drive and turn commands
// easier to understand when used.
// Later we can add code to fetch information from other sources
// like an autonmous (fake) joystick... or we could just change
// the motor command source in the driveControlTask, further down.
int getDriveCommand()
{
	return vexRT[DRIVE_AXIS];
}

int getTurnCommand()
{
	return vexRT[TURN_AXIS];
}

// Create a driveControl task to run the user control loop
// for driving the drive motors. Initialization and motor
// setup should bet at the top of the task, OUTSIDE the
// loop
//
// To avoid having to edit this code, we should pass a right
// and left motor "id" to some variables. If this were a class-like
// interface we would be initializing some member variables.
//
// Since it is possible that multiple motors are being used on each side
// we would prefer to slave the motors to avoid needing to send multiple
// commands.
task driveControlTask()
{
	for EVER
	{
		// Read the inputs and convert to float so we can scale easier
		float drive = (float)getDriveCommand() / JOYSTICK_MAX_FLOAT;
		float turn = (float)getTurnCommand() / JOYSTICK_MAX_FLOAT;

		// Scale the inputs to make the joystick easier to use
		// There are many scaling options: square, cube, sine, logarithmic
		// The simplest to implement here is square, preserving the sign
		drive *= fabs(drive);
		turn *= fabs(turn);

		// Now we just implement the arcade logic (similar to the WPI library
		// used on the FRC robot)
		float leftMotorSpeed = 0.0;
		float rightMotorSpeed = 0.0;
		if (drive > 0.0)
		{
			if (turn > 0.0)
			{
				leftMotorSpeed = drive - turn;
				rightMotorSpeed = max(drive, turn);
			}
			else
			{
				leftMotorSpeed = max(drive, -turn);
				rightMotorSpeed = drive + turn;
			}
		}
		else
		{
			if (turn > 0.0)
			{
				leftMotorSpeed = -max(-drive, turn);
				rightMotorSpeed = drive + turn;
			}
			else
			{
				leftMotorSpeed = drive - turn;
				rightMotorSpeed = -max(-drive, -turn);
			}
		}

		// Scale for the motor range (truncating to integer)
		int leftMotorCommand = (int)(leftMotorSpeed * MOTOR_MAX_FLOAT);
		int rightMotorCommand = (int)(rightMotorSpeed * MOTOR_MAX_FLOAT);

		motor[driveMotors.leftId] = leftMotorCommand;
		motor[driveMotors.rightId] = rightMotorCommand;

		// No need to run drive control faster than about 20 Hz
		wait1Msec(50);

	} // end for ever
} // end task
