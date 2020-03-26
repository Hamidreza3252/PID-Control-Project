# PID Control Project 


## 1. Objective 
The objective of this project is to develop and fine-tune the parameters of two PID controllers to adjust the steering and throtle of the car.  

## 2. Approach 

### Input Data and Main Functions 
The simulator provides cte (error with respeect to the center of the lane), speed, and steering angle of the ego car. The PID controller class has two functions to estimate the steering angle and the throtle to get up to speed of 30 mph. 

These methods are: 
- `TotalSteerError` calculates total PID error of steering 
- `TotalThrotleError` calculates total PID error of throtle. This method works with the velocity error which is the differene between the velocity of the ego vehicle and the set point of 30 mph. 

### Hyper Parameters 
I followed a straightforward instruction to fine-tune the PID hyper parameters to calculate the steering angle and throtle value. I first set `kd` and `ki` to zero and then manually played with `kp`, the proportional factor. After finding the close range, then I manually played with `kd` and `ki` step by step to find the best combination of these parameters. 


## 3. Dependencies

* cmake >= 3.5
* gcc/g++ >= 5.4
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `install-mac.sh` or `install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
* The simulator can be downloaded from [project intro page](https://github.com/udacity/self-driving-car-sim/releases). 

## 4. Code Style

I used [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html) for this project. 


