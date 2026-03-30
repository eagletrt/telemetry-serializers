#ifndef SERIALIZERS_CUSTOM_PRESET_H
#define SERIALIZERS_CUSTOM_PRESET_H

#include "custom_preset.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace App
{
enum class PlotType
{
    UNKNOWN = 0,
    LINE = 1,
    SCATTER = 2
};

struct Size
{
    double w;
    double h;
    
    Size() = default;
    Size(const PbApp::Size& protobuf);
    operator PbApp::Size() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct GraphElement
{
    std::string label;
    PlotType type;
    std::string xField;
    std::string yField;
    uint32_t color;
    int32_t axisX;
    int32_t axisY;
    
    GraphElement() = default;
    GraphElement(const PbApp::GraphElement& protobuf);
    operator PbApp::GraphElement() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Graph
{
    std::string id;
    std::string title;
    std::vector<std::string> tags;
    std::vector<GraphElement> signals;
    std::vector<std::string> otherElements;
    bool hasTooltip;
    std::string author;
    int32_t implotFlags;
    int32_t axisFlags;
    
    Graph() = default;
    Graph(const PbApp::Graph& protobuf);
    operator PbApp::Graph() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct GridPlot
{
    std::string name;
    std::string id;
    Size size;
    int32_t flags;
    std::vector<std::string> graphID;
    
    GridPlot() = default;
    GridPlot(const PbApp::GridPlot& protobuf);
    operator PbApp::GridPlot() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CustomPage
{
    std::string id;
    std::string name;
    Size size;
    std::string author;
    std::vector<int32_t> gridCells;
    std::vector<std::string> gridPlotID;
    
    CustomPage() = default;
    CustomPage(const PbApp::CustomPage& protobuf);
    operator PbApp::CustomPage() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct PresetMappings
{
    std::unordered_map<std::string, Graph> plot_configs;
    std::unordered_map<std::string, GridPlot> subplot_configs;
    std::unordered_map<std::string, CustomPage> preset_configs;
    
    PresetMappings() = default;
    PresetMappings(const PbApp::PresetMappings& protobuf);
    operator PbApp::PresetMappings() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif