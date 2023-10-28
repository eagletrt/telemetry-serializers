#include "lapcounter/laps.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace LapCounter
{
Lap::Lap(const LapCounterLap& proto) {
    timestamp = proto.timestamp();
    number = proto.number();
    time = proto.time();
    sectorTimes = {proto.sectortimes().begin(), proto.sectortimes().end()};
}

Lap::operator LapCounterLap() const {
    LapCounterLap ret;
    ret.set_timestamp(timestamp);
    ret.set_number(number);
    ret.set_time(time);
    *(ret.mutable_sectortimes()) = {sectorTimes.begin(), sectorTimes.end()};
    return ret;
}

std::string Lap::serializeAsJsonString() const {
    LapCounterLap proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Lap::serializeAsProtobufString() const {
    LapCounterLap proto(*this);
    return proto.SerializeAsString();
}

bool Lap::deserializeFromJsonString(const std::string& str) {
    LapCounterLap proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Lap::deserializeFromProtobufString(const std::string& str) {
    LapCounterLap proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Laps::Laps(const LapCounterLaps& proto) {
    laps = {proto.laps().begin(), proto.laps().end()};
}

Laps::operator LapCounterLaps() const {
    LapCounterLaps ret;
    *(ret.mutable_laps()) = {laps.begin(), laps.end()};
    return ret;
}

std::string Laps::serializeAsJsonString() const {
    LapCounterLaps proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Laps::serializeAsProtobufString() const {
    LapCounterLaps proto(*this);
    return proto.SerializeAsString();
}

bool Laps::deserializeFromJsonString(const std::string& str) {
    LapCounterLaps proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Laps::deserializeFromProtobufString(const std::string& str) {
    LapCounterLaps proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}