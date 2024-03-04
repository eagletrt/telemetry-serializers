#include "actions/command.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Actions
{
Command::Command(const PbActions::Command& message) {
    input = message.input();
    output = message.output();
}

Command::operator PbActions::Command() const {
    PbActions::Command ret;
    ret.set_input(input);
    ret.set_output(output);
    return ret;
}

std::string Command::serializeAsJsonString() const {
    PbActions::Command message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Command::serializeAsProtobufString() const {
    PbActions::Command message(*this);
    return message.SerializeAsString();
}

bool Command::deserializeFromJsonString(const std::string& str) {
    PbActions::Command message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Command::deserializeFromProtobufString(const std::string& str) {
    PbActions::Command message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}