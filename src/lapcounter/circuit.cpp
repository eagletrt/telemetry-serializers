#include "lapcounter/circuit.h"

#include <google/protobuf/util/json_util.h>

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
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
}
}