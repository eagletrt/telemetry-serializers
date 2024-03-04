#include "configs/car_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Configs
{
Aero::Aero(const PbConfigs::Aero& message) {
    angleOfIncidenceFront = message.angleofincidencefront();
    angleOfIncidenceRear = message.angleofincidencerear();
    flap = message.flap();
}

Aero::operator PbConfigs::Aero() const {
    PbConfigs::Aero ret;
    ret.set_angleofincidencefront(angleOfIncidenceFront);
    ret.set_angleofincidencerear(angleOfIncidenceRear);
    ret.set_flap(flap);
    return ret;
}

std::string Aero::serializeAsJsonString() const {
    PbConfigs::Aero message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Aero::serializeAsProtobufString() const {
    PbConfigs::Aero message(*this);
    return message.SerializeAsString();
}

bool Aero::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Aero message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Aero::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Aero message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Wheel::Wheel(const PbConfigs::Wheel& message) {
    camber = message.camber();
    toe = message.toe();
    pressure = message.pressure();
}

Wheel::operator PbConfigs::Wheel() const {
    PbConfigs::Wheel ret;
    ret.set_camber(camber);
    ret.set_toe(toe);
    ret.set_pressure(pressure);
    return ret;
}

std::string Wheel::serializeAsJsonString() const {
    PbConfigs::Wheel message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Wheel::serializeAsProtobufString() const {
    PbConfigs::Wheel message(*this);
    return message.SerializeAsString();
}

bool Wheel::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Wheel message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Wheel::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Wheel message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Damper::Damper(const PbConfigs::Damper& message) {
    bound_low_comp = message.bound_low_comp();
    bound_high_comp = message.bound_high_comp();
    rebound = message.rebound();
    preload = message.preload();
}

Damper::operator PbConfigs::Damper() const {
    PbConfigs::Damper ret;
    ret.set_bound_low_comp(bound_low_comp);
    ret.set_bound_high_comp(bound_high_comp);
    ret.set_rebound(rebound);
    ret.set_preload(preload);
    return ret;
}

std::string Damper::serializeAsJsonString() const {
    PbConfigs::Damper message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Damper::serializeAsProtobufString() const {
    PbConfigs::Damper message(*this);
    return message.SerializeAsString();
}

bool Damper::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Damper message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Damper::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Damper message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

CarConfig::CarConfig(const PbConfigs::CarConfig& message) {
    aero = message.aero();
    wheelFront = message.wheelfront();
    wheelRear = message.wheelrear();
    damperFront = message.damperfront();
    damperRear = message.damperrear();
    wheelCompound = message.wheelcompound();
    rideHeight = message.rideheight();
    balancing = message.balancing();
    notes = message.notes();
}

CarConfig::operator PbConfigs::CarConfig() const {
    PbConfigs::CarConfig ret;
    *(ret.mutable_aero()) = aero;
    *(ret.mutable_wheelfront()) = wheelFront;
    *(ret.mutable_wheelrear()) = wheelRear;
    *(ret.mutable_damperfront()) = damperFront;
    *(ret.mutable_damperrear()) = damperRear;
    ret.set_wheelcompound(wheelCompound);
    ret.set_rideheight(rideHeight);
    ret.set_balancing(balancing);
    ret.set_notes(notes);
    return ret;
}

std::string CarConfig::serializeAsJsonString() const {
    PbConfigs::CarConfig message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string CarConfig::serializeAsProtobufString() const {
    PbConfigs::CarConfig message(*this);
    return message.SerializeAsString();
}

bool CarConfig::deserializeFromJsonString(const std::string& str) {
    PbConfigs::CarConfig message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool CarConfig::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::CarConfig message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}