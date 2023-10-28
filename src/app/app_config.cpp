#include "app/app_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace App
{
Device::Device(const AppDevice& proto) {
    vehicleId = proto.vehicleid();
    deviceId = proto.deviceid();
}

Device::operator AppDevice() const {
    AppDevice ret;
    ret.set_vehicleid(vehicleId);
    ret.set_deviceid(deviceId);
    return ret;
}

std::string Device::serializeAsJsonString() const {
    AppDevice proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Device::serializeAsProtobufString() const {
    AppDevice proto(*this);
    return proto.SerializeAsString();
}

bool Device::deserializeFromJsonString(const std::string& str) {
    AppDevice proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Device::deserializeFromProtobufString(const std::string& str) {
    AppDevice proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Connection::Connection(const AppConnection& proto) {
    ip = proto.ip();
    port = proto.port();
    mode = proto.mode();
}

Connection::operator AppConnection() const {
    AppConnection ret;
    ret.set_ip(ip);
    ret.set_port(port);
    ret.set_mode(mode);
    return ret;
}

std::string Connection::serializeAsJsonString() const {
    AppConnection proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Connection::serializeAsProtobufString() const {
    AppConnection proto(*this);
    return proto.SerializeAsString();
}

bool Connection::deserializeFromJsonString(const std::string& str) {
    AppConnection proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Connection::deserializeFromProtobufString(const std::string& str) {
    AppConnection proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

PostProc::PostProc(const AppPostProc& proto) {
    sampleFrequency = proto.samplefrequency();
    includedItems = {proto.includeditems().begin(), proto.includeditems().end()};
    exceludedItems = {proto.exceludeditems().begin(), proto.exceludeditems().end()};
}

PostProc::operator AppPostProc() const {
    AppPostProc ret;
    ret.set_samplefrequency(sampleFrequency);
    *(ret.mutable_includeditems()) = {includedItems.begin(), includedItems.end()};
    *(ret.mutable_exceludeditems()) = {exceludedItems.begin(), exceludedItems.end()};
    return ret;
}

std::string PostProc::serializeAsJsonString() const {
    AppPostProc proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string PostProc::serializeAsProtobufString() const {
    AppPostProc proto(*this);
    return proto.SerializeAsString();
}

bool PostProc::deserializeFromJsonString(const std::string& str) {
    AppPostProc proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool PostProc::deserializeFromProtobufString(const std::string& str) {
    AppPostProc proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Color::Color(const AppColor& proto) {
    r = proto.r();
    g = proto.g();
    b = proto.b();
    a = proto.a();
}

Color::operator AppColor() const {
    AppColor ret;
    ret.set_r(r);
    ret.set_g(g);
    ret.set_b(b);
    ret.set_a(a);
    return ret;
}

std::string Color::serializeAsJsonString() const {
    AppColor proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Color::serializeAsProtobufString() const {
    AppColor proto(*this);
    return proto.SerializeAsString();
}

bool Color::deserializeFromJsonString(const std::string& str) {
    AppColor proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Color::deserializeFromProtobufString(const std::string& str) {
    AppColor proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Event::Event(const AppEvent& proto) {
    message = proto.message();
    field = proto.field();
    comparator = proto.comparator();
    value = proto.value();
    color = proto.color();
}

Event::operator AppEvent() const {
    AppEvent ret;
    ret.set_message(message);
    ret.set_field(field);
    ret.set_comparator(comparator);
    ret.set_value(value);
    *(ret.mutable_color()) = color;
    return ret;
}

std::string Event::serializeAsJsonString() const {
    AppEvent proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Event::serializeAsProtobufString() const {
    AppEvent proto(*this);
    return proto.SerializeAsString();
}

bool Event::deserializeFromJsonString(const std::string& str) {
    AppEvent proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Event::deserializeFromProtobufString(const std::string& str) {
    AppEvent proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Field::Field(const AppField& proto) {
    message = proto.message();
    field = proto.field();
}

Field::operator AppField() const {
    AppField ret;
    ret.set_message(message);
    ret.set_field(field);
    return ret;
}

std::string Field::serializeAsJsonString() const {
    AppField proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Field::serializeAsProtobufString() const {
    AppField proto(*this);
    return proto.SerializeAsString();
}

bool Field::deserializeFromJsonString(const std::string& str) {
    AppField proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Field::deserializeFromProtobufString(const std::string& str) {
    AppField proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Axis::Axis(const AppAxis& proto) {
    name = proto.name();
    fields = {proto.fields().begin(), proto.fields().end()};
}

Axis::operator AppAxis() const {
    AppAxis ret;
    ret.set_name(name);
    *(ret.mutable_fields()) = {fields.begin(), fields.end()};
    return ret;
}

std::string Axis::serializeAsJsonString() const {
    AppAxis proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Axis::serializeAsProtobufString() const {
    AppAxis proto(*this);
    return proto.SerializeAsString();
}

bool Axis::deserializeFromJsonString(const std::string& str) {
    AppAxis proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Axis::deserializeFromProtobufString(const std::string& str) {
    AppAxis proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

CustomPlot::CustomPlot(const AppCustomPlot& proto) {
    name = proto.name();
    axes = {proto.axes().begin(), proto.axes().end()};
}

CustomPlot::operator AppCustomPlot() const {
    AppCustomPlot ret;
    ret.set_name(name);
    *(ret.mutable_axes()) = {axes.begin(), axes.end()};
    return ret;
}

std::string CustomPlot::serializeAsJsonString() const {
    AppCustomPlot proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string CustomPlot::serializeAsProtobufString() const {
    AppCustomPlot proto(*this);
    return proto.SerializeAsString();
}

bool CustomPlot::deserializeFromJsonString(const std::string& str) {
    AppCustomPlot proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool CustomPlot::deserializeFromProtobufString(const std::string& str) {
    AppCustomPlot proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

AppConfig::AppConfig(const AppAppConfig& proto) {
    loginTimestamp = proto.logintimestamp();
    colorTheme = proto.colortheme();
    mode = proto.mode();
    csvAutoSave = proto.csvautosave();
    postProc = proto.postproc();
    connection = proto.connection();
    savedConnections = {proto.savedconnections().begin(), proto.savedconnections().end()};
    devices = {proto.devices().begin(), proto.devices().end()};
    events = {proto.events().begin(), proto.events().end()};
    customPlots = {proto.customplots().begin(), proto.customplots().end()};
    filesPaths = {proto.filespaths().begin(), proto.filespaths().end()};
}

AppConfig::operator AppAppConfig() const {
    AppAppConfig ret;
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
    return ret;
}

std::string AppConfig::serializeAsJsonString() const {
    AppAppConfig proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string AppConfig::serializeAsProtobufString() const {
    AppAppConfig proto(*this);
    return proto.SerializeAsString();
}

bool AppConfig::deserializeFromJsonString(const std::string& str) {
    AppAppConfig proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool AppConfig::deserializeFromProtobufString(const std::string& str) {
    AppAppConfig proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}