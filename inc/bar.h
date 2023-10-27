#ifndef BAR_H
#define BAR_H

#include "bar.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
enum class MySmallEnum
{
    MY_SMALL_ENUM_0 = 0,
    My_SMALL_ENUM_1 = 1,
    My_SMALL_ENUM_2 = 2
};

enum class MyEnum
{
    MY_ENUM_0 = 0,
    My_ENUM_1 = 1,
    MY_ENUM_2 = 2
};

struct MySmallMessage
{
    int64_t val;
    
    MySmallMessage() = default;
    MySmallMessage(const bar::MySmallMessage& proto);
    operator bar::MySmallMessage() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct MyMessage
{
    double val;
    std::string str;
    MyEnum enm;
    MySmallMessage mySmallMessage;
    std::vector<MyEnum> enumVec;
    std::vector<MySmallMessage> structVec;
    std::unordered_map<uint32_t, std::string> stringMap;
    std::unordered_map<uint32_t, MyEnum> enumMap;
    std::unordered_map<uint32_t, MySmallMessage> structMap;
    
    MyMessage() = default;
    MyMessage(const bar::MyMessage& proto);
    operator bar::MyMessage() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}

#endif