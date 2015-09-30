/*
 * Project:     serial RFID Library for linux
 * File:        RFIDAttributeTypes.h
 * Author:      Claudio "Dna" Bonesana
 * Date:        september 2013
 * Version:     1.0
 *
 */
#ifndef RFIDATTRIBUTETYPES_H
#define RFIDATTRIBUTETYPES_H

/*!
 * \class RFIDAttributeTypes
 * \brief The RFIDAttributeTypes class is an auxiliary class created to simplify the work of the programmer.
 *
 * \brief The RFIDAttributeTypes class is an auxiliary class with all the AVP attributes that can be sent to the RFID reader.
 */
class RFIDAttributeTypes
{
public:
    static const unsigned short COMMAND_NAME      = 0x0001;
    static const unsigned short RESULT_CODE       = 0x0002;
    static const unsigned short EVENT_TYPE        = 0x000E;
    static const unsigned short TAG_ID_LEN        = 0x000F;
    static const unsigned short TIME_STAMP        = 0x0010;
    static const unsigned short TAG_ID            = 0x0011;
    static const unsigned short TAG_TYPE          = 0x0012;
    static const unsigned short CHANNEL_NAME      = 0x001E;
    static const unsigned short CHANNEL_ADDRESS   = 0x001F;
    static const unsigned short TRIGGER_NAME      = 0x0020;
    static const unsigned short TRIGGER_TYPE      = 0x0021;
    static const unsigned short READ_POINT_NAME   = 0x0022;
    static const unsigned short TAG_VALUE         = 0x004D;
    static const unsigned short TAG_ADDRESS       = 0x004E;
    // static const unsigned short RESERVED          = 0x004F;
    static const unsigned short LENGTH            = 0x0050;
    static const unsigned short BIT_RATE          = 0x0051;
    static const unsigned short POWER_GET         = 0x0052;
    // static const unsigned short RESERVED          = 0x0053;
    static const unsigned short PROTOCOL          = 0x0054;
    static const unsigned short READ_POINT_STATUS = 0x0056;
    static const unsigned short BOOLEAN           = 0x0057;
    static const unsigned short IP_ADDRESS        = 0x0058;
    static const unsigned short IP_NETMASK         = 0x0059;
    static const unsigned short IP_GATEWAY        = 0x005A;
    static const unsigned short DESB_ENABLE       = 0x005B;
    static const unsigned short FW_RELEASE        = 0x005C;
    static const unsigned short DESB_STATUS       = 0x005D;
    static const unsigned short EPCPWD            = 0x005E;
    static const unsigned short RF_ON_OFF         = 0x005F;
    static const unsigned short BAUD_RATE         = 0x0060;
    static const unsigned short DATA_BITS         = 0x0061;
    static const unsigned short STOP_BITS         = 0x0062;
    static const unsigned short PARITY            = 0x0063;
    static const unsigned short FLOW_CTRL         = 0x0064;
    static const unsigned short DATE_TIME         = 0x0065;
    static const unsigned short SEL_UNSE_OP       = 0x0066;
    static const unsigned short BITMASK           = 0x0067;
    //static const unsigned short RESERVED          = 0x0068;
    static const unsigned short IO_REGISTER       = 0x0069;
    static const unsigned short CONFIG_PARAMETER  = 0x006A;
    static const unsigned short CONFIG_VALUE      = 0x006B;
    static const unsigned short NO_OF_TRIGGERS    = 0x006C;
    static const unsigned short NO_OF_CHANNELS    = 0x006D;
    static const unsigned short EVENT_MODE        = 0x006E;
    static const unsigned short UPGRADE_TYPE      = 0x006F;
    static const unsigned short UPGRADE_ARGUMENT  = 0x0070;
    static const unsigned short MEMORY_BANK       = 0x0071;
    static const unsigned short PAYLOAD           = 0x0072;
    static const unsigned short G2_PASSWORD       = 0x0073;
    static const unsigned short G2_nsi            = 0x0074;
    static const unsigned short Q_PARAMETER       = 0x0075;
    static const unsigned short READER_INFO       = 0x0076;
    static const unsigned short RF_CHANNEL        = 0x0078;
    static const unsigned short RSSI              = 0x007A;
    static const unsigned short AVP_OPTION        = 0x007B;
    static const unsigned short AVP_XPC           = 0x007C;
    static const unsigned short AVP_PC            = 0x007D;
    static const unsigned short POWER_SET         = 0x0096;
    static const unsigned short SOURCE_NAME       = 0x00FB;
};

#endif // RFIDATTRIBUTETYPES_H
