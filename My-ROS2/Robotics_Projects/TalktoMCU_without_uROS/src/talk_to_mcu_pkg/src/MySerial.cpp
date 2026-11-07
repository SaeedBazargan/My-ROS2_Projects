#include "talk_to_mcu_pkg/MySerial.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <cstring>
#include <iostream>

SerialPort::SerialPort() : fd(-1), isOpen(false)
{}
SerialPort::~SerialPort()
{
    serialClose();
}

bool SerialPort::serialOpen(const std::string& port, int speed)
{    
    fd = open(port.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if(fd < 0)
    {
        std::cerr << "Error opening " << port << ": " << strerror(errno) << std::endl;
        return false;
    }
    
    // Configure serial port
    struct termios tty = {};   
    cfsetospeed(&tty, speed);
    cfsetispeed(&tty, speed);
    
    tty.c_cflag = CS8 | CLOCAL | CREAD;
    tty.c_iflag = 0;
    tty.c_oflag = 0;
    tty.c_lflag = 0;
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 5;
    
    if(tcsetattr(fd, TCSANOW, &tty) != 0)
    {
        std::cerr << "tcsetattr error: " << strerror(errno) << std::endl;
        close(fd);
        return false;
    }
    
    isOpen = true;

    serialFlush();
    return true;
}

void SerialPort::serialClose()
{
    if(fd >= 0)
    {
        close(fd);
        isOpen = false;
        fd = -1;
    }
}

bool SerialPort::serial_isOpen()
{
    return isOpen;
}

int SerialPort::serialWrite(const std::string& data)
{
    return write(fd, data.c_str(), data.size());
}

std::string SerialPort::serialRead(size_t maxSize)
{    
    char* buffer = new char[maxSize + 1];
    int n = read(fd, buffer, maxSize);
    
    if(n <= 0)
    {
        delete[] buffer;
        return "";
    }
    
    buffer[n] = '\0';
    std::string result(buffer);
    delete[] buffer;
    return result;
}

void SerialPort::serialFlush()
{
    if(fd < 0)
    {
        return;
    }
    
    // TCIOFLUSH: Flush both input and output
    if(tcflush(fd, TCIOFLUSH) != 0)
    {
        std::cerr << "Error flushing serial port: " << strerror(errno) << std::endl;
    }
}