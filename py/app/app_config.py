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

    def populate_proto(self):
        self._proto_message.ip = self.ip
        self._proto_message.port = self.port
        self._proto_message.mode = self.mode

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Connection":
        message = app_config_pb2.Connection()
        message.ParseFromString(data)
        return cls(
            ip=message.ip,
            port=message.port,
            mode=message.mode,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Connection":
        message = app_config_pb2.Connection()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

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

    def populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.message = self.message
        self._proto_message.signal = self.signal
        self._proto_message.comparator = self.comparator
        self._proto_message.value = self.value
        self._proto_message.color = self.color

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DoubleTrigger":
        message = app_config_pb2.DoubleTrigger()
        message.ParseFromString(data)
        return cls(
            id=message.id,
            message=message.message,
            signal=message.signal,
            comparator=message.comparator,
            value=message.value,
            color=message.color,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DoubleTrigger":
        message = app_config_pb2.DoubleTrigger()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

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

    def populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.message = self.message
        self._proto_message.signal = self.signal
        self._proto_message.comparator = self.comparator
        self._proto_message.value = self.value
        self._proto_message.color = self.color

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "EnumTrigger":
        message = app_config_pb2.EnumTrigger()
        message.ParseFromString(data)
        return cls(
            id=message.id,
            message=message.message,
            signal=message.signal,
            comparator=message.comparator,
            value=message.value,
            color=message.color,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "EnumTrigger":
        message = app_config_pb2.EnumTrigger()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

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

    def populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.message = self.message
        self._proto_message.signal = self.signal
        self._proto_message.comparator = self.comparator
        self._proto_message.value = self.value
        self._proto_message.color = self.color

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "BitTrigger":
        message = app_config_pb2.BitTrigger()
        message.ParseFromString(data)
        return cls(
            id=message.id,
            message=message.message,
            signal=message.signal,
            comparator=message.comparator,
            value=message.value,
            color=message.color,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "BitTrigger":
        message = app_config_pb2.BitTrigger()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class AxisItem:
    message: str = ""
    signal: str = ""
    isEnum: bool = ""
    color: int = 0
    
    _proto_message: app_config_pb2.AxisItem = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.AxisItem()

    def populate_proto(self):
        self._proto_message.message = self.message
        self._proto_message.signal = self.signal
        self._proto_message.isEnum = self.isEnum
        self._proto_message.color = self.color

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "AxisItem":
        message = app_config_pb2.AxisItem()
        message.ParseFromString(data)
        return cls(
            message=message.message,
            signal=message.signal,
            isEnum=message.isEnum,
            color=message.color,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "AxisItem":
        message = app_config_pb2.AxisItem()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class Axis:
    name: str = ""
    items: List[AxisItem] = field(default_factory=list)
    
    _proto_message: app_config_pb2.Axis = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.Axis()

    def populate_proto(self):
        self._proto_message.name = self.name
        del self._proto_message.items[:]
        for value in self.items:
            value.populate_proto()
            tmp = self._proto_message.items.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Axis":
        message = app_config_pb2.Axis()
        message.ParseFromString(data)
        return cls(
            name=message.name,
            items=[AxisItem(value) for value in message.items],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Axis":
        message = app_config_pb2.Axis()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class CustomPlot:
    name: str = ""
    axes: Dict[int, Axis] = field(default_factory=dict)
    
    _proto_message: app_config_pb2.CustomPlot = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_config_pb2.CustomPlot()

    def populate_proto(self):
        self._proto_message.name = self.name
        self._proto_message.axes.clear()
        for key, value in self.axes.items():
            value.populate_proto()
            tmp = self._proto_message.axes.setdefault(key)
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CustomPlot":
        message = app_config_pb2.CustomPlot()
        message.ParseFromString(data)
        return cls(
            name=message.name,
            axes={key: value for key, value in message.axes.items()},
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CustomPlot":
        message = app_config_pb2.CustomPlot()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

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

    def populate_proto(self):
        self._proto_message.loginTimestamp = self.loginTimestamp
        self._proto_message.colorTheme = self.colorTheme
        if self.connection:
            self._proto_message.connection.CopyFrom(self.connection._proto_message)
        self._proto_message.savedConnections.clear()
        for key, value in self.savedConnections.items():
            value.populate_proto()
            tmp = self._proto_message.savedConnections.setdefault(key)
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.activeTabs[:]
        for value in self.activeTabs:
            value.populate_proto()
            tmp = self._proto_message.activeTabs.add()
            tmp.CopyFrom(value._proto_message)
        self._proto_message.filesPaths.clear()
        for key, value in self.filesPaths.items():
            value.populate_proto()
            tmp = self._proto_message.filesPaths.setdefault(key)
            tmp.CopyFrom(value._proto_message)
        self._proto_message.stringCache.clear()
        for key, value in self.stringCache.items():
            value.populate_proto()
            tmp = self._proto_message.stringCache.setdefault(key)
            tmp.CopyFrom(value._proto_message)
        self._proto_message.boolCache.clear()
        for key, value in self.boolCache.items():
            value.populate_proto()
            tmp = self._proto_message.boolCache.setdefault(key)
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.doubleTriggers[:]
        for value in self.doubleTriggers:
            value.populate_proto()
            tmp = self._proto_message.doubleTriggers.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.enumTriggers[:]
        for value in self.enumTriggers:
            value.populate_proto()
            tmp = self._proto_message.enumTriggers.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.bitTriggers[:]
        for value in self.bitTriggers:
            value.populate_proto()
            tmp = self._proto_message.bitTriggers.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.customPlots[:]
        for value in self.customPlots:
            value.populate_proto()
            tmp = self._proto_message.customPlots.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "AppConfig":
        message = app_config_pb2.AppConfig()
        message.ParseFromString(data)
        return cls(
            loginTimestamp=message.loginTimestamp,
            colorTheme=message.colorTheme,
            connection=message.connection,
            savedConnections={key: value for key, value in message.savedConnections.items()},
            activeTabs=[str(value) for value in message.activeTabs],
            filesPaths={key: value for key, value in message.filesPaths.items()},
            stringCache={key: value for key, value in message.stringCache.items()},
            boolCache={key: value for key, value in message.boolCache.items()},
            doubleTriggers=[DoubleTrigger(value) for value in message.doubleTriggers],
            enumTriggers=[EnumTrigger(value) for value in message.enumTriggers],
            bitTriggers=[BitTrigger(value) for value in message.bitTriggers],
            customPlots=[CustomPlot(value) for value in message.customPlots],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "AppConfig":
        message = app_config_pb2.AppConfig()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
