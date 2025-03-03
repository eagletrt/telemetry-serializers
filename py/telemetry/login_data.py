from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from telemetry import login_data_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class LoginData:
    username: str = ""
    password: str = ""
    
    _proto_message: login_data_pb2.LoginData = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = login_data_pb2.LoginData()

    def _populate_proto(self):
        self._proto_message.username = self.username
        self._proto_message.password = self.password

    @classmethod
    def _from_proto(cls, proto_message) -> "LoginData":
        return cls(
            username = proto_message.username,
            password = proto_message.password,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LoginData":
        message = login_data_pb2.LoginData()
        message.ParseFromString(data)
        return cls(
            username = message.username,
            password = message.password,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LoginData":
        message = login_data_pb2.LoginData()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
