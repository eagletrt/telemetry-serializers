#include "mongodb/lapcounter_layout.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace MongoDb
{
Vec2::Vec2(const PbMongoDb::Vec2& protobuf) {
    x = protobuf.x();
    y = protobuf.y();
}

Vec2::operator PbMongoDb::Vec2() const {
    PbMongoDb::Vec2 ret;
    ret.set_x(x);
    ret.set_y(y);
    return ret;
}

std::string Vec2::serializeAsJsonString() const {
    PbMongoDb::Vec2 protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Vec2::serializeAsProtobufString() const {
    PbMongoDb::Vec2 protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Vec2::deserializeFromJsonString(const std::string& str) {
    PbMongoDb::Vec2 protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Vec2::deserializeFromProtobufString(const std::string& str) {
    PbMongoDb::Vec2 protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

PositionAndDirection::PositionAndDirection(const PbMongoDb::PositionAndDirection& protobuf) {
    position = protobuf.position();
    direction = protobuf.direction();
}

PositionAndDirection::operator PbMongoDb::PositionAndDirection() const {
    PbMongoDb::PositionAndDirection ret;
    *(ret.mutable_position()) = position;
    *(ret.mutable_direction()) = direction;
    return ret;
}

std::string PositionAndDirection::serializeAsJsonString() const {
    PbMongoDb::PositionAndDirection protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string PositionAndDirection::serializeAsProtobufString() const {
    PbMongoDb::PositionAndDirection protobuf(*this);
    return protobuf.SerializeAsString();
}

bool PositionAndDirection::deserializeFromJsonString(const std::string& str) {
    PbMongoDb::PositionAndDirection protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool PositionAndDirection::deserializeFromProtobufString(const std::string& str) {
    PbMongoDb::PositionAndDirection protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Layout::Layout(const PbMongoDb::Layout& protobuf) {
    version = protobuf.version();
    baseline_version = protobuf.baseline_version();
    vehicle_id = protobuf.vehicle_id();
    device_id = protobuf.device_id();
    location = protobuf.location();
    layout = protobuf.layout();
    start_line = protobuf.start_line();
    finish_line = protobuf.finish_line();
    sectors = {protobuf.sectors().begin(), protobuf.sectors().end()};
}

Layout::operator PbMongoDb::Layout() const {
    PbMongoDb::Layout ret;
    ret.set_version(version);
    ret.set_baseline_version(baseline_version);
    ret.set_vehicle_id(vehicle_id);
    ret.set_device_id(device_id);
    ret.set_location(location);
    ret.set_layout(layout);
    *(ret.mutable_start_line()) = start_line;
    *(ret.mutable_finish_line()) = finish_line;
    *(ret.mutable_sectors()) = {sectors.begin(), sectors.end()};
    return ret;
}

std::string Layout::serializeAsJsonString() const {
    PbMongoDb::Layout protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Layout::serializeAsProtobufString() const {
    PbMongoDb::Layout protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Layout::deserializeFromJsonString(const std::string& str) {
    PbMongoDb::Layout protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Layout::deserializeFromProtobufString(const std::string& str) {
    PbMongoDb::Layout protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}