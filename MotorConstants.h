#if !defined(MOTORCONSTANTS_H)

#define MOTORCONSTANTS_H

// From the spec sheets and language details
const int MOTOR_MAX = 127;
const float MOTOR_MAX_FLOAT = (float)MOTOR_MAX;

// Quadrature (shaft) Encoders: 360 ticks per revolution of the output shaft
// 269 Motor IME:	      240.4 ticks per revolution of the output shaft
// 393 Motor IME:       627.2 ticks per revolution of the output shaft
// 393 High Speed IME:  392 ticks per revolution of the output shaft
// 393 Turbo Speed IME: 261 ticks per revolution of the output shaft
const float DEG_PER_REV = 360.0;
const float SHAFT_ENCODER_TICKS_PER_REV = 360.0;
const float SHAFT_ENCODER_TICKS_PER_DEG = SHAFT_ENCODER_TICKS_PER_REV / DEG_PER_REV;
const float IME_TICKS_PER_REV           = 627.2;
const float IME_TICKS_PER_DEG           = IME_TICKS_PER_REV / DEG_PER_REV;
const float HIGH_SPEED_IME_TICKS_PER_REV  = 392;
const float HIGH_SPEED_IME_TICKS_PER_DEG  = HIGH_SPEED_IME_TICKS_PER_REV / DEG_PER_REV;
const float TURBO_SPEED_IME_TICKS_PER_REV = 261;
const float TURBO_SPEED_IME_TICKS_PER_DEG = TURBO_SPEED_IME_TICKS_PER_REV / DEG_PER_REV;


#endif
