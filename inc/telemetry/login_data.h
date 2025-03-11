#ifndef SERIALIZERS_LOGIN_DATA_H
#define SERIALIZERS_LOGIN_DATA_H

#include "login_data.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Telemetry
{
struct LoginData
{
    std::string username;
    std::string password;
    
    LoginData() = default;
    LoginData(const PbTelemetry::LoginData& protobuf);
    operator PbTelemetry::LoginData() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif