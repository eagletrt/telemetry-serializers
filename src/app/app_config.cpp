#include "app/app_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace App
{
Device::Device(const PbApp::Device& protobuf) {
    vehicleId = protobuf.vehicleid();
    deviceId = protobuf.deviceid();
}

Device::operator PbApp::Device() const {
    PbApp::Device ret;
    ret.set_vehicleid(vehicleId);
    ret.set_deviceid(deviceId);
    return ret;
}

std::string Device::serializeAsJsonString() const {
    PbApp::Device protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Device::serializeAsProtobufString() const {
    PbApp::Device protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Device::deserializeFromJsonString(const std::string& str) {
    PbApp::Device protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Device::deserializeFromProtobufString(const std::string& str) {
    PbApp::Device protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

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

PostProc::PostProc(const PbApp::PostProc& protobuf) {
    sampleFrequency = protobuf.samplefrequency();
    includedItems = {protobuf.includeditems().begin(), protobuf.includeditems().end()};
    exceludedItems = {protobuf.exceludeditems().begin(), protobuf.exceludeditems().end()};
}

PostProc::operator PbApp::PostProc() const {
    PbApp::PostProc ret;
    ret.set_samplefrequency(sampleFrequency);
    *(ret.mutable_includeditems()) = {includedItems.begin(), includedItems.end()};
    *(ret.mutable_exceludeditems()) = {exceludedItems.begin(), exceludedItems.end()};
    return ret;
}

std::string PostProc::serializeAsJsonString() const {
    PbApp::PostProc protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string PostProc::serializeAsProtobufString() const {
    PbApp::PostProc protobuf(*this);
    return protobuf.SerializeAsString();
}

bool PostProc::deserializeFromJsonString(const std::string& str) {
    PbApp::PostProc protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool PostProc::deserializeFromProtobufString(const std::string& str) {
    PbApp::PostProc protobuf;
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

Field::Field(const PbApp::Field& protobuf) {
    message = protobuf.message();
    field = protobuf.field();
}

Field::operator PbApp::Field() const {
    PbApp::Field ret;
    ret.set_message(message);
    ret.set_field(field);
    return ret;
}

std::string Field::serializeAsJsonString() const {
    PbApp::Field protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Field::serializeAsProtobufString() const {
    PbApp::Field protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Field::deserializeFromJsonString(const std::string& str) {
    PbApp::Field protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Field::deserializeFromProtobufString(const std::string& str) {
    PbApp::Field protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Axis::Axis(const PbApp::Axis& protobuf) {
    name = protobuf.name();
    fields = {protobuf.fields().begin(), protobuf.fields().end()};
}

Axis::operator PbApp::Axis() const {
    PbApp::Axis ret;
    ret.set_name(name);
    *(ret.mutable_fields()) = {fields.begin(), fields.end()};
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
    csvAutoSave = protobuf.csvautosave();
    postProc = protobuf.postproc();
    connection = protobuf.connection();
    savedConnections = {protobuf.savedconnections().begin(), protobuf.savedconnections().end()};
    devices = {protobuf.devices().begin(), protobuf.devices().end()};
    events = {protobuf.events().begin(), protobuf.events().end()};
    customPlots = {protobuf.customplots().begin(), protobuf.customplots().end()};
    filesPaths = {protobuf.filespaths().begin(), protobuf.filespaths().end()};
    cacheMap = {protobuf.cachemap().begin(), protobuf.cachemap().end()};
}

AppConfig::operator PbApp::AppConfig() const {
    PbApp::AppConfig ret;
    ret.set_logintimestamp(loginTimestamp);
    ret.set_colortheme(colorTheme);
    ret.set_mode(mode);
    ret.set_csvautosave(csvAutoSave);
    *(ret.mutable_postproc()) = postProc;
    *(ret.mutable_connection()) = connection;
    *(ret.mutable_savedconnections()) = {savedConnections.begin(), savedConnections.end()};
    *(ret.mutable_devices()) = {devices.begin(), devices.end()};
    *(ret.mutable_events()) = {events.begin(), events.end()};
    *(ret.mutable_customplots()) = {customPlots.begin(), customPlots.end()};
    *(ret.mutable_filespaths()) = {filesPaths.begin(), filesPaths.end()};
    *(ret.mutable_cachemap()) = {cacheMap.begin(), cacheMap.end()};
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