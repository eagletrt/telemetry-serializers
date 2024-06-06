#ifndef SERIALIZERS_KILOMETERS_COUNTER_H
#define SERIALIZERS_KILOMETERS_COUNTER_H

#include "kilometers_counter.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Telemetry
{
struct KilometersCounter
{
    std::string startDate;
    double kilometers;
    
    KilometersCounter() = default;
    KilometersCounter(const PbTelemetry::KilometersCounter& protobuf);
    operator PbTelemetry::KilometersCounter() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif