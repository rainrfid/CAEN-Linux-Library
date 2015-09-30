#include "SerialDevice.h"

/*!
 * \fn SerialDevice::SerialDevice
 *
 * Constructs a SerialDevice based on a \a config file and a serial \a device.
 * Object created with this constructor must be initialized with the method SerialDevice::init.
 *
 * \param config path to the configuration file.
 * \param device path to the system serial device as a file.
 * \param parent
 */
SerialDevice::SerialDevice(string device)
{
    deviceName = device;
    working = true;
}

/*!
 * \fn SerialDevice::SerialDevice
 *
 * Constructs and initialiaze a SerialDevice based on a \a configuration file, a serial \a device, \a speed and \a parity parameters.
 *
 * \param config path to the configurazion file.
 * \param device path to the system serial device as a file.
 * \param speed speed of the communication (for RFID 115200).
 * \param parity parity value (for RFID 0).
 * \param parent
 */
SerialDevice::SerialDevice(string device, int speed, int parity)
{
    deviceName = device;
    working = true;

    init(speed, parity);
}

/*!
 * \fn SerialDevice::~SerialDevice
 *
 * Destructs the module.
 *
 */
SerialDevice::~SerialDevice()
{
    if (close(device) < 0) {
        cerr << "Error " << errno << " closing " << deviceName << ": " << strerror(errno) << "." << endl;
    }
}

/*!
 * \fn SerialDevice::init
 *
 * The method SerialDevice::init initialize a SerialDevice object.
 *
 * \param speed speed of the communication (for RFID 115200).
 * \param parity parity value (for RFID 0).
 * \return true if everything is ok, otherwise false.
 */
bool SerialDevice::init(int speed, int parity)
{
    device = open(deviceName.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (device < 0) {
        cerr << "Error " << errno << " opening " <<  deviceName << ": " << strerror(errno) << ".";
        return false;
    }
    this->setInterfaceAttribs(device, speed, parity);
    return true;
}

/*!
 * \fn SerialDevice::send
 *
 * The method SerialDevice::send sends data do the serial device.
 *
 * \param inBuffer input buffer.
 * \param length length of the input buffer.
 * \return 0 no error, otherwise -1.
 */
int SerialDevice::send(unsigned char *inBuffer, unsigned int length)
{
    return write(device, inBuffer, length);
}

/*!
 * \fn SerialDevice::receive
 *
 * The method SerialDevice::receive is used to read the input from the serial device.
 *
 * \param outBuffer output buffer.
 * \param length length of the input
 * \return the number read, -1 for errors or 0 for EOF.
 */
int SerialDevice::receive(unsigned char *outBuffer, unsigned int length)
{
    return read(device, outBuffer, length);
}

/*!
 * \fn SerialDevice::sendAndReceive
 *
 * The method SerialDevice::sendAndReceive is a combination of SerialDevice::send and SerialDevice::receive
 *
 * \param sendBuffer input buffer.
 * \param sendLength input buffer length.
 * \param receivedLength the length of the read data.
 * \return the recieved data.
 */
unsigned char *SerialDevice::sendAndReceive(unsigned char *sendBuffer, unsigned int sendLength, unsigned int *receivedLength)
{

    int status = 0;
    status = send(sendBuffer,sendLength);

    unsigned char *receivedBuffer = new unsigned char[MAX_BUFFER];
    unsigned int pointer = 0;

    do {
        status = receive(&receivedBuffer[pointer], sizeof(unsigned char));
        if (status == 1) {
            pointer++;
        }
    } while (status == 1);

    *receivedLength = pointer;

    return receivedBuffer;
}

int SerialDevice::setInterfaceAttribs(int fd, int speed, int parity)
{
    memset (&tty, 0, sizeof(tty));
    if (tcgetattr(fd, &tty) != 0) {
        printf("Error %s from tcgetattr: %s.\n", errno, strerror(errno));
        return -1;
    }

    cfsetospeed(&tty, speed);
    cfsetispeed(&tty, speed);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit characters

    tty.c_iflag &= ~IGNBRK;     // ignore break signal
    tty.c_lflag = 0;            // no signaling char, no echo, no canonical processing
    tty.c_oflag = 0;            // no remapping, no delays
    tty.c_cc[VMIN]  = 0;        // read doesn't block
    tty.c_cc[VTIME] = 5;        // 0.5 seconds read timeout

    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= parity;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr (fd, TCSANOW, &tty) != 0) {
        printf("Error %d from tcsetattr: %s.\n", errno, strerror(errno));
        return -1;
    }

    return 0;
}

int SerialDevice::setBlocking(int fd, bool shouldBlock)
{
    struct termios tty;
    memset (&tty, 0, sizeof tty);
    if (tcgetattr (fd, &tty) != 0) {
        printf("Error %d from tcgetattr: %s.\n", errno, strerror(errno));

        return -1;
    }

    tty.c_cc[VMIN]  = shouldBlock ? 1 : 0;
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

    if (tcsetattr (fd, TCSANOW, &tty) != 0) {
        printf("Error %d from tcsetattr\: %sn", errno, strerror(errno));

        return -1;
    }
    return 0;
}
