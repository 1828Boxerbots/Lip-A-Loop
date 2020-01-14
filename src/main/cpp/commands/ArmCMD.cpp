/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "../include/commands/ArmCMD.h"
#include <Robot.h>
#include <frc/smartdashboard/SmartDashboard.h>

ArmCMD::ArmCMD() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_arm);
}

// Called just before this Command runs the first time
void ArmCMD::Initialize() 
{
  Robot::m_arm.InitDefaultCommand();
}

// Called repeatedly when this Command is scheduled to run
void ArmCMD::Execute() 
{
  Robot::m_arm.Log();
  //Declare Variables
  frc::XboxController * pController = Robot::m_oi.getController();
  bool buttonA = pController -> GetAButton();
  bool buttonB = pController -> GetBButton();
  bool buttonX = pController -> GetXButton();
  bool buttonY = pController -> GetYButton();
  bool bumperL = pController -> GetBumper(frc::GenericHID::kLeftHand);
  bool bumperR = pController -> GetBumper(frc::GenericHID::kRightHand);
  //Run Commands

  frc::SmartDashboard::SmartDashboard::GetBoolean("Button A", buttonA);
  frc::SmartDashboard::SmartDashboard::GetBoolean("Button B", buttonB);
  frc::SmartDashboard::SmartDashboard::GetBoolean("Button X", buttonX);
  frc::SmartDashboard::SmartDashboard::GetBoolean("Button Y", buttonY);

  //Lifting and lowering arm
    if(bumperL == true && bumperR == false)
    {
      Robot::m_arm.Lift();
    }
    else if(bumperL == false && bumperR == true)
    {
      Robot::m_arm.Lower();  
    }
  
  //Opening and closing hand
  if(buttonX == true && buttonY == false)
  {
    Robot::m_arm.Open();
  }
  else if(buttonX == false && buttonY == true)
  {
    Robot::m_arm.Close();
  }

  //Tilting up and down the hand
  if(buttonA == true && buttonB == false)
  {
    Robot::m_arm.TiltUp();
  }
  else if(buttonA == false && buttonB == true)
  {
    Robot::m_arm.TiltDown();
  }
}

// Make this return true when this Command no longer needs to run execute()
bool ArmCMD::IsFinished() { return false; }

// Called once after isFinished returns true
void ArmCMD::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmCMD::Interrupted() {}
