from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from data import vehicle_state_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class VehicleState:
    x: float = 0.0
    y: float = 0.0
    heading: float = 0.0
    u: float = 0.0
    v: float = 0.0
    
    _proto_message: vehicle_state_pb2.VehicleState = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = vehicle_state_pb2.VehicleState()

    def populate_proto(self):
        self._proto_message.x = self.x
        self._proto_message.y = self.y
        self._proto_message.heading = self.heading
        self._proto_message.u = self.u
        self._proto_message.v = self.v

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "VehicleState":
        message = vehicle_state_pb2.VehicleState()
        message.ParseFromString(data)
        return cls(
            x=message.x,
            y=message.y,
            heading=message.heading,
            u=message.u,
            v=message.v,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "VehicleState":
        message = vehicle_state_pb2.VehicleState()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
