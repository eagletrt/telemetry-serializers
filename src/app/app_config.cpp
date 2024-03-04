#include "app/app_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace App
{
Connection::Connection(const PbApp::Connection& message) {
    ip = message.ip();
    port = message.port();
    mode = message.mode();
}

Connection::operator PbApp::Connection() const {
    PbApp::Connection ret;
    ret.set_ip(ip);
    ret.set_port(port);
    ret.set_mode(mode);
    return ret;
}

std::string Connection::serializeAsJsonString() const {
    PbApp::Connection message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Connection::serializeAsProtobufString() const {
    PbApp::Connection message(*this);
    return message.SerializeAsString();
}

bool Connection::deserializeFromJsonString(const std::string& str) {
    PbApp::Connection message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Connection::deserializeFromProtobufString(const std::string& str) {
    PbApp::Connection message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Trigger::Trigger(const PbApp::Trigger& message) {
    id = message.id();
    message = message.message();
    signal = message.signal();
    comparator = message.comparator();
    value = message.value();
    color = message.color();
}

Trigger::operator PbApp::Trigger() const {
    PbApp::Trigger ret;
    ret.set_id(id);
    ret.set_message(message);
    ret.set_signal(signal);
    ret.set_comparator(comparator);
    ret.set_value(value);
    ret.set_color(color);
    return ret;
}

std::string Trigger::serializeAsJsonString() const {
    PbApp::Trigger message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Trigger::serializeAsProtobufString() const {
    PbApp::Trigger message(*this);
    return message.SerializeAsString();
}

bool Trigger::deserializeFromJsonString(const std::string& str) {
    PbApp::Trigger message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Trigger::deserializeFromProtobufString(const std::string& str) {
    PbApp::Trigger message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

AxisItem::AxisItem(const PbApp::AxisItem& message) {
    message = message.message();
    signal = message.signal();
    isEnum = message.isenum();
    color = message.color();
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
    PbApp::AxisItem message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string AxisItem::serializeAsProtobufString() const {
    PbApp::AxisItem message(*this);
    return message.SerializeAsString();
}

bool AxisItem::deserializeFromJsonString(const std::string& str) {
    PbApp::AxisItem message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool AxisItem::deserializeFromProtobufString(const std::string& str) {
    PbApp::AxisItem message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Axis::Axis(const PbApp::Axis& message) {
    name = message.name();
    items = {message.items().begin(), message.items().end()};
}

Axis::operator PbApp::Axis() const {
    PbApp::Axis ret;
    ret.set_name(name);
    *(ret.mutable_items()) = {items.begin(), items.end()};
    return ret;
}

std::string Axis::serializeAsJsonString() const {
    PbApp::Axis message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Axis::serializeAsProtobufString() const {
    PbApp::Axis message(*this);
    return message.SerializeAsString();
}

bool Axis::deserializeFromJsonString(const std::string& str) {
    PbApp::Axis message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Axis::deserializeFromProtobufString(const std::string& str) {
    PbApp::Axis message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

CustomPlot::CustomPlot(const PbApp::CustomPlot& message) {
    name = message.name();
    axes = {message.axes().begin(), message.axes().end()};
}

CustomPlot::operator PbApp::CustomPlot() const {
    PbApp::CustomPlot ret;
    ret.set_name(name);
    *(ret.mutable_axes()) = {axes.begin(), axes.end()};
    return ret;
}

std::string CustomPlot::serializeAsJsonString() const {
    PbApp::CustomPlot message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string CustomPlot::serializeAsProtobufString() const {
    PbApp::CustomPlot message(*this);
    return message.SerializeAsString();
}

bool CustomPlot::deserializeFromJsonString(const std::string& str) {
    PbApp::CustomPlot message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool CustomPlot::deserializeFromProtobufString(const std::string& str) {
    PbApp::CustomPlot message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

AppConfig::AppConfig(const PbApp::AppConfig& message) {
    loginTimestamp = message.logintimestamp();
    colorTheme = message.colortheme();
    mode = message.mode();
    connection = message.connection();
    savedConnections = {message.savedconnections().begin(), message.savedconnections().end()};
    activeTabs = {message.activetabs().begin(), message.activetabs().end()};
    triggers = {message.triggers().begin(), message.triggers().end()};
    customPlots = {message.customplots().begin(), message.customplots().end()};
    filesPaths = {message.filespaths().begin(), message.filespaths().end()};
    stringCache = {message.stringcache().begin(), message.stringcache().end()};
    boolCache = {message.boolcache().begin(), message.boolcache().end()};
}

AppConfig::operator PbApp::AppConfig() const {
    PbApp::AppConfig ret;
    ret.set_logintimestamp(loginTimestamp);
    ret.set_colortheme(colorTheme);
    ret.set_mode(mode);
    *(ret.mutable_connection()) = connection;
    *(ret.mutable_savedconnections()) = {savedConnections.begin(), savedConnections.end()};
    *(ret.mutable_activetabs()) = {activeTabs.begin(), activeTabs.end()};
    *(ret.mutable_triggers()) = {triggers.begin(), triggers.end()};
    *(ret.mutable_customplots()) = {customPlots.begin(), customPlots.end()};
    *(ret.mutable_filespaths()) = {filesPaths.begin(), filesPaths.end()};
    *(ret.mutable_stringcache()) = {stringCache.begin(), stringCache.end()};
    *(ret.mutable_boolcache()) = {boolCache.begin(), boolCache.end()};
    return ret;
}

std::string AppConfig::serializeAsJsonString() const {
    PbApp::AppConfig message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string AppConfig::serializeAsProtobufString() const {
    PbApp::AppConfig message(*this);
    return message.SerializeAsString();
}

bool AppConfig::deserializeFromJsonString(const std::string& str) {
    PbApp::AppConfig message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool AppConfig::deserializeFromProtobufString(const std::string& str) {
    PbApp::AppConfig message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}