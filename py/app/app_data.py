from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from app import app_data_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class CustomPlotItem:
    messageAxisX: str = ""
    messageAxisY: str = ""
    signalAxisX: str = ""
    signalAxisY: str = ""
    isEnum: bool = ""
    color: int = 0
    
    _proto_message: app_data_pb2.CustomPlotItem = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_data_pb2.CustomPlotItem()

    def populate_proto(self):
        self._proto_message.messageAxisX = self.messageAxisX
        self._proto_message.messageAxisY = self.messageAxisY
        self._proto_message.signalAxisX = self.signalAxisX
        self._proto_message.signalAxisY = self.signalAxisY
        self._proto_message.isEnum = self.isEnum
        self._proto_message.color = self.color

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CustomPlotItem":
        message = app_data_pb2.CustomPlotItem()
        message.ParseFromString(data)
        return cls(
            messageAxisX = message.messageAxisX,
            messageAxisY = message.messageAxisY,
            signalAxisX = message.signalAxisX,
            signalAxisY = message.signalAxisY,
            isEnum = message.isEnum,
            color = message.color,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CustomPlotItem":
        message = app_data_pb2.CustomPlotItem()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "CustomPlotItem":
        return cls(
            messageAxisX = proto_message.messageAxisX,
            messageAxisY = proto_message.messageAxisY,
            signalAxisX = proto_message.signalAxisX,
            signalAxisY = proto_message.signalAxisY,
            isEnum = proto_message.isEnum,
            color = proto_message.color,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class CustomPlotAxis:
    label: str = ""
    items: List[CustomPlotItem] = field(default_factory=list)
    
    _proto_message: app_data_pb2.CustomPlotAxis = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_data_pb2.CustomPlotAxis()

    def populate_proto(self):
        self._proto_message.label = self.label
        del self._proto_message.items[:]
        for value in self.items:
            value.populate_proto()
            tmp = self._proto_message.items.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CustomPlotAxis":
        message = app_data_pb2.CustomPlotAxis()
        message.ParseFromString(data)
        return cls(
            label = message.label,
            items = [CustomPlotItem.from_proto(value) for value in message.items],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CustomPlotAxis":
        message = app_data_pb2.CustomPlotAxis()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "CustomPlotAxis":
        return cls(
            label = proto_message.label,
            items = CustomPlotItem.from_proto(proto_message.items),
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class NewCustomPlot:
    title: str = ""
    axes: Dict[int, CustomPlotAxis] = field(default_factory=dict)
    
    _proto_message: app_data_pb2.NewCustomPlot = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_data_pb2.NewCustomPlot()

    def populate_proto(self):
        self._proto_message.title = self.title
        self._proto_message.axes.clear()
        for key, value in self.axes.items():
            value.populate_proto()
            tmp = self._proto_message.axes.setdefault(key)
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "NewCustomPlot":
        message = app_data_pb2.NewCustomPlot()
        message.ParseFromString(data)
        return cls(
            title = message.title,
            axes = {key: value for key, value in message.axes.items()},
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "NewCustomPlot":
        message = app_data_pb2.NewCustomPlot()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "NewCustomPlot":
        return cls(
            title = proto_message.title,
            axes = proto_message.axes,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class CustomSubPlots:
    rows: int = 0
    plots: List[NewCustomPlot] = field(default_factory=list)
    
    _proto_message: app_data_pb2.CustomSubPlots = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_data_pb2.CustomSubPlots()

    def populate_proto(self):
        self._proto_message.rows = self.rows
        del self._proto_message.plots[:]
        for value in self.plots:
            value.populate_proto()
            tmp = self._proto_message.plots.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CustomSubPlots":
        message = app_data_pb2.CustomSubPlots()
        message.ParseFromString(data)
        return cls(
            rows = message.rows,
            plots = [NewCustomPlot.from_proto(value) for value in message.plots],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CustomSubPlots":
        message = app_data_pb2.CustomSubPlots()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "CustomSubPlots":
        return cls(
            rows = proto_message.rows,
            plots = NewCustomPlot.from_proto(proto_message.plots),
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class CustomPlotsTab:
    subPlots: List[CustomSubPlots] = field(default_factory=list)
    
    _proto_message: app_data_pb2.CustomPlotsTab = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_data_pb2.CustomPlotsTab()

    def populate_proto(self):
        del self._proto_message.subPlots[:]
        for value in self.subPlots:
            value.populate_proto()
            tmp = self._proto_message.subPlots.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CustomPlotsTab":
        message = app_data_pb2.CustomPlotsTab()
        message.ParseFromString(data)
        return cls(
            subPlots = [CustomSubPlots.from_proto(value) for value in message.subPlots],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CustomPlotsTab":
        message = app_data_pb2.CustomPlotsTab()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "CustomPlotsTab":
        return cls(
            subPlots = CustomSubPlots.from_proto(proto_message.subPlots),
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class AppData:
    customPlotsTabs: Dict[str, CustomPlotsTab] = field(default_factory=dict)
    
    _proto_message: app_data_pb2.AppData = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = app_data_pb2.AppData()

    def populate_proto(self):
        self._proto_message.customPlotsTabs.clear()
        for key, value in self.customPlotsTabs.items():
            value.populate_proto()
            tmp = self._proto_message.customPlotsTabs.setdefault(key)
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "AppData":
        message = app_data_pb2.AppData()
        message.ParseFromString(data)
        return cls(
            customPlotsTabs = {key: value for key, value in message.customPlotsTabs.items()},
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "AppData":
        message = app_data_pb2.AppData()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "AppData":
        return cls(
            customPlotsTabs = proto_message.customPlotsTabs,
        )

    def __str__(self):
        return self.serializeAsJsonString()
