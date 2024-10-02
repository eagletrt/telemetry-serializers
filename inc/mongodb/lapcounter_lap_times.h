#ifndef SERIALIZERS_LAPCOUNTER_LAP_TIMES_H
#define SERIALIZERS_LAPCOUNTER_LAP_TIMES_H

#include "lapcounter_lap_times.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace MongoDb
{
struct LapTime
{
    uint64_t number;
    uint64_t start_timestamp;
    uint64_t end_timestamp;
    std::vector<uint64_t> sectors;
    
    LapTime() = default;
    LapTime(const PbMongoDb::LapTime& protobuf);
    operator PbMongoDb::LapTime() const;

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
    
    LapTimes() = default;
    LapTimes(const PbMongoDb::LapTimes& protobuf);
    operator PbMongoDb::LapTimes() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif