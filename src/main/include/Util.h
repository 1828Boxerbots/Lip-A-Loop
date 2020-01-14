/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

namespace Util
{
  double Limit(double value, double lowerLimit = -1.0, double upperLimit = 1.0);
  double ServoLimit(double value, double lowerLimit = 0.0, double upperLimit = 0.9);
}
