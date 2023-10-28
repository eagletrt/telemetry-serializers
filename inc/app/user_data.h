#ifndef USER_DATA_H
#define USER_DATA_H

#include "user_data.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef App::UserData AppUserData;

namespace Serializers
{
namespace App
{
struct UserData
{
    std::string username;
    std::string token;
    std::string refresh_token;
    double expiry;
    uint64_t role;
    
    UserData() = default;
    UserData(const AppUserData& proto);
    operator AppUserData() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif