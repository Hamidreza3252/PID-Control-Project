#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

// --------------------------------------------------------------------------------------------------------------------
PID::PID()
{
  i_steer_error_ = 0.0;
  i_throtle_error_ = 0.0;
}

// --------------------------------------------------------------------------------------------------------------------
PID::~PID()
{
}

// --------------------------------------------------------------------------------------------------------------------
void PID::Init(double kp_steer, double ki_steer, double kd_steer, double kp_throtle, double ki_throtle, double kd_throtle)
{
  kp_steer_ = kp_steer;
  ki_steer_ = ki_steer;
  kd_steer_ = kd_steer;

  i_steer_error_ = 0.0;

  kp_throtle_ = kp_throtle;
  ki_throtle_ = ki_throtle;
  kd_throtle_ = kd_throtle;

  i_throtle_error_ = 0.0;
}

// --------------------------------------------------------------------------------------------------------------------
void PID::UpdateSteerError(double cte, double delta_t)
{
  p_steer_error_ = cte;
  d_steer_error_ = (cte - prev_steer_cte_) / delta_t;
  i_steer_error_ += cte;

  prev_steer_cte_ = cte;
}

// --------------------------------------------------------------------------------------------------------------------
double PID::TotalSteerError()
{
  return -(kp_steer_ * p_steer_error_ + kd_steer_ * d_steer_error_ + ki_steer_ * i_steer_error_);
}

// --------------------------------------------------------------------------------------------------------------------
void PID::UpdateThrotleError(double speed, double target_speed, double delta_t)
{
  double cte = speed - target_speed;

  p_throtle_error_ = cte;
  d_throtle_error_ = (cte - prev_throtle_cte_) / delta_t;
  i_throtle_error_ += cte;

  prev_throtle_cte_ = cte;
}

// --------------------------------------------------------------------------------------------------------------------
double PID::TotaThrotleError()
{
  return -(kp_throtle_ * p_throtle_error_ + kd_throtle_ * d_throtle_error_ + ki_throtle_ * i_throtle_error_);
}

// --------------------------------------------------------------------------------------------------------------------
