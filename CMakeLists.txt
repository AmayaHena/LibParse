cmake_minimum_required(VERSION 3.0)
project(LibParse VERSION 0.1 DESCRIPTION "LibParse description")

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror")

add_library(LibParse SHARED
    lib/fileManager/src/LoadFile.cpp
    lib/fileManager/src/File.cpp
    lib/fileManager/src/ParserFile.cpp
)
target_include_directories(LibParse
    PUBLIC lib/fileManager/inc/
)

