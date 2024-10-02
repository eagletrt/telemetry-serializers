#ifndef SERIALIZERS_LAPCOUNTER_LAP_RECORDS_H
#define SERIALIZERS_LAPCOUNTER_LAP_RECORDS_H

#include "lapcounter_lap_records.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace MongoDb
{
struct LapRecord
{
    std::string driver;
    uint64_t start;
    uint64_t end;
    std::vector<uint64_t> sectors;
    
    LapRecord() = default;
    LapRecord(const PbMongoDb::LapRecord& protobuf);
    operator PbMongoDb::LapRecord() const;

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
    SectorsRecord(const PbMongoDb::SectorsRecord& protobuf);
    operator PbMongoDb::SectorsRecord() const;

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
    DriverRecord(const PbMongoDb::DriverRecord& protobuf);
    operator PbMongoDb::DriverRecord() const;

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
    
    LapRecords() = default;
    LapRecords(const PbMongoDb::LapRecords& protobuf);
    operator PbMongoDb::LapRecords() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif