cmake_minimum_required(VERSION 3.22)

project(serializers VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    ${PROJECT_NAME}
    STATIC

    src/configs/session_config.cpp
    src/configs/car_config.cpp
    src/configs/telemetry_config.cpp
    src/handcart/settings.cpp
    src/lapcounter/race.cpp
    src/lapcounter/circuit.cpp
    src/app/user_data.cpp
    src/app/app_config.cpp
    src/actions/command.cpp
    src/actions/file_transaction.cpp
    src/telemetry/login_data.cpp
    src/telemetry/statistics.cpp
    src/telemetry/status.cpp
    src/telemetry/error.cpp
    src/can/can_frequencies.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/inc
)