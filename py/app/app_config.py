from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from app import app_config_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Connection:
    ip: str = ""
    port: str = ""
    mode: str = ""
    
    _proto_message: app_config_pb2.Connection = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.Connection()

    def _populate_proto(self):
        self._proto_message.ip = self.ip
        self._proto_message.port = self.port
        self._proto_message.mode = self.mode

    @classmethod
    def _from_proto(cls, proto_message) -> "Connection":
        return cls(
            ip = proto_message.ip,
            port = proto_message.port,
            mode = proto_message.mode,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Connection":
        message = app_config_pb2.Connection()
        message.ParseFromString(data)
        return cls(
            ip = message.ip,
            port = message.port,
            mode = message.mode,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Connection":
        message = app_config_pb2.Connection()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class DoubleTrigger:
    id: str = ""
    message: str = ""
    signal: str = ""
    comparator: int = 0
    value: float = 0.0
    color: int = 0
    
    _proto_message: app_config_pb2.DoubleTrigger = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.DoubleTrigger()

    def _populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.message = self.message
        self._proto_message.signal = self.signal
        self._proto_message.comparator = self.comparator
        self._proto_message.value = self.value
        self._proto_message.color = self.color

    @classmethod
    def _from_proto(cls, proto_message) -> "DoubleTrigger":
        return cls(
            id = proto_message.id,
            message = proto_message.message,
            signal = proto_message.signal,
            comparator = proto_message.comparator,
            value = proto_message.value,
            color = proto_message.color,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DoubleTrigger":
        message = app_config_pb2.DoubleTrigger()
        message.ParseFromString(data)
        return cls(
            id = message.id,
            message = message.message,
            signal = message.signal,
            comparator = message.comparator,
            value = message.value,
            color = message.color,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DoubleTrigger":
        message = app_config_pb2.DoubleTrigger()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class EnumTrigger:
    id: str = ""
    message: str = ""
    signal: str = ""
    comparator: int = 0
    value: int = 0
    color: int = 0
    
    _proto_message: app_config_pb2.EnumTrigger = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.EnumTrigger()

    def _populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.message = self.message
        self._proto_message.signal = self.signal
        self._proto_message.comparator = self.comparator
        self._proto_message.value = self.value
        self._proto_message.color = self.color

    @classmethod
    def _from_proto(cls, proto_message) -> "EnumTrigger":
        return cls(
            id = proto_message.id,
            message = proto_message.message,
            signal = proto_message.signal,
            comparator = proto_message.comparator,
            value = proto_message.value,
            color = proto_message.color,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "EnumTrigger":
        message = app_config_pb2.EnumTrigger()
        message.ParseFromString(data)
        return cls(
            id = message.id,
            message = message.message,
            signal = message.signal,
            comparator = message.comparator,
            value = message.value,
            color = message.color,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "EnumTrigger":
        message = app_config_pb2.EnumTrigger()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class BitTrigger:
    id: str = ""
    message: str = ""
    signal: str = ""
    comparator: int = 0
    value: int = 0
    color: int = 0
    
    _proto_message: app_config_pb2.BitTrigger = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.BitTrigger()

    def _populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.message = self.message
        self._proto_message.signal = self.signal
        self._proto_message.comparator = self.comparator
        self._proto_message.value = self.value
        self._proto_message.color = self.color

    @classmethod
    def _from_proto(cls, proto_message) -> "BitTrigger":
        return cls(
            id = proto_message.id,
            message = proto_message.message,
            signal = proto_message.signal,
            comparator = proto_message.comparator,
            value = proto_message.value,
            color = proto_message.color,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "BitTrigger":
        message = app_config_pb2.BitTrigger()
        message.ParseFromString(data)
        return cls(
            id = message.id,
            message = message.message,
            signal = message.signal,
            comparator = message.comparator,
            value = message.value,
            color = message.color,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "BitTrigger":
        message = app_config_pb2.BitTrigger()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class AxisItem:
    message: str = ""
    signal: str = ""
    isEnum: bool = False
    color: int = 0
    
    _proto_message: app_config_pb2.AxisItem = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.AxisItem()

    def _populate_proto(self):
        self._proto_message.message = self.message
        self._proto_message.signal = self.signal
        self._proto_message.isEnum = self.isEnum
        self._proto_message.color = self.color

    @classmethod
    def _from_proto(cls, proto_message) -> "AxisItem":
        return cls(
            message = proto_message.message,
            signal = proto_message.signal,
            isEnum = proto_message.isEnum,
            color = proto_message.color,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "AxisItem":
        message = app_config_pb2.AxisItem()
        message.ParseFromString(data)
        return cls(
            message = message.message,
            signal = message.signal,
            isEnum = message.isEnum,
            color = message.color,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "AxisItem":
        message = app_config_pb2.AxisItem()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Axis:
    name: str = ""
    items: List[AxisItem] = field(default_factory=list)
    
    _proto_message: app_config_pb2.Axis = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.Axis()

    def _populate_proto(self):
        self._proto_message.name = self.name
        del self._proto_message.items[:]
        for val in self.items:
            val._populate_proto()
            tmp = self._proto_message.items.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Axis":
        return cls(
            name = proto_message.name,
            items=[AxisItem._from_proto(val) for val in proto_message.items],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Axis":
        message = app_config_pb2.Axis()
        message.ParseFromString(data)
        return cls(
            name = message.name,
            items = [AxisItem._from_proto(val) for val in message.items],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Axis":
        message = app_config_pb2.Axis()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class CustomPlot:
    name: str = ""
    axes: Dict[int, Axis] = field(default_factory=dict)
    
    _proto_message: app_config_pb2.CustomPlot = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.CustomPlot()

    def _populate_proto(self):
        self._proto_message.name = self.name
        self._proto_message.axes.clear()
        for key, val in self.axes.items():
            val._populate_proto()
            tmp = self._proto_message.axes.setdefault(key)
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "CustomPlot":
        return cls(
            name = proto_message.name,
            axes={key: Axis._from_proto(val) for key, val in proto_message.axes.items()},
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CustomPlot":
        message = app_config_pb2.CustomPlot()
        message.ParseFromString(data)
        return cls(
            name = message.name,
            axes = {key: Axis._from_proto(val) for key, val in message.axes.items()},
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CustomPlot":
        message = app_config_pb2.CustomPlot()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class AppConfig:
    loginTimestamp: int = 0
    colorTheme: int = 0
    connection: Connection = None
    savedConnections: Dict[str, Connection] = field(default_factory=dict)
    activeTabs: List[str] = field(default_factory=list)
    filesPaths: Dict[str, str] = field(default_factory=dict)
    stringCache: Dict[str, str] = field(default_factory=dict)
    boolCache: Dict[str, bool] = field(default_factory=dict)
    doubleTriggers: List[DoubleTrigger] = field(default_factory=list)
    enumTriggers: List[EnumTrigger] = field(default_factory=list)
    bitTriggers: List[BitTrigger] = field(default_factory=list)
    customPlots: List[CustomPlot] = field(default_factory=list)
    
    _proto_message: app_config_pb2.AppConfig = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.AppConfig()

    def _populate_proto(self):
        self._proto_message.loginTimestamp = self.loginTimestamp
        self._proto_message.colorTheme = self.colorTheme
        if self.connection:
            self.connection._populate_proto()
            self._proto_message.connection.CopyFrom(self.connection._proto_message)
        self._proto_message.savedConnections.clear()
        for key, val in self.savedConnections.items():
            val._populate_proto()
            tmp = self._proto_message.savedConnections.setdefault(key)
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.activeTabs[:]
        for val in self.activeTabs:
            self._proto_message.activeTabs.append(val)
        self._proto_message.filesPaths.clear()
        for key, val in self.filesPaths.items():
            self._proto_message.filesPaths[key] = val
        self._proto_message.stringCache.clear()
        for key, val in self.stringCache.items():
            self._proto_message.stringCache[key] = val
        self._proto_message.boolCache.clear()
        for key, val in self.boolCache.items():
            self._proto_message.boolCache[key] = val
        del self._proto_message.doubleTriggers[:]
        for val in self.doubleTriggers:
            val._populate_proto()
            tmp = self._proto_message.doubleTriggers.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.enumTriggers[:]
        for val in self.enumTriggers:
            val._populate_proto()
            tmp = self._proto_message.enumTriggers.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.bitTriggers[:]
        for val in self.bitTriggers:
            val._populate_proto()
            tmp = self._proto_message.bitTriggers.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.customPlots[:]
        for val in self.customPlots:
            val._populate_proto()
            tmp = self._proto_message.customPlots.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "AppConfig":
        return cls(
            loginTimestamp = proto_message.loginTimestamp,
            colorTheme = proto_message.colorTheme,
            connection = Connection._from_proto(proto_message.connection),
            savedConnections={key: Connection._from_proto(val) for key, val in proto_message.savedConnections.items()},
            activeTabs=[str(val) for val in proto_message.activeTabs],
            filesPaths={key: str(val) for key, val in proto_message.filesPaths.items()},
            stringCache={key: str(val) for key, val in proto_message.stringCache.items()},
            boolCache={key: bool(val) for key, val in proto_message.boolCache.items()},
            doubleTriggers=[DoubleTrigger._from_proto(val) for val in proto_message.doubleTriggers],
            enumTriggers=[EnumTrigger._from_proto(val) for val in proto_message.enumTriggers],
            bitTriggers=[BitTrigger._from_proto(val) for val in proto_message.bitTriggers],
            customPlots=[CustomPlot._from_proto(val) for val in proto_message.customPlots],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "AppConfig":
        message = app_config_pb2.AppConfig()
        message.ParseFromString(data)
        return cls(
            loginTimestamp = message.loginTimestamp,
            colorTheme = message.colorTheme,
            connection = (
                Connection._from_proto(message.connection)
                if message.HasField("connection")
                else None
            ),
            savedConnections = {key: Connection._from_proto(val) for key, val in message.savedConnections.items()},
            activeTabs = [str(val) for val in message.activeTabs],
            filesPaths = {key: str(val) for key, val in message.filesPaths.items()},
            stringCache = {key: str(val) for key, val in message.stringCache.items()},
            boolCache = {key: bool(val) for key, val in message.boolCache.items()},
            doubleTriggers = [DoubleTrigger._from_proto(val) for val in message.doubleTriggers],
            enumTriggers = [EnumTrigger._from_proto(val) for val in message.enumTriggers],
            bitTriggers = [BitTrigger._from_proto(val) for val in message.bitTriggers],
            customPlots = [CustomPlot._from_proto(val) for val in message.customPlots],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "AppConfig":
        message = app_config_pb2.AppConfig()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
