#include "lapcounter/circuit.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace LapCounter
{
Vector::Vector(const LapCounterVector& proto) {
    x = proto.x();
    y = proto.y();
}

Vector::operator LapCounterVector() const {
    LapCounterVector ret;
    ret.set_x(x);
    ret.set_y(y);
    return ret;
}

std::string Vector::serializeAsJsonString() const {
    LapCounterVector proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Vector::serializeAsProtobufString() const {
    LapCounterVector proto(*this);
    return proto.SerializeAsString();
}

bool Vector::deserializeFromJsonString(const std::string& str) {
    LapCounterVector proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Vector::deserializeFromProtobufString(const std::string& str) {
    LapCounterVector proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Circuit::Circuit(const LapCounterCircuit& proto) {
    startPosition = proto.startposition();
    startDirection = proto.startdirection();
    sectorsPositions = {proto.sectorspositions().begin(), proto.sectorspositions().end()};
    sectorsDirections = {proto.sectorsdirections().begin(), proto.sectorsdirections().end()};
}

Circuit::operator LapCounterCircuit() const {
    LapCounterCircuit ret;
    *(ret.mutable_startposition()) = startPosition;
    *(ret.mutable_startdirection()) = startDirection;
    *(ret.mutable_sectorspositions()) = {sectorsPositions.begin(), sectorsPositions.end()};
    *(ret.mutable_sectorsdirections()) = {sectorsDirections.begin(), sectorsDirections.end()};
    return ret;
}

std::string Circuit::serializeAsJsonString() const {
    LapCounterCircuit proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Circuit::serializeAsProtobufString() const {
    LapCounterCircuit proto(*this);
    return proto.SerializeAsString();
}

bool Circuit::deserializeFromJsonString(const std::string& str) {
    LapCounterCircuit proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Circuit::deserializeFromProtobufString(const std::string& str) {
    LapCounterCircuit proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}