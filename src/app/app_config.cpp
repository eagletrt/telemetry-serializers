#include "app/app_config.h"

#include <google/protobuf/util/json_util.h>

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
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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

Color::Color(const PbApp::Color& protobuf) {
    r = protobuf.r();
    g = protobuf.g();
    b = protobuf.b();
    a = protobuf.a();
}

Color::operator PbApp::Color() const {
    PbApp::Color ret;
    ret.set_r(r);
    ret.set_g(g);
    ret.set_b(b);
    ret.set_a(a);
    return ret;
}

std::string Color::serializeAsJsonString() const {
    PbApp::Color protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Color::serializeAsProtobufString() const {
    PbApp::Color protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Color::deserializeFromJsonString(const std::string& str) {
    PbApp::Color protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Color::deserializeFromProtobufString(const std::string& str) {
    PbApp::Color protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Event::Event(const PbApp::Event& protobuf) {
    message = protobuf.message();
    field = protobuf.field();
    comparator = protobuf.comparator();
    value = protobuf.value();
    color = protobuf.color();
}

Event::operator PbApp::Event() const {
    PbApp::Event ret;
    ret.set_message(message);
    ret.set_field(field);
    ret.set_comparator(comparator);
    ret.set_value(value);
    *(ret.mutable_color()) = color;
    return ret;
}

std::string Event::serializeAsJsonString() const {
    PbApp::Event protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Event::serializeAsProtobufString() const {
    PbApp::Event protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Event::deserializeFromJsonString(const std::string& str) {
    PbApp::Event protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Event::deserializeFromProtobufString(const std::string& str) {
    PbApp::Event protobuf;
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
    color = protobuf.color();
}

AxisItem::operator PbApp::AxisItem() const {
    PbApp::AxisItem ret;
    ret.set_message(message);
    ret.set_signal(signal);
    *(ret.mutable_color()) = color;
    return ret;
}

std::string AxisItem::serializeAsJsonString() const {
    PbApp::AxisItem protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    imAxis = protobuf.imaxis();
    items = {protobuf.items().begin(), protobuf.items().end()};
}

Axis::operator PbApp::Axis() const {
    PbApp::Axis ret;
    ret.set_name(name);
    ret.set_imaxis(imAxis);
    *(ret.mutable_items()) = {items.begin(), items.end()};
    return ret;
}

std::string Axis::serializeAsJsonString() const {
    PbApp::Axis protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    index = protobuf.index();
    axes = {protobuf.axes().begin(), protobuf.axes().end()};
}

CustomPlot::operator PbApp::CustomPlot() const {
    PbApp::CustomPlot ret;
    ret.set_name(name);
    ret.set_index(index);
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

AppConfig::AppConfig(const PbApp::AppConfig& protobuf) {
    loginTimestamp = protobuf.logintimestamp();
    colorTheme = protobuf.colortheme();
    mode = protobuf.mode();
    connection = protobuf.connection();
    savedConnections = {protobuf.savedconnections().begin(), protobuf.savedconnections().end()};
    activeTabs = {protobuf.activetabs().begin(), protobuf.activetabs().end()};
    events = {protobuf.events().begin(), protobuf.events().end()};
    customPlots = {protobuf.customplots().begin(), protobuf.customplots().end()};
    filesPaths = {protobuf.filespaths().begin(), protobuf.filespaths().end()};
    stringCache = {protobuf.stringcache().begin(), protobuf.stringcache().end()};
    boolCache = {protobuf.boolcache().begin(), protobuf.boolcache().end()};
}

AppConfig::operator PbApp::AppConfig() const {
    PbApp::AppConfig ret;
    ret.set_logintimestamp(loginTimestamp);
    ret.set_colortheme(colorTheme);
    ret.set_mode(mode);
    *(ret.mutable_connection()) = connection;
    *(ret.mutable_savedconnections()) = {savedConnections.begin(), savedConnections.end()};
    *(ret.mutable_activetabs()) = {activeTabs.begin(), activeTabs.end()};
    *(ret.mutable_events()) = {events.begin(), events.end()};
    *(ret.mutable_customplots()) = {customPlots.begin(), customPlots.end()};
    *(ret.mutable_filespaths()) = {filesPaths.begin(), filesPaths.end()};
    *(ret.mutable_stringcache()) = {stringCache.begin(), stringCache.end()};
    *(ret.mutable_boolcache()) = {boolCache.begin(), boolCache.end()};
    return ret;
}

std::string AppConfig::serializeAsJsonString() const {
    PbApp::AppConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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