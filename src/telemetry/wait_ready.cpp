#include "telemetry/wait_ready.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Telemetry
{
ReplayReady::ReplayReady(const PbTelemetry::ReplayReady& protobuf) {
    status = static_cast<ReadyStatus>(protobuf.status());
}

ReplayReady::operator PbTelemetry::ReplayReady() const {
    PbTelemetry::ReplayReady ret;
    ret.set_status(static_cast<PbTelemetry::ReadyStatus>(status));
    return ret;
}

std::string ReplayReady::serializeAsJsonString() const {
    PbTelemetry::ReplayReady protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ReplayReady::serializeAsProtobufString() const {
    PbTelemetry::ReplayReady protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ReplayReady::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::ReplayReady protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ReplayReady::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::ReplayReady protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

ReplayStart::ReplayStart(const PbTelemetry::ReplayStart& protobuf) {
    startTimestamp = protobuf.starttimestamp();
}

ReplayStart::operator PbTelemetry::ReplayStart() const {
    PbTelemetry::ReplayStart ret;
    ret.set_starttimestamp(startTimestamp);
    return ret;
}

std::string ReplayStart::serializeAsJsonString() const {
    PbTelemetry::ReplayStart protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ReplayStart::serializeAsProtobufString() const {
    PbTelemetry::ReplayStart protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ReplayStart::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::ReplayStart protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ReplayStart::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::ReplayStart protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}