#ifndef SERIALIZERS_FORWARDER_CONFIG_H
#define SERIALIZERS_FORWARDER_CONFIG_H

#include "forwarder_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Configs
{
struct NtripClient
{
    std::string casterHost;
    int32_t casterPort;
    std::string mountPoint;
    std::string username;
    std::string password;
    
    NtripClient() = default;
    NtripClient(const PbConfigs::NtripClient& protobuf);
    operator PbConfigs::NtripClient() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct GpsDev
{
    std::string address;
    std::string port;
    std::string mode;
    bool enabled;
    
    GpsDev() = default;
    GpsDev(const PbConfigs::GpsDev& protobuf);
    operator PbConfigs::GpsDev() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct ForwarderConfig
{
    GpsDev gpsDevice;
    NtripClient ntripClient;
    
    ForwarderConfig() = default;
    ForwarderConfig(const PbConfigs::ForwarderConfig& protobuf);
    operator PbConfigs::ForwarderConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif