/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "ModifiedArcadeDrive.h"
#include <rev/CANSparkMax.h>

class MAD_SparkMax : public ModifiedArcadeDrive {
 private:
  rev::CANSparkMax *m_leftMotor, *m_rightMotor;

 public:
  MAD_SparkMax(rev::CANSparkMax * lMotor, rev::CANSparkMax * Mrotor, double P, double I, double D, double F);

 private:
  virtual void setLeftMotor(double value);
  virtual void setRightMotor(double value);
  virtual void setLeftMotorPosition(int ticks);
  virtual void setRightMotorPosition(int ticks);
  virtual void setLeftMotorSetpoint(int ticks);
  virtual void setRightMotorSetpoint(int ticks);
  virtual void setP(double value);
  virtual void setI(double value);
  virtual void setD(double value);
};