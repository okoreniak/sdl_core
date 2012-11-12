#ifndef BLUETOOTHWRITER_HPP
#define BLUETOOTHWRITER_HPP

#include "ProtocolPacketHeader.hpp"
#include "Logger.hpp"

namespace AxisCore
{

/**
 * \class BluetoothWriter
 * \brief Class for writing to CBTAdapter
 * \author amarkosov
 */
class BluetoothWriter
{
public:
    BluetoothWriter();

    ~BluetoothWriter();

    /**
      * Write data to CBTAdapter
      * @param header Message header
      * @param data Data array
      */
    ERROR_CODE write(const ProtocolPacketHeader &header, const UInt8 *data);

private:
    UInt8 *mData;
    static Logger mLogger;
};

} //namespace AxisCore

#endif // BLUETOOTHWRITER_HPP
