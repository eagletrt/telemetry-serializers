from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from lapcounter import lapcounter_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Vector:
    x: float = 0.0
    y: float = 0.0
    
    _proto_message: lapcounter_pb2.Vector = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Vector()

    def populate_proto(self):
        self._proto_message.x = self.x
        self._proto_message.y = self.y

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Vector":
        message = lapcounter_pb2.Vector()
        message.ParseFromString(data)
        return cls(
            x = message.x,
            y = message.y,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Vector":
        message = lapcounter_pb2.Vector()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "Vector":
        return cls(
            x = proto_message.x,
            y = proto_message.y,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class Line:
    position: Vector = None
    direction: Vector = None
    
    _proto_message: lapcounter_pb2.Line = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Line()

    def populate_proto(self):
        if self.position:
            self.position.populate_proto()
            self._proto_message.position.CopyFrom(self.position._proto_message)
        if self.direction:
            self.direction.populate_proto()
            self._proto_message.direction.CopyFrom(self.direction._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Line":
        message = lapcounter_pb2.Line()
        message.ParseFromString(data)
        return cls(
            position = (
                Vector.from_proto(message.position)
                if message.HasField("position")
                else None
            ),
            direction = (
                Vector.from_proto(message.direction)
                if message.HasField("direction")
                else None
            ),
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Line":
        message = lapcounter_pb2.Line()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "Line":
        return cls(
            position = proto_message.position,
            direction = proto_message.direction,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class Circuit:
    circuitId: str = ""
    checksLines: List[Line] = field(default_factory=list)
    sectorsLines: List[Line] = field(default_factory=list)
    
    _proto_message: lapcounter_pb2.Circuit = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Circuit()

    def populate_proto(self):
        self._proto_message.circuitId = self.circuitId
        del self._proto_message.checksLines[:]
        for value in self.checksLines:
            value.populate_proto()
            tmp = self._proto_message.checksLines.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.sectorsLines[:]
        for value in self.sectorsLines:
            value.populate_proto()
            tmp = self._proto_message.sectorsLines.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Circuit":
        message = lapcounter_pb2.Circuit()
        message.ParseFromString(data)
        return cls(
            circuitId = message.circuitId,
            checksLines = [Line.from_proto(value) for value in message.checksLines],
            sectorsLines = [Line.from_proto(value) for value in message.sectorsLines],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Circuit":
        message = lapcounter_pb2.Circuit()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "Circuit":
        return cls(
            circuitId = proto_message.circuitId,
            checksLines = proto_message.checksLines,
            sectorsLines = proto_message.sectorsLines,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class Lap:
    number: int = 0
    startTimestamp: int = 0
    endTimestamp: int = 0
    sectorsTimestamps: List[int] = field(default_factory=list)
    
    _proto_message: lapcounter_pb2.Lap = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Lap()

    def populate_proto(self):
        self._proto_message.number = self.number
        self._proto_message.startTimestamp = self.startTimestamp
        self._proto_message.endTimestamp = self.endTimestamp
        del self._proto_message.sectorsTimestamps[:]
        for value in self.sectorsTimestamps:
            value.populate_proto()
            tmp = self._proto_message.sectorsTimestamps.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Lap":
        message = lapcounter_pb2.Lap()
        message.ParseFromString(data)
        return cls(
            number = message.number,
            startTimestamp = message.startTimestamp,
            endTimestamp = message.endTimestamp,
            sectorsTimestamps = [int(value) for value in message.sectorsTimestamps],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Lap":
        message = lapcounter_pb2.Lap()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "Lap":
        return cls(
            number = proto_message.number,
            startTimestamp = proto_message.startTimestamp,
            endTimestamp = proto_message.endTimestamp,
            sectorsTimestamps = proto_message.sectorsTimestamps,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class Race:
    raceId: str = ""
    circuitId: str = ""
    driverId: str = ""
    laps: List[Lap] = field(default_factory=list)
    
    _proto_message: lapcounter_pb2.Race = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Race()

    def populate_proto(self):
        self._proto_message.raceId = self.raceId
        self._proto_message.circuitId = self.circuitId
        self._proto_message.driverId = self.driverId
        del self._proto_message.laps[:]
        for value in self.laps:
            value.populate_proto()
            tmp = self._proto_message.laps.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Race":
        message = lapcounter_pb2.Race()
        message.ParseFromString(data)
        return cls(
            raceId = message.raceId,
            circuitId = message.circuitId,
            driverId = message.driverId,
            laps = [Lap.from_proto(value) for value in message.laps],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Race":
        message = lapcounter_pb2.Race()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "Race":
        return cls(
            raceId = proto_message.raceId,
            circuitId = proto_message.circuitId,
            driverId = proto_message.driverId,
            laps = proto_message.laps,
        )

    def __str__(self):
        return self.serializeAsJsonString()
