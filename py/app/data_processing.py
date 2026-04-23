from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from app import data_processing_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Plugin:
    path: str = ""
    
    _proto_message: data_processing_pb2.Plugin = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = data_processing_pb2.Plugin()

    def _populate_proto(self):
        self._proto_message.path = self.path

    @classmethod
    def _from_proto(cls, proto_message) -> "Plugin":
        return cls(
            path = proto_message.path,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Plugin":
        message = data_processing_pb2.Plugin()
        message.ParseFromString(data)
        return cls(
            path = message.path,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Plugin":
        message = data_processing_pb2.Plugin()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Signal:
    msg: str = ""
    fields: List[str] = field(default_factory=list)
    
    _proto_message: data_processing_pb2.Signal = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = data_processing_pb2.Signal()

    def _populate_proto(self):
        self._proto_message.msg = self.msg
        del self._proto_message.fields[:]
        for val in self.fields:
            self._proto_message.fields.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "Signal":
        return cls(
            msg = proto_message.msg,
            fields=[str(val) for val in proto_message.fields],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Signal":
        message = data_processing_pb2.Signal()
        message.ParseFromString(data)
        return cls(
            msg = message.msg,
            fields = [str(val) for val in message.fields],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Signal":
        message = data_processing_pb2.Signal()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class DataProcessing:
    plugins: List[Plugin] = field(default_factory=list)
    resampledSignals: List[Signal] = field(default_factory=list)
    
    _proto_message: data_processing_pb2.DataProcessing = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = data_processing_pb2.DataProcessing()

    def _populate_proto(self):
        del self._proto_message.plugins[:]
        for val in self.plugins:
            val._populate_proto()
            tmp = self._proto_message.plugins.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.resampledSignals[:]
        for val in self.resampledSignals:
            val._populate_proto()
            tmp = self._proto_message.resampledSignals.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "DataProcessing":
        return cls(
            plugins=[Plugin._from_proto(val) for val in proto_message.plugins],
            resampledSignals=[Signal._from_proto(val) for val in proto_message.resampledSignals],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DataProcessing":
        message = data_processing_pb2.DataProcessing()
        message.ParseFromString(data)
        return cls(
            plugins = [Plugin._from_proto(val) for val in message.plugins],
            resampledSignals = [Signal._from_proto(val) for val in message.resampledSignals],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DataProcessing":
        message = data_processing_pb2.DataProcessing()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
