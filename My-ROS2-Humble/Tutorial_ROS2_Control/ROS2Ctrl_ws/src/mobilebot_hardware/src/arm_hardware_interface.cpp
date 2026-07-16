#include "mobilebot_hardware/arm_hardware_interface.hpp"

namespace arm_hardware{

// Called when the hardware interface is initialized
hardware_interface::CallbackReturn ArmHardwareInterface::on_init(const hardware_interface::HardwareInfo &arm_info_)
{
    // Call the base class on_init to initialize info_ structure
    if(hardware_interface::SystemInterface::on_init(arm_info_) != hardware_interface::CallbackReturn::SUCCESS)
    {
        return hardware_interface::CallbackReturn::ERROR;
    }

    info_ = arm_info_;        // Store the hardware info locally

    actuator_id_ = 1;
    potr_num_ = "/dev/ttyUSB";
    driver_ = std::make_shared<MX64Driver>(potr_num_);      // Create the motor driver object

    return hardware_interface::CallbackReturn::SUCCESS;
}

// Called when the hardware interface is configured
hardware_interface::CallbackReturn ArmHardwareInterface::on_configure(const rclcpp_lifecycle::State &previous_state_)
{
    (void)previous_state_;
    if(driver_->init() != 0)
    {
        return hardware_interface::CallbackReturn::ERROR;
    }

    return hardware_interface::CallbackReturn::SUCCESS;
}

// Called when the hardware interface is activated (ready to run)
hardware_interface::CallbackReturn ArmHardwareInterface::on_activate(const rclcpp_lifecycle::State &previous_state_)
{
    (void)previous_state_;

    // Reset joint states
    arm_joint_position_ = 0.0;

    driver_->activateWithPositionMode(actuator_id_);

    return hardware_interface::CallbackReturn::SUCCESS;
}

// Called when the hardware interface is deactivated (stop sending commands)
hardware_interface::CallbackReturn ArmHardwareInterface::on_deactivate(const rclcpp_lifecycle::State &previous_state_)
{
    (void)previous_state_;
    driver_->deactivate(actuator_id_);

    return hardware_interface::CallbackReturn::SUCCESS;
}

// Export all state interfaces (readable values) for ROS2 controllers
std::vector<hardware_interface::StateInterface> ArmHardwareInterface::export_state_interfaces()
{
    std::vector<hardware_interface::StateInterface> state_interfaces;

    // Map joint positions and velocities to state interface
    state_interfaces.emplace_back("arm_base_forearm_joint", "position", &arm_joint_position_);
    state_interfaces.emplace_back("forearm_hand_joint", "position", &arm_joint_position_);

    // Return the list of state interfaces
    return state_interfaces;
}

// Export all command interfaces (writable values) for ROS2 controllers
std::vector<hardware_interface::CommandInterface> ArmHardwareInterface::export_command_interfaces()
{
    std::vector<hardware_interface::CommandInterface> command_interfaces;

    // Map wheel velocity commands to command interface
    command_interfaces.emplace_back("arm_base_forearm_joint", "position", &arm_joint_position_command_);
    command_interfaces.emplace_back("forearm_hand_joint", "position", &arm_joint_position_command_);

    return command_interfaces;
}

// Read current motor states from hardware and update state variables
hardware_interface::return_type ArmHardwareInterface::read(const rclcpp::Time &time_, const rclcpp::Duration &period_)
{
    (void)time_;
    (void)period_;
    double act_position_ = driver_->getPositionRadian(actuator_id_);

    // Update the position state for both wheels
    arm_joint_position_ = act_position_;

    return hardware_interface::return_type::OK;
}

// Write commanded velocities to the motor hardware
hardware_interface::return_type ArmHardwareInterface::write(const rclcpp::Time &time_, const rclcpp::Duration &period_)
{
    (void)time_;
    (void)period_;
    driver_->setTargetPositionRadian(actuator_id_, arm_joint_position_command_);

    return hardware_interface::return_type::OK;
}


}   // namespace arm_hardware

#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(arm_hardware::ArmHardwareInterface, hardware_interface::SystemInterface)

