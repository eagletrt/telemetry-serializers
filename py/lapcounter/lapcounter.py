from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from lapcounter import lapcounter_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Vector:
    x: float = 0.0
    y: float = 0.0
    
    _proto_message: lapcounter_pb2.Vector = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Vector()

    def _populate_proto(self):
        self._proto_message.x = self.x
        self._proto_message.y = self.y

    @classmethod
    def _from_proto(cls, proto_message) -> "Vector":
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
    def deserializeFromProtobufString(cls, data: bytes) -> "Vector":
        message = lapcounter_pb2.Vector()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Vector":
        message = lapcounter_pb2.Vector()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Line:
    position: Vector = None
    direction: Vector = None
    
    _proto_message: lapcounter_pb2.Line = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Line()

    def _populate_proto(self):
        if self.position:
            self.position._populate_proto()
            self._proto_message.position.CopyFrom(self.position._proto_message)
        if self.direction:
            self.direction._populate_proto()
            self._proto_message.direction.CopyFrom(self.direction._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Line":
        return cls(
            position = Vector._from_proto(proto_message.position),
            direction = Vector._from_proto(proto_message.direction),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Line":
        message = lapcounter_pb2.Line()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Line":
        message = lapcounter_pb2.Line()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Circuit:
    circuitId: str = ""
    checksLines: List[Line] = field(default_factory=list)
    sectorsLines: List[Line] = field(default_factory=list)
    
    _proto_message: lapcounter_pb2.Circuit = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Circuit()

    def _populate_proto(self):
        self._proto_message.circuitId = self.circuitId
        del self._proto_message.checksLines[:]
        for val in self.checksLines:
            val._populate_proto()
            tmp = self._proto_message.checksLines.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.sectorsLines[:]
        for val in self.sectorsLines:
            val._populate_proto()
            tmp = self._proto_message.sectorsLines.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Circuit":
        return cls(
            circuitId = proto_message.circuitId,
            checksLines=[Line._from_proto(val) for val in proto_message.checksLines],
            sectorsLines=[Line._from_proto(val) for val in proto_message.sectorsLines],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Circuit":
        message = lapcounter_pb2.Circuit()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Circuit":
        message = lapcounter_pb2.Circuit()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
class Status(Enum):
    DISARMED = 0
    NO_INSTRUMENT = 1
    NO_POSITION = 2
    NO_PROJECTION = 3
    OFF_TRACK = 4
    OUT_LAP = 5
    TIMING = 6


@dataclass
class LapCounterStatus:
    status: Status = None
    dropped_laps: int = 0
    detail: str = ""
    
    _proto_message: lapcounter_pb2.LapCounterStatus = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.LapCounterStatus()

    def _populate_proto(self):
        self._proto_message.status = self.status.value
        self._proto_message.dropped_laps = self.dropped_laps
        self._proto_message.detail = self.detail

    @classmethod
    def _from_proto(cls, proto_message) -> "LapCounterStatus":
        return cls(
            status = Status(proto_message.status),
            dropped_laps = proto_message.dropped_laps,
            detail = proto_message.detail,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LapCounterStatus":
        message = lapcounter_pb2.LapCounterStatus()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapCounterStatus":
        message = lapcounter_pb2.LapCounterStatus()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
