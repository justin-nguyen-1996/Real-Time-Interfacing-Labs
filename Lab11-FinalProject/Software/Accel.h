#ifndef ACCEL_H
#define ACCEL_H

#define ACCEL_X  0
#define ACCEL_Y  1
#define ACCEL_Z  2

#define DEADZONE_ACCEL_XY_MIN  1900
#define DEADZONE_ACCEL_XY_MAX  2100
#define DEADZONE_ACCEL_Z_MIN   1500
#define DEADZONE_ACCEL_Z_MAX   1700

void Accel_Init(void);

#endif
