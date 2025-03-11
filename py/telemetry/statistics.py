from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from telemetry import statistics_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Statistics:
    messages: int = 0
    averageFrequency: int = 0
    seconds: float = 0.0
    
    _proto_message: statistics_pb2.Statistics = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = statistics_pb2.Statistics()

    def _populate_proto(self):
        self._proto_message.messages = self.messages
        self._proto_message.averageFrequency = self.averageFrequency
        self._proto_message.seconds = self.seconds

    @classmethod
    def _from_proto(cls, proto_message) -> "Statistics":
        return cls(
            messages = proto_message.messages,
            averageFrequency = proto_message.averageFrequency,
            seconds = proto_message.seconds,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Statistics":
        message = statistics_pb2.Statistics()
        message.ParseFromString(data)
        return cls(
            messages = message.messages,
            averageFrequency = message.averageFrequency,
            seconds = message.seconds,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Statistics":
        message = statistics_pb2.Statistics()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
