from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from data import extra_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class RepeatedValue:
    values: List[float] = field(default_factory=list)
    
    _proto_message: extra_pb2.RepeatedValue = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = extra_pb2.RepeatedValue()

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
    def deserializeFromProtobufString(cls, data: bytes) -> "RepeatedValue":
        message = extra_pb2.RepeatedValue()
        message.ParseFromString(data)
        return cls(
            values=[float(value) for value in message.values],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "RepeatedValue":
        message = extra_pb2.RepeatedValue()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class ValuesMap:
    valuesMap: Dict[str, RepeatedValue] = field(default_factory=dict)
    
    _proto_message: extra_pb2.ValuesMap = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = extra_pb2.ValuesMap()

    def populate_proto(self):
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
            valuesMap={key: value for key, value in message.valuesMap.items()},
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ValuesMap":
        message = extra_pb2.ValuesMap()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

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
            valuesPack={key: value for key, value in message.valuesPack.items()},
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TimeValuesPack":
        message = extra_pb2.TimeValuesPack()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
