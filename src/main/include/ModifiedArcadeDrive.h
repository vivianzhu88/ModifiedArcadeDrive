/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <thread>
#include <rev/CANSparkMax.h>

class ModifiedArcadeDrive {
  public:
   double m_deadband = 0.12;
   double m_lowSpeedControlMultiplier = 0.57;
   double m_highSpeedControlMultiplier = 1.46;
   double m_thresholdPercentage = 0.5;

  public:
    void ModArcadeDrive(double xSpeed, double zRotation, double coeffA);
    void ArcadeDrive(double xSpeed, double zRotation);

  private:
    rev::CANSparkMax *m_leftMotor, *m_rightMotor;

  private:
    virtual void setLeftMotor(double value);
    virtual void setRightMotor(double value);
};