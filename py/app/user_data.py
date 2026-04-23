from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from app import user_data_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class UserData:
    username: str = ""
    token: str = ""
    refreshToken: str = ""
    expiry: float = 0.0
    role: int = 0
    
    _proto_message: user_data_pb2.UserData = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = user_data_pb2.UserData()

    def _populate_proto(self):
        self._proto_message.username = self.username
        self._proto_message.token = self.token
        self._proto_message.refreshToken = self.refreshToken
        self._proto_message.expiry = self.expiry
        self._proto_message.role = self.role

    @classmethod
    def _from_proto(cls, proto_message) -> "UserData":
        return cls(
            username = proto_message.username,
            token = proto_message.token,
            refreshToken = proto_message.refreshToken,
            expiry = proto_message.expiry,
            role = proto_message.role,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "UserData":
        message = user_data_pb2.UserData()
        message.ParseFromString(data)
        return cls(
            username = message.username,
            token = message.token,
            refreshToken = message.refreshToken,
            expiry = message.expiry,
            role = message.role,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "UserData":
        message = user_data_pb2.UserData()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
