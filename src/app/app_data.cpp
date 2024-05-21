#include "app/app_data.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace App
{
DoubleTrigger::DoubleTrigger(const PbApp::DoubleTrigger& protobuf) {
    id = protobuf.id();
    message = protobuf.message();
    signal = protobuf.signal();
    comparator = protobuf.comparator();
    value = protobuf.value();
    color = protobuf.color();
}

DoubleTrigger::operator PbApp::DoubleTrigger() const {
    PbApp::DoubleTrigger ret;
    ret.set_id(id);
    ret.set_message(message);
    ret.set_signal(signal);
    ret.set_comparator(comparator);
    ret.set_value(value);
    ret.set_color(color);
    return ret;
}

std::string DoubleTrigger::serializeAsJsonString() const {
    PbApp::DoubleTrigger protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string DoubleTrigger::serializeAsProtobufString() const {
    PbApp::DoubleTrigger protobuf(*this);
    return protobuf.SerializeAsString();
}

bool DoubleTrigger::deserializeFromJsonString(const std::string& str) {
    PbApp::DoubleTrigger protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool DoubleTrigger::deserializeFromProtobufString(const std::string& str) {
    PbApp::DoubleTrigger protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

EnumTrigger::EnumTrigger(const PbApp::EnumTrigger& protobuf) {
    id = protobuf.id();
    message = protobuf.message();
    signal = protobuf.signal();
    comparator = protobuf.comparator();
    value = protobuf.value();
    color = protobuf.color();
}

EnumTrigger::operator PbApp::EnumTrigger() const {
    PbApp::EnumTrigger ret;
    ret.set_id(id);
    ret.set_message(message);
    ret.set_signal(signal);
    ret.set_comparator(comparator);
    ret.set_value(value);
    ret.set_color(color);
    return ret;
}

std::string EnumTrigger::serializeAsJsonString() const {
    PbApp::EnumTrigger protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string EnumTrigger::serializeAsProtobufString() const {
    PbApp::EnumTrigger protobuf(*this);
    return protobuf.SerializeAsString();
}

bool EnumTrigger::deserializeFromJsonString(const std::string& str) {
    PbApp::EnumTrigger protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool EnumTrigger::deserializeFromProtobufString(const std::string& str) {
    PbApp::EnumTrigger protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

BitTrigger::BitTrigger(const PbApp::BitTrigger& protobuf) {
    id = protobuf.id();
    message = protobuf.message();
    signal = protobuf.signal();
    comparator = protobuf.comparator();
    value = protobuf.value();
    color = protobuf.color();
}

BitTrigger::operator PbApp::BitTrigger() const {
    PbApp::BitTrigger ret;
    ret.set_id(id);
    ret.set_message(message);
    ret.set_signal(signal);
    ret.set_comparator(comparator);
    ret.set_value(value);
    ret.set_color(color);
    return ret;
}

std::string BitTrigger::serializeAsJsonString() const {
    PbApp::BitTrigger protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string BitTrigger::serializeAsProtobufString() const {
    PbApp::BitTrigger protobuf(*this);
    return protobuf.SerializeAsString();
}

bool BitTrigger::deserializeFromJsonString(const std::string& str) {
    PbApp::BitTrigger protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool BitTrigger::deserializeFromProtobufString(const std::string& str) {
    PbApp::BitTrigger protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

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
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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

CustomPlot::CustomPlot(const PbApp::CustomPlot& protobuf) {
    title = protobuf.title();
    axes = {protobuf.axes().begin(), protobuf.axes().end()};
}

CustomPlot::operator PbApp::CustomPlot() const {
    PbApp::CustomPlot ret;
    ret.set_title(title);
    *(ret.mutable_axes()) = {axes.begin(), axes.end()};
    return ret;
}

std::string CustomPlot::serializeAsJsonString() const {
    PbApp::CustomPlot protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CustomPlot::serializeAsProtobufString() const {
    PbApp::CustomPlot protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CustomPlot::deserializeFromJsonString(const std::string& str) {
    PbApp::CustomPlot protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CustomPlot::deserializeFromProtobufString(const std::string& str) {
    PbApp::CustomPlot protobuf;
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
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    doubleTriggers = {protobuf.doubletriggers().begin(), protobuf.doubletriggers().end()};
    enumTriggers = {protobuf.enumtriggers().begin(), protobuf.enumtriggers().end()};
    bitTriggers = {protobuf.bittriggers().begin(), protobuf.bittriggers().end()};
    customPlotsTabs = {protobuf.customplotstabs().begin(), protobuf.customplotstabs().end()};
}

AppData::operator PbApp::AppData() const {
    PbApp::AppData ret;
    *(ret.mutable_doubletriggers()) = {doubleTriggers.begin(), doubleTriggers.end()};
    *(ret.mutable_enumtriggers()) = {enumTriggers.begin(), enumTriggers.end()};
    *(ret.mutable_bittriggers()) = {bitTriggers.begin(), bitTriggers.end()};
    *(ret.mutable_customplotstabs()) = {customPlotsTabs.begin(), customPlotsTabs.end()};
    return ret;
}

std::string AppData::serializeAsJsonString() const {
    PbApp::AppData protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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