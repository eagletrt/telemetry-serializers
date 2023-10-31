#include "lapcounter/race.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace LapCounter
{
Lap::Lap(const PbLapCounter::Lap& protobuf) {
    number = protobuf.number();
    startTimestamp = protobuf.starttimestamp();
    endTimestamp = protobuf.endtimestamp();
    sectorsTimestamps = {protobuf.sectorstimestamps().begin(), protobuf.sectorstimestamps().end()};
}

Lap::operator PbLapCounter::Lap() const {
    PbLapCounter::Lap ret;
    ret.set_number(number);
    ret.set_starttimestamp(startTimestamp);
    ret.set_endtimestamp(endTimestamp);
    *(ret.mutable_sectorstimestamps()) = {sectorsTimestamps.begin(), sectorsTimestamps.end()};
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

Race::Race(const PbLapCounter::Race& protobuf) {
    raceId = protobuf.raceid();
    circuitId = protobuf.circuitid();
    driverId = protobuf.driverid();
    laps = {protobuf.laps().begin(), protobuf.laps().end()};
}

Race::operator PbLapCounter::Race() const {
    PbLapCounter::Race ret;
    ret.set_raceid(raceId);
    ret.set_circuitid(circuitId);
    ret.set_driverid(driverId);
    *(ret.mutable_laps()) = {laps.begin(), laps.end()};
    return ret;
}

std::string Race::serializeAsJsonString() const {
    PbLapCounter::Race protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Race::serializeAsProtobufString() const {
    PbLapCounter::Race protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Race::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Race protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Race::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Race protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}