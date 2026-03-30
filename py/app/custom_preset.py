from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from app import custom_preset_pb2
from google.protobuf.json_format import MessageToJson, Parse

class PlotType(Enum):
    UNKNOWN = 0
    LINE = 1
    SCATTER = 2


@dataclass
class Size:
    w: float = 0.0
    h: float = 0.0
    
    _proto_message: custom_preset_pb2.Size = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = custom_preset_pb2.Size()

    def _populate_proto(self):
        self._proto_message.w = self.w
        self._proto_message.h = self.h

    @classmethod
    def _from_proto(cls, proto_message) -> "Size":
        return cls(
            w = proto_message.w,
            h = proto_message.h,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Size":
        message = custom_preset_pb2.Size()
        message.ParseFromString(data)
        return cls(
            w = message.w,
            h = message.h,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Size":
        message = custom_preset_pb2.Size()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class GraphElement:
    label: str = ""
    type: PlotType = None
    xField: str = ""
    yField: str = ""
    color: int = 0
    axisX: int = 0
    axisY: int = 0
    
    _proto_message: custom_preset_pb2.GraphElement = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = custom_preset_pb2.GraphElement()

    def _populate_proto(self):
        self._proto_message.label = self.label
        self._proto_message.type = self.type.value
        self._proto_message.xField = self.xField
        self._proto_message.yField = self.yField
        self._proto_message.color = self.color
        self._proto_message.axisX = self.axisX
        self._proto_message.axisY = self.axisY

    @classmethod
    def _from_proto(cls, proto_message) -> "GraphElement":
        return cls(
            label = proto_message.label,
            type = PlotType(proto_message.type),
            xField = proto_message.xField,
            yField = proto_message.yField,
            color = proto_message.color,
            axisX = proto_message.axisX,
            axisY = proto_message.axisY,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "GraphElement":
        message = custom_preset_pb2.GraphElement()
        message.ParseFromString(data)
        return cls(
            label = message.label,
            type = PlotType(message.type),
            xField = message.xField,
            yField = message.yField,
            color = message.color,
            axisX = message.axisX,
            axisY = message.axisY,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GraphElement":
        message = custom_preset_pb2.GraphElement()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Graph:
    id: str = ""
    title: str = ""
    tags: List[str] = field(default_factory=list)
    signals: List[GraphElement] = field(default_factory=list)
    otherElements: List[str] = field(default_factory=list)
    hasTooltip: bool = False
    author: str = ""
    implotFlags: int = 0
    axisFlags: int = 0
    
    _proto_message: custom_preset_pb2.Graph = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = custom_preset_pb2.Graph()

    def _populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.title = self.title
        del self._proto_message.tags[:]
        for val in self.tags:
            self._proto_message.tags.append(val)
        del self._proto_message.signals[:]
        for val in self.signals:
            val._populate_proto()
            tmp = self._proto_message.signals.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.otherElements[:]
        for val in self.otherElements:
            self._proto_message.otherElements.append(val)
        self._proto_message.hasTooltip = self.hasTooltip
        self._proto_message.author = self.author
        self._proto_message.implotFlags = self.implotFlags
        self._proto_message.axisFlags = self.axisFlags

    @classmethod
    def _from_proto(cls, proto_message) -> "Graph":
        return cls(
            id = proto_message.id,
            title = proto_message.title,
            tags=[str(val) for val in proto_message.tags],
            signals=[GraphElement._from_proto(val) for val in proto_message.signals],
            otherElements=[str(val) for val in proto_message.otherElements],
            hasTooltip = proto_message.hasTooltip,
            author = proto_message.author,
            implotFlags = proto_message.implotFlags,
            axisFlags = proto_message.axisFlags,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Graph":
        message = custom_preset_pb2.Graph()
        message.ParseFromString(data)
        return cls(
            id = message.id,
            title = message.title,
            tags = [str(val) for val in message.tags],
            signals = [GraphElement._from_proto(val) for val in message.signals],
            otherElements = [str(val) for val in message.otherElements],
            hasTooltip = message.hasTooltip,
            author = message.author,
            implotFlags = message.implotFlags,
            axisFlags = message.axisFlags,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Graph":
        message = custom_preset_pb2.Graph()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class GridPlot:
    name: str = ""
    id: str = ""
    size: Size = None
    flags: int = 0
    graphID: List[str] = field(default_factory=list)
    
    _proto_message: custom_preset_pb2.GridPlot = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = custom_preset_pb2.GridPlot()

    def _populate_proto(self):
        self._proto_message.name = self.name
        self._proto_message.id = self.id
        if self.size:
            self.size._populate_proto()
            self._proto_message.size.CopyFrom(self.size._proto_message)
        self._proto_message.flags = self.flags
        del self._proto_message.graphID[:]
        for val in self.graphID:
            self._proto_message.graphID.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "GridPlot":
        return cls(
            name = proto_message.name,
            id = proto_message.id,
            size = Size._from_proto(proto_message.size),
            flags = proto_message.flags,
            graphID=[str(val) for val in proto_message.graphID],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "GridPlot":
        message = custom_preset_pb2.GridPlot()
        message.ParseFromString(data)
        return cls(
            name = message.name,
            id = message.id,
            size = (
                Size._from_proto(message.size)
                if message.HasField("size")
                else None
            ),
            flags = message.flags,
            graphID = [str(val) for val in message.graphID],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GridPlot":
        message = custom_preset_pb2.GridPlot()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class CustomPage:
    id: str = ""
    name: str = ""
    size: Size = None
    author: str = ""
    gridCells: List[int] = field(default_factory=list)
    gridPlotID: List[str] = field(default_factory=list)
    
    _proto_message: custom_preset_pb2.CustomPage = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = custom_preset_pb2.CustomPage()

    def _populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.name = self.name
        if self.size:
            self.size._populate_proto()
            self._proto_message.size.CopyFrom(self.size._proto_message)
        self._proto_message.author = self.author
        del self._proto_message.gridCells[:]
        for val in self.gridCells:
            self._proto_message.gridCells.append(val)
        del self._proto_message.gridPlotID[:]
        for val in self.gridPlotID:
            self._proto_message.gridPlotID.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "CustomPage":
        return cls(
            id = proto_message.id,
            name = proto_message.name,
            size = Size._from_proto(proto_message.size),
            author = proto_message.author,
            gridCells=[int(val) for val in proto_message.gridCells],
            gridPlotID=[str(val) for val in proto_message.gridPlotID],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CustomPage":
        message = custom_preset_pb2.CustomPage()
        message.ParseFromString(data)
        return cls(
            id = message.id,
            name = message.name,
            size = (
                Size._from_proto(message.size)
                if message.HasField("size")
                else None
            ),
            author = message.author,
            gridCells = [int(val) for val in message.gridCells],
            gridPlotID = [str(val) for val in message.gridPlotID],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CustomPage":
        message = custom_preset_pb2.CustomPage()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class PresetMappings:
    plot_configs: Dict[str, Graph] = field(default_factory=dict)
    subplot_configs: Dict[str, GridPlot] = field(default_factory=dict)
    preset_configs: Dict[str, CustomPage] = field(default_factory=dict)
    
    _proto_message: custom_preset_pb2.PresetMappings = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = custom_preset_pb2.PresetMappings()

    def _populate_proto(self):
        self._proto_message.plot_configs.clear()
        for key, val in self.plot_configs.items():
            val._populate_proto()
            tmp = self._proto_message.plot_configs.setdefault(key)
            tmp.CopyFrom(val._proto_message)
        self._proto_message.subplot_configs.clear()
        for key, val in self.subplot_configs.items():
            val._populate_proto()
            tmp = self._proto_message.subplot_configs.setdefault(key)
            tmp.CopyFrom(val._proto_message)
        self._proto_message.preset_configs.clear()
        for key, val in self.preset_configs.items():
            val._populate_proto()
            tmp = self._proto_message.preset_configs.setdefault(key)
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "PresetMappings":
        return cls(
            plot_configs={key: Graph._from_proto(val) for key, val in proto_message.plot_configs.items()},
            subplot_configs={key: GridPlot._from_proto(val) for key, val in proto_message.subplot_configs.items()},
            preset_configs={key: CustomPage._from_proto(val) for key, val in proto_message.preset_configs.items()},
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "PresetMappings":
        message = custom_preset_pb2.PresetMappings()
        message.ParseFromString(data)
        return cls(
            plot_configs = {key: Graph._from_proto(val) for key, val in message.plot_configs.items()},
            subplot_configs = {key: GridPlot._from_proto(val) for key, val in message.subplot_configs.items()},
            preset_configs = {key: CustomPage._from_proto(val) for key, val in message.preset_configs.items()},
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "PresetMappings":
        message = custom_preset_pb2.PresetMappings()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
