cmake_minimum_required(VERSION 3.20)

project(FlightPlanSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(flight_sim
    src/mainDrone.cpp
    src/Geometry.cpp
)

target_compile_options(flight_sim PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
)
