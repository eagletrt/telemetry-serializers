#ifndef APP_CONFIG_H
#define APP_CONFIG_H

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

struct Color
{
    double r;
    double g;
    double b;
    double a;
    
    Color() = default;
    Color(const PbApp::Color& protobuf);
    operator PbApp::Color() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Event
{
    std::string message;
    std::string field;
    int64_t comparator;
    double value;
    Color color;
    
    Event() = default;
    Event(const PbApp::Event& protobuf);
    operator PbApp::Event() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Field
{
    std::string message;
    std::string field;
    
    Field() = default;
    Field(const PbApp::Field& protobuf);
    operator PbApp::Field() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Axis
{
    std::string name;
    std::vector<Field> fields;
    
    Axis() = default;
    Axis(const PbApp::Axis& protobuf);
    operator PbApp::Axis() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CustomPlot
{
    std::string name;
    std::vector<Axis> axes;
    
    CustomPlot() = default;
    CustomPlot(const PbApp::CustomPlot& protobuf);
    operator PbApp::CustomPlot() const;

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
    bool csvAutoSave;
    Connection connection;
    std::unordered_map<std::string, Connection> savedConnections;
    std::vector<std::string> activeTabs;
    std::vector<Event> events;
    std::vector<CustomPlot> customPlots;
    std::unordered_map<std::string, std::string> filesPaths;
    std::unordered_map<std::string, std::string> cacheMap;
    
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