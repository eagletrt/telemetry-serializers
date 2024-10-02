#ifndef SERIALIZERS_LAPCOUNTER_LAYOUT_H
#define SERIALIZERS_LAPCOUNTER_LAYOUT_H

#include "lapcounter_layout.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace MongoDb
{
struct Vec2
{
    int32_t x;
    int32_t y;
    
    Vec2() = default;
    Vec2(const PbMongoDb::Vec2& protobuf);
    operator PbMongoDb::Vec2() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct PositionAndDirection
{
    Vec2 position;
    Vec2 direction;
    
    PositionAndDirection() = default;
    PositionAndDirection(const PbMongoDb::PositionAndDirection& protobuf);
    operator PbMongoDb::PositionAndDirection() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Layout
{
    int32_t version;
    int32_t baseline_version;
    std::string vehicle_id;
    std::string device_id;
    std::string location;
    std::string layout;
    PositionAndDirection start_line;
    PositionAndDirection finish_line;
    std::vector<PositionAndDirection> sectors;
    
    Layout() = default;
    Layout(const PbMongoDb::Layout& protobuf);
    operator PbMongoDb::Layout() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif