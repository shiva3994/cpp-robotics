#include <iostream>
#include <string>

// Abstract Base Class / Interface (HAL)
class MotorDriver {
public:
  std::string motor_name;

  MotorDriver(std::string name) : motor_name(name) {}

  // Pure virtual functions: MUST be implemented by any concrete motor driver
  virtual void setSpeed(int speed_rpm) = 0;
  virtual void stop() = 0;

  virtual ~MotorDriver() {} // Always virtual destructor
};

// Concrete implementation 1: DC Motor Driver (PWM based)
class DCMotor : public MotorDriver {
public:
  DCMotor(std::string name) : MotorDriver(name) {}

  void setSpeed(int speed_rpm) override {
    std::cout << "[" << motor_name << "] Setting PWM duty cycle for "
              << speed_rpm << " RPM." << std::endl;
  }

  void stop() override {
    std::cout << "[" << motor_name << "] Cutting PWM signal to 0%."
              << std::endl;
  }
};

// Concrete implementation 2: Stepper Motor Driver (Step pulses)
class StepperMotor : public MotorDriver {
public:
  StepperMotor(std::string name) : MotorDriver(name) {}

  void setSpeed(int speed_rpm) override {
    std::cout << "[" << motor_name << "] Generating step pulses at "
              << speed_rpm * 200 / 60 << " Hz." << std::endl;
  }

  void stop() override {
    std::cout << "[" << motor_name << "] Holding coils energized in brake mode."
              << std::endl;
  }
};

int main() {
  // MotorDriver test; // COMPILE ERROR: Cannot instantiate abstract class!

  DCMotor left_wheel("LeftDCMotor");
  StepperMotor arm_joint("ArmStepper");

  MotorDriver *drivetrain[2] = {&left_wheel, &arm_joint};

  std::cout << "--- Command: Engage Drive System (150 RPM) ---" << std::endl;
  for (int i = 0; i < 2; i++) {
    drivetrain[i]->setSpeed(150);
  }

  std::cout << "\n--- Command: Emergency Stop ---" << std::endl;
  for (int i = 0; i < 2; i++) {
    drivetrain[i]->stop();
  }

  return 0;
}

// Compile & run:
// g++ 18AbstractClasses.cpp -o 18AbstractClasses.exe; .\18AbstractClasses.exe
