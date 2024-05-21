#ifndef SERIALIZERS_APP_CONFIG_H
#define SERIALIZERS_APP_CONFIG_H

#include "app_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace App
{
struct Connection
{
    std::string ip;
    std::string port;
    std::string mode;
    
    Connection() = default;
    Connection(const PbApp::Connection& protobuf);
    operator PbApp::Connection() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct AppConfig
{
    uint64_t loginTimestamp;
    uint32_t colorTheme;
    uint32_t mode;
    Connection connection;
    std::unordered_map<std::string, Connection> savedConnections;
    std::vector<std::string> activeTabs;
    std::unordered_map<std::string, std::string> filesPaths;
    std::unordered_map<std::string, std::string> stringCache;
    std::unordered_map<std::string, bool> boolCache;
    
    AppConfig() = default;
    AppConfig(const PbApp::AppConfig& protobuf);
    operator PbApp::AppConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif