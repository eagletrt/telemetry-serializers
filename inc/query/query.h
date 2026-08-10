#ifndef SERIALIZERS_QUERY_H
#define SERIALIZERS_QUERY_H

#include "query.pb.h"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace query
{
struct Weather
{
    double ambientTemperature;
    double trackTemperature;
    double humidity;
    
    Weather() = default;
    Weather(const Pbquery::Weather& protobuf);
    operator Pbquery::Weather() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionConfig
{
    std::string trackLocation;
    std::string trackLayout;
    std::string sessionName;
    std::string driver;
    std::string date;
    std::string time;
    Weather weather;
    std::string notes;
    double canlibVersion;
    uint64_t startTimestamp;
    uint64_t endTimestamp;
    
    SessionConfig() = default;
    SessionConfig(const Pbquery::SessionConfig& protobuf);
    operator Pbquery::SessionConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Baseline
{
    bool valid;
    bool logging;
    double length;
    std::vector<double> x;
    std::vector<double> y;
    bool resampled;
    std::vector<double> s;
    std::vector<double> theta;
    std::string hash;
    
    Baseline() = default;
    Baseline(const Pbquery::Baseline& protobuf);
    operator Pbquery::Baseline() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct GPSMapOrigin
{
    double latitude;
    double longitude;
    double altitude;
    
    GPSMapOrigin() = default;
    GPSMapOrigin(const Pbquery::GPSMapOrigin& protobuf);
    operator Pbquery::GPSMapOrigin() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct GPSMapOrigins
{
    std::string trackLocation;
    std::string trackLayout;
    std::unordered_map<std::string, GPSMapOrigin> origins;
    std::unordered_map<std::string, Baseline> tracksBaseline;
    
    GPSMapOrigins() = default;
    GPSMapOrigins(const Pbquery::GPSMapOrigins& protobuf);
    operator Pbquery::GPSMapOrigins() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SetBaseline
{
    std::string trackLocation;
    std::string trackLayout;
    GPSMapOrigin origin;
    std::vector<double> x;
    std::vector<double> y;
    
    SetBaseline() = default;
    SetBaseline(const Pbquery::SetBaseline& protobuf);
    operator Pbquery::SetBaseline() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct LapRecord
{
    std::string driver;
    uint64_t start;
    uint64_t end;
    std::vector<uint64_t> sectors;
    
    LapRecord() = default;
    LapRecord(const Pbquery::LapRecord& protobuf);
    operator Pbquery::LapRecord() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SectorsRecord
{
    std::string driver;
    uint64_t start_time_sector;
    uint64_t end_time_sector;
    
    SectorsRecord() = default;
    SectorsRecord(const Pbquery::SectorsRecord& protobuf);
    operator Pbquery::SectorsRecord() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct DriverRecord
{
    std::string driver;
    LapRecord best_lap;
    std::vector<SectorsRecord> best_sectors;
    
    DriverRecord() = default;
    DriverRecord(const Pbquery::DriverRecord& protobuf);
    operator Pbquery::DriverRecord() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct LapTime
{
    uint64_t number;
    uint64_t start_timestamp;
    uint64_t end_timestamp;
    std::vector<uint64_t> sectors;
    
    LapTime() = default;
    LapTime(const Pbquery::LapTime& protobuf);
    operator Pbquery::LapTime() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct LapTimes
{
    int32_t version;
    int32_t baseline_version;
    std::string vehicle_id;
    std::string device_id;
    std::string location;
    std::string layout;
    std::string driver;
    std::vector<LapTime> times;
    std::string baseline_hash;
    uint64_t session_start_timestamp;
    std::string session_name;
    
    LapTimes() = default;
    LapTimes(const Pbquery::LapTimes& protobuf);
    operator Pbquery::LapTimes() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Vec2
{
    double x;
    double y;
    
    Vec2() = default;
    Vec2(const Pbquery::Vec2& protobuf);
    operator Pbquery::Vec2() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct PositionAndDirection
{
    Vec2 position;
    Vec2 direction;
    
    PositionAndDirection() = default;
    PositionAndDirection(const Pbquery::PositionAndDirection& protobuf);
    operator Pbquery::PositionAndDirection() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Layout
{
    int32_t version;
    int32_t baseline_version;
    std::string vehicle_id;
    std::string device_id;
    std::string location;
    std::string layout;
    PositionAndDirection start_line;
    PositionAndDirection finish_line;
    std::vector<PositionAndDirection> sectors;
    std::string baseline_hash;
    double start_s;
    std::vector<double> sectors_s;
    double baseline_length;
    
    Layout() = default;
    Layout(const Pbquery::Layout& protobuf);
    operator Pbquery::Layout() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct LapRecords
{
    int32_t version;
    int32_t baseline_version;
    std::string vehicle_id;
    std::string device_id;
    std::string location;
    std::string layout;
    LapRecord best_lap;
    std::vector<SectorsRecord> best_sectors;
    std::vector<DriverRecord> drivers_records;
    std::string baseline_hash;
    uint64_t session_start_timestamp;
    std::string session_name;
    
    LapRecords() = default;
    LapRecords(const Pbquery::LapRecords& protobuf);
    operator Pbquery::LapRecords() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Track
{
    Layout layout;
    LapTimes lapTimes;
    LapRecords lapRecords;
    GPSMapOrigins gpsInfo;
    
    Track() = default;
    Track(const Pbquery::Track& protobuf);
    operator Pbquery::Track() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionByYearMonth
{
    std::string year;
    std::string month;
    
    SessionByYearMonth() = default;
    SessionByYearMonth(const Pbquery::SessionByYearMonth& protobuf);
    operator Pbquery::SessionByYearMonth() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionByYearMonthFound
{
    std::vector<int32_t> daysFound;
    
    SessionByYearMonthFound() = default;
    SessionByYearMonthFound(const Pbquery::SessionByYearMonthFound& protobuf);
    operator Pbquery::SessionByYearMonthFound() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionByDayRange
{
    SessionByYearMonth yearMonth;
    std::string startDay;
    std::string endDay;
    
    SessionByDayRange() = default;
    SessionByDayRange(const Pbquery::SessionByDayRange& protobuf);
    operator Pbquery::SessionByDayRange() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionByDayRangeFound
{
    std::vector<SessionConfig> sessionsFound;
    
    SessionByDayRangeFound() = default;
    SessionByDayRangeFound(const Pbquery::SessionByDayRangeFound& protobuf);
    operator Pbquery::SessionByDayRangeFound() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct TrackBySession
{
    SessionConfig sessionRequested;
    
    TrackBySession() = default;
    TrackBySession(const Pbquery::TrackBySession& protobuf);
    operator Pbquery::TrackBySession() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct DocumentBySessionFound
{
    std::vector<Track> tracksFound;
    
    DocumentBySessionFound() = default;
    DocumentBySessionFound(const Pbquery::DocumentBySessionFound& protobuf);
    operator Pbquery::DocumentBySessionFound() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif