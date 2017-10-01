const int DRIVE_AXIS = Ch3; //these axis match with the FRC configuration
const int TURN_AXIS = Ch1;

int getDriveCommand(){
	return vexRT[DRIVE_AXIS];
}

int getTurnCommand(){
	return vexRT[TURN_AXIS];
}
