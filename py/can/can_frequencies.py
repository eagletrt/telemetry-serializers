from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from can import can_frequencies_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class CanFrequency:
    timestamp: int = 0
    id: int = 0
    name: str = ""
    data: int = 0
    frequency: int = 0
    
    _proto_message: can_frequencies_pb2.CanFrequency = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = can_frequencies_pb2.CanFrequency()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.id = self.id
        self._proto_message.name = self.name
        self._proto_message.data = self.data
        self._proto_message.frequency = self.frequency

    @classmethod
    def _from_proto(cls, proto_message) -> "CanFrequency":
        return cls(
            timestamp = proto_message.timestamp,
            id = proto_message.id,
            name = proto_message.name,
            data = proto_message.data,
            frequency = proto_message.frequency,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CanFrequency":
        message = can_frequencies_pb2.CanFrequency()
        message.ParseFromString(data)
        return cls(
            timestamp = message.timestamp,
            id = message.id,
            name = message.name,
            data = message.data,
            frequency = message.frequency,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CanFrequency":
        message = can_frequencies_pb2.CanFrequency()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class CanFrequencies:
    frequencies: Dict[int, CanFrequency] = field(default_factory=dict)
    
    _proto_message: can_frequencies_pb2.CanFrequencies = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = can_frequencies_pb2.CanFrequencies()

    def _populate_proto(self):
        self._proto_message.frequencies.clear()
        for key, val in self.frequencies.items():
            val._populate_proto()
            tmp = self._proto_message.frequencies.setdefault(key)
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "CanFrequencies":
        return cls(
            frequencies={key: CanFrequency._from_proto(val) for key, val in proto_message.frequencies.items()},
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CanFrequencies":
        message = can_frequencies_pb2.CanFrequencies()
        message.ParseFromString(data)
        return cls(
            frequencies = {key: CanFrequency._from_proto(val) for key, val in message.frequencies.items()},
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CanFrequencies":
        message = can_frequencies_pb2.CanFrequencies()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class CanNetworksFrequencies:
    timestamp: int = 0
    networks: Dict[str, CanFrequencies] = field(default_factory=dict)
    
    _proto_message: can_frequencies_pb2.CanNetworksFrequencies = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = can_frequencies_pb2.CanNetworksFrequencies()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.networks.clear()
        for key, val in self.networks.items():
            val._populate_proto()
            tmp = self._proto_message.networks.setdefault(key)
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "CanNetworksFrequencies":
        return cls(
            timestamp = proto_message.timestamp,
            networks={key: CanFrequencies._from_proto(val) for key, val in proto_message.networks.items()},
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CanNetworksFrequencies":
        message = can_frequencies_pb2.CanNetworksFrequencies()
        message.ParseFromString(data)
        return cls(
            timestamp = message.timestamp,
            networks = {key: CanFrequencies._from_proto(val) for key, val in message.networks.items()},
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CanNetworksFrequencies":
        message = can_frequencies_pb2.CanNetworksFrequencies()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
