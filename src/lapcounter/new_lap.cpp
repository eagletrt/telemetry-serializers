#include "lapcounter/new_lap.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace LapCounter
{
NewLap::NewLap(const PbLapCounter::NewLap& protobuf) {
    timestamp = protobuf.timestamp();
}

NewLap::operator PbLapCounter::NewLap() const {
    PbLapCounter::NewLap ret;
    ret.set_timestamp(timestamp);
    return ret;
}

std::string NewLap::serializeAsJsonString() const {
    PbLapCounter::NewLap protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string NewLap::serializeAsProtobufString() const {
    PbLapCounter::NewLap protobuf(*this);
    return protobuf.SerializeAsString();
}

bool NewLap::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::NewLap protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool NewLap::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::NewLap protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}