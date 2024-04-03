#ifndef SERIALIZERS_STATISTICS_H
#define SERIALIZERS_STATISTICS_H

#include "statistics.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Telemetry
{
struct Statistics
{
    int64_t messages;
    int64_t averageFrequency;
    double seconds;
    
    Statistics() = default;
    Statistics(const PbTelemetry::Statistics& protobuf);
    operator PbTelemetry::Statistics() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif