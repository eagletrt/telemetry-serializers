#include "configs/car_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Configs
{
Aero::Aero(const ConfigsAero& proto) {
    angleOfIncidenceFront = proto.angleofincidencefront();
    angleOfIncidenceRear = proto.angleofincidencerear();
    flap = proto.flap();
}

Aero::operator ConfigsAero() const {
    ConfigsAero ret;
    ret.set_angleofincidencefront(angleOfIncidenceFront);
    ret.set_angleofincidencerear(angleOfIncidenceRear);
    ret.set_flap(flap);
    return ret;
}

std::string Aero::serializeAsJsonString() const {
    ConfigsAero proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Aero::serializeAsProtobufString() const {
    ConfigsAero proto(*this);
    return proto.SerializeAsString();
}

bool Aero::deserializeFromJsonString(const std::string& str) {
    ConfigsAero proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Aero::deserializeFromProtobufString(const std::string& str) {
    ConfigsAero proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Wheel::Wheel(const ConfigsWheel& proto) {
    camber = proto.camber();
    toe = proto.toe();
}

Wheel::operator ConfigsWheel() const {
    ConfigsWheel ret;
    ret.set_camber(camber);
    ret.set_toe(toe);
    return ret;
}

std::string Wheel::serializeAsJsonString() const {
    ConfigsWheel proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Wheel::serializeAsProtobufString() const {
    ConfigsWheel proto(*this);
    return proto.SerializeAsString();
}

bool Wheel::deserializeFromJsonString(const std::string& str) {
    ConfigsWheel proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Wheel::deserializeFromProtobufString(const std::string& str) {
    ConfigsWheel proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Damper::Damper(const ConfigsDamper& proto) {
    bound = proto.bound();
    rebound = proto.rebound();
    preload = proto.preload();
}

Damper::operator ConfigsDamper() const {
    ConfigsDamper ret;
    ret.set_bound(bound);
    ret.set_rebound(rebound);
    ret.set_preload(preload);
    return ret;
}

std::string Damper::serializeAsJsonString() const {
    ConfigsDamper proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Damper::serializeAsProtobufString() const {
    ConfigsDamper proto(*this);
    return proto.SerializeAsString();
}

bool Damper::deserializeFromJsonString(const std::string& str) {
    ConfigsDamper proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Damper::deserializeFromProtobufString(const std::string& str) {
    ConfigsDamper proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Driver::Driver(const ConfigsDriver& proto) {
    name = proto.name();
    weight = proto.weight();
}

Driver::operator ConfigsDriver() const {
    ConfigsDriver ret;
    ret.set_name(name);
    ret.set_weight(weight);
    return ret;
}

std::string Driver::serializeAsJsonString() const {
    ConfigsDriver proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Driver::serializeAsProtobufString() const {
    ConfigsDriver proto(*this);
    return proto.SerializeAsString();
}

bool Driver::deserializeFromJsonString(const std::string& str) {
    ConfigsDriver proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Driver::deserializeFromProtobufString(const std::string& str) {
    ConfigsDriver proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

CarConfig::CarConfig(const ConfigsCarConfig& proto) {
    aero = proto.aero();
    wheelFront = proto.wheelfront();
    wheelRear = proto.wheelrear();
    damperFront = proto.damperfront();
    damperRear = proto.damperrear();
    driver = proto.driver();
    wheelCompound = proto.wheelcompound();
    rideHeight = proto.rideheight();
    balancing = proto.balancing();
    notes = proto.notes();
}

CarConfig::operator ConfigsCarConfig() const {
    ConfigsCarConfig ret;
    *(ret.mutable_aero()) = aero;
    *(ret.mutable_wheelfront()) = wheelFront;
    *(ret.mutable_wheelrear()) = wheelRear;
    *(ret.mutable_damperfront()) = damperFront;
    *(ret.mutable_damperrear()) = damperRear;
    *(ret.mutable_driver()) = driver;
    ret.set_wheelcompound(wheelCompound);
    ret.set_rideheight(rideHeight);
    ret.set_balancing(balancing);
    ret.set_notes(notes);
    return ret;
}

std::string CarConfig::serializeAsJsonString() const {
    ConfigsCarConfig proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string CarConfig::serializeAsProtobufString() const {
    ConfigsCarConfig proto(*this);
    return proto.SerializeAsString();
}

bool CarConfig::deserializeFromJsonString(const std::string& str) {
    ConfigsCarConfig proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool CarConfig::deserializeFromProtobufString(const std::string& str) {
    ConfigsCarConfig proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}