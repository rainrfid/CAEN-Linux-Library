/*
 * Project:     Stouch application
 * File:        serialDevice.h
 * Author:      Claudio "Dna" Bonesana
 * Date:        july-august 2013
 * Version:     1.0
 *
 */

#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <errno.h>
#include <string>

#define MAX_BUFFER 4096

using namespace std;

/*!
 * \class SerialDevice
 * \brief The serialDevice class is used to communicate with a serial device.
 *
 * The SerialDevice class is used to establish a connection with a serial device and use it to transfer data.
 * The serial device must be an IO Device and must have a descriptor file in /dev.
 *
 * Objects of this class must have a separated QThread to work correctly.
 */
class SerialDevice
{

public:
    SerialDevice(string device);
    SerialDevice(string device, int speed, int parity);
    ~SerialDevice();

    bool init(int speed, int parity);

    int send(unsigned char *inBuffer, unsigned int length);
    int receive(unsigned char *outBuffer, unsigned int length);

    unsigned char *sendAndReceive(unsigned char *sendBuffer, unsigned int sendLength, unsigned int *receivedLength);

private:
    string        deviceName;

    int            device;
    struct termios tty;
    bool           working;

    int setInterfaceAttribs(int fd, int speed, int parity);
    int setBlocking(int fd, bool shouldBlock);
};

#endif // SERIALTHREAD_H
