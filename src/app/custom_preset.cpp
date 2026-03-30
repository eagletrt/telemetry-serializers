#include "app/custom_preset.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace App
{
Size::Size(const PbApp::Size& protobuf) {
    w = protobuf.w();
    h = protobuf.h();
}

Size::operator PbApp::Size() const {
    PbApp::Size ret;
    ret.set_w(w);
    ret.set_h(h);
    return ret;
}

std::string Size::serializeAsJsonString() const {
    PbApp::Size protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Size::serializeAsProtobufString() const {
    PbApp::Size protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Size::deserializeFromJsonString(const std::string& str) {
    PbApp::Size protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Size::deserializeFromProtobufString(const std::string& str) {
    PbApp::Size protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GraphElement::GraphElement(const PbApp::GraphElement& protobuf) {
    label = protobuf.label();
    type = static_cast<PlotType>(protobuf.type());
    xField = protobuf.xfield();
    yField = protobuf.yfield();
    color = protobuf.color();
    axisX = protobuf.axisx();
    axisY = protobuf.axisy();
}

GraphElement::operator PbApp::GraphElement() const {
    PbApp::GraphElement ret;
    ret.set_label(label);
    ret.set_type(static_cast<PbApp::PlotType>(type));
    ret.set_xfield(xField);
    ret.set_yfield(yField);
    ret.set_color(color);
    ret.set_axisx(axisX);
    ret.set_axisy(axisY);
    return ret;
}

std::string GraphElement::serializeAsJsonString() const {
    PbApp::GraphElement protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GraphElement::serializeAsProtobufString() const {
    PbApp::GraphElement protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GraphElement::deserializeFromJsonString(const std::string& str) {
    PbApp::GraphElement protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GraphElement::deserializeFromProtobufString(const std::string& str) {
    PbApp::GraphElement protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Graph::Graph(const PbApp::Graph& protobuf) {
    id = protobuf.id();
    title = protobuf.title();
    tags = {protobuf.tags().begin(), protobuf.tags().end()};
    signals = {protobuf.signals().begin(), protobuf.signals().end()};
    otherElements = {protobuf.otherelements().begin(), protobuf.otherelements().end()};
    hasTooltip = protobuf.hastooltip();
    author = protobuf.author();
    implotFlags = protobuf.implotflags();
    axisFlags = protobuf.axisflags();
}

Graph::operator PbApp::Graph() const {
    PbApp::Graph ret;
    ret.set_id(id);
    ret.set_title(title);
    *(ret.mutable_tags()) = {tags.begin(), tags.end()};
    *(ret.mutable_signals()) = {signals.begin(), signals.end()};
    *(ret.mutable_otherelements()) = {otherElements.begin(), otherElements.end()};
    ret.set_hastooltip(hasTooltip);
    ret.set_author(author);
    ret.set_implotflags(implotFlags);
    ret.set_axisflags(axisFlags);
    return ret;
}

std::string Graph::serializeAsJsonString() const {
    PbApp::Graph protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Graph::serializeAsProtobufString() const {
    PbApp::Graph protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Graph::deserializeFromJsonString(const std::string& str) {
    PbApp::Graph protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Graph::deserializeFromProtobufString(const std::string& str) {
    PbApp::Graph protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GridPlot::GridPlot(const PbApp::GridPlot& protobuf) {
    name = protobuf.name();
    id = protobuf.id();
    size = protobuf.size();
    flags = protobuf.flags();
    graphID = {protobuf.graphid().begin(), protobuf.graphid().end()};
}

GridPlot::operator PbApp::GridPlot() const {
    PbApp::GridPlot ret;
    ret.set_name(name);
    ret.set_id(id);
    *(ret.mutable_size()) = size;
    ret.set_flags(flags);
    *(ret.mutable_graphid()) = {graphID.begin(), graphID.end()};
    return ret;
}

std::string GridPlot::serializeAsJsonString() const {
    PbApp::GridPlot protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GridPlot::serializeAsProtobufString() const {
    PbApp::GridPlot protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GridPlot::deserializeFromJsonString(const std::string& str) {
    PbApp::GridPlot protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GridPlot::deserializeFromProtobufString(const std::string& str) {
    PbApp::GridPlot protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CustomPage::CustomPage(const PbApp::CustomPage& protobuf) {
    id = protobuf.id();
    name = protobuf.name();
    size = protobuf.size();
    author = protobuf.author();
    gridCells = {protobuf.gridcells().begin(), protobuf.gridcells().end()};
    gridPlotID = {protobuf.gridplotid().begin(), protobuf.gridplotid().end()};
}

CustomPage::operator PbApp::CustomPage() const {
    PbApp::CustomPage ret;
    ret.set_id(id);
    ret.set_name(name);
    *(ret.mutable_size()) = size;
    ret.set_author(author);
    *(ret.mutable_gridcells()) = {gridCells.begin(), gridCells.end()};
    *(ret.mutable_gridplotid()) = {gridPlotID.begin(), gridPlotID.end()};
    return ret;
}

std::string CustomPage::serializeAsJsonString() const {
    PbApp::CustomPage protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CustomPage::serializeAsProtobufString() const {
    PbApp::CustomPage protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CustomPage::deserializeFromJsonString(const std::string& str) {
    PbApp::CustomPage protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CustomPage::deserializeFromProtobufString(const std::string& str) {
    PbApp::CustomPage protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

PresetMappings::PresetMappings(const PbApp::PresetMappings& protobuf) {
    plot_configs = {protobuf.plot_configs().begin(), protobuf.plot_configs().end()};
    subplot_configs = {protobuf.subplot_configs().begin(), protobuf.subplot_configs().end()};
    preset_configs = {protobuf.preset_configs().begin(), protobuf.preset_configs().end()};
}

PresetMappings::operator PbApp::PresetMappings() const {
    PbApp::PresetMappings ret;
    *(ret.mutable_plot_configs()) = {plot_configs.begin(), plot_configs.end()};
    *(ret.mutable_subplot_configs()) = {subplot_configs.begin(), subplot_configs.end()};
    *(ret.mutable_preset_configs()) = {preset_configs.begin(), preset_configs.end()};
    return ret;
}

std::string PresetMappings::serializeAsJsonString() const {
    PbApp::PresetMappings protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string PresetMappings::serializeAsProtobufString() const {
    PbApp::PresetMappings protobuf(*this);
    return protobuf.SerializeAsString();
}

bool PresetMappings::deserializeFromJsonString(const std::string& str) {
    PbApp::PresetMappings protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool PresetMappings::deserializeFromProtobufString(const std::string& str) {
    PbApp::PresetMappings protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}