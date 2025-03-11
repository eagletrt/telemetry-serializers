from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from actions import command_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Command:
    input: str = ""
    output: str = ""
    
    _proto_message: command_pb2.Command = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = command_pb2.Command()

    def _populate_proto(self):
        self._proto_message.input = self.input
        self._proto_message.output = self.output

    @classmethod
    def _from_proto(cls, proto_message) -> "Command":
        return cls(
            input = proto_message.input,
            output = proto_message.output,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Command":
        message = command_pb2.Command()
        message.ParseFromString(data)
        return cls(
            input = message.input,
            output = message.output,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Command":
        message = command_pb2.Command()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
