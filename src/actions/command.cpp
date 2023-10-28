#include "actions/command.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Actions
{
Command::Command(const ActionsCommand& proto) {
    input = proto.input();
    output = proto.output();
}

Command::operator ActionsCommand() const {
    ActionsCommand ret;
    ret.set_input(input);
    ret.set_output(output);
    return ret;
}

std::string Command::serializeAsJsonString() const {
    ActionsCommand proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Command::serializeAsProtobufString() const {
    ActionsCommand proto(*this);
    return proto.SerializeAsString();
}

bool Command::deserializeFromJsonString(const std::string& str) {
    ActionsCommand proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Command::deserializeFromProtobufString(const std::string& str) {
    ActionsCommand proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}