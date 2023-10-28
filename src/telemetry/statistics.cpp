#include "telemetry/statistics.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
Statistics::Statistics(const TelemetryStatistics& proto) {
    messages = proto.messages();
    averageFrequency = proto.averagefrequency();
    seconds = proto.seconds();
}

Statistics::operator TelemetryStatistics() const {
    TelemetryStatistics ret;
    ret.set_messages(messages);
    ret.set_averagefrequency(averageFrequency);
    ret.set_seconds(seconds);
    return ret;
}

std::string Statistics::serializeAsJsonString() const {
    TelemetryStatistics proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Statistics::serializeAsProtobufString() const {
    TelemetryStatistics proto(*this);
    return proto.SerializeAsString();
}

bool Statistics::deserializeFromJsonString(const std::string& str) {
    TelemetryStatistics proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Statistics::deserializeFromProtobufString(const std::string& str) {
    TelemetryStatistics proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}