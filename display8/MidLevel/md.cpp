#include "md.h"

MD::MD()
{

}

MD::~MD()
{

}

/**************************************************************************************************
**  函数名：  MD_PosSolCal()
**	输入参数：
**	输出参数：
**	函数功能：坐标正解
**	备注：
**  作者：
**  开发日期:
***************************************************************************************************/
u8 MD::MD_PosSolCal(s32 *point, s32 *tarPoint)
{
    u16 i = 0;
    u8 ret = 0;
    ST_SCARA_JOINT_ANGLE sJointAngle = {};		//机器人关节角度(rad)
    ST_SCARA_JOINT_POS sJointPos = {};			//机器人关节位置(mm或rad)
    s32 offsetPostion[AXIS_NUM] = {0};			//轴坐标系-偏移坐标
    double screw = 0.0f;												//螺距

    for(i=0; i<AXIS_NUM; i++)
    {//求出每个轴旋转的角度
        tarPoint[i] = point[i];

        if(GP->sCartesian_Para.axisBackMinDir[i] == 0)
        {
            offsetPostion[i] = point[i] - GP->JXS_Parameter.OriginOffset[i];
        }
        else
        {
            offsetPostion[i] = GP->JXS_Parameter.OriginOffset[i] - point[i];
        }

        if(offsetPostion == 0)
        {
            sJointAngle.theta[i] = 0.0f;
        }
        else
        {
            sJointAngle.theta[i] = offsetPostion[i] * SCARA_PI / 18000.0f;
        }
    }


    screw = GP->sCartesian_Para.pitchLength / 100.0f;
    ret = ScaraForwardKinematics(GP->sCartesian_Para.length[0] / 100.0f, GP->sCartesian_Para.length[1] / 100.0f, screw, sJointAngle, &sJointPos);//正解
    if(ret)
    {
        return 1;
    }

    if(GP->sCartesian_Para.axisType[X_AXIS] == 1)
    {//显示成长度单位，单位0.01mm
        tarPoint[X_AXIS] = sJointPos.x * 100;
    }
    if(GP->sCartesian_Para.axisType[L_AXIS] == 1)
    {//显示成长度单位，单位0.01mm
        tarPoint[L_AXIS] = sJointPos.y * 100;
    }

    tarPoint[Z_AXIS] = point[Z_AXIS] - GP->JXS_Parameter.OriginOffset[Z_AXIS];

    if(GP->sCartesian_Para.axisType[O_AXIS] == 1)
    {//显示成角度，单位0.01°
        tarPoint[O_AXIS] = offsetPostion[O_AXIS] + offsetPostion[X_AXIS] + offsetPostion[L_AXIS];
    }
    else
    {
        tarPoint[O_AXIS] = point[O_AXIS] - GP->JXS_Parameter.OriginOffset[O_AXIS];
    }

    return 0;
}

/**************************************************************************************************
**  函数名：  MD_InvSolCal()
**	输入参数：
**	输出参数：
**	函数功能：笛卡尔坐标逆解
**	备注：
**  作者：
**  开发日期:
***************************************************************************************************/
u8 MD::MD_InvSolCal(s32 *point, s32 *tarPoint, u8 axisNum, s32 value)
{
    u16 i = 0;
    u8 flagJ1 = 0;
    u8 flagJ2 = 0;
    u8 handcoor = 0;
    u8 ret = 0;
    ST_SCARA_JOINT_ANGLE sJointAngle1 = {};		//机器人关节角度(rad)
    ST_SCARA_JOINT_ANGLE sJointAngle2 = {};		//机器人关节角度(rad)
    ST_SCARA_JOINT_POS sJointPos = {};				//机器人关节位置(mm或rad)
    s32 offsetPostion[AXIS_NUM] = {0};				//轴坐标系-偏移坐标
    u8 handturn_flag = 0;											//位置不能到达，翻转手系再次计算，若还不能到达，则运行出错
    double screw = 0.0f;												//螺距
    s32 pointTemp[AXIS_NUM] = {0};						//轴坐标保存

    for(i=0; i<AXIS_NUM; i++)
    {//求出每个轴旋转的角度
        pointTemp[i] = tarPoint[i] = point[i];

        if(GP->sCartesian_Para.axisBackMinDir[i] == 0)
        {
            offsetPostion[i] = point[i] - GP->JXS_Parameter.OriginOffset[i];
        }
        else
        {
            offsetPostion[i] = GP->JXS_Parameter.OriginOffset[i] - point[i];
        }

        if(offsetPostion[i] == 0)
        {
            sJointAngle1.theta[i] = 0.0f;
        }
        else
        {
            sJointAngle1.theta[i] = offsetPostion[i] * SCARA_PI / 18000.0f;
        }
    }

    flagJ1 = ScaraFindFlagJ1(sJointAngle1.theta[0]);
    flagJ2 = ScaraFindFlagJ2(sJointAngle1.theta[1]);
    handcoor = ScaraFindHandcoor(sJointAngle1.theta[1]);
    screw = GP->sCartesian_Para.pitchLength / 100.0f;

    ret = ScaraForwardKinematics(GP->sCartesian_Para.length[0] / 100.0f, GP->sCartesian_Para.length[1] / 100.0f,
            screw, sJointAngle1, &sJointPos);//正解
    if(ret)
    {
        return 1;
    }

    if(axisNum == X_AXIS)
    {//转换成长度单位，单位mm
        sJointPos.x = value / 100.0f;
    }
    if(axisNum == L_AXIS)
    {//转换成长度单位，单位mm
        sJointPos.y = value / 100.0f;
    }
    if(axisNum == Z_AXIS)
    {//转换成长度单位，单位mm
        sJointPos.z = value / 100.0f;
    }
    if(axisNum == O_AXIS)
    {//转换成角度，单位rad
        sJointPos.c = value * SCARA_PI / 18000.0f;
    }

    sJointPos.z = 0.0f;

    ret = ScaraInverseKinematics(GP->sCartesian_Para.length[0] / 100.0f, GP->sCartesian_Para.length[1] / 100.0f,
            screw, sJointPos, handcoor, flagJ1, flagJ2, &sJointAngle2);//逆解
    if(ret)
    {
        return 1;
    }

    sJointAngle2.theta[Z_AXIS] = sJointAngle2.theta[O_AXIS] - sJointAngle1.theta[O_AXIS];		//用于计算因O轴偏移引起的Z轴高度补偿

    for(i=0; i<AXIS_NUM; i++)
    {
        if(i != Z_AXIS && GP->sCartesian_Para.axisType[i] == 1)
        {//轴类型为旋转轴时，即为笛卡尔坐标系中的轴需要转换，其他轴只需要进行直线偏移
            offsetPostion[i] = sJointAngle2.theta[i] * 18000.0f / SCARA_PI;

            if(GP->sCartesian_Para.axisBackMinDir[i] == 0)
            {
                tarPoint[i] = offsetPostion[i] + GP->JXS_Parameter.OriginOffset[i];
            }
            else
            {
                tarPoint[i] = GP->JXS_Parameter.OriginOffset[i] - offsetPostion[i];
            }

            if(tarPoint[i] < 0 || (GP->Robot_SoftLimit[i].Switch_Limit == TRUE && tarPoint[i] > static_cast<int>(GP->Robot_SoftLimit[i].Right_Limit)))
            {//计算出的坐标不在安全区内，需要更换手系重新计算
                handturn_flag = 1;
                break;
            }
        }
        else if(i != Z_AXIS)
        {//其他轴只需要进行直线偏移
            tarPoint[i] = pointTemp[i];
        }
    }

    if(GP->sCartesian_Para.axisType[O_AXIS] == 1)
    {//如果O轴为旋转轴时，需要对Z轴进行补偿
        i = Z_AXIS;
        offsetPostion[i] = sJointAngle2.theta[Z_AXIS] * 180 * screw * 100 / SCARA_PI / 360;					//计算需要补偿的Z轴高度
        if(GP->sCartesian_Para.axisBackMinDir[i] == 0)
        {
            tarPoint[i] = offsetPostion[i] + pointTemp[i];
        }
        else
        {
            tarPoint[i] = pointTemp[i] - offsetPostion[i];
        }
    }
    else
    {//其他轴只需要进行直线偏移
        i = Z_AXIS;
        tarPoint[i] = pointTemp[i] + GP->sMD_Parameter.goodOffset[i];
    }

    if(handturn_flag == 1)
    {//计算得到的位置不在安全区内，翻转手系再次计算，若还不能到达，则运行出错
        if(handcoor == 0)
        {//切换手系
            handcoor = 1;
        }
        else
        {
            handcoor = 0;
        }

        //不考虑Z轴，screw=0
        ret = ScaraInverseKinematics(GP->sCartesian_Para.length[0] / 100.0f, GP->sCartesian_Para.length[1] / 100.0f,
                screw, sJointPos, handcoor, flagJ1, flagJ2, &sJointAngle2);//逆解
        if(ret)
        {
            return 1;
        }

        sJointAngle2.theta[Z_AXIS] = sJointAngle2.theta[O_AXIS] - sJointAngle1.theta[O_AXIS];		//用于计算因O轴偏移引起的Z轴高度补偿

        for(i=0; i<AXIS_NUM; i++)
        {
            if(i != Z_AXIS && GP->sCartesian_Para.axisType[i] == 1)
            {//轴类型为旋转轴时，即为笛卡尔坐标系中的轴需要转换，其他轴只需要进行直线偏移
                offsetPostion[i] = sJointAngle2.theta[i] * 18000.0f / SCARA_PI;

                if(GP->sCartesian_Para.axisBackMinDir[i] == 0)
                {
                    tarPoint[i] = offsetPostion[i] + GP->JXS_Parameter.OriginOffset[i];
                }
                else
                {
                    tarPoint[i] = GP->JXS_Parameter.OriginOffset[i] - offsetPostion[i];
                }

                if(tarPoint[i] < 0 || (GP->Robot_SoftLimit[i].Switch_Limit == TRUE && tarPoint[i] > static_cast<int>(GP->Robot_SoftLimit[i].Right_Limit)))
                {//计算出的坐标不在安全区内，报警
                    return 1;
                }
            }
            else if(i != Z_AXIS)
            {//其他轴只需要进行直线偏移
                tarPoint[i] = pointTemp[i];
            }
        }
    }

    if(GP->sCartesian_Para.axisType[O_AXIS] == 1)
    {//如果O轴为旋转轴时，需要对Z轴进行补偿
        i = Z_AXIS;
        offsetPostion[i] = sJointAngle2.theta[Z_AXIS] * 180 * screw * 100 / SCARA_PI / 360;					//计算需要补偿的Z轴高度
        if(GP->sCartesian_Para.axisBackMinDir[i] == 0)
        {
            tarPoint[i] = offsetPostion[i] + pointTemp[i];
        }
        else
        {
            tarPoint[i] = pointTemp[i] - offsetPostion[i];
        }
    }
    else
    {//其他轴只需要进行直线偏移
        i = Z_AXIS;
        tarPoint[i] = pointTemp[i] + GP->sMD_Parameter.goodOffset[i];
    }

    return 0;
}

/**************************************************************************************************
**  函数名：  MD_SCARA_AxisOffset()
**	输入参数：
**	输出参数：
**	函数功能：笛卡尔坐标系显示下修改笛卡尔坐标值
**	备注：
**  作者：
**  开发日期:
***************************************************************************************************/
u8 MD::MD_SCARA_AxisOffset(s32 *point, u8 axisNum, s32 value)
{
    u16 i = 0;
    s32 tarPointTemp[AXIS_NUM] = {0};
    u8 ret = 0;
    s32 z_MinPos = GP->Robot_SoftLimit[Z_AXIS].Left_Limit;
    s32 z_MaxPos = GP->Robot_SoftLimit[Z_AXIS].Right_Limit;
    s32 offsetPostion = 0;
    s32 axisAngle[AXIS_NUM] = {0};
    double screw = 0.0f;
    s32 point_O = 0;

    if(GP->g_AxiseCarteType == 1 && (GP->sCartesian_Para.MDCoordType == 1 || GP->sCartesian_Para.MDCoordType == 2) && axisNum == O_AXIS)
    {//SCARA结构时，O轴需要处理
        //计算得到当前X、Y轴的角度
        if(GP->sCartesian_Para.axisBackMinDir[X_AXIS] == 0)
        {
            axisAngle[X_AXIS] = point[X_AXIS] - GP->JXS_Parameter.OriginOffset[X_AXIS];
        }
        else
        {
            axisAngle[X_AXIS] = GP->JXS_Parameter.OriginOffset[X_AXIS] - point[X_AXIS];
        }

        if(GP->sCartesian_Para.axisBackMinDir[L_AXIS] == 0)
        {
            axisAngle[L_AXIS] = point[L_AXIS] - GP->JXS_Parameter.OriginOffset[L_AXIS];
        }
        else
        {
            axisAngle[L_AXIS] = GP->JXS_Parameter.OriginOffset[L_AXIS] - point[L_AXIS];
        }

        //得到新的O轴坐标
        point_O = value - axisAngle[X_AXIS] - axisAngle[L_AXIS] + GP->JXS_Parameter.OriginOffset[O_AXIS];
        if(GP->Robot_SoftLimit[O_AXIS].Switch_Limit == TRUE && point_O < static_cast<int>(GP->Robot_SoftLimit[O_AXIS].Left_Limit))
        {
            point_O = GP->Robot_SoftLimit[O_AXIS].Left_Limit;
        }
        else if(GP->Robot_SoftLimit[O_AXIS].Switch_Limit == TRUE && point_O > static_cast<int>(GP->Robot_SoftLimit[O_AXIS].Right_Limit))
        {
            point_O = GP->Robot_SoftLimit[O_AXIS].Right_Limit;
        }

        if(GP->sCartesian_Para.MDCoordType == 2)
        {//SCARA时，根据O轴的变化，得到新的Z轴坐标
            screw = GP->sCartesian_Para.pitchLength / 100.0f;
            offsetPostion = (point_O - point[O_AXIS]) * screw / 360;
            if(GP->sCartesian_Para.axisBackMinDir[i] == 0)
            {
                point[Z_AXIS] = offsetPostion + point[Z_AXIS];
            }
            else
            {
                point[Z_AXIS] = point[Z_AXIS] - offsetPostion;

            }
        }

        point[O_AXIS] = point_O;
    }
    else if(GP->g_AxiseCarteType == 1 && GP->sCartesian_Para.MDCoordType == 2 && axisNum == Z_AXIS)
    {//SCARA结构时，Z轴需要转换
        point[Z_AXIS] = value + GP->JXS_Parameter.OriginOffset[Z_AXIS];
        //计算Z轴新的软限位
        z_MinPos = AXisMovePosCal_Z(Z_AXIS, point[O_AXIS] / 100.0f, 0) * 100;
        z_MaxPos = AXisMovePosCal_Z(Z_AXIS, point[O_AXIS] / 100.0f, 1) * 100;

        if(GP->Robot_SoftLimit[Z_AXIS].Switch_Limit == TRUE && point[Z_AXIS] < z_MinPos)
        {
            point[Z_AXIS] = z_MinPos;
        }
        else if(GP->Robot_SoftLimit[Z_AXIS].Switch_Limit == TRUE && point[Z_AXIS] > z_MaxPos)
        {
            point[Z_AXIS] = z_MaxPos;
        }
    }
    else if(GP->g_AxiseCarteType == 1 && (GP->sCartesian_Para.MDCoordType == 1 || GP->sCartesian_Para.MDCoordType == 2))
    {//当前显示为笛卡尔坐标系
        ret = MD_InvSolCal(point, tarPointTemp, axisNum, value);			//逆解得到轴坐标
        if(ret == 0)
        {
            for(i=0; i<AXIS_NUM; i++)
            {
                if(GP->sCartesian_Para.axisType[i] == 1)
                {//旋转轴才需要赋值
                    point[i] = tarPointTemp[i];
                }
                else if(i == Z_AXIS && GP->sCartesian_Para.axisType[O_AXIS] == 1)
                {//如果O轴为旋转轴，Z轴就需要补偿
                    point[i] = tarPointTemp[i];
                }
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {//显示为轴坐标系时直接赋值
        point[axisNum] = value + GP->JXS_Parameter.OriginOffset[axisNum];
        if(point[axisNum] < 0)
        {
            point[axisNum] = 0;
        }
    }

    return 0;
}

/**************************************************************************************************
**  函数名：  FindHandcoor()
**	输入参数：关节2的角度theta2，单位rad
**	输出参数：机器人手系，1右手系 0左手系
**	函数功能：根据theta2计算scara机器人当前手系
**	备注：
**				右手系：theta2范围(0,Π)U(-2Π,-Π)
**				左手系：theta2范围(-Π,0)U(Π,2Π)
**				奇异位置：theta2取值{-2Π,-Π,0,Π,2Π}
***************************************************************************************************/
u8 MD::ScaraFindHandcoor(double theta2)
{
    u8 handcoor = 0;

    if((theta2 > 0.0f && theta2 < SCARA_PI) || (theta2 > -2.0f * SCARA_PI && theta2 < -SCARA_PI))
    {
        handcoor = 1;
    }
    else
    {
        handcoor = 0;
    }

    return handcoor;
}

/**************************************************************************************************
**  函数名：  FindFlagJ1()
**	输入参数：关节的角度theta1，单位rad
**	输出参数：scara机器人当前J1关节标志位
**	函数功能：计算scara机器人当前J1关节标志位
**	备注：
**				FlagJ1=0：theta1范围[-Π,Π];否则，FlagJ1=1
***************************************************************************************************/
u8 MD::ScaraFindFlagJ1(double theta1)
{
    u8 flagJ1 = 0;

    if(theta1 >= -SCARA_PI && theta1 <= SCARA_PI)
    {
        flagJ1 = 0;
    }
    else
    {
        flagJ1 = 1;
    }

    return flagJ1;
}

/**************************************************************************************************
**  函数名：  FindFlagJ2()
**	输入参数：关节的角度theta2，单位rad
**	输出参数：scara机器人当前J2关节标志位
**	函数功能：计算scara机器人当前J2关节标志位
**	备注：
**				FlagJ2=0：theta2范围[-Π,Π];否则，FlagJ2=1
***************************************************************************************************/
u8 MD::ScaraFindFlagJ2(double theta2)
{
    u8 flagJ2 = 0;

    if(theta2 >= -SCARA_PI && theta2 <= SCARA_PI)
    {
        flagJ2 = 0;
    }
    else
    {
        flagJ2 = 1;
    }

    return flagJ2;
}

/**************************************************************************************************
**  函数名：  ScaraForwardKinematics()
**	输入参数：大臂长(mm),小臂长(mm),丝杆螺距(mm),机器人关节角度(rad),机器人关节位置(mm或rad)
**	输出参数：scara机器人运动学正解
**	函数功能：计算scara机器人末端位置(mm或rad)
**	备注：
***************************************************************************************************/
u8 MD::ScaraForwardKinematics(double L1, double L2, double screw, ST_SCARA_JOINT_ANGLE jointAngle, ST_SCARA_JOINT_POS *jointPos)
{
    u8 ret = 0;

    jointPos->x = L1 * qCos(jointAngle.theta[0]) + L2 * qCos(jointAngle.theta[0] + jointAngle.theta[1]);

    jointPos->y = L1 * qSin(jointAngle.theta[0]) + L2 * qSin(jointAngle.theta[0] + jointAngle.theta[1]);

    jointPos->z = jointAngle.theta[2] * screw / (2 * SCARA_PI);

    jointPos->c = jointAngle.theta[0] + jointAngle.theta[1] + jointAngle.theta[3];

    return ret;
}

/**************************************************************************************************
**  函数名：  ScaraInverseKinematics()
**	输入参数：大臂长(mm),小臂长(mm),丝杆螺距(mm),机器人关节位置(mm或rad),
**						机器人当前手系, 机器人当前J1关节标志位, 机器人当前J2关节标志位, 需要得到的机器人关节角度(rad)
**	输出参数：scara机器人运动学逆解
**	函数功能：计算scara机器人末端位置(mm或rad)
**	备注：
***************************************************************************************************/
u8 MD::ScaraInverseKinematics(double L1, double L2, double screw, ST_SCARA_JOINT_POS jointPos, u8 handcoor, u8 flagJ1, u8 flagJ2, ST_SCARA_JOINT_ANGLE *jointAngle)
{
    u8 ret = 0;
    double c2 = 0.0f;
    double s2 = 0.0f;
    double calErr = 0.00001f;					//允许计算误差
    double temp = 0.0f;

    /*若末端在(x,y)坐标系中，C2必在[-1,1]里，但由于计算精度，c2绝对值可能稍微大于1*/
    c2 = (jointPos.x * jointPos.x + jointPos.y * jointPos.y - L1 * L1 - L2 * L2) / (2.0f * L1 * L2);
    temp = 1.0f - c2 * c2;
    if(temp < 0.0f)
    {
        if(temp > -calErr)
        {
            temp = 0.0f;
        }
    else
        {
            return 1;
        }
    }

    if(handcoor == 0)
    {//左手系
        jointAngle->theta[1] = qAtan2(-qSqrt(temp), c2);
    }
    else
    {//右手系
        jointAngle->theta[1] = qAtan2(qSqrt(temp), c2);
    }

    s2 = qSin(jointAngle->theta[1]);
    jointAngle->theta[0] = qAtan2(jointPos.y, jointPos.x) - qAtan2(L2 * s2, L1 + L2 * c2);

    if(screw == 0.0f)
    {
        jointAngle->theta[2] = 0;
    }
    else
    {
        jointAngle->theta[2] = 2.0f * SCARA_PI * jointPos.z / screw;
    }

    if(jointAngle->theta[0] <= -SCARA_PI)
    {
        jointAngle->theta[0] = jointAngle->theta[0] + 2.0f * SCARA_PI;
    }
    else if(jointAngle->theta[0] >= SCARA_PI)
    {
        jointAngle->theta[0] = jointAngle->theta[0] - 2.0f * SCARA_PI;
    }

    if(flagJ1 == 1)
    {
        if(jointAngle->theta[0] >= 0.0f)
        {
            jointAngle->theta[0] = jointAngle->theta[0] - 2.0f * SCARA_PI;
        }
        else
        {
            jointAngle->theta[0] = jointAngle->theta[0] + 2.0f * SCARA_PI;
        }
    }

    if(flagJ2 == 1)
    {
        if(jointAngle->theta[1] >= 0.0f)
        {
            jointAngle->theta[1] = jointAngle->theta[1] - 2.0f * SCARA_PI;
        }
        else
        {
            jointAngle->theta[1] = jointAngle->theta[1] + 2.0f * SCARA_PI;
        }
    }

    jointAngle->theta[3] = jointPos.c - jointAngle->theta[0] - jointAngle->theta[1];

    return ret;
}

/**************************************************************************************************
**  函数名：  AXisMovePosCal_Z()
**	输入参数：Axsis轴编号 tarPos_O O轴将要运动或当前的位置 posType 0返回最小坐标 1返回最大坐标
**	输出参数：无
**	函数功能：计算Z轴手动移动时的目标位置
**	备注：	  返回
**  作者：
**  开发日期：
***************************************************************************************************/
float MD::AXisMovePosCal_Z(u8 Axsis, double tarPos_O, u8 posType)
{
    s32 interAxisDis = 0;
    double dis1 = 0.0f;
    double dis2 = 0.0f;
    //float dis3 = 0.0f;

    /*计算因O轴旋转引起的高度变化量*/
    dis1 = tarPos_O / 360.0f;											//将O轴可以旋转的总的角度转换成多少圈
    dis1 = dis1 * GP->sCartesian_Para.pitchLength / 100.0f;				//计算得到Z轴的补偿量
    if(GP->sCartesian_Para.axisBackMinDir[Axsis] == 1)
    {//两个轴的结构上表现垂直方向上的方向要相反，确保爪子在运动过程中保持原来高度
        dis1 = -dis1;
    }

    if(posType == 1)
    {//返回最大限位坐标
        interAxisDis = GP->Robot_SoftLimit[Axsis].Right_Limit / 100.0f + dis2 + dis1;
    }
    else
    {//返回最小限位坐标
        interAxisDis = dis2 + dis1;
    }

    return interAxisDis;
}
