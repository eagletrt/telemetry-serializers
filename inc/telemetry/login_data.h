#ifndef LOGIN_DATA_H
#define LOGIN_DATA_H

#include "login_data.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef Telemetry::LoginData TelemetryLoginData;

namespace Serializers
{
namespace Telemetry
{
struct LoginData
{
    std::string username;
    std::string password;
    
    LoginData() = default;
    LoginData(const TelemetryLoginData& proto);
    operator TelemetryLoginData() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif