#include "actions/command.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Actions
{
Command::Command(const PbActions::Command& protobuf) {
    input = protobuf.input();
    output = protobuf.output();
}

Command::operator PbActions::Command() const {
    PbActions::Command ret;
    ret.set_input(input);
    ret.set_output(output);
    return ret;
}

std::string Command::serializeAsJsonString() const {
    PbActions::Command protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Command::serializeAsProtobufString() const {
    PbActions::Command protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Command::deserializeFromJsonString(const std::string& str) {
    PbActions::Command protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Command::deserializeFromProtobufString(const std::string& str) {
    PbActions::Command protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}