from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from tpms import rtl433_payload_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Rtl433Payload:
    time: str = ""
    model: str = ""
    id: int = 0
    pressure: int = 0
    temperature: int = 0
    acceleration: int = 0
    battery: int = 0
    interframe: int = 0
    wo_state: int = 0
    checksum: int = 0
    mic: str = ""
    mod: str = ""
    freq1: float = 0.0
    freq2: float = 0.0
    rssi: float = 0.0
    snr: float = 0.0
    noise: float = 0.0
    
    _proto_message: rtl433_payload_pb2.Rtl433Payload = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = rtl433_payload_pb2.Rtl433Payload()

    def _populate_proto(self):
        self._proto_message.time = self.time
        self._proto_message.model = self.model
        self._proto_message.id = self.id
        self._proto_message.pressure = self.pressure
        self._proto_message.temperature = self.temperature
        self._proto_message.acceleration = self.acceleration
        self._proto_message.battery = self.battery
        self._proto_message.interframe = self.interframe
        self._proto_message.wo_state = self.wo_state
        self._proto_message.checksum = self.checksum
        self._proto_message.mic = self.mic
        self._proto_message.mod = self.mod
        self._proto_message.freq1 = self.freq1
        self._proto_message.freq2 = self.freq2
        self._proto_message.rssi = self.rssi
        self._proto_message.snr = self.snr
        self._proto_message.noise = self.noise

    @classmethod
    def _from_proto(cls, proto_message) -> "Rtl433Payload":
        return cls(
            time = proto_message.time,
            model = proto_message.model,
            id = proto_message.id,
            pressure = proto_message.pressure,
            temperature = proto_message.temperature,
            acceleration = proto_message.acceleration,
            battery = proto_message.battery,
            interframe = proto_message.interframe,
            wo_state = proto_message.wo_state,
            checksum = proto_message.checksum,
            mic = proto_message.mic,
            mod = proto_message.mod,
            freq1 = proto_message.freq1,
            freq2 = proto_message.freq2,
            rssi = proto_message.rssi,
            snr = proto_message.snr,
            noise = proto_message.noise,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Rtl433Payload":
        message = rtl433_payload_pb2.Rtl433Payload()
        message.ParseFromString(data)
        return cls(
            time = message.time,
            model = message.model,
            id = message.id,
            pressure = message.pressure,
            temperature = message.temperature,
            acceleration = message.acceleration,
            battery = message.battery,
            interframe = message.interframe,
            wo_state = message.wo_state,
            checksum = message.checksum,
            mic = message.mic,
            mod = message.mod,
            freq1 = message.freq1,
            freq2 = message.freq2,
            rssi = message.rssi,
            snr = message.snr,
            noise = message.noise,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Rtl433Payload":
        message = rtl433_payload_pb2.Rtl433Payload()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
