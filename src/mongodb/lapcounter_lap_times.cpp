#include "mongodb/lapcounter_lap_times.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace MongoDb
{
LapTime::LapTime(const PbMongoDb::LapTime& protobuf) {
    number = protobuf.number();
    start_timestamp = protobuf.start_timestamp();
    end_timestamp = protobuf.end_timestamp();
    sectors = {protobuf.sectors().begin(), protobuf.sectors().end()};
}

LapTime::operator PbMongoDb::LapTime() const {
    PbMongoDb::LapTime ret;
    ret.set_number(number);
    ret.set_start_timestamp(start_timestamp);
    ret.set_end_timestamp(end_timestamp);
    *(ret.mutable_sectors()) = {sectors.begin(), sectors.end()};
    return ret;
}

std::string LapTime::serializeAsJsonString() const {
    PbMongoDb::LapTime protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapTime::serializeAsProtobufString() const {
    PbMongoDb::LapTime protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapTime::deserializeFromJsonString(const std::string& str) {
    PbMongoDb::LapTime protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapTime::deserializeFromProtobufString(const std::string& str) {
    PbMongoDb::LapTime protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapTimes::LapTimes(const PbMongoDb::LapTimes& protobuf) {
    version = protobuf.version();
    baseline_version = protobuf.baseline_version();
    vehicle_id = protobuf.vehicle_id();
    device_id = protobuf.device_id();
    location = protobuf.location();
    layout = protobuf.layout();
    driver = protobuf.driver();
    times = {protobuf.times().begin(), protobuf.times().end()};
}

LapTimes::operator PbMongoDb::LapTimes() const {
    PbMongoDb::LapTimes ret;
    ret.set_version(version);
    ret.set_baseline_version(baseline_version);
    ret.set_vehicle_id(vehicle_id);
    ret.set_device_id(device_id);
    ret.set_location(location);
    ret.set_layout(layout);
    ret.set_driver(driver);
    *(ret.mutable_times()) = {times.begin(), times.end()};
    return ret;
}

std::string LapTimes::serializeAsJsonString() const {
    PbMongoDb::LapTimes protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapTimes::serializeAsProtobufString() const {
    PbMongoDb::LapTimes protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapTimes::deserializeFromJsonString(const std::string& str) {
    PbMongoDb::LapTimes protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapTimes::deserializeFromProtobufString(const std::string& str) {
    PbMongoDb::LapTimes protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}