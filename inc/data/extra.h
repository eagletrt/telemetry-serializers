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
struct RepeatedValue
{
    std::vector<double> values;
    
    RepeatedValue() = default;
    RepeatedValue(const PbData::RepeatedValue& protobuf);
    operator PbData::RepeatedValue() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct ValuesMap
{
    std::unordered_map<std::string, RepeatedValue> valuesMap;
    
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