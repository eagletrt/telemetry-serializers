from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from telemetry import status_pb2
from google.protobuf.json_format import MessageToJson, Parse

class TelemetryState(Enum):
    INIT = 0
    IDLE = 1
    SETUP_RUN = 2
    RUN = 3
    WAIT_READY = 4
    ERROR = 5


@dataclass
class MessagesPerSecond:
    deviceName: str = ""
    bitsPerSecond: int = 0
    busLoad: float = 0.0
    count: int = 0
    
    _proto_message: status_pb2.MessagesPerSecond = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = status_pb2.MessagesPerSecond()

    def _populate_proto(self):
        self._proto_message.deviceName = self.deviceName
        self._proto_message.bitsPerSecond = self.bitsPerSecond
        self._proto_message.busLoad = self.busLoad
        self._proto_message.count = self.count

    @classmethod
    def _from_proto(cls, proto_message) -> "MessagesPerSecond":
        return cls(
            deviceName = proto_message.deviceName,
            bitsPerSecond = proto_message.bitsPerSecond,
            busLoad = proto_message.busLoad,
            count = proto_message.count,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "MessagesPerSecond":
        message = status_pb2.MessagesPerSecond()
        message.ParseFromString(data)
        return cls(
            deviceName = message.deviceName,
            bitsPerSecond = message.bitsPerSecond,
            busLoad = message.busLoad,
            count = message.count,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "MessagesPerSecond":
        message = status_pb2.MessagesPerSecond()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Status:
    timestamp: int = 0
    zeroTimestamp: int = 0
    state: TelemetryState = None
    cpuTotalLoad: int = 0
    cpuProcessLoad: int = 0
    memProcessLoad: int = 0
    canlibBuildTime: int = 0
    telemetryBuildTime: int = 0
    messagesPerSecond: List[MessagesPerSecond] = field(default_factory=list)
    
    _proto_message: status_pb2.Status = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = status_pb2.Status()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.zeroTimestamp = self.zeroTimestamp
        self._proto_message.state = self.state.value
        self._proto_message.cpuTotalLoad = self.cpuTotalLoad
        self._proto_message.cpuProcessLoad = self.cpuProcessLoad
        self._proto_message.memProcessLoad = self.memProcessLoad
        self._proto_message.canlibBuildTime = self.canlibBuildTime
        self._proto_message.telemetryBuildTime = self.telemetryBuildTime
        del self._proto_message.messagesPerSecond[:]
        for val in self.messagesPerSecond:
            val._populate_proto()
            tmp = self._proto_message.messagesPerSecond.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Status":
        return cls(
            timestamp = proto_message.timestamp,
            zeroTimestamp = proto_message.zeroTimestamp,
            state = TelemetryState._from_proto(proto_message.state),
            cpuTotalLoad = proto_message.cpuTotalLoad,
            cpuProcessLoad = proto_message.cpuProcessLoad,
            memProcessLoad = proto_message.memProcessLoad,
            canlibBuildTime = proto_message.canlibBuildTime,
            telemetryBuildTime = proto_message.telemetryBuildTime,
            messagesPerSecond=[MessagesPerSecond._from_proto(val) for val in proto_message.messagesPerSecond],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Status":
        message = status_pb2.Status()
        message.ParseFromString(data)
        return cls(
            timestamp = message.timestamp,
            zeroTimestamp = message.zeroTimestamp,
            state = TelemetryState(message.state),
            cpuTotalLoad = message.cpuTotalLoad,
            cpuProcessLoad = message.cpuProcessLoad,
            memProcessLoad = message.memProcessLoad,
            canlibBuildTime = message.canlibBuildTime,
            telemetryBuildTime = message.telemetryBuildTime,
            messagesPerSecond = [MessagesPerSecond._from_proto(val) for val in message.messagesPerSecond],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Status":
        message = status_pb2.Status()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
