/*
 * Project:     serial RFID Library for linux
 * File:        RFIDAttributeTypes.h
 * Author:      Claudio "Dna" Bonesana
 * Date:        september 2013
 * Version:     1.0
 *
 */
#ifndef RFIDCOMMANDSCODES_H
#define RFIDCOMMANDSCODES_H

/*!
 * \class RFIDCommandsCodes
 * \brief The RFIDCommandsCodes class is an auxiliary class created to simplify the work of the programmer.
 *
 * \brief The RFIDCommandsCodes  class is an auxiliary class with all the AVP commands name that can be sent to the RFID reader.

 */
class RFIDCommandsCodes
{
public:
    static const unsigned short SUCCESS                           = 0x0000;
    static const unsigned short RAW_READ_IDS                      = 0x0012;
    static const unsigned short INVENTORY_TAG                     = 0x0013;
    static const unsigned short ADD_READ_TRIGGER                  = 0x003F;
    static const unsigned short ADD_NOTIFY_TRIGGER                = 0x0040;
    static const unsigned short REMOVE_READ_TRIGGER               = 0x0041;
    static const unsigned short REMOVE_NOTIFY_TRIGGER             = 0x0042;
    static const unsigned short ALLOCATE_TRIGGER                  = 0x0049;
    static const unsigned short DEALLOCATE_TRIGGER                = 0x004A;
    static const unsigned short ALLOCATE_CHANNEL                  = 0x0053;
    static const unsigned short DEALLOCATE_CHANNEL                = 0x0054;
    static const unsigned short ADD_SOURCE_TO_CHANNEL             = 0x005D;
    static const unsigned short REMOVE_SOURCE_FROM_CHANNEL        = 0x005E;
    static const unsigned short ADD_READ_POINT_TO_SOURCE          = 0x005F;
    static const unsigned short REMOVE_READ_POINT_FROM_SOURCE     = 0x0060;
    static const unsigned short SET_POWER                         = 0x0064;
    static const unsigned short READ_TAG_DATA                     = 0x006E;
    static const unsigned short WRITE_TAG_DATA                    = 0x006F;
    static const unsigned short LOCK_TAG                          = 0x0070;
    // static const unsigned short RESERVED                          = 0x0071;
    static const unsigned short SET_BIT_RATE                      = 0x0072;
    static const unsigned short GET_POWER                         = 0x0073;
    static const unsigned short SET_PROTOCOL                      = 0x0074;
    // static const unsigned short RESERVED                          = 0x0075;
    static const unsigned short CHECK_READ_POINT_STATUS           = 0x0076;
    static const unsigned short CHECK_SOURCE_IN_CHANNEL           = 0x0077;
    static const unsigned short CHECK_READ_POINT_IN_SOURCE        = 0x0078;
    static const unsigned short GET_PROTOCOL                      = 0x0079;
    static const unsigned short SET_NETWORK                       = 0x007A;
    static const unsigned short SET_DESB                          = 0x007B;
    static const unsigned short GET_FIRMWARE_RELEASE              = 0x007C;
    static const unsigned short GET_DESB                          = 0x007D;
    static const unsigned short PROGRAM_ID                        = 0x007E;
    static const unsigned short KILL_TAG                          = 0x007F;
    static const unsigned short RF_ON_OFF                         = 0x0080;
    static const unsigned short GET_BIT_RATE                      = 0x0081;
    static const unsigned short BLOCK_WRITE_TAG                   = 0x0082;
    static const unsigned short SET_RS232                         = 0x0083;
    static const unsigned short SET_DATE_TIME                     = 0x0084;
    static const unsigned short GROUP_SELECT_UNSELECT             = 0x0085;
    static const unsigned short GET_IO                            = 0x0086;
    static const unsigned short SET_IO                            = 0x0087;
    static const unsigned short SET_IO_DIRECTION                  = 0x0088;
    static const unsigned short GET_IO_DIRECTION                  = 0x0089;
    static const unsigned short SET_SOURCE_CONFIG                 = 0x008A;
    static const unsigned short GET_SOURCE_CONFIG                 = 0x008B;
    static const unsigned short GET_TRIGGERS                      = 0x008C;
    static const unsigned short GET_CHANNELS                      = 0x008D;
    static const unsigned short CHECK_SOURCE_IN_TRIGGER           = 0x008E;
    static const unsigned short CHECK_TRIGGER_IN_CHANNEL          = 0x008F;
    static const unsigned short CHECK_CHANNEL_IN_TRIGGER          = 0x0090;
    static const unsigned short SET_EVENT_MODE                    = 0x0091;
    static const unsigned short GET_EVENT_MODE                    = 0x0092;
    static const unsigned short FIRMWARE_UPGRADE                  = 0x0093;
    static const unsigned short E119_PROGRAM_ID                   = 0x0094;
    static const unsigned short PROGRAM_ID_EPC_C1G2               = 0x0095;
    static const unsigned short READ_TAG_DATA_EPC_C1G2            = 0x0096;
    static const unsigned short WRITE_TAG_DATA_EPC_C1G2           = 0x0097;
    static const unsigned short LOCK_TAG_EPC_C1G2                 = 0x0098;
    static const unsigned short KILL_TAG_EPC_C1G2                 = 0x0099;
    static const unsigned short QUERY_EPC_C1G2                    = 0x009A;
    static const unsigned short SET_Q_EPC_C1G2                    = 0x009B;
    static const unsigned short GET_Q_EPC_C1G2                    = 0x009C;
    static const unsigned short QUERY_ACK_EPC_C1G2                = 0x009D;
    static const unsigned short GET_READER_INFO                   = 0x009E;
    static const unsigned short SET_LBT_MODE                      = 0x009F;
    static const unsigned short GET_LBT_MODE                      = 0x00A0;
    static const unsigned short GET_RF_REGULATION                 = 0x00A2;
    static const unsigned short SET_RF_CHANNEL                    = 0x00A3;
    static const unsigned short GET_RF_CHANNEL                    = 0x00A4;
    // static const unsigned short GET_CHANNEL_DATA                  = 0x00A7; // OBSOLETE
    static const unsigned short GET_BUFFERED_DATA                 = 0x00B0;
    static const unsigned short LOCK_BLOCK_PERMA_LOCK_EPC_C1G2    = 0x00B1;
    static const unsigned short READ_BLOCK_PERMA_LOCK_EPC_C1G2    = 0x00B2;
    // static const unsigned short RESERVED                          = 0xFFFF;
};

#endif // RFIDCOMMANDSCODES_H
