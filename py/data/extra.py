from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from data import extra_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class RepeatedValueUint64:
    values: List[int] = field(default_factory=list)
    
    _proto_message: extra_pb2.RepeatedValueUint64 = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = extra_pb2.RepeatedValueUint64()

    def populate_proto(self):
        del self._proto_message.values[:]
        for value in self.values:
            value.populate_proto()
            tmp = self._proto_message.values.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "RepeatedValueUint64":
        message = extra_pb2.RepeatedValueUint64()
        message.ParseFromString(data)
        return cls(
            values = [int(value) for value in message.values],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "RepeatedValueUint64":
        message = extra_pb2.RepeatedValueUint64()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "RepeatedValueUint64":
        return cls(
            values = proto_message.values,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class RepeatedValueDouble:
    values: List[float] = field(default_factory=list)
    
    _proto_message: extra_pb2.RepeatedValueDouble = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = extra_pb2.RepeatedValueDouble()

    def populate_proto(self):
        del self._proto_message.values[:]
        for value in self.values:
            value.populate_proto()
            tmp = self._proto_message.values.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "RepeatedValueDouble":
        message = extra_pb2.RepeatedValueDouble()
        message.ParseFromString(data)
        return cls(
            values = [float(value) for value in message.values],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "RepeatedValueDouble":
        message = extra_pb2.RepeatedValueDouble()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "RepeatedValueDouble":
        return cls(
            values = proto_message.values,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class ValuesMap:
    timestamp: RepeatedValueUint64 = None
    valuesMap: Dict[str, RepeatedValueDouble] = field(default_factory=dict)
    
    _proto_message: extra_pb2.ValuesMap = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = extra_pb2.ValuesMap()

    def populate_proto(self):
        if self.timestamp:
            self.timestamp.populate_proto()
            self._proto_message.timestamp.CopyFrom(self.timestamp._proto_message)
        self._proto_message.valuesMap.clear()
        for key, value in self.valuesMap.items():
            value.populate_proto()
            tmp = self._proto_message.valuesMap.setdefault(key)
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "ValuesMap":
        message = extra_pb2.ValuesMap()
        message.ParseFromString(data)
        return cls(
            timestamp = (
                RepeatedValueUint64.from_proto(message.timestamp)
                if message.HasField("timestamp")
                else None
            ),
            valuesMap = {key: value for key, value in message.valuesMap.items()},
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ValuesMap":
        message = extra_pb2.ValuesMap()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "ValuesMap":
        return cls(
            timestamp = proto_message.timestamp,
            valuesMap = proto_message.valuesMap,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class TimeValuesPack:
    valuesPack: Dict[str, ValuesMap] = field(default_factory=dict)
    
    _proto_message: extra_pb2.TimeValuesPack = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = extra_pb2.TimeValuesPack()

    def populate_proto(self):
        self._proto_message.valuesPack.clear()
        for key, value in self.valuesPack.items():
            value.populate_proto()
            tmp = self._proto_message.valuesPack.setdefault(key)
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "TimeValuesPack":
        message = extra_pb2.TimeValuesPack()
        message.ParseFromString(data)
        return cls(
            valuesPack = {key: value for key, value in message.valuesPack.items()},
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TimeValuesPack":
        message = extra_pb2.TimeValuesPack()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "TimeValuesPack":
        return cls(
            valuesPack = proto_message.valuesPack,
        )

    def __str__(self):
        return self.serializeAsJsonString()
