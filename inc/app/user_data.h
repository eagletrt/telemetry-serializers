#ifndef SERIALIZERS_USER_DATA_H
#define SERIALIZERS_USER_DATA_H

#include "user_data.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace App
{
struct UserData
{
    std::string username;
    std::string token;
    std::string refreshToken;
    double expiry;
    uint64_t role;
    
    UserData() = default;
    UserData(const PbApp::UserData& protobuf);
    operator PbApp::UserData() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif