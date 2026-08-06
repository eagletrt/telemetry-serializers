#ifndef SERIALIZERS_TRACK_H
#define SERIALIZERS_TRACK_H

#include "track.pb.h"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Track
{
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
    Baseline(const PbTrack::Baseline& protobuf);
    operator PbTrack::Baseline() const;

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
    GPSMapOrigin(const PbTrack::GPSMapOrigin& protobuf);
    operator PbTrack::GPSMapOrigin() const;

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
    GPSMapOrigins(const PbTrack::GPSMapOrigins& protobuf);
    operator PbTrack::GPSMapOrigins() const;

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
    SetBaseline(const PbTrack::SetBaseline& protobuf);
    operator PbTrack::SetBaseline() const;

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
    LapRecord(const PbTrack::LapRecord& protobuf);
    operator PbTrack::LapRecord() const;

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
    SectorsRecord(const PbTrack::SectorsRecord& protobuf);
    operator PbTrack::SectorsRecord() const;

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
    DriverRecord(const PbTrack::DriverRecord& protobuf);
    operator PbTrack::DriverRecord() const;

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
    LapTime(const PbTrack::LapTime& protobuf);
    operator PbTrack::LapTime() const;

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
    LapTimes(const PbTrack::LapTimes& protobuf);
    operator PbTrack::LapTimes() const;

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
    Vec2(const PbTrack::Vec2& protobuf);
    operator PbTrack::Vec2() const;

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
    PositionAndDirection(const PbTrack::PositionAndDirection& protobuf);
    operator PbTrack::PositionAndDirection() const;

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
    Layout(const PbTrack::Layout& protobuf);
    operator PbTrack::Layout() const;

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
    LapRecords(const PbTrack::LapRecords& protobuf);
    operator PbTrack::LapRecords() const;

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
    Track(const PbTrack::Track& protobuf);
    operator PbTrack::Track() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif