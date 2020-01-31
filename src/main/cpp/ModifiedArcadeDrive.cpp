#include "ModifiedArcadeDrive.h"
#include <frc/Timer.h>
#include <math.h>
#include <rev/CANSparkMax.h>

using namespace frc;

void ModifiedArcadeDrive::ModArcadeDrive(double xSpeed, double zRotation, double coeffA)
{
   if(abs(xSpeed) < m_deadband)
   {
      xSpeed = 0;
   }
   else
   {
      xSpeed = std::copysign(coeffA*xSpeed*xSpeed, xSpeed);
   }

   if(abs(zRotation) < m_deadband)
   {
      zRotation = 0;
   }
   else
   {
      zRotation = std::copysign(coeffA*xSpeed*xSpeed, xSpeed);
   }

   if (xSpeed > 1)
   {
      xSpeed = 1;
   }
   else if (xSpeed < -1)
   {
      xSpeed = -1;
   }

   if (zRotation > 1)
   {
      zRotation = 1;
   }
   else if (zRotation < -1)
   {
      zRotation = -1;
   }

   /*
   if(abs(xSpeed) < m_deadband)
   {
      xSpeed = 0;
   }
   else if(abs(xSpeed) < (1 - m_deadband) * m_thresholdPercentage + m_deadband)
   {
      xSpeed = std::copysign(m_lowSpeedControlMultiplier * (abs(xSpeed)  - m_deadband), xSpeed);
   }
   else
   {
      xSpeed = std::copysign(m_highSpeedControlMultiplier * abs(xSpeed) + 1 - m_highSpeedControlMultiplier, xSpeed);
   }

   if(abs(zRotation) < m_deadband)
   {
      zRotation = 0;
   }
   else if(abs(zRotation) < (1 - m_deadband) * m_thresholdPercentage + m_deadband)
   {
      zRotation = std::copysign(m_lowSpeedControlMultiplier * (abs(zRotation)  - m_deadband), zRotation);
   }
   else
   {
      zRotation = std::copysign(m_highSpeedControlMultiplier * abs(zRotation) + 1 - m_highSpeedControlMultiplier, zRotation);
   }
   */

   ArcadeDrive(xSpeed, zRotation);
}

void ModifiedArcadeDrive::ArcadeDrive(double xSpeed, double zRotation){
   double leftMotorOutput;
   double rightMotorOutput;
   double maxInput = std::copysign(std::max(std::abs(xSpeed), std::abs(zRotation)), xSpeed);

   if (xSpeed >= 0.0)
   {
      // First quadrant, else second quadrant
      if (zRotation >= 0.0)
      {
         leftMotorOutput = maxInput;
         rightMotorOutput = xSpeed - zRotation;
      }
      else
      {
         leftMotorOutput = xSpeed + zRotation;
         rightMotorOutput = maxInput;
      }
   }
   else
   {
      // Third quadrant, else fourth quadrant
      if (zRotation >= 0.0)
      {
         leftMotorOutput = xSpeed + zRotation;
         rightMotorOutput = maxInput;
      }
      else
      {
         leftMotorOutput = maxInput;
         rightMotorOutput = xSpeed - zRotation;
      }
   }
   m_leftMotor->Set(leftMotorOutput);
   m_rightMotor->Set(rightMotorOutput);

}
