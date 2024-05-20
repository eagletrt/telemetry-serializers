#ifndef SERIALIZERS_BASELINE_H
#define SERIALIZERS_BASELINE_H

#include "baseline.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Telemetry
{
struct Baseline
{
    std::vector<double> xs;
    std::vector<double> ys;
    
    Baseline() = default;
    Baseline(const PbTelemetry::Baseline& protobuf);
    operator PbTelemetry::Baseline() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif