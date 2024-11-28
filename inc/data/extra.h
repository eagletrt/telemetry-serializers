#ifndef SERIALIZERS_EXTRA_H
#define SERIALIZERS_EXTRA_H

#include "extra.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Data
{
struct RepeatedValueUint64
{
    std::vector<uint64_t> values;
    
    RepeatedValueUint64() = default;
    RepeatedValueUint64(const PbData::RepeatedValueUint64& protobuf);
    operator PbData::RepeatedValueUint64() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct RepeatedValueDouble
{
    std::vector<double> values;
    
    RepeatedValueDouble() = default;
    RepeatedValueDouble(const PbData::RepeatedValueDouble& protobuf);
    operator PbData::RepeatedValueDouble() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct ValuesMap
{
    RepeatedValueUint64 timestamp;
    std::unordered_map<std::string, RepeatedValueDouble> valuesMap;
    
    ValuesMap() = default;
    ValuesMap(const PbData::ValuesMap& protobuf);
    operator PbData::ValuesMap() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct TimeValuesPack
{
    std::unordered_map<std::string, ValuesMap> valuesPack;
    
    TimeValuesPack() = default;
    TimeValuesPack(const PbData::TimeValuesPack& protobuf);
    operator PbData::TimeValuesPack() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif