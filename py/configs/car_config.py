from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from configs import car_config_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Aero:
    angleOfIncidenceFront: float = 0.0
    angleOfIncidenceRear: float = 0.0
    flap: str = ""
    
    _proto_message: car_config_pb2.Aero = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.Aero()

    def populate_proto(self):
        self._proto_message.angleOfIncidenceFront = self.angleOfIncidenceFront
        self._proto_message.angleOfIncidenceRear = self.angleOfIncidenceRear
        self._proto_message.flap = self.flap

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Aero":
        message = car_config_pb2.Aero()
        message.ParseFromString(data)
        return cls(
            angleOfIncidenceFront = message.angleOfIncidenceFront,
            angleOfIncidenceRear = message.angleOfIncidenceRear,
            flap = message.flap,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Aero":
        message = car_config_pb2.Aero()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "Aero":
        return cls(
            angleOfIncidenceFront = proto_message.angleOfIncidenceFront,
            angleOfIncidenceRear = proto_message.angleOfIncidenceRear,
            flap = proto_message.flap,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class Wheel:
    camber: float = 0.0
    toe: float = 0.0
    pressure: str = ""
    
    _proto_message: car_config_pb2.Wheel = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.Wheel()

    def populate_proto(self):
        self._proto_message.camber = self.camber
        self._proto_message.toe = self.toe
        self._proto_message.pressure = self.pressure

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Wheel":
        message = car_config_pb2.Wheel()
        message.ParseFromString(data)
        return cls(
            camber = message.camber,
            toe = message.toe,
            pressure = message.pressure,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Wheel":
        message = car_config_pb2.Wheel()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "Wheel":
        return cls(
            camber = proto_message.camber,
            toe = proto_message.toe,
            pressure = proto_message.pressure,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class Damper:
    bound_low_comp: float = 0.0
    bound_high_comp: float = 0.0
    rebound: float = 0.0
    preload: float = 0.0
    
    _proto_message: car_config_pb2.Damper = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.Damper()

    def populate_proto(self):
        self._proto_message.bound_low_comp = self.bound_low_comp
        self._proto_message.bound_high_comp = self.bound_high_comp
        self._proto_message.rebound = self.rebound
        self._proto_message.preload = self.preload

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Damper":
        message = car_config_pb2.Damper()
        message.ParseFromString(data)
        return cls(
            bound_low_comp = message.bound_low_comp,
            bound_high_comp = message.bound_high_comp,
            rebound = message.rebound,
            preload = message.preload,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Damper":
        message = car_config_pb2.Damper()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "Damper":
        return cls(
            bound_low_comp = proto_message.bound_low_comp,
            bound_high_comp = proto_message.bound_high_comp,
            rebound = proto_message.rebound,
            preload = proto_message.preload,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class CarConfig:
    aero: Aero = None
    wheelFront: Wheel = None
    wheelRear: Wheel = None
    damperFront: Damper = None
    damperRear: Damper = None
    wheelCompound: str = ""
    rideHeight: float = 0.0
    balancing: str = ""
    notes: str = ""
    
    _proto_message: car_config_pb2.CarConfig = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.CarConfig()

    def populate_proto(self):
        if self.aero:
            self.aero.populate_proto()
            self._proto_message.aero.CopyFrom(self.aero._proto_message)
        if self.wheelFront:
            self.wheelFront.populate_proto()
            self._proto_message.wheelFront.CopyFrom(self.wheelFront._proto_message)
        if self.wheelRear:
            self.wheelRear.populate_proto()
            self._proto_message.wheelRear.CopyFrom(self.wheelRear._proto_message)
        if self.damperFront:
            self.damperFront.populate_proto()
            self._proto_message.damperFront.CopyFrom(self.damperFront._proto_message)
        if self.damperRear:
            self.damperRear.populate_proto()
            self._proto_message.damperRear.CopyFrom(self.damperRear._proto_message)
        self._proto_message.wheelCompound = self.wheelCompound
        self._proto_message.rideHeight = self.rideHeight
        self._proto_message.balancing = self.balancing
        self._proto_message.notes = self.notes

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CarConfig":
        message = car_config_pb2.CarConfig()
        message.ParseFromString(data)
        return cls(
            aero = (
                Aero.from_proto(message.aero)
                if message.HasField("aero")
                else None
            ),
            wheelFront = (
                Wheel.from_proto(message.wheelFront)
                if message.HasField("wheelFront")
                else None
            ),
            wheelRear = (
                Wheel.from_proto(message.wheelRear)
                if message.HasField("wheelRear")
                else None
            ),
            damperFront = (
                Damper.from_proto(message.damperFront)
                if message.HasField("damperFront")
                else None
            ),
            damperRear = (
                Damper.from_proto(message.damperRear)
                if message.HasField("damperRear")
                else None
            ),
            wheelCompound = message.wheelCompound,
            rideHeight = message.rideHeight,
            balancing = message.balancing,
            notes = message.notes,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CarConfig":
        message = car_config_pb2.CarConfig()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "CarConfig":
        return cls(
            aero = proto_message.aero,
            wheelFront = proto_message.wheelFront,
            wheelRear = proto_message.wheelRear,
            damperFront = proto_message.damperFront,
            damperRear = proto_message.damperRear,
            wheelCompound = proto_message.wheelCompound,
            rideHeight = proto_message.rideHeight,
            balancing = proto_message.balancing,
            notes = proto_message.notes,
        )

    def __str__(self):
        return self.serializeAsJsonString()
