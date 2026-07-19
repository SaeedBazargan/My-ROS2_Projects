#include "rclcpp/rclcpp.hpp"
#include "dxl_test/mx64_driver.hpp"

using namespace std::chrono_literals;

int main()
{
    uint8_t dxl_ID = 1;

    auto driver_ = MX64Driver("/dev/ttyUSB0");
    driver_.init();
    std::this_thread::sleep_for(1s);

    driver_.activateWithVelocityMode(dxl_ID);
    driver_.setTargetVelocityRadianPerSec(dxl_ID, 3.14159);

    std::this_thread::sleep_for(1s);

    double velocity_ = driver_.getVelocityRadianPerSec(dxl_ID);
    std::cout << "Velocity ID_1: " << velocity_ << std::endl;

    driver_.deactivate(dxl_ID);

    return 0;
}
