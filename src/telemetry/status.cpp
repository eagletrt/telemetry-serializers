#include "telemetry/status.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
Message::Message(const TelemetryMessage& proto) {
    deviceName = proto.devicename();
    bitsPerSecond = proto.bitspersecond();
    busLoad = proto.busload();
    count = proto.count();
}

Message::operator TelemetryMessage() const {
    TelemetryMessage ret;
    ret.set_devicename(deviceName);
    ret.set_bitspersecond(bitsPerSecond);
    ret.set_busload(busLoad);
    ret.set_count(count);
    return ret;
}

std::string Message::serializeAsJsonString() const {
    TelemetryMessage proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Message::serializeAsProtobufString() const {
    TelemetryMessage proto(*this);
    return proto.SerializeAsString();
}

bool Message::deserializeFromJsonString(const std::string& str) {
    TelemetryMessage proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Message::deserializeFromProtobufString(const std::string& str) {
    TelemetryMessage proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Camera::Camera(const TelemetryCamera& proto) {
    status = proto.status();
    error = proto.error();
}

Camera::operator TelemetryCamera() const {
    TelemetryCamera ret;
    ret.set_status(status);
    ret.set_error(error);
    return ret;
}

std::string Camera::serializeAsJsonString() const {
    TelemetryCamera proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Camera::serializeAsProtobufString() const {
    TelemetryCamera proto(*this);
    return proto.SerializeAsString();
}

bool Camera::deserializeFromJsonString(const std::string& str) {
    TelemetryCamera proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Camera::deserializeFromProtobufString(const std::string& str) {
    TelemetryCamera proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Status::Status(const TelemetryStatus& proto) {
    timestamp = proto.timestamp();
    zeroTimestamp = proto.zerotimestamp();
    cpuTotalLoad = proto.cputotalload();
    cpuProcessLoad = proto.cpuprocessload();
    memProcessLoad = proto.memprocessload();
    canlibVersion = proto.canlibversion();
    camera = proto.camera();
    messages = {proto.messages().begin(), proto.messages().end()};
}

Status::operator TelemetryStatus() const {
    TelemetryStatus ret;
    ret.set_timestamp(timestamp);
    ret.set_zerotimestamp(zeroTimestamp);
    ret.set_cputotalload(cpuTotalLoad);
    ret.set_cpuprocessload(cpuProcessLoad);
    ret.set_memprocessload(memProcessLoad);
    ret.set_canlibversion(canlibVersion);
    *(ret.mutable_camera()) = camera;
    *(ret.mutable_messages()) = {messages.begin(), messages.end()};
    return ret;
}

std::string Status::serializeAsJsonString() const {
    TelemetryStatus proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Status::serializeAsProtobufString() const {
    TelemetryStatus proto(*this);
    return proto.SerializeAsString();
}

bool Status::deserializeFromJsonString(const std::string& str) {
    TelemetryStatus proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Status::deserializeFromProtobufString(const std::string& str) {
    TelemetryStatus proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}