#if !defined(JOYSTICK_MAP_H)
#define JOYSTICK_MAP_H

const int JOYSTICK_MAX = 127;
const float JOYSTICK_MAX_FLOAT = (float)JOYSTICK_MAX;

//Driver stuff

const int DRIVER_LEFT_Y = Ch3;
const int DRIVER_LEFT_X = Ch4;

const int DRIVER_RIGHT_Y = Ch2;
const int DRIVER_RIGHT_X = Ch1;

const int DRIVER_LEFT_TOP_BUMPER = Btn5U;
const int DRIVER_LEFT_BOTTOM_BUMPER = Btn5D;

const int DRIVER_RIGHT_TOP_BUMPER = Btn6U;
const int DRIVER_RIGHT_BUTTON_BUMPER = Btn6D;

const int DRIVER_LEFT_BUTTONS_L = Btn7L;
const int DRIVER_LEFT_BUTTONS_U = Btn7U;
const int DRIVER_LEFT_BUTTONS_R = Btn7R;
const int DRIVER_LEFT_BUTTONS_D = Btn7D;

const int DRIVER_RIGHT_BUTTONS_L = Btn8L;
const int DRIVER_RIGHT_BUTTONS_U = Btn8U;
const int DRIVER_RIGHT_BUTTONS_R = Btn8R;
const int DRIVER_RIGHT_BUTTONS_D = Btn8D;

//Operator stuff

const int OPERATOR_LEFT_Y = Ch3Xmtr2; //I think this is what it is for the second controller. The API was not very helpful
const int OPERATOR_LEFT_X = Ch4Xmtr2;

const int OPERATOR_RIGHT_Y = Ch2Xmtr2;
const int OPERATOR_RIGHT_X = Ch1Xmtr2;

const int OPERATOR_LEFT_TOP_BUMPER = Btn5UXmtr2;
const int OPERATOR_LEFT_BOTTOM_BUMPER = Btn5DXmtr2;

const int OPERATOR_RIGHT_TOP_BUMPER = Btn6UXmtr2;
const int OPERATOR_RIGHT_BUTTON_BUMPER = Btn6DXmtr2;

const int OPERATOR_LEFT_BUTTONS_L = Btn7LXmtr2;
const int OPERATOR_LEFT_BUTTONS_U = Btn7UXmtr2;
const int OPERATOR_LEFT_BUTTONS_R = Btn7RXmtr2;
const int OPERATOR_LEFT_BUTTONS_D = Btn7DXmtr2;

const int OPERATOR_RIGHT_BUTTONS_L = Btn8LXmtr2;
const int OPERATOR_RIGHT_BUTTONS_U = Btn8UXmtr2;
const int OPERATOR_RIGHT_BUTTONS_R = Btn8RXmtr2;
const int OPERATOR_RIGHT_BUTTONS_D = Btn8DXmtr2;

#endif
