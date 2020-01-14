/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "../include/RobotMap.h"
#include <frc/Servo.h>

class Arm : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Arm();
  void InitDefaultCommand() override;

  //objects
  frc::Servo m_servoArm {PWM_SERVO_ARM};
  frc::Servo m_servoWrist {PWM_SERVO_WRIST};
  frc::Servo m_servoHand {PWM_SERVO_HAND};
  //functions
  void LiftArm(double angle);
  void OpenHand(double angle);
  void Open();
  void Close();
  void Lift();
  void Lower();
  void TiltDown();
  void TiltUp();
  void Log();
  void SetTwoZero();

  private:
  double oneDegree = 0.005;
  double scale = 0.1;

  double m_handAngle = 0.0;
  double m_armAngle = 0.0;
  double m_wristAngle = 0.0;

  const double MIN_ARM = 0.16;
  const double MAX_ARM = 0.65;

  const double MIN_WRIST = 0.0;
  const double MAX_WRIST = 0.47;

  const double MIN_HAND = 0.06;
  const double MAX_HAND = 0.5;
};
