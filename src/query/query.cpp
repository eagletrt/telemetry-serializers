#include "query/query.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace query
{
Weather::Weather(const Pbquery::Weather& protobuf) {
    ambientTemperature = protobuf.ambienttemperature();
    trackTemperature = protobuf.tracktemperature();
    humidity = protobuf.humidity();
}

Weather::operator Pbquery::Weather() const {
    Pbquery::Weather ret;
    ret.set_ambienttemperature(ambientTemperature);
    ret.set_tracktemperature(trackTemperature);
    ret.set_humidity(humidity);
    return ret;
}

std::string Weather::serializeAsJsonString() const {
    Pbquery::Weather protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Weather::serializeAsProtobufString() const {
    Pbquery::Weather protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Weather::deserializeFromJsonString(const std::string& str) {
    Pbquery::Weather protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Weather::deserializeFromProtobufString(const std::string& str) {
    Pbquery::Weather protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionConfig::SessionConfig(const Pbquery::SessionConfig& protobuf) {
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    sessionName = protobuf.sessionname();
    driver = protobuf.driver();
    date = protobuf.date();
    time = protobuf.time();
    weather = protobuf.weather();
    notes = protobuf.notes();
    canlibVersion = protobuf.canlibversion();
    startTimestamp = protobuf.starttimestamp();
    endTimestamp = protobuf.endtimestamp();
}

SessionConfig::operator Pbquery::SessionConfig() const {
    Pbquery::SessionConfig ret;
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    ret.set_sessionname(sessionName);
    ret.set_driver(driver);
    ret.set_date(date);
    ret.set_time(time);
    *(ret.mutable_weather()) = weather;
    ret.set_notes(notes);
    ret.set_canlibversion(canlibVersion);
    ret.set_starttimestamp(startTimestamp);
    ret.set_endtimestamp(endTimestamp);
    return ret;
}

std::string SessionConfig::serializeAsJsonString() const {
    Pbquery::SessionConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionConfig::serializeAsProtobufString() const {
    Pbquery::SessionConfig protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionConfig::deserializeFromJsonString(const std::string& str) {
    Pbquery::SessionConfig protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionConfig::deserializeFromProtobufString(const std::string& str) {
    Pbquery::SessionConfig protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Baseline::Baseline(const Pbquery::Baseline& protobuf) {
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

Baseline::operator Pbquery::Baseline() const {
    Pbquery::Baseline ret;
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
    Pbquery::Baseline protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Baseline::serializeAsProtobufString() const {
    Pbquery::Baseline protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Baseline::deserializeFromJsonString(const std::string& str) {
    Pbquery::Baseline protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Baseline::deserializeFromProtobufString(const std::string& str) {
    Pbquery::Baseline protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GPSMapOrigin::GPSMapOrigin(const Pbquery::GPSMapOrigin& protobuf) {
    latitude = protobuf.latitude();
    longitude = protobuf.longitude();
    altitude = protobuf.altitude();
}

GPSMapOrigin::operator Pbquery::GPSMapOrigin() const {
    Pbquery::GPSMapOrigin ret;
    ret.set_latitude(latitude);
    ret.set_longitude(longitude);
    ret.set_altitude(altitude);
    return ret;
}

std::string GPSMapOrigin::serializeAsJsonString() const {
    Pbquery::GPSMapOrigin protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GPSMapOrigin::serializeAsProtobufString() const {
    Pbquery::GPSMapOrigin protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GPSMapOrigin::deserializeFromJsonString(const std::string& str) {
    Pbquery::GPSMapOrigin protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GPSMapOrigin::deserializeFromProtobufString(const std::string& str) {
    Pbquery::GPSMapOrigin protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GPSMapOrigins::GPSMapOrigins(const Pbquery::GPSMapOrigins& protobuf) {
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    origins = {protobuf.origins().begin(), protobuf.origins().end()};
    tracksBaseline = {protobuf.tracksbaseline().begin(), protobuf.tracksbaseline().end()};
}

GPSMapOrigins::operator Pbquery::GPSMapOrigins() const {
    Pbquery::GPSMapOrigins ret;
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    *(ret.mutable_origins()) = {origins.begin(), origins.end()};
    *(ret.mutable_tracksbaseline()) = {tracksBaseline.begin(), tracksBaseline.end()};
    return ret;
}

std::string GPSMapOrigins::serializeAsJsonString() const {
    Pbquery::GPSMapOrigins protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GPSMapOrigins::serializeAsProtobufString() const {
    Pbquery::GPSMapOrigins protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GPSMapOrigins::deserializeFromJsonString(const std::string& str) {
    Pbquery::GPSMapOrigins protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GPSMapOrigins::deserializeFromProtobufString(const std::string& str) {
    Pbquery::GPSMapOrigins protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SetBaseline::SetBaseline(const Pbquery::SetBaseline& protobuf) {
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    origin = protobuf.origin();
    x = {protobuf.x().begin(), protobuf.x().end()};
    y = {protobuf.y().begin(), protobuf.y().end()};
}

SetBaseline::operator Pbquery::SetBaseline() const {
    Pbquery::SetBaseline ret;
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    *(ret.mutable_origin()) = origin;
    *(ret.mutable_x()) = {x.begin(), x.end()};
    *(ret.mutable_y()) = {y.begin(), y.end()};
    return ret;
}

std::string SetBaseline::serializeAsJsonString() const {
    Pbquery::SetBaseline protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SetBaseline::serializeAsProtobufString() const {
    Pbquery::SetBaseline protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SetBaseline::deserializeFromJsonString(const std::string& str) {
    Pbquery::SetBaseline protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SetBaseline::deserializeFromProtobufString(const std::string& str) {
    Pbquery::SetBaseline protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapRecord::LapRecord(const Pbquery::LapRecord& protobuf) {
    driver = protobuf.driver();
    start = protobuf.start();
    end = protobuf.end();
    sectors = {protobuf.sectors().begin(), protobuf.sectors().end()};
}

LapRecord::operator Pbquery::LapRecord() const {
    Pbquery::LapRecord ret;
    ret.set_driver(driver);
    ret.set_start(start);
    ret.set_end(end);
    *(ret.mutable_sectors()) = {sectors.begin(), sectors.end()};
    return ret;
}

std::string LapRecord::serializeAsJsonString() const {
    Pbquery::LapRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapRecord::serializeAsProtobufString() const {
    Pbquery::LapRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapRecord::deserializeFromJsonString(const std::string& str) {
    Pbquery::LapRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapRecord::deserializeFromProtobufString(const std::string& str) {
    Pbquery::LapRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SectorsRecord::SectorsRecord(const Pbquery::SectorsRecord& protobuf) {
    driver = protobuf.driver();
    start_time_sector = protobuf.start_time_sector();
    end_time_sector = protobuf.end_time_sector();
}

SectorsRecord::operator Pbquery::SectorsRecord() const {
    Pbquery::SectorsRecord ret;
    ret.set_driver(driver);
    ret.set_start_time_sector(start_time_sector);
    ret.set_end_time_sector(end_time_sector);
    return ret;
}

std::string SectorsRecord::serializeAsJsonString() const {
    Pbquery::SectorsRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SectorsRecord::serializeAsProtobufString() const {
    Pbquery::SectorsRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SectorsRecord::deserializeFromJsonString(const std::string& str) {
    Pbquery::SectorsRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SectorsRecord::deserializeFromProtobufString(const std::string& str) {
    Pbquery::SectorsRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

DriverRecord::DriverRecord(const Pbquery::DriverRecord& protobuf) {
    driver = protobuf.driver();
    best_lap = protobuf.best_lap();
    best_sectors = {protobuf.best_sectors().begin(), protobuf.best_sectors().end()};
}

DriverRecord::operator Pbquery::DriverRecord() const {
    Pbquery::DriverRecord ret;
    ret.set_driver(driver);
    *(ret.mutable_best_lap()) = best_lap;
    *(ret.mutable_best_sectors()) = {best_sectors.begin(), best_sectors.end()};
    return ret;
}

std::string DriverRecord::serializeAsJsonString() const {
    Pbquery::DriverRecord protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string DriverRecord::serializeAsProtobufString() const {
    Pbquery::DriverRecord protobuf(*this);
    return protobuf.SerializeAsString();
}

bool DriverRecord::deserializeFromJsonString(const std::string& str) {
    Pbquery::DriverRecord protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool DriverRecord::deserializeFromProtobufString(const std::string& str) {
    Pbquery::DriverRecord protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapTime::LapTime(const Pbquery::LapTime& protobuf) {
    number = protobuf.number();
    start_timestamp = protobuf.start_timestamp();
    end_timestamp = protobuf.end_timestamp();
    sectors = {protobuf.sectors().begin(), protobuf.sectors().end()};
}

LapTime::operator Pbquery::LapTime() const {
    Pbquery::LapTime ret;
    ret.set_number(number);
    ret.set_start_timestamp(start_timestamp);
    ret.set_end_timestamp(end_timestamp);
    *(ret.mutable_sectors()) = {sectors.begin(), sectors.end()};
    return ret;
}

std::string LapTime::serializeAsJsonString() const {
    Pbquery::LapTime protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapTime::serializeAsProtobufString() const {
    Pbquery::LapTime protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapTime::deserializeFromJsonString(const std::string& str) {
    Pbquery::LapTime protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapTime::deserializeFromProtobufString(const std::string& str) {
    Pbquery::LapTime protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapTimes::LapTimes(const Pbquery::LapTimes& protobuf) {
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

LapTimes::operator Pbquery::LapTimes() const {
    Pbquery::LapTimes ret;
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
    Pbquery::LapTimes protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapTimes::serializeAsProtobufString() const {
    Pbquery::LapTimes protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapTimes::deserializeFromJsonString(const std::string& str) {
    Pbquery::LapTimes protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapTimes::deserializeFromProtobufString(const std::string& str) {
    Pbquery::LapTimes protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Vec2::Vec2(const Pbquery::Vec2& protobuf) {
    x = protobuf.x();
    y = protobuf.y();
}

Vec2::operator Pbquery::Vec2() const {
    Pbquery::Vec2 ret;
    ret.set_x(x);
    ret.set_y(y);
    return ret;
}

std::string Vec2::serializeAsJsonString() const {
    Pbquery::Vec2 protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Vec2::serializeAsProtobufString() const {
    Pbquery::Vec2 protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Vec2::deserializeFromJsonString(const std::string& str) {
    Pbquery::Vec2 protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Vec2::deserializeFromProtobufString(const std::string& str) {
    Pbquery::Vec2 protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

PositionAndDirection::PositionAndDirection(const Pbquery::PositionAndDirection& protobuf) {
    position = protobuf.position();
    direction = protobuf.direction();
}

PositionAndDirection::operator Pbquery::PositionAndDirection() const {
    Pbquery::PositionAndDirection ret;
    *(ret.mutable_position()) = position;
    *(ret.mutable_direction()) = direction;
    return ret;
}

std::string PositionAndDirection::serializeAsJsonString() const {
    Pbquery::PositionAndDirection protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string PositionAndDirection::serializeAsProtobufString() const {
    Pbquery::PositionAndDirection protobuf(*this);
    return protobuf.SerializeAsString();
}

bool PositionAndDirection::deserializeFromJsonString(const std::string& str) {
    Pbquery::PositionAndDirection protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool PositionAndDirection::deserializeFromProtobufString(const std::string& str) {
    Pbquery::PositionAndDirection protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Layout::Layout(const Pbquery::Layout& protobuf) {
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

Layout::operator Pbquery::Layout() const {
    Pbquery::Layout ret;
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
    Pbquery::Layout protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Layout::serializeAsProtobufString() const {
    Pbquery::Layout protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Layout::deserializeFromJsonString(const std::string& str) {
    Pbquery::Layout protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Layout::deserializeFromProtobufString(const std::string& str) {
    Pbquery::Layout protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

LapRecords::LapRecords(const Pbquery::LapRecords& protobuf) {
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

LapRecords::operator Pbquery::LapRecords() const {
    Pbquery::LapRecords ret;
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
    Pbquery::LapRecords protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LapRecords::serializeAsProtobufString() const {
    Pbquery::LapRecords protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LapRecords::deserializeFromJsonString(const std::string& str) {
    Pbquery::LapRecords protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LapRecords::deserializeFromProtobufString(const std::string& str) {
    Pbquery::LapRecords protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Track::Track(const Pbquery::Track& protobuf) {
    layout = protobuf.layout();
    lapTimes = protobuf.laptimes();
    lapRecords = protobuf.laprecords();
    gpsInfo = protobuf.gpsinfo();
}

Track::operator Pbquery::Track() const {
    Pbquery::Track ret;
    *(ret.mutable_layout()) = layout;
    *(ret.mutable_laptimes()) = lapTimes;
    *(ret.mutable_laprecords()) = lapRecords;
    *(ret.mutable_gpsinfo()) = gpsInfo;
    return ret;
}

std::string Track::serializeAsJsonString() const {
    Pbquery::Track protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Track::serializeAsProtobufString() const {
    Pbquery::Track protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Track::deserializeFromJsonString(const std::string& str) {
    Pbquery::Track protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Track::deserializeFromProtobufString(const std::string& str) {
    Pbquery::Track protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionByYearMonth::SessionByYearMonth(const Pbquery::SessionByYearMonth& protobuf) {
    year = protobuf.year();
    month = protobuf.month();
}

SessionByYearMonth::operator Pbquery::SessionByYearMonth() const {
    Pbquery::SessionByYearMonth ret;
    ret.set_year(year);
    ret.set_month(month);
    return ret;
}

std::string SessionByYearMonth::serializeAsJsonString() const {
    Pbquery::SessionByYearMonth protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionByYearMonth::serializeAsProtobufString() const {
    Pbquery::SessionByYearMonth protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionByYearMonth::deserializeFromJsonString(const std::string& str) {
    Pbquery::SessionByYearMonth protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionByYearMonth::deserializeFromProtobufString(const std::string& str) {
    Pbquery::SessionByYearMonth protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionByYearMonthFound::SessionByYearMonthFound(const Pbquery::SessionByYearMonthFound& protobuf) {
    daysFound = {protobuf.daysfound().begin(), protobuf.daysfound().end()};
}

SessionByYearMonthFound::operator Pbquery::SessionByYearMonthFound() const {
    Pbquery::SessionByYearMonthFound ret;
    *(ret.mutable_daysfound()) = {daysFound.begin(), daysFound.end()};
    return ret;
}

std::string SessionByYearMonthFound::serializeAsJsonString() const {
    Pbquery::SessionByYearMonthFound protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionByYearMonthFound::serializeAsProtobufString() const {
    Pbquery::SessionByYearMonthFound protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionByYearMonthFound::deserializeFromJsonString(const std::string& str) {
    Pbquery::SessionByYearMonthFound protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionByYearMonthFound::deserializeFromProtobufString(const std::string& str) {
    Pbquery::SessionByYearMonthFound protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionByDayRange::SessionByDayRange(const Pbquery::SessionByDayRange& protobuf) {
    yearMonth = protobuf.yearmonth();
    startDay = protobuf.startday();
    endDay = protobuf.endday();
}

SessionByDayRange::operator Pbquery::SessionByDayRange() const {
    Pbquery::SessionByDayRange ret;
    *(ret.mutable_yearmonth()) = yearMonth;
    ret.set_startday(startDay);
    ret.set_endday(endDay);
    return ret;
}

std::string SessionByDayRange::serializeAsJsonString() const {
    Pbquery::SessionByDayRange protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionByDayRange::serializeAsProtobufString() const {
    Pbquery::SessionByDayRange protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionByDayRange::deserializeFromJsonString(const std::string& str) {
    Pbquery::SessionByDayRange protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionByDayRange::deserializeFromProtobufString(const std::string& str) {
    Pbquery::SessionByDayRange protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionByDayRangeFound::SessionByDayRangeFound(const Pbquery::SessionByDayRangeFound& protobuf) {
    sessionsFound = {protobuf.sessionsfound().begin(), protobuf.sessionsfound().end()};
}

SessionByDayRangeFound::operator Pbquery::SessionByDayRangeFound() const {
    Pbquery::SessionByDayRangeFound ret;
    *(ret.mutable_sessionsfound()) = {sessionsFound.begin(), sessionsFound.end()};
    return ret;
}

std::string SessionByDayRangeFound::serializeAsJsonString() const {
    Pbquery::SessionByDayRangeFound protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionByDayRangeFound::serializeAsProtobufString() const {
    Pbquery::SessionByDayRangeFound protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionByDayRangeFound::deserializeFromJsonString(const std::string& str) {
    Pbquery::SessionByDayRangeFound protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionByDayRangeFound::deserializeFromProtobufString(const std::string& str) {
    Pbquery::SessionByDayRangeFound protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

TrackBySession::TrackBySession(const Pbquery::TrackBySession& protobuf) {
    sessionRequested = protobuf.sessionrequested();
}

TrackBySession::operator Pbquery::TrackBySession() const {
    Pbquery::TrackBySession ret;
    *(ret.mutable_sessionrequested()) = sessionRequested;
    return ret;
}

std::string TrackBySession::serializeAsJsonString() const {
    Pbquery::TrackBySession protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string TrackBySession::serializeAsProtobufString() const {
    Pbquery::TrackBySession protobuf(*this);
    return protobuf.SerializeAsString();
}

bool TrackBySession::deserializeFromJsonString(const std::string& str) {
    Pbquery::TrackBySession protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool TrackBySession::deserializeFromProtobufString(const std::string& str) {
    Pbquery::TrackBySession protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

TrackBySessionFound::TrackBySessionFound(const Pbquery::TrackBySessionFound& protobuf) {
    tracksFound = {protobuf.tracksfound().begin(), protobuf.tracksfound().end()};
}

TrackBySessionFound::operator Pbquery::TrackBySessionFound() const {
    Pbquery::TrackBySessionFound ret;
    *(ret.mutable_tracksfound()) = {tracksFound.begin(), tracksFound.end()};
    return ret;
}

std::string TrackBySessionFound::serializeAsJsonString() const {
    Pbquery::TrackBySessionFound protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string TrackBySessionFound::serializeAsProtobufString() const {
    Pbquery::TrackBySessionFound protobuf(*this);
    return protobuf.SerializeAsString();
}

bool TrackBySessionFound::deserializeFromJsonString(const std::string& str) {
    Pbquery::TrackBySessionFound protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool TrackBySessionFound::deserializeFromProtobufString(const std::string& str) {
    Pbquery::TrackBySessionFound protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}