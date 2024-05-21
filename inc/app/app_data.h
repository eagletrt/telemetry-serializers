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
struct DoubleTrigger
{
    std::string id;
    std::string message;
    std::string signal;
    int32_t comparator;
    double value;
    uint32_t color;
    
    DoubleTrigger() = default;
    DoubleTrigger(const PbApp::DoubleTrigger& protobuf);
    operator PbApp::DoubleTrigger() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct EnumTrigger
{
    std::string id;
    std::string message;
    std::string signal;
    int32_t comparator;
    uint64_t value;
    uint32_t color;
    
    EnumTrigger() = default;
    EnumTrigger(const PbApp::EnumTrigger& protobuf);
    operator PbApp::EnumTrigger() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct BitTrigger
{
    std::string id;
    std::string message;
    std::string signal;
    int32_t comparator;
    uint64_t value;
    uint32_t color;
    
    BitTrigger() = default;
    BitTrigger(const PbApp::BitTrigger& protobuf);
    operator PbApp::BitTrigger() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

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

struct CustomPlot
{
    std::string title;
    std::unordered_map<int32_t, CustomPlotAxis> axes;
    
    CustomPlot() = default;
    CustomPlot(const PbApp::CustomPlot& protobuf);
    operator PbApp::CustomPlot() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CustomSubPlots
{
    uint32_t rows;
    std::vector<CustomPlot> plots;
    
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
    std::vector<DoubleTrigger> doubleTriggers;
    std::vector<EnumTrigger> enumTriggers;
    std::vector<BitTrigger> bitTriggers;
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