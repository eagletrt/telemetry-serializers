#ifndef SERIALIZERS_CAN_SEND_H
#define SERIALIZERS_CAN_SEND_H

#include "can_send.pb.h"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Can
{
enum class CanSendMode
{
    can_send_mode_once = 0,
    can_send_mode_periodic = 1
};

enum class CanSendAction
{
    can_send_action_set = 0,
    can_send_action_send = 1,
    can_send_action_remove = 2,
    can_send_action_clear = 3,
    can_send_action_get = 4
};

struct CanSendMessage
{
    std::string name{};
    std::string device{};
    std::string network{};
    uint32_t id{};
    std::string fields{};
    CanSendMode mode{};
    double frequencyHz{};
    bool enabled{};
    
    CanSendMessage() = default;
    CanSendMessage(const PbCan::CanSendMessage& protobuf);
    operator PbCan::CanSendMessage() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CanSendRequest
{
    CanSendAction action{};
    CanSendMessage message{};
    
    CanSendRequest() = default;
    CanSendRequest(const PbCan::CanSendRequest& protobuf);
    operator PbCan::CanSendRequest() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CanSendList
{
    std::vector<CanSendMessage> messages;
    
    CanSendList() = default;
    CanSendList(const PbCan::CanSendList& protobuf);
    operator PbCan::CanSendList() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif