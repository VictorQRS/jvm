cmake_minimum_required(VERSION 3.5)
project(jvm)

option(BUILD_32 "Force 32-bit compilation" OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

if(BUILD_32)
    # Targeting 32-bit systems
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -m32)
    set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} -m32)
endif(BUILD_32)

include_directories("src/include")
add_compile_options(-Wall -Wextra -Wpedantic)

set(SOURCES
    src/main.cpp
    src/util/converter.cpp
    src/util/commander.cpp
    src/engine/frame.cpp
    src/engine/operands.cpp
    src/engine/variables.cpp
    src/class_loader/class_loader.cpp
    src/class_loader/constant_pool.cpp
    src/class_loader/interface.cpp
    src/class_loader/attribute.cpp
    src/class_loader/method.cpp
    src/class_loader/field.cpp
    src/class_loader/reader.cpp
    src/engine/engine.cpp
    src/engine/frames_stack.cpp
    src/class_loader/code_info.hpp
    src/class_loader/instruction_info.hpp
    src/class_loader/code_info.cpp
    src/class_loader/instruction_info.cpp
)

#file(GLOB SOURCES "src/*.cpp")

add_executable(jvm ${SOURCES})
