#include <cstdio>

#include "SerialDevice.h"
#include "RFIDDevice.h"
#include "RFIDMessage.h"

using namespace std;

int main()
{
    SerialDevice *serial = new SerialDevice("/dev/USB0", B115200, 0);
    RFIDDevice *rfid = new RFIDDevice(serial);
    RFIDMessage *msgIn;

    unsigned char Source_0[9] = {0x53, 0x6F, 0x75, 0x72, 0x63, 0x65, 0x5F, 0x30, 0x00};
    unsigned int protocol     = 0x00000003;

    unsigned int powerInitial = 199;
    unsigned int powerMiddle  = 80;
    unsigned int powerTesting = 19;

    double gain = 8.0;
    double loss = 1.5;
    double ERPPower = 2000.0;

    // Set Protocol
    msgIn = rfid->setProtocol(protocol);
    msgIn->print();
    printf("SET POWER COMPLETE\n");
    getc(stdin);

    // Get Power
    printf("Get Power\n");
    msgIn = rfid->getPower();
    msgIn->print();
    printf("GET POWER COMPLETE\n");
    getc(stdin);

    // Set Power
    msgIn = rfid->setPower(powerMiddle);
    msgIn->print();
    printf("SET POWER COMPLETE\n");
    getc(stdin);

    // Get Power
    msgIn = rfid->getPower();
    msgIn->print();
    printf("GET POWER COMPLETE\n");
    getc(stdin);

    // antenna status
    msgIn = rfid->getAntennaStatus(Source_0, 9);
    msgIn->print();
    printf("GET ANTENNA STATUS COMPLETE\n");
    getc(stdin);

    printf("START INVENTORY\n");

    // Inventory
    printf("\n");

    for(;;) {
        msgIn = rfid->inventory(Source_0,9);

        int k=0;

        vector<RFID> *founds = msgIn->getRFIDs();

        for(vector<RFID>::iterator it = founds->begin(); it != founds->end(); ++it){
            printf("%s \n", RFIDDevice::parseRFID(*it));
            k++;
        }
        printf("\n");
        sleep(1);
    }

    printf("\n");

    return 0;
}

