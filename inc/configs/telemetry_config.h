#ifndef TELEMETRY_CONFIG_H
#define TELEMETRY_CONFIG_H

#include "telemetry_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef Configs::CanDevice ConfigsCanDevice;
typedef Configs::GpsDevice ConfigsGpsDevice;
typedef Configs::Connection ConfigsConnection;
typedef Configs::ConnectionConfig ConfigsConnectionConfig;
typedef Configs::TelemetryConfig ConfigsTelemetryConfig;

namespace Serializers
{
namespace Configs
{
struct CanDevice
{
    std::string socket;
    std::string name;
    std::vector<std::string> networks;
    
    CanDevice() = default;
    CanDevice(const ConfigsCanDevice& proto);
    operator ConfigsCanDevice() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct GpsDevice
{
    std::string address;
    std::string mode;
    bool enabled;
    
    GpsDevice() = default;
    GpsDevice(const ConfigsGpsDevice& proto);
    operator ConfigsGpsDevice() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Connection
{
    std::string ip;
    std::string port;
    std::string mode;
    std::string whoamiUrl;
    bool tlsEnabled;
    std::string cafile;
    std::string capath;
    std::string certfile;
    std::string keyfile;
    
    Connection() = default;
    Connection(const ConfigsConnection& proto);
    operator ConfigsConnection() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct ConnectionConfig
{
    bool enabled;
    bool downsampleEnabled;
    bool downsampleSkipData;
    int64_t downsampleMps;
    int64_t sendRate;
    bool sendSensorData;
    
    ConnectionConfig() = default;
    ConnectionConfig(const ConfigsConnectionConfig& proto);
    operator ConfigsConnectionConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct TelemetryConfig
{
    std::string vehicleId;
    std::string deviceId;
    uint64_t role;
    bool cameraEnabled;
    bool generateCsv;
    Connection connection;
    ConnectionConfig connectionConfig;
    std::vector<CanDevice> canDevies;
    std::vector<GpsDevice> gpsDevices;
    
    TelemetryConfig() = default;
    TelemetryConfig(const ConfigsTelemetryConfig& proto);
    operator ConfigsTelemetryConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif