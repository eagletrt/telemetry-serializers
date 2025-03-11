#ifndef SERIALIZERS_DATA_PROCESSING_H
#define SERIALIZERS_DATA_PROCESSING_H

#include "data_processing.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace App
{
struct Plugin
{
    std::string path;
    
    Plugin() = default;
    Plugin(const PbApp::Plugin& protobuf);
    operator PbApp::Plugin() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Signal
{
    std::string msg;
    std::vector<std::string> fields;
    
    Signal() = default;
    Signal(const PbApp::Signal& protobuf);
    operator PbApp::Signal() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct DataProcessing
{
    std::vector<Plugin> plugins;
    std::vector<Signal> resampledSignals;
    
    DataProcessing() = default;
    DataProcessing(const PbApp::DataProcessing& protobuf);
    operator PbApp::DataProcessing() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif