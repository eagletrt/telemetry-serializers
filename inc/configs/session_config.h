#ifndef SESSION_CONFIG_H
#define SESSION_CONFIG_H

#include "session_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Configs
{
struct Weather
{
    double temperature;
    double humidity;
    
    Weather() = default;
    Weather(const PbConfigs::Weather& protobuf);
    operator PbConfigs::Weather() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionConfig
{
    std::string circuitId;
    std::string raceId;
    std::string test;
    std::string driverId;
    std::string date;
    std::string time;
    Weather weather;
    std::string notes;
    double canlibVersion;
    
    SessionConfig() = default;
    SessionConfig(const PbConfigs::SessionConfig& protobuf);
    operator PbConfigs::SessionConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif