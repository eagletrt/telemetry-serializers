cmake_minimum_required(VERSION 3.10)

project(serializers VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    ${PROJECT_NAME}
    STATIC

    src/app/app_data.cpp
    src/app/data_processing.cpp
    src/app/user_data.cpp
    src/app/app_config.cpp
    src/can/can_frequencies.cpp
    src/handcart/settings.cpp
    src/tpms/rtl433_payload.cpp
    src/telemetry/odometer.cpp
    src/telemetry/gps_maps.cpp
    src/telemetry/statistics.cpp
    src/telemetry/login_data.cpp
    src/telemetry/status.cpp
    src/telemetry/error.cpp
    src/lapcounter/lapcounter.cpp
    src/lapcounter/lap_counter.cpp
    src/configs/session_config.cpp
    src/configs/telemetry_config.cpp
    src/configs/car_config.cpp
    src/mongodb/lapcounter_layout.cpp
    src/mongodb/lapcounter_lap_records.cpp
    src/mongodb/lapcounter_lap_times.cpp
    src/actions/file_transaction.cpp
    src/actions/command.cpp
    src/data/telemetry_lap_data.cpp
    src/data/vehicle_state.cpp
    src/data/extra.cpp
    src/data/as_commands.cpp
    src/sessions/gpsSession.cpp
    src/influxlogger/configuration.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/inc
)