cmake_minimum_required(VERSION 3.18)
project(protomacrosnippet)

set(CMAKE_CXX_STANDARD 20)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS message.proto)

add_executable(main main.cpp ${PROTO_SRCS} ${PROTO_HDRS})
TARGET_LINK_LIBRARIES(main ${Protobuf_LIBRARIES})
