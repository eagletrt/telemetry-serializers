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

    def populate_proto(self):
        self._proto_message.input = self.input
        self._proto_message.output = self.output

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Command":
        message = command_pb2.Command()
        message.ParseFromString(data)
        return cls(
            input=message.input,
            output=message.output,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Command":
        message = command_pb2.Command()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
