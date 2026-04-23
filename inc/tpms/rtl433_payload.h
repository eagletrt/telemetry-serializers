#ifndef SERIALIZERS_RTL433_PAYLOAD_H
#define SERIALIZERS_RTL433_PAYLOAD_H

#include "rtl433_payload.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace TPMS
{
struct Rtl433Payload
{
    std::string time;
    std::string model;
    int64_t id;
    uint32_t pressure;
    uint32_t temperature;
    uint32_t acceleration;
    uint32_t battery;
    uint32_t interframe;
    uint32_t wo_state;
    uint32_t checksum;
    std::string mic;
    std::string mod;
    double freq1;
    double freq2;
    double rssi;
    double snr;
    double noise;
    
    Rtl433Payload() = default;
    Rtl433Payload(const PbTPMS::Rtl433Payload& protobuf);
    operator PbTPMS::Rtl433Payload() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif