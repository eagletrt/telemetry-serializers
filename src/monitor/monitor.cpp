#include "monitor/monitor.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Monitor
{
Setup::Setup(const PbMonitor::Setup& protobuf) {
    timestamp = protobuf.timestamp();
    name = protobuf.name();
    version = protobuf.version();
    address = protobuf.address();
    heartbeatSeconds = protobuf.heartbeatseconds();
}

Setup::operator PbMonitor::Setup() const {
    PbMonitor::Setup ret;
    ret.set_timestamp(timestamp);
    ret.set_name(name);
    ret.set_version(version);
    ret.set_address(address);
    ret.set_heartbeatseconds(heartbeatSeconds);
    return ret;
}

std::string Setup::serializeAsJsonString() const {
    PbMonitor::Setup protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Setup::serializeAsProtobufString() const {
    PbMonitor::Setup protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Setup::deserializeFromJsonString(const std::string& str) {
    PbMonitor::Setup protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Setup::deserializeFromProtobufString(const std::string& str) {
    PbMonitor::Setup protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

State::State(const PbMonitor::State& protobuf) {
    timestamp = protobuf.timestamp();
    state = static_cast<ServiceState>(protobuf.state());
}

State::operator PbMonitor::State() const {
    PbMonitor::State ret;
    ret.set_timestamp(timestamp);
    ret.set_state(static_cast<PbMonitor::ServiceState>(state));
    return ret;
}

std::string State::serializeAsJsonString() const {
    PbMonitor::State protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string State::serializeAsProtobufString() const {
    PbMonitor::State protobuf(*this);
    return protobuf.SerializeAsString();
}

bool State::deserializeFromJsonString(const std::string& str) {
    PbMonitor::State protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool State::deserializeFromProtobufString(const std::string& str) {
    PbMonitor::State protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Alive::Alive(const PbMonitor::Alive& protobuf) {
    timestamp = protobuf.timestamp();
    uptimeMs = protobuf.uptimems();
}

Alive::operator PbMonitor::Alive() const {
    PbMonitor::Alive ret;
    ret.set_timestamp(timestamp);
    ret.set_uptimems(uptimeMs);
    return ret;
}

std::string Alive::serializeAsJsonString() const {
    PbMonitor::Alive protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Alive::serializeAsProtobufString() const {
    PbMonitor::Alive protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Alive::deserializeFromJsonString(const std::string& str) {
    PbMonitor::Alive protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Alive::deserializeFromProtobufString(const std::string& str) {
    PbMonitor::Alive protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CpuStats::CpuStats(const PbMonitor::CpuStats& protobuf) {
    timestamp = protobuf.timestamp();
    usage = protobuf.usage();
    processUsage = protobuf.processusage();
    temperature = protobuf.temperature();
}

CpuStats::operator PbMonitor::CpuStats() const {
    PbMonitor::CpuStats ret;
    ret.set_timestamp(timestamp);
    ret.set_usage(usage);
    ret.set_processusage(processUsage);
    ret.set_temperature(temperature);
    return ret;
}

std::string CpuStats::serializeAsJsonString() const {
    PbMonitor::CpuStats protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CpuStats::serializeAsProtobufString() const {
    PbMonitor::CpuStats protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CpuStats::deserializeFromJsonString(const std::string& str) {
    PbMonitor::CpuStats protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CpuStats::deserializeFromProtobufString(const std::string& str) {
    PbMonitor::CpuStats protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

RAMStats::RAMStats(const PbMonitor::RAMStats& protobuf) {
    timestamp = protobuf.timestamp();
    usage = protobuf.usage();
    processUsage = protobuf.processusage();
    memoryAvailable = protobuf.memoryavailable();
}

RAMStats::operator PbMonitor::RAMStats() const {
    PbMonitor::RAMStats ret;
    ret.set_timestamp(timestamp);
    ret.set_usage(usage);
    ret.set_processusage(processUsage);
    ret.set_memoryavailable(memoryAvailable);
    return ret;
}

std::string RAMStats::serializeAsJsonString() const {
    PbMonitor::RAMStats protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string RAMStats::serializeAsProtobufString() const {
    PbMonitor::RAMStats protobuf(*this);
    return protobuf.SerializeAsString();
}

bool RAMStats::deserializeFromJsonString(const std::string& str) {
    PbMonitor::RAMStats protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool RAMStats::deserializeFromProtobufString(const std::string& str) {
    PbMonitor::RAMStats protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Link::Link(const PbMonitor::Link& protobuf) {
    name = protobuf.name();
    connected = protobuf.connected();
    bytesSent = protobuf.bytessent();
    bytesReceived = protobuf.bytesreceived();
    rttMs = protobuf.rttms();
}

Link::operator PbMonitor::Link() const {
    PbMonitor::Link ret;
    ret.set_name(name);
    ret.set_connected(connected);
    ret.set_bytessent(bytesSent);
    ret.set_bytesreceived(bytesReceived);
    ret.set_rttms(rttMs);
    return ret;
}

std::string Link::serializeAsJsonString() const {
    PbMonitor::Link protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Link::serializeAsProtobufString() const {
    PbMonitor::Link protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Link::deserializeFromJsonString(const std::string& str) {
    PbMonitor::Link protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Link::deserializeFromProtobufString(const std::string& str) {
    PbMonitor::Link protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

ConnectionStats::ConnectionStats(const PbMonitor::ConnectionStats& protobuf) {
    timestamp = protobuf.timestamp();
    links = {protobuf.links().begin(), protobuf.links().end()};
}

ConnectionStats::operator PbMonitor::ConnectionStats() const {
    PbMonitor::ConnectionStats ret;
    ret.set_timestamp(timestamp);
    *(ret.mutable_links()) = {links.begin(), links.end()};
    return ret;
}

std::string ConnectionStats::serializeAsJsonString() const {
    PbMonitor::ConnectionStats protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ConnectionStats::serializeAsProtobufString() const {
    PbMonitor::ConnectionStats protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ConnectionStats::deserializeFromJsonString(const std::string& str) {
    PbMonitor::ConnectionStats protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ConnectionStats::deserializeFromProtobufString(const std::string& str) {
    PbMonitor::ConnectionStats protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}