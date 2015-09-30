/*
 * Project:     serial RFID Library for linux
 * File:        RFIDAttributeTypes.h
 * Author:      Claudio "Dna" Bonesana
 * Date:        september 2013
 * Version:     1.0
 *
 */
#ifndef RFIDDevice_H
#define RFIDDevice_H

#include "RFIDMessage.h"
#include "SerialDevice.h"

using namespace std;

/*!
 * \class RFIDDevice
 * \brief The RFIDDevice class is used to interact with RFID readers.
 *
 * The RFIDDevice class offers a group of methods to work with the RFID readers.
 * This class uses the RFIDMessage nad SerialModule classes to contact the reader and recieve response.
 *
 * This class offers only a limited amount of already implemented commands for the RFID readers.
 * Other commands can be implemented very quickly using the RFIDMessage construction methods.
 */
class RFIDDevice
{
public:
    RFIDDevice(SerialDevice *device);
    ~RFIDDevice();

    static char *parseRFID(RFID rfid);

    RFIDMessage *sendAndRecieve(RFIDMessage *message);

    RFIDMessage *getAntennaStatus(unsigned char *source, unsigned short len, unsigned short id=0x0000);
    RFIDMessage *getPower(unsigned short id=0x0000);
    RFIDMessage *setPower(unsigned int powerLevel, unsigned short id=0x0000);
    RFIDMessage *setProtocol(unsigned int protocol, unsigned short id=0x0000);
    RFIDMessage *getProtocol(unsigned short id=0x0000);
    RFIDMessage *inventory(unsigned char *source, unsigned short len, unsigned short id=0x0000);

private:
    SerialDevice *serialDevice;
};

#endif // RFIDDevice_H
