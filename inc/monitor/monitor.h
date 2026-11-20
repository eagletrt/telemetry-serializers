#ifndef SERIALIZERS_MONITOR_H
#define SERIALIZERS_MONITOR_H

#include "monitor.pb.h"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Monitor
{
enum class ServiceState
{
    SERVICE_STATE_INIT = 0,
    SERVICE_STATE_IDLE = 1,
    SERVICE_STATE_RUN = 2,
    SERVICE_STATE_ERROR = 3,
    SERVICE_STATE_STOP = 4,
    SERVICE_STATE_OFFLINE = 5
};

enum class Capability
{
    CAPABILITY_CPU_STATS = 0,
    CAPABILITY_RAM_STATS = 1,
    CAPABILITY_CONNECTION_STATS = 2,
    CAPABILITY_FIX = 3
};

enum class Severity
{
    SEVERITY_DEBUG = 0,
    SEVERITY_INFO = 1,
    SEVERITY_WARNING = 2,
    SEVERITY_ERROR = 3
};

struct Setup
{
    uint64_t timestamp{};
    std::string name{};
    std::string version{};
    std::string address{};
    uint32_t heartbeatSeconds{};
    
    Setup() = default;
    Setup(const PbMonitor::Setup& protobuf);
    operator PbMonitor::Setup() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct State
{
    uint64_t timestamp{};
    ServiceState state{};
    
    State() = default;
    State(const PbMonitor::State& protobuf);
    operator PbMonitor::State() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Alive
{
    uint64_t timestamp{};
    uint64_t uptimeMs{};
    
    Alive() = default;
    Alive(const PbMonitor::Alive& protobuf);
    operator PbMonitor::Alive() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CpuStats
{
    uint64_t timestamp{};
    double usage{};
    double processUsage{};
    double temperature{};
    
    CpuStats() = default;
    CpuStats(const PbMonitor::CpuStats& protobuf);
    operator PbMonitor::CpuStats() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct RAMStats
{
    uint64_t timestamp{};
    double usage{};
    double processUsage{};
    uint64_t memoryAvailable{};
    
    RAMStats() = default;
    RAMStats(const PbMonitor::RAMStats& protobuf);
    operator PbMonitor::RAMStats() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Link
{
    std::string name{};
    bool connected{};
    uint64_t bytesSent{};
    uint64_t bytesReceived{};
    double rttMs{};
    
    Link() = default;
    Link(const PbMonitor::Link& protobuf);
    operator PbMonitor::Link() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct ConnectionStats
{
    uint64_t timestamp{};
    std::vector<Link> links;
    
    ConnectionStats() = default;
    ConnectionStats(const PbMonitor::ConnectionStats& protobuf);
    operator PbMonitor::ConnectionStats() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif