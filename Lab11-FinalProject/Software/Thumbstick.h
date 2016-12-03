#ifndef THUMBSTICK_H
#define THUBMSTICK_H

#define TSTICK1_V  0
#define TSTICK1_H  1
#define TSTICK2_V  3
#define TSTICK2_H  2

#define DEADZONE_TSTICK_MIN    1800
#define DEADZONE_TSTICK_MAX    2200

// TSTICK2 --> left thumbstick, movement
// TSTICK1 --> right thumbstick, firing direction
void Thumbstick_Init(void);

#endif
