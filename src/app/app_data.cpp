#include "app/app_data.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace App
{
CustomPlotItem::CustomPlotItem(const PbApp::CustomPlotItem& protobuf) {
    messageAxisX = protobuf.messageaxisx();
    messageAxisY = protobuf.messageaxisy();
    signalAxisX = protobuf.signalaxisx();
    signalAxisY = protobuf.signalaxisy();
    isEnum = protobuf.isenum();
    color = protobuf.color();
}

CustomPlotItem::operator PbApp::CustomPlotItem() const {
    PbApp::CustomPlotItem ret;
    ret.set_messageaxisx(messageAxisX);
    ret.set_messageaxisy(messageAxisY);
    ret.set_signalaxisx(signalAxisX);
    ret.set_signalaxisy(signalAxisY);
    ret.set_isenum(isEnum);
    ret.set_color(color);
    return ret;
}

std::string CustomPlotItem::serializeAsJsonString() const {
    PbApp::CustomPlotItem protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CustomPlotItem::serializeAsProtobufString() const {
    PbApp::CustomPlotItem protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CustomPlotItem::deserializeFromJsonString(const std::string& str) {
    PbApp::CustomPlotItem protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CustomPlotItem::deserializeFromProtobufString(const std::string& str) {
    PbApp::CustomPlotItem protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CustomPlotAxis::CustomPlotAxis(const PbApp::CustomPlotAxis& protobuf) {
    label = protobuf.label();
    items = {protobuf.items().begin(), protobuf.items().end()};
}

CustomPlotAxis::operator PbApp::CustomPlotAxis() const {
    PbApp::CustomPlotAxis ret;
    ret.set_label(label);
    *(ret.mutable_items()) = {items.begin(), items.end()};
    return ret;
}

std::string CustomPlotAxis::serializeAsJsonString() const {
    PbApp::CustomPlotAxis protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CustomPlotAxis::serializeAsProtobufString() const {
    PbApp::CustomPlotAxis protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CustomPlotAxis::deserializeFromJsonString(const std::string& str) {
    PbApp::CustomPlotAxis protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CustomPlotAxis::deserializeFromProtobufString(const std::string& str) {
    PbApp::CustomPlotAxis protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

NewCustomPlot::NewCustomPlot(const PbApp::NewCustomPlot& protobuf) {
    title = protobuf.title();
    axes = {protobuf.axes().begin(), protobuf.axes().end()};
}

NewCustomPlot::operator PbApp::NewCustomPlot() const {
    PbApp::NewCustomPlot ret;
    ret.set_title(title);
    *(ret.mutable_axes()) = {axes.begin(), axes.end()};
    return ret;
}

std::string NewCustomPlot::serializeAsJsonString() const {
    PbApp::NewCustomPlot protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string NewCustomPlot::serializeAsProtobufString() const {
    PbApp::NewCustomPlot protobuf(*this);
    return protobuf.SerializeAsString();
}

bool NewCustomPlot::deserializeFromJsonString(const std::string& str) {
    PbApp::NewCustomPlot protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool NewCustomPlot::deserializeFromProtobufString(const std::string& str) {
    PbApp::NewCustomPlot protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CustomSubPlots::CustomSubPlots(const PbApp::CustomSubPlots& protobuf) {
    rows = protobuf.rows();
    plots = {protobuf.plots().begin(), protobuf.plots().end()};
}

CustomSubPlots::operator PbApp::CustomSubPlots() const {
    PbApp::CustomSubPlots ret;
    ret.set_rows(rows);
    *(ret.mutable_plots()) = {plots.begin(), plots.end()};
    return ret;
}

std::string CustomSubPlots::serializeAsJsonString() const {
    PbApp::CustomSubPlots protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CustomSubPlots::serializeAsProtobufString() const {
    PbApp::CustomSubPlots protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CustomSubPlots::deserializeFromJsonString(const std::string& str) {
    PbApp::CustomSubPlots protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CustomSubPlots::deserializeFromProtobufString(const std::string& str) {
    PbApp::CustomSubPlots protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CustomPlotsTab::CustomPlotsTab(const PbApp::CustomPlotsTab& protobuf) {
    subPlots = {protobuf.subplots().begin(), protobuf.subplots().end()};
}

CustomPlotsTab::operator PbApp::CustomPlotsTab() const {
    PbApp::CustomPlotsTab ret;
    *(ret.mutable_subplots()) = {subPlots.begin(), subPlots.end()};
    return ret;
}

std::string CustomPlotsTab::serializeAsJsonString() const {
    PbApp::CustomPlotsTab protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CustomPlotsTab::serializeAsProtobufString() const {
    PbApp::CustomPlotsTab protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CustomPlotsTab::deserializeFromJsonString(const std::string& str) {
    PbApp::CustomPlotsTab protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CustomPlotsTab::deserializeFromProtobufString(const std::string& str) {
    PbApp::CustomPlotsTab protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

AppData::AppData(const PbApp::AppData& protobuf) {
    customPlotsTabs = {protobuf.customplotstabs().begin(), protobuf.customplotstabs().end()};
}

AppData::operator PbApp::AppData() const {
    PbApp::AppData ret;
    *(ret.mutable_customplotstabs()) = {customPlotsTabs.begin(), customPlotsTabs.end()};
    return ret;
}

std::string AppData::serializeAsJsonString() const {
    PbApp::AppData protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string AppData::serializeAsProtobufString() const {
    PbApp::AppData protobuf(*this);
    return protobuf.SerializeAsString();
}

bool AppData::deserializeFromJsonString(const std::string& str) {
    PbApp::AppData protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool AppData::deserializeFromProtobufString(const std::string& str) {
    PbApp::AppData protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}