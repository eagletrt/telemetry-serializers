#ifndef SERIALIZERS_APP_DATA_H
#define SERIALIZERS_APP_DATA_H

#include "app_data.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace App
{
struct CustomPlotItem
{
    std::string messageAxisX;
    std::string messageAxisY;
    std::string signalAxisX;
    std::string signalAxisY;
    bool isEnum;
    uint32_t color;
    
    CustomPlotItem() = default;
    CustomPlotItem(const PbApp::CustomPlotItem& protobuf);
    operator PbApp::CustomPlotItem() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CustomPlotAxis
{
    std::string label;
    std::vector<CustomPlotItem> items;
    
    CustomPlotAxis() = default;
    CustomPlotAxis(const PbApp::CustomPlotAxis& protobuf);
    operator PbApp::CustomPlotAxis() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct NewCustomPlot
{
    std::string title;
    std::unordered_map<int32_t, CustomPlotAxis> axes;
    
    NewCustomPlot() = default;
    NewCustomPlot(const PbApp::NewCustomPlot& protobuf);
    operator PbApp::NewCustomPlot() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CustomSubPlots
{
    uint32_t rows;
    std::vector<NewCustomPlot> plots;
    
    CustomSubPlots() = default;
    CustomSubPlots(const PbApp::CustomSubPlots& protobuf);
    operator PbApp::CustomSubPlots() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CustomPlotsTab
{
    std::vector<CustomSubPlots> subPlots;
    
    CustomPlotsTab() = default;
    CustomPlotsTab(const PbApp::CustomPlotsTab& protobuf);
    operator PbApp::CustomPlotsTab() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct AppData
{
    std::unordered_map<std::string, CustomPlotsTab> customPlotsTabs;
    
    AppData() = default;
    AppData(const PbApp::AppData& protobuf);
    operator PbApp::AppData() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif