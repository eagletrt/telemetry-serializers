#ifndef SESSION_CONFIG_H
#define SESSION_CONFIG_H

#include "session_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef Configs::Weather ConfigsWeather;
typedef Configs::SessionConfig ConfigsSessionConfig;

namespace Serializers
{
namespace Configs
{
struct Weather
{
    double temperature;
    double humidity;
    
    Weather() = default;
    Weather(const ConfigsWeather& proto);
    operator ConfigsWeather() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionConfig
{
    std::string circuit;
    std::string driver;
    std::string race;
    std::string test;
    std::string date;
    std::string time;
    Weather weather;
    std::string notes;
    double canlibVersion;
    
    SessionConfig() = default;
    SessionConfig(const ConfigsSessionConfig& proto);
    operator ConfigsSessionConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif