#include "lapcounter/lapcounter.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace LapCounter
{
Vector::Vector(const PbLapCounter::Vector& protobuf) {
    x = protobuf.x();
    y = protobuf.y();
}

Vector::operator PbLapCounter::Vector() const {
    PbLapCounter::Vector ret;
    ret.set_x(x);
    ret.set_y(y);
    return ret;
}

std::string Vector::serializeAsJsonString() const {
    PbLapCounter::Vector protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Vector::serializeAsProtobufString() const {
    PbLapCounter::Vector protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Vector::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Vector protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Vector::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Vector protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Line::Line(const PbLapCounter::Line& protobuf) {
    position = protobuf.position();
    direction = protobuf.direction();
}

Line::operator PbLapCounter::Line() const {
    PbLapCounter::Line ret;
    *(ret.mutable_position()) = position;
    *(ret.mutable_direction()) = direction;
    return ret;
}

std::string Line::serializeAsJsonString() const {
    PbLapCounter::Line protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Line::serializeAsProtobufString() const {
    PbLapCounter::Line protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Line::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Line protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Line::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Line protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Circuit::Circuit(const PbLapCounter::Circuit& protobuf) {
    circuitId = protobuf.circuitid();
    checksLines = {protobuf.checkslines().begin(), protobuf.checkslines().end()};
    sectorsLines = {protobuf.sectorslines().begin(), protobuf.sectorslines().end()};
}

Circuit::operator PbLapCounter::Circuit() const {
    PbLapCounter::Circuit ret;
    ret.set_circuitid(circuitId);
    *(ret.mutable_checkslines()) = {checksLines.begin(), checksLines.end()};
    *(ret.mutable_sectorslines()) = {sectorsLines.begin(), sectorsLines.end()};
    return ret;
}

std::string Circuit::serializeAsJsonString() const {
    PbLapCounter::Circuit protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Circuit::serializeAsProtobufString() const {
    PbLapCounter::Circuit protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Circuit::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Circuit protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Circuit::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Circuit protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

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
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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