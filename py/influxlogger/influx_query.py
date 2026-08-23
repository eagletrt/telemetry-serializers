from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from influxlogger import influx_query_pb2
from google.protobuf.json_format import MessageToJson, Parse

class QueryFormat(Enum):
    QUERY_FORMAT_CSV = 0

class QueryCompression(Enum):
    QUERY_COMPRESSION_GZIP = 0
    QUERY_COMPRESSION_NONE = 1

class QueryState(Enum):
    QUERY_STATE_ACCEPTED = 0
    QUERY_STATE_RUNNING = 1
    QUERY_STATE_COMPLETED = 2
    QUERY_STATE_FAILED = 3

class QueryError(Enum):
    QUERY_ERROR_NONE = 0
    QUERY_ERROR_BAD_REQUEST = 1
    QUERY_ERROR_INVALID_RANGE = 2
    QUERY_ERROR_NOT_AUTHORIZED = 3
    QUERY_ERROR_UNAVAILABLE = 4
    QUERY_ERROR_DB_UNAVAILABLE = 5
    QUERY_ERROR_QUERY_FAILED = 6
    QUERY_ERROR_SERIALIZATION_FAILED = 7
    QUERY_ERROR_PUBLISH_FAILED = 8
    QUERY_ERROR_TIMEOUT = 9
    QUERY_ERROR_TOO_MUCH_DATA = 10
    QUERY_ERROR_INTERNAL = 11


@dataclass
class QueryRequest:
    start: int = 0
    stop: int = 0
    transactionId: str = ""
    networks: List[str] = field(default_factory=list)
    measurements: List[str] = field(default_factory=list)
    format: QueryFormat = None
    compression: QueryCompression = None
    maxRows: int = 0
    protocolVersion: int = 0
    
    _proto_message: influx_query_pb2.QueryRequest = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = influx_query_pb2.QueryRequest()

    def _populate_proto(self):
        self._proto_message.start = self.start
        self._proto_message.stop = self.stop
        self._proto_message.transactionId = self.transactionId
        del self._proto_message.networks[:]
        for val in self.networks:
            self._proto_message.networks.append(val)
        del self._proto_message.measurements[:]
        for val in self.measurements:
            self._proto_message.measurements.append(val)
        self._proto_message.format = self.format.value
        self._proto_message.compression = self.compression.value
        self._proto_message.maxRows = self.maxRows
        self._proto_message.protocolVersion = self.protocolVersion

    @classmethod
    def _from_proto(cls, proto_message) -> "QueryRequest":
        return cls(
            start = proto_message.start,
            stop = proto_message.stop,
            transactionId = proto_message.transactionId,
            networks=[str(val) for val in proto_message.networks],
            measurements=[str(val) for val in proto_message.measurements],
            format = QueryFormat(proto_message.format),
            compression = QueryCompression(proto_message.compression),
            maxRows = proto_message.maxRows,
            protocolVersion = proto_message.protocolVersion,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "QueryRequest":
        message = influx_query_pb2.QueryRequest()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "QueryRequest":
        message = influx_query_pb2.QueryRequest()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class QueryChunkInfo:
    transactionId: str = ""
    network: str = ""
    measurement: str = ""
    topic: str = ""
    chunkNumber: int = 0
    rows: int = 0
    sizeBytes: int = 0
    hash: str = ""
    format: QueryFormat = None
    compression: QueryCompression = None
    
    _proto_message: influx_query_pb2.QueryChunkInfo = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = influx_query_pb2.QueryChunkInfo()

    def _populate_proto(self):
        self._proto_message.transactionId = self.transactionId
        self._proto_message.network = self.network
        self._proto_message.measurement = self.measurement
        self._proto_message.topic = self.topic
        self._proto_message.chunkNumber = self.chunkNumber
        self._proto_message.rows = self.rows
        self._proto_message.sizeBytes = self.sizeBytes
        self._proto_message.hash = self.hash
        self._proto_message.format = self.format.value
        self._proto_message.compression = self.compression.value

    @classmethod
    def _from_proto(cls, proto_message) -> "QueryChunkInfo":
        return cls(
            transactionId = proto_message.transactionId,
            network = proto_message.network,
            measurement = proto_message.measurement,
            topic = proto_message.topic,
            chunkNumber = proto_message.chunkNumber,
            rows = proto_message.rows,
            sizeBytes = proto_message.sizeBytes,
            hash = proto_message.hash,
            format = QueryFormat(proto_message.format),
            compression = QueryCompression(proto_message.compression),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "QueryChunkInfo":
        message = influx_query_pb2.QueryChunkInfo()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "QueryChunkInfo":
        message = influx_query_pb2.QueryChunkInfo()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class QueryStatus:
    transactionId: str = ""
    timestamp: int = 0
    state: QueryState = None
    error: QueryError = None
    stage: str = ""
    description: str = ""
    totalChunks: int = 0
    totalRows: int = 0
    protocolVersion: int = 0
    chunks: List[QueryChunkInfo] = field(default_factory=list)
    details: Dict[str, str] = field(default_factory=dict)
    
    _proto_message: influx_query_pb2.QueryStatus = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = influx_query_pb2.QueryStatus()

    def _populate_proto(self):
        self._proto_message.transactionId = self.transactionId
        self._proto_message.timestamp = self.timestamp
        self._proto_message.state = self.state.value
        self._proto_message.error = self.error.value
        self._proto_message.stage = self.stage
        self._proto_message.description = self.description
        self._proto_message.totalChunks = self.totalChunks
        self._proto_message.totalRows = self.totalRows
        self._proto_message.protocolVersion = self.protocolVersion
        del self._proto_message.chunks[:]
        for val in self.chunks:
            val._populate_proto()
            tmp = self._proto_message.chunks.add()
            tmp.CopyFrom(val._proto_message)
        self._proto_message.details.clear()
        for key, val in self.details.items():
            self._proto_message.details[key] = val

    @classmethod
    def _from_proto(cls, proto_message) -> "QueryStatus":
        return cls(
            transactionId = proto_message.transactionId,
            timestamp = proto_message.timestamp,
            state = QueryState(proto_message.state),
            error = QueryError(proto_message.error),
            stage = proto_message.stage,
            description = proto_message.description,
            totalChunks = proto_message.totalChunks,
            totalRows = proto_message.totalRows,
            protocolVersion = proto_message.protocolVersion,
            chunks=[QueryChunkInfo._from_proto(val) for val in proto_message.chunks],
            details={key: str(val) for key, val in proto_message.details.items()},
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "QueryStatus":
        message = influx_query_pb2.QueryStatus()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "QueryStatus":
        message = influx_query_pb2.QueryStatus()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
