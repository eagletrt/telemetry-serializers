#include "app/app_config.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace App
{
Connection::Connection(const PbApp::Connection& protobuf) {
    ip = protobuf.ip();
    port = protobuf.port();
    mode = protobuf.mode();
}

Connection::operator PbApp::Connection() const {
    PbApp::Connection ret;
    ret.set_ip(ip);
    ret.set_port(port);
    ret.set_mode(mode);
    return ret;
}

std::string Connection::serializeAsJsonString() const {
    PbApp::Connection protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Connection::serializeAsProtobufString() const {
    PbApp::Connection protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Connection::deserializeFromJsonString(const std::string& str) {
    PbApp::Connection protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Connection::deserializeFromProtobufString(const std::string& str) {
    PbApp::Connection protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

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
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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

AxisItem::AxisItem(const PbApp::AxisItem& protobuf) {
    message = protobuf.message();
    signal = protobuf.signal();
    isEnum = protobuf.isenum();
    color = protobuf.color();
}

AxisItem::operator PbApp::AxisItem() const {
    PbApp::AxisItem ret;
    ret.set_message(message);
    ret.set_signal(signal);
    ret.set_isenum(isEnum);
    ret.set_color(color);
    return ret;
}

std::string AxisItem::serializeAsJsonString() const {
    PbApp::AxisItem protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string AxisItem::serializeAsProtobufString() const {
    PbApp::AxisItem protobuf(*this);
    return protobuf.SerializeAsString();
}

bool AxisItem::deserializeFromJsonString(const std::string& str) {
    PbApp::AxisItem protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool AxisItem::deserializeFromProtobufString(const std::string& str) {
    PbApp::AxisItem protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Axis::Axis(const PbApp::Axis& protobuf) {
    name = protobuf.name();
    items = {protobuf.items().begin(), protobuf.items().end()};
}

Axis::operator PbApp::Axis() const {
    PbApp::Axis ret;
    ret.set_name(name);
    *(ret.mutable_items()) = {items.begin(), items.end()};
    return ret;
}

std::string Axis::serializeAsJsonString() const {
    PbApp::Axis protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Axis::serializeAsProtobufString() const {
    PbApp::Axis protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Axis::deserializeFromJsonString(const std::string& str) {
    PbApp::Axis protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Axis::deserializeFromProtobufString(const std::string& str) {
    PbApp::Axis protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CustomPlot::CustomPlot(const PbApp::CustomPlot& protobuf) {
    name = protobuf.name();
    axes = {protobuf.axes().begin(), protobuf.axes().end()};
}

CustomPlot::operator PbApp::CustomPlot() const {
    PbApp::CustomPlot ret;
    ret.set_name(name);
    *(ret.mutable_axes()) = {axes.begin(), axes.end()};
    return ret;
}

std::string CustomPlot::serializeAsJsonString() const {
    PbApp::CustomPlot protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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

AppConfig::AppConfig(const PbApp::AppConfig& protobuf) {
    loginTimestamp = protobuf.logintimestamp();
    colorTheme = protobuf.colortheme();
    connection = protobuf.connection();
    savedConnections = {protobuf.savedconnections().begin(), protobuf.savedconnections().end()};
    activeTabs = {protobuf.activetabs().begin(), protobuf.activetabs().end()};
    filesPaths = {protobuf.filespaths().begin(), protobuf.filespaths().end()};
    stringCache = {protobuf.stringcache().begin(), protobuf.stringcache().end()};
    boolCache = {protobuf.boolcache().begin(), protobuf.boolcache().end()};
    doubleTriggers = {protobuf.doubletriggers().begin(), protobuf.doubletriggers().end()};
    enumTriggers = {protobuf.enumtriggers().begin(), protobuf.enumtriggers().end()};
    bitTriggers = {protobuf.bittriggers().begin(), protobuf.bittriggers().end()};
    customPlots = {protobuf.customplots().begin(), protobuf.customplots().end()};
}

AppConfig::operator PbApp::AppConfig() const {
    PbApp::AppConfig ret;
    ret.set_logintimestamp(loginTimestamp);
    ret.set_colortheme(colorTheme);
    *(ret.mutable_connection()) = connection;
    *(ret.mutable_savedconnections()) = {savedConnections.begin(), savedConnections.end()};
    *(ret.mutable_activetabs()) = {activeTabs.begin(), activeTabs.end()};
    *(ret.mutable_filespaths()) = {filesPaths.begin(), filesPaths.end()};
    *(ret.mutable_stringcache()) = {stringCache.begin(), stringCache.end()};
    *(ret.mutable_boolcache()) = {boolCache.begin(), boolCache.end()};
    *(ret.mutable_doubletriggers()) = {doubleTriggers.begin(), doubleTriggers.end()};
    *(ret.mutable_enumtriggers()) = {enumTriggers.begin(), enumTriggers.end()};
    *(ret.mutable_bittriggers()) = {bitTriggers.begin(), bitTriggers.end()};
    *(ret.mutable_customplots()) = {customPlots.begin(), customPlots.end()};
    return ret;
}

std::string AppConfig::serializeAsJsonString() const {
    PbApp::AppConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string AppConfig::serializeAsProtobufString() const {
    PbApp::AppConfig protobuf(*this);
    return protobuf.SerializeAsString();
}

bool AppConfig::deserializeFromJsonString(const std::string& str) {
    PbApp::AppConfig protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool AppConfig::deserializeFromProtobufString(const std::string& str) {
    PbApp::AppConfig protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}