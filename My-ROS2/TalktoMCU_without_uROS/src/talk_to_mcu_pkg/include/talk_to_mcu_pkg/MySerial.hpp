#ifndef MYSERIAL_H
#define MYSERIAL_H

#include <string>
#include <termios.h>

class SerialPort
{
private:
    int fd;
    bool isOpen;

public:
    SerialPort();  // Constructor
    ~SerialPort(); // Destructor
    
    bool serialOpen(const std::string& port, int speed = B9600);
    void serialClose();
    bool serial_isOpen();
    int serialWrite(const std::string& data);
    std::string serialRead(size_t maxSize = 100);
    void serialFlush();
};

#endif