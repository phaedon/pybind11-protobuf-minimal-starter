cmake_minimum_required(VERSION 3.12)
project(Pybind11ProtobufMinimalStarter)

set(BUILD_TESTING OFF)
set(FETCHCONTENT_QUIET OFF)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
set(PROTO_FILES example.proto)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})
protobuf_generate_python(PROTO_PY ${PROTO_FILES})

add_library(
    helloworld helloworld.h ${PROTO_SRCS} ${PROTO_HDRS}
)

target_link_libraries(
    helloworld PUBLIC ${Protobuf_LIBRARIES}
)

include(FetchContent)

message(STATUS "Fetching pybind11...")
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.13.6
)

message(STATUS "Fetching pybind11_protobuf...")
FetchContent_Declare(
    pybind11_protobuf
    GIT_REPOSITORY https://github.com/pybind/pybind11_protobuf.git
    GIT_TAG f02a2b7653bc50eb5119d125842a3870db95d251
    CMAKE_ARGS 
        -DPYBIND11_PROTOBUF_BUILD_TESTING=OFF
        -DUSE_SYSTEM_PYBIND=OFF
        -DUSE_SYSTEM_ABSEIL=ON
        -DUSE_SYSTEM_PROTOBUF=ON
)
FetchContent_MakeAvailable(pybind11 pybind11_protobuf)

pybind11_add_module(helloworld_pybind helloworld_pybind.cpp)
target_link_libraries(helloworld_pybind PRIVATE pybind11::module pybind11_protobuf::pybind11_native_proto_caster)