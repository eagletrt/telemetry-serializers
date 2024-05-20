#include "telemetry/baseline.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
Baseline::Baseline(const PbTelemetry::Baseline& protobuf) {
    xs = {protobuf.xs().begin(), protobuf.xs().end()};
    ys = {protobuf.ys().begin(), protobuf.ys().end()};
}

Baseline::operator PbTelemetry::Baseline() const {
    PbTelemetry::Baseline ret;
    *(ret.mutable_xs()) = {xs.begin(), xs.end()};
    *(ret.mutable_ys()) = {ys.begin(), ys.end()};
    return ret;
}

std::string Baseline::serializeAsJsonString() const {
    PbTelemetry::Baseline protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Baseline::serializeAsProtobufString() const {
    PbTelemetry::Baseline protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Baseline::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Baseline protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Baseline::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Baseline protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}