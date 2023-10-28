#ifndef APP_CONFIG_H
#define APP_CONFIG_H

#include "app_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef App::Device AppDevice;
typedef App::Connection AppConnection;
typedef App::PostProc AppPostProc;
typedef App::Color AppColor;
typedef App::Event AppEvent;
typedef App::Field AppField;
typedef App::Axis AppAxis;
typedef App::CustomPlot AppCustomPlot;
typedef App::AppConfig AppAppConfig;

namespace Serializers
{
namespace App
{
struct Device
{
    std::string vehicleId;
    std::string deviceId;
    
    Device() = default;
    Device(const AppDevice& proto);
    operator AppDevice() const;

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
    
    Connection() = default;
    Connection(const AppConnection& proto);
    operator AppConnection() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct PostProc
{
    int64_t sampleFrequency;
    std::vector<std::string> includedItems;
    std::vector<std::string> exceludedItems;
    
    PostProc() = default;
    PostProc(const AppPostProc& proto);
    operator AppPostProc() const;

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
    Color(const AppColor& proto);
    operator AppColor() const;

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
    Event(const AppEvent& proto);
    operator AppEvent() const;

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
    Field(const AppField& proto);
    operator AppField() const;

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
    Axis(const AppAxis& proto);
    operator AppAxis() const;

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
    CustomPlot(const AppCustomPlot& proto);
    operator AppCustomPlot() const;

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
    PostProc postProc;
    Connection connection;
    std::vector<Connection> savedConnections;
    std::vector<Device> devices;
    std::vector<Event> events;
    std::vector<CustomPlot> customPlots;
    std::unordered_map<std::string, std::string> filesPaths;
    
    AppConfig() = default;
    AppConfig(const AppAppConfig& proto);
    operator AppAppConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif