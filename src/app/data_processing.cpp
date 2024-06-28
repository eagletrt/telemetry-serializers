#include "app/data_processing.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace App
{
Plugin::Plugin(const PbApp::Plugin& protobuf) {
    path = protobuf.path();
}

Plugin::operator PbApp::Plugin() const {
    PbApp::Plugin ret;
    ret.set_path(path);
    return ret;
}

std::string Plugin::serializeAsJsonString() const {
    PbApp::Plugin protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Plugin::serializeAsProtobufString() const {
    PbApp::Plugin protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Plugin::deserializeFromJsonString(const std::string& str) {
    PbApp::Plugin protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Plugin::deserializeFromProtobufString(const std::string& str) {
    PbApp::Plugin protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Signal::Signal(const PbApp::Signal& protobuf) {
    msg = protobuf.msg();
    fields = {protobuf.fields().begin(), protobuf.fields().end()};
}

Signal::operator PbApp::Signal() const {
    PbApp::Signal ret;
    ret.set_msg(msg);
    *(ret.mutable_fields()) = {fields.begin(), fields.end()};
    return ret;
}

std::string Signal::serializeAsJsonString() const {
    PbApp::Signal protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Signal::serializeAsProtobufString() const {
    PbApp::Signal protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Signal::deserializeFromJsonString(const std::string& str) {
    PbApp::Signal protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Signal::deserializeFromProtobufString(const std::string& str) {
    PbApp::Signal protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

DataProcessing::DataProcessing(const PbApp::DataProcessing& protobuf) {
    plugins = {protobuf.plugins().begin(), protobuf.plugins().end()};
    resampledSignals = {protobuf.resampledsignals().begin(), protobuf.resampledsignals().end()};
}

DataProcessing::operator PbApp::DataProcessing() const {
    PbApp::DataProcessing ret;
    *(ret.mutable_plugins()) = {plugins.begin(), plugins.end()};
    *(ret.mutable_resampledsignals()) = {resampledSignals.begin(), resampledSignals.end()};
    return ret;
}

std::string DataProcessing::serializeAsJsonString() const {
    PbApp::DataProcessing protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string DataProcessing::serializeAsProtobufString() const {
    PbApp::DataProcessing protobuf(*this);
    return protobuf.SerializeAsString();
}

bool DataProcessing::deserializeFromJsonString(const std::string& str) {
    PbApp::DataProcessing protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool DataProcessing::deserializeFromProtobufString(const std::string& str) {
    PbApp::DataProcessing protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}