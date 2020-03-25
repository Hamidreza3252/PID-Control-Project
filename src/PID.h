#ifndef PID_H
#define PID_H

class PID
{
public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double kp_steer, double ki_steer, double kd_steer, double kp_throtle, double ki_throtle, double kd_throtle);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateSteerError(double cte, double delta_t);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalSteerError();

  void UpdateThrotleError(double speed, double target_speed, double delta_t);
  double TotaThrotleError();

private:
  /**
   * PID Errors
   */
  double p_steer_error_;
  double i_steer_error_;
  double d_steer_error_;

  double prev_steer_cte_;

  /**
   * PID Coefficients
   */
  double kp_steer_;
  double ki_steer_;
  double kd_steer_;

  double p_throtle_error_;
  double i_throtle_error_;
  double d_throtle_error_;

  // double speed_;
  double kp_throtle_;
  double ki_throtle_;
  double kd_throtle_;

  double prev_throtle_cte_;
};

#endif // PID_H