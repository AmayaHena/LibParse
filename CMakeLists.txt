cmake_minimum_required(VERSION 3.0)
project(LibParse VERSION 0.1 DESCRIPTION "LibParse description")

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror")

add_library(LibParse SHARED
    lib/src/LoadFile/LoadFile.cpp
    lib/src/File/File.cpp
    lib/src/Parser/Parser.cpp
)
target_include_directories(LibParse
    PUBLIC lib/inc
    PUBLIC lib/inc/LoadFile
    PUBLIC lib/inc/File
    PUBLIC lib/inc/Parser
)

