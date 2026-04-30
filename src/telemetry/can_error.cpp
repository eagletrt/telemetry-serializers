#include "telemetry/can_error.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Telemetry
{
Invalid_can_id::Invalid_can_id(const PbTelemetry::Invalid_can_id& protobuf) {
    timestamp = protobuf.timestamp();
    id = protobuf.id();
    payload = {protobuf.payload().begin(), protobuf.payload().end()};
}

Invalid_can_id::operator PbTelemetry::Invalid_can_id() const {
    PbTelemetry::Invalid_can_id ret;
    ret.set_timestamp(timestamp);
    ret.set_id(id);
    *(ret.mutable_payload()) = {payload.begin(), payload.end()};
    return ret;
}

std::string Invalid_can_id::serializeAsJsonString() const {
    PbTelemetry::Invalid_can_id protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Invalid_can_id::serializeAsProtobufString() const {
    PbTelemetry::Invalid_can_id protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Invalid_can_id::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Invalid_can_id protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Invalid_can_id::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Invalid_can_id protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}