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
        return cls(
            x = message.x,
            y = message.y,
        )

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
        return cls(
            position = (
                Vector._from_proto(message.position)
                if message.HasField("position")
                else None
            ),
            direction = (
                Vector._from_proto(message.direction)
                if message.HasField("direction")
                else None
            ),
        )

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
        return cls(
            circuitId = message.circuitId,
            checksLines = [Line._from_proto(val) for val in message.checksLines],
            sectorsLines = [Line._from_proto(val) for val in message.sectorsLines],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Circuit":
        message = lapcounter_pb2.Circuit()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Lap:
    number: int = 0
    startTimestamp: int = 0
    endTimestamp: int = 0
    sectorsTimestamps: List[int] = field(default_factory=list)
    
    _proto_message: lapcounter_pb2.Lap = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Lap()

    def _populate_proto(self):
        self._proto_message.number = self.number
        self._proto_message.startTimestamp = self.startTimestamp
        self._proto_message.endTimestamp = self.endTimestamp
        del self._proto_message.sectorsTimestamps[:]
        for val in self.sectorsTimestamps:
            self._proto_message.sectorsTimestamps.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "Lap":
        return cls(
            number = proto_message.number,
            startTimestamp = proto_message.startTimestamp,
            endTimestamp = proto_message.endTimestamp,
            sectorsTimestamps=[int(val) for val in proto_message.sectorsTimestamps],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Lap":
        message = lapcounter_pb2.Lap()
        message.ParseFromString(data)
        return cls(
            number = message.number,
            startTimestamp = message.startTimestamp,
            endTimestamp = message.endTimestamp,
            sectorsTimestamps = [int(val) for val in message.sectorsTimestamps],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Lap":
        message = lapcounter_pb2.Lap()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Race:
    raceId: str = ""
    circuitId: str = ""
    driverId: str = ""
    laps: List[Lap] = field(default_factory=list)
    
    _proto_message: lapcounter_pb2.Race = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_pb2.Race()

    def _populate_proto(self):
        self._proto_message.raceId = self.raceId
        self._proto_message.circuitId = self.circuitId
        self._proto_message.driverId = self.driverId
        del self._proto_message.laps[:]
        for val in self.laps:
            val._populate_proto()
            tmp = self._proto_message.laps.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Race":
        return cls(
            raceId = proto_message.raceId,
            circuitId = proto_message.circuitId,
            driverId = proto_message.driverId,
            laps=[Lap._from_proto(val) for val in proto_message.laps],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Race":
        message = lapcounter_pb2.Race()
        message.ParseFromString(data)
        return cls(
            raceId = message.raceId,
            circuitId = message.circuitId,
            driverId = message.driverId,
            laps = [Lap._from_proto(val) for val in message.laps],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Race":
        message = lapcounter_pb2.Race()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
