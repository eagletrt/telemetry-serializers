from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from telemetry import wait_ready_pb2
from google.protobuf.json_format import MessageToJson, Parse

class ReadyStatus(Enum):
    WAITING = 0
    READY = 1


@dataclass
class ReplayReady:
    status: ReadyStatus = None
    
    _proto_message: wait_ready_pb2.ReplayReady = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = wait_ready_pb2.ReplayReady()

    def _populate_proto(self):
        self._proto_message.status = self.status.value

    @classmethod
    def _from_proto(cls, proto_message) -> "ReplayReady":
        return cls(
            status = ReadyStatus(proto_message.status),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "ReplayReady":
        message = wait_ready_pb2.ReplayReady()
        message.ParseFromString(data)
        return cls(
            status = ReadyStatus(message.status),
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ReplayReady":
        message = wait_ready_pb2.ReplayReady()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class ReplayStart:
    startTimestamp: int = 0
    
    _proto_message: wait_ready_pb2.ReplayStart = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = wait_ready_pb2.ReplayStart()

    def _populate_proto(self):
        self._proto_message.startTimestamp = self.startTimestamp

    @classmethod
    def _from_proto(cls, proto_message) -> "ReplayStart":
        return cls(
            startTimestamp = proto_message.startTimestamp,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "ReplayStart":
        message = wait_ready_pb2.ReplayStart()
        message.ParseFromString(data)
        return cls(
            startTimestamp = message.startTimestamp,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ReplayStart":
        message = wait_ready_pb2.ReplayStart()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
