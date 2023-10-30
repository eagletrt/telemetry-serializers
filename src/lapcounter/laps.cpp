#include "lapcounter/laps.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace LapCounter
{
Lap::Lap(const PbLapCounter::Lap& protobuf) {
    timestamp = protobuf.timestamp();
    number = protobuf.number();
    time = protobuf.time();
    sectorTimes = {protobuf.sectortimes().begin(), protobuf.sectortimes().end()};
}

Lap::operator PbLapCounter::Lap() const {
    PbLapCounter::Lap ret;
    ret.set_timestamp(timestamp);
    ret.set_number(number);
    ret.set_time(time);
    *(ret.mutable_sectortimes()) = {sectorTimes.begin(), sectorTimes.end()};
    return ret;
}

std::string Lap::serializeAsJsonString() const {
    PbLapCounter::Lap protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Lap::serializeAsProtobufString() const {
    PbLapCounter::Lap protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Lap::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Lap protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Lap::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Lap protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Laps::Laps(const PbLapCounter::Laps& protobuf) {
    laps = {protobuf.laps().begin(), protobuf.laps().end()};
}

Laps::operator PbLapCounter::Laps() const {
    PbLapCounter::Laps ret;
    *(ret.mutable_laps()) = {laps.begin(), laps.end()};
    return ret;
}

std::string Laps::serializeAsJsonString() const {
    PbLapCounter::Laps protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Laps::serializeAsProtobufString() const {
    PbLapCounter::Laps protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Laps::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Laps protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Laps::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Laps protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}