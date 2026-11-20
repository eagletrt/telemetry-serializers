from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from actions import rtcm_source_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class RtcmSource:
    type: str = ""
    topic: str = ""
    ref_topic: str = ""
    profile: str = ""
    
    _proto_message: rtcm_source_pb2.RtcmSource = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = rtcm_source_pb2.RtcmSource()

    def _populate_proto(self):
        self._proto_message.type = self.type
        self._proto_message.topic = self.topic
        self._proto_message.ref_topic = self.ref_topic
        self._proto_message.profile = self.profile

    @classmethod
    def _from_proto(cls, proto_message) -> "RtcmSource":
        return cls(
            type = proto_message.type,
            topic = proto_message.topic,
            ref_topic = proto_message.ref_topic,
            profile = proto_message.profile,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "RtcmSource":
        message = rtcm_source_pb2.RtcmSource()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "RtcmSource":
        message = rtcm_source_pb2.RtcmSource()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class RtcmSourceCommand:
    seq: float = 0.0
    base: str = ""
    by: str = ""
    source: RtcmSource = None
    
    _proto_message: rtcm_source_pb2.RtcmSourceCommand = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = rtcm_source_pb2.RtcmSourceCommand()

    def _populate_proto(self):
        self._proto_message.seq = self.seq
        self._proto_message.base = self.base
        self._proto_message.by = self.by
        if self.source:
            self.source._populate_proto()
            self._proto_message.source.CopyFrom(self.source._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "RtcmSourceCommand":
        return cls(
            seq = proto_message.seq,
            base = proto_message.base,
            by = proto_message.by,
            source = RtcmSource._from_proto(proto_message.source),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "RtcmSourceCommand":
        message = rtcm_source_pb2.RtcmSourceCommand()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "RtcmSourceCommand":
        message = rtcm_source_pb2.RtcmSourceCommand()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class RtcmSourceStatus:
    seq: float = 0.0
    ok: bool = False
    source: RtcmSource = None
    error: str = ""
    rtcm_age_s: float = 0.0
    rtcm_bytes: float = 0.0
    frames: int = 0
    bad_frames: int = 0
    
    _proto_message: rtcm_source_pb2.RtcmSourceStatus = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = rtcm_source_pb2.RtcmSourceStatus()

    def _populate_proto(self):
        self._proto_message.seq = self.seq
        self._proto_message.ok = self.ok
        if self.source:
            self.source._populate_proto()
            self._proto_message.source.CopyFrom(self.source._proto_message)
        self._proto_message.error = self.error
        self._proto_message.rtcm_age_s = self.rtcm_age_s
        self._proto_message.rtcm_bytes = self.rtcm_bytes
        self._proto_message.frames = self.frames
        self._proto_message.bad_frames = self.bad_frames

    @classmethod
    def _from_proto(cls, proto_message) -> "RtcmSourceStatus":
        return cls(
            seq = proto_message.seq,
            ok = proto_message.ok,
            source = RtcmSource._from_proto(proto_message.source),
            error = proto_message.error,
            rtcm_age_s = proto_message.rtcm_age_s,
            rtcm_bytes = proto_message.rtcm_bytes,
            frames = proto_message.frames,
            bad_frames = proto_message.bad_frames,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "RtcmSourceStatus":
        message = rtcm_source_pb2.RtcmSourceStatus()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "RtcmSourceStatus":
        message = rtcm_source_pb2.RtcmSourceStatus()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
