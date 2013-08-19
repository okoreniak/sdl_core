/**
 * \file DeviceAdapterImpl.hpp
 * \brief DeviceAdapterImpl class header.
 * Copyright (c) 2013, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_DEVICE_ADAPTER_IMPL_H_
#define SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_DEVICE_ADAPTER_IMPL_H_

#include <queue>
#include <set>
#include <memory>
#include <string>

#include "utils/logger.h"

#include "transport_manager/device_adapter/device_adapter.h"
#include "transport_manager/device_adapter/device_adapter_controller.h"
#include "transport_manager/device_adapter/connection.h"

namespace transport_manager {
namespace device_adapter {

class DeviceAdapterListener;
class DeviceScanner;
class ServerConnectionFactory;
class ClientConnectionListener;

/*
 * @brief Base class for @link components_transportmanager_internal_design_device_adapters device adapters @endlink.
 **/
class DeviceAdapterImpl : public DeviceAdapter, public DeviceAdapterController {
 protected:
  /**
   * @brief Constructor.
   *
   **/
  DeviceAdapterImpl(DeviceScanner* device_scanner,
                    ServerConnectionFactory* server_connection_factory,
                    ClientConnectionListener* client_connection_listener);

  /**
   * @brief Destructor.
   **/
  virtual ~DeviceAdapterImpl();

  virtual bool isInitialised() const;

 public:
  /**
   * @brief Run device adapter.
   *
   * Called from transport manager to start device adapter.
   **/
  virtual DeviceAdapter::Error init();

  virtual void addListener(DeviceAdapterListener *listener);

  virtual void removeListener(DeviceAdapterListener *listener);

  /**
   * @brief Start scanning for new devices.
   *
   * List of new devices will be supplied in onDeviceListUpdated callback.
   *
   * @see @ref components_transportmanager_internal_design_device_adapters_common_device_scan
   **/
  virtual DeviceAdapter::Error searchDevices();

  /**
   * @brief Connect to the specified application discovered on device.
   *
   * @param device_handle Handle of device to connect to.
   * @param app_handle Handle of application to connect to.
   *
   * @see @ref components_transportmanager_internal_design_device_adapters_common_connecting_devices
   **/
  virtual DeviceAdapter::Error connect(const DeviceUID& device_handle,
                                       const ApplicationHandle& app_handle);

  /**
   * @brief Disconnect from specified session.
   *
   * @param session_id Session identifier to disconnect.
   *
   * @see @ref components_transportmanager_internal_design_device_adapters_common_disconnecting_devices
   **/
  virtual DeviceAdapter::Error disconnect(const DeviceUID& device_handle,
                                          const ApplicationHandle& app_handle);

  /**
   * @brief Disconnect from all sessions on specified device.
   *
   * @param device_handle Device handle to disconnect.
   *
   * @see @ref components_transportmanager_internal_design_device_adapters_common_disconnecting_devices
   **/
  virtual DeviceAdapter::Error disconnectDevice(const DeviceUID& device_handle);

  /**
   * @brief Send frame.
   *
   * @param ConnectionHandle Connection handle.
   * @param Data Frame payload data.
   * @param DataSize Size of data in bytes.
   * @param UserData Any user data.
   *
   * @see @ref components_transportmanager_internal_design_device_adapters_common_handling_communication
   **/
  virtual DeviceAdapter::Error sendData(const DeviceUID& device_handle,
                                        const ApplicationHandle& app_handle,
                                        const RawMessageSptr data);

  virtual DeviceAdapter::Error startClientListening();
  virtual DeviceAdapter::Error stopClientListening();

  virtual bool isSearchDevicesSupported() const;
  virtual bool isServerOriginatedConnectSupported() const;
  virtual bool isClientOriginatedConnectSupported() const;

  virtual DeviceList getDeviceList() const;
  virtual ApplicationList getApplicationList(
      const DeviceUID& device_handle) const;
  virtual DeviceSptr findDevice(const DeviceUID& device_handle) const;

  virtual void searchDeviceDone(const DeviceVector& devices);
  virtual void searchDeviceFailed(const SearchDeviceError& error);
  virtual DeviceSptr addDevice(DeviceSptr device);

  virtual void connectionCreated(ConnectionSptr connection,
                                 const DeviceUID& device_handle,
                                 const ApplicationHandle& app_handle);
  virtual void connectionFinished(const DeviceUID& device_handle,
                                  const ApplicationHandle& app_handle);
  virtual void connectionAborted(const DeviceUID& device_handle,
                                 const ApplicationHandle& app_handle,
                                 const CommunicationError& error);
  virtual void connectDone(const DeviceUID& device_handle,
                           const ApplicationHandle& app_handle);
  virtual void connectFailed(const DeviceUID& device_handle,
                             const ApplicationHandle& app_handle,
                             const ConnectError& error);
  virtual void disconnectDone(const DeviceUID& device_handle,
                              const ApplicationHandle& app_handle);
  virtual void dataReceiveDone(const DeviceUID& device_handle,
                               const ApplicationHandle& app_handle,
                               RawMessageSptr message);
  virtual void dataReceiveFailed(const DeviceUID& device_handle,
                                 const ApplicationHandle& app_handle,
                                 const DataReceiveError&);
  virtual void dataSendDone(const DeviceUID& device_handle,
                            const ApplicationHandle& app_handle,
                            RawMessageSptr message);
  virtual void dataSendFailed(const DeviceUID& device_handle,
                              const ApplicationHandle& app_handle,
                              RawMessageSptr message, const DataSendError&);

  virtual std::string DeviceName(const DeviceUID &device_id) const;

 private:

  ConnectionSptr findEstablishedConnection(const DeviceUID& device_handle,
                                           const ApplicationHandle& app_handle);

  /**
   * @brief Listener for device adapter notifications.
   **/
  DeviceAdapterListenerList listeners_;

  bool initialised_;

  /**
   * @brief Devices map.
   **/
  typedef std::map<DeviceUID, DeviceSptr> DeviceMap;

  struct ConnectionInfo {
    ConnectionSptr connection;
    DeviceUID device_id;
    ApplicationHandle app_handle;
    enum {
      NEW,
      ESTABLISHED,
      FINALISING
    } state;
  };

  typedef std::map<std::pair<DeviceUID, ApplicationHandle>, ConnectionInfo> ConnectionMap;

  /**
   * @brief Map of device handle to device.
   *
   * This map contains all currently available bluetooth devices.
   *
   * @see @ref components_transportmanager_internal_design_device_adapters_common_devices_map
   **/
  DeviceMap devices_;

  /**
   * @brief Mutex restricting access to device map.
   *
   * @see @ref components_transportmanager_internal_design_device_adapters_common_devices_map
   **/
  mutable pthread_mutex_t devices_mutex_;

  /**
   * @brief Map of connections.
   *
   * @see @ref components_transportmanager_internal_design_device_adapters_common_connections_map
   **/
  ConnectionMap connections_;

  /**
   * @brief Mutex restricting access to connections map.
   *
   * @see @ref components_transportmanager_internal_design_device_adapters_common_connections_map
   **/
  mutable pthread_mutex_t connections_mutex_;

 protected:
  DeviceScanner* device_scanner_;
  ServerConnectionFactory* server_connection_factory_;
  ClientConnectionListener* client_connection_listener_;
};

extern log4cxx::LoggerPtr logger_;

}  // namespace device_adapter
}  // namespace transport_manager

#endif // #ifndef SRC_COMPONENTS_TRANSPORT_MANAGER_INCLUDE_TRANSPORT_MANAGER_DEVICE_ADAPTER_IMPL_H_