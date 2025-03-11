#include "tpms/rtl433_payload.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace TPMS
{
Rtl433Payload::Rtl433Payload(const PbTPMS::Rtl433Payload& protobuf) {
    time = protobuf.time();
    model = protobuf.model();
    id = protobuf.id();
    pressure = protobuf.pressure();
    temperature = protobuf.temperature();
    acceleration = protobuf.acceleration();
    battery = protobuf.battery();
    interframe = protobuf.interframe();
    wo_state = protobuf.wo_state();
    checksum = protobuf.checksum();
    mic = protobuf.mic();
    mod = protobuf.mod();
    freq1 = protobuf.freq1();
    freq2 = protobuf.freq2();
    rssi = protobuf.rssi();
    snr = protobuf.snr();
    noise = protobuf.noise();
}

Rtl433Payload::operator PbTPMS::Rtl433Payload() const {
    PbTPMS::Rtl433Payload ret;
    ret.set_time(time);
    ret.set_model(model);
    ret.set_id(id);
    ret.set_pressure(pressure);
    ret.set_temperature(temperature);
    ret.set_acceleration(acceleration);
    ret.set_battery(battery);
    ret.set_interframe(interframe);
    ret.set_wo_state(wo_state);
    ret.set_checksum(checksum);
    ret.set_mic(mic);
    ret.set_mod(mod);
    ret.set_freq1(freq1);
    ret.set_freq2(freq2);
    ret.set_rssi(rssi);
    ret.set_snr(snr);
    ret.set_noise(noise);
    return ret;
}

std::string Rtl433Payload::serializeAsJsonString() const {
    PbTPMS::Rtl433Payload protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Rtl433Payload::serializeAsProtobufString() const {
    PbTPMS::Rtl433Payload protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Rtl433Payload::deserializeFromJsonString(const std::string& str) {
    PbTPMS::Rtl433Payload protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Rtl433Payload::deserializeFromProtobufString(const std::string& str) {
    PbTPMS::Rtl433Payload protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}