from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from mongodb import lapcounter_layout_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Vec2:
    x: float = 0.0
    y: float = 0.0
    
    _proto_message: lapcounter_layout_pb2.Vec2 = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_layout_pb2.Vec2()

    def _populate_proto(self):
        self._proto_message.x = self.x
        self._proto_message.y = self.y

    @classmethod
    def _from_proto(cls, proto_message) -> "Vec2":
        return cls(
            x = proto_message.x,
            y = proto_message.y,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Vec2":
        message = lapcounter_layout_pb2.Vec2()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Vec2":
        message = lapcounter_layout_pb2.Vec2()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class PositionAndDirection:
    position: Vec2 = None
    direction: Vec2 = None
    
    _proto_message: lapcounter_layout_pb2.PositionAndDirection = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_layout_pb2.PositionAndDirection()

    def _populate_proto(self):
        if self.position:
            self.position._populate_proto()
            self._proto_message.position.CopyFrom(self.position._proto_message)
        if self.direction:
            self.direction._populate_proto()
            self._proto_message.direction.CopyFrom(self.direction._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "PositionAndDirection":
        return cls(
            position = Vec2._from_proto(proto_message.position),
            direction = Vec2._from_proto(proto_message.direction),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "PositionAndDirection":
        message = lapcounter_layout_pb2.PositionAndDirection()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "PositionAndDirection":
        message = lapcounter_layout_pb2.PositionAndDirection()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Layout:
    version: int = 0
    baseline_version: int = 0
    vehicle_id: str = ""
    device_id: str = ""
    location: str = ""
    layout: str = ""
    start_line: PositionAndDirection = None
    finish_line: PositionAndDirection = None
    sectors: List[PositionAndDirection] = field(default_factory=list)
    baseline_hash: str = ""
    start_s: float = 0.0
    sectors_s: List[float] = field(default_factory=list)
    baseline_length: float = 0.0
    
    _proto_message: lapcounter_layout_pb2.Layout = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_layout_pb2.Layout()

    def _populate_proto(self):
        self._proto_message.version = self.version
        self._proto_message.baseline_version = self.baseline_version
        self._proto_message.vehicle_id = self.vehicle_id
        self._proto_message.device_id = self.device_id
        self._proto_message.location = self.location
        self._proto_message.layout = self.layout
        if self.start_line:
            self.start_line._populate_proto()
            self._proto_message.start_line.CopyFrom(self.start_line._proto_message)
        if self.finish_line:
            self.finish_line._populate_proto()
            self._proto_message.finish_line.CopyFrom(self.finish_line._proto_message)
        del self._proto_message.sectors[:]
        for val in self.sectors:
            val._populate_proto()
            tmp = self._proto_message.sectors.add()
            tmp.CopyFrom(val._proto_message)
        self._proto_message.baseline_hash = self.baseline_hash
        self._proto_message.start_s = self.start_s
        del self._proto_message.sectors_s[:]
        for val in self.sectors_s:
            self._proto_message.sectors_s.append(val)
        self._proto_message.baseline_length = self.baseline_length

    @classmethod
    def _from_proto(cls, proto_message) -> "Layout":
        return cls(
            version = proto_message.version,
            baseline_version = proto_message.baseline_version,
            vehicle_id = proto_message.vehicle_id,
            device_id = proto_message.device_id,
            location = proto_message.location,
            layout = proto_message.layout,
            start_line = PositionAndDirection._from_proto(proto_message.start_line),
            finish_line = PositionAndDirection._from_proto(proto_message.finish_line),
            sectors=[PositionAndDirection._from_proto(val) for val in proto_message.sectors],
            baseline_hash = proto_message.baseline_hash,
            start_s = proto_message.start_s,
            sectors_s=[float(val) for val in proto_message.sectors_s],
            baseline_length = proto_message.baseline_length,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Layout":
        message = lapcounter_layout_pb2.Layout()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Layout":
        message = lapcounter_layout_pb2.Layout()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
