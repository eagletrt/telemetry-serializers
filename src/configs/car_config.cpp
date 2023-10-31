#include "configs/car_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Configs
{
Aero::Aero(const PbConfigs::Aero& protobuf) {
    angleOfIncidenceFront = protobuf.angleofincidencefront();
    angleOfIncidenceRear = protobuf.angleofincidencerear();
    flap = protobuf.flap();
}

Aero::operator PbConfigs::Aero() const {
    PbConfigs::Aero ret;
    ret.set_angleofincidencefront(angleOfIncidenceFront);
    ret.set_angleofincidencerear(angleOfIncidenceRear);
    ret.set_flap(flap);
    return ret;
}

std::string Aero::serializeAsJsonString() const {
    PbConfigs::Aero protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Aero::serializeAsProtobufString() const {
    PbConfigs::Aero protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Aero::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Aero protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Aero::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Aero protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Wheel::Wheel(const PbConfigs::Wheel& protobuf) {
    camber = protobuf.camber();
    toe = protobuf.toe();
}

Wheel::operator PbConfigs::Wheel() const {
    PbConfigs::Wheel ret;
    ret.set_camber(camber);
    ret.set_toe(toe);
    return ret;
}

std::string Wheel::serializeAsJsonString() const {
    PbConfigs::Wheel protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Wheel::serializeAsProtobufString() const {
    PbConfigs::Wheel protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Wheel::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Wheel protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Wheel::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Wheel protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Damper::Damper(const PbConfigs::Damper& protobuf) {
    bound = protobuf.bound();
    rebound = protobuf.rebound();
    preload = protobuf.preload();
}

Damper::operator PbConfigs::Damper() const {
    PbConfigs::Damper ret;
    ret.set_bound(bound);
    ret.set_rebound(rebound);
    ret.set_preload(preload);
    return ret;
}

std::string Damper::serializeAsJsonString() const {
    PbConfigs::Damper protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Damper::serializeAsProtobufString() const {
    PbConfigs::Damper protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Damper::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Damper protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Damper::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Damper protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CarConfig::CarConfig(const PbConfigs::CarConfig& protobuf) {
    aero = protobuf.aero();
    wheelFront = protobuf.wheelfront();
    wheelRear = protobuf.wheelrear();
    damperFront = protobuf.damperfront();
    damperRear = protobuf.damperrear();
    wheelCompound = protobuf.wheelcompound();
    rideHeight = protobuf.rideheight();
    balancing = protobuf.balancing();
    notes = protobuf.notes();
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
    PbConfigs::CarConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CarConfig::serializeAsProtobufString() const {
    PbConfigs::CarConfig protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CarConfig::deserializeFromJsonString(const std::string& str) {
    PbConfigs::CarConfig protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CarConfig::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::CarConfig protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}