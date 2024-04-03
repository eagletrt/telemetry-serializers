#ifndef SERIALIZERS_CONFIGURATION_H
#define SERIALIZERS_CONFIGURATION_H

#include "configuration.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace InfluxLogger
{
struct Configuration
{
    std::string mqtt_host;
    uint32_t mqtt_port;
    std::string vehicle_id;
    std::string device_id;
    std::string influx_host;
    uint32_t influx_port;
    bool influx_https;
    std::string influx_bucket;
    std::string influx_orgid;
    std::string influx_token;
    std::vector<std::string> networks;
    std::string proxy_host;
    uint32_t proxy_port;
    
    Configuration() = default;
    Configuration(const PbInfluxLogger::Configuration& protobuf);
    operator PbInfluxLogger::Configuration() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif