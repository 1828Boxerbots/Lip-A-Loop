/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Util.h"

double Util::Limit(double value, double lowerLimit, double upperLimit)
{
    if(lowerLimit > upperLimit)
    {
        return value;
    }

    if(value < lowerLimit)
    {
        value = lowerLimit;
    }

    if(value > upperLimit)
    {
        value = upperLimit;
    }

    return value;
}

double Util::ServoLimit(double value, double lowerLimit, double upperLimit)
{
    return Limit(value, lowerLimit, upperLimit);
}
