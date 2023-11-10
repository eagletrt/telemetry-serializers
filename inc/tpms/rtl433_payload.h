#ifndef RTL433_PAYLOAD_H
#define RTL433_PAYLOAD_H

#include "rtl433_payload.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace tpms
{
struct Rtl433Payload
{
    std::string model;
    int32_t id;
    double pressure;
    uint32_t temperature;
    uint32_t acceleration;
    uint32_t battery;
    uint32_t interframe;
    uint32_t wo_state;
    uint32_t checksum;
    std::string mic;
    
    Rtl433Payload() = default;
    Rtl433Payload(const Pbtpms::Rtl433Payload& protobuf);
    operator Pbtpms::Rtl433Payload() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif