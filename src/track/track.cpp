#include "track/track.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Track
{
Baseline::Baseline(const PbTrack::Baseline& protobuf) {
    valid = protobuf.valid();
    logging = protobuf.logging();
    length = protobuf.length();
    x = {protobuf.x().begin(), protobuf.x().end()};
    y = {protobuf.y().begin(), protobuf.y().end()};
    resampled = protobuf.resampled();
    s = {protobuf.s().begin(), protobuf.s().end()};
    theta = {protobuf.theta().begin(), protobuf.theta().end()};
    hash = protobuf.hash();
}

Baseline::operator PbTrack::Baseline() const {
    PbTrack::Baseline ret;
    ret.set_valid(valid);
    ret.set_logging(logging);
    ret.set_length(length);
    *(ret.mutable_x()) = {x.begin(), x.end()};
    *(ret.mutable_y()) = {y.begin(), y.end()};
    ret.set_resampled(resampled);
    *(ret.mutable_s()) = {s.begin(), s.end()};
    *(ret.mutable_theta()) = {theta.begin(), theta.end()};
    ret.set_hash(hash);
    return ret;
}

std::string Baseline::serializeAsJsonString() const {
    PbTrack::Baseline protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Baseline::serializeAsProtobufString() const {
    PbTrack::Baseline protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Baseline::deserializeFromJsonString(const std::string& str) {
    PbTrack::Baseline protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Baseline::deserializeFromProtobufString(const std::string& str) {
    PbTrack::Baseline protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GPSMapOrigin::GPSMapOrigin(const PbTrack::GPSMapOrigin& protobuf) {
    latitude = protobuf.latitude();
    longitude = protobuf.longitude();
    altitude = protobuf.altitude();
}

GPSMapOrigin::operator PbTrack::GPSMapOrigin() const {
    PbTrack::GPSMapOrigin ret;
    ret.set_latitude(latitude);
    ret.set_longitude(longitude);
    ret.set_altitude(altitude);
    return ret;
}

std::string GPSMapOrigin::serializeAsJsonString() const {
    PbTrack::GPSMapOrigin protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GPSMapOrigin::serializeAsProtobufString() const {
    PbTrack::GPSMapOrigin protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GPSMapOrigin::deserializeFromJsonString(const std::string& str) {
    PbTrack::GPSMapOrigin protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GPSMapOrigin::deserializeFromProtobufString(const std::string& str) {
    PbTrack::GPSMapOrigin protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GPSMapOrigins::GPSMapOrigins(const PbTrack::GPSMapOrigins& protobuf) {
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    origins = {protobuf.origins().begin(), protobuf.origins().end()};
    tracksBaseline = {protobuf.tracksbaseline().begin(), protobuf.tracksbaseline().end()};
}

GPSMapOrigins::operator PbTrack::GPSMapOrigins() const {
    PbTrack::GPSMapOrigins ret;
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    *(ret.mutable_origins()) = {origins.begin(), origins.end()};
    *(ret.mutable_tracksbaseline()) = {tracksBaseline.begin(), tracksBaseline.end()};
    return ret;
}

std::string GPSMapOrigins::serializeAsJsonString() const {
    PbTrack::GPSMapOrigins protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GPSMapOrigins::serializeAsProtobufString() const {
    PbTrack::GPSMapOrigins protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GPSMapOrigins::deserializeFromJsonString(const std::string& str) {
    PbTrack::GPSMapOrigins protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GPSMapOrigins::deserializeFromProtobufString(const std::string& str) {
    PbTrack::GPSMapOrigins protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SetBaseline::SetBaseline(const PbTrack::SetBaseline& protobuf) {
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    origin = protobuf.origin();
    x = {protobuf.x().begin(), protobuf.x().end()};
    y = {protobuf.y().begin(), protobuf.y().end()};
}

SetBaseline::operator PbTrack::SetBaseline() const {
    PbTrack::SetBaseline ret;
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    *(ret.mutable_origin()) = origin;
    *(ret.mutable_x()) = {x.begin(), x.end()};
    *(ret.mutable_y()) = {y.begin(), y.end()};
    return ret;
}

std::string SetBaseline::serializeAsJsonString() const {
    PbTrack::SetBaseline protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SetBaseline::serializeAsProtobufString() const {
    PbTrack::SetBaseline protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SetBaseline::deserializeFromJsonString(const std::string& str) {
    PbTrack::SetBaseline protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SetBaseline::deserializeFromProtobufString(const std::string& str) {
    PbTrack::SetBaseline protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapRecord::LapRecord(const PbTrack::LapRecord& protobuf) {
    driver = protobuf.driver();
    start = protobuf.start();
    end = protobuf.end();
    sectors = {protobuf.sectors().begin(), protobuf.sectors().end()};
}

LapRecord::operator PbTrack::LapRecord() const {
    PbTrack::LapRecord ret;
    ret.set_driver(driver);
    ret.set_start(start);
    ret.set_end(end);
    *(ret.mutable_sectors()) = {sectors.begin(), sectors.end()};
    return ret;
}

std::string LapRecord::serializeAsJsonString() const {
    PbTrack::LapRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapRecord::serializeAsProtobufString() const {
    PbTrack::LapRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapRecord::deserializeFromJsonString(const std::string& str) {
    PbTrack::LapRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapRecord::deserializeFromProtobufString(const std::string& str) {
    PbTrack::LapRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SectorsRecord::SectorsRecord(const PbTrack::SectorsRecord& protobuf) {
    driver = protobuf.driver();
    start_time_sector = protobuf.start_time_sector();
    end_time_sector = protobuf.end_time_sector();
}

SectorsRecord::operator PbTrack::SectorsRecord() const {
    PbTrack::SectorsRecord ret;
    ret.set_driver(driver);
    ret.set_start_time_sector(start_time_sector);
    ret.set_end_time_sector(end_time_sector);
    return ret;
}

std::string SectorsRecord::serializeAsJsonString() const {
    PbTrack::SectorsRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SectorsRecord::serializeAsProtobufString() const {
    PbTrack::SectorsRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SectorsRecord::deserializeFromJsonString(const std::string& str) {
    PbTrack::SectorsRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SectorsRecord::deserializeFromProtobufString(const std::string& str) {
    PbTrack::SectorsRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

DriverRecord::DriverRecord(const PbTrack::DriverRecord& protobuf) {
    driver = protobuf.driver();
    best_lap = protobuf.best_lap();
    best_sectors = {protobuf.best_sectors().begin(), protobuf.best_sectors().end()};
}

DriverRecord::operator PbTrack::DriverRecord() const {
    PbTrack::DriverRecord ret;
    ret.set_driver(driver);
    *(ret.mutable_best_lap()) = best_lap;
    *(ret.mutable_best_sectors()) = {best_sectors.begin(), best_sectors.end()};
    return ret;
}

std::string DriverRecord::serializeAsJsonString() const {
    PbTrack::DriverRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string DriverRecord::serializeAsProtobufString() const {
    PbTrack::DriverRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool DriverRecord::deserializeFromJsonString(const std::string& str) {
    PbTrack::DriverRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool DriverRecord::deserializeFromProtobufString(const std::string& str) {
    PbTrack::DriverRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapTime::LapTime(const PbTrack::LapTime& protobuf) {
    number = protobuf.number();
    start_timestamp = protobuf.start_timestamp();
    end_timestamp = protobuf.end_timestamp();
    sectors = {protobuf.sectors().begin(), protobuf.sectors().end()};
}

LapTime::operator PbTrack::LapTime() const {
    PbTrack::LapTime ret;
    ret.set_number(number);
    ret.set_start_timestamp(start_timestamp);
    ret.set_end_timestamp(end_timestamp);
    *(ret.mutable_sectors()) = {sectors.begin(), sectors.end()};
    return ret;
}

std::string LapTime::serializeAsJsonString() const {
    PbTrack::LapTime protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapTime::serializeAsProtobufString() const {
    PbTrack::LapTime protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapTime::deserializeFromJsonString(const std::string& str) {
    PbTrack::LapTime protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapTime::deserializeFromProtobufString(const std::string& str) {
    PbTrack::LapTime protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapTimes::LapTimes(const PbTrack::LapTimes& protobuf) {
    version = protobuf.version();
    baseline_version = protobuf.baseline_version();
    vehicle_id = protobuf.vehicle_id();
    device_id = protobuf.device_id();
    location = protobuf.location();
    layout = protobuf.layout();
    driver = protobuf.driver();
    times = {protobuf.times().begin(), protobuf.times().end()};
    baseline_hash = protobuf.baseline_hash();
    session_start_timestamp = protobuf.session_start_timestamp();
    session_name = protobuf.session_name();
}

LapTimes::operator PbTrack::LapTimes() const {
    PbTrack::LapTimes ret;
    ret.set_version(version);
    ret.set_baseline_version(baseline_version);
    ret.set_vehicle_id(vehicle_id);
    ret.set_device_id(device_id);
    ret.set_location(location);
    ret.set_layout(layout);
    ret.set_driver(driver);
    *(ret.mutable_times()) = {times.begin(), times.end()};
    ret.set_baseline_hash(baseline_hash);
    ret.set_session_start_timestamp(session_start_timestamp);
    ret.set_session_name(session_name);
    return ret;
}

std::string LapTimes::serializeAsJsonString() const {
    PbTrack::LapTimes protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapTimes::serializeAsProtobufString() const {
    PbTrack::LapTimes protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapTimes::deserializeFromJsonString(const std::string& str) {
    PbTrack::LapTimes protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapTimes::deserializeFromProtobufString(const std::string& str) {
    PbTrack::LapTimes protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Vec2::Vec2(const PbTrack::Vec2& protobuf) {
    x = protobuf.x();
    y = protobuf.y();
}

Vec2::operator PbTrack::Vec2() const {
    PbTrack::Vec2 ret;
    ret.set_x(x);
    ret.set_y(y);
    return ret;
}

std::string Vec2::serializeAsJsonString() const {
    PbTrack::Vec2 protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Vec2::serializeAsProtobufString() const {
    PbTrack::Vec2 protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Vec2::deserializeFromJsonString(const std::string& str) {
    PbTrack::Vec2 protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Vec2::deserializeFromProtobufString(const std::string& str) {
    PbTrack::Vec2 protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

PositionAndDirection::PositionAndDirection(const PbTrack::PositionAndDirection& protobuf) {
    position = protobuf.position();
    direction = protobuf.direction();
}

PositionAndDirection::operator PbTrack::PositionAndDirection() const {
    PbTrack::PositionAndDirection ret;
    *(ret.mutable_position()) = position;
    *(ret.mutable_direction()) = direction;
    return ret;
}

std::string PositionAndDirection::serializeAsJsonString() const {
    PbTrack::PositionAndDirection protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string PositionAndDirection::serializeAsProtobufString() const {
    PbTrack::PositionAndDirection protobuf(*this);
    return protobuf.SerializeAsString();
}

bool PositionAndDirection::deserializeFromJsonString(const std::string& str) {
    PbTrack::PositionAndDirection protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool PositionAndDirection::deserializeFromProtobufString(const std::string& str) {
    PbTrack::PositionAndDirection protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Layout::Layout(const PbTrack::Layout& protobuf) {
    version = protobuf.version();
    baseline_version = protobuf.baseline_version();
    vehicle_id = protobuf.vehicle_id();
    device_id = protobuf.device_id();
    location = protobuf.location();
    layout = protobuf.layout();
    start_line = protobuf.start_line();
    finish_line = protobuf.finish_line();
    sectors = {protobuf.sectors().begin(), protobuf.sectors().end()};
    baseline_hash = protobuf.baseline_hash();
    start_s = protobuf.start_s();
    sectors_s = {protobuf.sectors_s().begin(), protobuf.sectors_s().end()};
    baseline_length = protobuf.baseline_length();
}

Layout::operator PbTrack::Layout() const {
    PbTrack::Layout ret;
    ret.set_version(version);
    ret.set_baseline_version(baseline_version);
    ret.set_vehicle_id(vehicle_id);
    ret.set_device_id(device_id);
    ret.set_location(location);
    ret.set_layout(layout);
    *(ret.mutable_start_line()) = start_line;
    *(ret.mutable_finish_line()) = finish_line;
    *(ret.mutable_sectors()) = {sectors.begin(), sectors.end()};
    ret.set_baseline_hash(baseline_hash);
    ret.set_start_s(start_s);
    *(ret.mutable_sectors_s()) = {sectors_s.begin(), sectors_s.end()};
    ret.set_baseline_length(baseline_length);
    return ret;
}

std::string Layout::serializeAsJsonString() const {
    PbTrack::Layout protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Layout::serializeAsProtobufString() const {
    PbTrack::Layout protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Layout::deserializeFromJsonString(const std::string& str) {
    PbTrack::Layout protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Layout::deserializeFromProtobufString(const std::string& str) {
    PbTrack::Layout protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapRecords::LapRecords(const PbTrack::LapRecords& protobuf) {
    version = protobuf.version();
    baseline_version = protobuf.baseline_version();
    vehicle_id = protobuf.vehicle_id();
    device_id = protobuf.device_id();
    location = protobuf.location();
    layout = protobuf.layout();
    best_lap = protobuf.best_lap();
    best_sectors = {protobuf.best_sectors().begin(), protobuf.best_sectors().end()};
    drivers_records = {protobuf.drivers_records().begin(), protobuf.drivers_records().end()};
    baseline_hash = protobuf.baseline_hash();
    session_start_timestamp = protobuf.session_start_timestamp();
    session_name = protobuf.session_name();
}

LapRecords::operator PbTrack::LapRecords() const {
    PbTrack::LapRecords ret;
    ret.set_version(version);
    ret.set_baseline_version(baseline_version);
    ret.set_vehicle_id(vehicle_id);
    ret.set_device_id(device_id);
    ret.set_location(location);
    ret.set_layout(layout);
    *(ret.mutable_best_lap()) = best_lap;
    *(ret.mutable_best_sectors()) = {best_sectors.begin(), best_sectors.end()};
    *(ret.mutable_drivers_records()) = {drivers_records.begin(), drivers_records.end()};
    ret.set_baseline_hash(baseline_hash);
    ret.set_session_start_timestamp(session_start_timestamp);
    ret.set_session_name(session_name);
    return ret;
}

std::string LapRecords::serializeAsJsonString() const {
    PbTrack::LapRecords protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapRecords::serializeAsProtobufString() const {
    PbTrack::LapRecords protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapRecords::deserializeFromJsonString(const std::string& str) {
    PbTrack::LapRecords protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapRecords::deserializeFromProtobufString(const std::string& str) {
    PbTrack::LapRecords protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Track::Track(const PbTrack::Track& protobuf) {
    layout = protobuf.layout();
    lapTimes = protobuf.laptimes();
    lapRecords = protobuf.laprecords();
    gpsInfo = protobuf.gpsinfo();
}

Track::operator PbTrack::Track() const {
    PbTrack::Track ret;
    *(ret.mutable_layout()) = layout;
    *(ret.mutable_laptimes()) = lapTimes;
    *(ret.mutable_laprecords()) = lapRecords;
    *(ret.mutable_gpsinfo()) = gpsInfo;
    return ret;
}

std::string Track::serializeAsJsonString() const {
    PbTrack::Track protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Track::serializeAsProtobufString() const {
    PbTrack::Track protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Track::deserializeFromJsonString(const std::string& str) {
    PbTrack::Track protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Track::deserializeFromProtobufString(const std::string& str) {
    PbTrack::Track protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}