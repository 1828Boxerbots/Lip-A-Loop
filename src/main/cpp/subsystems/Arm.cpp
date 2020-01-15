/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "../include/subsystems/Arm.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include "../include/Util.h"

Arm::Arm() : Subsystem("Arm") {}

void Arm::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  m_handAngle = 0.0;
  m_armAngle = 0.0;
  m_wristAngle = 0.0;

  SetTwoZero();
  Log();
}

void Arm::Log()
{
  frc::SmartDashboard::SmartDashboard::PutNumber("Hand Angle", m_handAngle);
  frc::SmartDashboard::SmartDashboard::PutNumber("Arm Angle", m_armAngle);
  frc::SmartDashboard::SmartDashboard::PutNumber("Wrist Angle", m_wristAngle);
}

void Arm::SetTwoZero()
{
  //m_servoArm.Set(0.0);
  //m_servoHand.Set(0.5);
  //m_servoWrist.Set(0.0);
}

void Arm::Open()
{
  m_handAngle += oneDegree;
  m_handAngle = Util::ServoLimit(m_handAngle, MIN_HAND, MAX_HAND);
  OpenHand(m_handAngle);
}

void Arm::Close()
{ 
  m_handAngle -= oneDegree;
  m_handAngle = Util::ServoLimit(m_handAngle, MIN_HAND, MAX_HAND);
  OpenHand(m_handAngle);
}

void Arm::OpenHand(double angle)
{
  m_servoHand.Set(Util::ServoLimit(angle));
}

void Arm::Lift()
{
  m_armAngle += oneDegree * scale;
  m_armAngle = Util::ServoLimit(m_armAngle, MIN_ARM, MAX_ARM);
  LiftArm(m_armAngle);
}

void Arm::Lower()
{
  m_armAngle -= oneDegree * scale;
  m_armAngle = Util::ServoLimit(m_armAngle, MIN_ARM, MAX_ARM);
  LiftArm(m_armAngle);
}

void Arm::LiftArm(double angle)
{
  m_servoArm.Set(Util::ServoLimit(angle));
  //m_servoWrist.Set(m_wristAngle + angle);
}

void Arm::TiltDown()
{
  m_wristAngle -= oneDegree;
  m_wristAngle = Util::ServoLimit(m_wristAngle, MIN_WRIST, MAX_WRIST);
  m_servoWrist.Set(m_wristAngle);
}

void Arm::TiltUp()
{
  m_wristAngle += oneDegree;
  m_wristAngle = Util::ServoLimit(m_wristAngle, MIN_WRIST, MAX_WRIST);
  m_servoWrist.Set(m_wristAngle);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
