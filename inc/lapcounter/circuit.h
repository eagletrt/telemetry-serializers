#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "circuit.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef LapCounter::Vector LapCounterVector;
typedef LapCounter::Circuit LapCounterCircuit;

namespace Serializers
{
namespace LapCounter
{
struct Vector
{
    double x;
    double y;
    
    Vector() = default;
    Vector(const LapCounterVector& proto);
    operator LapCounterVector() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Circuit
{
    Vector startPosition;
    Vector startDirection;
    std::vector<Vector> sectorsPositions;
    std::vector<Vector> sectorsDirections;
    
    Circuit() = default;
    Circuit(const LapCounterCircuit& proto);
    operator LapCounterCircuit() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif