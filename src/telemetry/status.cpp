#include "telemetry/status.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
MessagesPerSecond::MessagesPerSecond(const PbTelemetry::MessagesPerSecond& message) {
    deviceName = message.devicename();
    bitsPerSecond = message.bitspersecond();
    busLoad = message.busload();
    count = message.count();
}

MessagesPerSecond::operator PbTelemetry::MessagesPerSecond() const {
    PbTelemetry::MessagesPerSecond ret;
    ret.set_devicename(deviceName);
    ret.set_bitspersecond(bitsPerSecond);
    ret.set_busload(busLoad);
    ret.set_count(count);
    return ret;
}

std::string MessagesPerSecond::serializeAsJsonString() const {
    PbTelemetry::MessagesPerSecond message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string MessagesPerSecond::serializeAsProtobufString() const {
    PbTelemetry::MessagesPerSecond message(*this);
    return message.SerializeAsString();
}

bool MessagesPerSecond::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::MessagesPerSecond message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool MessagesPerSecond::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::MessagesPerSecond message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Camera::Camera(const PbTelemetry::Camera& message) {
    status = message.status();
    error = message.error();
}

Camera::operator PbTelemetry::Camera() const {
    PbTelemetry::Camera ret;
    ret.set_status(status);
    ret.set_error(error);
    return ret;
}

std::string Camera::serializeAsJsonString() const {
    PbTelemetry::Camera message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Camera::serializeAsProtobufString() const {
    PbTelemetry::Camera message(*this);
    return message.SerializeAsString();
}

bool Camera::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Camera message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Camera::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Camera message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Status::Status(const PbTelemetry::Status& message) {
    timestamp = message.timestamp();
    zeroTimestamp = message.zerotimestamp();
    data = message.data();
    cpuTotalLoad = message.cputotalload();
    cpuProcessLoad = message.cpuprocessload();
    memProcessLoad = message.memprocessload();
    canlibBuildTime = message.canlibbuildtime();
    telemetryBuildTime = message.telemetrybuildtime();
    camera = message.camera();
    messagesPerSecond = {message.messagespersecond().begin(), message.messagespersecond().end()};
}

Status::operator PbTelemetry::Status() const {
    PbTelemetry::Status ret;
    ret.set_timestamp(timestamp);
    ret.set_zerotimestamp(zeroTimestamp);
    ret.set_data(data);
    ret.set_cputotalload(cpuTotalLoad);
    ret.set_cpuprocessload(cpuProcessLoad);
    ret.set_memprocessload(memProcessLoad);
    ret.set_canlibbuildtime(canlibBuildTime);
    ret.set_telemetrybuildtime(telemetryBuildTime);
    *(ret.mutable_camera()) = camera;
    *(ret.mutable_messagespersecond()) = {messagesPerSecond.begin(), messagesPerSecond.end()};
    return ret;
}

std::string Status::serializeAsJsonString() const {
    PbTelemetry::Status message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Status::serializeAsProtobufString() const {
    PbTelemetry::Status message(*this);
    return message.SerializeAsString();
}

bool Status::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Status message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Status::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Status message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}