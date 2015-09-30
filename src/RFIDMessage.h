/*
 * Project:     serial RFID Library for linux
 * File:        RFIDAttributeTypes.h
 * Author:      Claudio "Dna" Bonesana
 * Date:        september 2013
 * Version:     1.0
 *
 */
#ifndef RFIDMESSAGE_H
#define RFIDMESSAGE_H

#include "RFIDattributeTypes.h"
#include "RFIDCommandsCodes.h"

#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>

#define HEAD_START 0
#define MESSAGE_ID 2
#define VENDOR_ID 4
#define MSG_LENGTH 8

using namespace std;

/*!
 * \struct MessageRFIDBody
 *
 * The struct MessageRFIDBody represents a single frame of the easy2read commands list.
 */
typedef struct MessageRFIDBody {
    unsigned short reserved;        // 2 bytes
    unsigned short length;          // 2 bytes
    unsigned short attributeType;   // 2 bytes
    unsigned char *attributeValue;  // * bytes

} MessageRFIDBody;

/*!
 * \struct RFID
 *
 * The struct RFID represents a single RFID code.
 */
typedef struct RFID {
    unsigned char *rfid;
    unsigned short length;
} RFID;


/*!
 * \class RFIDMessage
 * \brief The RFIDMessage class is a container for the RFID messages.
 *
 * The RFIDMessage class is used to store the information for and from the RFID reader.
 * This class is based on the Attribute-Value Pair structure used by the protocol easy2read.
 * Every message is composed by an header followed by a list of frames, used to describe commands, values and operations.
 *
 * Every object of this type is a message sent to the reader or recieved from it.
 *
 * This class offers methods to build a complete message, but offers only methods to test if the response is a success response and to recovery the RFID code.
 * Others operations must be implemented.
 */
class RFIDMessage
{
public:
    RFIDMessage(unsigned short id);
    RFIDMessage(unsigned char *buffer, unsigned int messageLength);
    virtual ~RFIDMessage();

    int addCommand(unsigned short type, unsigned short value);
    int addCommand(unsigned short type, unsigned int value);
    int addCommand(unsigned short type, unsigned long value, unsigned short len);
    int addCommand(unsigned short type, unsigned char *value, unsigned short len);

    unsigned char *getBuffer();
    unsigned short getLength();

    vector<RFID> *getRFIDs();
    bool success();

    void print();

private:
    /* header */
    unsigned short version;     // 2 bytes
    unsigned short messageId;   // 2 bytes
    unsigned int   vendor;      // 4 bytes
    unsigned short length;      // 2 bytes

    std::vector<MessageRFIDBody> body;

    void shortToBuffer(unsigned short s, unsigned char *converted);
    void intToBuffer(unsigned int i, unsigned char *converted);
    void longToBuffer(unsigned long l, unsigned char *converted, unsigned short len);

    unsigned short bufferToShort(unsigned char *buffer);
    unsigned int bufferToInt(unsigned char *buffer);
};

#endif // RFIDMESSAGE_H
