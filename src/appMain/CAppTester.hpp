/**
 * \file CAppTester.hpp
 * \brief .
 * \author AKara
 */

#ifndef APPTESTER_H 
#define APPTESTER_H 

#include <stdint.h>
#include <string>
#include <vector>
#include <queue>

#include "Types.hpp"
#include "Blob.hpp"

/**
 * \namespace NsApplicationTester
 * \brief AppLink tester for high level.
 */ 
namespace NsApplicationTester
{
   /**
    * \class CBTAdapter
    * \brief Bluetooth adapter for AppLink
    */
   class CAppTester/*: public Bluetooth::IBluetoothAPI*/
   {
      public:
        /**
        * \brief Constructor.
        */
        CAppTester();

        /**
        * \brief Destructor.
        */
        ~CAppTester();

		    int startSession(int count);
		    int sendDataFromFile(const char * fileName);

        //void initBluetooth(Bluetooth::IBluetoothHandler * pHandler);
        void deinitBluetooth();

        const Blob getBuffer();
        void releaseBuffer(const Blob& blob);

        void sendBuffer(UInt8 * pBuffer, size_t size);

      private:
        void generateSingleMessage(UInt8 protocolVersion,
                                       UInt8 serviceType,
                                       UInt8 sessionID,
                                       std::string payload);
        //Bluetooth::IBluetoothHandler * mpProtocolHandler;

        std::queue<Blob> blobQueue;
   };
}/* namespace NsApplicationTester */
#endif /* APPTESTER_H */