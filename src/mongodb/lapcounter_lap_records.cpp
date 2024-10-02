#include "mongodb/lapcounter_lap_records.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace MongoDb
{
LapRecord::LapRecord(const PbMongoDb::LapRecord& protobuf) {
    driver = protobuf.driver();
    start = protobuf.start();
    end = protobuf.end();
    sectors = {protobuf.sectors().begin(), protobuf.sectors().end()};
}

LapRecord::operator PbMongoDb::LapRecord() const {
    PbMongoDb::LapRecord ret;
    ret.set_driver(driver);
    ret.set_start(start);
    ret.set_end(end);
    *(ret.mutable_sectors()) = {sectors.begin(), sectors.end()};
    return ret;
}

std::string LapRecord::serializeAsJsonString() const {
    PbMongoDb::LapRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapRecord::serializeAsProtobufString() const {
    PbMongoDb::LapRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapRecord::deserializeFromJsonString(const std::string& str) {
    PbMongoDb::LapRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapRecord::deserializeFromProtobufString(const std::string& str) {
    PbMongoDb::LapRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SectorsRecord::SectorsRecord(const PbMongoDb::SectorsRecord& protobuf) {
    driver = protobuf.driver();
    start_time_sector = protobuf.start_time_sector();
    end_time_sector = protobuf.end_time_sector();
}

SectorsRecord::operator PbMongoDb::SectorsRecord() const {
    PbMongoDb::SectorsRecord ret;
    ret.set_driver(driver);
    ret.set_start_time_sector(start_time_sector);
    ret.set_end_time_sector(end_time_sector);
    return ret;
}

std::string SectorsRecord::serializeAsJsonString() const {
    PbMongoDb::SectorsRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SectorsRecord::serializeAsProtobufString() const {
    PbMongoDb::SectorsRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SectorsRecord::deserializeFromJsonString(const std::string& str) {
    PbMongoDb::SectorsRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SectorsRecord::deserializeFromProtobufString(const std::string& str) {
    PbMongoDb::SectorsRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

DriverRecord::DriverRecord(const PbMongoDb::DriverRecord& protobuf) {
    driver = protobuf.driver();
    best_lap = protobuf.best_lap();
    best_sectors = {protobuf.best_sectors().begin(), protobuf.best_sectors().end()};
}

DriverRecord::operator PbMongoDb::DriverRecord() const {
    PbMongoDb::DriverRecord ret;
    ret.set_driver(driver);
    *(ret.mutable_best_lap()) = best_lap;
    *(ret.mutable_best_sectors()) = {best_sectors.begin(), best_sectors.end()};
    return ret;
}

std::string DriverRecord::serializeAsJsonString() const {
    PbMongoDb::DriverRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string DriverRecord::serializeAsProtobufString() const {
    PbMongoDb::DriverRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool DriverRecord::deserializeFromJsonString(const std::string& str) {
    PbMongoDb::DriverRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool DriverRecord::deserializeFromProtobufString(const std::string& str) {
    PbMongoDb::DriverRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapRecords::LapRecords(const PbMongoDb::LapRecords& protobuf) {
    version = protobuf.version();
    baseline_version = protobuf.baseline_version();
    vehicle_id = protobuf.vehicle_id();
    device_id = protobuf.device_id();
    location = protobuf.location();
    layout = protobuf.layout();
    best_lap = protobuf.best_lap();
    best_sectors = {protobuf.best_sectors().begin(), protobuf.best_sectors().end()};
    drivers_records = {protobuf.drivers_records().begin(), protobuf.drivers_records().end()};
}

LapRecords::operator PbMongoDb::LapRecords() const {
    PbMongoDb::LapRecords ret;
    ret.set_version(version);
    ret.set_baseline_version(baseline_version);
    ret.set_vehicle_id(vehicle_id);
    ret.set_device_id(device_id);
    ret.set_location(location);
    ret.set_layout(layout);
    *(ret.mutable_best_lap()) = best_lap;
    *(ret.mutable_best_sectors()) = {best_sectors.begin(), best_sectors.end()};
    *(ret.mutable_drivers_records()) = {drivers_records.begin(), drivers_records.end()};
    return ret;
}

std::string LapRecords::serializeAsJsonString() const {
    PbMongoDb::LapRecords protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapRecords::serializeAsProtobufString() const {
    PbMongoDb::LapRecords protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapRecords::deserializeFromJsonString(const std::string& str) {
    PbMongoDb::LapRecords protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapRecords::deserializeFromProtobufString(const std::string& str) {
    PbMongoDb::LapRecords protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}