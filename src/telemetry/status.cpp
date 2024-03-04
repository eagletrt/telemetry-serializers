#include "telemetry/status.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
MessagesPerSecond::MessagesPerSecond(const PbTelemetry::MessagesPerSecond& protobuf) {
    deviceName = protobuf.devicename();
    bitsPerSecond = protobuf.bitspersecond();
    busLoad = protobuf.busload();
    count = protobuf.count();
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
    PbTelemetry::MessagesPerSecond protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string MessagesPerSecond::serializeAsProtobufString() const {
    PbTelemetry::MessagesPerSecond protobuf(*this);
    return protobuf.SerializeAsString();
}

bool MessagesPerSecond::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::MessagesPerSecond protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool MessagesPerSecond::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::MessagesPerSecond protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Camera::Camera(const PbTelemetry::Camera& protobuf) {
    status = protobuf.status();
    error = protobuf.error();
}

Camera::operator PbTelemetry::Camera() const {
    PbTelemetry::Camera ret;
    ret.set_status(status);
    ret.set_error(error);
    return ret;
}

std::string Camera::serializeAsJsonString() const {
    PbTelemetry::Camera protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Camera::serializeAsProtobufString() const {
    PbTelemetry::Camera protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Camera::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Camera protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Camera::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Camera protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Status::Status(const PbTelemetry::Status& protobuf) {
    timestamp = protobuf.timestamp();
    zeroTimestamp = protobuf.zerotimestamp();
    data = protobuf.data();
    cpuTotalLoad = protobuf.cputotalload();
    cpuProcessLoad = protobuf.cpuprocessload();
    memProcessLoad = protobuf.memprocessload();
    canlibBuildTime = protobuf.canlibbuildtime();
    telemetryBuildTime = protobuf.telemetrybuildtime();
    camera = protobuf.camera();
    messagesPerSecond = {protobuf.messagespersecond().begin(), protobuf.messagespersecond().end()};
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
    PbTelemetry::Status protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Status::serializeAsProtobufString() const {
    PbTelemetry::Status protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Status::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Status protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Status::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Status protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}