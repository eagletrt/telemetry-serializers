#include "lapcounter/lapcounter.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace LapCounter
{
Vector::Vector(const PbLapCounter::Vector& message) {
    x = message.x();
    y = message.y();
}

Vector::operator PbLapCounter::Vector() const {
    PbLapCounter::Vector ret;
    ret.set_x(x);
    ret.set_y(y);
    return ret;
}

std::string Vector::serializeAsJsonString() const {
    PbLapCounter::Vector message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Vector::serializeAsProtobufString() const {
    PbLapCounter::Vector message(*this);
    return message.SerializeAsString();
}

bool Vector::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Vector message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Vector::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Vector message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Line::Line(const PbLapCounter::Line& message) {
    position = message.position();
    direction = message.direction();
}

Line::operator PbLapCounter::Line() const {
    PbLapCounter::Line ret;
    *(ret.mutable_position()) = position;
    *(ret.mutable_direction()) = direction;
    return ret;
}

std::string Line::serializeAsJsonString() const {
    PbLapCounter::Line message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Line::serializeAsProtobufString() const {
    PbLapCounter::Line message(*this);
    return message.SerializeAsString();
}

bool Line::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Line message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Line::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Line message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Circuit::Circuit(const PbLapCounter::Circuit& message) {
    circuitId = message.circuitid();
    checksLines = {message.checkslines().begin(), message.checkslines().end()};
    sectorsLines = {message.sectorslines().begin(), message.sectorslines().end()};
}

Circuit::operator PbLapCounter::Circuit() const {
    PbLapCounter::Circuit ret;
    ret.set_circuitid(circuitId);
    *(ret.mutable_checkslines()) = {checksLines.begin(), checksLines.end()};
    *(ret.mutable_sectorslines()) = {sectorsLines.begin(), sectorsLines.end()};
    return ret;
}

std::string Circuit::serializeAsJsonString() const {
    PbLapCounter::Circuit message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Circuit::serializeAsProtobufString() const {
    PbLapCounter::Circuit message(*this);
    return message.SerializeAsString();
}

bool Circuit::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Circuit message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Circuit::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Circuit message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Lap::Lap(const PbLapCounter::Lap& message) {
    number = message.number();
    startTimestamp = message.starttimestamp();
    endTimestamp = message.endtimestamp();
    sectorsTimestamps = {message.sectorstimestamps().begin(), message.sectorstimestamps().end()};
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
    PbLapCounter::Lap message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Lap::serializeAsProtobufString() const {
    PbLapCounter::Lap message(*this);
    return message.SerializeAsString();
}

bool Lap::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Lap message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Lap::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Lap message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Race::Race(const PbLapCounter::Race& message) {
    raceId = message.raceid();
    circuitId = message.circuitid();
    driverId = message.driverid();
    laps = {message.laps().begin(), message.laps().end()};
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
    PbLapCounter::Race message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Race::serializeAsProtobufString() const {
    PbLapCounter::Race message(*this);
    return message.SerializeAsString();
}

bool Race::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Race message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Race::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Race message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}