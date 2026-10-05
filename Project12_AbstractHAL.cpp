// Project 12: Hardware Abstraction Layer (HAL) - Robotic Payload Manager
// Create an abstract base class PayloadDevice with pure virtual functions
// selfTest() and runTask(). Implement three concrete devices: CameraGimbal,
// Spectrometer, and DrillMechanism. In main(), create an array of
// PayloadDevice* pointers, run a system checkout (selfTest), and if all devices
// pass, trigger their respective mission tasks (runTask).

#include <iostream>
#include <string>

// Abstract Base Class (Hardware Interface)
class PayloadDevice {
public:
  std::string device_name;
  int power_watts;

  PayloadDevice(std::string name, int power)
      : device_name(name), power_watts(power) {}

  // Pure virtual functions: define the interface contract
  virtual bool selfTest() = 0;
  virtual void runTask() = 0;

  // Virtual destructor ensures proper cleanup of derived objects
  virtual ~PayloadDevice() {}
};

// Concrete Device 1: Camera Gimbal
class CameraGimbal : public PayloadDevice {
public:
  CameraGimbal(std::string name, int power) : PayloadDevice(name, power) {}

  bool selfTest() override {
    std::cout << "[" << device_name << "] Centering pan/tilt servos... OK."
              << std::endl;
    return true;
  }

  void runTask() override {
    std::cout << "[" << device_name
              << "] Capturing 360-degree panoramic survey." << std::endl;
  }
};

// Concrete Device 2: Spectrometer
class Spectrometer : public PayloadDevice {
public:
  Spectrometer(std::string name, int power) : PayloadDevice(name, power) {}

  bool selfTest() override {
    std::cout << "[" << device_name
              << "] Calibrating laser detector baseline... OK." << std::endl;
    return true;
  }

  void runTask() override {
    std::cout << "[" << device_name
              << "] Analyzing surface mineral absorption spectrum."
              << std::endl;
  }
};

// Concrete Device 3: Drill Mechanism
class DrillMechanism : public PayloadDevice {
public:
  int max_depth_cm;

  DrillMechanism(std::string name, int power, int depth)
      : PayloadDevice(name, power), max_depth_cm(depth) {}

  bool selfTest() override {
    std::cout << "[" << device_name
              << "] Verifying torque limit switch and bit clamp... OK."
              << std::endl;
    return true;
  }

  void runTask() override {
    std::cout << "[" << device_name << "] Drilling " << max_depth_cm
              << " cm core sample into canister." << std::endl;
  }
};

int main() {
  CameraGimbal cam("GimbalCam-1", 15);
  Spectrometer spec("NIR-Spectrometer", 25);
  DrillMechanism drill("CoreDrill-X", 75, 10);

  // Array of base class pointers managing all payload hardware
  PayloadDevice *payloads[3] = {&cam, &spec, &drill};

  std::cout << "=== ROVER PAYLOAD PRE-FLIGHT CHECKOUT ===" << std::endl;
  bool all_systems_go = true;
  int total_power = 0;

  for (int i = 0; i < 3; i++) {
    total_power += payloads[i]->power_watts;
    bool passed = payloads[i]->selfTest();
    if (!passed) {
      all_systems_go = false;
      std::cout << "ALERT: Hardware failure on " << payloads[i]->device_name
                << std::endl;
    }
  }

  std::cout << "Total Payload Power Draw: " << total_power << " W" << std::endl;

  if (all_systems_go) {
    std::cout << "\n=== EXECUTING SURFACE SCIENCE MISSION ===" << std::endl;
    for (int i = 0; i < 3; i++) {
      payloads[i]->runTask();
    }
    std::cout << "=== MISSION PAYLOAD TASKS COMPLETE ===" << std::endl;
  } else {
    std::cout << "\nMission aborted due to payload diagnostic failure."
              << std::endl;
  }

  return 0;
}

// g++ Project12_AbstractHAL.cpp -o Project12_AbstractHAL.exe;
// .\Project12_AbstractHAL.exe
