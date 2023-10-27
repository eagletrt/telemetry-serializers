#ifndef FOO_H
#define FOO_H

#include "foo.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
struct AnotherSmallMessage
{
    int64_t val;
    
    AnotherSmallMessage() = default;
    AnotherSmallMessage(const bar::AnotherSmallMessage& proto);
    operator bar::AnotherSmallMessage() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}

#endif