// Include the header for our hardware interface
#include "mobilebot_hardware/mobile_base_hardware_interface.hpp"

namespace mobile_base_hardware{

// Called when the hardware interface is initialized
hardware_interface::CallbackReturn MobileBaseHardwareInterface::on_init(const hardware_interface::HardwareInfo &mobilebot_info_)
{
    // Call the base class on_init to initialize info_ structure
    if(hardware_interface::SystemInterface::on_init(mobilebot_info_) != hardware_interface::CallbackReturn::SUCCESS)
    {
        return hardware_interface::CallbackReturn::ERROR;
    }

    info_ = mobilebot_info_;        // Store the hardware info locally

    actuator_id_ = 1;
    potr_num_ = "/dev/ttyUSB";
    driver_ = std::make_shared<MX64Driver>(potr_num_);      // Create the motor driver object

    return hardware_interface::CallbackReturn::SUCCESS;
}

// Called when the hardware interface is configured
hardware_interface::CallbackReturn MobileBaseHardwareInterface::on_configure(const rclcpp_lifecycle::State &previous_state_)
{
    (void)previous_state_;
    if(driver_->init() != 0)
    {
        return hardware_interface::CallbackReturn::ERROR;
    }

    return hardware_interface::CallbackReturn::SUCCESS;
}

// Called when the hardware interface is activated (ready to run)
hardware_interface::CallbackReturn MobileBaseHardwareInterface::on_activate(const rclcpp_lifecycle::State &previous_state_)
{
    (void)previous_state_;

    // Reset joint states
    right_wheel_position_ = 0.0;
    left_wheel_position_ = 0.0;
    right_wheel_velocity_ = 0.0;
    left_wheel_velocity_ = 0.0;    

    driver_->activateWithVelocityMode(actuator_id_);

    return hardware_interface::CallbackReturn::SUCCESS;
}

// Called when the hardware interface is deactivated (stop sending commands)
hardware_interface::CallbackReturn MobileBaseHardwareInterface::on_deactivate(const rclcpp_lifecycle::State &previous_state_)
{
    (void)previous_state_;
    driver_->deactivate(actuator_id_);

    return hardware_interface::CallbackReturn::SUCCESS;
}

// Export all state interfaces (readable values) for ROS2 controllers
std::vector<hardware_interface::StateInterface> MobileBaseHardwareInterface::export_state_interfaces()
{
    std::vector<hardware_interface::StateInterface> state_interfaces;

    // Map joint positions and velocities to state interface
    state_interfaces.emplace_back("base_RightWheel_joint", "position", &right_wheel_position_);
    state_interfaces.emplace_back("base_RightWheel_joint", "velocity", &right_wheel_velocity_);
    state_interfaces.emplace_back("base_LeftWheel_joint", "position", &left_wheel_position_);
    state_interfaces.emplace_back("base_LeftWheel_joint", "velocity", &left_wheel_velocity_);

    // Return the list of state interfaces
    return state_interfaces;
}

// Export all command interfaces (writable values) for ROS2 controllers
std::vector<hardware_interface::CommandInterface> MobileBaseHardwareInterface::export_command_interfaces()
{
    std::vector<hardware_interface::CommandInterface> command_interfaces;

    // Map wheel velocity commands to command interface
    command_interfaces.emplace_back("base_RightWheel_joint", "velocity", &right_wheel_velocity_command_);
    command_interfaces.emplace_back("base_LeftWheel_joint", "velocity", &left_wheel_velocity_command_);

    return command_interfaces;
}

// Read current motor states from hardware and update state variables
hardware_interface::return_type MobileBaseHardwareInterface::read(const rclcpp::Time &time_, const rclcpp::Duration &period_)
{
    (void)time_;
    double act_velocity_ = driver_->getVelocityRadianPerSec(actuator_id_);

    // Update the velocity state for both wheels
    right_wheel_velocity_ = act_velocity_;
    left_wheel_velocity_ = act_velocity_;

    // Integrate to get position
    right_wheel_position_ += act_velocity_ * period_.seconds();
    left_wheel_position_ += act_velocity_ * period_.seconds();

    return hardware_interface::return_type::OK;
}

// Write commanded velocities to the motor hardware
hardware_interface::return_type MobileBaseHardwareInterface::write(const rclcpp::Time &time_, const rclcpp::Duration &period_)
{
    (void)time_;
    (void)period_;
    driver_->setTargetVelocityRadianPerSec(actuator_id_, right_wheel_velocity_command_);

    return hardware_interface::return_type::OK;
}

}   // namespace mobile_base_hardware

// Export this class as a plugin for ROS2 controller manager
#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(mobile_base_hardware::MobileBaseHardwareInterface, hardware_interface::SystemInterface)