#include "RFIDDevice.h"

/*!
 * \fn RFIDDevice::RFIDDevice
 *
 * Constructs the RFIDDevice based on a serialDevice and a configurazion file.
 *
 * \param device the serialDevice used to contact the reader.
 */
RFIDDevice::RFIDDevice(SerialDevice *device)
{
    serialDevice = device;
}

/*!
 * \fn RFIDDevice::~RFIDDevice
 *
 * Destructs the module.
 */
RFIDDevice::~RFIDDevice()
{}

/*!
 * \fn RFIDDevice::parseRFID
 *
 * The auxiliary method RFIDDevice::parseRFID is used to parse an RFID object, generating a string.
 *
 * \param rfid the RFID to be parsed.
 * \return the RFID code in string format.
 */
char *RFIDDevice::parseRFID(RFID rfid)
{
    char *str = new char[1024]();
    for (short i=0; i<rfid.length; i++){
        sprintf(str,"%s%02x:",str,rfid.rfid[i]);
    }
    str[strlen(str)-1] = '\0';
    return str;
}

/*!
 * \fn RFIDDevice::sendAndRecieve
 *
 * The method RFIDDevice::sendAndRecieve is used to send a message to the reader and waiting for the response.
 *
 * \param message the message with all the commands to send to the reader.
 * \return the message sent from the reader with the response.
 */
RFIDMessage *RFIDDevice::sendAndRecieve(RFIDMessage *message)
{
    unsigned char *send = message->getBuffer();
    unsigned int sendLength = message->getLength();
    unsigned int receivedLength;

    unsigned char *received = serialDevice->sendAndReceive(send, sendLength, &receivedLength);

    if (receivedLength < 10){
        return NULL;
    }
    return new RFIDMessage(received,receivedLength);
}

/*!
 * \fn RFIDDevice::getAntennaStatus
 *
 * The method RFIDDevice::getAntennaStatus requests the status of the \a source antenna.
 *
 * \param source name of the antenna.
 * \param len length of the name.
 * \param id message id.
 * \return a message with the status of the antenna.
 */
RFIDMessage *RFIDDevice::getAntennaStatus(unsigned char *source, unsigned short len, unsigned short id)
{
    RFIDMessage *msgCheckAntenna = new RFIDMessage(id);
    msgCheckAntenna->addCommand(RFIDAttributeTypes::COMMAND_NAME, RFIDCommandsCodes::CHECK_READ_POINT_STATUS);
    msgCheckAntenna->addCommand(RFIDAttributeTypes::READ_POINT_NAME, source, len);
    RFIDMessage *response = sendAndRecieve(msgCheckAntenna);
    delete(msgCheckAntenna);
    return response;
}

/*!
 * \fn RFIDDevice::getPower
 *
 * The method RFIDDevice::getPower returns the acqual power level (19-199) of the reader.
 *
 * \param id message id.
 * \return a message with the acqual value.
 */
RFIDMessage *RFIDDevice::getPower(unsigned short id)
{
    RFIDMessage *msgGetPower = new RFIDMessage(id);
    msgGetPower->addCommand(RFIDAttributeTypes::COMMAND_NAME, RFIDCommandsCodes::GET_POWER);
    RFIDMessage *response = sendAndRecieve(msgGetPower);
    delete(msgGetPower);
    return response;
}

/*!
 * \fn RFIDDevice::setPower
 *
 * The method RFIDDevice::setPower changes the power level of the reader to a new value between 19mW and 199mW.
 *
 * \param powerLevel the new value.
 * \param id message id.
 * \return a message with the success status.
 */
RFIDMessage *RFIDDevice::setPower(unsigned int powerLevel, unsigned short id)
{
    RFIDMessage *msgSetPower = new RFIDMessage(id);
    msgSetPower->addCommand(RFIDAttributeTypes::COMMAND_NAME, RFIDCommandsCodes::SET_POWER);
    msgSetPower->addCommand(RFIDAttributeTypes::POWER_SET, powerLevel);
    RFIDMessage *response = sendAndRecieve(msgSetPower);
    delete(msgSetPower);
    return response;
}

/*!
 * \fn RFIDDevice::setProtocol
 *
 * The method RFIDDevice::setProtocol changes the acqual communication protocol.
 *
 * \param protocol the new protocol.
 * \param id message id.
 * \return a message with the success status.
 */
RFIDMessage *RFIDDevice::setProtocol(unsigned int protocol, unsigned short id)
{
    RFIDMessage *msgSetProtocol = new RFIDMessage(id);
    msgSetProtocol->addCommand(RFIDAttributeTypes::COMMAND_NAME, RFIDCommandsCodes::SET_PROTOCOL);
    msgSetProtocol->addCommand(RFIDAttributeTypes::PROTOCOL, protocol);
    RFIDMessage *response = sendAndRecieve(msgSetProtocol);
    delete(msgSetProtocol);
    return response;
}

/*!
 * \fn RFIDDevice::getProtocol
 *
 * The method RFIDDevice::getProtocol returns the acquatl used protocl.
 *
 * \param id message id.
 * \return a message with the protocol name.
 */
RFIDMessage *RFIDDevice::getProtocol(unsigned short id)
{
    RFIDMessage *msgGetProtocol = new RFIDMessage(id);
    msgGetProtocol->addCommand(RFIDAttributeTypes::COMMAND_NAME, RFIDCommandsCodes::GET_PROTOCOL);
    RFIDMessage *response = sendAndRecieve(msgGetProtocol);
    delete(msgGetProtocol);
    return response;
}

/*!
 * \fn RFIDDevice::inventory
 *
 * The method RFIDDevice::inventory performs an inventory scan and returns all the found RFID ids.
 *
 * \param source antenna name to be used.
 * \param len length of \a source param.
 * \param id message id.
 * \return a message with all the founds RFID ids.
 */
RFIDMessage *RFIDDevice::inventory(unsigned char *source, unsigned short len, unsigned short id)
{
    RFIDMessage *msgInventory = new RFIDMessage(id);
    RFIDMessage *msgIn;
    msgInventory->addCommand(RFIDAttributeTypes::COMMAND_NAME, RFIDCommandsCodes::INVENTORY_TAG);
    msgInventory->addCommand(RFIDAttributeTypes::SOURCE_NAME, source, len);

    msgIn = sendAndRecieve(msgInventory);

    delete(msgInventory);

    return msgIn;
}
