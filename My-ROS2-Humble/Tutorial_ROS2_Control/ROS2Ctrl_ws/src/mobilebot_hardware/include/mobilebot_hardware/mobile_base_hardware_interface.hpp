#ifndef MOBILE_BASE_HARDWARE_INTERFACE_HPP
#define MOBILE_BASE_HARDWARE_INTERFACE_HPP

#include "hardware_interface/system_interface.hpp"
#include "mobilebot_hardware/mx64_driver.hpp"

namespace mobile_base_hardware{

class MobileBaseHardwareInterface : public hardware_interface::SystemInterface
{
private:
    std::shared_ptr<MX64Driver> driver_;
    uint8_t actuator_id_;
    std::string potr_num_;

    // Joint state variables
    double right_wheel_position_ = 0.0;
    double left_wheel_position_ = 0.0;
    double right_wheel_velocity_ = 0.0;
    double left_wheel_velocity_ = 0.0;

    // Joint command variables
    double right_wheel_velocity_command_ = 0.0;
    double left_wheel_velocity_command_ = 0.0;
        
public:
    // lifecycle node override
    hardware_interface::CallbackReturn on_configure(const rclcpp_lifecycle::State &previous_state_) override;
    hardware_interface::CallbackReturn on_activate(const rclcpp_lifecycle::State &previous_state_) override;
    hardware_interface::CallbackReturn on_deactivate(const rclcpp_lifecycle::State &previous_state_) override;

    // systemInterface override
    hardware_interface::CallbackReturn on_init(const hardware_interface::HardwareInfo &mobilebot_info_) override;
    hardware_interface::return_type read(const rclcpp::Time &time_, const rclcpp::Duration &period_) override;
    hardware_interface::return_type write(const rclcpp::Time &time_, const rclcpp::Duration &period_) override;

    std::vector<hardware_interface::StateInterface> export_state_interfaces() override;
    std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;
};

}   // namespace mobile_base_hardware

#endif /*MOBILE_BASE_HARDWARE_INTERFACE_HPP*/
