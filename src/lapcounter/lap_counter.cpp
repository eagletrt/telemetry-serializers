#include "lapcounter/lap_counter.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace LapCounter
{
LcPoint::LcPoint(const PbLapCounter::LcPoint& protobuf) {
    position_x = protobuf.position_x();
    position_y = protobuf.position_y();
    inclination_x = protobuf.inclination_x();
    inclination_y = protobuf.inclination_y();
}

LcPoint::operator PbLapCounter::LcPoint() const {
    PbLapCounter::LcPoint ret;
    ret.set_position_x(position_x);
    ret.set_position_y(position_y);
    ret.set_inclination_x(inclination_x);
    ret.set_inclination_y(inclination_y);
    return ret;
}

std::string LcPoint::serializeAsJsonString() const {
    PbLapCounter::LcPoint protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LcPoint::serializeAsProtobufString() const {
    PbLapCounter::LcPoint protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LcPoint::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::LcPoint protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LcPoint::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::LcPoint protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

TrackLayout::TrackLayout(const PbLapCounter::TrackLayout& protobuf) {
    layout_id = protobuf.layout_id();
    name = protobuf.name();
    start1 = protobuf.start1();
    start2 = protobuf.start2();
    sector_count = protobuf.sector_count();
    sectors = {protobuf.sectors().begin(), protobuf.sectors().end()};
}

TrackLayout::operator PbLapCounter::TrackLayout() const {
    PbLapCounter::TrackLayout ret;
    ret.set_layout_id(layout_id);
    ret.set_name(name);
    *(ret.mutable_start1()) = start1;
    *(ret.mutable_start2()) = start2;
    ret.set_sector_count(sector_count);
    *(ret.mutable_sectors()) = {sectors.begin(), sectors.end()};
    return ret;
}

std::string TrackLayout::serializeAsJsonString() const {
    PbLapCounter::TrackLayout protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string TrackLayout::serializeAsProtobufString() const {
    PbLapCounter::TrackLayout protobuf(*this);
    return protobuf.SerializeAsString();
}

bool TrackLayout::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::TrackLayout protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool TrackLayout::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::TrackLayout protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Time::Time(const PbLapCounter::Time& protobuf) {
    layout_id = protobuf.layout_id();
    lap_number = protobuf.lap_number();
    driver_name = protobuf.driver_name();
    start_timestamp = protobuf.start_timestamp();
    end_timestamp = protobuf.end_timestamp();
    sectors_timestamp = {protobuf.sectors_timestamp().begin(), protobuf.sectors_timestamp().end()};
}

Time::operator PbLapCounter::Time() const {
    PbLapCounter::Time ret;
    ret.set_layout_id(layout_id);
    ret.set_lap_number(lap_number);
    ret.set_driver_name(driver_name);
    ret.set_start_timestamp(start_timestamp);
    ret.set_end_timestamp(end_timestamp);
    *(ret.mutable_sectors_timestamp()) = {sectors_timestamp.begin(), sectors_timestamp.end()};
    return ret;
}

std::string Time::serializeAsJsonString() const {
    PbLapCounter::Time protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Time::serializeAsProtobufString() const {
    PbLapCounter::Time protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Time::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Time protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Time::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Time protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

DriverRecord::DriverRecord(const PbLapCounter::DriverRecord& protobuf) {
    driver = protobuf.driver();
    start_timestamp = protobuf.start_timestamp();
    end_timestamp = protobuf.end_timestamp();
    sectors_timestamp = {protobuf.sectors_timestamp().begin(), protobuf.sectors_timestamp().end()};
}

DriverRecord::operator PbLapCounter::DriverRecord() const {
    PbLapCounter::DriverRecord ret;
    ret.set_driver(driver);
    ret.set_start_timestamp(start_timestamp);
    ret.set_end_timestamp(end_timestamp);
    *(ret.mutable_sectors_timestamp()) = {sectors_timestamp.begin(), sectors_timestamp.end()};
    return ret;
}

std::string DriverRecord::serializeAsJsonString() const {
    PbLapCounter::DriverRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string DriverRecord::serializeAsProtobufString() const {
    PbLapCounter::DriverRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool DriverRecord::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::DriverRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool DriverRecord::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::DriverRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

TrackRecord::TrackRecord(const PbLapCounter::TrackRecord& protobuf) {
    layout_id = protobuf.layout_id();
    lap_number = protobuf.lap_number();
    best_lap = protobuf.best_lap();
    best_sectors = {protobuf.best_sectors().begin(), protobuf.best_sectors().end()};
}

TrackRecord::operator PbLapCounter::TrackRecord() const {
    PbLapCounter::TrackRecord ret;
    ret.set_layout_id(layout_id);
    ret.set_lap_number(lap_number);
    *(ret.mutable_best_lap()) = best_lap;
    *(ret.mutable_best_sectors()) = {best_sectors.begin(), best_sectors.end()};
    return ret;
}

std::string TrackRecord::serializeAsJsonString() const {
    PbLapCounter::TrackRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string TrackRecord::serializeAsProtobufString() const {
    PbLapCounter::TrackRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool TrackRecord::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::TrackRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool TrackRecord::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::TrackRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Driver::Driver(const PbLapCounter::Driver& protobuf) {
    name = protobuf.name();
    times = {protobuf.times().begin(), protobuf.times().end()};
}

Driver::operator PbLapCounter::Driver() const {
    PbLapCounter::Driver ret;
    ret.set_name(name);
    *(ret.mutable_times()) = {times.begin(), times.end()};
    return ret;
}

std::string Driver::serializeAsJsonString() const {
    PbLapCounter::Driver protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Driver::serializeAsProtobufString() const {
    PbLapCounter::Driver protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Driver::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::Driver protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Driver::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::Driver protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

DataBase::DataBase(const PbLapCounter::DataBase& protobuf) {
    layouts = {protobuf.layouts().begin(), protobuf.layouts().end()};
    drivers = {protobuf.drivers().begin(), protobuf.drivers().end()};
    records = {protobuf.records().begin(), protobuf.records().end()};
    last_id = protobuf.last_id();
    lap_number = protobuf.lap_number();
}

DataBase::operator PbLapCounter::DataBase() const {
    PbLapCounter::DataBase ret;
    *(ret.mutable_layouts()) = {layouts.begin(), layouts.end()};
    *(ret.mutable_drivers()) = {drivers.begin(), drivers.end()};
    *(ret.mutable_records()) = {records.begin(), records.end()};
    ret.set_last_id(last_id);
    ret.set_lap_number(lap_number);
    return ret;
}

std::string DataBase::serializeAsJsonString() const {
    PbLapCounter::DataBase protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string DataBase::serializeAsProtobufString() const {
    PbLapCounter::DataBase protobuf(*this);
    return protobuf.SerializeAsString();
}

bool DataBase::deserializeFromJsonString(const std::string& str) {
    PbLapCounter::DataBase protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool DataBase::deserializeFromProtobufString(const std::string& str) {
    PbLapCounter::DataBase protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}