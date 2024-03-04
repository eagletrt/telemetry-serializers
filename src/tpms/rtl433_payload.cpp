#include "tpms/rtl433_payload.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace TPMS
{
Rtl433Payload::Rtl433Payload(const PbTPMS::Rtl433Payload& message) {
    time = message.time();
    model = message.model();
    id = message.id();
    pressure = message.pressure();
    temperature = message.temperature();
    acceleration = message.acceleration();
    battery = message.battery();
    interframe = message.interframe();
    wo_state = message.wo_state();
    checksum = message.checksum();
    mic = message.mic();
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
    return ret;
}

std::string Rtl433Payload::serializeAsJsonString() const {
    PbTPMS::Rtl433Payload message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Rtl433Payload::serializeAsProtobufString() const {
    PbTPMS::Rtl433Payload message(*this);
    return message.SerializeAsString();
}

bool Rtl433Payload::deserializeFromJsonString(const std::string& str) {
    PbTPMS::Rtl433Payload message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Rtl433Payload::deserializeFromProtobufString(const std::string& str) {
    PbTPMS::Rtl433Payload message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}