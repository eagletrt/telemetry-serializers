from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from can import can_sand_pb2
from google.protobuf.json_format import MessageToJson, Parse

class CanSendMode(Enum):
    can_send_mode_once = 0
    can_send_mode_periodic = 1

class CanSendAction(Enum):
    can_send_action_set = 0
    can_send_action_send = 1
    can_send_action_remove = 2
    can_send_action_clear = 3
    can_send_action_get = 4


@dataclass
class CanSendMessage:
    name: str = ""
    device: str = ""
    network: str = ""
    id: int = 0
    fields: str = ""
    mode: CanSendMode = None
    frequencyHz: float = 0.0
    enabled: bool = False
    
    _proto_message: can_sand_pb2.CanSendMessage = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = can_sand_pb2.CanSendMessage()

    def _populate_proto(self):
        self._proto_message.name = self.name
        self._proto_message.device = self.device
        self._proto_message.network = self.network
        self._proto_message.id = self.id
        self._proto_message.fields = self.fields
        self._proto_message.mode = self.mode.value
        self._proto_message.frequencyHz = self.frequencyHz
        self._proto_message.enabled = self.enabled

    @classmethod
    def _from_proto(cls, proto_message) -> "CanSendMessage":
        return cls(
            name = proto_message.name,
            device = proto_message.device,
            network = proto_message.network,
            id = proto_message.id,
            fields = proto_message.fields,
            mode = CanSendMode(proto_message.mode),
            frequencyHz = proto_message.frequencyHz,
            enabled = proto_message.enabled,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CanSendMessage":
        message = can_sand_pb2.CanSendMessage()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CanSendMessage":
        message = can_sand_pb2.CanSendMessage()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class CanSendRequest:
    action: CanSendAction = None
    message: CanSendMessage = None
    
    _proto_message: can_sand_pb2.CanSendRequest = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = can_sand_pb2.CanSendRequest()

    def _populate_proto(self):
        self._proto_message.action = self.action.value
        if self.message:
            self.message._populate_proto()
            self._proto_message.message.CopyFrom(self.message._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "CanSendRequest":
        return cls(
            action = CanSendAction(proto_message.action),
            message = CanSendMessage._from_proto(proto_message.message),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CanSendRequest":
        message = can_sand_pb2.CanSendRequest()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CanSendRequest":
        message = can_sand_pb2.CanSendRequest()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class CanSendList:
    messages: List[CanSendMessage] = field(default_factory=list)
    
    _proto_message: can_sand_pb2.CanSendList = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = can_sand_pb2.CanSendList()

    def _populate_proto(self):
        del self._proto_message.messages[:]
        for val in self.messages:
            val._populate_proto()
            tmp = self._proto_message.messages.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "CanSendList":
        return cls(
            messages=[CanSendMessage._from_proto(val) for val in proto_message.messages],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CanSendList":
        message = can_sand_pb2.CanSendList()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CanSendList":
        message = can_sand_pb2.CanSendList()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
