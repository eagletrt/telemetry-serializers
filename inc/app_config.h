#ifndef APP_CONFIG_H
#define APP_CONFIG_H

#include "app_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
struct Connection
{
    uint32_t ip;
    uint32_t port;
    std::string mode;
    
    Connection() = default;
    Connection(const app_config::Connection& proto);
    operator app_config::Connection() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Config
{
    uint32_t config;
    std::string name;
    Connection connection;
    
    Config() = default;
    Config(const app_config::Config& proto);
    operator app_config::Config() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}

#endif