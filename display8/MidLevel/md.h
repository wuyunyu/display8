#ifndef MD_H
#define MD_H

#include <QtMath>
#include <iostream>
#include <unistd.h>
#include "ParaConfig/parasum.h"

class MD
{
public:
    MD();
    ~MD();

public:
    u8 MD_PosSolCal(s32 *point, s32 *tarPoint);
    u8 MD_InvSolCal(s32 *point, s32 *tarPoint, u8 axisNum, s32 value);
    u8 MD_SCARA_AxisOffset(s32 *point, u8 axisNum, s32 value);

private:
    GlobalPara *GP;
    u8 ScaraFindHandcoor(double theta2);
    u8 ScaraFindFlagJ1(double theta1);
    u8 ScaraFindFlagJ2(double theta2);
    u8 ScaraForwardKinematics(double L1, double L2, double screw, ST_SCARA_JOINT_ANGLE jointAngle, ST_SCARA_JOINT_POS *jointPos);
    u8 ScaraInverseKinematics(double L1, double L2, double screw, ST_SCARA_JOINT_POS jointPos, u8 handcoor, u8 flagJ1, u8 flagJ2, ST_SCARA_JOINT_ANGLE *jointAngle);
    float AXisMovePosCal_Z(u8 Axsis, double tarPos_O, u8 posType);
};

#endif // MD_H
