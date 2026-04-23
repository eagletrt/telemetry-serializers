#ifndef SERIALIZERS_LAP_COUNTER_H
#define SERIALIZERS_LAP_COUNTER_H

#include "lap_counter.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace LapCounter
{
struct LcPoint
{
    double position_x;
    double position_y;
    double inclination_x;
    double inclination_y;
    
    LcPoint() = default;
    LcPoint(const PbLapCounter::LcPoint& protobuf);
    operator PbLapCounter::LcPoint() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct TrackLayout
{
    int32_t layout_id;
    std::string name;
    LcPoint start1;
    LcPoint start2;
    int32_t sector_count;
    std::vector<LcPoint> sectors;
    
    TrackLayout() = default;
    TrackLayout(const PbLapCounter::TrackLayout& protobuf);
    operator PbLapCounter::TrackLayout() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Time
{
    int32_t layout_id;
    uint32_t lap_number;
    std::string driver_name;
    uint64_t start_timestamp;
    uint64_t end_timestamp;
    std::vector<uint64_t> sectors_timestamp;
    
    Time() = default;
    Time(const PbLapCounter::Time& protobuf);
    operator PbLapCounter::Time() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct DriverRecord
{
    std::string driver;
    uint64_t start_timestamp;
    uint64_t end_timestamp;
    std::vector<uint64_t> sectors_timestamp;
    
    DriverRecord() = default;
    DriverRecord(const PbLapCounter::DriverRecord& protobuf);
    operator PbLapCounter::DriverRecord() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct TrackRecord
{
    int32_t layout_id;
    uint32_t lap_number;
    DriverRecord best_lap;
    std::vector<DriverRecord> best_sectors;
    
    TrackRecord() = default;
    TrackRecord(const PbLapCounter::TrackRecord& protobuf);
    operator PbLapCounter::TrackRecord() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Driver
{
    std::string name;
    std::vector<Time> times;
    
    Driver() = default;
    Driver(const PbLapCounter::Driver& protobuf);
    operator PbLapCounter::Driver() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct DataBase
{
    std::vector<TrackLayout> layouts;
    std::vector<Driver> drivers;
    std::vector<TrackRecord> records;
    int32_t last_id;
    uint32_t lap_number;
    
    DataBase() = default;
    DataBase(const PbLapCounter::DataBase& protobuf);
    operator PbLapCounter::DataBase() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif